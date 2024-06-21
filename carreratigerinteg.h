#ifndef CARRERATIGERINTEG_H
#define CARRERATIGERINTEG_H

#include "carrerasetting.h"
#include <QSettings>
#include <QString>

class CArreraTigerInteg
{
private :
    string nameFile;
    QSettings *settings;
public:
    CArreraTigerInteg();
    bool copiloteInstall();

};

#endif // CARRERATIGERINTEG_H
