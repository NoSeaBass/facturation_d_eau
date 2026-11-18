#include "windowGestion.h"
#include "./ui_windowGestion.h"
#include "basedonnee.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>

WindowGestion::WindowGestion(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WindowGestion)
    , modelCompteur(nullptr)
{
    ui->setupUi(this);

    if (!BaseDonnee::instance().connecter().open()) {
        QMessageBox::critical(this, "Erreur", "Impossible de se connecter à la base gestion_eau !");
        return;
    }

    modelCompteur = new QSqlTableModel(this, BaseDonnee::instance().database());
    modelCompteur->setTable("Compteur");
    modelCompteur->select();
    ui->tableViewCompteur->setModel(modelCompteur);

    connect(ui->btnAjouterCompteur, &QPushButton::clicked, this, &WindowGestion::ajouterCompteur);
}

WindowGestion::~WindowGestion() {
    BaseDonnee::instance().deconnecter();
    delete ui;
}

void WindowGestion::ajouterCompteur() {
    QString serie = ui->lineEditSerie->text().trimmed();

    if (serie.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une série pour le compteur !");
        return;
    }

    QSqlQuery query(BaseDonnee::instance().database());
    query.prepare("INSERT INTO Compteur (serie) VALUES (:serie)");
    query.bindValue(":serie", serie);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Compteur ajouté avec succès !");
        ui->lineEditSerie->clear();
        modelCompteur->select();
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible d'ajouter le compteur : " + query.lastError().text());
        qDebug() << "Erreur SQL :" << query.lastError().text();
    }
}
