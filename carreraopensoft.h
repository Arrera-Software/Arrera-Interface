#ifndef CARRERAOPENSOFT_H
#define CARRERAOPENSOFT_H
#include "carreratigerinteg.h"
#include "cos.h"
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>
#include <QDebug>

#define NAMELNKSIXWIN "Six.lnk"
#define NAMELNKRYLEYWIN "Ryley.lnk"
#define NAMELNKPARASIXWIN "sixPara.lnk"
#define NAMELNKPARARYLEYWIN "ryleyPara.lnk"

#define NAMERYLEYSH "ryley.sh"
#define NAMESIXSH "six.sh"
#define NAMERYLEYPARASH "ryleyPara.sh"
#define NAMESIXPARASH "sixPara.sh"

class CArreraOpenSoft
{
private :
    CArreraSetting* objPara;
    bool objSet,linuxOS,windowsOS ;
    COS system ;
public:
    CArreraOpenSoft();
    void setObjPara(CArreraSetting* obj);
    bool openTableur();
    bool openTTexte();
    bool openNavigateur();
    bool openPresentation();
    bool openSix();
    bool openRyley();
    bool openSixPara();
    bool openRyleyPara();
    bool openAppLib(int nb);
    bool openArreraApp(int nb);
    bool openVMStart();
    bool openSoftTouchScreen();
    bool openTiger();
};

#endif // CARRERAOPENSOFT_H
