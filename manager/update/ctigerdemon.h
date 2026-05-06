#ifndef CTIGERDEMON_H
#define CTIGERDEMON_H

#include <QCoreApplication>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QEventLoop>
#include <QFile>
#include <QTextStream>
#include "version.h"

// Debug
/*
#include <iostream>
using namespace std;
*/


class CTigerDemon : public QObject
{
    Q_OBJECT
public:
    explicit CTigerDemon(QString name, QObject* parent = nullptr);
    void checkUpdate();
    QString get_version();
private:
    QNetworkAccessManager* manager;
    QJsonObject contenuJSON;
    version offline_version;
    QString online_version,name_soft;
    QString url = "https://github.com/Arrera-Software/distribution/blob/main/index.json";
private: // Methode
    bool sate_connection();
    int set_online_version();

signals:
    void updateResult(bool hasUpdate, const QString& newVersion);
    void updateError(int errorCode);

};

#endif // CTIGERDEMON_H
