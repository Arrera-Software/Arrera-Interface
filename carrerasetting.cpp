#include "carrerasetting.h"
#include <qdebug.h>
#include <QFileDialog>

CArreraSetting::CArreraSetting()
{
    // Recuperartion etat systeme d'exploitation
    windowsOS = systeme.getWindows();
    linuxOS = systeme.getLinux();
    // Nom des fichier
    nameFile = "config.ini";
    nameFileMode[0]="configMode1.ini";
    nameFileMode[1]="configMode2.ini";
    nameFileMode[2]="configMode3.ini";
    nameFileMode[3]="configMode4.ini";
    nameFileMode[4]="configMode5.ini";
    nameFileApp =  "configAPP.ini";
    nameFileTaskbarMode[0] = nameFile;
    nameFileTaskbarMode[1] = nameFileMode[0];
    nameFileTaskbarMode[2] = nameFileMode[1];
    nameFileTaskbarMode[3] = nameFileMode[2];
    nameFileTaskbarMode[4] = nameFileMode[3];
    nameFileTaskbarMode[5] = nameFileMode[4];
    // Chargement de fichier
    chargedAllFile();
}

void CArreraSetting::chargedAllFile()
{
    int i = 0 ;
    etatChargement = gestionFile.charger(nameFile);
    chargementFileApp = gestionFileApp.charger(nameFileApp);
    for (i=0;i<4;i++)
    {
        chargementMode[i] = gestionFileMode[i].charger(nameFileMode[i]);
    }
    etatFileTaskbar[0]=gestionFileTaskbar[0].charger(nameFile);
    etatFileTaskbar[1]=gestionFileTaskbar[1].charger(nameFileMode[0]);
    etatFileTaskbar[2]=gestionFileTaskbar[2].charger(nameFileMode[1]);
    etatFileTaskbar[3]=gestionFileTaskbar[3].charger(nameFileMode[2]);
    etatFileTaskbar[4]=gestionFileTaskbar[4].charger(nameFileMode[3]);
    etatFileTaskbar[5]=gestionFileTaskbar[5].charger(nameFileMode[4]);
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
        chargedAllFile();
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

string CArreraSetting::getNameUser()
{
    if (etatChargement)
    {
        return gestionFile.obtenirParametre("nameUser");
    }
    else
    {
        return "";
    }
}

string CArreraSetting::getRyleyEmplacement()
{
    if (etatChargement)
    {
        return gestionFile.obtenirParametre("emplacementRyley");
    }
    else
    {
        return "";
    }
}

string CArreraSetting::getSixEmplacement()
{
    if (etatChargement)
    {
        return gestionFile.obtenirParametre("emplacementSix");
    }
    else
    {
        return "";
    }
}

string CArreraSetting::getAssistantMode(int nbMode)
{
    if (chargementMode[nbMode-1])
    {
        string sortie;
        sortie = gestionFileMode[nbMode-1].obtenirParametre("assistant");
        return sortie;
    }
    else
    {
        return "";
    }
}

string CArreraSetting::getEtatTaskbar(int nbMode)
{
    if (chargementMode[nbMode-1])
    {
        return gestionFileMode[nbMode-1].obtenirParametre("taskbar");
    }
    else
    {
        return "";
    }
}

string CArreraSetting::getSoftNavigateur()
{
    if (etatChargement)
    {
        return gestionFile.obtenirParametre("emplacementNavigateur");
    }
    else
    {
        return "";
    }
}

string CArreraSetting::getSoftTableur()
{
    if (etatChargement)
    {
        return gestionFile.obtenirParametre("emplacementTableur");
    }
    else
    {
        return "";
    }
}


string CArreraSetting::getSoftTTexte()
{
    if (etatChargement)
    {
        return gestionFile.obtenirParametre("emplacementTraitementT");
    }
    else
    {
        return "";
    }
}

string CArreraSetting::getSoftPresentation()
{
    if (etatChargement)
    {
        return gestionFile.obtenirParametre("emplacementPresentation");
    }
    else
    {
        return "";
    }
}

string CArreraSetting::getNameApp(int nb)
{
    string sortie ;
    if (chargementFileApp)
    {

        switch (nb) {
        case 1:
            sortie=gestionFileApp.obtenirParametre("nameApp1");
            return sortie;
            break;
        case 2:
            sortie=gestionFileApp.obtenirParametre("nameApp2");
            return sortie;
            break;
        case 3:
            sortie=gestionFileApp.obtenirParametre("nameApp3");
            return sortie;
            break;
        case 4:
            sortie=gestionFileApp.obtenirParametre("nameApp4");
            return sortie;
            break;
        case 5:
            sortie=gestionFileApp.obtenirParametre("nameApp5");
            return sortie;
            break;
        case 6:
            sortie=gestionFileApp.obtenirParametre("nameApp6");
            return sortie;
            break;
        case 7:
            sortie=gestionFileApp.obtenirParametre("nameApp7");
            return sortie;
            break;
        case 8:
            sortie=gestionFileApp.obtenirParametre("nameApp8");
            return sortie;
            break;
        case 9:
            sortie=gestionFileApp.obtenirParametre("nameApp9");
            return sortie;
            break;
        case 10:
            sortie=gestionFileApp.obtenirParametre("nameApp10");
            return sortie;
            break;
        case 11:
            sortie=gestionFileApp.obtenirParametre("nameApp11");
            return sortie;
            break;
        case 12:
            sortie=gestionFileApp.obtenirParametre("nameApp12");
            return sortie;
            break;
        default:
            return "";
            break;
        }
    }
    else
    {
        return "";
    }
}

string CArreraSetting::getEmplacementApp(int nb)
{
    string sortie ;
    if (chargementFileApp)
    {

        switch (nb) {
        case 1:
            sortie=gestionFileApp.obtenirParametre("emplacementApp1");
            return sortie;
            break;
        case 2:
            sortie=gestionFileApp.obtenirParametre("emplacementApp2");
            return sortie;
            break;
        case 3:
            sortie=gestionFileApp.obtenirParametre("emplacementApp3");
            return sortie;
            break;
        case 4:
            sortie=gestionFileApp.obtenirParametre("emplacementApp4");
            return sortie;
            break;
        case 5:
            sortie=gestionFileApp.obtenirParametre("emplacementApp5");
            return sortie;
            break;
        case 6:
            sortie=gestionFileApp.obtenirParametre("emplacementApp6");
            return sortie;
            break;
        case 7:
            sortie=gestionFileApp.obtenirParametre("emplacementApp7");
            return sortie;
            break;
        case 8:
            sortie=gestionFileApp.obtenirParametre("emplacementApp8");
            return sortie;
            break;
        case 9:
            sortie=gestionFileApp.obtenirParametre("emplacementApp9");
            return sortie;
            break;
        case 10:
            sortie=gestionFileApp.obtenirParametre("emplacementApp10");
            return sortie;
            break;
        case 11:
            sortie=gestionFileApp.obtenirParametre("emplacementApp11");
            return sortie;
            break;
        case 12:
            sortie=gestionFileApp.obtenirParametre("emplacementApp12");
            return sortie;
            break;
        default:
            return "";
            break;
        }
    }
    else
    {
        return "";
    }
}

string CArreraSetting::getArreraAppEmplacement(int nb)
{
    string sortie ;
    if (chargementFileApp)
    {
        switch (nb) {
        case 1:
            sortie=gestionFileApp.obtenirParametre("emplacementArreraVideo");
            return sortie;
            break;
        case 2:
            sortie=gestionFileApp.obtenirParametre("emplacementArreraDoc");
            return sortie;
            break;
        case 3:
            sortie=gestionFileApp.obtenirParametre("emplacementArreraInfo");
            return sortie;
            break;
        case 4:
            sortie=gestionFileApp.obtenirParametre("emplacementArreraRecherche");
            return sortie;
            break;
        default:
            return "";
            break;
        }
    }
    else
    {
        return "";
    }
}

string CArreraSetting::getNbAppTaskbar(int nbButton,int mode)
{
    if ((etatFileTaskbar[0])&&(etatFileTaskbar[1])&&(etatFileTaskbar[2])&&(etatFileTaskbar[3])&&(etatFileTaskbar[4])&&(etatFileTaskbar[5]))
    {
        string sortieString;
        switch (nbButton) {
        case 1:
            sortieString=gestionFileTaskbar[mode].obtenirParametre("btnTaskbar1");
            return sortieString;
            break;
        case 2:
            sortieString=gestionFileTaskbar[mode].obtenirParametre("btnTaskbar2");
            return sortieString;
            break;
        case 3:
            sortieString=gestionFileTaskbar[mode].obtenirParametre("btnTaskbar3");
            return sortieString;
            break;
        case 4:
            sortieString=gestionFileTaskbar[mode].obtenirParametre("btnTaskbar4");
            return sortieString;
            break;
        case 5:
            sortieString=gestionFileTaskbar[mode].obtenirParametre("btnTaskbar5");
            return sortieString;
            break;
        default:
            return "";
            break;
        }

    }
    else
    {
        return "";
    }
}

bool CArreraSetting::resetAllPara()
{
    if (etatChargement)
    {
        int i ;
        gestionFile.definirParametre("nameUser","Nothing");
        gestionFile.definirParametre("nameMode1","Mode 1");
        gestionFile.definirParametre("nameMode2","Mode 2");
        gestionFile.definirParametre("nameMode3","Mode 3");
        gestionFile.definirParametre("nameMode4","Mode 4");
        gestionFile.definirParametre("nameMode5","Mode 5");
        gestionFile.definirParametre("emplacementTableur","nothing");
        gestionFile.definirParametre("emplacementSix","nothing");
        gestionFile.definirParametre("emplacementRyley","nothing");
        gestionFile.definirParametre("emplacementPresentation","nothing");
        gestionFile.definirParametre("emplacementTraitementT","nothing");
        gestionFile.definirParametre("emplacementNavigateur","nothing");
        gestionFile.definirParametre("btnTaskbar1","nothing");
        gestionFile.definirParametre("btnTaskbar2","nothing");
        gestionFile.definirParametre("btnTaskbar3","nothing");
        gestionFile.definirParametre("btnTaskbar4","nothing");
        gestionFile.definirParametre("btnTaskbar5","nothing");

        gestionFileApp.definirParametre("emplacementApp1","nothing");
        gestionFileApp.definirParametre("emplacementApp2","nothing");
        gestionFileApp.definirParametre("emplacementApp3","nothing");
        gestionFileApp.definirParametre("emplacementApp4","nothing");
        gestionFileApp.definirParametre("emplacementApp5","nothing");
        gestionFileApp.definirParametre("emplacementApp6","nothing");
        gestionFileApp.definirParametre("emplacementApp7","nothing");
        gestionFileApp.definirParametre("emplacementApp8","nothing");
        gestionFileApp.definirParametre("emplacementApp9","nothing");
        gestionFileApp.definirParametre("emplacementApp10","nothing");
        gestionFileApp.definirParametre("emplacementApp11","nothing");
        gestionFileApp.definirParametre("emplacementApp12","nothing");
        gestionFileApp.definirParametre("nameApp1","nothing");
        gestionFileApp.definirParametre("nameApp2","nothing");
        gestionFileApp.definirParametre("nameApp3","nothing");
        gestionFileApp.definirParametre("nameApp4","nothing");
        gestionFileApp.definirParametre("nameApp5","nothing");
        gestionFileApp.definirParametre("nameApp6","nothing");
        gestionFileApp.definirParametre("nameApp7","nothing");
        gestionFileApp.definirParametre("nameApp8","nothing");
        gestionFileApp.definirParametre("nameApp9","nothing");
        gestionFileApp.definirParametre("nameApp10","nothing");
        gestionFileApp.definirParametre("nameApp11","nothing");
        gestionFileApp.definirParametre("nameApp12","nothing");
        gestionFileApp.definirParametre("emplacementArreraVideo","nothing");
        gestionFileApp.definirParametre("emplacementArreraDoc","nothing");
        gestionFileApp.definirParametre("emplacementArreraInfo","nothing");
        gestionFileApp.definirParametre("emplacementArreraRecherche","nothing");
        gestionFileApp.sauvegarder(nameFileApp);
        gestionFile.sauvegarder(nameFile);

        if ((chargementMode[0])&&(chargementMode[1])&&(chargementMode[2])&&(chargementMode[3]&&(chargementMode[4])))
        {
            for (i=0;i<5;i++)
            {
                gestionFileMode[i].definirParametre("assistant","nothing");
                gestionFileMode[i].definirParametre("taskbar","false");
                gestionFileMode[i].sauvegarder(nameFileMode[i]);
                gestionFileMode[i].definirParametre("btnTaskbar1","nothing");
                gestionFileMode[i].definirParametre("btnTaskbar2","nothing");
                gestionFileMode[i].sauvegarder(nameFileMode[i]);
                gestionFileMode[i].definirParametre("btnTaskbar3","nothing");
                gestionFileMode[i].definirParametre("btnTaskbar4","nothing");
                gestionFileMode[i].sauvegarder(nameFileMode[i]);
                gestionFileMode[i].definirParametre("btnTaskbar5","nothing");
                gestionFileMode[i].definirParametre("appBoot","0");
                gestionFileMode[i].definirParametre("modeSet","0");
                gestionFileMode[i].sauvegarder(nameFileMode[i]);

            }
            chargedAllFile();
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

string CArreraSetting::getModeAppAsBoot(int mode)
{
    if (chargementMode[mode-1])
    {
        return gestionFileMode[mode-1].obtenirParametre("appBoot");
    }
    else
    {
        return "";
    }
}

string CArreraSetting::getModeEnable(int mode)
{
    if (chargementMode[mode-1])
    {
        return gestionFileMode[mode-1].obtenirParametre("modeSet");
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
            chargedAllFile();
            return true;
            break;
        case 2:
            gestionFile.definirParametre("nameMode2",valeur);
            gestionFile.sauvegarder(nameFile);
            nameMode1 = gestionFile.obtenirParametre("nameMode2");
            chargedAllFile();
            return true;
            break;
        case 3:
            gestionFile.definirParametre("nameMode3",valeur);
            gestionFile.sauvegarder(nameFile);
            nameMode1 = gestionFile.obtenirParametre("nameMode3");
            chargedAllFile();
            return true;
            break;
        case 4:
            gestionFile.definirParametre("nameMode4",valeur);
            gestionFile.sauvegarder(nameFile);
            nameMode1 = gestionFile.obtenirParametre("nameMode4");
            chargedAllFile();
            return true;
            break;
        case 5:
            gestionFile.definirParametre("nameMode5",valeur);
            gestionFile.sauvegarder(nameFile);
            nameMode1 = gestionFile.obtenirParametre("nameMode5");
            chargedAllFile();
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
    bool sortie;
    if (chargementMode[nbMode-1])
    {
        if ((six==true)&&(ryley==false))
        {
            gestionFileMode[nbMode-1].definirParametre("assistant","six");
            sortie = gestionFileMode[nbMode-1].sauvegarder(nameFileMode[nbMode-1]);
            return sortie;
        }
        else
        {
            if ((six==false)&&(ryley==true))
            {
                gestionFileMode[nbMode-1].definirParametre("assistant","ryley");
                sortie = gestionFileMode[nbMode-1].sauvegarder(nameFileMode[nbMode-1]);
                return sortie;
            }
            else
            {
                gestionFileMode[nbMode-1].definirParametre("assistant","nothing");
                sortie = gestionFileMode[nbMode-1].sauvegarder(nameFileMode[nbMode-1]);
                return sortie;
            }
        }
    }
    else
    {
        return false;
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
            chargedAllFile();
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
            chargedAllFile();
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
            chargedAllFile();
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
            chargedAllFile();
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
            chargedAllFile();
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

bool CArreraSetting::setSoftNavigateur()
{
    QString emplacement;
    if (etatChargement==true)
    {
        if ((windowsOS==true)&&(linuxOS==false))
        {
            emplacement = QFileDialog::getOpenFileName(nullptr,"Navigateur Internet", QDir::homePath(), "Fichiers de raccourci (*.lnk)");
        }
        else
        {
            if ((windowsOS==false)&&(linuxOS==true))
            {
                emplacement = QFileDialog::getOpenFileName(nullptr,"Navigateur Internet", QDir::homePath());
            }
            else
            {
                return false;
            }
        }
        if (emplacement.isNull())
        {
            return false ;
        }
        else
        {
            gestionFile.definirParametre("emplacementNavigateur",emplacement.toStdString());
            gestionFile.sauvegarder(nameFile);
            chargedAllFile();
            return true;
        }

    }
    else
    {
        return false;
    }
}

bool CArreraSetting::setSoftPresentation()
{
    QString emplacement;
    if (etatChargement==true)
    {
        if ((windowsOS==true)&&(linuxOS==false))
        {
            emplacement = QFileDialog::getOpenFileName(nullptr,"Presentation", QDir::homePath(), "Fichiers de raccourci (*.lnk)");
        }
        else
        {
            if ((windowsOS==false)&&(linuxOS==true))
            {
                emplacement = QFileDialog::getOpenFileName(nullptr,"Presentation", QDir::homePath());
            }
            else
            {
                return false;
            }
        }
        if (emplacement.isNull())
        {
            return false ;
        }
        else
        {
            gestionFile.definirParametre("emplacementPresentation",emplacement.toStdString());
            gestionFile.sauvegarder(nameFile);
            chargedAllFile();
            return true;
        }

    }
    else
    {
        return false;
    }
}

bool CArreraSetting::setSoftTTexte()
{
    QString emplacement;
    if (etatChargement==true)
    {
        if ((windowsOS==true)&&(linuxOS==false))
        {
            emplacement = QFileDialog::getOpenFileName(nullptr,"Traitement de texte", QDir::homePath(), "Fichiers de raccourci (*.lnk)");
        }
        else
        {
            if ((windowsOS==false)&&(linuxOS==true))
            {
                emplacement = QFileDialog::getOpenFileName(nullptr,"Traitement de texte", QDir::homePath());
            }
            else
            {
                return false;
            }
        }
        if (emplacement.isNull())
        {
            return false ;
        }
        else
        {
            gestionFile.definirParametre("emplacementTraitementT",emplacement.toStdString());
            gestionFile.sauvegarder(nameFile);
            chargedAllFile();
            return true;
        }

    }
    else
    {
        return false;
    }
}

bool CArreraSetting::setSoftTableur()
{
    QString emplacement;
    if (etatChargement==true)
    {
        if ((windowsOS==true)&&(linuxOS==false))
        {
            emplacement = QFileDialog::getOpenFileName(nullptr,"Tableur", QDir::homePath(), "Fichiers de raccourci (*.lnk)");
        }
        else
        {
            if ((windowsOS==false)&&(linuxOS==true))
            {
                emplacement = QFileDialog::getOpenFileName(nullptr,"Tableur", QDir::homePath());
            }
            else
            {
                return false;
            }
        }
        if (emplacement.isNull())
        {
            return false ;
        }
        else
        {
            gestionFile.definirParametre("emplacementTableur",emplacement.toStdString());
            gestionFile.sauvegarder(nameFile);
            chargedAllFile();
            return true;
        }

    }
    else
    {
        return false;
    }
}

bool CArreraSetting::setSixEmplacement()
{
    QString emplacement;
    if (etatChargement==true)
    {
        emplacement = QFileDialog::getExistingDirectory(nullptr,"Six", QDir::homePath());
        if (emplacement.isNull())
        {
            return false ;
        }
        else
        {
            gestionFile.definirParametre("emplacementSix",emplacement.toStdString());
            gestionFile.sauvegarder(nameFile);
            chargedAllFile();
            return true;
        }

    }
    else
    {
        return false;
    }
}

bool CArreraSetting::setRyleyEmplacement()
{
    QString emplacement;
    if (etatChargement==true)
    {
        emplacement = QFileDialog::getExistingDirectory(nullptr,"Ryley", QDir::homePath());
        if (emplacement.isNull())
        {
            return false ;
        }
        else
        {
            gestionFile.definirParametre("emplacementRyley",emplacement.toStdString());
            gestionFile.sauvegarder(nameFile);
            chargedAllFile();
            return true;
        }

    }
    else
    {
        return false;
    }
}

bool CArreraSetting::setNameUser(string name)
{
    if (etatChargement==true)
    {
        gestionFile.definirParametre("nameUser",name);
        gestionFile.sauvegarder(nameFile);
        chargedAllFile();
        return true;
    }
    else
    {
        return false;
    }
}

bool CArreraSetting::setNameApp(int nb,string name)
{
    if (chargementFileApp==true)
    {

        switch (nb) {
        case 1:
            gestionFileApp.definirParametre("nameApp1",name);
            gestionFileApp.sauvegarder(nameFileApp);
            chargedAllFile();
            return true;
            break;
        case 2:
            gestionFileApp.definirParametre("nameApp2",name);
            gestionFileApp.sauvegarder(nameFileApp);
            chargedAllFile();
            return true;
            break;
        case 3:
            gestionFileApp.definirParametre("nameApp3",name);
            gestionFileApp.sauvegarder(nameFileApp);
            chargedAllFile();
            return true;
            break;
        case 4:
            gestionFileApp.definirParametre("nameApp4",name);
            gestionFileApp.sauvegarder(nameFileApp);
            chargedAllFile();
            return true;
            break;
        case 5:
            gestionFileApp.definirParametre("nameApp5",name);
            gestionFileApp.sauvegarder(nameFileApp);
            chargedAllFile();
            return true;
            break;
        case 6:
            gestionFileApp.definirParametre("nameApp6",name);
            gestionFileApp.sauvegarder(nameFileApp);
            chargedAllFile();
            return true;
            break;
        case 7:
            gestionFileApp.definirParametre("nameApp7",name);
            gestionFileApp.sauvegarder(nameFileApp);
            chargedAllFile();
            return true;
            break;
        case 8:
            gestionFileApp.definirParametre("nameApp8",name);
            gestionFileApp.sauvegarder(nameFileApp);
            chargedAllFile();
            return true;
            break;
        case 9:
            gestionFileApp.definirParametre("nameApp9",name);
            gestionFileApp.sauvegarder(nameFileApp);
            chargedAllFile();
            return true;
            break;
        case 10:
            gestionFileApp.definirParametre("nameApp10",name);
            gestionFileApp.sauvegarder(nameFileApp);
            chargedAllFile();
            return true;
            break;
        case 11:
            gestionFileApp.definirParametre("nameApp11",name);
            gestionFileApp.sauvegarder(nameFileApp);
            chargedAllFile();
            return true;
            break;
        case 12:
            gestionFileApp.definirParametre("nameApp12",name);
            gestionFileApp.sauvegarder(nameFileApp);
            chargedAllFile();
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

bool CArreraSetting::setEmplacementApp(int nb)
{
    QString emplacement;
    if (chargementFileApp)
    {
        if ((windowsOS==true)&&(linuxOS==false))
        {
            emplacement = QFileDialog::getOpenFileName(nullptr,"Application n°"+QString::number(nb), QDir::homePath(), "Fichiers de raccourci (*.lnk)");
        }
        else
        {
            if ((windowsOS==false)&&(linuxOS==true))
            {
                emplacement = QFileDialog::getOpenFileName(nullptr,"Application n°"+QString::number(nb), QDir::homePath());
            }
            else
            {
                return false;
            }
        }
        if (emplacement.isNull())
        {
            return false ;
        }
        else
        {
            switch (nb) {
            case 1:
                gestionFileApp.definirParametre("emplacementApp1",emplacement.toStdString());
                gestionFileApp.sauvegarder(nameFileApp);
                chargedAllFile();
                return true;
                break;
            case 2:
                gestionFileApp.definirParametre("emplacementApp2",emplacement.toStdString());
                gestionFileApp.sauvegarder(nameFileApp);
                chargedAllFile();
                return true;
                break;
            case 3:
                gestionFileApp.definirParametre("emplacementApp3",emplacement.toStdString());
                gestionFileApp.sauvegarder(nameFileApp);
                chargedAllFile();
                return true;
                break;
            case 4:
                gestionFileApp.definirParametre("emplacementApp4",emplacement.toStdString());
                gestionFileApp.sauvegarder(nameFileApp);
                chargedAllFile();
                return true;
                break;
            case 5:
                gestionFileApp.definirParametre("emplacementApp5",emplacement.toStdString());
                gestionFileApp.sauvegarder(nameFileApp);
                chargedAllFile();
                return true;
                break;
            case 6:
                gestionFileApp.definirParametre("emplacementApp6",emplacement.toStdString());
                gestionFileApp.sauvegarder(nameFileApp);
                chargedAllFile();
                return true;
                break;
            case 7:
                gestionFileApp.definirParametre("emplacementApp7",emplacement.toStdString());
                gestionFileApp.sauvegarder(nameFileApp);
                chargedAllFile();
                return true;
                break;
            case 8:
                gestionFileApp.definirParametre("emplacementApp8",emplacement.toStdString());
                gestionFileApp.sauvegarder(nameFileApp);
                chargedAllFile();
                return true;
                break;
            case 9:
                gestionFileApp.definirParametre("emplacementApp9",emplacement.toStdString());
                gestionFileApp.sauvegarder(nameFileApp);
                chargedAllFile();
                return true;
                break;
            case 10:
                gestionFileApp.definirParametre("emplacementApp10",emplacement.toStdString());
                gestionFileApp.sauvegarder(nameFileApp);
                chargedAllFile();
                return true;
                break;
            case 11:
                gestionFileApp.definirParametre("emplacementApp11",emplacement.toStdString());
                gestionFileApp.sauvegarder(nameFileApp);
                chargedAllFile();
                return true;
                break;
            case 12:
                gestionFileApp.definirParametre("emplacementApp12",emplacement.toStdString());
                gestionFileApp.sauvegarder(nameFileApp);
                chargedAllFile();
                return true;
                break;
            default:
                return false;
                break;
            }
        }
    }
    else
    {
        return false;
    }

}

bool CArreraSetting::setArreraAppEmplacement(int nb)
{
    /*
     1 :  Arrera Video
     2 :  Arrera Doc
     3 : Arrera Info
     4 : Arrera Recherche
     */
    QString emplacement;
    if (chargementFileApp)
    {
        if ((windowsOS==true)&&(linuxOS==false))
        {
            emplacement = QFileDialog::getOpenFileName(nullptr,"Arrera App", QDir::homePath(), "Fichiers de raccourci (*.lnk)");
        }
        else
        {
            if ((windowsOS==false)&&(linuxOS==true))
            {
                emplacement = QFileDialog::getOpenFileName(nullptr,"Arrera App", QDir::homePath());
            }
            else
            {
                return false;
            }
        }
        if (emplacement.isNull())
        {
            return false ;
        }
        else
        {
        switch (nb) {
        case 1:
            gestionFileApp.definirParametre("emplacementArreraVideo",emplacement.toStdString());
            gestionFileApp.sauvegarder(nameFileApp);
            chargedAllFile();
            return true;
            break;
        case 2:
            gestionFileApp.definirParametre("emplacementArreraDoc",emplacement.toStdString());
            gestionFileApp.sauvegarder(nameFileApp);
            chargedAllFile();
            return true;
            break;
        case 3:
            gestionFileApp.definirParametre("emplacementArreraInfo",emplacement.toStdString());
            gestionFileApp.sauvegarder(nameFileApp);
            chargedAllFile();
            return true;
            break;
        case 4:
            gestionFileApp.definirParametre("emplacementArreraRecherche",emplacement.toStdString());
            gestionFileApp.sauvegarder(nameFileApp);
            chargedAllFile();
            return true;
            break;
        default:
            return false;
            break;
        }
        }
    }
    else
    {
        return false;
    }

}
bool CArreraSetting::setAppTaskBar(int nbAppTaskbar,int nbAppSelected,int mode)
{


    if ((etatFileTaskbar[0])&&(etatFileTaskbar[1])&&(etatFileTaskbar[2])&&(etatFileTaskbar[3])&&(etatFileTaskbar[4])&&(etatFileTaskbar[5]))
    {
        switch (nbAppTaskbar) {
        case 1:
            if (nbAppSelected==0)
            {
                gestionFileTaskbar[mode].definirParametre("btnTaskbar1","nothing");
            }
            else
            {
                gestionFileTaskbar[mode].definirParametre("btnTaskbar1",to_string(nbAppSelected));
            }
            gestionFileTaskbar[mode].sauvegarder(nameFileTaskbarMode[mode]);
            chargedAllFile();
            return true;
            break;
        case 2:
            if (nbAppSelected==0)
            {
                gestionFileTaskbar[mode].definirParametre("btnTaskbar2","nothing");
            }
            else
            {
                gestionFileTaskbar[mode].definirParametre("btnTaskbar2",to_string(nbAppSelected));
            }
            gestionFileTaskbar[mode].sauvegarder(nameFileTaskbarMode[mode]);
            chargedAllFile();
            return true;
            break;
        case 3:
            if (nbAppSelected==0)
            {
                gestionFileTaskbar[mode].definirParametre("btnTaskbar3","nothing");
            }
            else
            {
                gestionFileTaskbar[mode].definirParametre("btnTaskbar3",to_string(nbAppSelected));
            }
            gestionFileTaskbar[mode].sauvegarder(nameFileTaskbarMode[mode]);
            chargedAllFile();
            return true;
            break;
        case 4:
            if (nbAppSelected==0)
            {
                gestionFileTaskbar[mode].definirParametre("btnTaskbar4","nothing");
            }
            else
            {
                gestionFileTaskbar[mode].definirParametre("btnTaskbar4",to_string(nbAppSelected));
            }
            gestionFileTaskbar[mode].sauvegarder(nameFileTaskbarMode[mode]);
            chargedAllFile();
            return true;
            break;
        case 5:
            if (nbAppSelected==0)
            {
                gestionFileTaskbar[mode].definirParametre("btnTaskbar5","nothing");
            }
            else
            {
                gestionFileTaskbar[mode].definirParametre("btnTaskbar5",to_string(nbAppSelected));
            }
            gestionFileTaskbar[mode].sauvegarder(nameFileTaskbarMode[mode]);
            chargedAllFile();
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

bool CArreraSetting::setModeAppAsBoot(int mode,int nbAPPSelected)
{
    gestionFileMode[mode-1].definirParametre("appBoot",to_string(nbAPPSelected));
    return gestionFileMode[mode-1].sauvegarder(nameFileMode[mode-1]);
}

bool CArreraSetting::resetEmplacementApp(int app)
{
    if (chargementFileApp)
    {
        switch (app) {
        case 1:
            gestionFileApp.definirParametre("emplacementApp1","nothing");
            gestionFileApp.sauvegarder(nameFileApp);
            return true;
            break;
        case 2:
            gestionFileApp.definirParametre("emplacementApp2","nothing");
            gestionFileApp.sauvegarder(nameFileApp);
            return true;
            break;
        case 3:
            gestionFileApp.definirParametre("emplacementApp3","nothing");
            gestionFileApp.sauvegarder(nameFileApp);
            return true;
            break;
        case 4:
            gestionFileApp.definirParametre("emplacementApp4","nothing");
            gestionFileApp.sauvegarder(nameFileApp);
            return true;
            break;
        case 5:
            gestionFileApp.definirParametre("emplacementApp5","nothing");
            gestionFileApp.sauvegarder(nameFileApp);
            return true;
            break;
        case 6:
            gestionFileApp.definirParametre("emplacementApp6","nothing");
            gestionFileApp.sauvegarder(nameFileApp);
            return true;
            break;
        case 7:
            gestionFileApp.definirParametre("emplacementApp7","nothing");
            gestionFileApp.sauvegarder(nameFileApp);
            return true;
            break;
        case 8:
            gestionFileApp.definirParametre("emplacementApp8","nothing");
            gestionFileApp.sauvegarder(nameFileApp);
            return true;
            break;
        case 9:
            gestionFileApp.definirParametre("emplacementApp9","nothing");
            gestionFileApp.sauvegarder(nameFileApp);
            return true;
            break;
        case 10:
            gestionFileApp.definirParametre("emplacementApp10","nothing");
            gestionFileApp.sauvegarder(nameFileApp);
            return true;
            break;
        case 11:
            gestionFileApp.definirParametre("emplacementApp11","nothing");
            gestionFileApp.sauvegarder(nameFileApp);
            return true;
            break;
        case 12:
            gestionFileApp.definirParametre("emplacementApp12","nothing");
            gestionFileApp.sauvegarder(nameFileApp);
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

bool CArreraSetting::setModeEnable(int nbMode)
{
    if ((chargementMode[0])&&(chargementMode[1])&&(chargementMode[2])&&(chargementMode[3])&&(chargementMode[4]))
    {
        gestionFileMode[nbMode-1].definirParametre("modeSet","1");
        gestionFileMode[nbMode-1].sauvegarder(nameFileMode[nbMode-1]);
        chargedAllFile();
        return true;
    }
    else
    {
        return false;
    }
}

bool CArreraSetting::resetMode(int nbMode)
{
    bool sortie ;
    sortie = setNameMode(nbMode,"Mode");
    sortie = setAssistantMode(nbMode,false,false);
    sortie = setEtatTaskbar(nbMode,false);
    sortie = setModeAppAsBoot(nbMode,0);
    gestionFileMode[nbMode-1].definirParametre("modeSet","0");
    gestionFileMode[nbMode-1].definirParametre("btnTaskbar1","nothing");
    gestionFileMode[nbMode-1].definirParametre("btnTaskbar2","nothing");
    gestionFileMode[nbMode-1].definirParametre("btnTaskbar3","nothing");
    gestionFileMode[nbMode-1].definirParametre("btnTaskbar4","nothing");
    gestionFileMode[nbMode-1].definirParametre("btnTaskbar5","nothing");
    gestionFileMode[nbMode-1].sauvegarder(nameFileMode[nbMode-1]);
    loadSetting();
    return sortie;
}
