/*************************************************************************
 *
 * FILE NAME : debug.h - Debugging tool & debug flag set
 *
 * ROLLRAT SOFTWARE IA-32 SHELL ASSEMBLER(RASM)
 *
 *
 * LANGUAGE : Macro Assembly, C++
 * VERSION  : Microsoft Macro Assembler v12.00.30501.0
 *            ISO/C++ 11-Microsoft C/C++ Optimizer Compiler 18.00.0501
 * CREATION : 2014.10.15
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com, rollrat.software@gmail.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#ifndef _DEBUG_
#define _DEBUG_

#include <Windows.h>
#include <fstream>

#ifdef _DEBUGGING_MODE
	#error _DEBUGGING_MODE flag is already defined!
#else
	#ifdef _DEBUG
		#define _DEBUGGING_MODE 1		// debug mode
	#else
		#define _DEBUGGING_MODE 0		// release mode
	#endif
#endif

#if !defined(_M_IX86) && !defined(_M_IA64) && !defined(_IA64) && !defined(__amd64) && !defined(_M_X64) && !defined(_IA64) && !defined(_SENDIAN)
	#error This platform is not accepted little endian.
#endif

#if _DEBUGGING_MODE == 1
		// simple get build number, auto increment build number method 
void build_count()
	{
	std::ifstream inf("build", std::ios::in);
	int build_number;
		inf >> build_number;
		inf.close();
	std::ofstream onf("build", std::ios::out);
		onf << build_number+1;
		onf.close();
	}

int get_build_count()
	{
	std::ifstream inf("build", std::ios::in);
	int build_number;
		inf >> build_number;
		inf.close();
	return build_number;
	}
#endif

class rtc_debugger {
//austinpower get
	PROCESS_INFORMATION pi;
	STARTUPINFO	si;
	CREATE_PROCESS_DEBUG_INFO ProcessDbgInfo;
	PVOID AddressOfBase;
	PROCESS_INFORMATION	ProcessInfo;
	BYTE m_originalExeEntryPointOpcode;

	void start(char *filename)
		{
		ZeroMemory(&si, sizeof(si));
		si.cb = sizeof(si);
		if(CreateProcess(NULL,filename,NULL,NULL,FALSE, DEBUG_ONLY_THIS_PROCESS,NULL,NULL,&si,&pi))
			debug_loop();
		}

	void tls_scan()
		{
		}

	BOOL ep_scan()
		{
		DWORD cBytesMoved;
		AddressOfBase = ProcessDbgInfo.lpStartAddress;
		BOOL retValue = ReadProcessMemory( ProcessInfo.hProcess,
			AddressOfBase,
			&m_originalExeEntryPointOpcode,
			sizeof( m_originalExeEntryPointOpcode ),
			&cBytesMoved );
		if( !retValue )
			return FALSE;
		BYTE bpOpcode = 0xCC;
		return WriteProcessMemory( ProcessInfo.hProcess,
			AddressOfBase,
			&bpOpcode,
			sizeof( bpOpcode ),
			&cBytesMoved );
		}

	BOOL revome_epbp()
		{
		DWORD cBytesMoved;
		return WriteProcessMemory( ProcessInfo.hProcess,
			AddressOfBase,
			&m_originalExeEntryPointOpcode,
			sizeof( m_originalExeEntryPointOpcode ),
			&cBytesMoved );
		}

	void debug_loop()
		{
		DEBUG_EVENT event;
		DWORD cs;
		while(1){
				WaitForDebugEvent(&event, INFINITE);
				cs = DBG_EXCEPTION_NOT_HANDLED;
				if(event.dwDebugEventCode == CREATE_PROCESS_DEBUG_EVENT)
					ProcessDbgInfo = event.u.CreateProcessInfo;
				else if(event.dwDebugEventCode == EXCEPTION_DEBUG_EVENT)
					;//HandleException( &event, &cs );
				if(event.dwDebugEventCode == EXIT_PROCESS_DEBUG_EVENT)
					return;
				ContinueDebugEvent(event.dwProcessId, event.dwThreadId, cs);
			}
		}

	};

#endif