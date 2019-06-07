#include "container.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Ingredient test = Ingredient("test1");
    Container::instance().addIngredient(test);
    test = Ingredient("test2");
    Container::instance().addIngredient(test);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
