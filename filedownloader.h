#ifndef FILEDOWNLOADER_H
#define FILEDOWNLOADER_H

#include <QObject>
#include <QByteArray>
#include <QNetworkAccessManager.h>
#include <QNetworkRequest>
#include <QNetworkReply>

class FileDownloader : public QObject
{
 Q_OBJECT
public:
 explicit FileDownloader(QUrl imageUrl, QObject *parent = 0);

 virtual ~FileDownloader();

 QByteArray downloadedData() const;

signals:
 void downloaded();

private slots:

 void fileDownloaded(QNetworkReply* pReply);

    void dataRecived();

private:

QNetworkAccessManager m_WebCtrl;

QByteArray m_DownloadedData;

};

#endif // FILEDOWNLOADER_H
