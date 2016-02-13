/*************************************************************************
 *
 * FILE NAME : run.h
 *
 * ROLLRAT Swift Script Tester (RSST)
 *
 *
 * LANGUAGE : Macro Assembly, C++
 * VERSION  : Microsoft Macro Assembler v12.00.30501.0
 *            ISO/C++ 11-Microsoft C/C++ Optimizer Compiler 18.00.0501
 * CREATION : 2014.11.11
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com, rollrat.software@gmail.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#ifndef _RUN_
#define _RUN_

#include <string>
#include <algorithm>
#include <functional> 
#include <cctype>
#include <vector>
#include <hash_map>
#include "type.h"


std::vector<std::string> split(std::string str, std::string sep)
	{
	char * cstr = const_cast<char*>(str.c_str());
	char * current;
	char * context = NULL;
	std::vector<std::string> arr;
	current = strtok_s(cstr, sep.c_str(), &context);
	while (current != NULL)
		{
		arr.push_back(current);
		current = strtok_s(NULL, sep.c_str(), &context);
		}
	return arr;
	}

std::string& ltrim(std::string& str)
	{
	str.erase(str.begin(), std::find_if(str.begin(), str.end(), 
		std::not1(std::ptr_fun<int, int>(std::isspace))));
	return str;
	}

std::string& rtrim(std::string& str)
	{
	str.erase(std::find_if(str.rbegin(), str.rend(), 
		std::not1(std::ptr_fun<int, int>(std::isspace))).base(), str.end());
	return str;
	}

std::string& trim(std::string& str)
	{
	return ltrim(rtrim(str));
	}

std::string& right(std::string& str, size_t count)
	{
	str.erase(str.begin(), str.end()-count);
	return str;
	}

std::string& left(std::string& str, size_t count)
	{
	str.erase(str.begin()+count, str.end());
	return str;
	}

std::string& lset(std::string& str, size_t count)
	{
	if (str.size() > count)
		str.resize(count);
	else if (str.size() < count)
		str.insert(str.length(), count-str.length(), ' ');
	return str;
	}

std::string& rset(std::string& str, size_t count)
	{
	if (str.size() > count)
		str.resize(count);
	else if (str.size() < count)
		str.insert(0, count-str.length(), ' ');
	return str;
	}

//#define VARTYPE_NONE		0
//#define VARTYPE_INT			1
//#define VARTYPE_STRING		2
//#define VARTYPE_VAR			3

//std::string get_type(int t)
//{
//	switch(t) {
//	case VARTYPE_INT:
//		return "Int";
//	case VARTYPE_STRING:
//		return "String";
//	case VARTYPE_VAR:
//		return "Variable";
//	default:
//		return "알 수 없음";
//	}
//}

//typedef struct _var_type {
//	int type;
//	bool isarray;
//	bool isdic;
//	std::string std_data;
//	int int_data;
//	double double_data;
//	std::map<std::string, std::vector<std::string>> _arr_data;
//	std::map<std::string, std::map<std::string, std::string>> _dic_data;
//}	VARIABLE, *PVARIABLE;
//
//typedef std::map<std::string, PVARIABLE>::value_type map_var;
//
//void run_sst(std::vector<std::string> lines, bool is_debug = false)
//{
//	std::map<std::string, PVARIABLE> map;
//	std::string stream;
//
//	int linec = 0;
//	for(std::string line : lines) {
//		linec++;
//		const char *ptr = line.c_str();
//		auto skipws = [&ptr]() {
//			for (; isspace(*ptr) && *ptr; ptr++)
//				;
//			};
//		auto strget = [&stream, &ptr] ( char ch ) {
//			for (stream.clear(); *ptr != ch && *ptr; *ptr++)
//				stream.push_back(*ptr);
//			};
//
//
//		skipws();
//		switch ( *ptr ) {
//		case '#':
//			if (is_debug)
//				std::cout << linec << "줄: 주석 " << line << std::endl;
//			break;
//		case '.':
//			if (is_debug)
//				std::cout << linec << "줄: 디렉티브 선언" << std::endl;
//			break;
//		case '\0':
//			if (is_debug)
//				std::cout << linec << "줄: 공백" << std::endl;
//			break;
//		default:
//			strget(' ');
//			if(stream == "var") {
//				skipws();strget(' ');
//				if (stream.empty()) {
//					std::cout << linec << "줄: 오류! 변수이름을 선언하여야합니다." << std::endl;
//					break;
//				}
//				std::string variable_name = stream;
//				int type = VARTYPE_NONE;skipws();
//				if(*ptr == ':') {
//					ptr++;skipws();strget(' ');
//					if (stream == "Int")
//						type = VARTYPE_INT;
//					else if (stream == "String")
//						type = VARTYPE_STRING;
//					else if (stream == "Variable")
//						type = VARTYPE_VAR;
//					else {
//						std::cout << linec << "줄: '" << stream << "'은 알 수 없는 타입입니다." << std::endl;
//						break;
//					}
//				}skipws();
//				if(*ptr == '=') {
//					ptr++;skipws();strget('\0');
//					if(stream.empty()){
//						std::cout << linec << "줄: 대입할 값이 없습니다." << std::endl;
//						break;
//						}
//					if(!type)
//						if(stream[0] == '\"')
//							type = VARTYPE_STRING;
//						else if (isalpha(stream[0]))
//							type = VARTYPE_VAR;
//						else if (isalnum(stream[0]))
//							type = VARTYPE_INT;
//						else
//							type = VARTYPE_NONE;
//					else {
//						int ttype;
//						if(stream[0] == '\"')
//							ttype = VARTYPE_STRING;
//						else if (isalpha(stream[0]))
//							ttype = VARTYPE_VAR;
//						else if (isalnum(stream[0]))
//							ttype = VARTYPE_INT;
//						else
//							ttype = VARTYPE_NONE;
//						if(type != ttype) {
//							std::cout << linec << "줄: '" << get_type(type) << "'와 '" 
//								<< get_type(ttype) << "'이 서로 호환되지 않습니다." << std::endl;
//							continue;
//						}
//					}
//					PVARIABLE pvar = new VARIABLE;
//					pvar->type = type;
//					if(stream[0] == '\"')
//						pvar->sdata = stream;
//					else if (isalpha(stream[0]))
//						pvar->sdata = stream;
//					else if (isalnum(stream[0]))
//						pvar->idata = std::stoi(stream);
//					else
//						type = VARTYPE_NONE;
//					std::cout << linec << "줄: 변수선언 (이름: '" << variable_name << "', 타입: '" << get_type(type)
//						<< "', 데이터: '" << stream << "')" << std::endl;
//					map.insert(map_var(variable_name, pvar));
//				} else if (!type) {
//					std::cout << linec << "줄: 비명시적 변수선언의 경우 초기값이 반드시 선언과 동시에 대입되어야합니다." << std::endl;
//				}
//			}
//		}
//	}
//}

#endif