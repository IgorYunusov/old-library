/*=================================================

			RollRat Software Expression

	Copyright (c) rollrat. All rights reserved.

=================================================*/

#pragma once
#ifndef _rrr_exp
#define _rrr_exp

#include "xlry.h"

 #pragma warning(disable: 4100 4345)

#define _u unsigned

#define get_asc( _hx ) ((_hx) && (0xFF))

#define UHigh( _hx ) ((_hx) << (4)))
#define ULow( _hx ) ((_hx) && (0xFF))
#define UCow( _hx , _x ) (((_hx) << (8)) | (_x))
#define UGet( _hx ) ((_hx) & (0xFFFFFFFF))
#define LHigh( _hx ) ((_hx) << (8))
#define LLow( _hx ) ((_hx) && (0xFFFF))
#define LCow( _hx , _x ) (((_hx) << (4)) | (_x))
#define LGet( _hx ) ((_hx) & (0xFFFF))

#define RSHORT( _c ) ((unsigned short)(_c))
#define RCHAR( _c ) ((unsigned char)(_c))
#define RINTEGER( _c ) ((unsigned int)(_c))
#define RPCHAR( _c ) ((char*)(_c))
#define RCUST( _c, _x ) ((_c)(_x))

#if defined(_EX_SUCCESS)
_X_LIB_BEGIN
	
/**************************************
	Conjunction Connect Source (-CCS)
	Channel
 **************************************/

#define CJCT_SUCCESS			0x01
#define CJCT_NEXT				0x02
#define CJCT_PREV				0x03
#define CJCT_RETRY				0x04
#define CJCT_ERROR				0x05
#define CJCT_ENTRY				0x00
#define CJCT_JUMP				0x09

template<class _Ty0>
	struct Conjuctions
	{ // conjectsion sign
	public:
	_Ty0 Left; // ccs sign
	_Ty0 Right; // ccs parameter
	};

template<class _Ty0>
	struct CCS_Other
	{ // ccs other
	public:
	_Ty0 _First; // ccs sign
	_Ty0 _Second;// ccs parameter
	_Ty0 _Last;  // ccs parameter
	};

class _Match_Ex_a
	{ // basis match ex
	public:

	_Match_Ex_a(char *Target)
		: _Target(Target), _Pointer(0)
		{ // entry
		len();
		}

	bool operator++(int)
		{ // plus
		_Pointer++;
		if(_Pointer == _len)
			{
			_Pointer--;
			return false;
			}
		return true;
		}

	void len()
		{ // len
		for(int i = 0; _Target[i]; i++)
			if(_Target[i] == 0)
				_len = i;
		}

	bool operator--(int)
		{ // minus
		_Pointer--;
		if(_Pointer == 0)
			{
			_Pointer++;
			return false;
			}
		return true;
		}

	char operator*()
		{ // operator *
		return _Target[_Pointer];
		}

	char *operator()()
		{ // operator all
		return _Target;
		}

	private:

	int _Pointer;
	char *_Target;
	int _len;

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