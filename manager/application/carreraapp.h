#ifndef CARRERAAPP_H
#define CARRERAAPP_H
#include <QFileDialog>
#include <QStandardPaths>
#include <QDesktopServices>
#include <QProcess>
#include <QPushButton>
#include <QtCore>

// Debug
/*
#include <iostream>
using namespace std;
*/

class CArreraApp {
private :
    bool hub_config_file_init;
    QString hub_config_file;
    QSettings* hub_settings;
    bool exectute(QString app);
public:
    CArreraApp();
    bool load_hub_config_file();
    bool open_arrera_hub();
    bool load_arrera_application(QString nameApp ,QPushButton* button);
};

#endif // CARRERAAPP_H
