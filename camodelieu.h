#ifndef CAMODELIEU_H
#define CAMODELIEU_H
#include <QString>
#include <csetting.h>

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
    bool setNameView(QString pname);
    bool setAssistant(QString assistant);
    bool isSeted();
};

#endif // CAMODELIEU_H
