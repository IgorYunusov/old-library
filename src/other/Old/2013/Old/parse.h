/*=================================================

			RollRat Software Expression

	Copyright (c) rollrat. All rights reserved.

=================================================*/

#pragma once
#ifndef _x_lib_parse_
#define _x_lib_parse_

#include "algorithm.h"

#if defined(_EX_SUCCESS)
_X_LIB_BEGIN

template<typename _Ty0> inline
	int strlen_dev(
		const _Ty0 *str)
	{ // strlen dev
	const _Ty0 *ch = str;
	while(*ch++)
		;
	return ((int)(ch - str - 1));
	}

template<typename _Ty0> inline
	_Ty0 *strrev_dev(
		_Ty0 *string
		)
	{ // strrev
	_Ty0 *start = string;
	_Ty0 *left = string;
	_Ty0 ch;
	while(*string++)
		;
	string -= 2;
	while (left < string)
		{
		ch = *left;
		*left++ = *string;
		*string-- = ch;
		}
	return(start);
	}

template<typename _Ty0> inline
	_Ty0 *split_ch(
		const _Ty0 *rCharText, 
		const _Ty0 fSplit, 
		int Arrange)
	{ // split character
	int i=0, f=0, Split=0;
	_Ty0 Buf[10][1000];
	while(rCharText[f])
		{
		if(rCharText[f] == fSplit)
			{
			Buf[Split][++i] = 0;
			Split++;
			i = 0;
			}
		if(rCharText[f] != fSplit)
			Buf[Split][i] = rCharText[f];
		else
			Buf[Split][--i] = rCharText[f];
		i++;
		f++;
		}
	if(rCharText[f] == 0)
		{
		Buf[Split][++i] = 0;
		Split++;
		i = 0;
		}
	if(rCharText[f] != fSplit)
		Buf[Split][i] = rCharText[f];
	else
		Buf[Split][--i] = rCharText[f];
	return Buf[Arrange];
	}

template<typename _Ty0> inline
	_Ty0 *left_ch(
		const _Ty0 *str,
		_Ty0 ch)
	{ // get character left
	while(*str && *str != ch)
		str++;
	if(*str == ch)
		return ((_Ty0 *)(++str));
	return (0);
	}

template<typename _Ty0> inline
	_Ty0 *right_ch(
		const _Ty0 *str,
		_Ty0 ch)
	{ // get character right
	_Ty0 *start = (_Ty0 *)str;
	while(*str++)
		;
	while(--str != start && *str != (ch))
		;
	if(*str == ch)
		return ((_Ty0 *)(++str));
	return (0);
	}

template<typename _Ty0> inline
	_Ty0 *replace_ch(
		const _Ty0 *str,
		_Ty0 _left,
		_Ty0 _right)
	{ // replace character
	int len = strlen_dev(str);
	int back = 0;
	_Ty0 *start = new _Ty0[len];
	for(int i = 0; i <= len; i++)
		start[i] = str[i];
	while(*start && *start != _left)
		start++, back++;
	*start = _right;
	return start - back;
	}

template<typename _Ty0> inline
	_Ty0 *replace_ch_n(
		const _Ty0 *str,
		_Ty0 _left,
		_Ty0 _right)
	{ // replace all character
	int len = strlen_dev(str);
	int back = 0;
	_Ty0 *start = new _Ty0[len];
	for(int i = 0; i <= len; i++)
		start[i] = str[i];
	while(*start)
		if(*start == _left)
			*start = _right;
		else
			start++, back++;
	return start - back;
	}

template<class _Ty>
	class parser
	{ // parser
	typedef typename __type<_Ty>::value_type _MyT;

	public:
		
	_MyT *strs;

	parser(_MyT *str)
		: strs(str)
		{ // entry point
		}

	explicit parser(const _MyT *str)
		: strs((_MyT *)(str))
		{ // entry point
		}

#ifndef _EXPLICITFF_
	explicit parser()
		: strs(0)
		{ // entry point
		}
#endif

	_MyT *cut(int _First)
		{ // cut all
		_MyT *_tmp = new _MyT[_First];
		for(int i = 0; i <= _First; i++)
			_tmp[i] = strs[i];
		return _tmp;
		}
	
	_MyT *cut_between(int _First, int _Second)
		{ // cut between
		_MyT *_tmp = new _MyT[_Second - _First];
		for(int i = _First, f = 0; i <= _Second; i++, f++)
			_tmp[f] = strs[i];
		return _tmp;
		}

	_MyT *cut_bind(int _LFirst, int _LSecond,
			int _RFirst, int _RSecond)
		{ // cut bind
		_MyT *_tmp = new _MyT[_LSecond + _RSecond - _LFirst - _RFirst];
		int f = 0;
		for(int i = _LFirst; i <= _LSecond; i++, f++)
			_tmp[f] = strs[i];
		for(int i = _RFirst; i <= _RSecond; i++, f++)
			_tmp[f] = strs[i];
		return _tmp;
		}

	};
	
	typedef enum _xdfef
		{
			OPERATOR_PLUS,
			OPERATOR_MINUS,
			OPERATOR_MULTIPLE,
			OPERATOR_DIVIDE,
			OPERATOR_MOD,
			OPERATOR_EQUAL,
		};

template<class _Ty = char>
	class _numberic_form
		: public parser<_Ty>
	{ // numberic form
	typedef typename __type<_Ty>::value_type _MyVT;

	public:

	#define OPERATOR_SET			"+-*/%="
	#define SPECIFICOPERATOR_SET	"sprt/root/sin/cos/tan/in/log/arcsin/arccos/arctan/csc/sec/cotan/"
	#define SET_SYMBOLS				"∧;∨;¬;⇒;→,iff;∀;∃;∃1,∃!;∴;∵;:=,:⇔;∈;∋;∉;=;≠;⊆;⊇;⊂;⊃;⊊;⊋;⊄;⊅;"
		//∫

	int solve_form_int(_Ty *_First)
		{ // solve form int
		int len = strlen_dev(_First);
		
		}

	bool IsNumberic(_Ty *_First)
		{ // is numberic
		while(*_First)
			if(!('0' <= *_First && *_First <= '9'))
				return false;
			else
				_First++;
		return true;
		}

	bool IsIni(_Ty _First)
		{ // is ini
		char set[] = OPERATOR_SET;
		for(int i = 1; i <= 6; i++)
			if(_First == set[i])
				return true;
		return false;
		}

	bool IsScs(_Ty *_That)
		{
		char set[] = SPECIFICOPERATOR_SET;
		char jjj[13];

		}

	};

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