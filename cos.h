#ifndef COS_H
#define COS_H

class COS
{
private :
    bool ewindows;
    bool elinux;
public :
    COS();
    ~COS();
    bool getWindows();
    bool getLinux();
};
#endif // COS_H
