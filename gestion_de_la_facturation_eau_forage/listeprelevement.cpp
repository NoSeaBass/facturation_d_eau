#include <QSqlQuery>

#include "listeprelevement.h"
#include "nouvellefacture.h"
#include "basedonnee.h"
#include "ui_listeprelevement.h"

void listePrelevement::miseAJour() {
    ui->tablePrelevements->setRowCount(0);
    ui->tablePrelevements->setColumnCount(6);

    QStringList headers;
    headers << "ID" << "Date Prélèvement" << "N° Compteur" << "Nouvel Index" << "Ancien Index" << "Consommation";
    ui->tablePrelevements->setHorizontalHeaderLabels(headers);

    QSqlQuery remplir;
    remplir.prepare("SELECT * FROM Prelevement");
    remplir.exec();

    int row = 0;
    while (remplir.next()) {
        ui->tablePrelevements->insertRow(row);

        ui->tablePrelevements->setItem(row, 0, new QTableWidgetItem(remplir.value(0).toString()));
        ui->tablePrelevements->setItem(row, 1, new QTableWidgetItem(remplir.value(1).toString()));
        ui->tablePrelevements->setItem(row, 2, new QTableWidgetItem(remplir.value(2).toString()));
        ui->tablePrelevements->setItem(row, 3, new QTableWidgetItem(remplir.value(3).toString()));
        ui->tablePrelevements->setItem(row, 4, new QTableWidgetItem(remplir.value(4).toString()));

        int consommation = remplir.value(3).toInt() - remplir.value(4).toInt();
        QString consommationText = QString("%1 m³").arg(consommation);
        ui->tablePrelevements->setItem(row, 5, new QTableWidgetItem(consommationText));

        row++;
    }
}


listePrelevement::listePrelevement(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::listePrelevement)
{
    ui->setupUi(this);
    /*
    listePrelevement::db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("gestion_eau.db");
    */

    db = BaseDonnee::instance().connecter();
    if(!db.open()){
        qDebug() << "Erreur connexion :" << db.lastError().text();
    }
    qDebug() << "Connexion à la base de donnees reussite";
    miseAJour();
}

listePrelevement::~listePrelevement()
{
    db.close();
    delete ui;
}

void listePrelevement::on_btnAjouterPrelevement_clicked()
{
    nouvellefacture* n = new nouvellefacture(db);
    n->show();
}


void listePrelevement::on_btnActualiser_clicked()
{
    miseAJour();
}

