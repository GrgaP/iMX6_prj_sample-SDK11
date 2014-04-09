/*
 * Copyright (C) 2009-2013, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 *
 */

#include "stdafx.h"
#include "HidDeviceClass.h"
#include "HidDevice.h"
#include <hidclass.h>

HidDeviceClass::HidDeviceClass(INSTANCE_HANDLE handle)
: DeviceClass(&GUID_DEVINTERFACE_HID, &GUID_DEVCLASS_HIDCLASS, _T("HID"), DeviceTypeHid, handle)
{
}

HidDeviceClass::~HidDeviceClass(void)
{
}

Device* HidDeviceClass::CreateDevice(DeviceClass* deviceClass, SP_DEVINFO_DATA deviceInfoData, CString path)
{
    //Check if the path matches our device pid&vid.
    //An example of value of path: "\\?\hid#vid_413c&pid_2011&mi_01&col02#8&2598dfbd&0&0001#{4d1e55b2-f16f-11cf-88cb-001111000030}"
    return new HidDevice(deviceClass, deviceInfoData.DevInst, path, m_pLibHandle);
}
