/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *mainLayout;
    QSpacerItem *topSpacer;
    QFrame *loginFrame;
    QVBoxLayout *formLayout;
    QLabel *titleLabel;
    QVBoxLayout *identifiantLayout;
    QLabel *label;
    QLineEdit *lineEditIdentifiant;
    QVBoxLayout *motDePasseLayout;
    QLabel *label_2;
    QLineEdit *lineEditMotDePasse;
    QSpacerItem *formSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *leftButtonSpacer;
    QPushButton *pushButton;
    QSpacerItem *rightButtonSpacer;
    QSpacerItem *bottomSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(420, 380);
        MainWindow->setStyleSheet(QString::fromUtf8("/* Utilisation des couleurs et th\303\250mes par d\303\251faut de Qt avec am\303\251liorations subtiles */\n"
"\n"
"QMainWindow {\n"
"    background-color: palette(window);\n"
"}\n"
"\n"
"QWidget {\n"
"    font-family: \"Segoe UI\", \"Roboto\", sans-serif;\n"
"}\n"
"\n"
"/* Titre de connexion */\n"
"QLabel#titleLabel {\n"
"    font-size: 16pt;\n"
"    font-weight: bold;\n"
"    color: palette(text);\n"
"    padding: 12px 0px;\n"
"    qproperty-alignment: AlignCenter;\n"
"}\n"
"\n"
"/* Labels des champs */\n"
"QLabel {\n"
"    font-size: 9pt;\n"
"    color: palette(text);\n"
"    font-weight: 500;\n"
"    padding: 3px 0px;\n"
"}\n"
"\n"
"/* Champs de saisie */\n"
"QLineEdit {\n"
"    border: 2px solid palette(mid);\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    font-size: 9pt;\n"
"    background-color: palette(base);\n"
"    color: palette(text);\n"
"    min-height: 16px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: palette(highlight);\n"
"    background-color: palette(base);\n"
"}\n"
""
                        "\n"
"QLineEdit:hover {\n"
"    border-color: palette(dark);\n"
"}\n"
"\n"
"/* Bouton de connexion */\n"
"QPushButton {\n"
"    background-color: palette(highlight);\n"
"    color: palette(highlighted-text);\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 10px 20px;\n"
"    font-size: 10pt;\n"
"    font-weight: 600;\n"
"    min-height: 16px;\n"
"    min-width: 100px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: palette(dark);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: palette(shadow);\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: palette(mid);\n"
"    color: palette(disabled-text);\n"
"}\n"
"\n"
"/* Frame conteneur pour un meilleur style */\n"
"QFrame#loginFrame {\n"
"    background-color: palette(base);\n"
"    border: 1px solid palette(mid);\n"
"    border-radius: 10px;\n"
"    padding: 15px;\n"
"    max-width: 320px;\n"
"    max-height: 260px;\n"
"}\n"
"\n"
"/* MenuBar */\n"
"QMenuBar {\n"
"    background-color: palette(window);\n"
"   "
                        " color: palette(text);\n"
"    border-bottom: 1px solid palette(mid);\n"
"    spacing: 3px;\n"
"}\n"
"\n"
"QMenuBar::item {\n"
"    padding: 6px 10px;\n"
"    background-color: transparent;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background-color: palette(highlight);\n"
"    color: palette(highlighted-text);\n"
"}\n"
"\n"
"QMenuBar::item:pressed {\n"
"    background-color: palette(dark);\n"
"}\n"
"\n"
"/* StatusBar */\n"
"QStatusBar {\n"
"    background-color: palette(window);\n"
"    color: palette(text);\n"
"    border-top: 1px solid palette(mid);\n"
"}\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        mainLayout = new QVBoxLayout(centralwidget);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(40, 30, 40, 30);
        topSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        mainLayout->addItem(topSpacer);

        loginFrame = new QFrame(centralwidget);
        loginFrame->setObjectName("loginFrame");
        loginFrame->setFrameShape(QFrame::StyledPanel);
        loginFrame->setFrameShadow(QFrame::Raised);
        formLayout = new QVBoxLayout(loginFrame);
        formLayout->setSpacing(15);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(20, 20, 20, 20);
        titleLabel = new QLabel(loginFrame);
        titleLabel->setObjectName("titleLabel");

        formLayout->addWidget(titleLabel);

        identifiantLayout = new QVBoxLayout();
        identifiantLayout->setSpacing(5);
        identifiantLayout->setObjectName("identifiantLayout");
        label = new QLabel(loginFrame);
        label->setObjectName("label");

        identifiantLayout->addWidget(label);

        lineEditIdentifiant = new QLineEdit(loginFrame);
        lineEditIdentifiant->setObjectName("lineEditIdentifiant");

        identifiantLayout->addWidget(lineEditIdentifiant);


        formLayout->addLayout(identifiantLayout);

        motDePasseLayout = new QVBoxLayout();
        motDePasseLayout->setSpacing(5);
        motDePasseLayout->setObjectName("motDePasseLayout");
        label_2 = new QLabel(loginFrame);
        label_2->setObjectName("label_2");

        motDePasseLayout->addWidget(label_2);

        lineEditMotDePasse = new QLineEdit(loginFrame);
        lineEditMotDePasse->setObjectName("lineEditMotDePasse");
        lineEditMotDePasse->setEchoMode(QLineEdit::Password);

        motDePasseLayout->addWidget(lineEditMotDePasse);


        formLayout->addLayout(motDePasseLayout);

        formSpacer = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout->addItem(formSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        leftButtonSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(leftButtonSpacer);

        pushButton = new QPushButton(loginFrame);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        rightButtonSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(rightButtonSpacer);


        formLayout->addLayout(horizontalLayout);


        mainLayout->addWidget(loginFrame, 0, Qt::AlignCenter);

        bottomSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        mainLayout->addItem(bottomSpacer);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 420, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        pushButton->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Connexion", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "Connexion", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Identifiant", nullptr));
        lineEditIdentifiant->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez votre identifiant", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Mot de passe", nullptr));
        lineEditMotDePasse->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez votre mot de passe", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Connexion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
