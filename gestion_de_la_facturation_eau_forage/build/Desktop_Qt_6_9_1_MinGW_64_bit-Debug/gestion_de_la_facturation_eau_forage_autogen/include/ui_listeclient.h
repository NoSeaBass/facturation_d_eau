/********************************************************************************
** Form generated from reading UI file 'listeclient.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTECLIENT_H
#define UI_LISTECLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_listeclient
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *listeclient)
    {
        if (listeclient->objectName().isEmpty())
            listeclient->setObjectName("listeclient");
        listeclient->resize(800, 600);
        centralwidget = new QWidget(listeclient);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(9, 9, 9, 9);
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setShowGrid(false);
        tableView->setAlternatingRowColors(true);
        tableView->setWordWrap(false);
        tableView->horizontalHeader()->setVisible(true);
        tableView->horizontalHeader()->setCascadingSectionResizes(true);
        tableView->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(tableView);

        listeclient->setCentralWidget(centralwidget);
        menubar = new QMenuBar(listeclient);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        listeclient->setMenuBar(menubar);
        statusbar = new QStatusBar(listeclient);
        statusbar->setObjectName("statusbar");
        listeclient->setStatusBar(statusbar);

        retranslateUi(listeclient);

        QMetaObject::connectSlotsByName(listeclient);
    } // setupUi

    void retranslateUi(QMainWindow *listeclient)
    {
        listeclient->setWindowTitle(QCoreApplication::translate("listeclient", "Liste des clients", nullptr));
    } // retranslateUi

};

namespace Ui {
    class listeclient: public Ui_listeclient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTECLIENT_H
