/*************************************************************************
 *
 *                    TETO. BYTE ASSEMBLER 0.1201.1.1.3
 *						INTERPRETER
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _INTERPRETER_
#define _INTERPRETER_

#include "String.h"

enum class if_condition{
	left_high,
	right_high,
	left_high_and_equal,
	right_high_and_equal,
	equal,
	nequal,
	_true, _false,
	error
};

#define _MUNJA_GUBUNJA		"\""

template<class _Inpret = char> class
	Interpreter
	{
	typedef typename basm::String<_Inpret> _MyStr;

public:

	if_condition get_condition_from_idealized_codeblock(_MyStr& _T)
		{
#define SWITCH(_dst)	if(_Tmp.Contains(_dst))
#define CASE(_dst)	else if(_Tmp.Contains(_dst))
#define DEFAULT		else



		_MyStr _Tmp = _T.Copy();

		SWITCH("<=")
			return if_condition::right_high_and_equal;
		CASE(">=")
			return if_condition::left_high_and_equal;
		CASE("<")
			return if_condition::right_high;
		CASE(">")
			return if_condition::left_high;
		CASE("==")
			return if_condition::equal;
		CASE("!=")
			return if_condition::nequal;
		CASE("<>")
			return if_condition::nequal;
		DEFAULT
			return if_condition::error;
		}

	_MyStr& condition_codeblock_syntax_analysis(_MyStr& _T)
		{
		_MyStr _Tmp = _T.Copy();

		

		}

	};

#endif