#ifndef CLIENTMODEL_H
#define CLIENTMODEL_H

#include <QString>

class ClientModel
{
public:
    ClientModel();
    ClientModel(int id, const QString& nom, const QString& prenom,
                const QString& adresse, const QString& telephone);

    int getId() const { return idClient; }
    QString getNom() const { return nom; }
    QString getPrenom() const { return prenom; }
    QString getAdresse() const { return adresse; }
    QString getTelephone() const { return telephone; }

    void setId(int id) { idClient = id; }
    void setNom(const QString& n) { nom = n; }
    void setPrenom(const QString& p) { prenom = p; }
    void setAdresse(const QString& a) { adresse = a; }
    void setTelephone(const QString& t) { telephone = t; }

private:
    int idClient;
    QString nom;
    QString prenom;
    QString adresse;
    QString telephone;
};

#endif // CLIENTMODEL_H
