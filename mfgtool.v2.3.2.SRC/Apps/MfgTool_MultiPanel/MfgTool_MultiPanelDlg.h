/*
 * Copyright (C) 2012-2013, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 *
 */

#pragma once

#include "OpBtnDlg.h"
#include "PortMgrDlg.h"

#define SEPERATE_WIDTH		10


// CMfgTool_MultiPanelDlg dialog
class CMfgTool_MultiPanelDlg : public CDialog
{
// Construction
public:
	CMfgTool_MultiPanelDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFGTOOL_MULTIPANEL_DIALOG };

	CString m_strDefaultPath;	//exe path
	int m_PortMgrDlgNums;
	typedef CTypedPtrArray<CObArray, CPortMgrDlg*>  CPortMgrDlgArray;
	CPortMgrDlgArray m_PortMgrDlg_Array;
	COpBtnDlg m_OpBtnDlg;

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

public:
	int GetPortMgrDlgCount() const
	{
		return m_PortMgrDlgNums;
	}

private:
	void RelayoutWindows();

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	virtual void PostNcDestroy();
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnClose();
};

extern CMfgTool_MultiPanelDlg *g_pMainDlg;
