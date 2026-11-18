#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QList>
#include <QDebug>
#include "ClientModel.h"

class DatabaseManager
{
public:
    static DatabaseManager* getInstance();

    bool connectToDatabase();
    void disconnectFromDatabase();

    bool ajouterClient(const ClientModel& client);
    QList<ClientModel> obtenirTousLesClients();
    bool modifierClient(const ClientModel& client);
    bool supprimerClient(int idClient);
    QList<ClientModel> trierClientsParCollectivite();

    QStringList obtenirCompteursClient(int idClient);

private:
    DatabaseManager();
    ~DatabaseManager();
    static DatabaseManager* instance;
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
