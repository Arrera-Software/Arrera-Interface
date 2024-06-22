#ifndef CARRERATIGERINTEG_H
#define CARRERATIGERINTEG_H

#include <QProcess>
#include "carrerasetting.h"
#include <QSettings>
#include <QString>

class CArreraTigerInteg
{
private :
    QProcess *proccess;
public:
    CArreraTigerInteg(QProcess *pProcces);
    bool copiloteInstall();
    bool startCopilote();
};

#endif // CARRERATIGERINTEG_H
