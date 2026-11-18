/********************************************************************************
** Form generated from reading UI file 'trans_archive.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANS_ARCHIVE_H
#define UI_TRANS_ARCHIVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TransArchive
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableCompteurs;
    QHBoxLayout *buttonLayout;
    QPushButton *btnArchiver;
    QPushButton *btnTransferer;
    QPushButton *btnNouvelAbonnement;

    void setupUi(QDialog *TransArchive)
    {
        if (TransArchive->objectName().isEmpty())
            TransArchive->setObjectName("TransArchive");
        TransArchive->resize(600, 400);
        verticalLayout = new QVBoxLayout(TransArchive);
        verticalLayout->setObjectName("verticalLayout");
        tableCompteurs = new QTableWidget(TransArchive);
        if (tableCompteurs->columnCount() < 4)
            tableCompteurs->setColumnCount(4);
        tableCompteurs->setObjectName("tableCompteurs");
        tableCompteurs->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        tableCompteurs->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tableCompteurs->setColumnCount(4);

        verticalLayout->addWidget(tableCompteurs);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        btnArchiver = new QPushButton(TransArchive);
        btnArchiver->setObjectName("btnArchiver");

        buttonLayout->addWidget(btnArchiver);

        btnTransferer = new QPushButton(TransArchive);
        btnTransferer->setObjectName("btnTransferer");

        buttonLayout->addWidget(btnTransferer);

        btnNouvelAbonnement = new QPushButton(TransArchive);
        btnNouvelAbonnement->setObjectName("btnNouvelAbonnement");

        buttonLayout->addWidget(btnNouvelAbonnement);


        verticalLayout->addLayout(buttonLayout);


        retranslateUi(TransArchive);

        QMetaObject::connectSlotsByName(TransArchive);
    } // setupUi

    void retranslateUi(QDialog *TransArchive)
    {
        TransArchive->setWindowTitle(QCoreApplication::translate("TransArchive", "Gestion archivage & transfert", nullptr));
        tableCompteurs->setProperty("horizontalHeaderLabels", QVariant(QStringList{
            QCoreApplication::translate("TransArchive", "Num\303\251ro", nullptr),
            QCoreApplication::translate("TransArchive", "Client", nullptr),
            QCoreApplication::translate("TransArchive", "Date abonnement", nullptr),
            QCoreApplication::translate("TransArchive", "\303\211tat", nullptr)}));
        btnArchiver->setText(QCoreApplication::translate("TransArchive", "Supprimer", nullptr));
        btnTransferer->setText(QCoreApplication::translate("TransArchive", "Transf\303\251rer", nullptr));
        btnNouvelAbonnement->setText(QCoreApplication::translate("TransArchive", "Nouvelle abonnement", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TransArchive: public Ui_TransArchive {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANS_ARCHIVE_H
