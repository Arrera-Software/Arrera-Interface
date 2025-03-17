#ifndef CARRERAAPP_H
#define CARRERAAPP_H
#include "cainterfacesetting.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QStandardPaths>
#include <QDesktopServices>
#include <QProcess>
#include <QPushButton>

class CArreraApp
{
private :
    CJSONWORD* jsonFile;
    CAInterfaceSetting* psetting;
    CDetectionOS* dectOS;
    QWidget *widget;
    bool tigerFileSetted;
    QString tigerFile;
    bool exectute(QString app,bool appSetted);
    bool setBatWindows(QString emplacement);
public:
    CArreraApp();
    CArreraApp(CAInterfaceSetting* p,CDetectionOS *os,QWidget *pw);
    bool loadJson();
    bool setEmplacementTiger();
    bool openStore();
    bool loadApp(QString nameApp ,QPushButton* button);
    bool executeApp(QString nameApp);
};

#endif // CARRERAAPP_H
