#ifndef CARRERASETTING_H
#define CARRERASETTING_H
#include "cconfiguration.h"
#include <string.h>

using namespace std ;

class CArreraSetting
{
private :
    Cconfiguration gestionFile ;
    bool etatChargement ;
    string nameFile;
    string nameMode1;
    string nameMode2;
    string nameMode3;
    string nameMode4;
    string nameMode5;
public:
    CArreraSetting();

    bool loadSetting();

    string getNameMode1();
    string getNameMode2();
    string getNameMode3();
    string getNameMode4();
    string getNameMode5();

    bool setNameMode1(string valeur);
    bool setNameMode2(string valeur);
    bool setNameMode3(string valeur);
    bool setNameMode4(string valeur);
    bool setNameMode5(string valeur);


};

#endif // CARRERASETTING_H
