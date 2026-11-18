#include "DatabaseManager.h"
#include <QStandardPaths>
#include <QDir>

DatabaseManager* DatabaseManager::instance = nullptr;

DatabaseManager::DatabaseManager()
{
}

DatabaseManager::~DatabaseManager()
{
    disconnectFromDatabase();
}

DatabaseManager* DatabaseManager::getInstance()
{
    if (!instance) {
        instance = new DatabaseManager();
    }
    return instance;
}

bool DatabaseManager::connectToDatabase()
{

    QString dbPath = "gestion_eau.db";
    qDebug() << "Chemin de la base de données:" << dbPath;

    if (QSqlDatabase::contains(QSqlDatabase::defaultConnection)) {
        QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
    }

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);

    if (!db.open()) {
        qDebug() << "Erreur de connexion à la base de données:" << db.lastError().text();
        return false;
    }

    qDebug() << "Connexion à la base de données réussie";
    qDebug() << "Base de données:" << db.databaseName();
    qDebug() << "Driver:" << db.driverName();

    if (!db.isOpen()) {
        qDebug() << "Base de données non ouverte pour créer les tables!";
        return false;
    }

    QSqlQuery query(db);

    QString createClientTable = R"(
        CREATE TABLE IF NOT EXISTS Client (
            idClient INTEGER PRIMARY KEY AUTOINCREMENT,
            nom VARCHAR(100) NOT NULL,
            prenom VARCHAR(100) NOT NULL,
            adresse TEXT,
            telephone VARCHAR(20),
            created_at DATETIME DEFAULT CURRENT_TIMESTAMP
        )
    )";

    qDebug() << "Création de la table Client...";
    if (!query.exec(createClientTable)) {
        qDebug() << "ERREUR création table Client:" << query.lastError().text();
        qDebug() << "Requête:" << createClientTable;
        return false;
    }
    qDebug() << "Table Client créée avec succès";

    QString createCompteurTable = R"(
        CREATE TABLE IF NOT EXISTS Compteur (
            numCompteur VARCHAR(50) PRIMARY KEY,
            marque VARCHAR(100),
            modele VARCHAR(100),
            date_installation DATE,
            etat VARCHAR(20) DEFAULT 'Actif',
            created_at DATETIME DEFAULT CURRENT_TIMESTAMP
        )
    )";

    if (!query.exec(createCompteurTable)) {
        qDebug() << "ERREUR création table Compteur:" << query.lastError().text();
        return false;
    }
    qDebug() << "Table Compteur créée avec succès";

    QString createAbonnementTable = R"(
        CREATE TABLE IF NOT EXISTS Abonnement (
            idAbonnement INTEGER PRIMARY KEY AUTOINCREMENT,
            idClient INTEGER NOT NULL,
            numCompteur VARCHAR(50) NOT NULL,
            date_abonnement DATE NOT NULL,
            date_fin DATE,
            type_abonnement VARCHAR(50) DEFAULT 'Standard',
            actif BOOLEAN DEFAULT 1,
            created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
            FOREIGN KEY (idClient) REFERENCES Client(idClient) ON DELETE CASCADE,
            FOREIGN KEY (numCompteur) REFERENCES Compteur(numCompteur) ON DELETE CASCADE
        )
    )";

    if (!query.exec(createAbonnementTable)) {
        qDebug() << "ERREUR création table Abonnement:" << query.lastError().text();
        return false;
    }
    qDebug() << "Table Abonnement créée avec succès";

    QSqlQuery countQuery("SELECT COUNT(*) FROM Client", db);
    if (countQuery.exec() && countQuery.next()) {
        int count = countQuery.value(0).toInt();
        if (count == 0) {
            qDebug() << "Insertion de données de test...";

            QSqlQuery insertClient(db);
            insertClient.prepare("INSERT INTO Client (nom, prenom, adresse, telephone) VALUES (?, ?, ?, ?)");

            QStringList noms = {"Diop", "Fall", "Ndiaye", "Seck"};
            QStringList prenoms = {"Moussa", "Fatou", "Amadou", "Aïcha"};
            QStringList adresses = {"Dakar Plateau", "Pikine", "Guédiawaye", "Parcelles Assainies"};
            QStringList telephones = {"77 123 45 67", "70 987 65 43", "76 555 44 33", "78 111 22 33"};

            for (int i = 0; i < 4; ++i) {
                insertClient.addBindValue(noms[i]);
                insertClient.addBindValue(prenoms[i]);
                insertClient.addBindValue(adresses[i]);
                insertClient.addBindValue(telephones[i]);

                if (!insertClient.exec()) {
                    qDebug() << "Erreur insertion client test:" << insertClient.lastError().text();
                } else {
                    qDebug() << "Client test ajouté:" << noms[i] << prenoms[i];
                }
            }
        }
    }

    QSqlQuery tablesQuery("SELECT name FROM sqlite_master WHERE type='table'", db);
    qDebug() << "=== TABLES DISPONIBLES APRÈS CRÉATION ===";
    QStringList tables;
    while (tablesQuery.next()) {
        QString tableName = tablesQuery.value(0).toString();
        tables.append(tableName);
        qDebug() << "Table trouvée:" << tableName;

        QSqlQuery structQuery(QString("PRAGMA table_info(%1)").arg(tableName), db);
        while (structQuery.next()) {
            qDebug() << "  Colonne:" << structQuery.value(1).toString()
            << "Type:" << structQuery.value(2).toString();
        }

        QSqlQuery countQuery(QString("SELECT COUNT(*) FROM %1").arg(tableName), db);
        if (countQuery.exec() && countQuery.next()) {
            qDebug() << "  Enregistrements:" << countQuery.value(0).toInt();
        }
    }
    qDebug() << "Nombre total de tables:" << tables.size();

    if (tables.isEmpty()) {
        qDebug() << "ATTENTION: Aucune table trouvée même après création!";
        qDebug() << "Erreur de la requête:" << tablesQuery.lastError().text();
        return false;
    }

    return true;
}

void DatabaseManager::disconnectFromDatabase()
{
    if (db.isOpen()) {
        db.close();
        qDebug() << "Base de données fermée";
    }
}

bool DatabaseManager::ajouterClient(const ClientModel& client)
{
    QSqlQuery query(db);
    query.prepare("INSERT INTO Client (nom, prenom, adresse, telephone) VALUES (?, ?, ?, ?)");

    query.addBindValue(client.getNom());
    query.addBindValue(client.getPrenom());
    query.addBindValue(client.getAdresse());
    query.addBindValue(client.getTelephone());

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout du client:" << query.lastError().text();
        return false;
    }

    qDebug() << "Client ajouté avec succès! ID:" << query.lastInsertId().toInt();
    return true;
}

QList<ClientModel> DatabaseManager::obtenirTousLesClients()
{
    QList<ClientModel> clients;
    QSqlQuery query("SELECT idClient, nom, prenom, adresse, telephone FROM Client ORDER BY nom, prenom", db);

    if (!query.exec()) {
        qDebug() << "Erreur requête clients:" << query.lastError().text();
        return clients;
    }

    while (query.next()) {
        ClientModel client;
        client.setId(query.value(0).toInt());
        client.setNom(query.value(1).toString());
        client.setPrenom(query.value(2).toString());
        client.setAdresse(query.value(3).toString());
        client.setTelephone(query.value(4).toString());

        clients.append(client);
    }

    qDebug() << "Nombre de clients récupérés:" << clients.size();
    return clients;
}

bool DatabaseManager::modifierClient(const ClientModel& client)
{
    QSqlQuery query(db);
    query.prepare("UPDATE Client SET nom = ?, prenom = ?, adresse = ?, telephone = ? WHERE idClient = ?");

    query.addBindValue(client.getNom());
    query.addBindValue(client.getPrenom());
    query.addBindValue(client.getAdresse());
    query.addBindValue(client.getTelephone());
    query.addBindValue(client.getId());

    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification du client:" << query.lastError().text();
        return false;
    }

    qDebug() << "Client modifié avec succès. Lignes affectées:" << query.numRowsAffected();
    return query.numRowsAffected() > 0;
}

bool DatabaseManager::supprimerClient(int idClient)
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM Client WHERE idClient = ?");
    query.addBindValue(idClient);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression du client:" << query.lastError().text();
        return false;
    }

    qDebug() << "Client supprimé. Lignes affectées:" << query.numRowsAffected();
    return query.numRowsAffected() > 0;
}

QList<ClientModel> DatabaseManager::trierClientsParCollectivite()
{
    QList<ClientModel> clients;
    QSqlQuery query("SELECT idClient, nom, prenom, adresse, telephone FROM Client ORDER BY adresse ASC, nom ASC", db);

    if (!query.exec()) {
        qDebug() << "Erreur requête tri clients:" << query.lastError().text();
        return clients;
    }

    while (query.next()) {
        ClientModel client;
        client.setId(query.value(0).toInt());
        client.setNom(query.value(1).toString());
        client.setPrenom(query.value(2).toString());
        client.setAdresse(query.value(3).toString());
        client.setTelephone(query.value(4).toString());

        clients.append(client);
    }

    return clients;
}

QStringList DatabaseManager::obtenirCompteursClient(int idClient)
{
    QStringList compteurs;
    QSqlQuery query(db);

    query.prepare("SELECT c.numCompteur, a.date_abonnement "
                  "FROM Compteur c "
                  "INNER JOIN Abonnement a ON c.numCompteur = a.numCompteur "
                  "WHERE a.idClient = ?");

    query.addBindValue(idClient);

    qDebug() << "Exécution de la requête pour les compteurs du client ID:" << idClient;
    if (query.exec()) {
        while (query.next()) {
            QString info = QString("Compteur: %1 - Date: %2")
            .arg(query.value(0).toString())
                .arg(query.value(1).toString());
            compteurs.append(info);
        }
        qDebug() << "Requête réussie. Nombre de compteurs trouvés:" << compteurs.size();
    } else {
        qDebug() << "Erreur requête compteurs:" << query.lastError().text();
    }

    return compteurs;
}

