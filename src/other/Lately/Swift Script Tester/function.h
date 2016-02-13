/*************************************************************************
 *
 * FILE NAME : function.h
 *
 * ROLLRAT Swift Script Tester (RSST)
 *
 *
 * LANGUAGE : Macro Assembly, C++
 * VERSION  : Microsoft Macro Assembler v12.00.30501.0
 *            ISO/C++ 11-Microsoft C/C++ Optimizer Compiler 18.00.0501
 * CREATION : 2014.12.03
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com, rollrat.software@gmail.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#ifndef _FUNCTION_
#define _FUNCTION_

#include <string>
#include <algorithm>
#include <functional> 
#include <cctype>
#include <vector>
#include <hash_map>
#include <map>
#include <tuple>
#include "_tool.h"

class _function {
public:
	static void function_syntax(const char *syn) {
		std::vector<std::string> vSr = split(syn, ".");
		if (vSr[0] != "func")
			return;

	}
};

#endif