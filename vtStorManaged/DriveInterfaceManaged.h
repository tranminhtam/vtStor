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

#ifndef __vtStorDriveInterfaceManaged_h__
#define __vtStorDriveInterfaceManaged_h__
#pragma once

#include "BufferInterfaceManaged.h"
#include "CommandHandlerInterfaceManaged.h"
#include "DriveInterface.h"
#include "SharedPtrManaged.h"

namespace vtStor
{
    namespace Managed
    {
        public ref class cDriveInterface
        {
        public:
            cDriveInterface( std::shared_ptr<vtStor::cDriveInterface> Drive );
            ~cDriveInterface();

        protected:
            !cDriveInterface();

        public:
            operator void*();

        public:
            void RegisterCommandHandler(U32 CommandType, vtStor::Managed::cCommandHandlerInterface^ CommandHandler);

            eErrorCode IssueCommand(U32 CommandType, vtStor::Managed::cBufferInterface^ CommandDescriptor, vtStor::Managed::cBufferInterface^ Data);

        private:
            cSharedPtr<vtStor::cDriveInterface> m_Drive;
        };
    }
}

#endif