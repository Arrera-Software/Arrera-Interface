#include "csetting.h"

CSetting::CSetting() : fileOpen(false), fileCreated(false), settings(nullptr) {}

CSetting::CSetting(const QString &file) {
    QFileInfo checkFile(file);
    fileCreated = !checkFile.exists();
    settings = new QSettings(file, QSettings::IniFormat);
    fileOpen = true;
}

bool CSetting::getFileCreated() const {
    return fileCreated;
}

bool CSetting::setValeur(const QString &section, const QString &key, const QString &value) {
    if (!fileOpen) return false;
    if (section.isEmpty() || key.isEmpty() || value.isEmpty()) return false;
    settings->setValue(section + "/" + key, value);
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
