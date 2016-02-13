/*=================================================

			RollRat Software Expression

	Copyright (c) rollrat. All rights reserved.

=================================================*/

#pragma once
#ifndef _x_lib_integer
#define _x_lib_integer

#include "algorithm.h"
#include <iostream>

#if defined(_EX_SUCCESS)
_X_LIB_BEGIN

template<typename _Ty1> inline
	_Ty1 Translate_Char_Int(_Ty1 _First)
	{ // char -> int
	if('0' <= _First && _First <= '9')
		return _First - '0';
	if(_First == 0)
		return 0;
	}

template<typename _Ty1> inline
	_Ty1 Translate_Int_Char(_Ty1 _First)
	{ // int -> char
	if(0 <= _First && _First <= 9)
		return _First + '0';
	if(_First == 0)
		return 0;
	}

template<typename _Ty1> inline
	int Get_Length(_Ty1 _First)
	{ // get length
	for(int i = 0; ; )
		if(!_First[i++])
			return i;
	}

template<typename _Ty1> inline
	_Ty1 *reverse(_Ty1 *s)
	{ // reverse char
	_Ty1  c;
	_Ty1 *s0 = s - 1;
	_Ty1 *s1 = s;
	for( ; *s1; ) ++s1;
	for( ; s1-- > ++s0; )
		{
		c   = *s0;
		*s0 = *s1;
		*s1 =  c;
		}
	return s;
	}

typedef enum Sign
	{
	minus	= -1,
	zero	= 0,
	plus	= 1,
	};

#define MAX_CHAR 32767 // max char in x64 arcitacture

template<class _Ty0 = int>
	class UInteger
	{ // unsigned integer
	public:

	UInteger()
		: Sign(zero), Length(0), retbuf(0)
		{ // entry point
		uintegerbuf = new char[MAX_CHAR];
		for(register int i = 0; i <= MAX_CHAR; i++)
			uintegerbuf[i] = 0;
		uintegerbuf[0] = '0';
		}

	~UInteger()
		{ // desconductor
		delete[] uintegerbuf;
		}

	void operator++(int)
		{ // public algorithm
		for(register long long i = 0; ; i++)
			{
			if(uintegerbuf[i] == '0' || uintegerbuf[i] == 0)
				{
				uintegerbuf[i] = '1';
				break;
				}
			else if(uintegerbuf[i] == '9')
				uintegerbuf[i] = '0';
			else 
				{
				uintegerbuf[i] += 1;
				break;
				}
			}
		}

	void operator--(int)
		{ // public algorithm
		for(register long long i = 0; ; i++)
			{
			if(uintegerbuf[i] == '0')
				uintegerbuf[i] = '9';
			else
				{
				uintegerbuf[i] -= 1;
				break;
				}
			}
		}

	char *operator()()
		{ // operator()
		_reverse();
		return uintegerbuf;
		}

	void _reverse()
		{ // reverse me
		reverse(uintegerbuf);
		}

	void operator+=(int _First)
		{ // operator += int
		static char *buf = new char[MAX_CHAR];
		for(long long i = 0; i <= MAX_CHAR; i++)
			buf[i] = 0;
		itoa(_First, buf, 10);/*
		for(register long long i = 0; i <= f; i++)
			if ('0' <= buf[i] && buf[i] <= '9')
				;
			else 
				buf[i] = 0;*/
		operator+=(buf);
		}

	void operator+=(char* _me)
		{ // algorithm
		char* me;
		me = reverse(_me);
		int f = Get_Length(me);
		for(register long long i = 0; i <= f - 1; i++)
			{
			if(0 <= (Translate_Char_Int(me[i]) + Translate_Char_Int(uintegerbuf[i])) 
				&& (Translate_Char_Int(me[i]) + Translate_Char_Int(uintegerbuf[i])) < 10)
				uintegerbuf[i] = Translate_Int_Char(Translate_Char_Int(me[i]) 
				+ Translate_Char_Int(uintegerbuf[i]));
			else if(10 <= (Translate_Char_Int(me[i]) + Translate_Char_Int(uintegerbuf[i])) 
				&& (Translate_Char_Int(me[i]) + Translate_Char_Int(uintegerbuf[i])) <= 18 )
				uintegerbuf[i] = Translate_Int_Char(Translate_Char_Int(me[i]) 
					+ Translate_Char_Int(uintegerbuf[i]) - 10),
				pluse_n_come_char_innex_parameter(i + 1);
			}
		}

	void pluse_n_come_char_innex_parameter(long long state)
		{
		if(uintegerbuf[state] == '9')
			{
			uintegerbuf[state] = '0';
			pluse_n_come_char_innex_parameter(state + 1);
			}
		else
			if(uintegerbuf[state] == 0)
				uintegerbuf[state] = '1';
			else
				uintegerbuf[state] = uintegerbuf[state] + 1;
		}

	void operator-=(int _First)
		{ // operator += int
		static char *buf = new char[MAX_CHAR];
		for(long long i = 0; i <= MAX_CHAR; i++)
			buf[i] = 0;
		itoa(_First, buf, 10);/*
		for(register long long i = 0; i <= f; i++)
			if ('0' <= buf[i] && buf[i] <= '9')
				;
			else 
				buf[i] = 0;*/
		operator-=(buf);
		}

	void operator*=(int _First)
		{
		static char *buf = new char[MAX_CHAR];
		for(long long i = 0; i <= MAX_CHAR; i++)
			buf[i] = 0;
		itoa(_First, buf, 10);/*
		for(register long long i = 0; i <= f; i++)
			if ('0' <= buf[i] && buf[i] <= '9')
				;
			else 
				buf[i] = 0;*/
		operator*=(buf);
		}

	void operator*=(char *_buf)
		{ // algorithm
		}

	private:

	char *retbuf;
	char *uintegerbuf;
	Sign Sign;
	long long Length;

	};



#if defined(_IOSTREAM_)
std::ostream &operator<<(std::ostream &os, UInteger<>& x) 
	{
	os << x();
	x._reverse();
	return os;
	}
#endif

_X_LIB_END
#endif

#endif
/*
 *	The rollrat expression header
 *  Updated : 2013-04
 *	http://blog.naver.com/rollrat
 *  Copyright (c) 2009-2013 by rollrat. All right reserved.
 *  For more information, refer to the documentation on the license.
V0.1:0001****/