#ifndef NOUVELLEFACTURE_H
#define NOUVELLEFACTURE_H

#include <QDialog>
#include <QSqlDatabase>
#include <QtSql>
#include <QMessageBox>

namespace Ui {
class nouvellefacture;
}

class nouvellefacture : public QDialog
{
    Q_OBJECT

public:
    explicit nouvellefacture(QSqlDatabase &db, QWidget *parent = nullptr);
    ~nouvellefacture();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::nouvellefacture *ui;
    QSqlDatabase db;
    void remplirComboBoxes();
};

#endif // NOUVELLEFACTURE_H
