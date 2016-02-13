/************************************************************
 *															*
 *															*
 *			ROLLRAT AUTO PERSONA VERBOTER LIBROFEX			*
 *															*
 *															*
 *		COPYRIGHT (c) rollrat. 2013. ALL RIGHTS RESERVED.	*
 *															*
 *															*
 ************************************************************/

#pragma once

#ifndef _APVL_
#define _APVL_

#ifdef _APVL_USING_WINDOWS_CONSOLE_CONTROL
#include "apvlConsole.h"
#endif
#include "apvlWINAPI_File.h"
#include "apvlDef.h"
#include "apvlIndex.h"
#include "apvlGather.h"

#pragma region WINSOCK_TOOL
#define WINSOCK_DEFINE	\
		WSADATA wsaData;\
		SOCKET hServSock, hClntSock;\
		SOCKADDR_IN servAddr, clntAddr;
#pragma endregion

#endif
