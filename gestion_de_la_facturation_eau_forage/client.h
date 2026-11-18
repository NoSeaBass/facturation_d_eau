#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QGroupBox>
#include <QMessageBox>
#include <QHeaderView>
#include <QTextEdit>
#include <QSplitter>
#include "DatabaseManager.h"
#include "ClientModel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Client; }
QT_END_NAMESPACE

class Client : public QMainWindow
{
    Q_OBJECT

public:
    Client(QWidget *parent = nullptr);
    ~Client();

private slots:
    void ajouterClient();
    void modifierClient();
    void supprimerClient();
    void trierParCollectivite();
    void afficherCompteursClient();
    void viderChamps();
    void selectionnerClient();
    void actualiserListe();

private:
    void setupUI();
    void connecterSignaux();
    void chargerClients();
    void remplirTableau(const QList<ClientModel>& clients);

    QWidget *centralWidget;
    QSplitter *splitterPrincipal;

    QGroupBox *groupFormulaire;
    QLineEdit *lineEditNom;
    QLineEdit *lineEditPrenom;
    QLineEdit *lineEditAdresse;
    QLineEdit *lineEditTelephone;
    QPushButton *btnAjouter;
    QPushButton *btnModifier;
    QPushButton *btnSupprimer;
    QPushButton *btnVider;

    QGroupBox *groupTableau;
    QTableWidget *tableauClients;
    QPushButton *btnTrierCollectivite;
    QPushButton *btnActualiser;
    QPushButton *btnAfficherCompteurs;

    QGroupBox *groupCompteurs;
    QTextEdit *textEditCompteurs;

    DatabaseManager *dbManager;
    int clientIdActuel;

    Ui::Client *ui;
};

#endif // CLIENT_H
