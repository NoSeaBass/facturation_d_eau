#ifndef ASSOCIATION_H
#define ASSOCIATION_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class Association;
}

class Association : public QDialog
{
    Q_OBJECT

public:
    explicit Association(QSqlDatabase db, QWidget *parent = nullptr);
    ~Association();

private slots:
    void chargerClients();
    void chargerCompteurs();
    void associerCompteurAuClient();

private:
    Ui::Association *ui;
    QSqlDatabase db;
};

#endif // ASSOCIATION_H
