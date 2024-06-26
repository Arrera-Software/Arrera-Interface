#ifndef CARRERASETTING_H
#define CARRERASETTING_H

#include "COS.h"
#include <QSettings>
#include <QString>
#include <QVariant>

class CArreraSetting
{
public:
    CArreraSetting(QObject* p);
private :
    // Methode pour faciliter la gestion des fichier .ini
    void setValueGroup(int file,const QString &group, const QString &key, const QVariant &value);
    void setValueSimple(int file,const QString &key, const QVariant &value);
    QVariant getValueSimple(int file,const QString &key,
                            const QVariant &defaultValue) const;
    QVariant getValueGroup(int file,const QString &group,
                           const QString &key,
                           const QVariant &defaultValue = QVariant()) const;
    // objQT
    QObject *parent;
    // Obj Setting
    QSettings *settingApp;

};

#endif // CARRERASETTING_H
