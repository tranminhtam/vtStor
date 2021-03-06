/*
<License>
Copyright 2015 Virtium Technology

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http ://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
</License>
*/

#ifndef __vtStorDriveManagerInterfaceManaged_h__
#define __vtStorDriveManagerInterfaceManaged_h__
#pragma once

#include "DriveManagerInterface.h"
#include "DriveEnumeratorInterfaceManaged.h"
#include "ErrorCodesManaged.h"
#include "ScanForHardwareChangesManaged.h"
#include "UniquePtrManaged.h"

namespace vtStor
{
    namespace Managed
    {
        ref class cDriveInterface;

        public ref class cDriveManagerInterface
        {
        public:
            cDriveManagerInterface();
            ~cDriveManagerInterface();

        protected:
            !cDriveManagerInterface();

        public:
            void        RegisterDriveEnumerator( cDriveEnumeratorInterface^ DriveEnumerator );
            eErrorCode  EnumerateDrives( eScanForHardwareChanges ScanForHardwareChanges );

        public:
            U32     GetDriveCount();
            cDriveInterface^ GetDrive( U32 DriveIndex );

        private:
            cUniquePtr<vtStor::cDriveManagerInterface> m_DriveManager;
        };
    }
}

#endif