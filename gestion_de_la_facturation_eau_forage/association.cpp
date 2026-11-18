#include "association.h"
#include "basedonnee.h"
#include "ui_association.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

Association::Association(QSqlDatabase db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Association)
{
    ui->setupUi(this);

    if(!db.open()){
        QMessageBox::warning(this,"Erreur","Echec de la connexion à la base de données");
    }

    chargerClients();
    chargerCompteurs();

    connect(ui->btnAssocier, &QPushButton::clicked, this, &Association::associerCompteurAuClient);
}

Association::~Association()
{
    delete ui;
}

void Association::chargerClients()
{
    ui->comboBoxClient->clear();
    QSqlQuery query;

    if (!query.exec("SELECT idClient, nom || ' ' || prenom FROM Client")) {
        QMessageBox::critical(this, "Erreur", "Impossible de charger les clients : " + query.lastError().text());
        return;
    }

    while (query.next()) {
        int idClient = query.value(0).toInt();
        QString nomComplet = query.value(1).toString();
        ui->comboBoxClient->addItem(nomComplet, idClient);
    }

    if (ui->comboBoxClient->count() == 0) {
        ui->comboBoxClient->addItem("Aucun client disponible", -1);
    }
}

void Association::chargerCompteurs()
{
    ui->comboBoxCompteur->clear();
    QSqlQuery query;

    if (!query.exec("SELECT numCompteur, serie FROM Compteur WHERE attributComp = 0")) {
        QMessageBox::critical(this, "Erreur", "Impossible de charger les compteurs : " + query.lastError().text());
        return;
    }

    while (query.next()) {
        int numCompteur = query.value(0).toInt();
        QString serie = query.value(1).toString();
        ui->comboBoxCompteur->addItem("Compteur " + serie, numCompteur);
    }

    if (ui->comboBoxCompteur->count() == 0) {
        ui->comboBoxCompteur->addItem("Aucun compteur disponible", -1);
    }
}

void Association::associerCompteurAuClient()
{
    int idClient = ui->comboBoxClient->currentData().toInt();
    int numCompteur = ui->comboBoxCompteur->currentData().toInt();
    QString date = ui->dateEditAbonnement->date().toString("yyyy-MM-dd");

    if (idClient == -1 || numCompteur == -1) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un client et un compteur valides.");
        return;
    }

    QSqlQuery query;

    query.prepare("INSERT INTO Abonnement (idClient, numCompteur, date_abonnement) "
                  "VALUES (:idClient, :numCompteur, :date)");
    query.bindValue(":idClient", idClient);
    query.bindValue(":numCompteur", numCompteur);
    query.bindValue(":date", date);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec de l'association : " + query.lastError().text());
        return;
    }

    query.prepare("UPDATE Compteur SET attributComp = 1 WHERE numCompteur = :numCompteur");
    query.bindValue(":numCompteur", numCompteur);
    if (!query.exec()) {
        QMessageBox::warning(this, "Avertissement", "L'association a réussi mais la mise à jour du compteur a échoué : " + query.lastError().text());
    }

    QMessageBox::information(this, "Succès", "Compteur associé au client avec succès !");
    this->close();
}
