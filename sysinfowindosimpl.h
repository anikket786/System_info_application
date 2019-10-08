#ifndef SYSINFOWINDOSIMPL_H
#define SYSINFOWINDOSIMPL_H

#include <QtGlobal>
#include <QVector>
#include "sysinfo.h"

typedef struct _FILETIME FILETIME;

class SysInfoWindosImpl : public SysInfo
{
public:
    SysInfoWindosImpl();
    void init() override;
    double cpuLoadAverage() override;
    double memoryUsed() override;

private:
    QVector<qulonglong> cpuRawData();
    qulonglong convertFileTime(const FILETIME& filetime) const;

private:
    QVector<qulonglong> mCpuLoadLastValues;
};

#endif // SYSINFOWINDOSIMPL_H
