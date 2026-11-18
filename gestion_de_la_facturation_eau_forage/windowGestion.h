#ifndef WINDOWGESTION_H
#define WINDOWGESTION_H

#include <QMainWindow>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class WindowGestion; }
QT_END_NAMESPACE

class WindowGestion : public QMainWindow
{
    Q_OBJECT

public:
    WindowGestion(QWidget *parent = nullptr);
    ~WindowGestion();

private slots:
    void ajouterCompteur();

private:
    Ui::WindowGestion *ui;
    QSqlTableModel *modelCompteur;
};

#endif // WINDOWGESTION_H
