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

// Methode public

CArreraSetting::CArreraSetting(QObject* p)
{
    parent = p ;
}
