#include "ccommunication.h"
#include <iostream>
using namespace std;

CCommunication::CCommunication() {}

CCommunication::CCommunication(CArreraServeur* pserveur,CArreraServeur* passistant){
    app = pserveur;
    assistant = passistant;
}

bool CCommunication::traitementApp(const QString &nameSoft,const QString message)
{
    std::cout << nameSoft.toStdString()<< " " << message.toStdString() << std::endl;
    return true;
}

bool CCommunication::sendDataApp(const QString &nameSoft, const QString &message){
    return app->sendMessage(nameSoft,message);

}

bool CCommunication::traitementAssistant(const QString &nameSoft,const QString message){
    std::cout << nameSoft.toStdString()<< " " << message.toStdString() << std::endl;
    return true;
}

bool CCommunication::sendDataAssistant(const QString &nameSoft, const QString &message){
    return assistant->sendMessage(nameSoft,message);
}
