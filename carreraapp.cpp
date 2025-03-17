#include "carreraapp.h"
#include "QFile"

#include "iostream"
using namespace std ;

CArreraApp::CArreraApp() {}

CArreraApp::CArreraApp(CAInterfaceSetting* p,CDetectionOS *os,QWidget *pw){
    psetting = p;
    dectOS = os;
    widget = pw;
}

bool CArreraApp::loadJson(){
    tigerFile = psetting->getFileJson();

    if (tigerFile=="nothing"){
        jsonFile = nullptr;
        tigerFileSetted = false;
    }else{
        jsonFile = new CJSONWORD(tigerFile);
        tigerFileSetted = true;
    }
}

bool  CArreraApp::exectute(QString app,bool appSetted){
    if (!appSetted){
        QProcess process;
        if (dectOS->getosWin()){
            return process.startDetached(app);
        }else{
            if(dectOS->getosLinux()){

                return process.startDetached(app, QStringList());
            }else{
                return false;
            }
        }
    }else{
        return false;
    }
}

bool CArreraApp::setBatWindows(QString emplacement){
    QString workingDir = QFileInfo(emplacement).absolutePath();
    QString exeWin = emplacement.remove(workingDir);
    QString batFile = workingDir+"/"+"lauch.bat";

    QFile file(batFile);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }
    QTextStream out(&file);
    out << "@echo off" << Qt::endl;
    out << "cd "+workingDir << Qt::endl;
    out << ".\\"+exeWin << Qt::endl;
    file.close();
    return true;
}

bool CArreraApp::openStore(){
    QString exeLinux = "lauch.sh" ;
    QString exeWin = "arrera-store.exe" ;
    QString jsonFile = "json/tigerConf.json";

    QString emplacementStore = psetting->getEmplacementStore();

    if (emplacementStore == "nothing"){
        QString appEmplacement;
        QMessageBox::information(widget,"Information",
                                 "Veuillez sélectionner l'emplacement du dossier où vous avez installé l'Arrera Store.");
        appEmplacement = QFileDialog::getExistingDirectory(
            widget,
            "Sélectionner un dossier",
            QDir::homePath(),
            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks
            );
        if (dectOS->getosLinux()){
            if (psetting->setEmplacementStore(appEmplacement+"/"+exeLinux) &&
                psetting->setFileJson(appEmplacement+"/"+jsonFile)){
                return true;
            }else{
                return false;
            }
        }else{
            if (dectOS->getosWin()){
                QString fileBat = appEmplacement+"/"+"lauch.bat";
                QFile file(fileBat);
                if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                    return false;
                }
                QTextStream out(&file);
                out << "@echo off" << Qt::endl;
                out << "cd "+appEmplacement << Qt::endl;
                out << ".\\"+exeWin << Qt::endl;
                file.close();

                if (psetting->setEmplacementStore(appEmplacement+"/lauch.bat") &&
                    psetting->setFileJson(appEmplacement+"/"+jsonFile)){
                    return true;
                }else{
                    return false;
                }
            }
        }
    }else{
        return exectute(emplacementStore,emplacementStore.isEmpty());
    }
    return  false;
}

bool CArreraApp::loadApp(QString nameApp ,QPushButton* button)
{
    /*
     App possible:
         * "ryley"
         * "six"
         * "arrera-raccourci"
         * "arrera-postite"
         * "arrera-video-download"
         * "arrera-copilote"
     */

    // Verification si l'app a etais setted

    QString exeApp = psetting->getExeArreraApp(nameApp);

    if (exeApp=="nothing"){
        bool clesExisted = jsonFile->isExist(nameApp);
        if (!clesExisted){
            button->setVisible(false);
            return false;
        }

        QString emplacement = jsonFile->read(nameApp);

        if (emplacement == "nothing"){
            button->setVisible(false);
            return false;
        }else{

            if (dectOS->osLinux()){
                psetting->setEmplacementArreraApp(nameApp,emplacement);
            }else{
                if (dectOS->osWin()){

                }
            }

            button->setVisible(true);
            return true;
        }
    }else{
        button->setVisible(true);
        return true;
    }



}

bool CArreraApp::executeApp(QString nameApp){
    /*
     App possible:
         * "ryley"
         * "six"
         * "arrera-raccourci"
         * "arrera-postite"
         * "arrera-video-download"
         * "arrera-copilote"
     */
}
