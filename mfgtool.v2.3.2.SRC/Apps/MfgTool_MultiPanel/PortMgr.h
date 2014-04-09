/*
 * Copyright (C) 2012-2013, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 *
 */

#pragma once

#include "../MfgToolLib/MfgToolLib_Export.h"
#include "CommonDef.h"

class CPortMgr : public CWinThread
{
public:
	CPortMgr(int id);
	virtual ~CPortMgr();

	virtual BOOL InitInstance();
	virtual int ExitInstance();

	BOOL Open();
	void Close();

	void StartDownload();
	void StopDownload();

	TCHAR* GetCurrentDeviceDesc();

public:
	typedef struct
	{
		CString Hub;
		int HubIndex;
		int PortIndex;
		CString DeviceDesc;
		TCHAR DriverLetter;
		BOOL bDeviceConnected;
		MX_DEVICE_CHANGE_EVENT Event;
	}DEV_CHG_NOTIFY;

	int m_Index;
	UINT m_AllCmdSize;
	UINT m_AllPhaseNumbers;

	HANDLE m_hThreadStartEvent;

	int m_PreviousPhaseIndex;
};

