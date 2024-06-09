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
    bool chargedAllFile();
    void createFile();
public:
    CArreraSetting();
    string getNameUser();
    string getNameMode(int nb);
    string getSoftTableur();
    string getSoftPresentation();
    string getSoftNavigateur();
    string getSixEmplacement();
    string getRyleyEmplacement();
    string getAssistantMode(int nbMode);//0 : aucun / 1:six / 2:ryley
    string getEtatTaskbar(int nbMode);
    string getSoftTTexte();
    string getNameApp(int nb);
    string getEmplacementApp(int nb);
    string getArreraAppEmplacement(int nb);
    string getNbAppTaskbar(int nbButton,int mode);
    string getModeAppAsBoot(int mode);
    string getModeEnable(int mode);
    string getMTPUser();
    string getVMStart();
    string getScreenTouch();
    string getVMMode(int nb);
    string getTouchMode(int nb);

    bool resetAllPara();
    bool setNameMode(int nbMode,string valeur);
    bool setAssistantMode(int nbMode,bool ryley,bool six);
    bool setEtatTaskbar(int nbMode,bool enable);
    bool setEtatVM(int nbMode,bool enable);
    bool setEtatTouch(int nbMode,bool enable);
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
    bool resetMode(int nbMode);
    bool setMTPUser(string mtp);
    bool setParaSetteur();
    bool getParaSetteur();
    bool setVMStart();
    bool setScreenTouch();

};

#endif // CARRERASETTING_H
