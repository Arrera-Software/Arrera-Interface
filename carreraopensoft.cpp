#include "carreraopensoft.h"
#include "QDebug"

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
        if ((windowsOS==true)&&(linuxOS==false))
        {
            if (QDesktopServices::openUrl(QUrl::fromLocalFile(QString::fromStdString(objPara->getSoftTableur())))) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            if ((windowsOS==false)&&(linuxOS==true))
            {
                if (QProcess::startDetached(QString::fromStdString(objPara->getSoftTableur())))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
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
        if ((windowsOS==true)&&(linuxOS==false))
        {
            if (QDesktopServices::openUrl(QUrl::fromLocalFile(QString::fromStdString(objPara->getSoftTTexte())))) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            if ((windowsOS==false)&&(linuxOS==true))
            {
                if (QProcess::startDetached(QString::fromStdString(objPara->getSoftTTexte())))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
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
        if ((windowsOS==true)&&(linuxOS==false))
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
            if ((windowsOS==false)&&(linuxOS==true))
            {
                if (QProcess::startDetached(QString::fromStdString(objPara->getSoftNavigateur())))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else{
                return false;
            }
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
        if ((windowsOS==true)&&(linuxOS==false))
        {
            if (QDesktopServices::openUrl(QUrl::fromLocalFile(QString::fromStdString(objPara->getSoftPresentation())))) {
                return true;
            }
            else {
                return false;
            }
        }
        else
        {
            if ((windowsOS==false)&&(linuxOS==true))
            {
                if (QProcess::startDetached(QString::fromStdString(objPara->getSoftPresentation())))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else{
                return false;
            }
        }
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
        if ((windowsOS==true)&&(linuxOS==false))
        {
            emplacement = objPara->getSixEmplacement();
            assistant = QString::fromStdString(emplacement)+"/"+NAMELNKSIXWIN;
            if (QDesktopServices::openUrl(QUrl::fromLocalFile(assistant))) {
                return true;
            }
            else {
                return false;
            }
        }
        else
        {
            if ((windowsOS==false)&&(linuxOS==true))
            {
                emplacement = objPara->getSixEmplacement();
                assistant = QString::fromStdString(emplacement)+"/"+NAMESIXSH;
                if (QProcess::startDetached("/bin/bash",QStringList() << assistant))
                {

                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
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
        if ((windowsOS==true)&&(linuxOS==false))
        {
            emplacement = objPara->getRyleyEmplacement();
            assistant = QString::fromStdString(emplacement)+"/"+NAMELNKRYLEYWIN;
            if (QDesktopServices::openUrl(QUrl::fromLocalFile(assistant))) {
                return true;
            }
            else {
                return false;
            }
        }
        else
        {
            if ((windowsOS==false)&&(linuxOS==true))
            {
                emplacement = objPara->getRyleyEmplacement();
                assistant = QString::fromStdString(emplacement)+"/"+NAMERYLEYSH;
                if (QProcess::startDetached("/bin/bash",QStringList() << assistant))
                {

                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
}

bool CArreraOpenSoft::openSixPara()
{
    string emplacement ;
    QString assistant;
    if (objSet)
    {
        if ((windowsOS==true)&&(linuxOS==false))
        {
            emplacement = objPara->getSixEmplacement();
            assistant = QString::fromStdString(emplacement)+"/"+NAMELNKPARASIXWIN;
            if (QDesktopServices::openUrl(QUrl::fromLocalFile(assistant))) {
                return true;
            }
            else {
                return false;
            }
        }
        else
        {
            if ((windowsOS==false)&&(linuxOS==true))
            {
                emplacement = objPara->getSixEmplacement();
                assistant = QString::fromStdString(emplacement)+"/"+NAMESIXPARASH;
                if (QProcess::startDetached("/bin/bash",QStringList() << assistant))
                {

                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
}
bool CArreraOpenSoft::openRyleyPara()
{
    string emplacement ;
    QString assistant;
    if (objSet)
    {
        if ((windowsOS==true)&&(linuxOS==false))
        {
            emplacement = objPara->getRyleyEmplacement();
            assistant = QString::fromStdString(emplacement)+"/"+NAMELNKPARARYLEYWIN;
            if (QDesktopServices::openUrl(QUrl::fromLocalFile(assistant))) {
                return true;
            }
            else {
                return false;
            }
        }
        else
        {
            if ((windowsOS==false)&&(linuxOS==true))
            {
                emplacement = objPara->getRyleyEmplacement();
                assistant = QString::fromStdString(emplacement)+"/"+NAMERYLEYPARASH;
                if (QProcess::startDetached("/bin/bash",QStringList() << assistant))
                {

                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
}

bool CArreraOpenSoft::openAppLib(int nb)
{
    if (objSet)
    {
        if ((windowsOS==true)&&(linuxOS==false))
        {
            if (QDesktopServices::openUrl(QUrl::fromLocalFile(QString::fromStdString(objPara->getEmplacementApp(nb))))) {
                return true;
            }
            else {
                return false;
            }
        }
        else
        {
            if ((windowsOS==false)&&(linuxOS==true))
            {
                if (QProcess::startDetached(QString::fromStdString(objPara->getSoftPresentation())))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    else
    {
        return false;
    }
}


bool CArreraOpenSoft::openArreraApp(int nb)
{
    if (objSet)
    {
        if ((windowsOS==true)&&(linuxOS==false))
        {
            if (QDesktopServices::openUrl(QUrl::fromLocalFile(QString::fromStdString(objPara->getArreraAppEmplacement(nb))))) {
                return true;
            }
            else {
                return false;
            }
        }
        else
        {
            if ((windowsOS==false)&&(linuxOS==true))
            {
                if (QProcess::startDetached(QString::fromStdString(objPara->getSoftPresentation())))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    else
    {
        return false;
    }
}
