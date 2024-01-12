#include "carrerasetting.h"
#include <qdebug.h>


CArreraSetting::CArreraSetting()
{
    int i = 0 ;
    nameFile = "config.ini";
    nameFileMode[0]="configMode1.ini";
    nameFileMode[1]="configMode2.ini";
    nameFileMode[2]="configMode3.ini";
    nameFileMode[3]="configMode4.ini";
    nameFileMode[4]="configMode5.ini";
    etatChargement = gestionFile.charger(nameFile);
    for (i=0;i<4;i++)
    {
        chargementMode[i] = gestionFileMode[i].charger(nameFileMode[i]);
    }
}

bool CArreraSetting::loadSetting()
{
    if (etatChargement)
    {
        nameMode1 = gestionFile.obtenirParametre("nameMode1");
        nameMode2 = gestionFile.obtenirParametre("nameMode2");
        nameMode3 = gestionFile.obtenirParametre("nameMode3");
        nameMode4 = gestionFile.obtenirParametre("nameMode4");
        nameMode5 = gestionFile.obtenirParametre("nameMode5");
        return true;
    }
    else
    {
        return false;
    }

}



string CArreraSetting::getNameMode1()
{
    if (etatChargement)
    {
        return nameMode1;
    }
    else
    {
        return "";
    }
}

string CArreraSetting::getNameMode2()
{
    if (etatChargement)
    {
        return nameMode2;
    }
    else
    {
        return "";
    }
}

string CArreraSetting::getNameMode3()
{
    if (etatChargement)
    {
        return nameMode3;
    }
    else
    {
        return "";
    }
}

string CArreraSetting::getNameMode4()
{
    if (etatChargement)
    {
        return nameMode4;
    }
    else
    {
        return "";
    }
}

string CArreraSetting::getNameMode5()
{
    if (etatChargement)
    {
        return nameMode5;
    }
    else
    {
        return "";
    }
}

bool CArreraSetting::setNameMode(int nbMode,string valeur)
{
    if (etatChargement)
    {
        switch (nbMode) {
        case 1:
            gestionFile.definirParametre("nameMode1",valeur);
            gestionFile.sauvegarder(nameFile);
            nameMode1 = gestionFile.obtenirParametre("nameMode1");
            return true;
            break;
        case 2:
            gestionFile.definirParametre("nameMode2",valeur);
            gestionFile.sauvegarder(nameFile);
            nameMode1 = gestionFile.obtenirParametre("nameMode2");
            return true;
            break;
        case 3:
            gestionFile.definirParametre("nameMode3",valeur);
            gestionFile.sauvegarder(nameFile);
            nameMode1 = gestionFile.obtenirParametre("nameMode3");
            return true;
            break;
        case 4:
            gestionFile.definirParametre("nameMode4",valeur);
            gestionFile.sauvegarder(nameFile);
            nameMode1 = gestionFile.obtenirParametre("nameMode4");
            return true;
            break;
        case 5:
            gestionFile.definirParametre("nameMode5",valeur);
            gestionFile.sauvegarder(nameFile);
            nameMode1 = gestionFile.obtenirParametre("nameMode5");
            return true;
            break;
        default:
            return false;
            break;
        }
    }
    else
    {
        return false;
    }
}

bool CArreraSetting::setAssistantMode(int nbMode,bool ryley,bool six)
{
    switch (nbMode) {
    case 1:
        if (chargementMode[0]==false)
        {
            return false;
        }
        else
        {
            if (six==true)
            {
                gestionFileMode[0].definirParametre("assistant","six");
                gestionFileMode[0].sauvegarder(nameFileMode[0]);
                return true;
            }
            else
            {
                if (ryley==true)
                {
                    gestionFileMode[0].definirParametre("assistant","ryley");
                    gestionFileMode[0].sauvegarder(nameFileMode[0]);
                    return true;
                }
                else
                {
                    gestionFileMode[0].definirParametre("assistant","nothing");
                    gestionFileMode[0].sauvegarder(nameFileMode[0]);
                    return true;
                }
            }

        }
        break;
    case 2:
        if (chargementMode[1]==false)
        {
            return false;
        }
        else
        {
            if (six==true)
            {
                gestionFileMode[1].definirParametre("assistant","six");
                gestionFileMode[1].sauvegarder(nameFileMode[1]);
                return true;
            }
            else
            {
                if (ryley==true)
                {
                    gestionFileMode[1].definirParametre("assistant","ryley");
                    gestionFileMode[1].sauvegarder(nameFileMode[1]);
                    return true;
                }
                else
                {
                    gestionFileMode[1].definirParametre("assistant","nothing");
                    gestionFileMode[1].sauvegarder(nameFileMode[1]);
                    return true;
                }
            }

        }
        break;
    case 3:
        if (chargementMode[2]==false)
        {
            return false;
        }
        else
        {
            if (six==true)
            {
                gestionFileMode[2].definirParametre("assistant","six");
                gestionFileMode[2].sauvegarder(nameFileMode[2]);
                return true;
            }
            else
            {
                if (ryley==true)
                {
                    gestionFileMode[2].definirParametre("assistant","ryley");
                    gestionFileMode[2].sauvegarder(nameFileMode[2]);
                    return true;
                }
                else
                {
                    gestionFileMode[2].definirParametre("assistant","nothing");
                    gestionFileMode[2].sauvegarder(nameFileMode[2]);
                    return true;
                }
            }

        }
        break;
    case 4:
        if (chargementMode[3]==false)
        {
            return false;
        }
        else
        {
            if (six==true)
            {
                gestionFileMode[3].definirParametre("assistant","six");
                gestionFileMode[3].sauvegarder(nameFileMode[3]);
                return true;
            }
            else
            {
                if (ryley==true)
                {
                    gestionFileMode[3].definirParametre("assistant","ryley");
                    gestionFileMode[3].sauvegarder(nameFileMode[3]);
                    return true;
                }
                else
                {
                    gestionFileMode[3].definirParametre("assistant","nothing");
                    gestionFileMode[3].sauvegarder(nameFileMode[3]);
                    return true;
                }
            }
        }
        break;
    case 5:
        if (chargementMode[4]==false)
        {
            return false;
        }
        else
        {
            if (six==true)
            {
                gestionFileMode[4].definirParametre("assistant","six");
                gestionFileMode[4].sauvegarder(nameFileMode[4]);
                return true;
            }
            else
            {
                if (ryley==true)
                {
                    gestionFileMode[4].definirParametre("assistant","ryley");
                    gestionFileMode[4].sauvegarder(nameFileMode[4]);
                    return true;
                }
                else
                {
                    gestionFileMode[4].definirParametre("assistant","nothing");
                    gestionFileMode[4].sauvegarder(nameFileMode[4]);
                    return true;
                }
            }
        }
        break;
    default:
        return false;
        break;
    }
}

bool CArreraSetting::setEtatTaskbar(int nbMode,bool enable)
{
    switch (nbMode) {
    case 1:
        if (chargementMode[0]==true)
        {
            if (enable==true)
            {
                gestionFileMode[0].definirParametre("taskbar","true");
            }
            else
            {
                gestionFileMode[0].definirParametre("taskbar","false");
            }
            gestionFileMode[0].sauvegarder(nameFileMode[0]);
            return true;
        }
        else
        {
            return false;
        }
        break;
    case 2:
        if (chargementMode[1]==true)
        {
            if (enable==true)
            {
                gestionFileMode[1].definirParametre("taskbar","true");
            }
            else
            {
                gestionFileMode[1].definirParametre("taskbar","false");
            }
            gestionFileMode[1].sauvegarder(nameFileMode[1]);
            return true;
        }
        else
        {
            return false;
        }
        break;
    case 3:
        if (chargementMode[2]==true)
        {
            if (enable==true)
            {
                gestionFileMode[2].definirParametre("taskbar","true");
            }
            else
            {
                gestionFileMode[2].definirParametre("taskbar","false");
            }
            gestionFileMode[2].sauvegarder(nameFileMode[2]);
            return true;
        }
        else
        {
            return false;
        }
        break;
    case 4:
        if (chargementMode[3]==true)
        {
            if (enable==true)
            {
                gestionFileMode[3].definirParametre("taskbar","true");
            }
            else
            {
                gestionFileMode[3].definirParametre("taskbar","false");
            }
            gestionFileMode[3].sauvegarder(nameFileMode[3]);
            return true;
        }
        else
        {
            return false;
        }
        break;
    case 5:
        if (chargementMode[3]==true)
        {
            if (enable==true)
            {
                gestionFileMode[4].definirParametre("taskbar","true");
            }
            else
            {
                gestionFileMode[4].definirParametre("taskbar","false");
            }
            gestionFileMode[4].sauvegarder(nameFileMode[4]);
            return true;
        }
        else
        {
            return false;
        }
        break;
    default:
        return false;
        break;
    }
}