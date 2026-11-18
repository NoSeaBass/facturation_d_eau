#include "application.h"
#include "./ui_application.h"

application::application(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::application)
{
    ui->setupUi(this);
}

application::~application()
{
    delete ui;
}

void application::on_btnGestionClients_clicked()
{
    Client *l = new Client();
    l->setAttribute(Qt::WA_DeleteOnClose);
    l->show();
}

void application::on_btnGestionCompteurs_clicked()
{
    WindowGestion *a = new WindowGestion();
    a->setAttribute(Qt::WA_DeleteOnClose);
    a->show();
}

void application::on_btnGestionFactures_clicked()
{
    gestionFactures *F = new gestionFactures();
    F->setAttribute(Qt::WA_DeleteOnClose);
    F->show();
}

void application::on_btnListePrelevements_clicked()
{
    listePrelevement* n = new listePrelevement();
    n->setAttribute(Qt::WA_DeleteOnClose);
    n->show();
}

void application::on_btnListeAbonnements_clicked()
{
    TransArchive *c = new TransArchive();
    c->setAttribute(Qt::WA_DeleteOnClose);
    c->show();
}

void application::on_btnFermer_clicked()
{
    this->close();
}
