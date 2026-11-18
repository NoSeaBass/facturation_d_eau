#include "basedonnee.h"
#include <QSqlError>
#include <QDebug>

BaseDonnee& BaseDonnee::instance() {
    static BaseDonnee instance;
    return instance;
}

QSqlDatabase BaseDonnee::connecter() {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("gestion_eau.db");
    return m_db;
}

void BaseDonnee::deconnecter() {
    if (m_db.isOpen()) {
        m_db.close();
        qDebug() << "Déconnexion de la base de données réussie.";
    }
}

QSqlDatabase BaseDonnee::database() {
    return m_db;
}
