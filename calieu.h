#ifndef CALIEU_H
#define CALIEU_H

#include "camodelieu.h"

class CALieu : public CAModeLieu
{
public:
    CALieu();
    CALieu(QString pname,CSetting *psetting);
    QString getLieuGeographique();
    bool setLieuGeographique(QString lieu);
};

#endif // CALIEU_H
