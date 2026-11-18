/********************************************************************************
** Form generated from reading UI file 'gestionfactures.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTIONFACTURES_H
#define UI_GESTIONFACTURES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gestionFactures
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_main;
    QVBoxLayout *contentLayout;
    QLabel *titleLabel;
    QTableWidget *tableFactures;
    QHBoxLayout *horizontalLayout;
    QPushButton *nouvelleFacture;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QLabel *infoLabel;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuEdition;
    QMenu *menuAide;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *gestionFactures)
    {
        if (gestionFactures->objectName().isEmpty())
            gestionFactures->setObjectName("gestionFactures");
        gestionFactures->resize(1200, 800);
        gestionFactures->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-color: palette(window);\n"
"}\n"
"\n"
"QWidget#centralwidget {\n"
"    background-color: palette(window);\n"
"}\n"
"\n"
"QTableWidget {\n"
"    background-color: palette(base);\n"
"    border: 1px solid palette(mid);\n"
"    border-radius: 6px;\n"
"    gridline-color: palette(midlight);\n"
"    selection-background-color: palette(highlight);\n"
"    selection-color: palette(highlighted-text);\n"
"    font-size: 11pt;\n"
"    outline: none;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    border: none;\n"
"    border-bottom: 1px solid palette(midlight);\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: palette(highlight);\n"
"    color: palette(highlighted-text);\n"
"}\n"
"\n"
"QTableWidget::item:hover {\n"
"    background-color: palette(midlight);\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: palette(button);\n"
"    color: palette(buttonText);\n"
"    border: none;\n"
"    border-bottom: 2px solid palette(mid);\n"
"    border-right: 1px solid "
                        "palette(mid);\n"
"    font-weight: 600;\n"
"    font-size: 11pt;\n"
"}\n"
"\n"
"QHeaderView::section:hover {\n"
"    background-color: palette(midlight);\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: palette(button);\n"
"    color: palette(buttonText);\n"
"    border: 1px solid palette(mid);\n"
"    border-radius: 6px;\n"
"    font-size: 11pt;\n"
"    font-weight: 500;\n"
"    min-height: 16px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: palette(midlight);\n"
"    border-color: palette(dark);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: palette(mid);\n"
"}\n"
"\n"
"QPushButton#nouvelleFacture {\n"
"    background-color: #2563eb;\n"
"    color: white;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton#nouvelleFacture:hover {\n"
"    background-color: #1d4ed8;\n"
"}\n"
"\n"
"QPushButton#nouvelleFacture:pressed {\n"
"    background-color: #1e40af;\n"
"}\n"
"\n"
"QPushButton#pushButton {\n"
"    background-color: palette(button);\n"
"    border: 1px solid palette(mid);\n"
""
                        "}\n"
"\n"
"/* Styles globaux pour tous les boutons dans les cellules du tableau */\n"
"QTableWidget QWidget QPushButton {\n"
"    background-color: palette(button);\n"
"    color: palette(buttonText);\n"
"}\n"
"\n"
"QTableWidget QWidget QPushButton:hover {\n"
"    background-color: palette(midlight);\n"
"    border-color: palette(dark);\n"
"}\n"
"\n"
"QTableWidget QWidget QPushButton:pressed {\n"
"    background-color: palette(mid);\n"
"}\n"
"\n"
"/* Styles pour les widgets conteneurs dans les cellules */\n"
"QTableWidget QWidget {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"}\n"
"\n"
"QLabel#titleLabel {\n"
"    color: palette(windowText);\n"
"    font-size: 24pt;\n"
"    font-weight: 600;\n"
"    margin: 0px;\n"
"    padding: 20px 0px;\n"
"}\n"
"\n"
"QLabel#infoLabel {\n"
"    color: palette(mid);\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"QMenuBar {\n"
"    background-color: palette(window);\n"
"    color: palette(windowText);\n"
"    border-bottom: 1px solid palette(mid);\n"
"}\n"
"\n"
"Q"
                        "MenuBar::item {\n"
"    background-color: transparent;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background-color: palette(highlight);\n"
"    color: palette(highlighted-text);\n"
"}\n"
"\n"
"QStatusBar {\n"
"    background-color: palette(window);\n"
"    border-top: 1px solid palette(mid);\n"
"    color: palette(windowText);\n"
"    padding: 4px;\n"
"}"));
        centralwidget = new QWidget(gestionFactures);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_main = new QVBoxLayout(centralwidget);
        verticalLayout_main->setSpacing(0);
        verticalLayout_main->setObjectName("verticalLayout_main");
        verticalLayout_main->setContentsMargins(0, 0, 0, 0);
        contentLayout = new QVBoxLayout();
        contentLayout->setSpacing(24);
        contentLayout->setObjectName("contentLayout");
        contentLayout->setContentsMargins(32, 32, 32, 32);
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        contentLayout->addWidget(titleLabel);

        tableFactures = new QTableWidget(centralwidget);
        if (tableFactures->columnCount() < 8)
            tableFactures->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableFactures->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableFactures->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableFactures->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableFactures->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableFactures->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableFactures->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableFactures->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableFactures->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableFactures->setObjectName("tableFactures");
        tableFactures->setMinimumSize(QSize(0, 450));
        tableFactures->setAlternatingRowColors(true);
        tableFactures->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tableFactures->setShowGrid(false);
        tableFactures->setSortingEnabled(true);
        tableFactures->setCornerButtonEnabled(false);
        tableFactures->horizontalHeader()->setDefaultSectionSize(140);
        tableFactures->horizontalHeader()->setStretchLastSection(true);
        tableFactures->verticalHeader()->setVisible(false);

        contentLayout->addWidget(tableFactures);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(16);
        horizontalLayout->setObjectName("horizontalLayout");
        nouvelleFacture = new QPushButton(centralwidget);
        nouvelleFacture->setObjectName("nouvelleFacture");

        horizontalLayout->addWidget(nouvelleFacture);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        infoLabel = new QLabel(centralwidget);
        infoLabel->setObjectName("infoLabel");

        horizontalLayout->addWidget(infoLabel);


        contentLayout->addLayout(horizontalLayout);


        verticalLayout_main->addLayout(contentLayout);

        gestionFactures->setCentralWidget(centralwidget);
        menubar = new QMenuBar(gestionFactures);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 24));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName("menuFichier");
        menuEdition = new QMenu(menubar);
        menuEdition->setObjectName("menuEdition");
        menuAide = new QMenu(menubar);
        menuAide->setObjectName("menuAide");
        gestionFactures->setMenuBar(menubar);
        statusbar = new QStatusBar(gestionFactures);
        statusbar->setObjectName("statusbar");
        gestionFactures->setStatusBar(statusbar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuEdition->menuAction());
        menubar->addAction(menuAide->menuAction());

        retranslateUi(gestionFactures);

        QMetaObject::connectSlotsByName(gestionFactures);
    } // setupUi

    void retranslateUi(QMainWindow *gestionFactures)
    {
        gestionFactures->setWindowTitle(QCoreApplication::translate("gestionFactures", "Gestion des Factures", nullptr));
        titleLabel->setText(QCoreApplication::translate("gestionFactures", "\360\237\222\247 Gestion des Factures d'Eau", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableFactures->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("gestionFactures", "ID Facture", nullptr));
#if QT_CONFIG(tooltip)
        ___qtablewidgetitem->setToolTip(QCoreApplication::translate("gestionFactures", "Identifiant unique de la facture", nullptr));
#endif // QT_CONFIG(tooltip)
        QTableWidgetItem *___qtablewidgetitem1 = tableFactures->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("gestionFactures", "Num\303\251ro Compteur", nullptr));
#if QT_CONFIG(tooltip)
        ___qtablewidgetitem1->setToolTip(QCoreApplication::translate("gestionFactures", "Num\303\251ro du compteur d'eau", nullptr));
#endif // QT_CONFIG(tooltip)
        QTableWidgetItem *___qtablewidgetitem2 = tableFactures->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("gestionFactures", "ID Client", nullptr));
#if QT_CONFIG(tooltip)
        ___qtablewidgetitem2->setToolTip(QCoreApplication::translate("gestionFactures", "Identifiant du client", nullptr));
#endif // QT_CONFIG(tooltip)
        QTableWidgetItem *___qtablewidgetitem3 = tableFactures->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("gestionFactures", "Solde Ant\303\251rieur", nullptr));
#if QT_CONFIG(tooltip)
        ___qtablewidgetitem3->setToolTip(QCoreApplication::translate("gestionFactures", "Montant du solde pr\303\251c\303\251dent", nullptr));
#endif // QT_CONFIG(tooltip)
        QTableWidgetItem *___qtablewidgetitem4 = tableFactures->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("gestionFactures", "Consommation", nullptr));
#if QT_CONFIG(tooltip)
        ___qtablewidgetitem4->setToolTip(QCoreApplication::translate("gestionFactures", "Consommation en m\302\263", nullptr));
#endif // QT_CONFIG(tooltip)
        QTableWidgetItem *___qtablewidgetitem5 = tableFactures->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("gestionFactures", "Tarif Total", nullptr));
#if QT_CONFIG(tooltip)
        ___qtablewidgetitem5->setToolTip(QCoreApplication::translate("gestionFactures", "Montant total calcul\303\251", nullptr));
#endif // QT_CONFIG(tooltip)
        QTableWidgetItem *___qtablewidgetitem6 = tableFactures->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("gestionFactures", "Statut", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableFactures->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("gestionFactures", "Actions", nullptr));
#if QT_CONFIG(tooltip)
        ___qtablewidgetitem7->setToolTip(QCoreApplication::translate("gestionFactures", "Actions disponibles pour cette facture", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        nouvelleFacture->setToolTip(QCoreApplication::translate("gestionFactures", "Cr\303\251er une nouvelle facture", nullptr));
#endif // QT_CONFIG(tooltip)
        nouvelleFacture->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton->setToolTip(QCoreApplication::translate("gestionFactures", "Actualiser la liste des factures", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton->setText(QString());
        infoLabel->setText(QString());
        menuFichier->setTitle(QCoreApplication::translate("gestionFactures", "Fichier", nullptr));
        menuEdition->setTitle(QCoreApplication::translate("gestionFactures", "\303\211dition", nullptr));
        menuAide->setTitle(QCoreApplication::translate("gestionFactures", "Aide", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gestionFactures: public Ui_gestionFactures {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTIONFACTURES_H
