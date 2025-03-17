#include "carreraapp.h"

CArreraApp::CArreraApp() {}

CArreraApp::CArreraApp(CAInterfaceSetting* p,CDetectionOS *os,QWidget *pw){
    psetting = p;
    dectOS = os;
    widget = pw;

    tigerFile = psetting->getFileJson();

    if (tigerFile=="nothing"){
        tigerFileSetted = false;
    }else{
        tigerFileSetted = true;
    }
}

bool  CArreraApp::exectute(QString app,bool appSetted){
    if (!appSetted){
        if (dectOS->getosWin()){
            if (QDesktopServices::openUrl(QUrl::fromLocalFile(
                    app))) {
                return true;
            }
            else {
                return false;
            }
        }else{
            if(dectOS->getosLinux()){
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
    QString emplacementStore = psetting->getEmplacementStore();
    if (emplacementStore == "nothing"){
        int rMessage;
        QString appDirectory ;
        QString appEmplacement;
        // Partie linux
        if (dectOS->getosLinux() == true){
            rMessage = QMessageBox::question(widget,"Emplacement application",
                                             "L'application Arrera Store se trouve dans votre /home ou dans le /bin ?",
                                             QMessageBox::Yes | QMessageBox::No,QMessageBox::No);

            if (rMessage == QMessageBox::Yes){
                // Dossier /bin
                appDirectory = "/bin";
            }else{
                // Dossier /home
                appDirectory = QDir::homePath();
            }
            appEmplacement = QFileDialog::getOpenFileName(
                widget,                       // Parent widget
                "Sélectionner l'application",  // Titre de la boîte de dialogue
                appDirectory           // Répertoire initial
                );
            return psetting->setEmplacementStore(appEmplacement);
        }else{
            if(dectOS->getosWin()==true){
                rMessage = QMessageBox::question(widget,"Emplacement application",
                                                 "Arrera Store se trouve dans le menu Démarrer global ?",
                                                 QMessageBox::Yes | QMessageBox::No,QMessageBox::No);

                if (rMessage == QMessageBox::Yes){
                    // Dossier programme data
                    appDirectory = "C:/ProgramData/Microsoft/Windows/Start Menu/Programs";
                }else{
                    // Menu demarer dans le dossier utilisateur
                    appDirectory = QStandardPaths::writableLocation(QStandardPaths::ApplicationsLocation);
                }
                appEmplacement = QFileDialog::getOpenFileName(
                    widget,                       // Parent widget
                    "Sélectionner l'application",  // Titre de la boîte de dialogue
                    appDirectory           // Répertoire initial
                    );
                return psetting->setEmplacementStore(appEmplacement);
            }
        }
    }else{
        return exectute(emplacementStore,emplacementStore.isEmpty());
    }
}


