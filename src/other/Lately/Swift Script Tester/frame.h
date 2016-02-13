/*************************************************************************
 *
 * FILE NAME : frame.h
 *
 * ROLLRAT Swift Script Tester (RSST)
 *
 *
 * LANGUAGE : Macro Assembly, C++
 * VERSION  : Microsoft Macro Assembler v12.00.30501.0
 *            ISO/C++ 11-Microsoft C/C++ Optimizer Compiler 18.00.0501
 * CREATION : 2014.11.12
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com, rollrat.software@gmail.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#ifndef _FRAME_
#define _FRAME_

#include <string>
#include <algorithm>
#include <functional> 
#include <cctype>
#include <vector>
#include <hash_map>
#include <map>
#include <tuple>
#include <Windows.h>
#include <stack>
#include "type.h"
#include "var.h"
#include "token.h"
#include "function.h"

void run_sst(std::vector<std::string> lines, bool is_debug = false)
{
	//std::map<std::string, PVARIABLE> map;
	variable_map vm;
	int linec = 0;
	std::string temp, stream;
	for(std::string line : lines) {
		linec++;
		auto st = _scan::scan_keyword(line.c_str());
		switch(std::get<0>(st))
		{
		case KEYWORD_NONE:
			_token::token_syntax(line.c_str(), vm);
			break;

		case KEYWORD_IF:
		case KEYWORD_ELSEIF:
		case KEYWORD_ELSE:

		case KEYWORD_FOR:
		case KEYWORD_DO:
		case KEYWORD_WHILE:
			
		case KEYWORD_SWITCH:

		case KEYWORD_VAR:
		case KEYWORD_LET:
			PVARIABLE pVle;
			pVle = _variable::variable_syntax(line.c_str());
			vm(pVle->varname, pVle);
			break;

		case KEYWORD_FUNCTION:
			_function::function_syntax(line.c_str());
			break;
		}
	}
}


#endif