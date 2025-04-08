#ifndef CCOMMUNICATION_H
#define CCOMMUNICATION_H

#include "carreraserveur.h"

class CCommunication
{
private:
    CArreraServeur *serveur;
public:
    CCommunication();
    CCommunication(CArreraServeur* pserveur = nullptr);
    bool traitement();
    bool sendData(QString soft,QString data);
    QList <QString> listSoft();
};

#endif // CCOMMUNICATION_H
