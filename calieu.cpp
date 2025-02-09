#include "calieu.h"

CALieu::CALieu() {}

CALieu::CALieu(QString pname,CSetting *psetting) : CAModeLieu(pname,psetting){}

QString CALieu::getLieuGeographique()
{
    return objSetting->getValeur(name,"geo");
}


bool CALieu::setLieuGeographique(QString lieu){
    return objSetting->setValeur(name,"geo",lieu);
}
