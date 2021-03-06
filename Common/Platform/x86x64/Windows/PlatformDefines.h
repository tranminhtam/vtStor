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
#ifndef __vtStorCommonPlatformDefines_h__
#define __vtStorCommonPlatformDefines_h__

#include <string>
#include <Windows.h>

#include "vtStorPlatformDefines.h"

#ifdef _UNICODE
#define    __STORAPITEXT( s ) L##s
using tchar = wchar_t;
using tstring = std::wstring;
#else
#define    __STORAPITEXT( s ) s
using tchar = char;
using tstring = std::string; 
#endif

namespace vtStor
{
    
using DeviceHandle = HANDLE;

}


#endif