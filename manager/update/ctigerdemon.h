#ifndef CTIGERDEMON_H
#define CTIGERDEMON_H

#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include <QJsonObject>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonArray>
#include <QEventLoop>
#include <QTimer>
#include <QUrl>
#include "gui/update/windowsmaj.h"
// Debug
/*
#include <iostream>
using namespace std;
*/


class CTigerDemon : public QObject
{
    Q_OBJECT
public:
    explicit CTigerDemon(const QString &name, const QString &version, QWidget *parent = nullptr);
    void checkUpdate();
    void closeUpdateWindow();
    QString get_version();

private:
    QNetworkAccessManager* manager;
    QJsonObject contenuJSON;
    QString offline_version;
    QString online_version, name_soft;
    QString url = "https://raw.githubusercontent.com/Arrera-Software/distribution/refs/heads/main/index.json";
    WindowsMaj winMaj;

signals:
    void updateStatusChanged(bool visible, const QString &message);

private: // Methode
    bool sate_connection();
    int set_online_version();
};

#endif // CTIGERDEMON_H
