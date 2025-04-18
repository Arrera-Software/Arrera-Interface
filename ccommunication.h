#ifndef CCOMMUNICATION_H
#define CCOMMUNICATION_H

#include "carreraserveur.h"

class CCommunication
{
private:
    CArreraServeur *app,*assistant;
    Ui_ArreraUI* gui;
public:
    CCommunication();
    CCommunication(CArreraServeur* pserveur= nullptr,CArreraServeur* passistant = nullptr);
    // Partie App
    bool traitementApp(const QString &nameSoft,const QString message);
    bool sendDataApp(const QString &nameSoft, const QString &message);
    // Partie Assistant
    bool traitementAssistant(const QString &nameSoft,const QString message);
    bool sendDataAssistant(const QString &nameSoft, const QString &message);
};

#endif // CCOMMUNICATION_H
