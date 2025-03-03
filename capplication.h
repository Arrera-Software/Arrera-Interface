#ifndef CAPPLICATION_H
#define CAPPLICATION_H
#include "cainterfacesetting.h"
#include "cdetectionos.h"  // Ajoutez cette ligne pour inclure la classe CDetectionOS
#include <QPushButton>
#include <QDesktopServices>
#include <QProcess>
#include <QUrl>  // Ajoutez cette inclusion pour QUrl

class CApplication
{
protected:
    CAInterfaceSetting* objPara;
    QPushButton* button;
    CDetectionOS* objOs;
    QIcon* iconApp;
    QString exeApp,nameApp;
    bool appSetted;
    int nbApp;
public:
    CApplication();
    CApplication(int PnbApp, CAInterfaceSetting* pSetting, QPushButton* pButton, CDetectionOS* pOS);
    virtual ~CApplication();  // Ajoutez le mot-clé 'virtual'
    virtual bool loadData();  // Vous devez implémenter cette méthode
    bool executeApplication();
    bool getAppSetted();
};

#endif // CAPPLICATION_H
