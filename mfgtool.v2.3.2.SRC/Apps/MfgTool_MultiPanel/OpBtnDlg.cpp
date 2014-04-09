/*
 * Copyright (C) 2012-2013, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 *
 */

// OpBtnDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MfgTool_MultiPanel.h"
#include "OpBtnDlg.h"

#include "../MfgToolLib/MfgToolLib_Export.h"
#include "CommonDef.h"
#include "MfgTool_MultiPanelDlg.h"


// COpBtnDlg dialog

IMPLEMENT_DYNAMIC(COpBtnDlg, CDialog)

COpBtnDlg::COpBtnDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COpBtnDlg::IDD, pParent)
{

}

COpBtnDlg::~COpBtnDlg()
{
}

void COpBtnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(COpBtnDlg, CDialog)
	ON_BN_CLICKED(IDC_BTN_EXIT, &COpBtnDlg::OnBnClickedBtnExit)
	ON_BN_CLICKED(ID_START_STOP_TOGGLE, &COpBtnDlg::OnBnClickedStartStopToggle)
END_MESSAGE_MAP()


// COpBtnDlg message handlers

BOOL COpBtnDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	// first disable Start/Stop button
	m_bRunning = FALSE;

	GetDlgItem(IDC_STATUS_OK_UPDATES)->SetWindowText(_T("0"));
	GetDlgItem(IDC_STATUS_FAILED_UPDATES)->SetWindowText(_T("0"));
	CString strMsg;
	strMsg.Format(_T("%d %%"), 0);
	GetDlgItem(IDC_STATUS_FAILURE_RATE)->SetWindowText(strMsg);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void COpBtnDlg::OnBnClickedBtnExit()
{
	// TODO: Add your control notification handler code here
	if(m_bRunning)
	{
		AfxMessageBox(_T("Please press <Stop> and allow all operations to finish before exiting the program."));
		return;
	}
	g_pMainDlg->DestroyWindow();
}

void COpBtnDlg::OnBnClickedStartStopToggle()
{
	// TODO: Add your control notification handler code here
	if(m_bRunning)
	{	// wanna stop
		for(int i=0; i<theApp.m_PortMgr_Array.GetSize(); i++)
		{
			CPortMgr *pPortMgr = theApp.m_PortMgr_Array.GetAt(i);
			pPortMgr->StopDownload();
		}
		(GetDlgItem(ID_START_STOP_TOGGLE))->SetWindowText(_T("Start"));
	}
	else
	{	// wanna start
		for(int i=0; i<theApp.m_PortMgr_Array.GetSize(); i++)
		{
			CPortMgr *pPortMgr = theApp.m_PortMgr_Array.GetAt(i);
			pPortMgr->StartDownload();
		}
		(GetDlgItem(ID_START_STOP_TOGGLE))->SetWindowText(_T("Stop"));
	}

	m_bRunning = !m_bRunning;
}

BOOL COpBtnDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message == WM_KEYDOWN) 
	{
		switch(pMsg->wParam)  
		{  
		case VK_RETURN: 
			return true;  
		case VK_ESCAPE:
			return true;  
		}
	}

	return CDialog::PreTranslateMessage(pMsg);
}
