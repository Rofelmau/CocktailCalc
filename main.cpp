#include "container.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Ingredient test = Ingredient("test1");
    Container::instance().addIngredient(test);
    test = Ingredient("test2");
    Container::instance().addIngredient(test);

    QUrl url("https://raw.githubusercontent.com/Rofelmau/FotoGen/master/src/Main.java");
    FileDownloader* fd = new FileDownloader(url);


    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
