#include "selectclient.h"
#include "ui_selectclient.h"
#include "basedonnee.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

SelectClient::SelectClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectClient)
{
    ui->setupUi(this);

    QSqlQuery query(BaseDonnee::instance().database());
    if (!query.exec("SELECT idClient, nom, prenom FROM Client")) {
        QMessageBox::critical(this, "Erreur", "Erreur chargement clients : " + query.lastError().text());
        return;
    }

    ui->tableClients->setRowCount(0);
    while (query.next()) {
        int row = ui->tableClients->rowCount();
        ui->tableClients->insertRow(row);
        ui->tableClients->setItem(row, 0, new QTableWidgetItem(query.value("idClient").toString()));
        ui->tableClients->setItem(row, 1, new QTableWidgetItem(query.value("nom").toString()));
        ui->tableClients->setItem(row, 2, new QTableWidgetItem(query.value("prenom").toString()));
    }
}

SelectClient::~SelectClient()
{
    BaseDonnee::instance().deconnecter();
    delete ui;
}

void SelectClient::on_buttonBox_accepted()
{
    QModelIndexList selection = ui->tableClients->selectionModel()->selectedRows();
    if (selection.empty()) {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner un client.");
        return;
    }

    int row = selection.first().row();
    m_clientIdSelectionne = ui->tableClients->item(row, 0)->text().toInt();

    accept();
}

int SelectClient::clientIdSelectionne() const
{
    return m_clientIdSelectionne;
}
