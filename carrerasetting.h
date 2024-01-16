#ifndef CARRERASETTING_H
#define CARRERASETTING_H
#include "cconfiguration.h"
#include <string.h>
#include "cos.h"

using namespace std ;

class CArreraSetting
{
private :
    Cconfiguration gestionFile;
    Cconfiguration gestionFileMode[5];
    COS systeme;
    bool etatChargement, chargementMode[5],linuxOS,windowsOS;
    string nameFile;
    string nameFileMode[5];
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


};

#endif // CARRERASETTING_H
