/*
 * Copyright (C) 2012-2013, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 *
 */

#include "stdafx.h"
#include <io.h>
#include <fcntl.h> 
#include <iostream>
#include "FslConsole.h"
#include "CommonDef.h"

#include "../MfgToolLib/MfgToolLib_Export.h"

using namespace std;

CFSLConsole *g_pConsole = NULL;

IMPLEMENT_DYNCREATE(CFSLConsole, CWinThread)

CFSLConsole::CFSLConsole()
{
	m_bAutoDelete = FALSE; //Don't destroy the object at thread termination
}

CFSLConsole::~CFSLConsole()
{
}

BOOL CFSLConsole::CreateConsole()
{
	BOOL bret = AllocConsole();
	if(bret)
	{
		*stdin  = *( _fdopen(_open_osfhandle((intptr_t)::GetStdHandle(STD_INPUT_HANDLE), _O_TEXT), "r"));  
		*stdout = *( _fdopen(_open_osfhandle((intptr_t)::GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT), "wt"));  
		ios_base::sync_with_stdio(); 
	}

	return bret;
}

void CFSLConsole::DeleteConsole()
{
	FreeConsole();
}

BOOL CFSLConsole::Open()
{
	m_hThreadStartEvent = ::CreateEvent(NULL, FALSE, FALSE, NULL);
	if(m_hThreadStartEvent == NULL)
	{
		CString strMsg;
		strMsg.Format(_T("CFSLConsole::Open---Create m_hThreadStartEvent error"));
		OutputToConsole(strMsg);
		return FALSE;
	}

	if( CreateThread() != 0 )
	{
		::WaitForSingleObject(m_hThreadStartEvent, INFINITE);
	}
	else
	{
		::CloseHandle(m_hThreadStartEvent);
		return FALSE;
	}
	::CloseHandle(m_hThreadStartEvent);
	m_hThreadStartEvent = NULL;

	return TRUE;
}

void CFSLConsole::Close()
{
}

BOOL CFSLConsole::InitInstance()
{
	SetEvent(m_hThreadStartEvent);

	return TRUE;
}

BEGIN_MESSAGE_MAP(CFSLConsole, CWinThread)
    ON_THREAD_MESSAGE(UM_MODIFY_LINE, OnModifySpecifiedLine)
END_MESSAGE_MAP()

void CFSLConsole::OnModifySpecifiedLine(WPARAM MsgPos, LPARAM szMsg)
{
	MSG_CURSOR_POSITION *pMsgPos = (MSG_CURSOR_POSITION *)MsgPos;
	CString strMsgNew = (LPCTSTR)szMsg;
	SysFreeString((BSTR)szMsg);

	GoToXY(pMsgPos->x, pMsgPos->y);

	CString strSpaces = _T("");
	for(int i=0; i<pMsgPos->length; i++)
	{
		strSpaces += _T(" ");
	}
	_tprintf(_T("%s"), strSpaces);
	_tprintf(_T("\r"));

	_tprintf(_T("%s"), strMsgNew);

	pMsgPos->length = strMsgNew.GetLength();
}
