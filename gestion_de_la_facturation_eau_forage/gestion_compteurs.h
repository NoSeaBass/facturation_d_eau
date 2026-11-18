#ifndef GESTION_COMPTEURS_H
#define GESTION_COMPTEURS_H

#include <QMainWindow>

namespace Ui {
class gestion_compteurs;
}

class gestion_compteurs : public QMainWindow
{
    Q_OBJECT

public:
    explicit gestion_compteurs(QWidget *parent = nullptr);
    ~gestion_compteurs();

private slots:
    void on_pushButton_ajout_clicked();
    void on_pushButton_attribution_clicked();
    void on_pushButton_trans_archive_clicked();

private:
    Ui::gestion_compteurs *ui;
};

#endif // GESTION_COMPTEURS_H
