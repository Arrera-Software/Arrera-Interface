#include "calieu.h"

CALieu::CALieu() {}

QString CALieu::getLieuGeographique()
{
    return objSetting->getValeur(name,"geo");
}


bool CALieu::setLieuGeographique(QString lieu){
    return objSetting->setValeur(name,"geo",lieu);
}
