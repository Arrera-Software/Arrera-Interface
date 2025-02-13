#include "camodelieu.h"

CAModeLieu::CAModeLieu() {}

CAModeLieu::CAModeLieu(QString pname,CSetting *psetting){
    objSetting = psetting;
    name = pname;
    if (objSetting->getFileCreated()){
        objSetting->setValeur(name,"name","nothing");
        objSetting->setValeur(name,"assistant","nothing");
        objSetting->setValeur(name,"icon","nothing");
    }
}

CAModeLieu::~CAModeLieu(){}

QString CAModeLieu::getNameView(){
    return objSetting->getValeur(name,"name");
}

QString CAModeLieu::getAssistant(){
    return objSetting->getValeur(name,"assistant");
}

QString CAModeLieu::getIcon(){
    return objSetting->getValeur(name,"icon");
}

bool CAModeLieu::setNameView(QString pname){
    return objSetting->setValeur(name,"name",pname);
}

bool CAModeLieu::setAssistant(QString assistant){
    return objSetting->setValeur(name,"assistant",assistant);
}

bool CAModeLieu::isSeted(){
    if (getNameView() == "nothing"){
        return false;
    }else{
        return true;
    }
}

bool CAModeLieu::setIcon(QString icon){
    return objSetting->setValeur(name,"icon",icon);
}
