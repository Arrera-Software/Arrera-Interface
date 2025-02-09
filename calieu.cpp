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
