#ifndef CARRERASETTING_H
#define CARRERASETTING_H

#include "COS.h"
#include <filesystem>
#include <fstream>
#include <QSettings>
#include <QString>
#include <QVariant>

#define NAMEFILEAPP "confApp.ini"

using namespace std;

class CArreraSetting
{
public:
    CArreraSetting(QObject* p);
    ~CArreraSetting();
private :
    // Methode pour faciliter la gestion des fichier .ini
    void setValueGroup(int file,const QString &group,
                       const QString &key, const QVariant &value);
    void setValueSimple(int file,const QString &key,
                        const QVariant &value);
    QVariant getValueSimple(int file,const QString &key,
                            const QVariant &defaultValue) const;
    QVariant getValueGroup(int file,const QString &group,
                           const QString &key,
                           const QVariant &defaultValue = QVariant()) const;
    // Methode private pour gerer les fichier
    bool fileExists(const std::string &filePath);
    bool loadFiles();
    void createFiles();
    // objQT
    QObject *parent;
    // Obj Setting
    QSettings *settingApp;

};

#endif // CARRERASETTING_H
