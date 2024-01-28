#ifndef CARRERASETTING_H
#define CARRERASETTING_H
#include "cconfiguration.h"
#include "cos.h"

using namespace std ;

class CArreraSetting
{
private :
    Cconfiguration gestionFile,gestionFileMode[5],gestionFileApp;
    Cconfiguration gestionFileTaskbar[6];
    COS systeme;
    bool etatChargement, chargementMode[5],linuxOS,windowsOS,chargementFileApp;
    bool etatFileTaskbar[6];
    string nameFile,nameFileMode[5],nameFileApp , nameFileTaskbarMode[6];
    string nameMode1,nameMode2,nameMode3,nameMode4,nameMode5;
    void chargedAllFile();
public:
    CArreraSetting();

    bool loadSetting();


    string getNameUser();
    string getNameMode1();
    string getNameMode2();
    string getNameMode3();
    string getNameMode4();
    string getNameMode5();
    string getSoftTableur();
    string getSoftPresentation();
    string getSoftNavigateur();
    string getSixEmplacement();
    string getRyleyEmplacement();
    int getAssistantMode(int nbMode);//0 : aucun / 1:six / 2:ryley
    string getEtatTaskbar(int nbMode);
    string getSoftTTexte();
    string getNameApp(int nb);
    string getEmplacementApp(int nb);
    string getArreraAppEmplacement(int nb);
    string getNbAppTaskbar(int nbButton,int mode);
    string getModeAppAsBoot(int mode);
    string getModeEnable(int mode);

    bool resetAllPara();
    bool setNameMode(int nbMode,string valeur);
    bool setAssistantMode(int nbMode,bool ryley,bool six);
    bool setEtatTaskbar(int nbMode,bool enable);
    bool setSoftTableur();
    bool setSoftTTexte();
    bool setSoftPresentation();
    bool setSoftNavigateur();
    bool setSixEmplacement();
    bool setRyleyEmplacement();
    bool setNameUser(string name);
    bool setNameApp(int nb,string name);
    bool setEmplacementApp(int nb);
    bool setArreraAppEmplacement(int nb);
    bool setAppTaskBar(int nbAppTaskbar,int nbAppSelected,int mode);
    bool setModeAppAsBoot(int mode,int nbAPPSelected);
    bool resetEmplacementApp(int app);
    bool setModeEnable(int nbMode);

};

#endif // CARRERASETTING_H
