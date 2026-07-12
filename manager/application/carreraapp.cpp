#include "carreraapp.h"

CArreraApp::CArreraApp() {
#if defined(Q_OS_MAC) || defined(Q_OS_LINUX)
    hub_config_file = QStandardPaths::writableLocation(QStandardPaths::HomeLocation) + "/.config/arrera-hub/config.ini";
#elif defined(Q_OS_WIN)
    QString roaming = QStandardPaths::writableLocation(QStandardPaths::GenericConfigLocation);
    QString base_dir = roaming + "/arrera-hub";
    hub_config_file = base_dir+"/config.ini";
#endif
}

bool CArreraApp::load_hub_config_file(){
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
        return false;

    } catch (...) {
        return false;
    }
    #elif defined(Q_OS_MAC)
        QStringList openArgs;
        openArgs << "-a" << app;
        openArgs << "--args";
        return QProcess::startDetached("open", openArgs);
    #endif
    return false;
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

bool CArreraApp::load_arrera_application(QString nameApp ,QPushButton* button)
{
    /*
     * copilot
     * markdown
     * post-it
     * ryley
     * six
     * six_chat
    */

    button->setVisible(false);
    button->disconnect();

    QStringList list_app = {"copilot","markdown","post-it","ryley","six","six_chat"};


    if (!list_app.contains(nameApp)) return false;
    if (!hub_config_file_init) return false;

    hub_settings->sync();
    hub_settings->beginGroup("software");
    QString app_emplacement = hub_settings->value(nameApp+"_install", "error").toString();
    hub_settings->endGroup();

    //cout << app_emplacement.toStdString() << endl;

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
    #elif defined(Q_OS_MAC)
    QObject::connect(button, &QPushButton::clicked, [this, app_emplacement]() {
        this->exectute(app_emplacement);
    });
    #endif

    return true;
}
