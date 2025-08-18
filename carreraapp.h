#ifndef CARRERAAPP_H
#define CARRERAAPP_H
#include "cainterfacesetting.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QStandardPaths>
#include <QDesktopServices>
#include <QProcess>
#include <QPushButton>
#include <QtCore>
#include "cjsonword.h"
#include "cdetectionos.h"

// Debug

#include <iostream>
using namespace std;

static inline QString canonical(const QString &p) {
    QFileInfo fi(p);
    const QString c = fi.canonicalFilePath();
    return c.isEmpty() ? fi.absoluteFilePath() : c;
}


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
    QString setBatWindows(QString emplacement);
public:
    CArreraApp();
    CArreraApp(CAInterfaceSetting* p,CDetectionOS *os,QWidget *pw);
    bool loadJson();
    bool setEmplacementTiger();
    bool openStore();
    bool loadApp(QString nameApp ,QPushButton* button);
    bool loadAppMacOS();
    bool executeApp(QString nameApp);
};

#endif // CARRERAAPP_H
