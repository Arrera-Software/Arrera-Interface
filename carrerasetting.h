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
