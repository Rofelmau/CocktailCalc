#include "container.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    QUrl url("https://raw.githubusercontent.com/Rofelmau/CocktailCalc/master/cocktailList.json");
    FileDownloader *fileDownloader = new FileDownloader(url);

    MainWindow w(fileDownloader);

    return a.exec();
}
