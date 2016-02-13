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

#endif