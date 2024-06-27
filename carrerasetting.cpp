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

// Methode de la partie APP
bool CArreraSetting::addApp(int nb,QString name,QString emplacement,QString icon)
{
    if (nb <= 1 || nb >= 12)
    {
        return false;
    }
    else
    {
        settingApp->beginGroup("app"+QString::number(nb));
        settingApp->setValue("name",name);
        settingApp->setValue("emplacement",emplacement);
        settingApp->setValue("icon",icon);
        settingApp->endGroup();
        return true;
    }
}

bool CArreraSetting::supprApp(int nb)
{
    if (nb <= 1 || nb >= 12)
    {
        return false;
    }
    else
    {
        settingApp->beginGroup("app"+QString::number(nb));
        settingApp->setValue("name","null");
        settingApp->setValue("emplacement","null");
        settingApp->setValue("icon","null");
        settingApp->endGroup();
        return true;
    }
}

QString CArreraSetting::getNameApp(int nb)
{
    if (nb <= 1 || nb >= 12)
    {
        return "error";
    }
    else
    {
        settingApp->beginGroup("app"+QString::number(nb));
        QString sortie = settingApp->value("name").toString();
        settingApp->endGroup();
        return sortie;
    }
}
QString CArreraSetting::getEmplacementApp(int nb)
{
    if (nb <= 1 || nb >= 12)
    {
        return "error";
    }
    else
    {
        settingApp->beginGroup("app"+QString::number(nb));
        QString sortie = settingApp->value("emplacement").toString();
        settingApp->endGroup();
        return sortie;
    }
}

QString CArreraSetting::getIconApp(int nb)
{
    if (nb <= 1 || nb >= 12)
    {
        return "error";
    }
    else
    {
        settingApp->beginGroup("app"+QString::number(nb));
        QString sortie = settingApp->value("icon").toString();
        settingApp->endGroup();
        return sortie;
    }
}
