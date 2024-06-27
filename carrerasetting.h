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
    void resetFiles();
    // Methode de la partie APP
    bool addApp(int nb,QString name,QString emplacement,QString icon = "null");
    bool supprApp(int nb);
    QString getNameApp(int nb);
    QString getEmplacementApp(int nb);
    QString getIconApp(int nb);
private :
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
