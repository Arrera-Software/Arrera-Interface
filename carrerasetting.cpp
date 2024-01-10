#include "carrerasetting.h"
#include <qdebug.h>


CArreraSetting::CArreraSetting()
{
    nameFile = "config.ini";
    etatChargement = gestionFile.charger(nameFile);
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

bool CArreraSetting::setNameMode1(string valeur)
{
    if (etatChargement)
    {
        gestionFile.definirParametre("nameMode1",valeur);
        gestionFile.sauvegarder(nameFile);
        nameMode1 = gestionFile.obtenirParametre("nameMode1");
        return true;
    }
    else
    {
        return false;
    }
}

bool CArreraSetting::setNameMode2(string valeur)
{
    if (etatChargement)
    {
        gestionFile.definirParametre("nameMode2",valeur);
        gestionFile.sauvegarder(nameFile);
        nameMode1 = gestionFile.obtenirParametre("nameMode2");
        return true;
    }
    else
    {
        return false;
    }
}


bool CArreraSetting::setNameMode3(string valeur)
{
    if (etatChargement)
    {
        gestionFile.definirParametre("nameMode3",valeur);
        gestionFile.sauvegarder(nameFile);
        nameMode1 = gestionFile.obtenirParametre("nameMode3");
        return true;
    }
    else
    {
        return false;
    }
}


bool CArreraSetting::setNameMode4(string valeur)
{
    if (etatChargement)
    {
        gestionFile.definirParametre("nameMode4",valeur);
        gestionFile.sauvegarder(nameFile);
        nameMode1 = gestionFile.obtenirParametre("nameMode4");
        return true;
    }
    else
    {
        return false;
    }
}


bool CArreraSetting::setNameMode5(string valeur)
{
    if (etatChargement)
    {
        gestionFile.definirParametre("nameMode5",valeur);
        gestionFile.sauvegarder(nameFile);
        nameMode1 = gestionFile.obtenirParametre("nameMode5");
        return true;
    }
    else
    {
        return false;
    }
}

