#include "camodelieu.h"

CAModeLieu::CAModeLieu() {}

CAModeLieu::CAModeLieu(QString pname,CSetting *psetting){
    objSetting = psetting;
    name = pname;
}

CAModeLieu::~CAModeLieu(){}

QString CAModeLieu::getNameView(){
    return objSetting->getValeur(name,"name");
}

QString CAModeLieu::getAssistant(){
    return objSetting->getValeur(name,"assistant");
}

bool CAModeLieu::setNameView(QString pname){
    return objSetting->setValeur(name,"name",pname);
}

bool CAModeLieu::setAssistant(QString assistant){
    return objSetting->setValeur(name,"assistant",assistant);
}
