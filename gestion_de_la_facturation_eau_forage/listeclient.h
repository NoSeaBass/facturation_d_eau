#ifndef LISTECLIENT_H
#define LISTECLIENT_H

#include <QMainWindow>

namespace Ui {
class listeclient;
}

class listeclient : public QMainWindow
{
    Q_OBJECT

public:
    explicit listeclient(QWidget *parent = nullptr);
    ~listeclient();

private:
    Ui::listeclient *ui;
};

#endif // LISTECLIENT_H
