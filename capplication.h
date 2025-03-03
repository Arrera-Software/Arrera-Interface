#ifndef CAPPLICATION_H
#define CAPPLICATION_H
#include "cainterfacesetting.h"
#include <QPushButton>
#include <QDesktopServices>
#include <QProcess>

class CApplication
{
protected:
    CAInterfaceSetting* objPara;
    QPushButton* button;
    CDetectionOS* objOs;
    QIcon iconApp;
    QString exeApp,nameApp;
    bool appSetted;
public:
    CApplication();
    CApplication(CAInterfaceSetting* pSetting,QPushButton* pButton,CDetectionOS* pOS);
    bool virtual loadData(int nbApp);
    bool executeApplication();
};

#endif // CAPPLICATION_H
