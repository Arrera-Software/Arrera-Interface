#include "cainterfacesetting.h"

CAInterfaceSetting::CAInterfaceSetting() {}

CAInterfaceSetting::CAInterfaceSetting(QString& inifile,QString& jsonfile){
    fileINI = new CSetting(inifile);
    fileTiger = new CJSONWORD(jsonfile);
    // Instentation des mode
    mode1 = CAMode("mode1",fileINI);
    mode2 = CAMode("mode2",fileINI);
    mode3 = CAMode("mode3",fileINI);
    mode4 = CAMode("mode4",fileINI);
    mode5 = CAMode("mode5",fileINI);
    mode6 = CAMode("mode6",fileINI);
    // Instentation des lieu
    lieu1 = CALieu("lieu1",fileINI);
    lieu2 = CALieu("lieu2",fileINI);
    if(fileINI->getFileCreated()){
        fileINI->setValeur("arrera-recherche","moteur","nothing");
        fileINI->setValeur("interface","user","nothing");
    }
}

CAInterfaceSetting::~CAInterfaceSetting(){}

// Getteurs
QList <QString>  CAInterfaceSetting::getListAssistant(){
    return QList<QString>({"SIX", "RYLEY", "AUCUN"});
}

QList <QString>  CAInterfaceSetting::getListMoteur(){
    return QList<QString>({"GOOGLE", "DUCKDUCKGO", "ECOSIA" , "BING", "BRAVE","QWANT"});
}

QString CAInterfaceSetting::getNameUser(){
    return fileINI->getValeur("interface","user");
}

QString CAInterfaceSetting::getNameMode1(){
    return mode1.getNameView();
}

QString CAInterfaceSetting::getNameMode2(){
    return mode2.getNameView();
}

QString CAInterfaceSetting::getNameMode3(){
    return mode3.getNameView();
}

QString CAInterfaceSetting::getNameMode4(){
    return mode4.getNameView();
}

QString CAInterfaceSetting::getNameMode5(){
    return mode5.getNameView();
}

QString CAInterfaceSetting::getNameMode6(){
    return mode6.getNameView();
}

QString CAInterfaceSetting::getNameLieu1(){
    return lieu1.getNameView();
}

QString CAInterfaceSetting::getNameLieu2(){
    return lieu2.getNameView();
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

// getteur Icon Mode

QString CAInterfaceSetting::getIconMode1(){
    return mode1.getIcon();
}

QString CAInterfaceSetting::getIconMode2(){
    return mode2.getIcon();
}

QString CAInterfaceSetting::getIconMode3(){
    return mode3.getIcon();
}

QString CAInterfaceSetting::getIconMode4(){
    return mode4.getIcon();
}

QString CAInterfaceSetting::getIconMode5(){
    return mode5.getIcon();
}

QString CAInterfaceSetting::getIconMode6(){
    return mode6.getIcon();
}

// Getteur icon lieu
QString CAInterfaceSetting::getIconLieu1(){
    return lieu1.getIcon();
}

QString CAInterfaceSetting::getIconLieu2(){
    return lieu2.getIcon();
}

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

QString CAInterfaceSetting::getMoteurRecherche(){
    return fileINI->getValeur("arrera-recherche","moteur");
}

// Setteurs
bool CAInterfaceSetting::setNameUser(QString& user){
    return fileINI->setValeur("interface","user",user);
}

bool CAInterfaceSetting::setNameMode1(QString& name){
    return mode1.setNameView(name);
}

bool CAInterfaceSetting::setNameMode2(QString& name){
    return mode2.setNameView(name);
}

bool CAInterfaceSetting::setNameMode3(QString& name){
    return mode3.setNameView(name);
}

bool CAInterfaceSetting::setNameMode4(QString& name){
    return mode4.setNameView(name);
}
bool CAInterfaceSetting::setNameMode5(QString& name){
    return mode5.setNameView(name);
}

bool CAInterfaceSetting::setNameMode6(QString& name){
    return mode6.setNameView(name);
}

bool CAInterfaceSetting::setNameLieu1(QString& name){
    return lieu1.setNameView(name);
}

bool CAInterfaceSetting::setNameLieu2(QString& name){
    return lieu2.setNameView(name);
}

bool CAInterfaceSetting::setAssistantLieu1(QString& assistant){
    return lieu1.setAssistant(assistant);
}

bool CAInterfaceSetting::setAssistantLieu2(QString& assistant){
    return lieu2.setAssistant(assistant);
}

bool CAInterfaceSetting::setGeoLieu1(QString& geo){
    return lieu1.setLieuGeographique(geo);
}

bool CAInterfaceSetting::setGeoLieu2(QString& geo){
    return lieu2.setLieuGeographique(geo);
}

bool CAInterfaceSetting::setIconLieu1(QString& icon){
    return lieu1.setIcon(icon);
}

bool CAInterfaceSetting::setIconLieu2(QString& icon){
    return lieu2.setIcon(icon);
}

bool CAInterfaceSetting::setAppMode1(QString& nameApp1,QString& nameApp2,QString& nameApp3,QString& nameApp4){
    bool sortie1 = mode1.setApp1(nameApp1);
    bool sortie2 = mode1.setApp2(nameApp2);
    bool sortie3 = mode1.setApp3(nameApp3);
    bool sortie4 = mode1.setApp4(nameApp4);
    if (sortie1 && sortie2 && sortie3 && sortie4){
        return true;
    }
    else{
        return false;
    }
}

bool CAInterfaceSetting::setAppMode2(QString& nameApp1,QString& nameApp2,QString& nameApp3,QString& nameApp4){
    bool sortie1 = mode2.setApp1(nameApp1);
    bool sortie2 = mode2.setApp2(nameApp2);
    bool sortie3 = mode2.setApp3(nameApp3);
    bool sortie4 = mode2.setApp4(nameApp4);
    if (sortie1 && sortie2 && sortie3 && sortie4){
        return true;
    }
    else{
        return false;
    }
}

bool CAInterfaceSetting::setAppMode3(QString& nameApp1,QString& nameApp2,QString& nameApp3,QString& nameApp4){
    bool sortie1 = mode3.setApp1(nameApp1);
    bool sortie2 = mode3.setApp2(nameApp2);
    bool sortie3 = mode3.setApp3(nameApp3);
    bool sortie4 = mode3.setApp4(nameApp4);
    if (sortie1 && sortie2 && sortie3 && sortie4){
        return true;
    }
    else{
        return false;
    }
}

bool CAInterfaceSetting::setAppMode4(QString& nameApp1,QString& nameApp2,QString& nameApp3,QString& nameApp4){
    bool sortie1 = mode4.setApp1(nameApp1);
    bool sortie2 = mode4.setApp2(nameApp2);
    bool sortie3 = mode4.setApp3(nameApp3);
    bool sortie4 = mode6.setApp4(nameApp4);
    if (sortie1 && sortie2 && sortie3 && sortie4){
        return true;
    }
    else{
        return false;
    }
}

bool CAInterfaceSetting::setAppMode5(QString& nameApp1,QString& nameApp2,QString& nameApp3,QString& nameApp4){
    bool sortie1 = mode5.setApp1(nameApp1);
    bool sortie2 = mode5.setApp2(nameApp2);
    bool sortie3 = mode5.setApp3(nameApp3);
    bool sortie4 = mode5.setApp4(nameApp4);
    if (sortie1 && sortie2 && sortie3 && sortie4){
        return true;
    }
    else{
        return false;
    }
}

bool CAInterfaceSetting::setAppMode6(QString& nameApp1,QString& nameApp2,QString& nameApp3,QString& nameApp4){
    bool sortie1 = mode6.setApp1(nameApp1);
    bool sortie2 = mode6.setApp2(nameApp2);
    bool sortie3 = mode6.setApp3(nameApp3);
    bool sortie4 = mode6.setApp4(nameApp4);
    if (sortie1 && sortie2 && sortie3 && sortie4){
        return true;
    }
    else{
        return false;
    }
}

bool CAInterfaceSetting::setAssistantMode1(QString& assistant){
    return mode1.setAssistant(assistant);
}
bool CAInterfaceSetting::setAssistantMode2(QString& assistant){
    return mode2.setAssistant(assistant);
}
bool CAInterfaceSetting::setAssistantMode3(QString& assistant){
    return mode3.setAssistant(assistant);
}
bool CAInterfaceSetting::setAssistantMode4(QString& assistant){
    return mode4.setAssistant(assistant);
}
bool CAInterfaceSetting::setAssistantMode5(QString& assistant){
    return mode5.setAssistant(assistant);
}
bool CAInterfaceSetting::setAssistantMode6(QString& assistant){
    return mode6.setAssistant(assistant);
}

// Setteur icon mode

bool CAInterfaceSetting::setIconMode1(QString icon){
    return mode1.setIcon(icon);
}

bool CAInterfaceSetting::setIconMode2(QString icon){
    return mode2.setIcon(icon);
}

bool CAInterfaceSetting::setIconMode3(QString icon){
    return mode3.setIcon(icon);
}

bool CAInterfaceSetting::setIconMode4(QString icon){
    return mode4.setIcon(icon);
}

bool CAInterfaceSetting::setIconMode5(QString icon){
    return mode5.setIcon(icon);
}

bool CAInterfaceSetting::setIconMode6(QString icon){
    return mode6.setIcon(icon);
}

bool CAInterfaceSetting::setApplication(int nb,QString nameApp,QString emplacement){}
bool CAInterfaceSetting::setAppTableur(QString emplacement){}
bool CAInterfaceSetting::setAppTraitementTexte(QString emplacement){}
bool CAInterfaceSetting::setAppPresentation(QString emplacement){}
bool CAInterfaceSetting::setAppNavigateur(QString emplacement){}

bool CAInterfaceSetting::setMoteurRecherche(QString moteur){
    return fileINI->setValeur("arrera-recherche","moteur",moteur);
}
// Methode pour savoir si les lieu ou mode son paramétrer

bool CAInterfaceSetting::mode1IsSeted(){
    return mode1.isSeted();
}

bool CAInterfaceSetting::mode2IsSeted(){
    return mode2.isSeted();
}

bool CAInterfaceSetting::mode3IsSeted(){
    return mode3.isSeted();
}

bool CAInterfaceSetting::mode4IsSeted(){
    return mode4.isSeted();
}

bool CAInterfaceSetting::mode5IsSeted(){
    return mode5.isSeted();
}

bool CAInterfaceSetting::mode6IsSeted(){
    return mode6.isSeted();
}

bool CAInterfaceSetting::lieu1IsSeted(){
    return lieu1.isSeted();
}

bool CAInterfaceSetting::lieu2IsSeted(){
    return lieu2.isSeted();
}

// Methode pour savoir si une icon est parametrer pour le mode

bool CAInterfaceSetting::iconMode1IsSetted(){
    if (getIconMode1()=="nothing"){
        return false;
    }else{
        return true;}
}

bool CAInterfaceSetting::iconMode2IsSetted(){
    if (getIconMode2()=="nothing"){
        return false;
    }else{
        return true;}
}

bool CAInterfaceSetting::iconMode3IsSetted(){
    if (getIconMode3()=="nothing"){
        return false;
    }else{
        return true;}
}

bool CAInterfaceSetting::iconMode4IsSetted(){
    if (getIconMode4()=="nothing"){
        return false;
    }else{
        return true;}
}

bool CAInterfaceSetting::iconMode5IsSetted(){
    if (getIconMode5()=="nothing"){
        return false;
    }else{
        return true;}
}

bool CAInterfaceSetting::iconMode6IsSetted(){
    if (getIconMode6()=="nothing"){
        return false;
    }else{
        return true;}
}

bool CAInterfaceSetting::iconLieu1IsSetted(){
    if (getIconLieu1()=="nothing"){
        return false;
    }else{
        return true;}
}

bool CAInterfaceSetting::iconLieu2IsSetted(){
    if (getIconLieu2()=="nothing"){
        return false;
    }else{
        return true;}
}

// Methode pour remettre a Zero les modes et lieu
bool CAInterfaceSetting::resetMode1(){
    return mode1.resetMode();
}

bool CAInterfaceSetting::resetMode2(){
    return mode2.resetMode();
}

bool CAInterfaceSetting::resetMode3(){
    return mode3.resetMode();
}

bool CAInterfaceSetting::resetMode4(){
    return mode4.resetMode();
}

bool CAInterfaceSetting::resetMode5(){
    return mode5.resetMode();
}

bool CAInterfaceSetting::resetMode6(){
    return mode6.resetMode();
}

bool CAInterfaceSetting::resetLieu1(){
    return lieu1.resetLieu();
}

bool CAInterfaceSetting::resetLieu2(){
    return lieu2.resetLieu();
}
