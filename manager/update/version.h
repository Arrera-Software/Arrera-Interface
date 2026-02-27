#ifndef VERSION_H
#define VERSION_H

#include <QString>

class version{
private :
    const QString version = "I2026-1.00" ;
    const QString name = "ARRERA-INTERFACE" ;
public :
    QString getVersion(){
        return version;
    };

    QString getName(){
        return name;
    };
};

#endif // VERSION_H
