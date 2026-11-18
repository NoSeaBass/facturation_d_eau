#ifndef GESTIONFACTURES_H
#define GESTIONFACTURES_H

#include <QMainWindow>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui {
class gestionFactures;
}
QT_END_NAMESPACE

class gestionFactures : public QMainWindow
{
    Q_OBJECT

public:
    gestionFactures(QWidget *parent = nullptr);
    ~gestionFactures();

private:
    Ui::gestionFactures *ui;
    void mettreAJourTable();
    void facturer(int);
    void supprimerFacture(int);
    QSqlDatabase db;
};

#endif // GESTIONFACTURES_H
