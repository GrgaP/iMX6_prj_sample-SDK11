/*
 * Copyright (C) 2012-2013, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 *
 */

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include "PortMgr.h"
#include "../MfgToolLib/MfgToolLib_Export.h"
#include <map>

// CMfgTool_MultiPanelApp:
// See MfgTool_MultiPanel.cpp for the implementation of this class
//

class CMfgTool_MultiPanelApp : public CWinAppEx
{
public:
	CMfgTool_MultiPanelApp();

// Overrides
public:
	virtual BOOL InitInstance();

//	BOOL FirstInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();

	BOOL ParseMyCommandLine(CString strCmdLine);

public:
	typedef CTypedPtrArray<CObArray, CPortMgr*>  CPortMgrArray;
	CPortMgrArray m_PortMgr_Array;

	CString m_strProfileName;
	CString m_strListName;
	std::map<CString, CString> m_uclKeywords;
	BOOL ParseCfgFile(CString strFilename, BOOL bMsgBox);
	BOOL IsSectionExist(CString strSection, CString strFilename);

	OPERATIONS_INFORMATION m_OperationsInformation;
	PHASES_INFORMATION m_PhasesInformation;

	//UINT GetStateCommandSize(MX_DEVICE_STATE devState);
	UINT GetStateCommandSize(int index);

	INSTANCE_HANDLE m_pLibHandle;

	int FindDeviceIndex(DWORD operationID);
};

extern CMfgTool_MultiPanelApp theApp;

extern void gDeviceChangeNotify(DEVICE_CHANGE_NOTIFY *pnsinfo);
extern void gProgressUpdate(OPERATE_RESULT *puiInfo);
