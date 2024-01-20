#ifndef CARRERASETTING_H
#define CARRERASETTING_H
#include "cconfiguration.h"
#include <string.h>
#include "cos.h"

using namespace std ;

class CArreraSetting
{
private :
    Cconfiguration gestionFile,gestionFileMode[5],gestionFileApp;
    COS systeme;
    bool etatChargement, chargementMode[5],linuxOS,windowsOS,chargementFileApp;
    string nameFile,nameFileMode[5],nameFileApp;
    string nameMode1,nameMode2,nameMode3,nameMode4,nameMode5;
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
    string getSoftTTexte();
    string getNameApp(int nb);
    string getEmplacementApp(int nb);
    string getArreraAppEmplacement(int nb);

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

};

#endif // CARRERASETTING_H
