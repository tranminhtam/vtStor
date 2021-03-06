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

#ifndef __vtStorDriveAtaCommandExtensionManaged_h__
#define __vtStorDriveAtaCommandExtensionManaged_h__
#pragma once

#include "DriveAtaCommandExtensions.h"

namespace vtStor
{
    namespace Ata
    {
        namespace Managed
        {
            public ref class cDriveAtaCommandExtensions
            {
            public:
                static vtStor::Managed::eErrorCode IssueCommand_IdentifyDevice(vtStor::Managed::cDriveInterface^ Drive, U32 CommandType, vtStor::Managed::cBufferInterface^ Data);

                static vtStor::Managed::eErrorCode IssueCommand_ReadDma(vtStor::Managed::cDriveInterface^ Drive, U32 CommandType, vtStor::Managed::cBufferInterface^ Data, U32 Lba, U8 Count);

                static vtStor::Managed::eErrorCode IssueCommand_WriteDma(vtStor::Managed::cDriveInterface^ Drive, U32 CommandType, vtStor::Managed::cBufferInterface^ Data, U32 Lba, U8 Count);

                static vtStor::Managed::eErrorCode IssueCommand_ReadBuffer(vtStor::Managed::cDriveInterface^ Drive, U32 CommandType, vtStor::Managed::cBufferInterface^ Data);

                static vtStor::Managed::eErrorCode IssueCommand_WriteBuffer(vtStor::Managed::cDriveInterface^ Drive, U32 CommandType, vtStor::Managed::cBufferInterface^ Data);

                static vtStor::Managed::eErrorCode IssueCommand_Smart(vtStor::Managed::cDriveInterface^ Drive, U32 CommandType, vtStor::Managed::cBufferInterface^ Data, U8 SubCommand);

                static vtStor::Managed::eErrorCode IssueCommand_DownloadMicrocode(vtStor::Managed::cDriveInterface^ Drive, U32 CommandType, vtStor::Managed::cBufferInterface^ Data, U8 SubCommand, U16 BlockCount, U16 BufferOffset);

                static vtStor::Managed::eErrorCode IssueCommand_DownloadMicrocodeDma(vtStor::Managed::cDriveInterface^ Drive, U32 CommandType, vtStor::Managed::cBufferInterface^ Data, U8 SubCommand, U16 BlockCount, U16 BufferOffset);
            };
        }
    }
}

#endif