/********************************************************************************
** Form generated from reading UI file 'application.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLICATION_H
#define UI_APPLICATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_application
{
public:
    QAction *actionNouveau;
    QAction *actionOuvrir;
    QAction *actionQuitter;
    QAction *actionA_propos;
    QWidget *centralwidget;
    QVBoxLayout *mainLayout;
    QLineEdit *titleLabel;
    QSpacerItem *topSpacer;
    QHBoxLayout *mainContentLayout;
    QFrame *cardFrame;
    QVBoxLayout *gestionLayout;
    QLabel *gestionTitle;
    QVBoxLayout *gestionButtonsGrid;
    QPushButton *btnGestionClients;
    QPushButton *btnGestionCompteurs;
    QPushButton *btnGestionFactures;
    QSpacerItem *gestionSpacer;
    QFrame *cardFrame_2;
    QVBoxLayout *listesLayout;
    QLabel *listesTitle;
    QVBoxLayout *listeButtonsGrid;
    QPushButton *btnListePrelevements;
    QPushButton *btnListeAbonnements;
    QSpacerItem *listesSpacer;
    QSpacerItem *bottomSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnFermer;
    QMenuBar *menubar;
    QMenu *menuAide;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *application)
    {
        if (application->objectName().isEmpty())
            application->setObjectName("application");
        application->resize(1000, 700);
        application->setMinimumSize(QSize(900, 650));
        application->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-color: palette(window);\n"
"}\n"
"\n"
"QWidget#centralwidget {\n"
"    background: palette(window);\n"
"}\n"
"\n"
"QLineEdit#titleLabel {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                               stop: 0 palette(highlight),\n"
"                               stop: 1 palette(dark));\n"
"    color: palette(highlighted-text);\n"
"    font-size: 24px;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"    border-radius: 15px;\n"
"    padding: 20px;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QFrame#cardFrame, QFrame#cardFrame_2 {\n"
"    background-color: palette(base);\n"
"    border: 2px solid palette(mid);\n"
"    border-radius: 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QFrame#cardFrame:hover, QFrame#cardFrame_2:hover {\n"
"    border-color: palette(highlight);\n"
"    background-color: palette(alternate-base);\n"
"}\n"
"\n"
"QLabel#gestionTitle, QLabel#listesTitle {\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    color: pale"
                        "tte(text);\n"
"    padding: 15px;\n"
"    margin: 0px;\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: palette(button);\n"
"    color: palette(button-text);\n"
"    border: 2px solid palette(mid);\n"
"    border-radius: 8px;\n"
"    padding: 12px 20px;\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    min-width: 180px;\n"
"    min-height: 40px;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: palette(highlight);\n"
"    color: palette(highlighted-text);\n"
"    border-color: palette(highlight);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: palette(dark);\n"
"}\n"
"\n"
"QMenuBar {\n"
"    background-color: palette(window);\n"
"    color: palette(window-text);\n"
"    border-bottom: 1px solid palette(mid);\n"
"    font-size: 14px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QMenuBar::item {\n"
"    padding: 8px 16px;\n"
"    background-color: transparent;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background-color: "
                        "palette(highlight);\n"
"    color: palette(highlighted-text);\n"
"}\n"
"\n"
"QStatusBar {\n"
"    background-color: palette(window);\n"
"    color: palette(window-text);\n"
"    border-top: 1px solid palette(mid);\n"
"    font-size: 12px;\n"
"    padding: 5px;\n"
"}"));
        actionNouveau = new QAction(application);
        actionNouveau->setObjectName("actionNouveau");
        actionOuvrir = new QAction(application);
        actionOuvrir->setObjectName("actionOuvrir");
        actionQuitter = new QAction(application);
        actionQuitter->setObjectName("actionQuitter");
        actionA_propos = new QAction(application);
        actionA_propos->setObjectName("actionA_propos");
        centralwidget = new QWidget(application);
        centralwidget->setObjectName("centralwidget");
        mainLayout = new QVBoxLayout(centralwidget);
        mainLayout->setSpacing(25);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(40, 30, 40, 30);
        titleLabel = new QLineEdit(centralwidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setMaximumSize(QSize(16777215, 85));
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        titleLabel->setReadOnly(true);

        mainLayout->addWidget(titleLabel);

        topSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        mainLayout->addItem(topSpacer);

        mainContentLayout = new QHBoxLayout();
        mainContentLayout->setSpacing(20);
        mainContentLayout->setObjectName("mainContentLayout");
        cardFrame = new QFrame(centralwidget);
        cardFrame->setObjectName("cardFrame");
        cardFrame->setFrameShape(QFrame::Shape::StyledPanel);
        cardFrame->setFrameShadow(QFrame::Shadow::Raised);
        cardFrame->setMinimumSize(QSize(400, 0));
        gestionLayout = new QVBoxLayout(cardFrame);
        gestionLayout->setSpacing(15);
        gestionLayout->setObjectName("gestionLayout");
        gestionLayout->setContentsMargins(15, 5, 15, 20);
        gestionTitle = new QLabel(cardFrame);
        gestionTitle->setObjectName("gestionTitle");

        gestionLayout->addWidget(gestionTitle);

        gestionButtonsGrid = new QVBoxLayout();
        gestionButtonsGrid->setSpacing(10);
        gestionButtonsGrid->setObjectName("gestionButtonsGrid");
        btnGestionClients = new QPushButton(cardFrame);
        btnGestionClients->setObjectName("btnGestionClients");
        btnGestionClients->setIconSize(QSize(20, 20));

        gestionButtonsGrid->addWidget(btnGestionClients);

        btnGestionCompteurs = new QPushButton(cardFrame);
        btnGestionCompteurs->setObjectName("btnGestionCompteurs");
        btnGestionCompteurs->setIconSize(QSize(20, 20));

        gestionButtonsGrid->addWidget(btnGestionCompteurs);

        btnGestionFactures = new QPushButton(cardFrame);
        btnGestionFactures->setObjectName("btnGestionFactures");
        btnGestionFactures->setIconSize(QSize(20, 20));

        gestionButtonsGrid->addWidget(btnGestionFactures);


        gestionLayout->addLayout(gestionButtonsGrid);

        gestionSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gestionLayout->addItem(gestionSpacer);


        mainContentLayout->addWidget(cardFrame);

        cardFrame_2 = new QFrame(centralwidget);
        cardFrame_2->setObjectName("cardFrame_2");
        cardFrame_2->setFrameShape(QFrame::Shape::StyledPanel);
        cardFrame_2->setFrameShadow(QFrame::Shadow::Raised);
        cardFrame_2->setMinimumSize(QSize(400, 0));
        listesLayout = new QVBoxLayout(cardFrame_2);
        listesLayout->setSpacing(15);
        listesLayout->setObjectName("listesLayout");
        listesLayout->setContentsMargins(15, 5, 15, 20);
        listesTitle = new QLabel(cardFrame_2);
        listesTitle->setObjectName("listesTitle");

        listesLayout->addWidget(listesTitle);

        listeButtonsGrid = new QVBoxLayout();
        listeButtonsGrid->setSpacing(10);
        listeButtonsGrid->setObjectName("listeButtonsGrid");
        btnListePrelevements = new QPushButton(cardFrame_2);
        btnListePrelevements->setObjectName("btnListePrelevements");
        btnListePrelevements->setIconSize(QSize(20, 20));

        listeButtonsGrid->addWidget(btnListePrelevements);

        btnListeAbonnements = new QPushButton(cardFrame_2);
        btnListeAbonnements->setObjectName("btnListeAbonnements");
        btnListeAbonnements->setIconSize(QSize(20, 20));

        listeButtonsGrid->addWidget(btnListeAbonnements);


        listesLayout->addLayout(listeButtonsGrid);

        listesSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        listesLayout->addItem(listesSpacer);


        mainContentLayout->addWidget(cardFrame_2);


        mainLayout->addLayout(mainContentLayout);

        bottomSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        mainLayout->addItem(bottomSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnFermer = new QPushButton(centralwidget);
        btnFermer->setObjectName("btnFermer");

        horizontalLayout->addWidget(btnFermer);


        mainLayout->addLayout(horizontalLayout);

        application->setCentralWidget(centralwidget);
        menubar = new QMenuBar(application);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 30));
        menuAide = new QMenu(menubar);
        menuAide->setObjectName("menuAide");
        application->setMenuBar(menubar);
        statusbar = new QStatusBar(application);
        statusbar->setObjectName("statusbar");
        application->setStatusBar(statusbar);

        menubar->addAction(menuAide->menuAction());
        menuAide->addAction(actionA_propos);

        retranslateUi(application);

        QMetaObject::connectSlotsByName(application);
    } // setupUi

    void retranslateUi(QMainWindow *application)
    {
        application->setWindowTitle(QCoreApplication::translate("application", "Gestion Facturation Eau - Forage", nullptr));
        actionNouveau->setText(QCoreApplication::translate("application", "Nouveau", nullptr));
#if QT_CONFIG(shortcut)
        actionNouveau->setShortcut(QCoreApplication::translate("application", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOuvrir->setText(QCoreApplication::translate("application", "Ouvrir", nullptr));
#if QT_CONFIG(shortcut)
        actionOuvrir->setShortcut(QCoreApplication::translate("application", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionQuitter->setText(QCoreApplication::translate("application", "Quitter", nullptr));
#if QT_CONFIG(shortcut)
        actionQuitter->setShortcut(QCoreApplication::translate("application", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionA_propos->setText(QCoreApplication::translate("application", "\303\200 propos", nullptr));
#if QT_CONFIG(tooltip)
        titleLabel->setToolTip(QCoreApplication::translate("application", "<html><head/><body><p>Syst\303\250me de gestion de facturation pour forage d'eau</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        titleLabel->setText(QCoreApplication::translate("application", "\360\237\232\260 Gestion de la Facturation d'Eau - Forage", nullptr));
        gestionTitle->setText(QCoreApplication::translate("application", "\360\237\223\212 Actions de Gestion", nullptr));
#if QT_CONFIG(tooltip)
        btnGestionClients->setToolTip(QCoreApplication::translate("application", "G\303\251rer la base de donn\303\251es clients", nullptr));
#endif // QT_CONFIG(tooltip)
        btnGestionClients->setText(QCoreApplication::translate("application", "\360\237\221\245 G\303\251rer les Clients", nullptr));
#if QT_CONFIG(tooltip)
        btnGestionCompteurs->setToolTip(QCoreApplication::translate("application", "G\303\251rer les compteurs d'eau", nullptr));
#endif // QT_CONFIG(tooltip)
        btnGestionCompteurs->setText(QCoreApplication::translate("application", "\342\232\241 G\303\251rer les Compteurs", nullptr));
#if QT_CONFIG(tooltip)
        btnGestionFactures->setToolTip(QCoreApplication::translate("application", "G\303\251rer les factures d'eau", nullptr));
#endif // QT_CONFIG(tooltip)
        btnGestionFactures->setText(QCoreApplication::translate("application", "\360\237\223\213 G\303\251rer les Factures", nullptr));
        listesTitle->setText(QCoreApplication::translate("application", "\360\237\223\213 Consultation des Listes", nullptr));
#if QT_CONFIG(tooltip)
        btnListePrelevements->setToolTip(QCoreApplication::translate("application", "Consulter la liste des pr\303\251l\303\250vements", nullptr));
#endif // QT_CONFIG(tooltip)
        btnListePrelevements->setText(QCoreApplication::translate("application", "\360\237\247\276 Liste des Pr\303\251l\303\250vements", nullptr));
#if QT_CONFIG(tooltip)
        btnListeAbonnements->setToolTip(QCoreApplication::translate("application", "Consulter la liste des abonnements", nullptr));
#endif // QT_CONFIG(tooltip)
        btnListeAbonnements->setText(QCoreApplication::translate("application", "\360\237\223\205 Liste des Abonnements", nullptr));
        btnFermer->setText(QCoreApplication::translate("application", "Fermer", nullptr));
        menuAide->setTitle(QCoreApplication::translate("application", "Aide", nullptr));
#if QT_CONFIG(tooltip)
        statusbar->setToolTip(QCoreApplication::translate("application", "Statut de l'application", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class application: public Ui_application {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLICATION_H
