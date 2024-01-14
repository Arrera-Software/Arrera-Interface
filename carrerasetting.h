#ifndef CARRERASETTING_H
#define CARRERASETTING_H
#include "cconfiguration.h"
#include <string.h>

using namespace std ;

class CArreraSetting
{
private :
    Cconfiguration gestionFile;
    Cconfiguration gestionFileMode[5];
    bool etatChargement, chargementMode[5];
    string nameFile;
    string nameFileMode[5];
    string nameMode1,nameMode2,nameMode3,nameMode4,nameMode5;
public:
    CArreraSetting();

    bool loadSetting();

    string getNameMode1();
    string getNameMode2();
    string getNameMode3();
    string getNameMode4();
    string getNameMode5();

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
