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
    bool traitement(const QString &nameSoft,const QString message);
    bool sendData(const QString &nameSoft, const QString &message);
    bool setSoftConnected(QString &nameSoft);
    bool setSoftDeconnected(QString &soft);
    void clientConnected();
    QList <QString> listSoft();
};

#endif // CCOMMUNICATION_H
