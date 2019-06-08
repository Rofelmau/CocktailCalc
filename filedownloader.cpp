#include "filedownloader.h"

#include <iostream>

FileDownloader::FileDownloader(QUrl imageUrl, QObject *parent) : QObject(parent) {
 connect(&m_WebCtrl, SIGNAL (finished(QNetworkReply*)),
 SLOT (fileDownloaded(QNetworkReply*)));
 connect(this, SIGNAL (downloaded()), SLOT (dataRecived()));


 QNetworkRequest request(imageUrl);
 m_WebCtrl.get(request);
}

FileDownloader::~FileDownloader()
{

}

void FileDownloader::fileDownloaded(QNetworkReply* pReply)
{
 m_DownloadedData = pReply->readAll();
 //emit a signal
 pReply->deleteLater();
 emit downloaded();
}

void FileDownloader::dataRecived() {
    std::cout << m_DownloadedData.toStdString() << std::endl;
}

QByteArray FileDownloader::downloadedData() const
{
 return m_DownloadedData;
}
