#include "ccommunication.h"
#include <iostream>

CCommunication::CCommunication() {}

CCommunication::CCommunication(CArreraServeur* pserveur){
    serveur = pserveur;
}

bool CCommunication::traitement(const QString &nameSoft,const QString message)
{
    std::cout << nameSoft.toStdString()<< " " << message.toStdString() << std::endl;
    return true;
}

bool CCommunication::sendData(const QString &nameSoft, const QString &message){
    return serveur->sendMessage(nameSoft,message);

}

QList <QString> CCommunication::listSoft(){

}
