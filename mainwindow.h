#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void slotActionBerechnung();

    void slotActionCocktail_bersicht();

    void slotActionZutaten_Finder();

private:
    void buildBerechnungWidget();
    void buildOverviewWidget();
    void buildFindWidget();
    void destroyCurrentWidget();

    Ui::MainWindow *ui;

    QWidget* activeWidget;

    int activeView;
};

#endif // MAINWINDOW_H
