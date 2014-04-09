/*
 * Copyright (C) 2012-2013, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 *
 */

class CFSLConsole : public CWinThread
{
	DECLARE_DYNCREATE(CFSLConsole)

public:
	CFSLConsole();
	virtual ~CFSLConsole();

	BOOL Open();
	void Close();

	virtual BOOL InitInstance();

	BOOL CreateConsole();
	void DeleteConsole();

	afx_msg void OnModifySpecifiedLine(WPARAM MsgPos, LPARAM szMsg);
	DECLARE_MESSAGE_MAP()

public:
	HANDLE m_hThreadStartEvent;
};

extern CFSLConsole *g_pConsole;
