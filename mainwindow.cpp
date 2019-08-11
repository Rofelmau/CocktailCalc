#include "container.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "position.h"

#include <QComboBox>
#include <QDoubleSpinBox>
#include <QHeaderView>
#include <QPushButton>
#include <QScrollBar>
#include <QStandardItemModel>
#include <QTableView>
#include <QUiLoader>
#include <QMovie>
#include <QSplashScreen>
#include <QLabel>
#include <QLayout>
#include <QProgressDialog>

#include <iostream>

MainWindow::MainWindow(FileDownloader* aFileDownlaoder, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    fileDownloader(aFileDownlaoder),
    progress("Copying files...", "Abort Copy", 0, 5, this) {


    progress.setWindowModality(Qt::WindowModal);

    this->show();

    connect(fileDownloader, SIGNAL(containerFilled()), this, SLOT(updateFromContainer()));
    connect(fileDownloader, SIGNAL(downloadFailed()), this, SLOT(downloadFailed()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::downloadFailed() {
    disconnect(fileDownloader, SIGNAL(containerFilleds()), this, SLOT(updateFromContainer()));
}

void MainWindow::updateFromContainer() {
    disconnect(fileDownloader, SIGNAL(downloadFailed()), this, SLOT(updateFromContainer()));
    progress.setValue(1);
    ui->setupUi(this);
    progress.setValue(2);
    buildCocktailOverviewList();
    progress.setValue(3);
    buildCalculatorPage();
    progress.setValue(4);
    buildSearchPage();
    progress.setValue(5);
    this->show();
}

void MainWindow::on_searchPageButton_clicked() {
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_overviewPageButton_clicked() {
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_calculatePageButton_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::buildSearchPage() {
    QComboBox *searchIngredientsComboBox = ui->stackedWidget->findChild<QComboBox*>("searchIngredientsComboBox");

    if (searchIngredientsComboBox != nullptr) {
        QStringList ingredients = Container::instance().getIngredientsAsString();
        ingredients.sort();

        searchIngredientsComboBox->addItems(ingredients);
    }
}

void MainWindow::buildCocktailOverviewList() {

    QStringList cocktailList = Container::instance().getCocktailsAsString();
    cocktailList.sort();

    QWidget *listView = ui->stackedWidget->findChild<QWidget*>("CocktailOWButtonList_2");
    foreach (const QString& name, cocktailList) {
        QPushButton *button = new QPushButton();
        button->setText(name);
        connect(button, SIGNAL(clicked()), this, SLOT(slot_on_buttonCocktailIngredientsOverview_clicked()));

        listView->layout()->addWidget(button);
    }
}

void MainWindow::buildCalculatorPage() {
    addCalculateLine();
}

void MainWindow::addCalculateLine() {
    QWidget *widget = ui->stackedWidget->findChild<QWidget*>("calculatorSelectabels_2");
    QStringList cocktailList = Container::instance().getCocktailsAsString();
    cocktailList.sort();

    QWidget *subwidget = new QWidget();
    QHBoxLayout *hLayout = new QHBoxLayout();
    QComboBox *combobox = new QComboBox();
    combobox->setObjectName("comboBoxCocktailSelected");
    foreach (QString name, cocktailList) {
        combobox->addItem(name);
    }
    QSpinBox *spinBox = new QSpinBox();
    spinBox->setMinimum(0);
    spinBox->setMaximum(200);
    spinBox->setMaximumWidth(75);
    spinBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
    spinBox->setObjectName("spinBoxCocktailAmount");

    hLayout->addWidget(combobox);
    hLayout->addWidget(spinBox);
    subwidget->setLayout(hLayout);
    widget->layout()->addWidget(subwidget);

    this->calculateLinesList.append(subwidget);
}


void MainWindow::on_buttonAddNewField_clicked() {
    if (this->calculateLinesList.count() < 10) {
        addCalculateLine();
    }

    if (this->calculateLinesList.count() == 10) {
        QObject *buttonObject = ui->stackedWidget->findChild<QObject*>("buttonAddNewField");
        QPushButton *addNewButton = qobject_cast<QPushButton*>(buttonObject);
        addNewButton->setDisabled(true);
    }
}

void MainWindow::on_buttonDeleteLastField_clicked() {
    QWidget *widget = ui->stackedWidget->findChild<QWidget*>("calculatorSelectabels_2");
    QWidget *lastWidget = this->calculateLinesList.last();
    widget->layout()->removeWidget(lastWidget);
    lastWidget->close();
    this->calculateLinesList.removeLast();

    if (this->calculateLinesList.count() == 0) {
        addCalculateLine();
    }

    QObject *buttonObject = ui->stackedWidget->findChild<QObject*>("buttonAddNewField");
    QPushButton *addNewButton = qobject_cast<QPushButton*>(buttonObject);
    addNewButton->setDisabled(false);

}

void MainWindow::on_buttonDeleteAllFelds_clicked() {
    QWidget *widget = ui->stackedWidget->findChild<QWidget*>("calculatorSelectabels_2");

    while (this->calculateLinesList.count() > 0) {
        QWidget *lastWidget = this->calculateLinesList.last();
        widget->layout()->removeWidget(lastWidget);
        lastWidget->close();
        this->calculateLinesList.removeLast();
    }

    addCalculateLine();

    QObject *buttonObject = ui->stackedWidget->findChild<QObject*>("buttonAddNewField");
    QPushButton *addNewButton = qobject_cast<QPushButton*>(buttonObject);
    addNewButton->setDisabled(false);
}

void MainWindow::slot_on_buttonCocktailIngredientsOverview_clicked() {
    QObject *senderObject = QObject::sender();
    QPushButton *senderButton = nullptr;
    if (senderObject != nullptr) {
        senderButton = qobject_cast<QPushButton*>(senderObject);
    }

    if (senderButton != nullptr) {
        const QString& cocktailName = senderButton->text();
        QObject *lineEditObject = this->ui->stackedWidget->findChild<QObject*>("cocktailOverviweCocktailName");

        QLineEdit *lineEditCocktailName = nullptr;
        if (lineEditObject != nullptr) {
            lineEditCocktailName = qobject_cast<QLineEdit*>(lineEditObject);
        }
        if (lineEditCocktailName != nullptr) {
            lineEditCocktailName->clear();
            lineEditCocktailName->setText(cocktailName);
        }

        Cocktail* cocktail = Container::instance().findCocktailByName(cocktailName);
        QObject *ingredientListObject = this->ui->stackedWidget->findChild<QObject*>("cocktaiIngredientOverviewList");
        if (cocktail != nullptr && ingredientListObject != nullptr) {
            QWidget *ingredientsListWidget = qobject_cast<QWidget*>(ingredientListObject);

            if (ingredientsListWidget != nullptr) {
                removeOldObjects(ingredientsListWidget);

                foreach (Position *position, cocktail->getPositions()) {
                    if (position != nullptr) {
                        QString text = position->getIngredient()->getName() + " ";
                        text += QString::number(position->getAmount()) + " ";
                        text += position->getIngredient()->getUnit();

                        QLineEdit *ingredientText = new QLineEdit();
                        ingredientText->setText(text);
                        ingredientText->setReadOnly(true);
                        ingredientText->setAlignment(Qt::AlignmentFlag::AlignCenter);
                        ingredientText->setFrame(false);

                        ingredientsListWidget->layout()->addWidget(ingredientText);
                    }
                }

            }

        }

    }

}

void MainWindow::on_buttonCalculate_clicked() {
    QHash<Cocktail*, double> cocktailCount;

    foreach (QWidget* widget, this->calculateLinesList) {
        QObject *comboboxObject = widget->findChild<QObject*>("comboBoxCocktailSelected");
        QObject *spinboxObject = widget->findChild<QObject*>("spinBoxCocktailAmount");
        if (comboboxObject != nullptr && spinboxObject != nullptr) {
            QComboBox *comboBox = qobject_cast<QComboBox*>(comboboxObject);
            QSpinBox *spinBox = qobject_cast<QSpinBox*>(spinboxObject);
            if (comboBox != nullptr && spinBox != nullptr && spinBox->value() > 0) {
                const QString& cocktailName = comboBox->currentText();
                Cocktail* cocktail = Container::instance().findCocktailByName(cocktailName);
                if (cocktail != nullptr) {
                    int amount = spinBox->value();
                    if (cocktailCount.contains(cocktail)) {
                        amount += cocktailCount.value(cocktail);
                    }

                    cocktailCount.insert(cocktail, amount);
                }
            }
        }
    }

    QHash<Ingredient*, double> ingredientCount;
    foreach (Cocktail *cocktail, cocktailCount.keys()) {
        foreach (Position *position, cocktail->getPositions()) {
            double amount = cocktailCount.value(cocktail);
            amount *= position->getAmount();

            if (ingredientCount.contains(position->getIngredient())) {
                amount += ingredientCount.value(position->getIngredient());
            }

            ingredientCount.insert(position->getIngredient(), amount);
        }
    }

    QObject *ingredientListObject = this->ui->stackedWidget->findChild<QObject*>("calculatedIngredients");
    if (ingredientListObject != nullptr) {
        QWidget *ingredientsListWidget = qobject_cast<QWidget*>(ingredientListObject);

        if (ingredientsListWidget != nullptr) {
            removeOldObjects(ingredientsListWidget);
            QTableView *tableView = new QTableView();
            QStandardItemModel *itemModel = new QStandardItemModel();
            QStringList header;
            header << "Cocktail";
            header << "Menge";
            header << "Einheit";
            itemModel->setHorizontalHeaderLabels(header);
            tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            tableView->verticalScrollBar()->setDisabled(true);

            foreach (Ingredient *ingredient, ingredientCount.keys()) {
                const QString ingredientText = ingredient->getName();
                const QString amountText = QString::number(ingredientCount.value(ingredient));
                const QString unitText = ingredient->getUnit();
                QStandardItem *item = new QStandardItem();
                item->setText(ingredientText);
                item->setTextAlignment(Qt::AlignmentFlag::AlignCenter);
                item->setEditable(false);
                QStandardItem *item2 = new QStandardItem();
                item2->setText(amountText);
                item2->setTextAlignment(Qt::AlignmentFlag::AlignCenter);
                item2->setEditable(false);
                QStandardItem *item3 = new QStandardItem();
                item3->setText(unitText);
                item3->setTextAlignment(Qt::AlignmentFlag::AlignCenter);
                item3->setEditable(false);
                QList<QStandardItem*> list;
                list.append(item);
                list.append(item2);
                list.append(item3);
                itemModel->appendRow(list);

                tableView->setModel(itemModel);

            }
            ingredientsListWidget->layout()->addWidget(tableView);
            tableView->setColumnWidth(0, 300);
            ingredientsListWidget->setMaximumHeight(tableView->height());
            ingredientsListWidget->setMinimumHeight(tableView->height());

        }

    }

}

void MainWindow::removeOldObjects(QWidget* aWidget) {
    if ( aWidget != nullptr) {
        QList<QWidget*> oldChildren = aWidget->findChildren<QWidget*>();

        foreach (QWidget* child, oldChildren) {
            aWidget->layout()->removeWidget(child);
            child->close();
        }
    }

}

void MainWindow::on_searchIngredeint_clicked() {
    QComboBox *searchIngredientsComboBox = ui->stackedWidget->findChild<QComboBox*>("searchIngredientsComboBox");

    if (searchIngredientsComboBox != nullptr) {
        const QString& selectedIngredient = searchIngredientsComboBox->currentText();
        QStringList cocktailList;
        foreach (Cocktail *cocktail, Container::instance().getCocktails()) {
            foreach (Position *position, cocktail->getPositions()) {
                if (position->getIngredient()->getName() == selectedIngredient) {
                    cocktailList << cocktail->getName();
                    break;
                }
            }
        }

        QObject *cocktailListObject = this->ui->stackedWidget->findChild<QObject*>("searchedIngredientResult");
        if (cocktailListObject != nullptr) {
            QWidget *cocktailListWidget = qobject_cast<QWidget*>(cocktailListObject);

            if (cocktailListWidget != nullptr) {
                removeOldObjects(cocktailListWidget);

                foreach (const QString& cocktailName, cocktailList) {
                    QLineEdit *ingredientText = new QLineEdit();
                    ingredientText->setText(cocktailName);
                    ingredientText->setReadOnly(true);
                    ingredientText->setAlignment(Qt::AlignmentFlag::AlignCenter);
                    ingredientText->setFrame(false);

                    cocktailListWidget->layout()->addWidget(ingredientText);
                }

            }

        }


    }

}

void MainWindow::on_stackedWidget_currentChanged(int arg1) {
    QList<QPushButton*> stackSwitchButtons;
    stackSwitchButtons.append(ui->calculatePageButton);
    stackSwitchButtons.append(ui->searchPageButton);
    stackSwitchButtons.append(ui->overviewPageButton);

    for (int i = 0; i < stackSwitchButtons.count(); i++) {
        if (i == arg1) {
            stackSwitchButtons[i]->setEnabled(false);
        }
        else {
            stackSwitchButtons[i]->setEnabled(true);
        };
    }

}
