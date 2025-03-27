#ifndef CALIEU_H
#define CALIEU_H

#include "camodelieu.h"
#include <QPushButton>

class CALieu : public CAModeLieu
{
private :
    QPushButton *btnSix, *btnRyley, *btnCopilote;
public:
    CALieu();
    CALieu(QString pname,CSetting *psetting,QPushButton *pbtnSix,QPushButton *pbtnRyley,QPushButton *pbtnCopilote);
    QString getLieuGeographique();
    bool setLieuGeographique(QString lieu);
    bool resetLieu();
    bool launchLieu();
    bool disableLieu();
};

#endif // CALIEU_H
