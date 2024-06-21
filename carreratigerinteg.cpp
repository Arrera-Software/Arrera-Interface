#include "carreratigerinteg.h"

CArreraTigerInteg::CArreraTigerInteg()
{
    settings = new QSettings("arreraSoft.ini", QSettings::IniFormat);
}

bool CArreraTigerInteg::copiloteInstall()
{
    settings->beginGroup("copilote");
    QString valeur = settings->value("exe","").toString();
    if (valeur=="copilote.exe")
    {
        return true;
    }
    else
    {
        return false;
    }
}
