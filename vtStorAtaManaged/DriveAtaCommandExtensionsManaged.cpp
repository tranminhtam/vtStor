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

#include <memory>

#include "DriveAtaCommandExtensionsManaged.h"

namespace vtStor
{
    namespace Ata
    {
        namespace Managed
        {
            vtStor::Managed::eErrorCode cDriveAtaCommandExtensions::IssueCommand_IdentifyDevice(vtStor::Managed::cDriveInterface^ Drive, U32 CommandType, vtStor::Managed::cBufferInterface^ Data)
            {
                vtStor::Managed::eErrorCode errorCode;
                std::shared_ptr<vtStor::cDriveInterface> spDriveInterface = cDriveInterface::ToSharedPtr(Drive);
                std::shared_ptr<vtStor::cBufferInterface> spBuffferInterface = cBufferInterface::ToSharedPtr(Data);
                errorCode = static_cast<vtStor::Managed::eErrorCode>(vtStor::Ata::IssueCommand_IdentifyDevice(spDriveInterface, CommandType, spBuffferInterface));
                return(errorCode);
            }

            vtStor::Managed::eErrorCode cDriveAtaCommandExtensions::IssueCommand_ReadDma(vtStor::Managed::cDriveInterface^ Drive, U32 CommandType, vtStor::Managed::cBufferInterface^ Data, U32 Lba, U8 Count)
            {
                vtStor::Managed::eErrorCode errorCode;
                std::shared_ptr<vtStor::cDriveInterface> spDriveInterface = cDriveInterface::ToSharedPtr(Drive);
                std::shared_ptr<vtStor::cBufferInterface> spBuffferInterface = cBufferInterface::ToSharedPtr(Data);
                errorCode = static_cast<vtStor::Managed::eErrorCode>(vtStor::Ata::IssueCommand_ReadDma(spDriveInterface, CommandType, spBuffferInterface, Lba, Count));
                return(errorCode);
            }

            vtStor::Managed::eErrorCode cDriveAtaCommandExtensions::IssueCommand_WriteDma(vtStor::Managed::cDriveInterface^ Drive, U32 CommandType, vtStor::Managed::cBufferInterface^ Data, U32 Lba, U8 Count)
            {
                vtStor::Managed::eErrorCode errorCode;
                std::shared_ptr<vtStor::cDriveInterface> spDriveInterface = cDriveInterface::ToSharedPtr(Drive);
                std::shared_ptr<vtStor::cBufferInterface> spBuffferInterface = cBufferInterface::ToSharedPtr(Data);
                errorCode = static_cast<vtStor::Managed::eErrorCode>(vtStor::Ata::IssueCommand_WriteDma(spDriveInterface, CommandType, spBuffferInterface, Lba, Count));
                return(errorCode);
            }

            vtStor::Managed::eErrorCode cDriveAtaCommandExtensions::IssueCommand_ReadBuffer(vtStor::Managed::cDriveInterface^ Drive, U32 CommandType, vtStor::Managed::cBufferInterface^ Data)
            {
                vtStor::Managed::eErrorCode errorCode;
                std::shared_ptr<vtStor::cDriveInterface> spDriveInterface = cDriveInterface::ToSharedPtr(Drive);
                std::shared_ptr<vtStor::cBufferInterface> spBuffferInterface = cBufferInterface::ToSharedPtr(Data);
                errorCode = static_cast<vtStor::Managed::eErrorCode>(vtStor::Ata::IssueCommand_ReadBuffer(spDriveInterface, CommandType, spBuffferInterface));
                return(errorCode);
            }

            vtStor::Managed::eErrorCode cDriveAtaCommandExtensions::IssueCommand_WriteBuffer(vtStor::Managed::cDriveInterface^ Drive, U32 CommandType, vtStor::Managed::cBufferInterface^ Data)
            {
                vtStor::Managed::eErrorCode errorCode;
                std::shared_ptr<vtStor::cDriveInterface> spDriveInterface = cDriveInterface::ToSharedPtr(Drive);
                std::shared_ptr<vtStor::cBufferInterface> spBuffferInterface = cBufferInterface::ToSharedPtr(Data);
                errorCode = static_cast<vtStor::Managed::eErrorCode>(vtStor::Ata::IssueCommand_WriteBuffer(spDriveInterface, CommandType, spBuffferInterface));
                return(errorCode);
            }

            vtStor::Managed::eErrorCode cDriveAtaCommandExtensions::IssueCommand_Smart(vtStor::Managed::cDriveInterface^ Drive, U32 CommandType, vtStor::Managed::cBufferInterface^ Data, U8 SubCommand)
            {
                vtStor::Managed::eErrorCode errorCode;
                std::shared_ptr<vtStor::cDriveInterface> spDriveInterface = cDriveInterface::ToSharedPtr(Drive);
                std::shared_ptr<vtStor::cBufferInterface> spBuffferInterface = cBufferInterface::ToSharedPtr(Data);
                errorCode = static_cast<vtStor::Managed::eErrorCode>(vtStor::Ata::IssueCommand_Smart(spDriveInterface, CommandType, spBuffferInterface, SubCommand));
                return(errorCode);
            }

            vtStor::Managed::eErrorCode cDriveAtaCommandExtensions::IssueCommand_DownloadMicrocode(vtStor::Managed::cDriveInterface^ Drive, U32 CommandType, vtStor::Managed::cBufferInterface^ Data, U8 SubCommand, U16 BlockCount, U16 BufferOffset)
            {
                vtStor::Managed::eErrorCode errorCode;
                std::shared_ptr<vtStor::cDriveInterface> spDriveInterface = cDriveInterface::ToSharedPtr(Drive);
                std::shared_ptr<vtStor::cBufferInterface> spBuffferInterface = cBufferInterface::ToSharedPtr(Data);
                errorCode = static_cast<vtStor::Managed::eErrorCode>(vtStor::Ata::IssueCommand_DownloadMicrocode(spDriveInterface, CommandType, spBuffferInterface, SubCommand, BlockCount, BufferOffset));
                return(errorCode);
            }

            vtStor::Managed::eErrorCode cDriveAtaCommandExtensions::IssueCommand_DownloadMicrocodeDma(vtStor::Managed::cDriveInterface^ Drive, U32 CommandType, vtStor::Managed::cBufferInterface^ Data, U8 SubCommand, U16 BlockCount, U16 BufferOffset)
            {
                vtStor::Managed::eErrorCode errorCode;
                std::shared_ptr<vtStor::cDriveInterface> spDriveInterface = cDriveInterface::ToSharedPtr(Drive);
                std::shared_ptr<vtStor::cBufferInterface> spBuffferInterface = cBufferInterface::ToSharedPtr(Data);
                errorCode = static_cast<vtStor::Managed::eErrorCode>(vtStor::Ata::IssueCommand_DownloadMicrocodeDma(spDriveInterface, CommandType, spBuffferInterface, SubCommand, BlockCount, BufferOffset));
                return(errorCode);
            }
        }
    }

}