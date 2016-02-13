/*=================================================

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

=================================================*/

#pragma once
#ifndef _xregex_
#define _xregex_

#include "xstrfmy.h"
#include "xalloc.h"

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
	
#define REGEX_OPERATE_LENGALPHABAT	"abcdefghijklmnopqrstuwxyz"
#define REGEX_OPERATE_CENGALPHABAT	"ABCDEFGHIJKLMNOPQRSTUWXYZ"
#define REGEX_OPERATE_ZEROTONINE	"0123456789"

namespace _regex_sign{
// Regular Sign List - ENG or NUM
typedef enum {
	E_CHECK_LENGA = 0, // check lower case english alphabat
	E_CHECK_CENGA,	// check capital english alphabat
	E_CHECK_NUM,	 // check numberic
}	_regex_sign_check_a;

// Regular Sign List - Grammar - Last Check List
typedef enum {
	/*  .  */ G_CHECK_DOT = 0, // Matches any single character '.'
	/* [ ] */ G_CHECK_BBRACKET,	// A bracket expression '[ ]'
	/* [^] */ G_CHECK_RBBRACKET,	 // Matches a single character that is not \
				contained within the brackets '[^ ]'
	/*  ^  */ G_CHECK_GRADE, // Matches the starting position within the string '^'
	/*  $  */ G_CHECK_DOLLAR, // Matches the ending position of the string or \
				the position just before a string-ending newline ' $'
	/* ( ) */ G_CHECK_SBRACKET, // Defines a marked subexpression '( )'
	/*  *  */ G_CHECK_ASTERISK, // Matches the preceding element zero or more times '*'
	/* { } */ G_CHECK_MBRACKET, // Matches the preceding element at least m and \
				not more than n times '{m, n}'
	/*  ?  */ G_CHECK_GREED, // Matches the preceding element zero or one time '?'
	/*  |  */ G_CHECK_CHOICE, // The choice (also known as alternation or set \
				union) operator matches either the expression before or the \
				expression after the operator '|'
	G_NONE,
}	_regex_sign_check_b;

// Irregular Sign List - Standard Flags
typedef enum {
	_Mark_Standard = 0, // using standard regex library
	_Mark_Extend, // using standard extend regex library(include standard lib)
	_Mark_RollRat, // using rollrat regex library(be excluded standard and extend)
	_Mark_All, // using all of regex(with standard, extend, rollrat)
}	_regex_sign_check_c;

// Regular And STL regex lib metacharacters list - First Check List \
		troublesome...
typedef enum {
	_Meta_lpar = '(',
	_Meta_rpar = ')',
	_Meta_dlr = '$',
	_Meta_caret = '^',
	_Meta_dot = '.',
	_Meta_star = '*',
	_Meta_plus = '+',
	_Meta_query = '?',
	_Meta_lsq = '[',
	_Meta_rsq = ']',
	_Meta_bar = '|',
	_Meta_esc = '\\',
	_Meta_dash = '-',
	_Meta_lbr = '{',
	_Meta_rbr = '}',
	_Meta_comma = ',',
	_Meta_colon = ':',
	_Meta_equal = '=',
	_Meta_exc = '!',
	_Meta_eos = -1,
	_Meta_num = 1,
	_Meta_nl = '\n',
	_Meta_cr = '\r',
	_Meta_bsp = '\b',
	_Meta_chr = 0,
	_Meta_chr_b = -8,
	_Sign_None = -2,
}	_regex_sign_check_d;
#define _META_CHECK _regex_sign::
// CHECK : http://en.wikipedia.org/wiki/Regular_expression
}

template<class _Ty2A = char>
	class _REGEX_MODULE
	{	// Loof function api within char, char_ptr or char array
public:

	INLINE void _check_lastpoint(_Ty2A *_Left)
		{ // move point last of ptr
		while(*_Left++)
			;
		}

	INLINE _Ty2A _check_length(const _Ty2A *_Left, _Ty2A _Hide_Right = 255)
		{ // get length
		const _Ty2A *_Ptr = _Left;
		_Ty2A C_H;
		for(C_H = 0; C_H < _Hide_Right && *_Ptr; _Ptr++, C_H++)
			; // go end of ptr
		return ((int)_Ptr - (int)_Left - 1); // check return
		}
	
	INLINE _Ty2A _check_strchr(const _Ty2A *_Left, _Ty2A _Right)
		{ // similar c standard lib in strchr but loof
		for( ; *_Left; )
			if(*_Left++ == _Right) // Exist Check
				return _Right;
		return 0; // if not finded...
		}

	INLINE _Ty2A _check_findfirst(_Ty2A *_Left, _Ty2A _Right)
		{ // check find first
		_Ty2A *_Ptr = _Left;
		for(int i = 0; *_Ptr; i++)
			if(*_Ptr++ == _Right)
				return i;
		return -1;
		}

	INLINE _Ty2A *_check_strchrl(_Ty2A *_Left, 
		_Ty2A _Right, _Ty2A _Times)
		{ // strchr with loof times
		int i = 1;
		_Ty2A *_Ptr = _Left;
		for(bool x = false; *_Ptr // find match
				&& x ? i != _Times : 1; x ? i++ : 0)
			if(*_Ptr++ == _Right)
				x = true;
			else if(x)
				x = false, i = 1;
		return _Ptr - _Times + 1; // check return
		}

	};
	
#define ISCHARENG(x) ('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z')
#define ISNUMBERIC(x) ('0' <= x && x <= '9')

template<class _Ty2A = char>
	class _REGEX_ENGINE
	{	// regex engine
public:

	void _Reset()
		{
		_Level1Engine_Now_Ended_State = false;
		}

	void _Level1Engine_ready(_Ty2A *_Regex_Pattern, 
			_Ty2A *_LastPoint)
		{ // ready engine core
		Pattern = _Regex_Pattern; _EndPoint = _LastPoint;
		_FirstPoint = _Regex_Pattern; _LastPoint = _FirstPoint;
		_Level1Engine_Now_Ended_State = true;
		}

	FORCE_INLINE bool _Level1Engine_nextprocess(_Ty2A _Now_Characters, // check for pointer
			_regex_sign::_regex_sign_check_d 
				_check_d_point = _regex_sign::_Meta_chr)
		{ // next process core
		switch(_check_regex_sign(*_LastPoint))
			{
		case _META_CHECK _Meta_chr:

			if(_check_d_point == _regex_sign::_Meta_chr)
				if(_Now_Characters == *_LastPoint)
					return true;
				else 
					return false;
			else if(_check_d_point == _regex_sign::_Meta_chr_b)
				if(_Now_Characters == *_LastPoint)
					return true;
				else 
					return false;
			else if(_check_d_point == _regex_sign::_Meta_num)
				if(_Now_Characters == *_LastPoint)
					return true;
				else 
					return false;
			else
				if(_check_d_point == _regex_sign::_Meta_esc)
					return _check_regex_esc(*(_Ty2A *)
						(AddressOf(_Now_Characters) + sizeof(_Ty2A)));
				else 
					return false;

		case _META_CHECK _Meta_chr_b:
			
			if(_check_d_point == _regex_sign::_Meta_chr)
				if(_Now_Characters == *_LastPoint)
					return true;
				else 
					return false;
			else if(_check_d_point == _regex_sign::_Meta_chr_b)
				if(_Now_Characters == *_LastPoint)
					return true;
				else 
					return false;
			else if(_check_d_point == _regex_sign::_Meta_num)
				if(_Now_Characters == *_LastPoint)
					return true;
				else 
					return false;
			else
				if(_check_d_point == _regex_sign::_Meta_esc)
					return _check_regex_esc(*(_Ty2A *)
						(AddressOf(_Now_Characters) + sizeof(_Ty2A)));
				else
					return false;

		case _META_CHECK _Meta_esc:

			return _Level1Engine_nextprocess(_Now_Characters, _regex_sign::_Meta_esc);

		case _META_CHECK _Meta_caret:
		case _META_CHECK _Meta_colon:
		case _META_CHECK _Meta_lpar:
		case _META_CHECK _Meta_rpar:
		case _META_CHECK _Meta_dlr:
		case _META_CHECK _Meta_dot:

			// use not _check_strchr for speed
			if(ISCHARENG(_Now_Characters))
				return true;
			else if(ISNUMBERIC(_Now_Characters))
				return true;
			else
				return false;

		case _META_CHECK _Meta_star:

			if(!(*_CharMemory))
				return _Level1Engine_nextprocess(_Now_Characters, _regex_sign::_Meta_chr);
			else
				return _check_regex_star(_Now_Characters);

		case _META_CHECK _Meta_plus:
		case _META_CHECK _Meta_query:
		case _META_CHECK _Meta_lsq:
		case _META_CHECK _Meta_rsq:
		case _META_CHECK _Meta_bar:
		case _META_CHECK _Meta_dash:
		case _META_CHECK _Meta_lbr:
		case _META_CHECK _Meta_rbr:
		case _META_CHECK _Meta_comma:
		case _META_CHECK _Meta_equal:
		case _META_CHECK _Meta_exc:
		case _META_CHECK _Meta_nl:
		case _META_CHECK _Meta_cr:
		case _META_CHECK _Meta_bsp:
			}
		}

	bool _Level1Engine_nowended() const
		{ // if ended now ended bool
		return _Level1Engine_Now_Ended_State;
		}

	FORCE_INLINE bool _check_regex_esc(_Ty2A what)
		{ // processing esc meta

		}
	
	FORCE_INLINE bool _check_regex_star(_Ty2A what)
		{ // processing star meta
		if(*_LastPoint == '.')
			if(what != *(_LastPoint + 2))
				return true;
			else
				return false;
		if(*_LastPoint == '?')
			if(what == *(_LastPoint + 2))
				return true;
			else
				return false;
		if(ISCHARENG(*_LastPoint))
			if(what == *_LastPoint)
				return false;
			else
				return true;
		}

	FORCE_INLINE _regex_sign::_regex_sign_check_d 
		_check_regex_sign(_Ty2A what)
		{ // return properly regex sign
		switch(what)
			{
		case '(': return _regex_sign::_Meta_lpar;
		case ')': return _regex_sign::_Meta_rpar;
		case '$': return _regex_sign::_Meta_dlr;
		case '^': return _regex_sign::_Meta_caret;
		case '.': return _regex_sign::_Meta_dot;
		case '*': return _regex_sign::_Meta_star;
		case '+': return _regex_sign::_Meta_plus;
		case '?': return _regex_sign::_Meta_query;
		case '[': return _regex_sign::_Meta_lsq;
		case ']': return _regex_sign::_Meta_rsq;
		case '|': return _regex_sign::_Meta_bar;
		case '\\': return _regex_sign::_Meta_esc;
		case '-': return _regex_sign::_Meta_dash;
		case '{': return _regex_sign::_Meta_lbr;
		case '}': return _regex_sign::_Meta_rbr;
		case ',': return _regex_sign::_Meta_comma;
		case ':': return _regex_sign::_Meta_colon;
		case '=': return _regex_sign::_Meta_equal;
		case '!': return _regex_sign::_Meta_exc;
		case '\n': return _regex_sign::_Meta_nl;
		case '\r': return _regex_sign::_Meta_cr;
		case '\b': return _regex_sign::_Meta_bsp;

		default:

			if(_REGEX_MODULE<_Ty2A>::_check_strchr(REGEX_OPERATE_LENGALPHABAT, what))
				return _regex_sign::_Meta_chr;
			if(_REGEX_MODULE<_Ty2A>::_check_strchr(REGEX_OPERATE_CENGALPHABAT, what))
				return _regex_sign::_Meta_chr_b;
			if(_REGEX_MODULE<_Ty2A>::_check_strchr(REGEX_OPERATE_ZEROTONINE, what))
				return _regex_sign::_Meta_num;
			}

		return _regex_sign::_Sign_None;
		}

private:

	bool _Level1Engine_Now_Ended_State;
	_Ty2A *Pattern;
	_Ty2A *_LastPoint;
	_Ty2A *_FirstPoint;
	_Ty2A *_EndPoint;
	_Ty2A *_CharMemory;

	};

		// STANDARD REGEX ENGINE
template<class _Ty5A = char>
	class regex
	{	// regex core
	typedef int _Access_To;
public:

	regex(_Ty5A *_Ptr, 
			_Ty5A *_Target)
		{ // entry point 1
		_Reset(_Ptr, _REGEX_MODULE<_Ty5A>::_check_lastpoint(_Ptr),
			_Target, _REGEX_MODULE<_Ty5A>::_check_lastpoint(_Target),
			_regex_sign::_Mark_Standard);
		}

	explicit regex(_Ty5A *_Ptr, _Ty5A *_Target, 
		_regex_sign::_regex_sign_check_c _Flags)
		{ // entry point 2
		_Reset(_Ptr, _REGEX_MODULE<_Ty5A>::_check_lastpoint(_Ptr),
			_Target, _REGEX_MODULE<_Ty5A>::_check_lastpoint(_Target),
			(_regex_sign::_regex_sign_check_c)_Flags);
		}

	template<class _In_Ptr_>
		regex(_In_Ptr_ *_Ptr, _In_Ptr_ *_Ptr_L,
			_In_Ptr_ *_Target, _In_Ptr_ *_Target_L,
			_regex_sign::_regex_sign_check_c _Flags)
		{ // entry point 3
		_Reset(_Ptr, _Ptr_L, _Target, 
			_Target_L, _Flags, (_Access_To)(0))
		}

	template<class _In_Ptr_>
		regex(_In_Ptr_ *_Ptr, 
			_In_Ptr_ *_Target)
		{ // entry point 4
		_Reset(_Ptr, _REGEX_MODULE<_Ty5A>::_check_lastpoint(_Ptr),
			_Target, _REGEX_MODULE<_Ty5A>::_check_lastpoint(_Target),
			_regex_sign::_Mark_Standard, (_Access_To)(0));
		}

	template<class _In_Ptr_>
		regex(_In_Ptr_ *_Ptr, 
			_In_Ptr_ *_Target,
				_regex_sign::_regex_sign_check_c _Flags)
		{ // entry point 4
		_Reset(_Ptr, _REGEX_MODULE<_Ty5A>::_check_lastpoint(_Ptr),
			_Target, _REGEX_MODULE<_Ty5A>::_check_lastpoint(_Target),
			_Flags, (_Access_To)(0));
		}

	void _Processing()
		{ // process regex
		Regex_Engine._Reset();
		Regex_Engine._Level1Engine_ready(Pattern, Pattern_L);
		}

private:

	void _Reset(_Ty5A *_Ptr_S, _Ty5A *_Ptr_E, 
		_Ty5A *_Pa_Ptr_S, _Ty5A *_Pa_Ptr_E, 
			_regex_sign::_regex_sign_check_c _Flags)
		{ // reset regex library
		Pattern = _Ptr_S; Pattern_L = _Ptr_E;
		Target = _Pa_Ptr_S; Target_L = _Pa_Ptr_E;
		_Flag = _Flags;
		}

	template<class _Others>
		void _Reset(_Others *_Ptr_S, _Others *_Ptr_E, 
			_Others *_Pa_Ptr_S, _Others *_Pa_Ptr_E, 
				_regex_sign::_regex_sign_check_c _Flags, _Access_To)
		{ // reset regex library
		Pattern = (_Ty5A *)_Ptr_S; Pattern_L = (_Ty5A *)_Ptr_E;
		Target = (_Ty5A *)_Pa_Ptr_S; Target_L = (_Ty5A *)_Pa_Ptr_E;
		_Flag = _Flags;
		}

	_Ty5A *Pattern, *Pattern_L;
	_Ty5A *Target, *Target_L;
	_Ty5A **Match;
	_Ty5A *Replace;
	_regex_sign::_regex_sign_check_c _Flag;
	_REGEX_ENGINE<_Ty5A> Regex_Engine;

	int Match_Size;

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