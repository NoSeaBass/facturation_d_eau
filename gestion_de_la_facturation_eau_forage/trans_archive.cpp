#include "trans_archive.h"
#include "ui_trans_archive.h"
#include "basedonnee.h"
#include "selectclient.h"
#include "association.h"

#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDate>

TransArchive::TransArchive(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransArchive)
{
    ui->setupUi(this);

    TransArchive::db = BaseDonnee::instance().connecter();
    if (!db.open()) {
        QMessageBox::critical(this, "Erreur", "Impossible de se connecter à la base gestion_eau !");
        return;
    }

    chargerCompteursAssocies();

    connect(ui->btnArchiver, &QPushButton::clicked, this, &TransArchive::archiverCompteur);
    connect(ui->btnTransferer, &QPushButton::clicked, this, &TransArchive::transfererCompteur);
}

TransArchive::~TransArchive()
{
    TransArchive::db.close();
    delete ui;
}

void TransArchive::chargerCompteursAssocies()
{
    QSqlQuery query;
    QString sql = R"(
        SELECT c.numCompteur, cl.idClient, cl.nom, cl.prenom, a.date_abonnement, c.attributComp
        FROM Compteur c
        JOIN Abonnement a ON c.numCompteur = a.numCompteur
        JOIN Client cl ON a.idClient = cl.idClient
        WHERE c.attributComp = 1
    )";

    if (!query.exec(sql)) {
        QMessageBox::critical(this, "Erreur", "Erreur chargement compteurs associés : " + query.lastError().text());
        return;
    }

    ui->tableCompteurs->setRowCount(0);
    while (query.next()) {
        int row = ui->tableCompteurs->rowCount();
        ui->tableCompteurs->insertRow(row);

        ui->tableCompteurs->setItem(row, 0, new QTableWidgetItem(query.value("numCompteur").toString()));

        QString clientInfo = QString("%1 - %2 %3")
                                 .arg(query.value("idClient").toString())
                                 .arg(query.value("nom").toString())
                                 .arg(query.value("prenom").toString());
        ui->tableCompteurs->setItem(row, 1, new QTableWidgetItem(clientInfo));

        ui->tableCompteurs->setItem(row, 2, new QTableWidgetItem(query.value("date_abonnement").toString()));

        ui->tableCompteurs->setItem(row, 3, new QTableWidgetItem("Actif"));
    }
}

void TransArchive::archiverCompteur()
{
    int row = ui->tableCompteurs->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner un compteur à archiver.");
        return;
    }
    QString numCompteur = ui->tableCompteurs->item(row, 0)->text();

    QSqlQuery query;

    query.prepare("SELECT idClient, date_abonnement FROM Abonnement WHERE numCompteur = :numCompteur");
    query.bindValue(":numCompteur", numCompteur);
    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, "Erreur", "Abonnement introuvable pour ce compteur.");
        return;
    }

    int idClient = query.value("idClient").toInt();
    QString dateAbonnement = query.value("date_abonnement").toString();
    QString dateFin = QDate::currentDate().toString("yyyy-MM-dd");

    query.prepare(R"(
        INSERT INTO historiqueAbonnement (idClient, numCompteur, date_abonnement, date_fin)
        VALUES (:idClient, :numCompteur, :dateAbonnement, :dateFin)
    )");
    query.bindValue(":idClient", idClient);
    query.bindValue(":numCompteur", numCompteur);
    query.bindValue(":dateAbonnement", dateAbonnement);
    query.bindValue(":dateFin", dateFin);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec de l'archivage dans historique : " + query.lastError().text());
        return;
    }

    query.prepare("DELETE FROM Abonnement WHERE numCompteur = :numCompteur");
    query.bindValue(":numCompteur", numCompteur);
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Impossible de supprimer l'abonnement actuel : " + query.lastError().text());
        return;
    }

    query.prepare("UPDATE Compteur SET attributComp = 0 WHERE numCompteur = :numCompteur");
    query.bindValue(":numCompteur", numCompteur);
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Impossible de libérer le compteur : " + query.lastError().text());
        return;
    }

    QMessageBox::information(this, "Succès", "Compteur archivé avec succès.");
    chargerCompteursAssocies();
}

void TransArchive::transfererCompteur()
{
    int row = ui->tableCompteurs->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner un compteur à transférer.");
        return;
    }
    QString numCompteur = ui->tableCompteurs->item(row, 0)->text();

    SelectClient dlg(this);
    if (dlg.exec() != QDialog::Accepted) {
        return;
    }

    int nouveauIdClient = dlg.clientIdSelectionne();

    QSqlQuery query;
    query.prepare("SELECT idClient FROM Abonnement WHERE numCompteur = :numCompteur");
    query.bindValue(":numCompteur", numCompteur);
    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, "Erreur", "Abonnement introuvable pour ce compteur.");
        return;
    }
    int ancienIdClient = query.value("idClient").toInt();
    if (nouveauIdClient == ancienIdClient) {
        QMessageBox::warning(this, "Attention", "Le client sélectionné est le même que l'ancien.");
        return;
    }

    QString dateAbonnement;
    query.prepare("SELECT date_abonnement FROM Abonnement WHERE numCompteur = :numCompteur");
    query.bindValue(":numCompteur", numCompteur);
    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer la date d'abonnement.");
        return;
    }
    dateAbonnement = query.value("date_abonnement").toString();
    QString dateFin = QDate::currentDate().toString("yyyy-MM-dd");

    query.prepare(R"(
        INSERT INTO historiqueAbonnement (idClient, numCompteur, date_abonnement, date_fin)
        VALUES (:idClient, :numCompteur, :dateAbonnement, :dateFin)
    )");
    query.bindValue(":idClient", ancienIdClient);
    query.bindValue(":numCompteur", numCompteur);
    query.bindValue(":dateAbonnement", dateAbonnement);
    query.bindValue(":dateFin", dateFin);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec de l'archivage historique : " + query.lastError().text());
        return;
    }

    query.prepare("UPDATE Abonnement SET idClient = :nouveauIdClient WHERE numCompteur = :numCompteur");
    query.bindValue(":nouveauIdClient", nouveauIdClient);
    query.bindValue(":numCompteur", numCompteur);
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec du transfert : " + query.lastError().text());
        return;
    }

    QMessageBox::information(this, "Succès", "Compteur transféré avec succès.");
    chargerCompteursAssocies();
}

void TransArchive::on_btnNouvelAbonnement_clicked()
{
    Association *b = new Association(db, this);
    b->setAttribute(Qt::WA_DeleteOnClose);
    b->show();
}

