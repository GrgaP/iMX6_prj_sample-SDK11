/*
 * Copyright (C) 2012-2013, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 *
 */

#pragma once

#include "Resource.h"

// COpBtnDlg dialog

class COpBtnDlg : public CDialog
{
	DECLARE_DYNAMIC(COpBtnDlg)

public:
	COpBtnDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~COpBtnDlg();

// Dialog Data
	enum { IDD = IDD_OP_DLG };

	BOOL m_bRunning;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnExit();
	afx_msg void OnBnClickedStartStopToggle();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
