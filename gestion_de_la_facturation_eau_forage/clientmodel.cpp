#include "ClientModel.h"

ClientModel::ClientModel()
    : idClient(0), nom(""), prenom(""), adresse(""), telephone("")
{
}

ClientModel::ClientModel(int id, const QString& nom, const QString& prenom,
                         const QString& adresse, const QString& telephone)
    : idClient(id), nom(nom), prenom(prenom), adresse(adresse), telephone(telephone)
{
}
