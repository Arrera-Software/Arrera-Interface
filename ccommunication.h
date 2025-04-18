#ifndef CCOMMUNICATION_H
#define CCOMMUNICATION_H

#include "carreraserveur.h"
#include "carrerarecheche.h"
#include "arrerasettingui.h"

class CCommunication
{
private:
    CArreraServeur *app,*assistant;
    CArreraRecheche* precherche;
    CAInterfaceSetting* pSetting;
public:
    CCommunication();
    CCommunication(CArreraServeur* pserveur = nullptr,CArreraServeur* passistant = nullptr,
                   CArreraRecheche* objRecherche = nullptr,CAInterfaceSetting* objSetting = nullptr);
    // Partie App
    bool traitementApp(const QString &nameSoft,const QString message);
    bool sendDataApp(const QString &nameSoft, const QString &message);
    // Partie Assistant
    bool traitementAssistant(const QString &nameSoft,const QString message);
    bool sendDataAssistant(const QString &nameSoft, const QString &message);
};

#endif // CCOMMUNICATION_H
