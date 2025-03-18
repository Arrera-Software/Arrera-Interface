#include "carreraapp.h"
#include "QFile"

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
        return false;
    }else{
        jsonFile = new CJSONWORD(tigerFile);
        tigerFileSetted = true;
        return true;
    }
}

bool  CArreraApp::exectute(QString app,bool appSetted){
    if (appSetted == false){
        if (dectOS->getosWin()){
            QProcess process;
            return process.startDetached(app);
        }else{
            if(dectOS->getosLinux()){
                return QProcess::startDetached("/bin/bash",QStringList() << app);
            }else{
                return false;
            }
        }
    }else{
        return false;
    }
}

QString CArreraApp::setBatWindows(QString emplacement){
    QString workingDir = QFileInfo(emplacement).absolutePath();
    QString exeWin = emplacement.remove(workingDir).remove("/").remove("\\");
    QString batFile = workingDir+"/"+"lauch.bat";

    QFile file(batFile);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return "error";
    }
    QTextStream out(&file);
    out << "@echo off" << Qt::endl;
    out << "cd "+workingDir << Qt::endl;
    out << ".\\"+exeWin << Qt::endl;
    file.close();
    return batFile;
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
    button->setVisible(false);
    // Verification si l'app a etais setted

    if (tigerFileSetted){

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

                if (dectOS->getosLinux()){
                    psetting->setEmplacementArreraApp(nameApp,emplacement);
                }else{
                    if (dectOS->getosWin()){
                        QString batfile = setBatWindows(emplacement);
                        psetting->setEmplacementArreraApp(nameApp,batfile);
                    }
                }

                button->setVisible(true);
                return true;
            }
        }else{
            button->setVisible(true);
            return true;
        }
    }else{
        button->setVisible(false);
        return false;
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
    QString exeApp = psetting->getExeArreraApp(nameApp);
    if (exeApp.isEmpty()){;
        return false;
    }else{
        return exectute(exeApp,exeApp.isEmpty());
    }
}
