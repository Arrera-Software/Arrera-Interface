//Coder le 28.11.2024
//Par: Enzo BOURKOUA

//Classe Permettant de gerer les fichiers jsons

#include "cjsonword.h"

CJSONWORD::CJSONWORD() : fileOpen(false) {}

CJSONWORD::CJSONWORD(QString fileName) : fileName(fileName), fileOpen(false) {
    file.setFileName(fileName);
    if (!file.exists()) {
        file.open(QIODevice::WriteOnly);
        file.write("{}");
        file.close();
    }
    file.open(QIODevice::ReadOnly);
    QByteArray data = file.readAll();
    file.close();
    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(data, &parseError);
    if (parseError.error == QJsonParseError::NoError) {
        jsonObject = doc.object();
        fileOpen = true;
    }
}

CJSONWORD::~CJSONWORD() {
    if (fileOpen) {
        file.close();
    }
}

bool CJSONWORD::isExist(QString cles) {
    return jsonObject.contains(cles);
}

QString CJSONWORD::read(QString cles) {
    if (fileOpen) {
        if (isExist(cles)) {
            return jsonObject.value(cles).toString();
        } else {
            return "error";
        }
    } else {
        return "error";
    }
}

bool CJSONWORD::write(QString cles, QString valeur) {
    if (fileOpen) {
        jsonObject.insert(cles, valeur);
        file.open(QIODevice::WriteOnly);
        QJsonDocument doc(jsonObject);
        file.write(doc.toJson());
        file.close();
        return true;
    } else {
        return false;
    }
}
