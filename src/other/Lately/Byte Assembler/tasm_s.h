/*************************************************************************
 *
 *                    TETO. BYTE ASSEMBLER 0.1201.1.1.0
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _TASM_MOD_
#define _TASM_MOD_

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h>
#include "tasm.h"
#include <hash_map>
#include <vector>
#include <stack>
#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <initializer_list>
#include <functional> 
#include <future>
#include <cctype>
#include <locale>
#include <limits>
#include <string>
#include <filesystem>
#include <exception>
#include <regex>
#include <new>
#include <cstring>
#include "mas.h"
#include <bitset>
#include <allocators>
#include <array>
#include <complex>
#include <istream>
#include <algorithm>
#include <hash_set>
#include <list>
#include <random>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeinfo>
#include <typeindex>
#include <unordered_map>
#include <unordered_set>
#include "metapro.h"

#define USING_AT_TR
#include "at_tr.h"
//#include "rac.h"
//#include "string.h"
//#include "tree.h"
//#include "urray.h"

#define getrvalue_macro( t, v )	( ( t&& ) v )

void PushDWord(DWORD val, std::vector<BYTE>& at)
{
	for (int a = 0; a < 4; a++)
	{
#if defined(_M_IX86) || defined(_M_IA64) || defined(_IA64) || defined(__amd64) || defined(_M_X64) || defined(_IA64) || defined(_SENDIAN)
		at.push_back(DWORD2BYTE(a, val));
#else
		at.push_back(DWORD2BYTE(3 - a, val));
#endif
	}
}

std::string &ltrim(std::string &str)
{
	str.erase(str.begin(), std::find_if(str.begin(), str.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
	return str;
}

std::string &rtrim(std::string &str)
{
	str.erase(std::find_if(str.rbegin(), str.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), str.end());
	return str;
}

std::string &trim(std::string &str)
{
	return ltrim(rtrim(str));
}

int _Call_IT(std::string str)
{
	int i = 0;
	for(auto& ch : str)
		if (ch == ',')
			i++;
	return i;
}

//std::vector<std::string> split(std::string str, std::string sep)
//{
//	char * cstr = const_cast<char*>(str.c_str());
//	char * current;
//	std::vector<std::string> arr;
//	current = strtok(cstr, sep.c_str());
//	while (current != NULL)
//	{
//		arr.push_back(current);
//		current = strtok(NULL, sep.c_str());
//	}
//	return arr;
//}
	// Disjunct split.
template<typename _Ch>
	std::vector<std::string> Split(_Ch *_Ptr, const _Ch *_T)
		{
		_Ch * _Ptrs = (_Ch *)(_Ptr);
		size_t _C = 0;
		for(; *_Ptrs; _Ptrs++)
			{
			const _Ch *s1 = _Ptrs, *s2 = _T;
			while (*s1 && *s2 && !(*s1 - *s2))
				s1++, s2++;
			if (!*s2)
				_Ptrs = (_Ch *)(s1 - 1), _C++;
			}

		int ic =_C + 1;
		_Ch **_ret = new _Ch*[ic], *s1, *s2, *tmp;
		int i = 0, t = strlen(_T);

		for (s1 = _Ptr; (s2 = strstr(s1, _T)) != NULL; i++)
			{
			tmp = new _Ch[s2 - s1 + 1];
			memcpy(tmp, s1, s2 - s1);
			tmp[s2 - s1] = 0;
			_ret[i] = tmp;
			s1 += s2 - s1 + t;
			}

		if(*s1)
			{
			for (s2 = s1; *s2; s2++)
				;
			tmp = new _Ch[s2 - s1 + 1];
			memcpy(tmp, s1, s2 - s1);
			tmp[s2 - s1] = 0;
			_ret[i] = tmp;
			i++;
			}
		
		std::vector<std::string> _ret_;
		for (int f = 0; f < i; f++)
			_ret_.push_back(_ret[f]);
			//_ret_.Add(*new _MyStr(_ret[f]));
		return _ret_;
		}
	
	// Disjunct Replace.
template<typename _Ch>
	_Ch * Replace(const _Ch *_Target, const _Ch *_Left, const _Ch *_Right)
		{ // [0] Laird Shaw, 2009, Assistence c-faq.{o-name : replace_str() } [PUBLIC]
		size_t _l, _r, _t;
		const _Ch *s1, *s2;
		if ((_l = strlen(_Left)) == ((_r = strlen(_Right))))
			_t = strlen(_Target);
		else
			{
			int _tmp_s = 0;
			for (s1 = _Target; (s2 = strstr(s1, _Left)) != NULL; s1 = s2 + _l)
				_tmp_s++;
			_t = s1 - _Target + strlen(s1) + _tmp_s * (_r - _l);
			}
		
		_Ch *s3, *ret = new _Ch[_t + 1];

		for(s3 = ret, s1 = _Target; (s2 = strstr(s1, _Left)) != NULL; s1 = s2 + _l)
			{
			memcpy(s3, s1, s2 - s1);
			s3 += s2 - s1;
			memcpy(s3, _Right, _r);
			s3 += _r;
			}

		while (*s3 != NULL)
			*s3++ = *s1++;

		return ret;
		}


#endif