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
        }else if(dectOS->getosLinux()){
            return QProcess::startDetached("/bin/bash",QStringList() << app);
        }else if (dectOS->getosApple()){
            QStringList openArgs;
            openArgs << "-a" << app;
            openArgs << "--args";
            return QProcess::startDetached("open", openArgs);
        }
        else{
            return false;
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

    bool appOS = dectOS->getosApple();
    QString emplacement;
    QString exeApp;

    if (tigerFileSetted || appOS ){

        exeApp = psetting->getExeArreraApp(nameApp);

        if (exeApp=="nothing"){
            if (!appOS){

                bool clesExisted = jsonFile->isExist(nameApp);
                if (!clesExisted){
                    button->setVisible(false);
                    return false;
                }

                emplacement = jsonFile->read(nameApp);
            }else{
                emplacement = exeApp;
            }


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

bool CArreraApp::loadAppMacOS(){
    if (dectOS->getosApple()){

        const QString home = QDir::homePath();
        const QStringList roots = {
            "/Applications",
            "/Applications/Utilities",
            home + "/Applications",
            "/System/Applications",
            "/System/Applications/Utilities",
            "/System/Library/CoreServices",
            "/System/Library/CoreServices/Applications"
        };

        QSet<QString> found;
        for (const QString &root : roots) {
            QDirIterator it(root,
                            QStringList{"*.app"},
                            QDir::Dirs | QDir::NoDotAndDotDot | QDir::Readable,
                            QDirIterator::Subdirectories);
            while (it.hasNext())
                found.insert(canonical(it.next()));
        }

        QStringList result = found.values();
        result.sort(Qt::CaseInsensitive);

        // Filtrer pour ne conserver que certains bundles .app (comparaison insensible à la casse)
        const QStringList targetsOrig = {
            "arrera-copilote.app",
            "Arrera-Postite.app",
            "six.app",
            "ryley.app"
        };

        // Map (lowercased) -> libellé d’origine demandé
        QHash<QString, QString> wanted;
        for (const auto &t : targetsOrig)
            wanted.insert(t.toLower(), t);

        // Résultat: nom demandé -> chemin .app trouvé
        QHash<QString, QString> selected;

        for (const QString &path : qAsConst(result)) {
            const QString fnameLower = QFileInfo(path).fileName().toLower();
            if (wanted.contains(fnameLower) && !selected.contains(wanted[fnameLower])) {
                selected.insert(wanted[fnameLower], path);
                if (selected.size() == wanted.size())
                    break;
            }
        }

        // 'selected' contient les emplacements des apps demandées (clé = nom demandé, valeur = chemin)

        /*
            ryley.app -> /Applications/ryley.app
            Arrera-Postite.app -> /Applications/Arrera-Postite.app
            six.app -> /Applications/six.app
            arrera-copilote.app -> /Applications/arrera-copilote.app
        */

        if (selected.contains("ryley.app")){
            psetting->setEmplacementArreraApp("ryley",selected.value("ryley.app"));
        }

        if (selected.contains("Arrera-Postite.app")){
            psetting->setEmplacementArreraApp("arrera-postite",selected.value("Arrera-Postite.app"));
        }
        if (selected.contains("six.app")){
            psetting->setEmplacementArreraApp("six",selected.value("six.app"));
        }

        if (selected.contains("arrera-copilote.app")){
            psetting->setEmplacementArreraApp("arrera-copilote",selected.value("arrera-copilote.app"));
        }


        return true;

    }else{
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
