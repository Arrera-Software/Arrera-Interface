#ifndef CARRERAOPENSOFT_H
#define CARRERAOPENSOFT_H
#include "carrerasetting.h"
#include "cos.h"
#include <QDesktopServices>
#include <QUrl>

#define NAMELNKSIXWIN "Six.lnk"
#define NAMELNKRYLEYWIN "Ryley.lnk"

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
};

#endif // CARRERAOPENSOFT_H
