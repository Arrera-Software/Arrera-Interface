#include "carrerasetting.h"

// Methode private

// Methode private pour gerer les fichier

bool CArreraSetting::fileExists(const std::string &filePath)
{
    return filesystem::exists(filePath);
}

bool CArreraSetting::loadFiles()
{
    if (fileExists(NAMEFILEAPP))
    {
        settingApp = new QSettings(NAMEFILEAPP, QSettings::IniFormat, parent);
        return true ;
    }
    else
    {
        return false;
    }
}

void CArreraSetting::createFiles()
{
    ofstream fichier1(NAMEFILEAPP);

    fichier1.close();
}

// Methode public

CArreraSetting::CArreraSetting(QObject* p)
{
    bool loading;
    parent = p ;
    loading = loadFiles();
    if(!loading)
    {
        createFiles();
        loadFiles();
        resetFiles();
    }
}

CArreraSetting::~CArreraSetting()
{
    delete settingApp;
}

void CArreraSetting::resetFiles()
{
    int i ;
    QString group;
    for (i=1;i<=12;i++)
    {
        group = "app"+QString::number(i);
        settingApp->beginGroup(group);
        settingApp->setValue("name","null");
        settingApp->setValue("emplacement","null");
        settingApp->setValue("icon","null");
        settingApp->endGroup();
    }
}
