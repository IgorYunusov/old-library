/*************************************************
 *												 *
 *			RollRat Software Library			 *
 *												 *
 *	Copyright (c) rollrat. All rights reserved.  *
 *_______________________________________________*/

#pragma once

#ifndef _solve_
#define _solve_

#include "tree.h"
#include "xstring.h"
#include "swap.h"

 #pragma warning(disable: 4100 4345)

#if defined(_EX_SUCCESS)
_X_LIB_BEGIN
	
template<class _Ty1 = char>
	class equa
	{ // equation solver
	stack<_Ty1> parenthesis;
	string<> str;

public:

	equa()
		:{}

	void SetText(_Ty1 *that)
		{ // string put
		str < that;
		}

	void SetText(string<> that)
		{ // string put
		str < that;
		}

	void Solve()
		{
		}

private:

	char *itoa(long val, char *buf)
		{ // itoa
		char *p, *f, temp;
		unsigned bufs; // check point
		p = buf; // first point
		if(val < 0)
			{ // check signal of number
			*p++ = '-';
			// abs check
			val = ((unsigned long)(-(long)(val)));}
		f = p;
		do { // put all
			bufs = ((unsigned)(val % 10));
			val /= 10;
			*p++ = ((char)(bufs + '0'));
		} while(val > 0);
		
		*p-- = '\0'; // last \0 lit
		return buf;
		}

	char *ftoa(double val, char *buf)
		{ // float to char
		char *p, *f, temp;
		unsigned bufs;
		p = buf;
		if(val < 0)
			{ // check signal of number
			*p++ = '-';
			// abs check
			val = ((unsigned double)(-(double)(val)));}
		f = p;
		do { // put digit
			bufs = ((unsigned)(val % 10));
			val /= 10;
			*p++ = ((char)(bufs + '0'));
		} while(val > 0);
		*p-- = '\0'; // last \0 lit
		return buf;
		}

	};

_X_LIB_END
#endif

#endif
/*
 *	The rollrat x_library
 *  Updated : 2013-05
 *	http://blog.naver.com/rollrat
 *  Copyright (c) 2009-2013 by rollrat. All right reserved.
 *  For more information, refer to the documentation on the license.
V0.1:0012****/

/*
 *	This item, is available free of charge. However, if you change 
 *	yourself, you can bring fatal consequences. This project is 
 *	based on the ethical issues of the information, and began to 
 *	improve the openness of the program. You can use anyone, but 
 *	please observe the clear copyright notice. When you beat this, 
 *	you can go into the legal action.
V0.1_x_Library_btype*/