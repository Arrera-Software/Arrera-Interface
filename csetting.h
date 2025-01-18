#ifndef CSETTING_H
#define CSETTING_H

#include <QSettings>
#include <QString>
#include <QFileInfo>

class CSetting {
private:
    bool fileOpen;
    bool fileCreated;
    QSettings *settings;

public:
    // Constructeur de base
    CSetting();

    // Constructeur avec le fichier
    CSetting(const QString &file);

    // Méthode pour obtenir l'état de création du fichier
    bool getFileCreated() const;

    // Méthode pour définir une valeur
    bool setValeur(const QString &section, const QString &key, const QString &value);

    // Méthode pour récupérer une valeur
    QString getValeur(const QString &section, const QString &key) const;

    // Méthode pour supprimer une valeur
    bool supprValeur(const QString &section, const QString &key);
};

#endif // CSETTING_H
