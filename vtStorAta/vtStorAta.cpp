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
#include "vtStorAta.h"
#include "DriveEnumeratorAta.h"

using namespace vtStor;

namespace vtStor
{

U32 cAta::s_DefaultCommandHandlerCommandType = 0;

}

void vtStorAtaInit(std::shared_ptr<vtStor::cDriveEnumeratorInterface>& DriveEnumerator)
{
    DriveEnumerator = std::make_unique<vtStor::cDriveEnumeratorAta>();
}