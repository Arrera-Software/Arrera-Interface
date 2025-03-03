#include "capplication.h"

CApplication::CApplication() {}

CApplication::CApplication(CAInterfaceSetting* pSetting,QPushButton* pButton,CDetectionOS* pOS){
    objPara = pSetting;
    button = pButton;
    objOs = pOS;
}

bool CApplication::executeApplication(){
    if (appSetted){
        if (objOs->getosWin()){
            if (QDesktopServices::openUrl(QUrl::fromLocalFile(
                    QString::fromStdString(exeApp)))) {
                return true;
            }
            else {
                return false;
            }
        }else{
            if(objOs->getosLinux()){
                QProcess process;
                return process.startDetached(exeApp.c_str(), QStringList());
            }else{
                return false;
            }
        }
    }else{
        return false;
    }
}
