#include "container.h"
#include "filedownloader.h"
#include "position.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDir>
#include <QCoreApplication>

#include <iostream>

FileDownloader::FileDownloader(QUrl imageUrl, QObject *parent) : QObject(parent) {
    connect(&m_WebCtrl, SIGNAL (finished(QNetworkReply*)), SLOT (fileDownloaded(QNetworkReply*)));
    connect(this, SIGNAL (downloaded()), SLOT (dataRecived()));
    QNetworkRequest request(imageUrl);
    m_WebCtrl.get(request);
}

FileDownloader::~FileDownloader() {

}

void FileDownloader::fileDownloaded(QNetworkReply* pReply) {
    this->m_DownloadedData = pReply->readAll();

//    const QString filename = QCoreApplication::applicationDirPath() + "/downloaded.json";
    const QString filename = "/Users/lucaschuller/Documents/GitHub/CocktailCalc/downloaded.json";
    if (this->m_DownloadedData.isNull() || this->m_DownloadedData.isEmpty()) {
        QFile file(filename);
        if (file.open(QIODevice::ReadOnly)) {
            this->m_DownloadedData = file.readAll();
            file.close();
            std::cout << "fertig gelesen" << std::endl;
        }
    }
    else {
        QFile file(filename);
        if (file.open(QIODevice::WriteOnly)) {
            file.write(this->m_DownloadedData);
            file.close();
            std::cout << "fertiiiig" << std::endl;
        }
    }

    pReply->deleteLater();

    if (this->m_DownloadedData.isNull() || this->m_DownloadedData.isEmpty()) {
        emit downloadFailed();
    }
    else {
        emit downloaded();
    }
}

void FileDownloader::dataRecived() {
    QJsonDocument jsonResponse = QJsonDocument::fromJson(m_DownloadedData);
    QJsonObject jsonObject = jsonResponse.object();
    QJsonArray jsonArray = jsonResponse.array();

    QJsonValue ingredients = jsonObject.value("ingredients");
    QJsonArray arryy = ingredients.toArray();
    foreach (QJsonValue val, arryy) {
        QJsonObject ingredientAsArray = val.toObject();

        Ingredient *in = new Ingredient(ingredientAsArray.value("name").toString(), ingredientAsArray.value("unit").toString());
        Container::instance().addIngredient(in);
    }

    QJsonValue cocktails = jsonObject.value("cocktails");
    arryy = cocktails.toArray();
    foreach (QJsonValue val, arryy) {
        QJsonObject cocktailsAsArray = val.toObject();

        Cocktail *cocktail = new Cocktail(cocktailsAsArray.value("name").toString());
        QJsonValue ingredients = cocktailsAsArray.value("ingredients");
        QJsonArray ingredientsArray = ingredients.toArray();
        foreach (QJsonValue ingredientValue, ingredientsArray) {
            QJsonObject ingredientAsArray = ingredientValue.toObject();
            Ingredient  *currentIngredient = Container::instance().findIngredientByName(ingredientAsArray.value("name").toString());
            if (currentIngredient != nullptr) {
                Position *position = new Position(currentIngredient, ingredientAsArray.value("amount").toDouble());
                cocktail->addPosition(position);
            }
        }

        Container::instance().addCocktail(cocktail);
    }

    emit containerFilled();
}

QByteArray FileDownloader::downloadedData() const {
    return m_DownloadedData;
}
