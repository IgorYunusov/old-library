/*=================================================

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

=================================================*/

#pragma once
#ifndef _funciton_
#define _function_

#include "tree.h"

/*----------------------------------------------------------------

				The Complex Programming Project

	The headers in C/C++ is all about grammar as much as 
	possible.

	LEVELS:

	CM LEVEL : (Complexity Metric)
		NOTE : http://en.wikipedia.org/wiki/Cyclomatic_complexity

	+----------+---------------------------------------------+
	| TYPENAME | Standard Expression						 |
	+----------+---------------------------------------------+
	| _Ty(n)A  | 1											 |
	| _Ty(n)B  | 1.5 or x									 |
	| _Ty(n)C  | log x										 |
	| _Ty(n)D  | log 2x										 |
	| _Ty(n)E  | 2 log x									 |
	| _Ty(n)F  | 2 ^ x										 |
	| _Ty(n)G  | 3 ^ x										 |
	+----------+---------------------------------------------+

----------------------------------------------------------------*/

#if defined(_EX_SUCCESS)
_X_LIB_BEGIN
	
// Check
#define ISDIGIT( w ) '0' <= w && w <= '9'
#define ISOPERATOR( u ) u == '+' || u == '-' \
			|| u == '*' || u == '/' || u == '^'
#define ISCHAR( j ) ('a' <= j && j <= 'z') \
			|| ('A' <= j && j <= 'Z')

template<class _Ty0> inline
	bool IsDigit(_Ty0 *chsar)
	{ // is digit
	for( ; *chsar; *chsar++)
		if(!(ISDIGIT(*chsar)))
			return false;
	return true;
	}

template<typename _Ty0> inline
	_Ty0*& inttochar(int i)
	{ // inttochar
	static _Ty0 buf[21];
	_Ty0 *p = buf + 19 + 1;
	if (i >= 0) 
		{while (i != 0)
			*--p = '0' + (i % 10), i /= 10;
		return p;}
	else{while (i != 0)
			*--p = '0' - (i % 10), i /= 10;
		*--p = '-';}
	return p;
	}

template<class _Ty0> inline
	int chartoint(_Ty0 *i)
	{ // chartoint
	int ret = 0;
	for( ; *i; )
		ret = 10 * ret + (*i++ - '0');
	return ret;
	}

template<class _Ty0> inline
	_Ty0 solver_x_intonly(const char *f_x, _Ty0 value)
	{ // unregularly solver
	const char *fx_p = f_x;
	char savt[21] = {0, };
	char *p_avt = savt;
	bool t = false;
	_Ty0 returning = 0, last;
	while(*fx_p)
		{
			if(t)
				if(ISDIGIT(*fx_p))
					*p_avt++ = *fx_p;
				else
				{
					last = chartoint(savt);
					t = false;
					for(int i = 0; i <= 20; i++)
						savt[i] = 0;
					p_avt = savt;
				}
			if(ISDIGIT(*fx_p) && !t)
				*p_avt++ = *fx_p,
				t = true;
			else 
				switch(*fx_p)
				{
				case '+':
					returning += last;
					break;
				case '-':
					returning -= last;
					break;
				case '*':
					returning *= last;
					break;
				case '/':
					returning /= last;
					break;
				case 'x':
					last = value;
					break;
				}
			*fx_p++;
		}
	return returning;
	}

template<class _Ty0> inline
	_Ty0 solver(const char *f_x, _Ty0 value)
	{ // regularly solver
	const char *fx_p = f_x;
	char tqwe[201];
	int mty = 0;
	int now = 0;
	for(int i = 0; i <= 200; i++)
		tqwe[i] = 0;

	while(*fx_p)
		{
			switch(*fx_p)
			{
				// closer(close gate)
			case '(':

				for( ; *fx_p != '(' && *fx_p != ')'; )
					tqwe[now++] = *fx_p++;
				mty++;

				// opener(open gate)
			case ')':

				mty--;

			}
			fx_p++;
		}

	fx_p = f_x;

	while(*fx_p)
		{
			switch(*fx_p)
			{
				// closer(close gate)
			case '(':

				mty++;

				// opener(open gate)
			case ')':

				mty--;

			default:

				if(!mty)
					tqwe[now++] = *fx_p;

			}
			fx_p++;
		}

	tqwe[now] = '+';

	return solver_x_intonly(tqwe, value);
	}

_X_LIB_END
#endif
#endif
/*
 *	The rollrat x_library
 *  Updated : 2013-06
 *	http://blog.naver.com/rollrat
 *  Copyright (c) 2009-2013 by rollrat. All right reserved.
 *  For more information, refer to the documentation on the license.
V0.1:0012****/

/*
 *	Special Library 'The Complex'
 *	Lastest Updated : 2013-06-01
 *	C/C++ syntax of the total complex made ​​possible by mobilizing header.
 *	If you understand all this, you C/C++ will have 
 *	completed all of the grammar.
L1_H*/

/*
 *	This item, is available free of charge. However, if you change 
 *	yourself, you can bring fatal consequences. This project is 
 *	based on the ethical issues of the information, and began to 
 *	improve the openness of the program. You can use anyone, but 
 *	please observe the clear copyright notice. When you beat this, 
 *	you can go into the legal action.
V0.1_x_Library_btype*/