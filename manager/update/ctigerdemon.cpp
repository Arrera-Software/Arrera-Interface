#include "ctigerdemon.h"

CTigerDemon::CTigerDemon(const QString &name, const QString &version, QWidget* parent)
    : QObject(parent)
    , offline_version(version)
    , name_soft(name)
    , winMaj(parent)
{
}

QString CTigerDemon::get_version(){
    return offline_version;
}

void CTigerDemon::closeUpdateWindow()
{
    winMaj.close();
}

void CTigerDemon::checkUpdate() {
    const int status = set_online_version();

    if (status != 1) {
        if (status == -1) {
            emit updateStatusChanged(true, QStringLiteral("Impossible de vérifier les mises à jour, une erreur réseau s'est produite"));
        } else if (status == -2) {
            emit updateStatusChanged(true, QStringLiteral("Impossible de vérifier les mises à jour"));
        } else {
            emit updateStatusChanged(false, QString());
        }
        return;
    }

    if (offline_version != QLatin1String("dev")
        && !online_version.isEmpty()
        && online_version != offline_version) {
        emit updateStatusChanged(true, QStringLiteral("La version %1 est disponible").arg(online_version));
        winMaj.set_new_version(online_version);
        winMaj.show();
        winMaj.raise();
        winMaj.activateWindow();
    } else {
        emit updateStatusChanged(false, QString());
    }
}

bool CTigerDemon::sate_connection(){
    QNetworkAccessManager manager;
    QNetworkRequest request{QUrl(url)};
    QNetworkReply *reply = manager.head(request);
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    QTimer timer;
    timer.setSingleShot(true);
    QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
    timer.start(2000);
    loop.exec();
    bool isConnected = (reply->error() == QNetworkReply::NoError);
    reply->deleteLater();
    return isConnected;
}

int CTigerDemon::set_online_version(){
    /*
     *  1 : OK (Connecté, JSON lu, logiciel trouvé et version récupérée)
     * -1 : Pas internet
     * -2 : Autre (Erreur réseau, JSON invalide, ou logiciel introuvable)
    */

    if (!sate_connection()) {
        return -1;
    }

    QNetworkAccessManager mgr(this);
    QNetworkRequest req(url);
    QNetworkReply* reply = mgr.get(req);

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() != QNetworkReply::NoError) {
        reply->deleteLater();
        return -2;
    }

    QByteArray data = reply->readAll();
    reply->deleteLater();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isObject()) {
        return -2;
    }

    QJsonObject root = doc.object();
    bool softwareFound = false;

    QStringList categories = {"application", "assistants"};

    for (const QString& category : categories) {
        if (root.contains(category) && root[category].isArray()) {
            QJsonArray array = root[category].toArray();

            for (int i = 0; i < array.size(); ++i) {
                QJsonObject item = array[i].toObject();

                if (item["name"].toString() == name_soft) {
                    online_version = item["version"].toString();
                    softwareFound = true;
                    break;
                }
            }
        }

        if (softwareFound) {
            break;
        }
    }

    if (softwareFound) {
        return 1;
    } else {
        return -2;
    }
}