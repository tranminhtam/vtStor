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
#ifndef __vtStorProtocolEssense_h__
#define __vtStorProtocolEssense_h__
#pragma once

#include <memory>

#include "BufferFormatter.h"
#include "vtStorPlatformDefines.h"

namespace vtStor
{
    class VTSTOR_API cProtocolEssense : public cBufferFormatter
    {

        static const size_t DEVICE_HANDLE_SIZE_IN_BYTES;

    public:
        static cProtocolEssense Reader(std::shared_ptr<const cBufferInterface> Buffer);
        static cProtocolEssense Modifier(std::shared_ptr<cBufferInterface> Buffer);

    protected:
        cProtocolEssense(std::shared_ptr<cBufferInterface> Buffer);
        cProtocolEssense(std::shared_ptr<cBufferInterface> Buffer, U32 Format);
        cProtocolEssense(std::shared_ptr<const cBufferInterface> Buffer);

    public:
        DeviceHandle& GetDeviceHandle();
        const DeviceHandle& GetDeviceHandle() const;

    protected:
        static const size_t DEVICE_HANDLE_OFFSET;
    };
}

#endif
