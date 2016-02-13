/*************************************************************************
 *
 * FILE NAME : _tool.h
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

#ifndef __TOOL_
#define __TOOL_

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

#endif