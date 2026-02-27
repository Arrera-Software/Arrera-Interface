#include "cappspeciaux.h"

CAppSpeciaux::CAppSpeciaux() {}

CAppSpeciaux::CAppSpeciaux(int nbApp,CAInterfaceSetting* pSetting,QPushButton* pButton,CDetectionOS* pOS) :
    CApplication(nbApp, pSetting, pButton, pOS)
{
     // 1.Navigateur 2.Presentation 3.tableur 4.Traitement de texte
}

CAppSpeciaux::~CAppSpeciaux(){}

bool CAppSpeciaux::loadData(){
    appSetted = objPara->getAppSpeciauxSetted(nbApp);
    if (appSetted){
        exeApp = objPara->getAppSpeciaux(nbApp);
        button->setVisible(true);
        return true;
    }else{
        button->setVisible(false);
        return false;
    }
}
