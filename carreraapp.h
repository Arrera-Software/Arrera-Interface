#ifndef CARRERAAPP_H
#define CARRERAAPP_H
#include "cainterfacesetting.h"

class CArreraApp
{
private :
    CJSONWORD jsonFile;
    CAInterfaceSetting* psetting;
    bool tigerFileSetted;
    QString tigerFile;
    bool exectute(QString app,bool appSetted);
public:
    CArreraApp();
    CArreraApp(CAInterfaceSetting* p);
    bool setEmplacementTiger();
    bool openStore();
};

#endif // CARRERAAPP_H
