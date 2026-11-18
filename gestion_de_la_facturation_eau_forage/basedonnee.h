#ifndef BASEDONNEE_H
#define BASEDONNEE_H



#include <QSqlDatabase>

class BaseDonnee {
public:
    static BaseDonnee& instance();
    void deconnecter();
    QSqlDatabase connecter();
    void creerTables();
    QSqlDatabase database();

private:
    BaseDonnee() = default;
    ~BaseDonnee() { deconnecter(); }
    QSqlDatabase m_db;
};



#endif // BASEDONNEE_H


