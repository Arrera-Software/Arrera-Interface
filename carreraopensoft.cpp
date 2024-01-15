#include "carreraopensoft.h"

CArreraOpenSoft::CArreraOpenSoft()
{
    objSet = false;
    linuxOS = system.getLinux();
    windowsOS = system.getWindows();
}


void CArreraOpenSoft::setObjPara(CArreraSetting* obj)
{
    objPara = obj ;
    objSet = true;
}
bool CArreraOpenSoft::openTableur()
{
    if (objSet)
    {
        if (QDesktopServices::openUrl(QUrl::fromLocalFile(QString::fromStdString(objPara->getSoftTableur())))) {
            return true;
        }
        else {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool CArreraOpenSoft::openTTexte()
{
    if (objSet)
    {
        if (QDesktopServices::openUrl(QUrl::fromLocalFile(QString::fromStdString(objPara->getSoftTTexte())))) {
            return true;
        }
        else {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool CArreraOpenSoft::openNavigateur()
{
    if (objSet)
    {
        if (QDesktopServices::openUrl(QUrl::fromLocalFile(QString::fromStdString(objPara->getSoftNavigateur())))) {
            return true;
        }
        else {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool CArreraOpenSoft::openPresentation()
{
    if (objSet)
    {
        if (QDesktopServices::openUrl(QUrl::fromLocalFile(QString::fromStdString(objPara->getSoftPresentation())))) {
            return true;
        }
        else {
            return false;
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool CArreraOpenSoft::openSix()
{
    string emplacement ;
    QString assistant;
    if (objSet)
    {
        emplacement = objPara->getSixEmplacement();
        assistant = QString::fromStdString(emplacement)+"/"+NAMELNKSIXWIN;
        if (QDesktopServices::openUrl(QUrl::fromLocalFile(assistant))) {
            return true;
        }
        else {
            return false;
        }
        return true;
    }
    else
    {
        return false;
    }
}
bool CArreraOpenSoft::openRyley()
{
    string emplacement ;
    QString assistant;
    if (objSet)
    {
        emplacement = objPara->getSixEmplacement();
        assistant = QString::fromStdString(emplacement)+"/"+NAMELNKRYLEYWIN;
        if (QDesktopServices::openUrl(QUrl::fromLocalFile(assistant))) {
            return true;
        }
        else {
            return false;
        }
        return true;
    }
    else
    {
        return false;
    }
}
