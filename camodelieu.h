#ifndef CAMODELIEU_H
#define CAMODELIEU_H
#include <QString>
#include <csetting.h>
// Debug
/*
#include <iostream>
using namespace std;
*/


class CAModeLieu
{
protected:
    QString name ;
    QString nameView ;
    QString assistant;
    CSetting *objSetting;
public:
    CAModeLieu();
    CAModeLieu(QString pname,CSetting *psetting);
    ~CAModeLieu();
    QString getNameView();
    QString getAssistant();
    QString getIcon();
    bool setNameView(QString pname);
    bool setAssistant(QString assistant);
    bool isSeted();
    bool setIcon(QString icon);
};

#endif // CAMODELIEU_H
