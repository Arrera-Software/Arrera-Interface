#include "cainterfacesetting.h"

CAInterfaceSetting::CAInterfaceSetting():
    fileINI("arrera-interface")
{
    if(fileINI.getFileCreated()){
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
    return fileINI.getValeur("interface","user");
}

// Getteur application

int CAInterfaceSetting::getFirstUnsetNumber(){
    for (int i = 1 ; i <= 21 ; i++){
        if(fileINI.getValeur("app"+QString::number(i),"name")=="nothing"){
            return i;
        }
    }
    return 0;
}

int CAInterfaceSetting::getnbAppSetted(){
    int nbApp=0;
    for(int i = 1;i<=20;i++){
        if(fileINI.getValeur("app"+QString::number(i),"name")!="nothing"){
            nbApp++;
        }
    }
    return nbApp;
}

bool CAInterfaceSetting::getAppSetted(int nbApp){
    QString nameApp = fileINI.getValeur("app"+QString::number(nbApp),"name");
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
            listOut.append(fileINI.getValeur("app"+QString::number(i),"name"));
        }
    }
    return listOut;
}

QString CAInterfaceSetting::assosNameOfApp(QString app){
    QString y ;
    for (int i = 1;i<=20;i++){
        if (getAppSetted(i)){
            y = fileINI.getValeur("app"+QString::number(i),"name");
            if (y==app){
                return "app"+QString::number(i);
            }
        }
    }
    return "error";
}

bool CAInterfaceSetting::checkNameAppIsAvailable(QString name){
    for (int i = 1;i<=20;i++){
        if (fileINI.getValeur("app"+QString::number(i),"name")==name){
            return false;
        }
    }
    return true;
}

int CAInterfaceSetting::getNbAppWithName(QString name){
    for (int i = 1;i<=20;i++){
        if (fileINI.getValeur("app"+QString::number(i),"name")==name){
            return i;
        }
    }
    return -1;
}

bool CAInterfaceSetting::getApplication(int nb,QString *name,QString *exe,QString *icon){
    if (nb >= 1 && nb <= 20) {
        *name = fileINI.getValeur("app"+QString::number(nb),"name");
        *exe = fileINI.getValeur("app"+QString::number(nb),"exe");
        *icon = fileINI.getValeur("app"+QString::number(nb),"icon");
        return true;
    } else {
        return false;
    }
}

QString CAInterfaceSetting::getAppSpeciaux(int app){
    switch (app) {
    case 1: // 1.Navigateur
        return fileINI.getValeur("navigateur","exe");
        break;
    case 2: // 2.Presentation
        return fileINI.getValeur("presentation","exe");
        break;
    case 3: // 3.tableur
        return fileINI.getValeur("tableur","exe");
        break;
    case 4: // 4.Traitement de texte
        return fileINI.getValeur("traitement","exe");
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
        emplacementapp = fileINI.getValeur("navigateur","exe");
        break;
    case 2: // 2.Presentation
        emplacementapp = fileINI.getValeur("presentation","exe");
        break;
    case 3: // 3.tableur
        emplacementapp = fileINI.getValeur("tableur","exe");
        break;
    case 4: // 4.Traitement de texte
        emplacementapp = fileINI.getValeur("traitement","exe");
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
    return fileINI.getValeur("arrera-recherche","moteur");
}

bool CAInterfaceSetting::getTaskbarBTNSix(){
    if (fileINI.getValeur("taskbar","btnSix")=="1"){
        return true;
    }else{
        return false;
    }
}
bool CAInterfaceSetting::getTaskbarBTNArreraApp(){
    if (fileINI.getValeur("taskbar","btnArreraApp")=="1"){
        return true;
    }else{
        return false;
    }
}
bool CAInterfaceSetting::getTaskbarBTNRyley(){
    if (fileINI.getValeur("taskbar","btnRyley")=="1"){
        return true;
    }else{
        return false;
    }
}

bool CAInterfaceSetting::getTaskbarCopilote(){
    if (fileINI.getValeur("taskbar","btnCopilote")=="1"){
        return true;
    }else{
        return false;
    }
}

bool CAInterfaceSetting::getTaskbarPostite(){
    if (fileINI.getValeur("taskbar","btnPostite")=="1"){
        return true;
    }else{
        return false;
    }
}

// Setteurs
bool CAInterfaceSetting::setNameUser(QString& user){
    return fileINI.setValeur("interface","user",user);
}

bool CAInterfaceSetting::setApplication(int nb,QString nameApp,QString emplacement,QString icon){
    if (nameApp.isEmpty() or emplacement.isEmpty()){
        return false;
    }else{
        if(clamp(nb, 1, 20) == nb){

            fileINI.setValeur("app"+QString::number(nb),"name",nameApp);
            fileINI.setValeur("app"+QString::number(nb),"exe",emplacement);

            if (!icon.isEmpty()){
                fileINI.setValeur("app"+QString::number(nb),"icon",icon);
            }
            return true;
        }else{
            return false;
        }
    }
}

bool CAInterfaceSetting::setNewExeApplication(int nb,QString emplacement){
    return fileINI.setValeur("app"+QString::number(nb),"exe",emplacement);
}

bool CAInterfaceSetting::setNewIconApplication(int nb,QString icon){
    return fileINI.setValeur("app"+QString::number(nb),"icon",icon);
}

bool CAInterfaceSetting::setSupprApplication(int nb){
    if (fileINI.setValeur("app"+QString::number(nb),"name","nothing")){
        if (fileINI.setValeur("app"+QString::number(nb),"exe","nothing")){
            return fileINI.setValeur("app"+QString::number(nb),"icon","nothing");
        }
        else{
            return false;
        }
    }else{
        return false;
    }
}

bool CAInterfaceSetting::setAppTableur(QString emplacement){
    return fileINI.setValeur("tableur","exe",emplacement);
}
bool CAInterfaceSetting::setAppTraitementTexte(QString emplacement){
    return fileINI.setValeur("traitement","exe",emplacement);
}
bool CAInterfaceSetting::setAppPresentation(QString emplacement){
    return fileINI.setValeur("presentation","exe",emplacement);
}
bool CAInterfaceSetting::setAppNavigateur(QString emplacement){
    return fileINI.setValeur("navigateur","exe",emplacement);
}


bool CAInterfaceSetting::setSupprAppTableur(){
    return fileINI.setValeur("tableur","exe","nothing");
}
bool CAInterfaceSetting::setSupprAppTraitementTexte(){
    return fileINI.setValeur("traitement","exe","nothing");
}
bool CAInterfaceSetting::setSupprAppPresentation(){
    return fileINI.setValeur("presentation","exe","nothing");
}
bool CAInterfaceSetting::setSupprAppNavigateur(){
    return fileINI.setValeur("navigateur","exe","nothing");
}

bool CAInterfaceSetting::setMoteurRecherche(QString moteur){
    return fileINI.setValeur("arrera-recherche","moteur",moteur);
}

bool CAInterfaceSetting::setTaskbarBTNSix(){
    return fileINI.setValeur("taskbar","btnSix","1");
}

bool CAInterfaceSetting::setTaskbarBTNArreraApp(){
    return fileINI.setValeur("taskbar","btnArreraApp","1");
}

bool CAInterfaceSetting::setTaskbarBTNRyley(){
    return fileINI.setValeur("taskbar","btnRyley","1");
}

bool CAInterfaceSetting::setTaskbarBTNCopilote(){
    return fileINI.setValeur("taskbar","btnCopilote","1");
}

bool CAInterfaceSetting::setTaskbarBBTNPostite(){
    return fileINI.setValeur("taskbar","btnPostite","1");
}

// Unset

bool CAInterfaceSetting::unsetTaskbarBTNSix(){
    return fileINI.setValeur("taskbar","btnSix","0");
}

bool CAInterfaceSetting::unsetTaskbarBTNArreraApp(){
    return fileINI.setValeur("taskbar","btnArreraApp","0");
}

bool CAInterfaceSetting::unsetTaskbarBTNRyley(){
    return fileINI.setValeur("taskbar","btnRyley","0");
}

bool CAInterfaceSetting::unsetTaskbarBTNCopilote(){
    return fileINI.setValeur("taskbar","btnCopilote","0");
}

bool CAInterfaceSetting::unsetTaskbarBTNPostite(){
    return fileINI.setValeur("taskbar","btnPostite","0");
}

// Partie reset

bool CAInterfaceSetting::resetAppPC(){
    bool name,exe,icon,ok;
    for (int i = 1 ; i <= 20 ; i++){
        name = fileINI.setValeur("app"+QString::number(i),"name","nothing");
        exe = fileINI.setValeur("app"+QString::number(i),"exe","nothing");
        icon = fileINI.setValeur("app"+QString::number(i),"icon","nothing");

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

    fileINI.setValeur("arrera-recherche","moteur","nothing");
    fileINI.setValeur("interface","user","nothing");
    for (int i = 1 ; i <= 20 ; i++){
        fileINI.setValeur("app"+QString::number(i),"name","nothing");
        fileINI.setValeur("app"+QString::number(i),"exe","nothing");
        fileINI.setValeur("app"+QString::number(i),"icon","nothing");
    }
    fileINI.setValeur("navigateur","exe","nothing");
    fileINI.setValeur("tableur","exe","nothing");
    fileINI.setValeur("presentation","exe","nothing");
    fileINI.setValeur("traitement","exe","nothing");

    fileINI.setValeur("taskbar","btnArreraApp","0");
    fileINI.setValeur("taskbar","btnSix","0");
    fileINI.setValeur("taskbar","btnRyley","0");
    fileINI.setValeur("taskbar","btnCopilote","0");
    fileINI.setValeur("taskbar","btnPostite","0");
}

QStringList CAInterfaceSetting::get_list_gui_six(){
    QStringList list_gui_six;
    list_gui_six << "normal" << "chat";
    return list_gui_six;
}


bool CAInterfaceSetting::set_gui_six(QString gui){
    QStringList list_gui_six = this->get_list_gui_six();

    if (list_gui_six.contains(gui)){
        return fileINI.setValeur("arrera-app","six_gui",gui);
    } else return false;
}

QString CAInterfaceSetting::get_gui_six(){
    return fileINI.getValeur("arrera-app","six_gui");
}

