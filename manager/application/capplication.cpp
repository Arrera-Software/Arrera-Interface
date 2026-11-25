#include "capplication.h"

CApplication::CApplication()
    : objPara(nullptr)
    , button(nullptr)
    , objOs(nullptr)
    , iconApp(nullptr)
    , appSetted(false)
    , nbApp(0)
{
}

CApplication::CApplication(int PnbApp, CAInterfaceSetting* pSetting, QPushButton* pButton, CDetectionOS* pOS){
    objPara = pSetting;
    button = pButton;
    objOs = pOS;
    nbApp = PnbApp;
    appSetted = false;  // Initialiser appSetted
    iconApp = nullptr;  // Initialiser iconApp
    if (button) {
        button->setVisible(false);
    }
}

CApplication::~CApplication(){
    delete iconApp;
    iconApp = nullptr;
}

// Implémentation de la méthode virtuelle loadData()
bool CApplication::loadData() {
    // Implémentation par défaut qui peut être redéfinie dans les classes dérivées
    return false;
}

bool CApplication::executeApplication(){
    if (appSetted){
        if (objOs->getosWin()){
            if (QDesktopServices::openUrl(QUrl::fromLocalFile(
                    exeApp))) {
                return true;
            }
            else {
                return false;
            }
        }
        else if(objOs->getosLinux())
        {
                QProcess process;
                return process.startDetached(exeApp, QStringList());
        }
        else if (objOs->getosApple())
        {
            QProcess process;
            QStringList arguments;
            arguments << exeApp;
            return process.startDetached("open", arguments);
        }
        else
        {
            return false;
        }
        }else
    {
        return false;
    }
}

bool CApplication::getAppSetted(){
    return appSetted;
}
