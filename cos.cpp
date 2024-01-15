#include "cos.h"

COS::COS()
{
#ifdef __linux__
    elinux = true;
    ewindows = false;
#elif _WIN32
    elinux = false;
    ewindows = true;
#else
    elinux = false;
    ewindows = false;
#endif
}

COS::~COS()
{

}

bool COS::getLinux()
{
    return elinux;
}

bool  COS::getWindows()
{
    return ewindows;
}
