#include "gestion_compteurs.h"
#include "windowGestion.h"
#include "association.h"
#include "trans_archive.h"
#include "ui_gestion_compteurs.h"

gestion_compteurs::gestion_compteurs(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gestion_compteurs)
{
    ui->setupUi(this);
}

gestion_compteurs::~gestion_compteurs()
{
    delete ui;
}

void gestion_compteurs::on_pushButton_ajout_clicked()
{
    WindowGestion *a = new WindowGestion(this);
    a->setAttribute(Qt::WA_DeleteOnClose);
    a->show();
}

void gestion_compteurs::on_pushButton_attribution_clicked()
{
    Association *b = new Association(this);
    b->setAttribute(Qt::WA_DeleteOnClose);
    b->show();
}

void gestion_compteurs::on_pushButton_trans_archive_clicked()
{
    TransArchive c(this);
    c.exec();
}
