#include "gestionfactures.h"
#include "nouvellefacture.h"
#include "basedonnee.h"
#include "./ui_gestionfactures.h"

#include <iostream>
#include <QDebug>
#include <QSqlError>
#include <ctime>
#include <iomanip>

int calculerMensualite(int consommation, int soldeAnterieur) {
    int total = 0;
    int consommationRestante = consommation;

    if (consommationRestante > 0) {
        int quantite = (consommationRestante < 20) ? consommationRestante : 20;
        total += quantite * 200;
        consommationRestante -= quantite;
    }

    if (consommationRestante > 0) {
        int quantite = (consommationRestante < 20) ? consommationRestante : 20;
        total += quantite * 400;
        consommationRestante -= quantite;
    }

    if (consommationRestante > 0) {
        total += consommationRestante * 1000;
    }

    total += soldeAnterieur;

    return total;
}

void gestionFactures::mettreAJourTable() {
    ui->tableFactures->setRowCount(0);

    QSqlQuery queryFactures("SELECT f.idFacture, f.numCompteur, f.idClient, f.soldeanterieur, f.consommation, c.nom, c.prenom "
                            "FROM Facture f "
                            "INNER JOIN Client c ON f.idClient = c.idClient");

    if (!queryFactures.exec()) {
        qDebug() << "Erreur de requete SQL pour les factures :" << queryFactures.lastError().text();
        return;
    }

    int row = 0;
    while (queryFactures.next()) {
        ui->tableFactures->insertRow(row);

        ui->tableFactures->setItem(row, 0, new QTableWidgetItem(queryFactures.value(0).toString())); // idFacture
        ui->tableFactures->setItem(row, 1, new QTableWidgetItem(queryFactures.value(1).toString())); // numCompteur
        ui->tableFactures->setItem(row, 2, new QTableWidgetItem(queryFactures.value(2).toString())); // idClient

        QString anterieur = queryFactures.value(3).toString();
        ui->tableFactures->setItem(row, 3, new QTableWidgetItem(anterieur + " FCFA"));

        QString consommation = queryFactures.value(4).toString();
        ui->tableFactures->setItem(row, 4, new QTableWidgetItem(consommation + " m³"));

        float tarif = calculerMensualite(queryFactures.value(4).toFloat(), queryFactures.value(3).toFloat());
        ui->tableFactures->setItem(row, 5, new QTableWidgetItem(QString::number(tarif, 'f', 2) + " FCFA"));

        QSqlQuery queryStatut;
        queryStatut.prepare("SELECT COUNT(*) FROM Facturation WHERE idFacture = ?;");
        queryStatut.addBindValue(queryFactures.value(0));

        if (queryStatut.exec() && queryStatut.next() && queryStatut.value(0).toInt() > 0) {
            ui->tableFactures->setItem(row, 6, new QTableWidgetItem("Payé"));
        } else {
            ui->tableFactures->setItem(row, 6, new QTableWidgetItem("Non payé"));
        }

        QWidget *actionWidget = new QWidget();
        actionWidget->setStyleSheet("background-color: transparent; border: none;");
        QHBoxLayout *layout = new QHBoxLayout(actionWidget);
        layout->setContentsMargins(4, 4, 4, 4);
        layout->setSpacing(6);

        QPushButton *btnSupprimer = new QPushButton("Supprimer");
        btnSupprimer->setObjectName("deleteBtn");
        btnSupprimer->setFixedSize(80, 28);

        btnSupprimer->setStyleSheet(
            "QPushButton#deleteBtn {"
            "    background-color: #ef4444;"
            "    color: white;"
            "    border: none;"
            "    border-radius: 4px;"
            "}"
            "QPushButton#deleteBtn:hover {"
            "    background-color: #dc2626;"
            "}"
            "QPushButton#deleteBtn:pressed {"
            "    background-color: #b91c1c;"
            "}"
            );

        layout->addWidget(btnSupprimer);

        QString currentIdFacture = queryFactures.value(0).toString();
        connect(btnSupprimer, &QPushButton::clicked, this, [this, currentIdFacture]() {
            for (int i = 0; i < ui->tableFactures->rowCount(); ++i) {
                if (ui->tableFactures->item(i, 0)->text() == currentIdFacture) {
                    supprimerFacture(i);
                    break;
                }
            }
        });

        QSqlQuery verifica;
        verifica.prepare("SELECT COUNT(*) FROM Facturation WHERE idFacture = :idFacture");
        verifica.bindValue(":idFacture", currentIdFacture);

        if (verifica.exec() && verifica.next()) {
            if (verifica.value(0).toInt() == 0) {
                QPushButton *btnFacturation = new QPushButton("Facturer");
                btnFacturation->setObjectName("invoiceBtn");
                btnFacturation->setFixedSize(80, 28);

                btnFacturation->setStyleSheet(
                    "QPushButton#invoiceBtn {"
                    "    background-color: #22c55e;"
                    "    color: white;"
                    "    border: none;"
                    "    border-radius: 4px;"
                    "}"
                    "QPushButton#invoiceBtn:hover {"
                    "    background-color: #16a34a;"
                    "}"
                    "QPushButton#invoiceBtn:pressed {"
                    "    background-color: #15803d;"
                    "}"
                    );

                layout->addWidget(btnFacturation);

                connect(btnFacturation, &QPushButton::clicked, this, [this, currentIdFacture]() {
                    for (int i = 0; i < ui->tableFactures->rowCount(); ++i) {
                        if (ui->tableFactures->item(i, 0)->text() == currentIdFacture) {
                            facturer(i);
                            break;
                        }
                    }
                });
            }
        }

        ui->tableFactures->setCellWidget(row, 7, actionWidget);
        row++;
    }

    ui->tableFactures->resizeColumnsToContents();
    ui->tableFactures->horizontalHeader()->setStretchLastSection(true);
}

void gestionFactures::supprimerFacture(int row) {
    if (row < 0 || row >= ui->tableFactures->rowCount()) {
        qDebug() << "Erreur: Index de ligne invalide:" << row;
        return;
    }

    QTableWidgetItem *item = ui->tableFactures->item(row, 0);
    if (!item) {
        qDebug() << "Erreur: Impossible de recuperer l'ID de la facture.";
        return;
    }
    QString idFacture = item->text();

    qDebug() << "Demande de suppression de la facture ID:" << idFacture;

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation",
                                  "Êtes-vous sûr de vouloir supprimer cette facture ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply != QMessageBox::Yes) {
        return;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM Facture WHERE idFacture = ?");
    query.addBindValue(idFacture);

    if (query.exec()) {
        qDebug() << "Facture ID" << idFacture << "supprimee avec succes.";
        QMessageBox::information(this, "Succès", "Facture supprimée avec succès !");
        mettreAJourTable();
    } else {
        qDebug() << "Erreur de suppression de la facture :" << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Impossible de supprimer la facture.");
    }
}

void gestionFactures::facturer(int row) {
    if (row < 0 || row >= ui->tableFactures->rowCount()) {
        qDebug() << "Erreur: Index de ligne invalide:" << row;
        return;
    }

    QTableWidgetItem *idFactureItem = ui->tableFactures->item(row, 0);
    QTableWidgetItem *numCompteurItem = ui->tableFactures->item(row, 1);
    QTableWidgetItem *idClientItem = ui->tableFactures->item(row, 2);

    if (!idFactureItem || !numCompteurItem || !idClientItem) {
        qDebug() << "Erreur: Impossible de recuperer les donnees de la ligne.";
        return;
    }

    QString idFacture = idFactureItem->text();
    QString numCompteur = numCompteurItem->text();
    QString idClient = idClientItem->text();

    QSqlQuery queryData;
    queryData.prepare("SELECT soldeanterieur, consommation FROM Facture WHERE idFacture = ?");
    queryData.addBindValue(idFacture);

    if (!queryData.exec() || !queryData.next()) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les données de la facture.");
        return;
    }

    double soldeAnterieur = queryData.value(0).toDouble();
    int consommation = queryData.value(1).toInt();
    double montantTotal = calculerMensualite(consommation, soldeAnterieur);

    qDebug() << "Action de facturation pour la facture ID:" << idFacture;

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation",
                                  QString("Confirmer la facturation de %1 FCFA ?")
                                      .arg(QString::number(montantTotal, 'f', 2)),
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply != QMessageBox::Yes) {
        return;
    }

    QSqlQuery payement;
    payement.prepare("INSERT INTO Facturation(date_paiement, numCompteur, idFacture, idClient, montant_total) VALUES"
                     "(:date_paiement, :numCompteur, :idFacture, :idClient, :montant_total)");

    payement.bindValue(":date_paiement", QDate::currentDate().toString("yyyy-MM-dd"));
    payement.bindValue(":numCompteur", numCompteur);
    payement.bindValue(":idFacture", idFacture);
    payement.bindValue(":idClient", idClient);
    payement.bindValue(":montant_total", montantTotal);

    if (payement.exec()) {
        QMessageBox::information(this, "Succès", "Facture enregistrée avec succès !");
        mettreAJourTable();
    } else {
        qDebug() << "Erreur d'ajout de la facturation:" << payement.lastError().text();
        QMessageBox::critical(this, "Erreur", "Impossible d'enregistrer la facturation.");
    }
    //j'aimerais archiver ce qui à été supprimer mais malheureusement le temps ne me le permet pas
}


gestionFactures::gestionFactures(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gestionFactures)
{
    ui->setupUi(this);
    showMaximized();
    if (!BaseDonnee::instance().connecter().open()) {
        QMessageBox::critical(this, "Erreur", "Impossible de se connecter à la base gestion_eau !");
        return;
    }

    mettreAJourTable();
}

gestionFactures::~gestionFactures() {
    BaseDonnee::instance().deconnecter();
    delete ui;
}
