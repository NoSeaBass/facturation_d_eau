#include "listeclient.h"
#include "ui_listeclient.h"

listeclient::listeclient(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::listeclient)
{
    ui->setupUi(this);
}

listeclient::~listeclient()
{
    delete ui;
}
