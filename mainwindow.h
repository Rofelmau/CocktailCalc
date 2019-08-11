#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "filedownloader.h"

#include <QMainWindow>
#include <QProgressDialog>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit MainWindow(FileDownloader* aFileDownlaoder, QWidget *parent = 0);

        ~MainWindow();

    private slots:
        void on_searchPageButton_clicked();

        void on_overviewPageButton_clicked();

        void on_calculatePageButton_clicked();

        void updateFromContainer();

        void downloadFailed();

        void on_buttonAddNewField_clicked();

        void on_buttonDeleteLastField_clicked();

        void on_buttonDeleteAllFelds_clicked();

        void slot_on_buttonCocktailIngredientsOverview_clicked();

        void on_buttonCalculate_clicked();

        void on_searchIngredeint_clicked();

        void on_stackedWidget_currentChanged(int arg1);

private:
        void addCalculateLine();

        void buildSearchPage();

        void buildCocktailOverviewList();

        void buildCalculatorPage();

        void removeOldObjects(QWidget* aWidget);

        QList<QWidget*> calculateLinesList;

        Ui::MainWindow *ui;

        QProgressDialog progress;

        FileDownloader *fileDownloader;
};

#endif // MAINWINDOW_H
