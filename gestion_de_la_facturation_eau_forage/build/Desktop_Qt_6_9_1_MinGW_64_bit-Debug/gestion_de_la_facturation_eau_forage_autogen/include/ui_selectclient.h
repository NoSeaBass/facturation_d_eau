/********************************************************************************
** Form generated from reading UI file 'selectclient.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTCLIENT_H
#define UI_SELECTCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SelectClient
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableClients;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SelectClient)
    {
        if (SelectClient->objectName().isEmpty())
            SelectClient->setObjectName("SelectClient");
        SelectClient->resize(400, 300);
        verticalLayout = new QVBoxLayout(SelectClient);
        verticalLayout->setObjectName("verticalLayout");
        tableClients = new QTableWidget(SelectClient);
        tableClients->setObjectName("tableClients");
        tableClients->setColumnCount(3);
        tableClients->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableClients->setSelectionMode(QAbstractItemView::SingleSelection);

        verticalLayout->addWidget(tableClients);

        buttonBox = new QDialogButtonBox(SelectClient);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(SelectClient);

        QMetaObject::connectSlotsByName(SelectClient);
    } // setupUi

    void retranslateUi(QDialog *SelectClient)
    {
        SelectClient->setWindowTitle(QCoreApplication::translate("SelectClient", "S\303\251lection Client", nullptr));
        tableClients->setHorizontalHeaderLabels(QStringList{
            QCoreApplication::translate("SelectClient", "ID", nullptr),
            QCoreApplication::translate("SelectClient", "Nom", nullptr),
            QCoreApplication::translate("SelectClient", "Pr\303\251nom", nullptr)});
    } // retranslateUi

};

namespace Ui {
    class SelectClient: public Ui_SelectClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTCLIENT_H
