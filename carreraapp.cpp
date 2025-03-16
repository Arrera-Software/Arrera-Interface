#include "carreraapp.h"

CArreraApp::CArreraApp() {}

CArreraApp::CArreraApp(CAInterfaceSetting* p){
    psetting = p;

    tigerFile = psetting->getFileJson();

    if (tigerFile=="nothing"){
        tigerFileSetted = false;
    }else{
        tigerFileSetted = true;
    }
}

bool  CArreraApp::exectute(QString app,bool appSetted){
    if (appSetted){
        if (objOs->getosWin()){
            if (QDesktopServices::openUrl(QUrl::fromLocalFile(
                    app))) {
                return true;
            }
            else {
                return false;
            }
        }else{
            if(objOs->getosLinux()){
                QProcess process;
                return process.startDetached(app, QStringList());
            }else{
                return false;
            }
        }
    }else{
        return false;
    }
}

bool CArreraApp::openStore(){

}


