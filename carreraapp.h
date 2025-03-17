#ifndef CARRERAAPP_H
#define CARRERAAPP_H
#include "cainterfacesetting.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QStandardPaths>
#include <QDesktopServices>
#include <QProcess>

class CArreraApp
{
private :
    CJSONWORD jsonFile;
    CAInterfaceSetting* psetting;
    CDetectionOS* dectOS;
    QWidget *widget;
    bool tigerFileSetted;
    QString tigerFile;
    bool exectute(QString app,bool appSetted);
public:
    CArreraApp();
    CArreraApp(CAInterfaceSetting* p,CDetectionOS *os,QWidget *pw);
    bool setEmplacementTiger();
    bool openStore();
};

#endif // CARRERAAPP_H
