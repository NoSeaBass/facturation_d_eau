/********************************************************************************
** Form generated from reading UI file 'nouvellefacture.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOUVELLEFACTURE_H
#define UI_NOUVELLEFACTURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_nouvellefacture
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QFormLayout *formLayout;
    QLineEdit *lineEdit;
    QDateEdit *DatePrelever;
    QLineEdit *lineEdit_2;
    QComboBox *comboBox_2;
    QLineEdit *lineEdit_3;
    QLineEdit *NouveauIndex;
    QFrame *infoFrame;
    QVBoxLayout *infoLayout;
    QLabel *infoLabel;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *nouvellefacture)
    {
        if (nouvellefacture->objectName().isEmpty())
            nouvellefacture->setObjectName("nouvellefacture");
        nouvellefacture->resize(650, 400);
        nouvellefacture->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background-color: palette(base);\n"
"    font-family: 'Segoe UI', system-ui, sans-serif;\n"
"    font-size: 9pt;\n"
"}\n"
"\n"
"QLabel#titleLabel {\n"
"    font-size: 16pt;\n"
"    font-weight: 600;\n"
"    color: palette(text);\n"
"    padding: 20px;\n"
"    background-color: palette(alternate-base);\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    margin-bottom: 10px;\n"
"}\n"
"\n"
"QLineEdit {\n"
"    padding: 12px;\n"
"    border: 1px solid palette(mid);\n"
"    border-radius: 6px;\n"
"    font-size: 9pt;\n"
"    background-color: palette(base);\n"
"    color: palette(text);\n"
"    min-height: 18px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid palette(highlight);\n"
"    background-color: palette(base);\n"
"}\n"
"\n"
"QLineEdit[readOnly=\"true\"] {\n"
"    background-color: palette(button);\n"
"    color: palette(button-text);\n"
"    font-weight: 500;\n"
"    border: 1px solid palette(mid);\n"
"    min-width: 150px;\n"
"    max-width: 180px;\n"
"}\n"
"\n"
"QComboB"
                        "ox {\n"
"    padding: 12px;\n"
"    border: 1px solid palette(mid);\n"
"    border-radius: 6px;\n"
"    background-color: palette(base);\n"
"    color: palette(text);\n"
"    font-size: 9pt;\n"
"    min-height: 18px;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 1px solid palette(highlight);\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border: 2px solid palette(highlight);\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    width: 25px;\n"
"    background-color: palette(button);\n"
"    border-left: 1px solid palette(mid);\n"
"    border-top-right-radius: 6px;\n"
"    border-bottom-right-radius: 6px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    width: 12px;\n"
"    height: 12px;\n"
"    image: url(data:image/svg+xml;base64,PHN2ZyB3aWR0aD0iMTIiIGhlaWdodD0iOCIgdmlld0JveD0iMCAwIDEyIDgiIGZpbGw9Im5vbmUiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyI+CjxwYXRoIGQ9Ik0xIDFMNiA2TDExIDEiIHN0cm9rZT0iIzY2NiIgc3Ryb2tlLXdpZHRoPSIxLjUiIHN0cm9rZS1saW5lY2FwPSJyb3VuZCIgc3Ryb2tlLWxpbmVqb2luPSJyb3VuZCIvPgo8L3N2Zz4"
                        "=);\n"
"}\n"
"\n"
"QDateEdit {\n"
"    padding: 12px;\n"
"    border: 1px solid palette(mid);\n"
"    border-radius: 6px;\n"
"    background-color: palette(base);\n"
"    color: palette(text);\n"
"    font-size: 9pt;\n"
"    min-height: 18px;\n"
"}\n"
"\n"
"QDateEdit:hover {\n"
"    border: 1px solid palette(highlight);\n"
"}\n"
"\n"
"QDateEdit:focus {\n"
"    border: 2px solid palette(highlight);\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"    border: none;\n"
"    width: 25px;\n"
"    background-color: palette(button);\n"
"    border-left: 1px solid palette(mid);\n"
"    border-top-right-radius: 6px;\n"
"    border-bottom-right-radius: 6px;\n"
"}\n"
"\n"
"QFrame#infoFrame {\n"
"    background-color: palette(alternate-base);\n"
"    border: 1px solid palette(mid);\n"
"    border-radius: 6px;\n"
"    padding: 15px;\n"
"}\n"
"\n"
"QLabel#infoLabel {\n"
"    color: palette(text);\n"
"    font-size: 9pt;\n"
"    font-weight: normal;\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: palette(button);\n"
"    col"
                        "or: palette(button-text);\n"
"    border: 1px solid palette(mid);\n"
"    border-radius: 6px;\n"
"    padding: 10px 20px;\n"
"    font-size: 9pt;\n"
"    font-weight: 500;\n"
"    min-width: 80px;\n"
"    min-height: 32px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: palette(light);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: palette(mid);\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    background-color: palette(highlight);\n"
"    color: palette(highlighted-text);\n"
"    border: 1px solid palette(highlight);\n"
"}\n"
"\n"
"QPushButton:default:hover {\n"
"    background-color: palette(highlight);\n"
"    opacity: 0.9;\n"
"}"));
        verticalLayoutWidget = new QWidget(nouvellefacture);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(20, 10, 610, 380));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(15, 10, 15, 10);
        titleLabel = new QLabel(verticalLayoutWidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(15);
        formLayout->setVerticalSpacing(15);
        formLayout->setContentsMargins(0, 10, 0, 10);
        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, lineEdit);

        DatePrelever = new QDateEdit(verticalLayoutWidget);
        DatePrelever->setObjectName("DatePrelever");
        DatePrelever->setCalendarPopup(true);

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, DatePrelever);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, lineEdit_2);

        comboBox_2 = new QComboBox(verticalLayoutWidget);
        comboBox_2->setObjectName("comboBox_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, comboBox_2);

        lineEdit_3 = new QLineEdit(verticalLayoutWidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, lineEdit_3);

        NouveauIndex = new QLineEdit(verticalLayoutWidget);
        NouveauIndex->setObjectName("NouveauIndex");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, NouveauIndex);


        verticalLayout->addLayout(formLayout);

        infoFrame = new QFrame(verticalLayoutWidget);
        infoFrame->setObjectName("infoFrame");
        infoFrame->setFrameShape(QFrame::Shape::StyledPanel);
        infoFrame->setFrameShadow(QFrame::Shadow::Plain);
        infoLayout = new QVBoxLayout(infoFrame);
        infoLayout->setSpacing(0);
        infoLayout->setObjectName("infoLayout");
        infoLayout->setContentsMargins(10, 5, 10, 5);
        infoLabel = new QLabel(infoFrame);
        infoLabel->setObjectName("infoLabel");
        infoLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        infoLayout->addWidget(infoLabel);


        verticalLayout->addWidget(infoFrame);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(verticalLayoutWidget);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(nouvellefacture);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, nouvellefacture, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, nouvellefacture, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(nouvellefacture);
    } // setupUi

    void retranslateUi(QDialog *nouvellefacture)
    {
        nouvellefacture->setWindowTitle(QCoreApplication::translate("nouvellefacture", "Nouveau Pr\303\251l\303\250vement", nullptr));
        titleLabel->setText(QCoreApplication::translate("nouvellefacture", "Nouveau Pr\303\251l\303\250vement", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit->setToolTip(QCoreApplication::translate("nouvellefacture", "S\303\251lectionnez l'identifiant du client", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEdit->setText(QCoreApplication::translate("nouvellefacture", "Date Pr\303\251l\303\250vement", nullptr));
#if QT_CONFIG(tooltip)
        DatePrelever->setToolTip(QCoreApplication::translate("nouvellefacture", "Choisissez la date du pr\303\251l\303\250vement", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        lineEdit_2->setToolTip(QCoreApplication::translate("nouvellefacture", "S\303\251lectionnez le num\303\251ro de compteur", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEdit_2->setText(QCoreApplication::translate("nouvellefacture", "N\302\260 Compteur", nullptr));
#if QT_CONFIG(tooltip)
        comboBox_2->setToolTip(QCoreApplication::translate("nouvellefacture", "Liste des compteurs disponibles", nullptr));
#endif // QT_CONFIG(tooltip)
        comboBox_2->setPlaceholderText(QCoreApplication::translate("nouvellefacture", "S\303\251lectionnez un compteur...", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_3->setToolTip(QCoreApplication::translate("nouvellefacture", "S\303\251lectionnez le type de pr\303\251l\303\250vement", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEdit_3->setText(QCoreApplication::translate("nouvellefacture", "Nouvel Index", nullptr));
#if QT_CONFIG(tooltip)
        NouveauIndex->setToolTip(QCoreApplication::translate("nouvellefacture", "Saisissez le nouvel index du compteur", nullptr));
#endif // QT_CONFIG(tooltip)
        NouveauIndex->setPlaceholderText(QCoreApplication::translate("nouvellefacture", "Entrez la nouvelle valeur...", nullptr));
        infoLabel->setText(QCoreApplication::translate("nouvellefacture", "Remplissez tous les champs pour cr\303\251er le pr\303\251l\303\250vement", nullptr));
    } // retranslateUi

};

namespace Ui {
    class nouvellefacture: public Ui_nouvellefacture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOUVELLEFACTURE_H
