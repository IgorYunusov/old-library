/*************************************************************************
 *
 * FILE NAME : util.hh - RASM utility
 *
 * ROLLRAT SOFTWARE IA-32 SHELL ASSEMBLER(RASM)
 *
 *
 * LANGUAGE : Macro Assembly, C++
 * VERSION  : Microsoft Macro Assembler v12.00.30501.0
 *            ISO/C++ 11-Microsoft C/C++ Optimizer Compiler 18.00.0501
 * CREATION : 2014.10.12
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com, rollrat.software@gmail.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#ifndef _UTIL_
#define _UTIL_

#include <string>
#include <algorithm>
#include <functional> 
#include <cctype>
#include <vector>
#include <hash_map>
#include "debug.h"

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

std::string& remove_annotation(std::string& str)
	{
	if (str.find(';') != false)
		return str;
	str.erase(std::find_if(str.rbegin(), str.rend(), 
		[](int _Ch){return _Ch == ';'; }).base()-1, str.end());
	return str;
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

#define DWORD2BYTE( t, tx )		(BYTE)(((tx) >> ((t) * 8)) & 0xff)

void pushdw(DWORD val, std::vector<BYTE>& at, bool be)
{
	if (!be)
		for (int xa = 0; xa < 4; xa++)
			at.push_back(DWORD2BYTE(xa, val));
	else
		for (int xa = 0; xa < 4; xa++)
			at.push_back(DWORD2BYTE(3 - xa, val));
}

void pushw(WORD val, std::vector<BYTE>& at, bool be)
{
	if (!be)
		{
		at.push_back(val & 0xff);
		at.push_back((val >> 8) & 0xff);
		}
	else
		{
		at.push_back((val >> 8) & 0xff);
		at.push_back(val & 0xff);
		}
}

void pushb(BYTE val, std::vector<BYTE>& at)
{
	at.push_back(val);
}

int get_register(const char* _T)
{
	const char * _Ptr = _T; 
	char _Tmp;
	if (*_Ptr == ' ')
		_Ptr++;
	if (*_Ptr == '[')
		return 255;
	if (*_Ptr++ != 'e')
		return 0;
	switch (*(_Ptr + 1))
	{
	case 'x':
		_Tmp = *_Ptr - 'a';
		return (((_Tmp ^ 0x2) + (_Tmp >> 1)) & 
			((_Tmp << 1) | (_Tmp >> 1) | _Tmp))+1;
	case 'p':
		return (~*_Ptr & 1) + 5;
	case 'i':
		return (~*_Ptr & 1) + 7;
	}
	return 0;
}

int get_oct(const char *_t)
{
	const char *_Ptr = _t;
	int g = 0, h = 1;
	if (*_t == '-')
		*_t++, h = -1;
	for (; *_Ptr != ' ' && *_Ptr && *_Ptr != ',' && *_Ptr != 'o'; _Ptr++)
		g *= 8, g += *_Ptr & 0xf;
	return g*h;
}

int get_integer(const char *_t)
{
	const char *_Ptr = _t;
	int g = 0, h = 1;
	if (*_t == '-')
		*_t++, h = -1;
	for (; *_Ptr != ' ' && *_Ptr && *_Ptr != ',' && *_Ptr != 'i' && *_Ptr != ']'; _Ptr++)
		 g *= 10, g += *_Ptr & 0xf;
	return g*h;
}

int get_hex(const char *_t)
{
	const char *_Ptr = _t;
	int g = 0;
	for (; *_Ptr != ' ' && *_Ptr && *_Ptr != ',' && *_Ptr != 'h'; _Ptr++)
		g *= 16, g += ('0' <= *_Ptr  && *_Ptr  <= '9') ? (*_Ptr & 0xf) : (*_Ptr  - 'a' + 0xa);
	return g;
}


#endif