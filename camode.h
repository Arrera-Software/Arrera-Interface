#ifndef CAMODE_H
#define CAMODE_H

#include "camodelieu.h"
// Debug
/*
#include <iostream>
using namespace std;
*/


class CAMode : public CAModeLieu
{
public:
    CAMode();
    CAMode(QString pname,CSetting *psetting);
    QString getApp1();
    QString getApp2();
    QString getApp3();
    QString getApp4();
    bool setApp1(QString app);
    bool setApp2(QString app);
    bool setApp3(QString app);
    bool setApp4(QString app);
    bool resetMode();
};

#endif // CAMODE_H
