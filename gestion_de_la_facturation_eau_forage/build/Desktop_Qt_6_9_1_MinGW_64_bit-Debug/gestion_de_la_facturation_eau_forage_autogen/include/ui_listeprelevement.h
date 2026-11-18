/********************************************************************************
** Form generated from reading UI file 'listeprelevement.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTEPRELEVEMENT_H
#define UI_LISTEPRELEVEMENT_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_listePrelevement
{
public:
    QAction *actionNouveau;
    QAction *actionOuvrir;
    QAction *actionExporter;
    QAction *actionQuitter;
    QAction *actionAjouter;
    QAction *actionModifier;
    QAction *actionSupprimer;
    QAction *actionActualiser;
    QAction *actionAPropos;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBoxFilters;
    QHBoxLayout *filtersLayout;
    QLabel *labelSearch;
    QLineEdit *lineEditSearch;
    QLabel *labelDateFrom;
    QDateEdit *dateEditFrom;
    QLabel *labelDateTo;
    QDateEdit *dateEditTo;
    QPushButton *btnFilter;
    QPushButton *btnClearFilter;
    QTableWidget *tablePrelevements;
    QHBoxLayout *actionsLayout;
    QPushButton *btnAjouterPrelevement;
    QPushButton *btnModifierPrelevement;
    QPushButton *btnSupprimerPrelevement;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnActualiser;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *listePrelevement)
    {
        if (listePrelevement->objectName().isEmpty())
            listePrelevement->setObjectName("listePrelevement");
        listePrelevement->resize(800, 600);
        actionNouveau = new QAction(listePrelevement);
        actionNouveau->setObjectName("actionNouveau");
        actionOuvrir = new QAction(listePrelevement);
        actionOuvrir->setObjectName("actionOuvrir");
        actionExporter = new QAction(listePrelevement);
        actionExporter->setObjectName("actionExporter");
        actionQuitter = new QAction(listePrelevement);
        actionQuitter->setObjectName("actionQuitter");
        actionAjouter = new QAction(listePrelevement);
        actionAjouter->setObjectName("actionAjouter");
        actionModifier = new QAction(listePrelevement);
        actionModifier->setObjectName("actionModifier");
        actionSupprimer = new QAction(listePrelevement);
        actionSupprimer->setObjectName("actionSupprimer");
        actionActualiser = new QAction(listePrelevement);
        actionActualiser->setObjectName("actionActualiser");
        actionAPropos = new QAction(listePrelevement);
        actionAPropos->setObjectName("actionAPropos");
        centralwidget = new QWidget(listePrelevement);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(5);
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        verticalLayout->setObjectName("verticalLayout");
        groupBoxFilters = new QGroupBox(centralwidget);
        groupBoxFilters->setObjectName("groupBoxFilters");
        filtersLayout = new QHBoxLayout(groupBoxFilters);
        filtersLayout->setObjectName("filtersLayout");
        labelSearch = new QLabel(groupBoxFilters);
        labelSearch->setObjectName("labelSearch");

        filtersLayout->addWidget(labelSearch);

        lineEditSearch = new QLineEdit(groupBoxFilters);
        lineEditSearch->setObjectName("lineEditSearch");
        lineEditSearch->setClearButtonEnabled(true);

        filtersLayout->addWidget(lineEditSearch);

        labelDateFrom = new QLabel(groupBoxFilters);
        labelDateFrom->setObjectName("labelDateFrom");

        filtersLayout->addWidget(labelDateFrom);

        dateEditFrom = new QDateEdit(groupBoxFilters);
        dateEditFrom->setObjectName("dateEditFrom");
        dateEditFrom->setCalendarPopup(true);
        dateEditFrom->setDate(QDate(2024, 1, 1));

        filtersLayout->addWidget(dateEditFrom);

        labelDateTo = new QLabel(groupBoxFilters);
        labelDateTo->setObjectName("labelDateTo");

        filtersLayout->addWidget(labelDateTo);

        dateEditTo = new QDateEdit(groupBoxFilters);
        dateEditTo->setObjectName("dateEditTo");
        dateEditTo->setCalendarPopup(true);
        dateEditTo->setDate(QDate(2025, 12, 31));

        filtersLayout->addWidget(dateEditTo);

        btnFilter = new QPushButton(groupBoxFilters);
        btnFilter->setObjectName("btnFilter");

        filtersLayout->addWidget(btnFilter);

        btnClearFilter = new QPushButton(groupBoxFilters);
        btnClearFilter->setObjectName("btnClearFilter");

        filtersLayout->addWidget(btnClearFilter);


        verticalLayout->addWidget(groupBoxFilters);

        tablePrelevements = new QTableWidget(centralwidget);
        if (tablePrelevements->columnCount() < 6)
            tablePrelevements->setColumnCount(6);
        tablePrelevements->setObjectName("tablePrelevements");
        tablePrelevements->setAlternatingRowColors(true);
        tablePrelevements->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        tablePrelevements->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tablePrelevements->setSortingEnabled(true);
        tablePrelevements->setCornerButtonEnabled(false);
        tablePrelevements->setColumnCount(6);
        tablePrelevements->horizontalHeader()->setVisible(true);
        tablePrelevements->horizontalHeader()->setDefaultSectionSize(120);
        tablePrelevements->horizontalHeader()->setHighlightSections(true);
        tablePrelevements->horizontalHeader()->setStretchLastSection(false);
        tablePrelevements->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tablePrelevements);

        actionsLayout = new QHBoxLayout();
        actionsLayout->setObjectName("actionsLayout");
        btnAjouterPrelevement = new QPushButton(centralwidget);
        btnAjouterPrelevement->setObjectName("btnAjouterPrelevement");
        btnAjouterPrelevement->setMinimumSize(QSize(120, 30));

        actionsLayout->addWidget(btnAjouterPrelevement);

        btnModifierPrelevement = new QPushButton(centralwidget);
        btnModifierPrelevement->setObjectName("btnModifierPrelevement");
        btnModifierPrelevement->setEnabled(false);
        btnModifierPrelevement->setMinimumSize(QSize(100, 30));

        actionsLayout->addWidget(btnModifierPrelevement);

        btnSupprimerPrelevement = new QPushButton(centralwidget);
        btnSupprimerPrelevement->setObjectName("btnSupprimerPrelevement");
        btnSupprimerPrelevement->setEnabled(false);
        btnSupprimerPrelevement->setMinimumSize(QSize(100, 30));

        actionsLayout->addWidget(btnSupprimerPrelevement);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        actionsLayout->addItem(horizontalSpacer_2);

        btnActualiser = new QPushButton(centralwidget);
        btnActualiser->setObjectName("btnActualiser");
        btnActualiser->setMinimumSize(QSize(100, 30));

        actionsLayout->addWidget(btnActualiser);


        verticalLayout->addLayout(actionsLayout);

        listePrelevement->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(listePrelevement);
        statusbar->setObjectName("statusbar");
        listePrelevement->setStatusBar(statusbar);

        retranslateUi(listePrelevement);
        QObject::connect(actionActualiser, &QAction::triggered, btnActualiser, qOverload<>(&QPushButton::click));

        QMetaObject::connectSlotsByName(listePrelevement);
    } // setupUi

    void retranslateUi(QMainWindow *listePrelevement)
    {
        listePrelevement->setWindowTitle(QCoreApplication::translate("listePrelevement", "Gestion des Pr\303\251l\303\250vements", nullptr));
        actionNouveau->setText(QCoreApplication::translate("listePrelevement", "Nouveau pr\303\251l\303\250vement", nullptr));
#if QT_CONFIG(shortcut)
        actionNouveau->setShortcut(QCoreApplication::translate("listePrelevement", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOuvrir->setText(QCoreApplication::translate("listePrelevement", "Ouvrir", nullptr));
#if QT_CONFIG(shortcut)
        actionOuvrir->setShortcut(QCoreApplication::translate("listePrelevement", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExporter->setText(QCoreApplication::translate("listePrelevement", "Exporter", nullptr));
#if QT_CONFIG(shortcut)
        actionExporter->setShortcut(QCoreApplication::translate("listePrelevement", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionQuitter->setText(QCoreApplication::translate("listePrelevement", "Quitter", nullptr));
#if QT_CONFIG(shortcut)
        actionQuitter->setShortcut(QCoreApplication::translate("listePrelevement", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAjouter->setText(QCoreApplication::translate("listePrelevement", "Ajouter", nullptr));
#if QT_CONFIG(shortcut)
        actionAjouter->setShortcut(QCoreApplication::translate("listePrelevement", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionModifier->setText(QCoreApplication::translate("listePrelevement", "Modifier", nullptr));
#if QT_CONFIG(shortcut)
        actionModifier->setShortcut(QCoreApplication::translate("listePrelevement", "Ctrl+M", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSupprimer->setText(QCoreApplication::translate("listePrelevement", "Supprimer", nullptr));
#if QT_CONFIG(shortcut)
        actionSupprimer->setShortcut(QCoreApplication::translate("listePrelevement", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        actionActualiser->setText(QCoreApplication::translate("listePrelevement", "Actualiser", nullptr));
#if QT_CONFIG(shortcut)
        actionActualiser->setShortcut(QCoreApplication::translate("listePrelevement", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAPropos->setText(QCoreApplication::translate("listePrelevement", "\303\200 propos", nullptr));
        groupBoxFilters->setTitle(QCoreApplication::translate("listePrelevement", "Recherche et Filtres", nullptr));
        labelSearch->setText(QCoreApplication::translate("listePrelevement", "Rechercher:", nullptr));
        lineEditSearch->setPlaceholderText(QCoreApplication::translate("listePrelevement", "Rechercher par num\303\251ro de compteur ou date...", nullptr));
        labelDateFrom->setText(QCoreApplication::translate("listePrelevement", "Du:", nullptr));
        labelDateTo->setText(QCoreApplication::translate("listePrelevement", "Au:", nullptr));
#if QT_CONFIG(tooltip)
        btnFilter->setToolTip(QCoreApplication::translate("listePrelevement", "Appliquer les filtres de recherche", nullptr));
#endif // QT_CONFIG(tooltip)
        btnFilter->setText(QCoreApplication::translate("listePrelevement", "Filtrer", nullptr));
#if QT_CONFIG(tooltip)
        btnClearFilter->setToolTip(QCoreApplication::translate("listePrelevement", "Effacer tous les filtres", nullptr));
#endif // QT_CONFIG(tooltip)
        btnClearFilter->setText(QCoreApplication::translate("listePrelevement", "Effacer", nullptr));
        tablePrelevements->setProperty("horizontalHeaderLabels", QVariant(QStringList{
            QCoreApplication::translate("listePrelevement", "ID", nullptr),
            QCoreApplication::translate("listePrelevement", "Date Pr\303\251l\303\250vement", nullptr),
            QCoreApplication::translate("listePrelevement", "N\302\260 Compteur", nullptr),
            QCoreApplication::translate("listePrelevement", "Nouvel Index", nullptr),
            QCoreApplication::translate("listePrelevement", "Ancien Index", nullptr),
            QCoreApplication::translate("listePrelevement", "Consommation", nullptr)}));
#if QT_CONFIG(tooltip)
        btnAjouterPrelevement->setToolTip(QCoreApplication::translate("listePrelevement", "Ajouter un nouveau pr\303\251l\303\250vement", nullptr));
#endif // QT_CONFIG(tooltip)
        btnAjouterPrelevement->setStyleSheet(QCoreApplication::translate("listePrelevement", "QPushButton {\n"
"           background-color: #27ae60;\n"
"           color: white;\n"
"           border: none;\n"
"           padding: 6px 12px;\n"
"           border-radius: 4px;\n"
"           font-weight: bold;\n"
"         }\n"
"         QPushButton:hover {\n"
"           background-color: #229954;\n"
"         }\n"
"         QPushButton:pressed {\n"
"           background-color: #1e8449;\n"
"         }", nullptr));
        btnAjouterPrelevement->setText(QCoreApplication::translate("listePrelevement", "Ajouter Pr\303\251l\303\250vement", nullptr));
#if QT_CONFIG(tooltip)
        btnModifierPrelevement->setToolTip(QCoreApplication::translate("listePrelevement", "Modifier le pr\303\251l\303\250vement s\303\251lectionn\303\251", nullptr));
#endif // QT_CONFIG(tooltip)
        btnModifierPrelevement->setStyleSheet(QCoreApplication::translate("listePrelevement", "QPushButton {\n"
"           background-color: #3498db;\n"
"           color: white;\n"
"           border: none;\n"
"           padding: 6px 12px;\n"
"           border-radius: 4px;\n"
"           font-weight: bold;\n"
"         }\n"
"         QPushButton:hover:enabled {\n"
"           background-color: #2980b9;\n"
"         }\n"
"         QPushButton:pressed:enabled {\n"
"           background-color: #21618c;\n"
"         }\n"
"         QPushButton:disabled {\n"
"           background-color: #bdc3c7;\n"
"         }", nullptr));
        btnModifierPrelevement->setText(QCoreApplication::translate("listePrelevement", "Modifier", nullptr));
#if QT_CONFIG(tooltip)
        btnSupprimerPrelevement->setToolTip(QCoreApplication::translate("listePrelevement", "Supprimer le pr\303\251l\303\250vement s\303\251lectionn\303\251", nullptr));
#endif // QT_CONFIG(tooltip)
        btnSupprimerPrelevement->setStyleSheet(QCoreApplication::translate("listePrelevement", "QPushButton {\n"
"           background-color: #e74c3c;\n"
"           color: white;\n"
"           border: none;\n"
"           padding: 6px 12px;\n"
"           border-radius: 4px;\n"
"           font-weight: bold;\n"
"         }\n"
"         QPushButton:hover:enabled {\n"
"           background-color: #c0392b;\n"
"         }\n"
"         QPushButton:pressed:enabled {\n"
"           background-color: #a93226;\n"
"         }\n"
"         QPushButton:disabled {\n"
"           background-color: #bdc3c7;\n"
"         }", nullptr));
        btnSupprimerPrelevement->setText(QCoreApplication::translate("listePrelevement", "Supprimer", nullptr));
#if QT_CONFIG(tooltip)
        btnActualiser->setToolTip(QCoreApplication::translate("listePrelevement", "Actualiser la liste des pr\303\251l\303\250vements", nullptr));
#endif // QT_CONFIG(tooltip)
        btnActualiser->setStyleSheet(QCoreApplication::translate("listePrelevement", "QPushButton {\n"
"           background-color: #7f8c8d;\n"
"           color: white;\n"
"           border: none;\n"
"           padding: 6px 12px;\n"
"           border-radius: 4px;\n"
"           font-weight: bold;\n"
"         }\n"
"         QPushButton:hover {\n"
"           background-color: #708090;\n"
"         }\n"
"         QPushButton:pressed {\n"
"           background-color: #5d6d7e;\n"
"         }", nullptr));
        btnActualiser->setText(QCoreApplication::translate("listePrelevement", "Actualiser", nullptr));
        statusbar->setStyleSheet(QCoreApplication::translate("listePrelevement", "QStatusBar { border-top: 1px solid #bdc3c7; }", nullptr));
    } // retranslateUi

};

namespace Ui {
    class listePrelevement: public Ui_listePrelevement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTEPRELEVEMENT_H
