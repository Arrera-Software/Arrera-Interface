#include "csetting.h"

CSetting::CSetting() : fileOpen(false), fileCreated(false), settings(nullptr) {}

CSetting::CSetting(const QString &namesoft) {

    int os = checkOS();
    QString file;
    QString standartFolder ;

    if (os == 3 || os == 2){
        QString standartFolder = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
        if (QDir().mkdir(standartFolder+
                         "/.config/"+namesoft))
        {
            return ;
        }
        file = standartFolder+
               "/.config/"+namesoft+"/config.ini";

    }else if (os == 1){
        standartFolder =  QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
        if (QDir().mkdir(standartFolder)){
            return ;
        }
        file = standartFolder+"\\config.ini";
    }else {
        file = namesoft+".ini";
    }

    //cout << QStandardPaths::writableLocation(QStandardPaths::AppDataLocation).toStdString() << endl;

    QFileInfo checkFile(file);

    if (!checkFile.exists()) {
        QFile newFile(file);
        if (newFile.open(QIODevice::WriteOnly)) {
            newFile.close();
        }
        fileCreated = true;
    }
    else{
        fileCreated = false;
    }

    settings = new QSettings(file, QSettings::IniFormat);
    fileOpen = true;
}

int CSetting::checkOS(){
    #if defined(Q_OS_WIN)
        return 1;
    #elif defined(Q_OS_LINUX)
        return 2;
    #elif defined(Q_OS_MAC)
        return 3;
    #endif
}

bool CSetting::getFileCreated() const {
    return fileCreated;
}

bool CSetting::setValeur(const QString &section, const QString &key, const QString &value) {
    if (!fileOpen) return false;
    if (section.isEmpty() || key.isEmpty() || value.isEmpty()) return false;
    settings->setValue(section + "/" + key, value);
    settings->sync();
    return true;
}

QString CSetting::getValeur(const QString &section, const QString &key) const {
    if (!fileOpen) return "error";
    if (section.isEmpty() || key.isEmpty()) return "error";
    return settings->value(section + "/" + key, "error").toString();
}

bool CSetting::supprValeur(const QString &section, const QString &key) {
    if (!fileOpen) return false;
    if (section.isEmpty() || key.isEmpty()) return false;
    settings->remove(section + "/" + key);
    return true;
}
