#include "capppc.h"

CAppPC::CAppPC() {}

CAppPC::CAppPC(int nbApp, CAInterfaceSetting* pSetting, QPushButton* pButton, CDetectionOS* pOS) :
    CApplication(nbApp, pSetting, pButton, pOS){}

CAppPC::~CAppPC(){}

bool CAppPC::loadData(){
    QString icon;
    if (!button) {
        return false;
    }

    button->setIcon(QIcon());
    if (nbApp >= 1 && nbApp <= 21) {
        appSetted = objPara->getAppSetted(nbApp);
        if (appSetted){
            if (objPara->getApplication(nbApp, &nameApp, &exeApp, &icon)){
                if(!nameApp.isEmpty() && !exeApp.isEmpty()){
                    button->setVisible(true);
                    if (icon != "nothing"){
                        button->setText("");
                        iconApp = new QIcon(icon);
                        button->setIcon(*iconApp);
                    }else{
                        button->setText(nameApp);
                    }
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        else{
            button->setVisible(false);
        }
    }
    return false;  // Ajoutez cette ligne pour couvrir tous les cas
}


QString CAppPC::getIcon(){
    QString icon;
    objPara->getApplication(nbApp, &nameApp, &exeApp, &icon);
    return icon;
}

QString CAppPC::getName(){
    return nameApp;
}
