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
#include "StorageUtility.h"

namespace vtStor
{

eErrorCode GetStorageDevicePaths( std::vector<String>& Paths, eOnErrorBehavior OnErrorBehavior )
{
    return( GetDevicePaths( Paths, &GUID_DEVINTERFACE_DISK, OnErrorBehavior ) );
}

eErrorCode GetDevicePaths( std::vector<String>& Paths, const GUID* InterfaceClassGUID, eOnErrorBehavior OnErrorBehavior )
{
    eErrorCode error = eErrorCode::None;

    sEnumerateDevicesCallback callBack;
    callBack.Data = (void*)&Paths;
    callBack.Function = []( void* Data, const HDEVINFO& DevInfoHandle, SP_DEVINFO_DATA& DevInfoData, const PSP_INTERFACE_DEVICE_DETAIL_DATA& DevDetailData, eErrorCode& ErrorCode )
    {
        std::vector<String>* paths = ( std::vector<String>* )Data;
        paths->push_back( DevDetailData->DevicePath );
    };

    error = EnumerateDevices( callBack, InterfaceClassGUID, OnErrorBehavior );
    return( error );
}

eErrorCode EnumerateDevices( sEnumerateDevicesCallback& Callback, const GUID* InterfaceClassGUID, eOnErrorBehavior OnErrorBehavior )
{
    HDEVINFO devInfoHandle =
        SetupDiGetClassDevs
        (
        InterfaceClassGUID,
        NULL,
        NULL,
        DIGCF_PRESENT | DIGCF_DEVICEINTERFACE
        );
    if ( INVALID_HANDLE_VALUE == devInfoHandle )
    {
        return( eErrorCode::Unknown );
    }

    DWORD error = 0;
    DWORD memberIndex = 0;
    while ( true == true )
    {
        SP_DEVICE_INTERFACE_DATA devInterfaceData;
        devInterfaceData.cbSize = sizeof( devInterfaceData );
        if ( SetupDiEnumDeviceInterfaces( devInfoHandle, NULL, InterfaceClassGUID, memberIndex++, &devInterfaceData ) == FALSE )
        {
            error = GetLastError();
            if ( ERROR_NO_MORE_ITEMS == error )
            {
                break;
            }
            else
            {
                SetupDiDestroyDeviceInfoList( devInfoHandle );
                return( eErrorCode::Unknown );
            }
        }

        DWORD bufferSize = 0;
        SP_DEVINFO_DATA devInfoData;
        devInfoData.cbSize = sizeof( devInfoData );

        // Get buffer size
        if ( SetupDiGetDeviceInterfaceDetail( devInfoHandle, &devInterfaceData, NULL, 0, &bufferSize, &devInfoData ) == FALSE )
        {
            error = GetLastError();
            if ( ERROR_INSUFFICIENT_BUFFER != error )
            {
                if ( eOnErrorBehavior::Continue == OnErrorBehavior ) { continue; }
                SetupDiDestroyDeviceInfoList( devInfoHandle );
                return( eErrorCode::Unknown );
            }
        }

        PSP_INTERFACE_DEVICE_DETAIL_DATA pDevDetailData = (PSP_INTERFACE_DEVICE_DETAIL_DATA)LocalAlloc( LPTR, bufferSize );
        if ( NULL == pDevDetailData )
        {
            if ( eOnErrorBehavior::Continue == OnErrorBehavior ) { continue; }
            SetupDiDestroyDeviceInfoList( devInfoHandle );
            return( eErrorCode::Memory );
        }
        pDevDetailData->cbSize = sizeof( SP_INTERFACE_DEVICE_DETAIL_DATA );

        if ( SetupDiGetDeviceInterfaceDetail( devInfoHandle, &devInterfaceData, pDevDetailData, bufferSize, NULL, NULL ) == FALSE )
        {
            error = GetLastError();
            if ( ERROR_INSUFFICIENT_BUFFER != error )
            {
                LocalFree( pDevDetailData );
                if ( eOnErrorBehavior::Continue == OnErrorBehavior ) { continue; }
                SetupDiDestroyDeviceInfoList( devInfoHandle );
                return( eErrorCode::Unknown );
            }
        }

        eErrorCode errorCode;
        errorCode = eErrorCode::Unknown;
        Callback.Function( Callback.Data, devInfoHandle, devInfoData, pDevDetailData, errorCode );

        LocalFree( pDevDetailData );
    }

    SetupDiDestroyDeviceInfoList( devInfoHandle );

    return( eErrorCode::None );
}

eErrorCode GetStorageDeviceHandle( const String& DevicePath, HANDLE& Handle )
{
    Handle =
        CreateFile(
                    DevicePath.c_str(),
                    GENERIC_READ | GENERIC_WRITE,
                    FILE_SHARE_READ | FILE_SHARE_WRITE,
                    NULL,
                    OPEN_EXISTING,
                    FILE_ATTRIBUTE_NORMAL,
                    NULL
                    );

    if ( INVALID_HANDLE_VALUE == Handle )
    {
        return( eErrorCode::Io );
    }

    return( eErrorCode::None );
}

eErrorCode GetStorageAdapterProperty( HANDLE Handle, sStorageAdapterProperty& AdapterProperty )
{
    STORAGE_DESCRIPTOR_HEADER storageDescHeader;

    STORAGE_PROPERTY_QUERY StorageProperty;
    StorageProperty.PropertyId = StorageAdapterProperty;
    StorageProperty.QueryType = PropertyStandardQuery;

    DWORD bytesReturned;
    DWORD ret =
        DeviceIoControl(
                        Handle,
                        IOCTL_STORAGE_QUERY_PROPERTY,
                        &StorageProperty,
                        sizeof(STORAGE_PROPERTY_QUERY),
                        &storageDescHeader,
                        sizeof(STORAGE_DESCRIPTOR_HEADER),
                        &bytesReturned,
                        NULL
                        );
    if ( 0 == ret )
    {
        return( eErrorCode::Io );
    }

    if ( 0 == storageDescHeader.Size )
    {
        return( eErrorCode::Io );   //TODO: replace with more descriptive error
    }

    PSTORAGE_ADAPTER_DESCRIPTOR pstorageAdapterDesc = NULL;
    pstorageAdapterDesc = (PSTORAGE_ADAPTER_DESCRIPTOR)LocalAlloc(LPTR, storageDescHeader.Size);

    ret =
        DeviceIoControl(
                        Handle,
                        IOCTL_STORAGE_QUERY_PROPERTY,
                        &StorageProperty,
                        sizeof(STORAGE_PROPERTY_QUERY),
                        pstorageAdapterDesc,
                        storageDescHeader.Size,
                        &bytesReturned,
                        NULL
                        );
    if (0 == ret)
    {
        LocalFree( pstorageAdapterDesc );
        return( eErrorCode::Io );
    }

    AdapterProperty.BusType = pstorageAdapterDesc->BusType;
    //iAdapterProperty.SrbType = pstorageAdapterDesc->SrbType;  TODO check this
    AdapterProperty.AlignmentMask = pstorageAdapterDesc->AlignmentMask;

    LocalFree( pstorageAdapterDesc );

    return( eErrorCode::None );
}

bool IsAtaDeviceBus( sStorageAdapterProperty StorageDeviceProperty )
{
    bool successFlag = false;
    switch ( StorageDeviceProperty.BusType )
    {
    case BusTypeAta:
    case BusTypeSata:
    {
        successFlag = true;
    } break;

    default:
    {
    } break;
    }

    return successFlag;
}

}