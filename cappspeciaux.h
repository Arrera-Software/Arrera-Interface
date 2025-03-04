#ifndef CAPPSPECIAUX_H
#define CAPPSPECIAUX_H

#include "capplication.h"

class CAppSpeciaux : public CApplication
{
public:
    CAppSpeciaux();
    CAppSpeciaux(int nbApp,CAInterfaceSetting* pSetting,QPushButton* pButton,CDetectionOS* pOS);
    ~CAppSpeciaux();
    bool loadData() override;
};

#endif // CAPPSPECIAUX_H
