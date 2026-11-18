/********************************************************************************
** Form generated from reading UI file 'association.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSOCIATION_H
#define UI_ASSOCIATION_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Association
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelClient;
    QComboBox *comboBoxClient;
    QLabel *labelCompteur;
    QComboBox *comboBoxCompteur;
    QLabel *labelDate;
    QDateEdit *dateEditAbonnement;
    QPushButton *btnAssocier;

    void setupUi(QWidget *Association)
    {
        if (Association->objectName().isEmpty())
            Association->setObjectName("Association");
        verticalLayout = new QVBoxLayout(Association);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        labelClient = new QLabel(Association);
        labelClient->setObjectName("labelClient");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelClient);

        comboBoxClient = new QComboBox(Association);
        comboBoxClient->setObjectName("comboBoxClient");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, comboBoxClient);

        labelCompteur = new QLabel(Association);
        labelCompteur->setObjectName("labelCompteur");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelCompteur);

        comboBoxCompteur = new QComboBox(Association);
        comboBoxCompteur->setObjectName("comboBoxCompteur");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, comboBoxCompteur);

        labelDate = new QLabel(Association);
        labelDate->setObjectName("labelDate");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelDate);

        dateEditAbonnement = new QDateEdit(Association);
        dateEditAbonnement->setObjectName("dateEditAbonnement");
        dateEditAbonnement->setCalendarPopup(true);
        dateEditAbonnement->setDate(QDate(0, 0, 0));

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, dateEditAbonnement);


        verticalLayout->addLayout(formLayout);

        btnAssocier = new QPushButton(Association);
        btnAssocier->setObjectName("btnAssocier");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnAssocier->sizePolicy().hasHeightForWidth());
        btnAssocier->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(btnAssocier);


        retranslateUi(Association);

        QMetaObject::connectSlotsByName(Association);
    } // setupUi

    void retranslateUi(QWidget *Association)
    {
        Association->setWindowTitle(QCoreApplication::translate("Association", "Association Compteur - Client", nullptr));
        labelClient->setText(QCoreApplication::translate("Association", "Client :", nullptr));
        labelCompteur->setText(QCoreApplication::translate("Association", "Compteur :", nullptr));
        labelDate->setText(QCoreApplication::translate("Association", "Date d'abonnement :", nullptr));
        btnAssocier->setText(QCoreApplication::translate("Association", "Associer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Association: public Ui_Association {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSOCIATION_H
