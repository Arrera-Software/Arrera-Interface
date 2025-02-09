#include "calieu.h"

CALieu::CALieu() {}

CALieu::CALieu(QString pname,CSetting *psetting) : CAModeLieu(pname,psetting){
    if (objSetting->getFileCreated()){
        objSetting->setValeur(name,"geo","nothing");
    }
}

QString CALieu::getLieuGeographique()
{
    return objSetting->getValeur(name,"geo");
}


bool CALieu::setLieuGeographique(QString lieu){
    return objSetting->setValeur(name,"geo",lieu);
}

bool CALieu::resetLieu(){
    bool sname = objSetting->setValeur(name,"name","nothing");
    bool sgeo = objSetting->setValeur(name,"geo","nothing");
    bool sassistant = objSetting->setValeur(name,"assistant","nothing");
    if (sname && sgeo && sassistant){
        return true;
    }else{
        return false;
    }
}
