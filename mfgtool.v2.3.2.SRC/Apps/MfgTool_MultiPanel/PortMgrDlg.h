/*
 * Copyright (C) 2012-2013, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 *
 */

#pragma once

#include "afxwin.h"
#include "afxcmn.h"

#include "ExProgressCtrl.h"
#include "../MfgToolLib/MfgToolLib_Export.h"

//Progress color
#define PROGRESS_RGB_BLUE	RGB(9,106,204)
#define PROGRESS_RGB_GREEN	RGB(78,217,11)
#define PROGRESS_RGB_RED	RGB(255,0,0)

#define PHASE_COMPLETE_POSITION		0x7FFFFFFF


// CPortMgrDlg dialog

class CPortMgrDlg : public CDialog
{
	DECLARE_DYNAMIC(CPortMgrDlg)

public:
	CPortMgrDlg(CWnd* pParent = NULL, int index = 0);   // standard constructor
	virtual ~CPortMgrDlg();

// Dialog Data
	enum { IDD = IDD_PORT_DLG };

private:
	int m_Index;
	BOOL m_bDeviceConnected;

public:
	int GetIndex() const
	{
		return m_Index;
	}

	BOOL IsDeviceConnected() const
	{
		return m_bDeviceConnected;
	}

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg LRESULT OnPortDlgMsgFun(WPARAM wEvent, LPARAM lParam);
	afx_msg LRESULT OnDeviceChangeNotify(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnUpdateUIInfo(WPARAM wParam, LPARAM lParam);
	CEdit m_port_status_ctrl;
	CExProgressCtrl m_port_progress_ctrl;
	CExProgressCtrl m_port_task_progress_ctrl;
	int m_PreviousCommandsIndex;
protected:
	virtual void PostNcDestroy();
public:
	CExProgressCtrl m_port_phase_progress_ctrl;
	afx_msg void OnPaint();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

extern void gDeviceChangeNotify(DEVICE_CHANGE_NOTIFY *pnsinfo);
extern void gProgressUpdate(OPERATE_RESULT *puiInfo);
