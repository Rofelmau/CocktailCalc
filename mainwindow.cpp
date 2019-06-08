#include "container.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QComboBox>
#include <QPushButton>
#include <QUiLoader>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);

    connect( ui->actionBerechnung, SIGNAL(triggered()),
             this, SLOT(slotActionBerechnung()));
    connect( ui->actionCocktail_bersicht, SIGNAL(triggered()),
             this, SLOT(slotActionCocktail_bersicht()));
    connect( ui->actionZutaten_Finder, SIGNAL(triggered()),
             this, SLOT(slotActionZutaten_Finder()));

    buildBerechnungWidget();
}

MainWindow::~MainWindow()
{
    disconnect( ui->actionBerechnung, SIGNAL(triggered()),
             this, SLOT(slotActionBerechnung()));
    disconnect( ui->actionCocktail_bersicht, SIGNAL(triggered()),
                this, SLOT(slotActionCocktail_bersicht()));
    disconnect( ui->actionZutaten_Finder, SIGNAL(triggered()),
                this, SLOT(slotActionZutaten_Finder()));

    delete ui;
}

void MainWindow::slotActionBerechnung() {
    if (activeView != 0) {
        destroyCurrentWidget();
        buildBerechnungWidget();
    }
}

void MainWindow::slotActionCocktail_bersicht() {
    if (activeView != 1) {
        destroyCurrentWidget();
        buildOverviewWidget();
    }
}

void MainWindow::slotActionZutaten_Finder() {
    if (activeView != 2) {
        destroyCurrentWidget();
        buildFindWidget();
    }
}

void MainWindow::buildBerechnungWidget() {
    this->activeWidget = new QWidget;
    QPushButton* button = new QPushButton("Berechnung Starten", activeWidget);

    ui->verticalLayout->addWidget(this->activeWidget);
    this->activeView = 0;
}

void MainWindow::buildOverviewWidget() {
    this->activeWidget = new QWidget;
    QPushButton* button = new QPushButton("Irgendwas überblick mäßiges", activeWidget);

    ui->verticalLayout->addWidget(this->activeWidget);
    this->activeView = 1;
}

void MainWindow::buildFindWidget() {

    QUiLoader loader;
    QFile file("/Users/lucaschuller/Documents/GitHub/CocktailCalc/searchforingredient.ui");
    file.open(QFile::ReadOnly);
    this->activeWidget = loader.load(&file, this);
    file.close();

    ui->verticalLayout->addWidget(this->activeWidget);
    this->activeView = 2;

    QStringList ingridientList;
    ingridientList << "Bitte wähle eine Zutat";
    ingridientList << Container::instance().getIngredientsAsString();
    QComboBox* comboBox = this->activeWidget->findChild<QComboBox*>("selectIngredientComboBox");
    comboBox->addItems(ingridientList);
}

void MainWindow::destroyCurrentWidget() {
    ui->verticalLayout->removeWidget(this->activeWidget);
    delete this->activeWidget;
}

