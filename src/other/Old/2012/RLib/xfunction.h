/*=================================================

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

=================================================*/

#pragma once
#ifndef _funciton_
#define _function_

#include "xstrfmy.h"
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
	
// Flag of type
#define FLAGS_PARSE_FUNCTIONOFX 0
#define FLAGS_PARSE_FUNCTIONOFY 1

// Flag of double type
#define FLAGS_DIGIT			0xff
#define FLAGS_NONDIGIT		0x100
#define FLAGS_OPERATOR		0x101

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

template<class _Ty3C = long double>
	class Function
	{ // function processing

	char *buf_function;
	tree<char> g_noints;
	_Ty3C lastest;
	char *digit_max;
	char *char_max;
	int p;

public:

	Function()
		{
		digit_max = new char[30];
		char_max = new char[10];
		for(int i = 0; i <= 31; i++)
			digit_max[i] = 0;
		for(int f = 0; f <= 11; f++)
			char_max[f] = 0;
		}

	void Processing(char *function_plot)
		{
		buf_function = function_plot;
		parse();
		}

	_Ty3C Get(_Ty3C value)
		{
		lastest = 0;
		for(int i = 0; i < p; i++)
			g_noints.leave();
		for(int i = 0; i < p; i++, g_noints.visit_left())
			{
			if((g_noints.left())->_data == 'x')
				{
				switch((g_noints.right())->_data)
					{
				case '+':
					lastest += value;
					break;
				case '-':
					lastest -= value;
					break;
				case '*':
					lastest *= value;
					break;
				case '/':
					lastest /= value;
					break;
					}
				}
			else
				{
					switch((g_noints.right())->_data)
					{
					case '+':
						lastest += (g_noints.left())->_data;
						break;
					case '-':
						lastest -= (g_noints.left())->_data;
						break;
					case '*':
						lastest *= (g_noints.left())->_data;
						break;
					case '/':
						lastest /= (g_noints.left())->_data;
						break;
					}
				}
			}
		return lastest;
		}

private:

	// only understand by standard display
	// ex) (x + 2) ^ 3 + sqrt(x) * x + 2

	void parse()
		{
		char *ft_digit = digit_max;
		bool t = false;
		p = 0;
		for( ; *buf_function; *buf_function++)
			{
			switch(*buf_function)
				{
			case ' ':
				t = true;

				if(char_max == "sqrt")
					;

				if(IsDigit(digit_max))
					g_noints.left(chartoint(digit_max));

				for(int i = 0; i <= 31; i++)
					digit_max[i] = 0;

				break;
			case 'X':
			case 'x':
				if( t )
					g_noints.left('x'),
					t = false;
				break;
			default:

				if(ISDIGIT(*buf_function))
					*ft_digit++ = *buf_function;

				else if(ISOPERATOR(*buf_function))
					g_noints.right(*buf_function),
					g_noints.visit_left(), p++;

				else if(ISCHAR(*buf_function))
					*char_max++ = *buf_function;

				}
			}
		}
	};

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