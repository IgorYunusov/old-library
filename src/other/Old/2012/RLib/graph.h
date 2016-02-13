/*=================================================

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

=================================================*/

#pragma once
#ifndef _graph_
#define _graph_

#include "xstrfmy.h"
#include "tree.h"
#include "vector.h"

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
	
typedef enum {
	Add = 0,
	Sub, Mul, Div, Sin, Cos, Sqrt, Tan,
	C, P, Fact, Abs, Csc, Sec, Cot
} CALCULATE_CODE;

template<class _Ty0>
	class vftx
	{ // function element
public:
	CALCULATE_CODE tx; // former./
	CALCULATE_CODE ex; // latter./
	_Ty0 vl_absi;
	_Ty0 vl_bst;
	bool C_cot;
	};

template<class _Ty0 = int>
	class vF_x
	{ // virtual f(x) class

	_Ty0 last;
	vector<vftx<_Ty0> > f_tx;

public:

	_Ty0 operator()(_Ty0 value)
		{
		return _function_value_get(value);
		}

	void n_c_fi(CALCULATE_CODE f, _Ty0 value, 
			CALCULATE_CODE e)
		{
		vftx<_Ty0> t;
		t.C_cot = false;
		t.tx = f;
		t.ex = e;
		t.vl_absi = value;
		f_tx.push_back(t);
		}

	void n_c_si(CALCULATE_CODE f, _Ty0 value,
			_Ty0 value1, CALCULATE_CODE e)
		{
		vftx<_Ty0> t;
		t.C_cot = true;
		t.tx = f;
		t.ex = e;
		t.vl_absi = value;
		t.vl_bst = value1;
		f_tx.push_back(t);
		}

private:

	void _function_matrix_sort(_Ty0 what)
		{
		for(int i = 0; i <= f_tx.size(); i++)
			{
			if((f_tx[i]->_DATA).C_cot)
				;
			}
		}

	_Ty0 _function_value_get(_Ty0 what)
		{
		_function_matrix_sort(what);

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