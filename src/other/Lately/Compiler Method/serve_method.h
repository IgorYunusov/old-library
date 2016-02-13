/*************************************************************************
 *
 *					  ROLLRAT SOFTWARE LIBRARY
 *						SERVE METHOD
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _SERVE_METHOD_
#define _SERVE_METHOD_

#include <hash_map>
#include "string.h"
#include "urray.h"
#include "tree.h"

template<typename _Ty>
	urray<String<_Ty>> GetArgument(const _Ty *_Str)
		{
		urray<String<_Ty>> _UArray;
		for (; *_Str;)
			{
			if (*_Str == '\"')
				{
				String<_Ty> _Tmpstr;
				++_Str;
				for (; *_Str != '\"' && *_Str;)
					{
					_Tmpstr.Append(*_Str);
					++_Str;
					}
				_UArray.Add(_Tmpstr);
				if (!*_Str)
					break;
				++_Str;
				}
			else if (*_Str != ' ')
				{
				String<_Ty> _Tmpstr;
				for (; *_Str != ' ' && *_Str;)
					{
					_Tmpstr.Append(*_Str);
					++_Str;
					}
				_UArray.Add(_Tmpstr);
				if (!*_Str)
					break;
				++_Str;
				}
			else if (*_Str == ' ')
				++_Str;
			}
		return _UArray;
		}

template<typename _Ch>
	String<_Ch>& make_string(const _Ch *_Str)
		{
		int len = strlen(_Str);
		_Ch *Temp_String = new _Ch[len + 1];
		for (int f = 0; f < len; f++)
			Temp_String[f] = _Str[f];
		Temp_String[len] = 0;
		return *new String<_Ch>(Temp_String);
		}

	// Disjunct split.
//template<typename _Ch>
//	urray<_Ch *> Split(_Ch *_Ptr, const _Ch *_T)
//		{
//		_Ch * _Ptrs = (_Ch *)(_Ptr);
//		size_t _C = 0;
//		for(; *_Ptrs; _Ptrs++)
//			{
//			const _Ch *s1 = _Ptrs, *s2 = _T;
//			while (*s1 && *s2 && !(*s1 - *s2))
//				s1++, s2++;
//			if (!*s2)
//				_Ptrs = (_Ch *)(s1 - 1), _C++;
//			}
//
//		int ic =_C + 1;
//		_Ch **_ret = new _Ch*[ic], *s1, *s2, *tmp;
//		int i = 0, t = strlen(_T);
//
//		for (s1 = _Ptr; (s2 = strstr(s1, _T)) != NULL; i++)
//			{
//			tmp = new _Ch[s2 - s1 + 1];
//			memcpy(tmp, s1, s2 - s1);
//			tmp[s2 - s1] = 0;
//			_ret[i] = tmp;
//			s1 += s2 - s1 + t;
//			}
//
//		if(*s1)
//			{
//			for (s2 = s1; *s2; s2++)
//				;
//			tmp = new _Ch[s2 - s1 + 1];
//			memcpy(tmp, s1, s2 - s1);
//			tmp[s2 - s1] = 0;
//			_ret[i] = tmp;
//			i++;
//			}
//		
//		urray<String<_Ch>> _ret_;
//		for (int f = 0; f < i; f++)
//			_ret_.Add(_ret[f]);
//			//_ret_.Add(*new _MyStr(_ret[f]));
//		return _ret_;
//		}

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

std::vector<std::string> split(std::string str, std::string sep)
	{
	char * cstr = const_cast<char*>(str.c_str());
	char * current;
	std::vector<std::string> arr;
	current = strtok(cstr, sep.c_str());
	while (current != NULL)
		{
		arr.push_back(current);
		current = strtok(NULL, sep.c_str());
		}
	return arr;
	}

#endif