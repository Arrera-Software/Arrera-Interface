#include "ctigerdemon.h"



CTigerDemon::CTigerDemon(const QString& url, const QString& nameSoft, QObject* parent)
    : QObject(parent)
{
    QNetworkAccessManager mgr(this);
    QNetworkRequest req(url);
    QNetworkReply* reply = mgr.get(req);

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        if (doc.isObject()) {
            QJsonObject root = doc.object();
            if (root.contains(nameSoft) && root[nameSoft].isObject()) {
                contenuJSON = root[nameSoft].toObject();
            }
        }
    }
    reply->deleteLater();
}

QString CTigerDemon::getVersionSoft(){
    QString versionInstalled;

    return fileversion.getVersion();
}

bool CTigerDemon::checkUpdate(){
    QString versionInstalled = getVersionSoft();
    QString lastVersion = contenuJSON["version"].toString();

    if (versionInstalled != "IXXXX-XXX"){
        if (versionInstalled != lastVersion){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}
