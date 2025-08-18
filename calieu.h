#ifndef CALIEU_H
#define CALIEU_H

#include "camodelieu.h"
#include <QPushButton>
// Debug
/*
#include <iostream>
using namespace std;
*/


class CALieu : public CAModeLieu
{
public:
    CALieu();
    CALieu(QString pname,CSetting *psetting);
    QString getLieuGeographique();
    bool setLieuGeographique(QString lieu);
    bool resetLieu();
    bool launchLieu(QPushButton* btnSix ,QPushButton* btnCopilote,QPushButton* btnRyley);
    bool disableLieu();
};

#endif // CALIEU_H
