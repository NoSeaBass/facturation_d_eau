#ifndef LISTEPRELEVEMENT_H
#define LISTEPRELEVEMENT_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>

namespace Ui {
class listePrelevement;
}

class listePrelevement : public QMainWindow
{
    Q_OBJECT

public:
    explicit listePrelevement(QWidget *parent = nullptr);
    ~listePrelevement();

private slots:
    void on_btnAjouterPrelevement_clicked();

    void on_btnActualiser_clicked();

private:
    Ui::listePrelevement *ui;
    void miseAJour();
    QSqlDatabase db;
};

#endif // LISTEPRELEVEMENT_H
