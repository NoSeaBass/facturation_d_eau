#include "nouvellefacture.h"
#include "gestionfactures.h"
#include "basedonnee.h"
#include "ui_nouvellefacture.h"

#include <QDebug>
#include <QSqlError>

void nouvellefacture::remplirComboBoxes()
{

    QSqlQuery query;

    ui->comboBox_2->clear();
    if (query.exec("SELECT numCompteur FROM Compteur WHERE attributComp = 1;")) {
        while (query.next()) {
            ui->comboBox_2->addItem(query.value(0).toString());
        }
    } else {
        qDebug() << "Erreur de requete (Compteur):" << query.lastError().text();
    }
}


nouvellefacture::nouvellefacture(QSqlDatabase &db, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::nouvellefacture)
{
    ui->setupUi(this);

    if(!this->db.isOpen()){
        qDebug() << "Erreur connexion :" << this->db.lastError().text();
    }
    qDebug() << "Connexion à la base de donnees reussite";
    remplirComboBoxes();
}

nouvellefacture::~nouvellefacture()
{
    db.close();
    delete ui;
}

void nouvellefacture::on_buttonBox_accepted()
{
    int ancienIndex = -1;
    int idClient = -1;
    double soldeAnterieur = 0.0;
    int consommation = 0;

    int idAncienneFacture = -1;
    double consommationAncienneFacture = 0.0;
    double soldeAnterieurAncienneFacture = 0.0;
    double prix_unitaire_hypothetique = 200.0;

    QSqlQuery query;

    query.prepare("SELECT ancienindex FROM Compteur WHERE numCompteur=:numCompteur");
    query.bindValue(":numCompteur", ui->comboBox_2->currentText().toInt());
    if (query.exec() && query.next()) {
        ancienIndex = query.value(0).toInt();
    } else {
        qDebug() << "Erreur de récupération de l'ancien index:" << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer l'ancien index du compteur.");
        return;
    }

    if (ancienIndex == -1) {
        QMessageBox::critical(this, "Erreur", "Ancien index non trouvé pour ce compteur.");
        return;
    }

    query.prepare("SELECT idClient FROM Abonnement WHERE numCompteur=:numCompteur");
    query.bindValue(":numCompteur", ui->comboBox_2->currentText().toInt());
    if (query.exec() && query.next()) {
        idClient = query.value(0).toInt();
    } else {
        qDebug() << "Erreur de récupération de l'ID client:" << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Le compteur ne se trouve pas dans un abonnement.");
        return;
    }

    query.prepare("SELECT F.idFacture, F.consommation, F.soldeanterieur FROM Facture AS F "
                  "LEFT JOIN Facturation AS FT ON F.idFacture = FT.idFacture "
                  "WHERE F.idClient = :idClient AND FT.idFacture IS NULL "
                  "ORDER BY F.idFacture DESC LIMIT 1");
    query.bindValue(":idClient", idClient);

    if (query.exec() && query.next()) {
        idAncienneFacture = query.value("idFacture").toInt();
        consommationAncienneFacture = query.value("consommation").toDouble();
        soldeAnterieurAncienneFacture = query.value("soldeanterieur").toDouble();

        soldeAnterieur = (consommationAncienneFacture * prix_unitaire_hypothetique) + soldeAnterieurAncienneFacture;
    }

    consommation = ui->NouveauIndex->text().toInt() - ancienIndex;

    if (consommation < 0) {
        QMessageBox::critical(this, "Erreur", "Le nouvel index ne peut pas être inférieur à l'ancien index.");
        return;
    }

    query.prepare("INSERT INTO Prelevement (dateprelevement, numCompteur, newIndex, ancienIndex) VALUES"
                  "(:dateprelevement, :numCompteur, :newIndex, :ancienIndex);");
    query.bindValue(":dateprelevement", ui->DatePrelever->date().toString("yyyy-MM-dd"));
    query.bindValue(":numCompteur", ui->comboBox_2->currentText().toInt());
    query.bindValue(":newIndex", ui->NouveauIndex->text().toInt());
    query.bindValue(":ancienIndex", ancienIndex);

    if (!query.exec()){
        qDebug() << "Erreur d'ajout du prélèvement:" << query.lastError().text();
        QMessageBox::critical(this, "Erreur d'ajout", "Impossible d'ajouter le prélèvement.");
        return;
    }

    query.prepare("INSERT INTO Facture (numCompteur, idClient, soldeanterieur, consommation) VALUES"
                  "(:numCompteur, :idClient, :soldeAnterieur, :consommation)");
    query.bindValue(":numCompteur", ui->comboBox_2->currentText().toInt());
    query.bindValue(":idClient", idClient);
    query.bindValue(":soldeAnterieur", soldeAnterieur);
    query.bindValue(":consommation", consommation);

    if (!query.exec()){
        qDebug() << "Erreur d'ajout de la facture:" << query.lastError().text();
        QMessageBox::critical(this, "Erreur d'ajout", "Impossible d'ajouter la facture.");
        return;
    }

    if (idAncienneFacture != -1) {
        QSqlQuery insertFacturationQuery;
        double montantAncienneFacture = (consommationAncienneFacture * prix_unitaire_hypothetique) + soldeAnterieurAncienneFacture;
        insertFacturationQuery.prepare("INSERT INTO ancienFacture (date_paiement, numCompteur, idFacture, idClient, montant_total) VALUES "
                                       "(:date_paiement, :numCompteur, :idFacture, :idClient, :montant_total)");
        insertFacturationQuery.bindValue(":date_paiement", ui->DatePrelever->date().toString("yyyy-MM-dd"));
        insertFacturationQuery.bindValue(":numCompteur", ui->comboBox_2->currentText().toInt());
        insertFacturationQuery.bindValue(":idFacture", idAncienneFacture);
        insertFacturationQuery.bindValue(":idClient", idClient);
        insertFacturationQuery.bindValue(":montant_total", montantAncienneFacture);

        if (!insertFacturationQuery.exec()) {
            qDebug() << "Avertissement: Impossible d'enregistrer le paiement de l'ancienne facture." << insertFacturationQuery.lastError().text();
        }

        QSqlQuery suprimer;
        suprimer.prepare("DELETE FROM Facture WHERE idFacture = :idFacture");
        suprimer.bindValue(":idFacture", idAncienneFacture);
        if(!suprimer.exec()){
            qDebug() << "Avertissement: Impossible de suprimer l'ancienne facture." << insertFacturationQuery.lastError().text();
        }
    }

    query.prepare("UPDATE Compteur SET ancienIndex = :newIndex WHERE numCompteur = :numCompteur");
    query.bindValue(":newIndex", ui->NouveauIndex->text().toInt());
    query.bindValue(":numCompteur", ui->comboBox_2->currentText().toInt());

    if (!query.exec()) {
        qDebug() << "Erreur de mise à jour de l'ancien index:" << query.lastError().text();
        QMessageBox::warning(this, "Avertissement", "La facture a été créée, mais l'ancien index du compteur n'a pas pu être mis à jour.");
    } else {
        QMessageBox::information(this, "Succès", "Le prélèvement et la facture ont été ajoutés avec succès !");
        this->close();
    }
}

void nouvellefacture::on_buttonBox_rejected()
{
    //qDebug() << "Refuser";
}

