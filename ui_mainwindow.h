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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
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
    QMenuBar *menuBar;
    QMenu *menuCocktailCalc;
    QMenu *menu_bersicht;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(992, 492);
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
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 992, 20));
        menuCocktailCalc = new QMenu(menuBar);
        menuCocktailCalc->setObjectName(QString::fromUtf8("menuCocktailCalc"));
        menu_bersicht = new QMenu(menuBar);
        menu_bersicht->setObjectName(QString::fromUtf8("menu_bersicht"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuCocktailCalc->menuAction());
        menuBar->addAction(menu_bersicht->menuAction());
        menu_bersicht->addSeparator();
        menu_bersicht->addAction(actionBerechnung);
        menu_bersicht->addAction(actionZutaten_Finder);
        menu_bersicht->addAction(actionCocktail_bersicht);

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
        menuCocktailCalc->setTitle(QApplication::translate("MainWindow", "CocktailCalc", nullptr));
        menu_bersicht->setTitle(QApplication::translate("MainWindow", "Funktionen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
