#include "camode.h"

CAMode::CAMode() {}

CAMode::CAMode(QString pname,CSetting *psetting) : CAModeLieu(pname,psetting) {}

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
