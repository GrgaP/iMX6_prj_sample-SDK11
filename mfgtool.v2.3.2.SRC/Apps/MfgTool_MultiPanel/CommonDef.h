/*
 * Copyright (C) 2012-2013, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 *
 */

#pragma once

#include <vector>

#define UM_PORT_DLG_MSG			WM_USER+100
typedef enum PortDlgMsgEvent
{
	OP_CMD_START,
	OP_CMD_STOP
};
#define UM_PORT_DEVICE_CHANGE	WM_USER+102
#define UM_PORT_UPDATE_INFO		WM_USER+103
#define UM_OPBTN_DLG_MSG		WM_USER+101

#define UM_MODIFY_LINE			WM_USER+105

#define DEFAULT_PORT_NUMBERS	1


extern int g_totalOps;
extern int g_successOps;
extern int g_failedOps;

extern int g_PortMgrDlgNums;

void OutputInformation(CString strMsg);
void OutputToConsole(CString strMsg);
void ExiFslConsole();
void DetachFslConsole();
void StartForConsole();

void WhereXY(int *x, int *y);
void GoToXY(int x, int y);
extern BOOL g_bConsoleApp;

#define PROFILE_FOLDER_NAME_TAG		_T("-c")
#define BOARD_NAME_TAG				_T("-b")
#define LIST_NAME_TAG				_T("-l")
#define PORT_NUMBERS_TAG			_T("-p")

typedef enum _tagMsgType
{
	DEVICE1_UPDATE_PERCENT = 0,
	DEVICE2_UPDATE_PERCENT = 1,
	DEVICE3_UPDATE_PERCENT = 2,
	DEVICE4_UPDATE_PERCENT = 3,
	DEVICE1_DESCRIPTION,
	DEVICE2_DESCRIPTION,
	DEVICE3_DESCRIPTION,
	DEVICE4_DESCRIPTION,
	SUCCESS_AND_FAIL_COUNT,
	LAST_CURSOR_POSITION
} MSG_TYPE;

typedef struct _tagMsgCursorPos
{
	MSG_TYPE type;
	int x;
	int y;
	int length;
} MSG_CURSOR_POSITION;

extern std::vector<MSG_CURSOR_POSITION*> g_VolatileMsgPosArray;
void ModifySpecifiedLine(MSG_CURSOR_POSITION *pMsgPos, CString strMsgNew);

