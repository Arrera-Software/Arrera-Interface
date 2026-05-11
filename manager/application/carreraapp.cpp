#include "carreraapp.h"
#include "QFile"

CArreraApp::CArreraApp() {}

CArreraApp::CArreraApp(CAInterfaceSetting* p,CDetectionOS *os,QWidget *pw){
    psetting = p;
    dectOS = os;
    widget = pw;

    #if defined(Q_OS_MAC) || defined(Q_OS_LINUX)
        hub_config_file = QStandardPaths::writableLocation(QStandardPaths::HomeLocation) + "/.config/arrera-hub/config.ini";
    #elif defined(Q_OS_WIN)
        QString roaming = QStandardPaths::writableLocation(QStandardPaths::GenericConfigLocation);
        QString base_dir = roaming + "/arrera-hub";
        hub_config_file = base_dir+"/config.ini";
    #endif
}

bool CArreraApp::loadJson(){
    QFileInfo checkFile(hub_config_file);
    if (checkFile.exists() && checkFile.isFile()){
        hub_settings = new QSettings(hub_config_file, QSettings::IniFormat);
        if (hub_settings->status() == QSettings::NoError){
            hub_config_file_init = true;
            return true;
        }else return false;
    }else return false;
}

bool  CArreraApp::exectute(QString app){
    #if defined(Q_OS_WIN)
        QFileInfo fileInfo(app);
        QString dossierApp = fileInfo.absolutePath();

        QProcess process;
        process.setProgram(app);
        process.setWorkingDirectory(dossierApp);
        return process.startDetached();
    #elif defined(Q_OS_LINUX)
    try{
        return QProcess::startDetached("/bin/bash",QStringList() << app);
    }catch (const std::exception& e){
        cout << "Erreur : " << e.what() << endl;

    } catch (...) {
        cout << "Erreur " << endl;
    }
    #elif defined(Q_OS_MAC)
        QStringList openArgs;
        openArgs << "-a" << app;
        openArgs << "--args";
        return QProcess::startDetached("open", openArgs);
    #endif
    return false;
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

bool CArreraApp::open_arrera_hub(){
    #if defined(Q_OS_LINUX)
    QString emplacementStore = QDir::homePath() +"/Applications/arrera-hub-linux-x86/launch.sh";
    if (QFile::exists(emplacementStore)) return exectute(emplacementStore);
    else return false;
    #elif defined(Q_OS_MAC)
    QString targetApp = "Arrera_Hub.app";

    QStringList searchPaths = QStandardPaths::standardLocations(QStandardPaths::ApplicationsLocation);

    if (!searchPaths.contains("/Applications")) {
        searchPaths.append("/Applications");
    }

    for (QString &basePath : searchPaths) {
        QDirIterator it(basePath,
                        QStringList() << targetApp,
                        QDir::Dirs | QDir::NoDotAndDotDot,
                        QDirIterator::Subdirectories);

        while (it.hasNext()) {
            QString appPath = it.next();
            return exectute(appPath) ;
        }
    }
    return false;

    #elif defined(Q_OS_WIN)
    QString hub_folder = QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation)+"/Programs/Arrera Hub";

    QDir dir(hub_folder);
    if (!dir.exists()) return false;
    QString hub_exe = hub_folder + "/Arrera_Hub.exe";

    QFileInfo exeInfo(hub_exe);
    if (exeInfo.exists() && exeInfo.isFile()) return exectute(hub_exe) ;
    else return false;
    #endif
}

bool CArreraApp::loadApp(QString nameApp ,QPushButton* button)
{
    /*
     * copilot
     * markdown
     * post-it
     * ryley
     * six
    */

    button->setVisible(false);
    button->disconnect();

    QStringList list_app = {"copilot","markdown","post-it","ryley","six"};


    if (!list_app.contains(nameApp)) return false;
    if (!hub_config_file_init) return false;

    hub_settings->sync();
    hub_settings->beginGroup("software");
    QString app_emplacement = hub_settings->value(nameApp+"_install", "error").toString();
    hub_settings->endGroup();

    cout << app_emplacement.toStdString() << endl;

    if ((app_emplacement == "error") || (app_emplacement == "none")) return false;

    button->setVisible(true);
    #if defined(Q_OS_WIN)
    QDirIterator it(app_emplacement, QStringList() << "*.exe", QDir::Files);
    if (!it.hasNext()) return false;
    QString exe_file = it.next();
    QObject::connect(button, &QPushButton::clicked, [this, exe_file](){
        this->exectute(exe_file);
    });
    #elif defined(Q_OS_LINUX)
    QObject::connect(button, &QPushButton::clicked, [this, app_emplacement]() {
        this->exectute(app_emplacement+"/launch.sh");
    });
    #endif



    return true;
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
        return exectute("");
    }
}
