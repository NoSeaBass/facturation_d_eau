#ifndef APPLICATION_H
#define APPLICATION_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

#include "gestionfactures.h"
#include "windowGestion.h"
#include "listeclient.h"
#include "client.h"
#include "trans_archive.h"
#include "listeprelevement.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class application;
}
QT_END_NAMESPACE

class application : public QMainWindow
{
    Q_OBJECT

public:
    application(QWidget *parent = nullptr);
    ~application();

private slots:
    void on_btnGestionClients_clicked();
    void on_btnGestionCompteurs_clicked();
    void on_btnGestionFactures_clicked();
    void on_btnListePrelevements_clicked();
    void on_btnListeAbonnements_clicked();
    void on_btnFermer_clicked();

private:
    Ui::application *ui;
};

#endif // APPLICATION_H
