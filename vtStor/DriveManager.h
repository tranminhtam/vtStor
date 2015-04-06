//Copyright( c ) 2015 Virtium Technology
//See the file license.txt for copying permission.

#ifndef __DriveManager_h__
#define __DriveManager_h__

#include "DriveManagerInterface.h"

namespace vtStor
{

class cDriveManager : public cDriveManagerInterface
{
public:
    virtual void RegisterDriveEnumerator( std::shared_ptr<cDriveEnumeratorInterface> DriveEnumerator );

    virtual ErrorCode EnumerateDrives( eScanForHardwareChanges ScanForHardwareChanges );

public:
    virtual const Vector_Drives& GetDrives();

public:
    cDriveManager();
    virtual ~cDriveManager();

private:
    using Vector_DriveEnumerator = std::vector<std::shared_ptr<cDriveEnumeratorInterface>>;
    Vector_DriveEnumerator m_DriveEnumerators;

private:
    Vector_Drives   m_Drives;
};

}

#endif