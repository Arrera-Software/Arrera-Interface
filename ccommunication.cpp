#include "ccommunication.h"

CCommunication::CCommunication() {}

CCommunication::CCommunication(CArreraServeur* pserveur){
    serveur = pserveur;
}

bool CCommunication::traitement(){}

bool CCommunication::sendData(QString soft,QString data){}

QList <QString> CCommunication::listSoft(){}
