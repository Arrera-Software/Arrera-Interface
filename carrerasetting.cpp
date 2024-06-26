#include "carrerasetting.h"

// Methode private
// Aide gestion
void CArreraSetting::setValueGroup(int file,const QString &group, const QString &key,
                                   const QVariant &value)
{
    /*
    1: File App
    */
    switch (file) {
    case 1:
        settingApp->beginGroup(group);
        settingApp->setValue(key, value);
        settingApp->endGroup();
        break;
    default:
        break;
    }
}

void CArreraSetting::setValueSimple(int file,const QString &key, const QVariant &value)
{
    /*
    1: File App
    */
    switch (file) {
    case 1:
        settingApp->setValue(key, value);
        break;
    default:
        break;
    }
}

QVariant CArreraSetting::getValueSimple(int file,const QString &key,
                        const QVariant &defaultValue) const
{
    /*
    1: File App
    */
    QVariant value ;
    switch (file) {
    case 1:
        value = settingApp->value(key, defaultValue);
        return value;
        break;
    default:
        return false;
        break;
    }
}

QVariant CArreraSetting::getValueGroup(int file,const QString &group,
                       const QString &key,
                       const QVariant &defaultValue) const
{
    /*
    1: File App
    */
    QVariant value ;
    switch (file) {
        case 1:
            settingApp->beginGroup(group);
            value = settingApp->value(key, defaultValue);
            settingApp->endGroup();
            return value;
            break;
        default:
            return false;
            break;
    }
}
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
    }
}

CArreraSetting::~CArreraSetting()
{
    delete settingApp;
}
