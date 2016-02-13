/*************************************************************************
 *
 * FILE NAME : token.h
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

#ifndef _TOKEN_
#define _TOKEN_

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
#include "independent_method.h"

		// INTERCODE GENERATOR for linked_rvalue with optimize for sst
int _optimize_intercode_generator2_for_sst(tree<std::string> tree, variable_map vm)
	{
	std::stack<std::string> var;
	std::vector<std::string> tdup1, tdup2, code;
	std::map<std::string, std::string> map;
	int count = 0;
	bool pref = false;
	bool t = false;
	
	auto is_number=[](std::string cptr)->bool
		{
		for (const char *ptr = cptr.c_str(); 
			('0' <= *ptr && *ptr <= '9') || *ptr == '.'; ptr++)
			if(!*(ptr+1))
				return true;
		return false;
		};

	postorder_travel([&](std::string str)
		{
		if (str.empty()) {
			t = true;
			return;
		}
		if(::strchr("+-*/&^|%<>!~", str[0]))
			{
			std::string rvalue("$t" + std::to_string(count) + "_=");
			if (!var.empty())
				{
				bool second_number = is_number(var.top());
				std::string temp = var.top();
				var.pop();
				if (!var.empty()) {
					if(is_number(var.top()) && second_number) {
						int v1 = std::stoll(temp), v2 = std::stoll(var.top()), v3;
						switch(*str.c_str()) {
						case '+': v3 = v2 + v1; break;
						case '-': v3 = v2 - v1; break;
						case '*': v3 = v2 * v1; break;
						case '/': v3 = v2 / v1; break;
						case '&': v3 = v2 & v1; break;
						case '^': v3 = v2 ^ v1; break;
						case '|': v3 = v2 | v1; break;
						case '%': v3 = v2 % v1; break;
						default:
							goto JUST_EXCUATE;
						}
						var.push(std::to_string(v3));
					} else {
			JUST_EXCUATE:
						int v1, v2 , v3;
						if (!is_number(var.top()))
							v2 = vm[map[var.top()]]->idata;
						else
							v2 = std::stoll(var.top());
						var.pop();
						if (!second_number)
							v1 = vm[map[temp]]->idata;
						else
							v1 = std::stoll(temp);
						switch(*str.c_str()) {
						case '+': v3 = v2 + v1; break;
						case '-': v3 = v2 - v1; break;
						case '*': v3 = v2 * v1; break;
						case '/': v3 = v2 / v1; break;
						case '&': v3 = v2 & v1; break;
						case '^': v3 = v2 ^ v1; break;
						case '|': v3 = v2 | v1; break;
						case '%': v3 = v2 % v1; break;
						default:
							goto JUST_EXCUATE;
						}
						var.push(std::to_string(v3));
						}
				} else 
					goto _LABEL_ERROR;
				}
			else
		_LABEL_ERROR:
				MessageBox(0, TEXT("Input value is incorrect. Please enter a valid expression."), TEXT("_rsst:_@_optimize_intercode_generator2"), MB_OK | MB_ICONERROR);
			}
		else
			if(is_number(str))
				var.push(str);
			else {
				bool t = false;
				for(int i = 0; i < tdup1.size(); i++)
					if(tdup2[i] == str) {
						var.push(tdup1[i]);
						t = true;
						break;
					}
				if(!t) {
					std::string rvalue("$t" + std::to_string(count) + "_=" + str);
					map.insert(std::make_pair("$t" + std::to_string(count) + "_", str));
					var.push("$t" + std::to_string(count) + "_");
					tdup1.push_back(var.top());
					tdup2.push_back(str);
					code.push_back(rvalue);
					count += 1;
				}
			}
		}
		, tree.travel());
	if(t)
		var.push(std::to_string(vm[map[var.top()]]->idata));
	return ::atoi(var.top().c_str());
	}

class _token {
public:
	static void token_syntax(const char *syn, variable_map& vm) {
		auto skipws = [&syn]() {
			for (; isspace(*syn) && *syn; syn++)
				;
			};
		skipws();
		std::string stream;
		for (; !::isspace(*syn) && *syn != '=' && *syn != '&' && *syn != '|' && *syn != '+' && *syn != '-' && *syn != '^' && *syn != '/' && *syn != '*'; syn++)
			stream.push_back(*syn);
		if (stream.empty())
			return;
		PVARIABLE pv_left = vm[stream];
		if(!pv_left) {
			MessageBox(0, TEXT(std::string("변수를 찾을 수 없습니다. var : " + stream).c_str()), TEXT("_rsst:_@token"), MB_OK | MB_ICONERROR);
			return;
		}
		if (pv_left->type != pv_left->typex && pv_left->typex != 0) {
			MessageBox(0, TEXT(std::string("불안정한 변수 사용이 감지되었습니다. var : " + pv_left->varname).c_str()), TEXT("_rsst:_@token"), MB_OK | MB_ICONERROR);
			return;
		}
		if (pv_left->type >= 7) {
			MessageBox(0, TEXT(std::string("상수를 나타내는 let을 갖는 변수에 값을 대입할 수 없습니다. var : " + pv_left->varname).c_str()), TEXT("_rsst:_@token"), MB_OK | MB_ICONERROR);
			return;
		}
		skipws();
		auto st = _scan::scan_token(syn);
		syn = std::get<1>(st);
		stream.clear();
		for (; *syn && *syn != '#'; syn++)
			stream.push_back(*syn);
		if (pv_left->type == VARTYPE_INT) {
			linked_rvalue<priority_second> lr;
			int tmp = _optimize_intercode_generator2_for_sst(lr.start(stream.c_str()), vm);
			if(std::get<0>(st) == TOKEN_EQUAL) {
				pv_left->idata = tmp;
				pv_left->init = true;
			}
			else if(pv_left->init){
				if (std::get<0>(st) == TOKEN_PLUSEQUAL)
					pv_left->idata += tmp;
				else if (std::get<0>(st) == TOKEN_MINUSEQUAL)
					pv_left->idata -= tmp;
				else if (std::get<0>(st) == TOKEN_XOREQUAL)
					pv_left->idata ^= tmp;
				else if (std::get<0>(st) == TOKEN_MULTIPLEEQUAL)
					pv_left->idata *= tmp;
				else if (std::get<0>(st) == TOKEN_DIVISIONEQUAL)
					pv_left->idata /= tmp;
				}
			else if(!pv_left->init)
				MessageBox(0, TEXT(std::string("초기화 되지 않은 변수에 값을 대입하려하고 있습니다. var : " + pv_left->varname).c_str()), TEXT("_rsst:_@token"), MB_OK | MB_ICONERROR);
			return;
		}
	}
};


#endif