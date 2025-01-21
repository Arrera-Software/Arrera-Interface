#include "cainterfacesetting.h"

CAInterfaceSetting::CAInterfaceSetting() {}

CAInterfaceSetting::CAInterfaceSetting(QString& inifile,QString& jsonfile){
    fileINI = new CSetting(inifile);
    fileTiger = new CJSONWORD(jsonfile);
}

CAInterfaceSetting::~CAInterfaceSetting(){}

// Getteurs
QString CAInterfaceSetting::getNameUser(){
    return fileINI->getValeur("interface","user");
}

QString CAInterfaceSetting::getNameMode1(){
    return fileINI->getValeur("mode1","name");
}

QString CAInterfaceSetting::getNameMode2(){
    return fileINI->getValeur("mode2","name");
}

QString CAInterfaceSetting::getNameMode3(){
    return fileINI->getValeur("mode3","name");
}

QString CAInterfaceSetting::getNameMode4(){
    return fileINI->getValeur("mode4","name");
}

QString CAInterfaceSetting::getNameMode5(){
    return fileINI->getValeur("mode5","name");
}

QString CAInterfaceSetting::getNameMode6(){
    return fileINI->getValeur("mode6","name");
}

// Getteurs App mode

bool CAInterfaceSetting::getAppMode1(QString* nameApp1, QString* nameApp2, QString* nameApp3, QString* nameApp4){}
bool CAInterfaceSetting::getAppMode2(QString* nameApp1, QString* nameApp2, QString* nameApp3, QString* nameApp4){}
bool CAInterfaceSetting::getAppMode3(QString* nameApp1, QString* nameApp2, QString* nameApp3, QString* nameApp4){}
bool CAInterfaceSetting::getAppMode4(QString* nameApp1, QString* nameApp2, QString* nameApp3, QString* nameApp4){}
bool CAInterfaceSetting::getAppMode5(QString* nameApp1, QString* nameApp2, QString* nameApp3, QString* nameApp4){}
bool CAInterfaceSetting::getAppMode6(QString* nameApp1, QString* nameApp2, QString* nameApp3, QString* nameApp4){}

// getteur Assistant App

QString CAInterfaceSetting::getAssistantMode1(){}
QString CAInterfaceSetting::getAssistantMode2(){}
QString CAInterfaceSetting::getAssistantMode3(){}
QString CAInterfaceSetting::getAssistantMode4(){}
QString CAInterfaceSetting::getAssistantMode5(){}
QString CAInterfaceSetting::getAssistantMode6(){}

// Getteur application

QString CAInterfaceSetting::getApplication(int nb){}
QString CAInterfaceSetting::getAppTableur(){}
QString CAInterfaceSetting::getAppTraitementTexte(){}
QString CAInterfaceSetting::getAppPresentation(){}
QString CAInterfaceSetting::getAppNavigateur(){}

// Getteur application Arrera

QString CAInterfaceSetting::getArreraRyley(){}
QString CAInterfaceSetting::getArreraSix(){}
QString CAInterfaceSetting::getArreraCopilote(){}
QString CAInterfaceSetting::getArreraPostite(){}
QString CAInterfaceSetting::getArreraVideoDownload(){}
QString CAInterfaceSetting::getArreraRaccourci(){}

// Setteurs
bool CAInterfaceSetting::setNameUser(QString& user){}
bool CAInterfaceSetting::setNameMode1(QString& name){}
bool CAInterfaceSetting::setNameMode2(QString& name){}
bool CAInterfaceSetting::setNameMode3(QString& name){}
bool CAInterfaceSetting::setNameMode4(QString& name){}
bool CAInterfaceSetting::setNameMode5(QString& name){}
bool CAInterfaceSetting::setNameMode6(QString& name){}

bool CAInterfaceSetting::setAppMode1(QString& nameApp1,QString& nameApp2,QString& nameApp3,QString& nameApp4){}
bool CAInterfaceSetting::setAppMode2(QString& nameApp1,QString& nameApp2,QString& nameApp3,QString& nameApp4){}
bool CAInterfaceSetting::setAppMode3(QString& nameApp1,QString& nameApp2,QString& nameApp3,QString& nameApp4){}
bool CAInterfaceSetting::setAppMode4(QString& nameApp1,QString& nameApp2,QString& nameApp3,QString& nameApp4){}
bool CAInterfaceSetting::setAppMode5(QString& nameApp1,QString& nameApp2,QString& nameApp3,QString& nameApp4){}
bool CAInterfaceSetting::setAppMode6(QString& nameApp1,QString& nameApp2,QString& nameApp3,QString& nameApp4){}

bool CAInterfaceSetting::setAssistantMode1(QString& assistant){}
bool CAInterfaceSetting::setAssistantMode2(QString& assistant){}
bool CAInterfaceSetting::setAssistantMode3(QString& assistant){}
bool CAInterfaceSetting::setAssistantMode4(QString& assistant){}
bool CAInterfaceSetting::setAssistantMode5(QString& assistant){}
bool CAInterfaceSetting::setAssistantMode6(QString& assistant){}

bool CAInterfaceSetting::setApplication(int nb,QString nameApp,QString emplacement){}
bool CAInterfaceSetting::setAppTableur(QString emplacement){}
bool CAInterfaceSetting::setAppTraitementTexte(QString emplacement){}
bool CAInterfaceSetting::setAppPresentation(QString emplacement){}
bool CAInterfaceSetting::setAppNavigateur(QString emplacement){}
