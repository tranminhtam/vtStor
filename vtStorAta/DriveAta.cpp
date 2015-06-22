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
#include "DriveAta.h"

namespace vtStor
{

cDriveAta::cDriveAta(std::shared_ptr<String> DevicePath) :
    cDrive(DevicePath)
{

}

cDriveAta::~cDriveAta()
{

}

eErrorCode cDriveAta::IssueCommand(U32 CommandType, std::shared_ptr<const cBufferInterface> CommandDescriptor, std::shared_ptr<cBufferInterface> Data)
{
    // set Device handle to Command descriptor and call parent->IssueCommand()
    DeviceHandle& deviceHandle = ((Ata::cCommandDescriptor1)CommandDescriptor).GetDeviceHandle();
    deviceHandle = m_DeviceHandle;

    eErrorCode errorCode = cDrive::IssueCommand(CommandType, CommandDescriptor, Data);

    return( errorCode );
}

}