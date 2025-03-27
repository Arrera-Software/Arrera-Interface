#include "cainterfacesetting.h"

CAInterfaceSetting::CAInterfaceSetting() {}

CAInterfaceSetting::CAInterfaceSetting(QString& inifile,QPushButton *bSix,QPushButton *bRyley,QPushButton *bCopilote){
    // Var
    fileINI = new CSetting(inifile);
    // Instentation des mode
    mode1 = CAMode("mode1",fileINI);
    mode2 = CAMode("mode2",fileINI);
    mode3 = CAMode("mode3",fileINI);
    mode4 = CAMode("mode4",fileINI);
    mode5 = CAMode("mode5",fileINI);
    mode6 = CAMode("mode6",fileINI);
    // Instentation des lieu
    lieu1 = CALieu("lieu1",fileINI,bSix,bRyley,bCopilote);
    lieu2 = CALieu("lieu2",fileINI,bSix,bRyley,bCopilote);
    if(fileINI->getFileCreated()){
        resetAll();
    }
}

CAInterfaceSetting::~CAInterfaceSetting(){}

// Getteurs
QList <QString>  CAInterfaceSetting::getListAssistant(){
    return QList<QString>({"SIX", "RYLEY","COPILOTE", "AUCUN"});
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

QString CAInterfaceSetting::getAssistantMode1(){
    return mode1.getAssistant();
}

QString CAInterfaceSetting::getAssistantMode2(){
    return mode2.getAssistant();
}

QString CAInterfaceSetting::getAssistantMode3(){
    return mode3.getAssistant();
}

QString CAInterfaceSetting::getAssistantMode4(){
    return mode4.getAssistant();
}

QString CAInterfaceSetting::getAssistantMode5(){
    return mode5.getAssistant();
}

QString CAInterfaceSetting::getAssistantMode6(){
    return mode6.getAssistant();
}


QString CAInterfaceSetting::getNameLieu1(){
    return lieu1.getNameView();
}

QString CAInterfaceSetting::getNameLieu2(){
    return lieu2.getNameView();
}

bool CAInterfaceSetting::getAppMode1(QString* app1,QString* app2,QString* app3,QString* app4){
    QString appOn = mode1.getApp1();
    QString appTwo = mode1.getApp2();
    QString appTheed = mode1.getApp3();
    QString appFoor = mode1.getApp4();

    if (app1 != nullptr) {
        *app1 = appOn;  // Affecte la valeur à l'adresse pointée par app1
    }else{
        return false;
    }

    if (app2 != nullptr) {
        *app2 = appTwo;
    }else{
        return false;
    }

    if (app3 != nullptr) {
        *app3 = appTheed;
    }else{
        return false;
    }

    if (app4 != nullptr) {
        *app4 = appFoor;
    }else{
        return false;
    }

    return true;
}

bool CAInterfaceSetting::getAppMode2(QString* app1,QString* app2,QString* app3,QString* app4){
    QString appOn = mode2.getApp1();
    QString appTwo = mode2.getApp2();
    QString appTheed = mode2.getApp3();
    QString appFoor = mode2.getApp4();
    if (app1 != nullptr) {
        *app1 = appOn;  // Affecte la valeur à l'adresse pointée par app1
    }else{
        return false;
    }

    if (app2 != nullptr) {
        *app2 = appTwo;
    }else{
        return false;
    }

    if (app3 != nullptr) {
        *app3 = appTheed;
    }else{
        return false;
    }

    if (app4 != nullptr) {
        *app4 = appFoor;
    }else{
        return false;
    }

    return true;
}

bool CAInterfaceSetting::getAppMode3(QString* app1,QString* app2,QString* app3,QString* app4){
    QString appOn = mode3.getApp1();
    QString appTwo = mode3.getApp2();
    QString appTheed = mode3.getApp3();
    QString appFoor = mode3.getApp4();
    if (app1 != nullptr) {
        *app1 = appOn;  // Affecte la valeur à l'adresse pointée par app1
    }else{
        return false;
    }

    if (app2 != nullptr) {
        *app2 = appTwo;
    }else{
        return false;
    }

    if (app3 != nullptr) {
        *app3 = appTheed;
    }else{
        return false;
    }

    if (app4 != nullptr) {
        *app4 = appFoor;
    }else{
        return false;
    }

    return true;
}

bool CAInterfaceSetting::getAppMode4(QString* app1,QString* app2,QString* app3,QString* app4){
    QString appOn = mode4.getApp1();
    QString appTwo = mode4.getApp2();
    QString appTheed = mode4.getApp3();
    QString appFoor = mode4.getApp4();
    if (app1 != nullptr) {
        *app1 = appOn;  // Affecte la valeur à l'adresse pointée par app1
    }else{
        return false;
    }

    if (app2 != nullptr) {
        *app2 = appTwo;
    }else{
        return false;
    }

    if (app3 != nullptr) {
        *app3 = appTheed;
    }else{
        return false;
    }

    if (app4 != nullptr) {
        *app4 = appFoor;
    }else{
        return false;
    }

    return true;
}

bool CAInterfaceSetting::getAppMode5(QString* app1,QString* app2,QString* app3,QString* app4){
    QString appOn = mode5.getApp1();
    QString appTwo = mode5.getApp2();
    QString appTheed = mode5.getApp3();
    QString appFoor = mode5.getApp4();
    if (app1 != nullptr) {
        *app1 = appOn;  // Affecte la valeur à l'adresse pointée par app1
    }else{
        return false;
    }

    if (app2 != nullptr) {
        *app2 = appTwo;
    }else{
        return false;
    }

    if (app3 != nullptr) {
        *app3 = appTheed;
    }else{
        return false;
    }

    if (app4 != nullptr) {
        *app4 = appFoor;
    }else{
        return false;
    }

    return true;
}

bool CAInterfaceSetting::getAppMode6(QString* app1,QString* app2,QString* app3,QString* app4){
    QString appOn = mode6.getApp1();
    QString appTwo = mode6.getApp2();
    QString appTheed = mode6.getApp3();
    QString appFoor = mode6.getApp4();
    if (app1 != nullptr) {
        *app1 = appOn;  // Affecte la valeur à l'adresse pointée par app1
    }else{
        return false;
    }

    if (app2 != nullptr) {
        *app2 = appTwo;
    }else{
        return false;
    }

    if (app3 != nullptr) {
        *app3 = appTheed;
    }else{
        return false;
    }

    if (app4 != nullptr) {
        *app4 = appFoor;
    }else{
        return false;
    }

    return true;
}

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

int CAInterfaceSetting::getFirstUnsetNumber(){
    for (int i = 1 ; i <= 21 ; i++){
        if(fileINI->getValeur("app"+QString::number(i),"name")=="nothing"){
            return i;
        }
    }
    return 0;
}

int CAInterfaceSetting::getnbAppSetted(){
    int nbApp=0;
    for(int i = 1;i<=20;i++){
        if(fileINI->getValeur("app"+QString::number(i),"name")!="nothing"){
            nbApp++;
        }
    }
    return nbApp;
}

bool CAInterfaceSetting::getAppSetted(int nbApp){
    QString nameApp = fileINI->getValeur("app"+QString::number(nbApp),"name");
    if (nameApp=="nothing"){
        return false;
    }else{
        return true;
    }
}

QList <QString> CAInterfaceSetting::getListNameAppSetted(){
    QList <QString> listOut;
    listOut = QList<QString>();
    for (int i = 1;i<=20;i++){
        if (getAppSetted(i)){
            listOut.append(fileINI->getValeur("app"+QString::number(i),"name"));
        }
    }
    return listOut;
}

QString CAInterfaceSetting::assosNameOfApp(QString app){
    QString y ;
    for (int i = 1;i<=20;i++){
        if (getAppSetted(i)){
            y = fileINI->getValeur("app"+QString::number(i),"name");
            if (y==app){
                return "app"+QString::number(i);
            }
        }
    }
    return "error";
}

bool CAInterfaceSetting::checkNameAppIsAvailable(QString name){
    for (int i = 1;i<=20;i++){
        if (fileINI->getValeur("app"+QString::number(i),"name")==name){
            return false;
        }
    }
    return true;
}

int CAInterfaceSetting::getNbAppWithName(QString name){
    for (int i = 1;i<=20;i++){
        if (fileINI->getValeur("app"+QString::number(i),"name")==name){
            return i;
        }
    }
    return -1;
}

bool CAInterfaceSetting::getApplication(int nb,QString *name,QString *exe,QString *icon){
    if (nb >= 1 && nb <= 20) {
        *name = fileINI->getValeur("app"+QString::number(nb),"name");
        *exe = fileINI->getValeur("app"+QString::number(nb),"exe");
        *icon = fileINI->getValeur("app"+QString::number(nb),"icon");
        return true;
    } else {
        return false;
    }
}

QString CAInterfaceSetting::getAppSpeciaux(int app){
    switch (app) {
    case 1: // 1.Navigateur
        return fileINI->getValeur("navigateur","exe");
        break;
    case 2: // 2.Presentation
        return fileINI->getValeur("presentation","exe");
        break;
    case 3: // 3.tableur
        return fileINI->getValeur("tableur","exe");
        break;
    case 4: // 4.Traitement de texte
        return fileINI->getValeur("traitement","exe");
        break;
    default:
        return "error";
        break;
    }
}

bool CAInterfaceSetting::getAppSpeciauxSetted(int app){
    QString emplacementapp;
    switch (app) {
    case 1: // 1.Navigateur
        emplacementapp = fileINI->getValeur("navigateur","exe");
        break;
    case 2: // 2.Presentation
        emplacementapp = fileINI->getValeur("presentation","exe");
        break;
    case 3: // 3.tableur
        emplacementapp = fileINI->getValeur("tableur","exe");
        break;
    case 4: // 4.Traitement de texte
        emplacementapp = fileINI->getValeur("traitement","exe");
        break;
    default:
        return false;
        break;
    }

    if (emplacementapp =="nothing"){
        return false;
    }
    else{
        return true;
    }
}

// Getteur application Arrera

QString CAInterfaceSetting::getMoteurRecherche(){
    return fileINI->getValeur("arrera-recherche","moteur");
}

QString CAInterfaceSetting::getFileJson(){
    return fileINI->getValeur("arrera-app","fileJson");
}

QString CAInterfaceSetting::getEmplacementStore(){
    return fileINI->getValeur("arrera-app","store");
}

QString CAInterfaceSetting::getExeArreraApp(QString nameApp){
    if (listApp.contains(nameApp)){
        return fileINI->getValeur("arrera-app",nameApp);
    }
    else{
        return "";
    }
}

bool CAInterfaceSetting::getTaskbarBTNSix(){
    if (fileINI->getValeur("taskbar","btnSix")=="1"){
        return true;
    }else{
        return false;
    }
}
bool CAInterfaceSetting::getTaskbarBTNArreraApp(){
    if (fileINI->getValeur("taskbar","btnArreraApp")=="1"){
        return true;
    }else{
        return false;
    }
}
bool CAInterfaceSetting::getTaskbarBTNRyley(){
    if (fileINI->getValeur("taskbar","btnRyley")=="1"){
        return true;
    }else{
        return false;
    }
}

bool CAInterfaceSetting::getTaskbarCopilote(){
    if (fileINI->getValeur("taskbar","btnCopilote")=="1"){
        return true;
    }else{
        return false;
    }
}

bool CAInterfaceSetting::getTaskbarPostite(){
    if (fileINI->getValeur("taskbar","btnPostite")=="1"){
        return true;
    }else{
        return false;
    }
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

bool CAInterfaceSetting::setApplication(int nb,QString nameApp,QString emplacement,QString icon){
    if (nameApp.isEmpty() or emplacement.isEmpty()){
        return false;
    }else{
        if(clamp(nb, 1, 20) == nb){

            fileINI->setValeur("app"+QString::number(nb),"name",nameApp);
            fileINI->setValeur("app"+QString::number(nb),"exe",emplacement);

            if (!icon.isEmpty()){
                fileINI->setValeur("app"+QString::number(nb),"icon",icon);
            }
            return true;
        }else{
            return false;
        }
    }
}

bool CAInterfaceSetting::setNewExeApplication(int nb,QString emplacement){
    return fileINI->setValeur("app"+QString::number(nb),"exe",emplacement);
}

bool CAInterfaceSetting::setNewIconApplication(int nb,QString icon){
    return fileINI->setValeur("app"+QString::number(nb),"icon",icon);
}

bool CAInterfaceSetting::setSupprApplication(int nb){
    if (fileINI->setValeur("app"+QString::number(nb),"name","nothing")){
        if (fileINI->setValeur("app"+QString::number(nb),"exe","nothing")){
            return fileINI->setValeur("app"+QString::number(nb),"icon","nothing");
        }
        else{
            return false;
        }
    }else{
        return false;
    }
}

bool CAInterfaceSetting::setAppTableur(QString emplacement){
    return fileINI->setValeur("tableur","exe",emplacement);
}
bool CAInterfaceSetting::setAppTraitementTexte(QString emplacement){
    return fileINI->setValeur("traitement","exe",emplacement);
}
bool CAInterfaceSetting::setAppPresentation(QString emplacement){
    return fileINI->setValeur("presentation","exe",emplacement);
}
bool CAInterfaceSetting::setAppNavigateur(QString emplacement){
    return fileINI->setValeur("navigateur","exe",emplacement);
}


bool CAInterfaceSetting::setSupprAppTableur(){
    return fileINI->setValeur("tableur","exe","nothing");
}
bool CAInterfaceSetting::setSupprAppTraitementTexte(){
    return fileINI->setValeur("traitement","exe","nothing");
}
bool CAInterfaceSetting::setSupprAppPresentation(){
    return fileINI->setValeur("presentation","exe","nothing");
}
bool CAInterfaceSetting::setSupprAppNavigateur(){
    return fileINI->setValeur("navigateur","exe","nothing");
}

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

bool CAInterfaceSetting::setFileJson(QString file){
    return fileINI->setValeur("arrera-app","fileJson",file);
}

bool CAInterfaceSetting::setEmplacementStore(QString emplacement){
    return fileINI->setValeur("arrera-app","store",emplacement);
}

bool CAInterfaceSetting::setEmplacementArreraApp(QString nameApp,QString emplacement){
    /*
     App possible:
         * "ryley"
         * "six"
         * "arrera-raccourci"
         * "arrera-postite"
         * "arrera-video-download"
         * "arrera-copilote"
    */
    if (listApp.contains(nameApp)){
        return fileINI->setValeur("arrera-app",nameApp,emplacement);
    }else{
        return false;
    }
}


bool CAInterfaceSetting::setTaskbarBTNSix(){
    return fileINI->setValeur("taskbar","btnSix","1");
}

bool CAInterfaceSetting::setTaskbarBTNArreraApp(){
    return fileINI->setValeur("taskbar","btnArreraApp","1");
}

bool CAInterfaceSetting::setTaskbarBTNRyley(){
    return fileINI->setValeur("taskbar","btnRyley","1");
}

bool CAInterfaceSetting::setTaskbarBTNCopilote(){
    return fileINI->setValeur("taskbar","btnCopilote","1");
}

bool CAInterfaceSetting::setTaskbarBBTNPostite(){
    return fileINI->setValeur("taskbar","btnPostite","1");
}

// Unset

bool CAInterfaceSetting::unsetTaskbarBTNSix(){
    return fileINI->setValeur("taskbar","btnSix","0");
}

bool CAInterfaceSetting::unsetTaskbarBTNArreraApp(){
    return fileINI->setValeur("taskbar","btnArreraApp","0");
}

bool CAInterfaceSetting::unsetTaskbarBTNRyley(){
    return fileINI->setValeur("taskbar","btnRyley","0");
}

bool CAInterfaceSetting::unsetTaskbarBTNCopilote(){
    return fileINI->setValeur("taskbar","btnCopilote","0");
}

bool CAInterfaceSetting::unsetTaskbarBTNPostite(){
    return fileINI->setValeur("taskbar","btnPostite","0");
}

// Partie reset
bool CAInterfaceSetting::resetArreraApp(){

    if (fileINI->setValeur("arrera-app","fileJson","nothing")){
        if (fileINI->setValeur("arrera-app","store","nothing")){
            if (fileINI->setValeur("arrera-app","ryley","nothing")){
                if (fileINI->setValeur("arrera-app","six","nothing")){
                    if (fileINI->setValeur("arrera-app","arrera-raccourci","nothing")){
                        if (fileINI->setValeur("arrera-app","arrera-postite","nothing")){
                            if (fileINI->setValeur("arrera-app","arrera-video-download","nothing")){
                                if (fileINI->setValeur("arrera-app","arrera-copilote","nothing")){
                                    return true;
                                }else{
                                    return false;
                                }
                            }else{
                                return false;
                            }
                        }else{
                            return false;
                        }
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }
}

bool CAInterfaceSetting::resetAppPC(){
    bool name,exe,icon,ok;
    for (int i = 1 ; i <= 20 ; i++){
        name = fileINI->setValeur("app"+QString::number(i),"name","nothing");
        exe = fileINI->setValeur("app"+QString::number(i),"exe","nothing");
        icon = fileINI->setValeur("app"+QString::number(i),"icon","nothing");

        if (name){
            if (exe){
                if (!icon){
                    return false;
                }
            }else{
                return false;
            }
        }else{
            return false;
        }
        ok = true;
    }
    return ok;
}

void CAInterfaceSetting::resetAll(){

    fileINI->setValeur("arrera-recherche","moteur","nothing");
    fileINI->setValeur("interface","user","nothing");
    fileINI->setValeur("arrera-app","fileJson","nothing");
    fileINI->setValeur("arrera-app","store","nothing");
    fileINI->setValeur("arrera-app","ryley","nothing");
    fileINI->setValeur("arrera-app","six","nothing");
    fileINI->setValeur("arrera-app","arrera-raccourci","nothing");
    fileINI->setValeur("arrera-app","arrera-postite","nothing");
    fileINI->setValeur("arrera-app","arrera-video-download","nothing");
    fileINI->setValeur("arrera-app","arrera-copilote","nothing");
    for (int i = 1 ; i <= 20 ; i++){
        fileINI->setValeur("app"+QString::number(i),"name","nothing");
        fileINI->setValeur("app"+QString::number(i),"exe","nothing");
        fileINI->setValeur("app"+QString::number(i),"icon","nothing");
    }
    fileINI->setValeur("navigateur","exe","nothing");
    fileINI->setValeur("tableur","exe","nothing");
    fileINI->setValeur("presentation","exe","nothing");
    fileINI->setValeur("traitement","exe","nothing");

    fileINI->setValeur("taskbar","btnArreraApp","0");
    fileINI->setValeur("taskbar","btnSix","0");
    fileINI->setValeur("taskbar","btnRyley","0");
    fileINI->setValeur("taskbar","btnCopilote","0");
    fileINI->setValeur("taskbar","btnPostite","0");
}


bool CAInterfaceSetting::launchLieu1(){
    return lieu1.launchLieu();
}
bool CAInterfaceSetting::launchLieu2(){
    return lieu2.launchLieu();
}

bool CAInterfaceSetting::disableLieu1(){
    return lieu1.disableLieu();
}
bool CAInterfaceSetting::disableLieu2(){
    return lieu2.disableLieu();
}
