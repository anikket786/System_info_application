#include "sysinfo.h"
#include <QtGlobal>

#ifdef Q_OS_WIN
    #include <sysinfowindosimpl.h>
#elif defined(Q_OS_MAC)
    #include <sysinfomacimpl.h>
#elif defined(Q_OS_LINUX)
    #include <sysinfolinuximpl.h>
#endif

SysInfo::SysInfo(){}

SysInfo& sysInfo::instance(){
    #ifdef Q_OS_WIN
        static SysInfoWindowsImpl sigleton;
    #elif defined(Q_OS_MAC)
        static SysInfoMacImpl siglton;
    #elif defined(Q_OS_LINUX)
        static SysInfoLinuxImpl sigleton;
    #endif
    return singleton;
}

SysInfo::~SysInfo(){}
