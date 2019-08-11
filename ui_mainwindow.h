/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionBerechnung;
    QAction *actionZutaten_Finder;
    QAction *actionCocktail_bersicht;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *calculatePageButton;
    QPushButton *searchPageButton;
    QPushButton *overviewPageButton;
    QStackedWidget *stackedWidget;
    QWidget *calculatePage;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QWidget *calculatorSelectabels_2;
    QVBoxLayout *calculatorSelectabels;
    QSpacerItem *verticalSpacer_5;
    QWidget *calculatedBuyList;
    QVBoxLayout *verticalLayout_6;
    QGridLayout *gridLayout_4;
    QPushButton *buttonCalculate;
    QPushButton *buttonDeleteAllFelds;
    QPushButton *buttonAddNewField;
    QPushButton *buttonDeleteLastField;
    QWidget *calculatedIngredients;
    QGridLayout *gridLayout_5;
    QSpacerItem *verticalSpacer_6;
    QWidget *searchPage;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *searchIngredientsComboBox;
    QPushButton *searchIngredeint;
    QWidget *searchedIngredientResult;
    QVBoxLayout *verticalLayout_11;
    QSpacerItem *verticalSpacer_4;
    QWidget *overviewPage;
    QGridLayout *gridLayout_3;
    QWidget *cocktailOverviewList;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *ListederCocktail;
    QWidget *CocktailOWButtonList_2;
    QVBoxLayout *CocktailOWButtonList;
    QSpacerItem *verticalSpacer_3;
    QWidget *cocktailIngreedientList;
    QVBoxLayout *verticalLayout_8;
    QLineEdit *cocktailOverviweCocktailName;
    QWidget *cocktaiIngredientOverviewList;
    QVBoxLayout *verticalLayout_10;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(992, 616);
        actionBerechnung = new QAction(MainWindow);
        actionBerechnung->setObjectName(QString::fromUtf8("actionBerechnung"));
        actionBerechnung->setMenuRole(QAction::ApplicationSpecificRole);
        actionZutaten_Finder = new QAction(MainWindow);
        actionZutaten_Finder->setObjectName(QString::fromUtf8("actionZutaten_Finder"));
        actionCocktail_bersicht = new QAction(MainWindow);
        actionCocktail_bersicht->setObjectName(QString::fromUtf8("actionCocktail_bersicht"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        calculatePageButton = new QPushButton(centralWidget);
        calculatePageButton->setObjectName(QString::fromUtf8("calculatePageButton"));
        calculatePageButton->setEnabled(false);

        horizontalLayout->addWidget(calculatePageButton);

        searchPageButton = new QPushButton(centralWidget);
        searchPageButton->setObjectName(QString::fromUtf8("searchPageButton"));

        horizontalLayout->addWidget(searchPageButton);

        overviewPageButton = new QPushButton(centralWidget);
        overviewPageButton->setObjectName(QString::fromUtf8("overviewPageButton"));

        horizontalLayout->addWidget(overviewPageButton);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addLayout(verticalLayout_2);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        calculatePage = new QWidget();
        calculatePage->setObjectName(QString::fromUtf8("calculatePage"));
        gridLayout = new QGridLayout(calculatePage);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        calculatorSelectabels_2 = new QWidget(calculatePage);
        calculatorSelectabels_2->setObjectName(QString::fromUtf8("calculatorSelectabels_2"));
        calculatorSelectabels_2->setMinimumSize(QSize(450, 0));
        calculatorSelectabels = new QVBoxLayout(calculatorSelectabels_2);
        calculatorSelectabels->setSpacing(6);
        calculatorSelectabels->setContentsMargins(11, 11, 11, 11);
        calculatorSelectabels->setObjectName(QString::fromUtf8("calculatorSelectabels"));

        verticalLayout_5->addWidget(calculatorSelectabels_2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_5);


        horizontalLayout_3->addLayout(verticalLayout_5);

        calculatedBuyList = new QWidget(calculatePage);
        calculatedBuyList->setObjectName(QString::fromUtf8("calculatedBuyList"));
        calculatedBuyList->setMinimumSize(QSize(400, 0));
        calculatedBuyList->setMaximumSize(QSize(750, 16777215));
        verticalLayout_6 = new QVBoxLayout(calculatedBuyList);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        buttonCalculate = new QPushButton(calculatedBuyList);
        buttonCalculate->setObjectName(QString::fromUtf8("buttonCalculate"));

        gridLayout_4->addWidget(buttonCalculate, 0, 0, 1, 1);

        buttonDeleteAllFelds = new QPushButton(calculatedBuyList);
        buttonDeleteAllFelds->setObjectName(QString::fromUtf8("buttonDeleteAllFelds"));

        gridLayout_4->addWidget(buttonDeleteAllFelds, 4, 0, 1, 1);

        buttonAddNewField = new QPushButton(calculatedBuyList);
        buttonAddNewField->setObjectName(QString::fromUtf8("buttonAddNewField"));

        gridLayout_4->addWidget(buttonAddNewField, 2, 0, 1, 1);

        buttonDeleteLastField = new QPushButton(calculatedBuyList);
        buttonDeleteLastField->setObjectName(QString::fromUtf8("buttonDeleteLastField"));

        gridLayout_4->addWidget(buttonDeleteLastField, 3, 0, 1, 1);


        verticalLayout_6->addLayout(gridLayout_4);

        calculatedIngredients = new QWidget(calculatedBuyList);
        calculatedIngredients->setObjectName(QString::fromUtf8("calculatedIngredients"));
        gridLayout_5 = new QGridLayout(calculatedIngredients);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));

        verticalLayout_6->addWidget(calculatedIngredients);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_6);


        horizontalLayout_3->addWidget(calculatedBuyList);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        stackedWidget->addWidget(calculatePage);
        searchPage = new QWidget();
        searchPage->setObjectName(QString::fromUtf8("searchPage"));
        gridLayout_2 = new QGridLayout(searchPage);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        lineEdit = new QLineEdit(searchPage);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setAlignment(Qt::AlignCenter);
        lineEdit->setReadOnly(true);
        lineEdit->setClearButtonEnabled(false);

        verticalLayout_4->addWidget(lineEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        searchIngredientsComboBox = new QComboBox(searchPage);
        searchIngredientsComboBox->setObjectName(QString::fromUtf8("searchIngredientsComboBox"));

        horizontalLayout_2->addWidget(searchIngredientsComboBox);

        searchIngredeint = new QPushButton(searchPage);
        searchIngredeint->setObjectName(QString::fromUtf8("searchIngredeint"));

        horizontalLayout_2->addWidget(searchIngredeint);


        verticalLayout_4->addLayout(horizontalLayout_2);

        searchedIngredientResult = new QWidget(searchPage);
        searchedIngredientResult->setObjectName(QString::fromUtf8("searchedIngredientResult"));
        verticalLayout_11 = new QVBoxLayout(searchedIngredientResult);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));

        verticalLayout_4->addWidget(searchedIngredientResult);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);


        gridLayout_2->addLayout(verticalLayout_4, 0, 1, 1, 1);

        stackedWidget->addWidget(searchPage);
        overviewPage = new QWidget();
        overviewPage->setObjectName(QString::fromUtf8("overviewPage"));
        gridLayout_3 = new QGridLayout(overviewPage);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        cocktailOverviewList = new QWidget(overviewPage);
        cocktailOverviewList->setObjectName(QString::fromUtf8("cocktailOverviewList"));
        verticalLayout_3 = new QVBoxLayout(cocktailOverviewList);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        ListederCocktail = new QLineEdit(cocktailOverviewList);
        ListederCocktail->setObjectName(QString::fromUtf8("ListederCocktail"));
        ListederCocktail->setReadOnly(true);

        verticalLayout_3->addWidget(ListederCocktail);

        CocktailOWButtonList_2 = new QWidget(cocktailOverviewList);
        CocktailOWButtonList_2->setObjectName(QString::fromUtf8("CocktailOWButtonList_2"));
        CocktailOWButtonList = new QVBoxLayout(CocktailOWButtonList_2);
        CocktailOWButtonList->setSpacing(6);
        CocktailOWButtonList->setContentsMargins(11, 11, 11, 11);
        CocktailOWButtonList->setObjectName(QString::fromUtf8("CocktailOWButtonList"));

        verticalLayout_3->addWidget(CocktailOWButtonList_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        gridLayout_3->addWidget(cocktailOverviewList, 0, 0, 1, 1);

        cocktailIngreedientList = new QWidget(overviewPage);
        cocktailIngreedientList->setObjectName(QString::fromUtf8("cocktailIngreedientList"));
        verticalLayout_8 = new QVBoxLayout(cocktailIngreedientList);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        cocktailOverviweCocktailName = new QLineEdit(cocktailIngreedientList);
        cocktailOverviweCocktailName->setObjectName(QString::fromUtf8("cocktailOverviweCocktailName"));
        cocktailOverviweCocktailName->setAlignment(Qt::AlignCenter);
        cocktailOverviweCocktailName->setReadOnly(true);

        verticalLayout_8->addWidget(cocktailOverviweCocktailName);

        cocktaiIngredientOverviewList = new QWidget(cocktailIngreedientList);
        cocktaiIngredientOverviewList->setObjectName(QString::fromUtf8("cocktaiIngredientOverviewList"));
        verticalLayout_10 = new QVBoxLayout(cocktaiIngredientOverviewList);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));

        verticalLayout_8->addWidget(cocktaiIngredientOverviewList);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_2);


        gridLayout_3->addWidget(cocktailIngreedientList, 0, 1, 1, 1);

        stackedWidget->addWidget(overviewPage);

        verticalLayout->addWidget(stackedWidget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionBerechnung->setText(QApplication::translate("MainWindow", "Berechnung", nullptr));
#ifndef QT_NO_TOOLTIP
        actionBerechnung->setToolTip(QApplication::translate("MainWindow", "Hier kannst du dir eine EInkaufsliste erstellen Lassen", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionBerechnung->setShortcut(QApplication::translate("MainWindow", "Ctrl+B", nullptr));
#endif // QT_NO_SHORTCUT
        actionZutaten_Finder->setText(QApplication::translate("MainWindow", "Zutaten Finder", nullptr));
#ifndef QT_NO_TOOLTIP
        actionZutaten_Finder->setToolTip(QApplication::translate("MainWindow", "Hier kannst du nach Zutaten suchen und sehen, wleche Cocktails diese Zutat enthalten", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionZutaten_Finder->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_NO_SHORTCUT
        actionCocktail_bersicht->setText(QApplication::translate("MainWindow", "Cocktail\303\274bersicht", nullptr));
#ifndef QT_NO_TOOLTIP
        actionCocktail_bersicht->setToolTip(QApplication::translate("MainWindow", "Hier siehst du eine \303\234bersicht aller Cocktails und ihrer Zutaten", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionCocktail_bersicht->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        calculatePageButton->setText(QApplication::translate("MainWindow", "Zutatenliste", nullptr));
        searchPageButton->setText(QApplication::translate("MainWindow", "Zutaten Suche", nullptr));
        overviewPageButton->setText(QApplication::translate("MainWindow", "Coktail \303\234bersicht", nullptr));
        buttonCalculate->setText(QApplication::translate("MainWindow", "Berechnen", nullptr));
        buttonDeleteAllFelds->setText(QApplication::translate("MainWindow", "Alle Felder L\303\266schen", nullptr));
        buttonAddNewField->setText(QApplication::translate("MainWindow", "Neues Feld Hinzuf\303\274gen", nullptr));
        buttonDeleteLastField->setText(QApplication::translate("MainWindow", "Letztes Feld L\303\266schen", nullptr));
        lineEdit->setText(QApplication::translate("MainWindow", "Hier kannst du sehen, in welchen Cocktails die ausgew\303\244hlte Zutat enthalten ist.", nullptr));
        searchIngredeint->setText(QApplication::translate("MainWindow", "Suchen", nullptr));
        ListederCocktail->setText(QApplication::translate("MainWindow", "Cocktail Liste", nullptr));
        cocktailOverviweCocktailName->setText(QApplication::translate("MainWindow", "Cocktail Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
