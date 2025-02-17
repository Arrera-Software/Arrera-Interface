#include "camode.h"

CAMode::CAMode() {}

CAMode::CAMode(QString pname,CSetting *psetting) : CAModeLieu(pname,psetting) {
    if (objSetting->getFileCreated()){
        objSetting->setValeur(name,"app1","nothing");
        objSetting->setValeur(name,"app2","nothing");
        objSetting->setValeur(name,"app3","nothing");
        objSetting->setValeur(name,"app4","nothing");
    }
}

QString CAMode::getApp1(){
    return objSetting->getValeur(name,"app1");
}

QString CAMode::getApp2(){
    return objSetting->getValeur(name,"app2");
}

QString CAMode::getApp3(){
    return objSetting->getValeur(name,"app3");
}

QString CAMode::getApp4(){
    return objSetting->getValeur(name,"app4");
}

bool CAMode::setApp1(QString app){
    return objSetting->setValeur(name,"app1",app);
}

bool CAMode::setApp2(QString app){
    return objSetting->setValeur(name,"app2",app);
}

bool CAMode::setApp3(QString app){
    return objSetting->setValeur(name,"app3",app);
}

bool CAMode::setApp4(QString app){
    return objSetting->setValeur(name,"app4",app);
}

bool CAMode::resetMode(){
    bool sname = objSetting->setValeur(name,"name","nothing");
    bool sapp1 = objSetting->setValeur(name,"app1","nothing");
    bool sapp2 = objSetting->setValeur(name,"app2","nothing");
    bool sapp3 = objSetting->setValeur(name,"app3","nothing");
    bool sapp4 = objSetting->setValeur(name,"app4","nothing");
    bool sassistant = objSetting->setValeur(name,"assistant","nothing");
    bool sicon = objSetting->setValeur(name,"icon","nothing");
    if (sname && sapp1 && sapp2 && sapp3 && sapp4 && sassistant && sicon){
        return true;
    }else{
        return false;
    }
}
