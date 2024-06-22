#include "carreratigerinteg.h"

CArreraTigerInteg::CArreraTigerInteg(QProcess *pProcces)
{
    proccess = pProcces;
}

bool CArreraTigerInteg::copiloteInstall()
{
    QSettings settings("arreraSoft.ini", QSettings::IniFormat);
    settings.beginGroup("copilote");
    if (settings.value("exe","").toString()=="copilote.exe")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CArreraTigerInteg::startCopilote()
{
    QSettings settings("arreraSoft.ini", QSettings::IniFormat);
    settings.beginGroup("copilote");
    QString workingDirectory = settings.value("folder","").toString();
    proccess->setWorkingDirectory(workingDirectory);
    proccess->start(workingDirectory +"/"+ settings.value("exe","").toString());
    return proccess->waitForStarted();
}
