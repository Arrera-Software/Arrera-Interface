#ifndef CAPPPC_H
#define CAPPPC_H

#include "capplication.h"
// Debug
/*
#include <iostream>
using namespace std;
*/


class CAppPC : public CApplication
{
public:
    CAppPC();
    CAppPC(int nbApp,CAInterfaceSetting* pSetting,QPushButton* pButton,CDetectionOS* pOS);
    ~CAppPC();
    bool loadData() override;
    QString getIcon();
    QString getName();
};

#endif // CAPPPC_H
