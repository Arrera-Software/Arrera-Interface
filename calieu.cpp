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
    bool sicon = objSetting->setValeur(name,"icon","nothing");
    if (sname && sgeo && sassistant && sicon){
        return true;
    }else{
        return false;
    }
}

bool CALieu::launchLieu(QPushButton* btnSix ,QPushButton* btnCopilote,QPushButton* btnRyley){
    QString a = getAssistant();
    btnSix->setVisible(false);
    btnCopilote->setVisible(false);
    btnRyley->setVisible(false);
    if (a=="SIX"){
        btnSix->setVisible(true);
        return true;
    }else if(a=="RYLEY"){
        btnCopilote->setVisible(true);
        return true;
    }else if (a=="COPILOTE"){
        btnRyley->setVisible(true);
        return true;
    }else{
        return false;
    }
}

bool CALieu::disableLieu(){
    // btnSix->setVisible(true);
    // btnCopilote->setVisible(true);
    // btnRyley->setVisible(true);
    return false;
}
