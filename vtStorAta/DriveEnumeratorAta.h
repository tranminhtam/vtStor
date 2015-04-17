//Copyright( c ) 2015 Virtium Technology
//See the file license.txt for copying permission.

#ifndef __DriveEnumeratorAta_h__
#define __DriveEnumeratorAta_h__

#include "vtStorAtaPlatformDefines.h"
#include "DriveEnumeratorInterface.h"

namespace vtStor
{
    class VT_STOR_ATA_API cDriveEnumeratorAta : public cDriveEnumeratorInterface
    {
    public:
        virtual eErrorCode EnumerateDrives( Vector_Drives& AddToList, U32& Count ) override;

    public:
        virtual ~cDriveEnumeratorAta();
    };
}

#endif