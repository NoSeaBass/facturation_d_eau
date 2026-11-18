#include "client.h"


Client::Client(QWidget *parent)
    : QMainWindow(parent), clientIdActuel(-1)

{

    dbManager = DatabaseManager::getInstance();

    if (!dbManager->connectToDatabase()) {
        QMessageBox::critical(this, "Erreur",
                              "Impossible de se connecter à la base de données!");
        return;
    }


    setupUI();
    connecterSignaux();
    chargerClients();

    setWindowTitle("Gestion des Abonnés - Facturation Eau");
    setMinimumSize(1000, 700);
    resize(1200, 800);
}

Client::~Client()
{

}

void Client::setupUI()
{
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);


    splitterPrincipal = new QSplitter(Qt::Horizontal, this);


    groupFormulaire = new QGroupBox("Informations Client", this);
    groupFormulaire->setFixedWidth(350);

    QGridLayout *layoutFormulaire = new QGridLayout(groupFormulaire);


    layoutFormulaire->addWidget(new QLabel("Nom:"), 0, 0);
    lineEditNom = new QLineEdit();
    layoutFormulaire->addWidget(lineEditNom, 0, 1);

    layoutFormulaire->addWidget(new QLabel("Prénom:"), 1, 0);
    lineEditPrenom = new QLineEdit();
    layoutFormulaire->addWidget(lineEditPrenom, 1, 1);

    layoutFormulaire->addWidget(new QLabel("Adresse:"), 2, 0);
    lineEditAdresse = new QLineEdit();
    layoutFormulaire->addWidget(lineEditAdresse, 2, 1);

    layoutFormulaire->addWidget(new QLabel("Téléphone:"), 3, 0);
    lineEditTelephone = new QLineEdit();
    layoutFormulaire->addWidget(lineEditTelephone, 3, 1);

    QHBoxLayout *layoutBoutons = new QHBoxLayout();
    btnAjouter = new QPushButton("Ajouter");
    btnModifier = new QPushButton("Modifier");
    btnSupprimer = new QPushButton("Supprimer");
    btnVider = new QPushButton("Vider");

    btnAjouter->setStyleSheet("QPushButton { background-color: #4CAF50; color: white; font-weight: bold; padding: 8px; }");
    btnModifier->setStyleSheet("QPushButton { background-color: #2196F3; color: white; font-weight: bold; padding: 8px; }");
    btnSupprimer->setStyleSheet("QPushButton { background-color: #f44336; color: white; font-weight: bold; padding: 8px; }");
    btnVider->setStyleSheet("QPushButton { background-color: #9E9E9E; color: white; font-weight: bold; padding: 8px; }");

    layoutBoutons->addWidget(btnAjouter);
    layoutBoutons->addWidget(btnModifier);
    layoutFormulaire->addLayout(layoutBoutons, 4, 0, 1, 2);

    QHBoxLayout *layoutBoutons2 = new QHBoxLayout();
    layoutBoutons2->addWidget(btnSupprimer);
    layoutBoutons2->addWidget(btnVider);
    layoutFormulaire->addLayout(layoutBoutons2, 5, 0, 1, 2);

    splitterPrincipal->addWidget(groupFormulaire);


    QWidget *containerDroit = new QWidget();
    QVBoxLayout *layoutDroit = new QVBoxLayout(containerDroit);


    groupTableau = new QGroupBox("Liste des Clients");
    QVBoxLayout *layoutTableau = new QVBoxLayout(groupTableau);


    QHBoxLayout *layoutControles = new QHBoxLayout();
    btnTrierCollectivite = new QPushButton("Trier par Collectivité");
    btnActualiser = new QPushButton("Actualiser");
    btnAfficherCompteurs = new QPushButton("Afficher Compteurs");

    btnTrierCollectivite->setStyleSheet("QPushButton { background-color: #FF9800; color: white; font-weight: bold; padding: 6px; }");
    btnActualiser->setStyleSheet("QPushButton { background-color: #607D8B; color: white; font-weight: bold; padding: 6px; }");
    btnAfficherCompteurs->setStyleSheet("QPushButton { background-color: #9C27B0; color: white; font-weight: bold; padding: 6px; }");

    layoutControles->addWidget(btnTrierCollectivite);
    layoutControles->addWidget(btnActualiser);
    layoutControles->addWidget(btnAfficherCompteurs);
    layoutControles->addStretch();


    tableauClients = new QTableWidget();
    tableauClients->setColumnCount(5);
    QStringList headers;
    headers << "ID" << "Nom" << "Prénom" << "Adresse" << "Téléphone";
    tableauClients->setHorizontalHeaderLabels(headers);


    tableauClients->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableauClients->setAlternatingRowColors(true);
    tableauClients->horizontalHeader()->setStretchLastSection(true);
    tableauClients->setEditTriggers(QAbstractItemView::NoEditTriggers);

    layoutTableau->addLayout(layoutControles);
    layoutTableau->addWidget(tableauClients);


    groupCompteurs = new QGroupBox("Compteurs du Client Sélectionné");
    QVBoxLayout *layoutCompteurs = new QVBoxLayout(groupCompteurs);

    textEditCompteurs = new QTextEdit();
    textEditCompteurs->setMaximumHeight(150);
    textEditCompteurs->setReadOnly(true);
    textEditCompteurs->setStyleSheet("QTextEdit { background-color: #f5f5f5; font-family: monospace; }");

    layoutCompteurs->addWidget(textEditCompteurs);


    layoutDroit->addWidget(groupTableau, 2);
    layoutDroit->addWidget(groupCompteurs, 1);

    splitterPrincipal->addWidget(containerDroit);


    QHBoxLayout *layoutPrincipal = new QHBoxLayout(centralWidget);
    layoutPrincipal->addWidget(splitterPrincipal);


    splitterPrincipal->setStretchFactor(0, 0);
    splitterPrincipal->setStretchFactor(1, 1);
}

void Client::connecterSignaux()
{
    connect(btnAjouter, &QPushButton::clicked, this, &Client::ajouterClient);
    connect(btnModifier, &QPushButton::clicked, this, &Client::modifierClient);
    connect(btnSupprimer, &QPushButton::clicked, this, &Client::supprimerClient);
    connect(btnVider, &QPushButton::clicked, this, &Client::viderChamps);
    connect(btnTrierCollectivite, &QPushButton::clicked, this, &Client::trierParCollectivite);
    connect(btnActualiser, &QPushButton::clicked, this, &Client::actualiserListe);
    connect(btnAfficherCompteurs, &QPushButton::clicked, this, &Client::afficherCompteursClient);

    connect(tableauClients, &QTableWidget::itemSelectionChanged, this, &Client::selectionnerClient);
}

void Client::chargerClients()
{
    QList<ClientModel> clients = dbManager->obtenirTousLesClients();
    remplirTableau(clients);
}

void Client::remplirTableau(const QList<ClientModel>& clients)
{
    tableauClients->setRowCount(clients.size());

    for (int i = 0; i < clients.size(); ++i) {
        const ClientModel& client = clients[i];

        tableauClients->setItem(i, 0, new QTableWidgetItem(QString::number(client.getId())));
        tableauClients->setItem(i, 1, new QTableWidgetItem(client.getNom()));
        tableauClients->setItem(i, 2, new QTableWidgetItem(client.getPrenom()));
        tableauClients->setItem(i, 3, new QTableWidgetItem(client.getAdresse()));
        tableauClients->setItem(i, 4, new QTableWidgetItem(client.getTelephone()));
    }


    tableauClients->resizeColumnsToContents();
}

void Client::ajouterClient()
{
    QString nom = lineEditNom->text().trimmed();
    QString prenom = lineEditPrenom->text().trimmed();
    QString adresse = lineEditAdresse->text().trimmed();
    QString telephone = lineEditTelephone->text().trimmed();

    if (nom.isEmpty() || prenom.isEmpty()) {
        QMessageBox::warning(this, "Attention", "Le nom et le prénom sont obligatoires!");
        return;
    }

    ClientModel client(0, nom, prenom, adresse, telephone);

    if (dbManager->ajouterClient(client)) {
        QMessageBox::information(this, "Succès", "Client ajouté avec succès!");
        viderChamps();
        chargerClients();
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout du client!");
    }
}

void Client::modifierClient()
{
    if (clientIdActuel == -1) {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner un client à modifier!");
        return;
    }

    QString nom = lineEditNom->text().trimmed();
    QString prenom = lineEditPrenom->text().trimmed();
    QString adresse = lineEditAdresse->text().trimmed();
    QString telephone = lineEditTelephone->text().trimmed();

    if (nom.isEmpty() || prenom.isEmpty()) {
        QMessageBox::warning(this, "Attention", "Le nom et le prénom sont obligatoires!");
        return;
    }

    ClientModel client(clientIdActuel, nom, prenom, adresse, telephone);

    if (dbManager->modifierClient(client)) {
        QMessageBox::information(this, "Succès", "Client modifié avec succès!");
        viderChamps();
        chargerClients();
        clientIdActuel = -1;
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la modification du client!");
    }
}

void Client::supprimerClient()
{
    if (clientIdActuel == -1) {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner un client à supprimer!");
        return;
    }

    int reponse = QMessageBox::question(this, "Confirmation",
                                        "Êtes-vous sûr de vouloir supprimer ce client?",
                                        QMessageBox::Yes | QMessageBox::No);

    if (reponse == QMessageBox::Yes) {
        if (dbManager->supprimerClient(clientIdActuel)) {
            QMessageBox::information(this, "Succès", "Client supprimé avec succès!");
            viderChamps();
            chargerClients();
            clientIdActuel = -1;
            textEditCompteurs->clear();
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression du client!");
        }
    }
}

void Client::trierParCollectivite()
{
    QList<ClientModel> clients = dbManager->trierClientsParCollectivite();
    remplirTableau(clients);
    QMessageBox::information(this, "Information", "Clients triés par collectivité (adresse)!");
}

void Client::afficherCompteursClient()
{
    if (clientIdActuel == -1) {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner un client!");
        return;
    }

    QStringList compteurs = dbManager->obtenirCompteursClient(clientIdActuel);

    if (compteurs.isEmpty()) {
        textEditCompteurs->setText("Aucun compteur assigné à ce client.");
    } else {
        QString texte = "=== COMPTEURS DU CLIENT ===\n\n";
        for (const QString& compteur : compteurs) {
            texte += compteur + "\n";
        }
        textEditCompteurs->setText(texte);
    }
}

void Client::viderChamps()
{
    lineEditNom->clear();
    lineEditPrenom->clear();
    lineEditAdresse->clear();
    lineEditTelephone->clear();
    clientIdActuel = -1;
    tableauClients->clearSelection();
    textEditCompteurs->clear();
}

void Client::selectionnerClient()
{
    int ligneSelectionnee = tableauClients->currentRow();

    if (ligneSelectionnee >= 0) {
        clientIdActuel = tableauClients->item(ligneSelectionnee, 0)->text().toInt();
        lineEditNom->setText(tableauClients->item(ligneSelectionnee, 1)->text());
        lineEditPrenom->setText(tableauClients->item(ligneSelectionnee, 2)->text());
        lineEditAdresse->setText(tableauClients->item(ligneSelectionnee, 3)->text());
        lineEditTelephone->setText(tableauClients->item(ligneSelectionnee, 4)->text());
    }
}

void Client::actualiserListe()
{
    chargerClients();
    QMessageBox::information(this, "Information", "Liste actualisée!");
}
