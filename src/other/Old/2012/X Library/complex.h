/*=================================================

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

=================================================*/

#pragma once
#ifndef _complex_
#define _complex_

#include "xstrfmy.h"
#include "tree.h"
#include "vector.h"

/*----------------------------------------------------------------

				The Complex Programmings Project

	The headers in C/C++ is all about grammar as much as 
	possible.

	LEVELS:

	+----------+---------------------------------------------+
	| TYPENAME | Expression of difficulty					 |
	+----------+---------------------------------------------+
	|   _Ty0   | General degree of difficulty.				 |
	|   _Ty1   | Intermediate level of difficulty.           |
	|   _Ty2   | High degree of difficulty.                  |
	|   _Ty3   | Expert.								     |
	|   _Ty4   | The public can not interpret.		         |
	|   _Ty5   | Producers can be interpreted only.		     |
	|   _Ty6   | Kiss my chuddies!							 |
	|   _Ty7   | I'll give you a yeot.						 |
	+----------+---------------------------------------------+

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

	CT LEVEL : (Complexity Tree)

	+----------+---------------------------------------------+
	| DEFINE												 |
	+----------+---------------------------------------------+
	| TREE_COMPLEXITY_ONE_LEVEL_BOUND_SHOT					 |
	| TREE_COMPLEXITY_ONE_LEVEL_UP_SHOT						 |
	| TREE_COMPLEXITY_TWO_LEVEL_SHOT						 |
	| TREE_COMPLEXITY_THREE_LEVEL							 |
	+----------+---------------------------------------------+

----------------------------------------------------------------*/

#if defined(_EX_SUCCESS)
_X_LIB_BEGIN
	


/*****************************************************************

		Project One	 Virtual Class - Made by rollrat.

*****************************************************************/


// ASSEBLME_CODE Matrix
typedef enum {
	Add = 0,
	Sub, Mul, Div, ShiftL, ShiftR,
	And, Not, Xor, Or, Cmp, Push, Pop,
	Inc, Dec,
} ASSEMBLE_CODE;

// BASIS VARIALBE Matrix
typedef enum {
	Int = 0,
	Char, Float, Double, Long, Unsigned,
	Long_Long,
} VARIABLE_CODE;

// Virtual Function Struct
typedef struct { 
	char *fn;	// function name
	VARIABLE_CODE size;
	void *value; // variable
} vft;

// Virtual Function Viewport
typedef struct {
	char *param1;
	char *param2;
	ASSEMBLE_CODE ykty;
	char *putted;
} vfx;

template<class _Ty3 = bool>
	class Virtual
	{ // virtual function maker

	vector<vft> VIRTUAL_VARIABLE_VECTOR;
	vector<vfx> VIRTUAL_FUNCTION_VECTOR;
	int now;
	_Ty3 started_;

public:

	void new_v(const char *variable_name, VARIABLE_CODE what)
		{
		vft new_buf;// = new vft;
		new_buf.fn = const_cast<char *> (variable_name);
		switch(what)
			{ // standard variable
		case Int: 
			new_buf.value = new int;
			new_buf.value = 0;
			new_buf.size = what;
			break;
		case Char: 
			new_buf.value = new char;
			new_buf.value = 0;
			new_buf.size = what;
			break;
		case Float: 
			new_buf.value = new float;
			new_buf.value = 0;
			new_buf.size = what;
			break;
		case Double: 
			new_buf.value = new double;
			new_buf.value = 0;
			new_buf.size = what;
			break;
		case Long: 
			new_buf.value = new long;
			new_buf.value = 0;
			new_buf.size = what;
			break;
		case Unsigned: 
			new_buf.value = new unsigned;
			new_buf.value = 0;
			new_buf.size = what;
			break;
		case Long_Long: 
			new_buf.value = new long long;
			new_buf.value = 0;
			new_buf.size = what;
			break;
			}
		VIRTUAL_VARIABLE_VECTOR.push_back(new_buf);
		}

	void put_f(vfx what)
		{
		VIRTUAL_FUNCTION_VECTOR.push_back(what);
		}

	void start()
		{
		now = 0;
		started_ = true;
		}

	vft next()
		{
		if(started_)
			return process_assemble(VIRTUAL_FUNCTION_VECTOR[now++]->_DATA);
		}

	void end()
		{
		now = 0;
		started_ = false;
		}

private:

	vft process_assemble(vfx what)
		{
		vft s = find_variable(what.putted);
		vft s1 = find_variable(what.param1);
		vft s2 = find_variable(what.param2);
		switch(what.ykty)
			{
		case Add:
			s.value = s1.value + s2.value;
			break;
		case Sub:
			s.value = s1.value - s2.value;
			break;
		case Mul:
			s.value = s1.value * s2.value;
			break;
		case Div:
			s.value = s1.value / s2.value;
			break;
		case ShiftL:
			s.value = s1.value << (int)s2.value;
			break;
		case ShiftR:
			s.value = s1.value >> (int)s2.value;
			break;
		case And:
			s.value = s1.value & s2.value;
			break;
		case Not:
			s.value = ~s1.value;
			break;
		case Xor:
			s.value = s1.value ^ s2.value;
			break;
		case Or:
			s.value = s1.value | s2.value;
			break;
		case Cmp:
			s.value = s1.value;
			break;
		case Push: // temporary param
			break;
		case Pop: // temporary param
			break;
		case Inc:
			s1.value += 1;
			break;
		case Dec:
			s1.value -= 1;
			break;
			}
		return s;
		}

	vft find_variable(char *what)
		{ // find variables
		vector<vft>::iterator h 
			= VIRTUAL_VARIABLE_VECTOR.front();
		vector<vft>::iterator t 
			= VIRTUAL_VARIABLE_VECTOR.back();
		for( ; h != t; h++)
			if((*h).fn == what)
				return *h;
		return *t;
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
 *	Special Library 'The Complex'
 *	Lastest Updated : 2013-05-28
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