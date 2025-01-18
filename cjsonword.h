//Coder le 28.11.2024
//Par: Enzo BOURKOUA

//Classe Permettant de gerer les fichiers jsons

#ifndef CJSONWORD_H
#define CJSONWORD_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QJsonValue>
#include <QJsonParseError>
#include <QString>

class CJSONWORD {
private:
    QString fileName;
    bool fileOpen;
    QJsonObject jsonObject;
    QFile file;

public:
    // Constructeur
    CJSONWORD();

    // Constructeur avec paramètre de nom de fichier
    CJSONWORD(QString fileName);

    ~CJSONWORD();

    // Vérifie si une clé existe
    bool isExist(QString cles);

    // Lit la valeur selon la clé
    QString read(QString cles);

    // Écrit une valeur dans la clé correspondante
    bool write(QString cles, QString valeur);
};

#endif // CJSONWORD_H
