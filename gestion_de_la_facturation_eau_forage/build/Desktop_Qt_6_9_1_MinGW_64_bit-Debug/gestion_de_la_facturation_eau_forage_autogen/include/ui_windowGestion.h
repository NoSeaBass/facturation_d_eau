/********************************************************************************
** Form generated from reading UI file 'windowGestion.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWGESTION_H
#define UI_WINDOWGESTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowGestion
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_main;
    QGroupBox *groupBoxForm;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEditSerie;
    QPushButton *btnAjouterCompteur;
    QGroupBox *groupBoxTable;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableViewCompteur;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_main = new QVBoxLayout(centralwidget);
        verticalLayout_main->setObjectName("verticalLayout_main");
        groupBoxForm = new QGroupBox(centralwidget);
        groupBoxForm->setObjectName("groupBoxForm");
        verticalLayout = new QVBoxLayout(groupBoxForm);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(groupBoxForm);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        lineEditSerie = new QLineEdit(groupBoxForm);
        lineEditSerie->setObjectName("lineEditSerie");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEditSerie);


        verticalLayout->addLayout(formLayout);

        btnAjouterCompteur = new QPushButton(groupBoxForm);
        btnAjouterCompteur->setObjectName("btnAjouterCompteur");

        verticalLayout->addWidget(btnAjouterCompteur);


        verticalLayout_main->addWidget(groupBoxForm);

        groupBoxTable = new QGroupBox(centralwidget);
        groupBoxTable->setObjectName("groupBoxTable");
        verticalLayout_2 = new QVBoxLayout(groupBoxTable);
        verticalLayout_2->setObjectName("verticalLayout_2");
        tableViewCompteur = new QTableView(groupBoxTable);
        tableViewCompteur->setObjectName("tableViewCompteur");

        verticalLayout_2->addWidget(tableViewCompteur);


        verticalLayout_main->addWidget(groupBoxTable);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("WindowGestion", "Gestion des compteurs", nullptr));
        groupBoxForm->setTitle(QCoreApplication::translate("WindowGestion", "Ajouter un compteur", nullptr));
        label->setText(QCoreApplication::translate("WindowGestion", "S\303\251rie :", nullptr));
        btnAjouterCompteur->setText(QCoreApplication::translate("WindowGestion", "Ajouter compteur", nullptr));
        groupBoxTable->setTitle(QCoreApplication::translate("WindowGestion", "Liste des compteurs", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowGestion: public Ui_WindowGestion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWGESTION_H
