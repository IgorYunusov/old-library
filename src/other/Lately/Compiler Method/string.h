/*************************************************************************
 *
 *					  ROLLRAT SOFTWARE LIBRARY
 *						STRING CLASS
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _STR_
#define _STR_

#include <string.h>
#include "urray.h"

#define STRING_SET_NULL			' '

//
// String Class
//
template<class _Ch = char> class
	String
	{
	typedef typename String<_Ch> _MyStr;
	_Ch * _Ptr;
	//urray<_MyStr> split_store;
public:
	//

	explicit String()
		: _Ptr(0)
		{
		}

	explicit String(_Ch *_T)
		: _Ptr(_T)
		{
		}

	// Get string length.
	size_t Length() const 
		{
		if (!_Ptr)
			return 0;
		const _Ch * _Ptrs = _Ptr;
		for (; *_Ptrs; _Ptrs++)
			;
		return _Ptrs - _Ptr;
		}

	// Clear string.
	void Clear()
		{
		_Ptr = 0;
		}

	// Append text.
	void Append(const _Ch _T)
		{
		size_t _my_len = Length();
		_Ch *_Ptr_t = new _Ch[_my_len + 2], *_t;
		_t = _Ptr_t;
		if (_Ptr)
			{
			memcpy(_t, _Ptr, _my_len);
			_t += _my_len;
			}
		*_t = _T;
		_t += 1;
		*_t = 0;
		_Ptr = _Ptr_t;
		}

	// Append text.
	void Append(const _Ch *_T)
		{
		if (_T == 0)
			return;
		size_t _t_len = strlen(_T), _my_len = Length();
		_Ch *_Ptr_t = new _Ch[_t_len + _my_len + 1], *_t;
		_t = _Ptr_t;
		if (_Ptr)
			{
			memcpy(_t, _Ptr, _my_len);
			_t += _my_len;
			}
		memcpy(_t, _T, _t_len);
		_t += _t_len;
		*_t = 0;
		_Ptr = _Ptr_t;
		}

	// Append text.
	void Append(const _MyStr& _T)
		{
		Append(_T._Ptr);
		}
	
	// Append integer.
	void Append(int _integer)
		{
		char buffer [33];
		_itoa_s(_integer, buffer, 10);
		Append(buffer);
		}

	// Append double.
	void Append(double _double)
		{
		char buffer[55];
		sprintf_s(buffer, "%lf", _double, 55);
		/////////////
		char *t = buffer;
		while(*t++)
			;
		t -= 2;
		for (; *t == '0'; t--)
			*t = 0;
		/////////////
		Append(buffer);
		}

	// Insert text.
	void Insert(int _integer, const _Ch *_T)
		{
		size_t _t_len = strlen(_T), _my_len = Length();
		_Ch *_Ptr_t = new _Ch[_t_len + _my_len + 1], *_t;
		_t = _Ptr_t;
		memcpy(_t, _Ptr, _integer);
		_t += _integer;
		memcpy(_t, _T, _t_len);
		_Ptr += _integer;
		_t += _t_len;
		memcpy(_t, _Ptr, _my_len - _integer);
		_t += _my_len - _integer;
		*_t = 0;
		_Ptr = _Ptr_t;
		}
	
	// Append integer.
	void Insert(int _integer, const _MyStr& _T)
		{
		Insert(_integer, _T._Ptr);
		}

	// Append double.
	void Insert(int _integer, double _double)
		{
		char buffer[55];
		sprintf_s(buffer, "%lf", _double, 55);
		/////////////
		char *t = buffer;
		while(*t++)
			;
		t -= 2;
		for (; *t == '0'; t--)
			*t = 0;
		/////////////
		Insert(_integer, buffer);
		}

	// Comparison this string and ohter string
	bool Equals(const _MyStr* _T)
		{
		return strcmp(_Ptr, _T->_Ptr);
		}

	// Comparison this string and ohter string
	bool Equals(const _MyStr& _T)
		{
		return strcmp(_Ptr, _T._Ptr);
		}

	// Comparison this string and ohter string
	bool Equals(const _Ch *_T)
		{
		return strcmp(_Ptr, _T);
		}

	_Ch& operator()(size_t _Wh)
		{
		return _Ptr[_Wh];
		}

	// Is empty?
	bool Empty()
		{
		return _Ptr == 0;
		}

	// Covert c style string.
	_Ch*& c_str()
		{
		return _Ptr;
		}
	
	// Covert c style string.
	_Ch*& operator*()
		{
		return _Ptr;
		}

	// Is string in target string?
	bool Contains(const _Ch * _T)
		{
		_Ch * _Ptrs = (_Ch *)(_Ptr);
		for(; *_Ptrs; _Ptrs++)
			{
			const _Ch *s1 = _Ptrs, *s2 = _T;
			while (*s1 && *s2 && !(*s1 - *s2))
				s1++, s2++;
			if (!*s2)
				return true;
			}
		return false;
		}
	
	// Is string in target string?
	bool Contains(const _MyStr& _T) const
		{
		return Contains(_T._Ptr);
		}

	// Count string in string.
	size_t Len(const _Ch *_T)
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
		return _C;
		}

	// Count string in string.
	size_t Len(const _MyStr& _T)
		{
		return Len(_T._Ptr);
		}

	// Copy by new string class.
	_MyStr Copy()
		{
		_Ch *_p = _Ptr, *_ret = new _Ch[Length() + 1], *t;
		t = _ret;
		while (*_p)
			*t++ = *_p++;
		*t = 0;
		return *new _MyStr(_ret);
		}
	
	// Replace all string.
	_MyStr Replace(const _Ch *_Left, const _Ch *_Right)
		{ // [0] Laird Shaw, 2009, Assistence c-faq.{o-name : replace_str() } [PUBLIC]
		size_t _l, _r, _t;
		const _Ch *s1, *s2;
		if ((_l = strlen(_Left)) == ((_r = strlen(_Right))))
			_t = Length();
		else
			{
			int _tmp_s = 0;
			for (s1 = _Ptr; (s2 = strstr(s1, _Left)) != NULL; s1 = s2 + _l)
				_tmp_s++;
			_t = s1 - _Ptr + strlen(s1) + _tmp_s * (_r - _l);
			}
		
		_Ch *s3, *ret = new _Ch[_t + 1];

		for(s3 = ret, s1 = _Ptr; (s2 = strstr(s1, _Left)) != NULL; s1 = s2 + _l)
			{
			memcpy(s3, s1, s2 - s1);
			s3 += s2 - s1;
			memcpy(s3, _Right, _r);
			s3 += _r;
			}

		while (*s3 != NULL)
			*s3++ = *s1++;

		return *new _MyStr(ret);
		}
	
	// Replace all string.
	_MyStr Replace(const _MyStr& _Left, const _MyStr& _Right)
		{
		return Replace(_Left._Ptr, _Right._Ptr);
		}

	// Replace all character
	_MyStr Replace(const _Ch _Left, const _Ch _Right)
		{
		_Ch *s = _Ptr;
		for (; *s; s++)
			if (*s == _Left)
				*s = _Right;
		return *new _MyStr(_Ptr);
		}

	// Returns a string array that contains the substrings in this string that are delimited by elements of a specified String array.
	urray<_MyStr> Split(const _Ch *_T)
		{
		int ic = Len(_T) + 1;
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
		
		urray<_MyStr> _ret_;
		for (int f = 0; f < i; f++)
			_ret_.Add(*new _MyStr(_ret[f]));
			//_ret_.Add(*new _MyStr(_ret[f]));
		return _ret_;
		/*_MyStr *_ret_m = new _MyStr[ic];
		for (int f = 0; f < i; f++)
			_ret_m[f] = *new _MyStr(_ret[f]);
		return _ret_m;*/
		/*ConstArray<_MyStr> *_ret_mm = new ConstArray<_MyStr>(ic);
		for (int f = 0; f < i; f++)
			_ret_mm->_Ptr[f] = *new _MyStr(_ret[f]);
		return _ret_mm;*/
		}
	
	// Returns a string array that contains the substrings in this string that are delimited by elements of a specified String array.
	_MyStr *Split(const _MyStr& _T)
		{
		return Split(_T._Ptr);
		}

	// Make sure at the start of this string instance, string that you specify as to whether or not the match.
	bool StartsWith(const _Ch *_T)
		{
		const _Ch *s = _T, *p = _Ptr;
		for (; *s; s++, p++)
			if (*s != *p)
				return false;
		return true;
		}
	
	// Make sure at the start of this string instance, string that you specify as to whether or not the match.
	bool StartsWith(const _MyStr& _T)
		{
		return StartsWith(_T->_Ptr);
		}

	// Make sure at the end of this string instance, string that you specify as to whether or not the match.
	bool EndsWith(const _Ch *_T)
		{
		const _Ch *s = _T, *p = _Ptr;
		while (*s++)
			;
		while (*p++)
			;
		for (s--, p--; s != _T; s--, p--)
			if (*s != *p)
				return false;
		return true;
		}

	// Make sure at the end of this string instance, string that you specify as to whether or not the match.
	bool EndsWith(const _MyStr& _T)
		{
		return EndsWith(_T._Ptr);
		}

	// CString style Right fucntion.
	_MyStr Right(const size_t _Count)
		{
		_Ch *_ret = new _Ch[_Count + 1], *p = _Ptr;
		while (*p++)
			;
		p -= _Count + 1;
		memcpy(_ret, p, _Count);
		_ret[_Count] = 0;
		return *new _MyStr(_ret);
		}
	
	// CString style Left fucntion.
	_MyStr Left(const size_t _Count)
		{
		_Ch *_ret = new _Ch[_Count + 1], *p = _Ptr;
		memcpy(_ret, p, _Count);
		_ret[_Count] = 0;
		return *new _MyStr(_ret);
		}
	
	// CString style Mid fucntion.
	_MyStr Mid(const size_t _Left, const size_t _Right)
		{
		_Ch *p = _Ptr;
		_Ptr += _Left;
		_MyStr _ret = Left(_Right);
		_Ptr = p;
		return _ret;
		}
	
	// Adjust to match the length that you specify, in a string that has been specified, returns a string that matches the left.
	_MyStr LSet(const size_t _Count)
		{
		_Ch *_p = new _Ch[_Count + 1], *p = _Ptr;
		int i = 0;
		for (; *p && i < _Count; i++, p++)
			_p[i] = *p;
		if (!*p)
			for (; i < _Count; i++)
				_p[i] = STRING_SET_NULL;
		_p[_Count] = 0;
		return *new _MyStr(_p);
		}

	// Returns a string that matches the right to match the length that is specified.
	_MyStr RSet(const size_t _Count)
		{
		_Ch *_p = new _Ch[_Count + 1];
		const _Ch *p = _Ptr;
		while (*p++)
			;
		p -= 2;
		int i = _Count;
		for (; p != (_Ptr - 1) && i; i--, p--)
			_p[i-1] = *p;
		if (p == (_Ptr - 1))
			{
			for (; i; i--)
				_p[i] = STRING_SET_NULL;
			*_p = STRING_SET_NULL;
			}
		_p[_Count] = 0;
		return *new _MyStr(_p);
		}

	// Returns a string copy of the specified string does not have (Trim) space leading spaces (LTrim), trailing spaces (RTrim), at the beginning or end is included.
	_MyStr LTrim()
		{
		const _Ch *p = _Ptr, *pp = _Ptr;
		while (*p++)
			;
		p -= 2;
		for (; isspace(*p); p--)
			;
		p++;
		_Ch *_ret = new _Ch[p - _Ptr + 1], *t;
		t = _ret;
		for (; pp != p; pp++)
			*t++ = *pp;
		*t = 0;
		return *new _MyStr(_ret);
		}

	// Returns a string copy of the specified string does not have (Trim) space leading spaces (LTrim), trailing spaces (RTrim), at the beginning or end is included.
	_MyStr RTrim()
		{
		const _Ch *p = _Ptr, *l = _Ptr;
		while (*l++)
			;
		l -= 2;
		for (; isspace(*p); p++)
			;
		_Ch *_ret = new _Ch[l - p + 1], *t;
		t = _ret;
		for (; *p; p++)
			*t++ = *p;
		*t = 0;
		return *new _MyStr(_ret);
		}

	// Returns a string copy of the specified string does not have (Trim) space leading spaces (LTrim), trailing spaces (RTrim), at the beginning or end is included.
	_MyStr Trim()
		{
		return LTrim().RTrim();
		}

	// Conver all lower character to upper character.
	_MyStr ToUpper()
		{
		_MyStr *_C = &Copy();
		_Ch *_c = _C->_Ptr;
		for (; *_c; _c++)
			if ('a' <= *_c && *_c <= 'z')
				*_c &= 0x5F;
		return *_C;
		}

	// Conver all upper character to lower character.
	_MyStr ToLower()
		{
		_MyStr *_C = &Copy();
		_Ch *_c = _C->_Ptr;
		for (; *_c; _c++)
			if ('A' <= *_c && *_c <= 'Z')
				*_c |= 0x20;
		return *_C;
		}
	
	// Compare with text.
	size_t Compare(const _Ch *_T)
		{
		return strcmp(_Ptr, _T);
		}
	
	bool operator==(const _Ch *_T)
		{
		return Equals(_T) == 0;
		}

	bool operator==(const _MyStr* _T)
		{
		return Equals(_T) == 0;
		}

	bool operator==(const _MyStr& _T)
		{
		return Equals(_T) == 0;
		}

	bool operator!=(const _Ch *_T)
		{
		return Equals(_T);
		}

	bool operator!=(const _MyStr* _T)
		{
		return Equals(_T);
		}

	bool operator!=(const _MyStr& _T)
		{
		return Equals(_T);
		}

	void operator=(const _MyStr* _T)
		{
		_Ptr = _T->_Ptr;
		}

	bool operator!=(int _i)
		{
		return (int)_Ptr != _i;
		}

	_Ch*& _Iter()
		{
		return _Ptr;
		}
	
	size_t make_hash()
		{
		const _Ch * _tmp = _Ptr;
		int j = 0;
		for(int i = 0; *_tmp; _tmp++)
			j = (j << ((256 | 0x7A64) + i)) + *_tmp;
		return j;
		}

	bool IsNumberic()
		{
		const _Ch * _tmp = _Ptr;
		for (; *_tmp; _tmp++)
			if (!(('0' <= _tmp) && (_tmp <= '9')))
				return false;
		return true;
		}

	// To string.
	_MyStr ToString()
		{ // no to string
		return *new _MyStr(_Ptr);
		}

	};

typedef String<char> CString;

#endif