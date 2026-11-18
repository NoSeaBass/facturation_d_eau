#ifndef TRANS_ARCHIVE_H
#define TRANS_ARCHIVE_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class TransArchive;
}

class TransArchive : public QDialog
{
    Q_OBJECT

public:
    explicit TransArchive(QWidget *parent = nullptr);
    ~TransArchive();

private slots:
    void chargerCompteursAssocies();
    void archiverCompteur();
    void transfererCompteur();

    void on_btnNouvelAbonnement_clicked();

private:
    Ui::TransArchive *ui;
    QSqlDatabase db;
};

#endif // TRANS_ARCHIVE_H
