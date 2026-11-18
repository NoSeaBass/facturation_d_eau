#include "mainwindow.h"
#include "application.h"
#include "basedonnee.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    db = BaseDonnee::instance().connecter();
    if(!db.open()){
        int why = 1;
    }
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QSqlQuery querry;

    QString id_entree = ui->lineEditIdentifiant->text();
    QString pass_entree = ui->lineEditMotDePasse->text();

    querry.prepare("SELECT password FROM User WHERE id=:id;");
    querry.bindValue(":id", id_entree);

    if(!querry.exec()){
        QMessageBox::critical(this, "Erreur", "Erreur de connexion à la base de données");
        return;
    }
    else{
        if(querry.next()){
            QString pass_bd = querry.value(0).toString();
            if(pass_bd == pass_entree){
                application *A = new application();
                A->setAttribute(Qt::WA_DeleteOnClose);
                A->showFullScreen();
                this->close();
            }
            else{
                QMessageBox::warning(this, "Erreur", "Id/Mot de passe incorrect");
            }
        }
        else{
            QMessageBox::warning(this, "Erreur", "Id/Mot de passe incorrect");
        }
    }
}
