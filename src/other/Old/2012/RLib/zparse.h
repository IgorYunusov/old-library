/*=================================================

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

=================================================*/

#pragma once
#ifndef _zvprocessor_
#define _zvprocessor_

#include "zfrmy.h"

#if defined(_EZ_SUCCESS)
_Z_LIB_BEGIN
	
#define True	1
#define False	0
	
#define IS_OK( x )		x == 0
#define IS_NO( x )		x == 0 ? 1 : 0


	// Debug Handler
struct HANDLER {
	HANDLE hHandle;
	BOOL wState;
	char *wDebugLine;
	char cCarriageReturn;
	};

struct VOLTEX {
	HANDLE hHandle;
	UINT wDepth;
	int cFixedH;
	};

struct CONFIG {
	HANDLE hHandle;
	char *wKeySet;
	VOLTEX cFixedVoltex;
	};

struct DEBUG_LINE {
	char **dwLine;
	char cReturn;
	};

	// Voltex Sign
#define VOLTEX_CUSTOM		0xf0000
#define VOLTEX_STANDARD		0xe0000

#if defined(_MFX_MEMORY_CHARGE)
#if !defined(_MCH)
#define _MCH		0xffff
#endif
#else
#define _MCH		0xff
#endif

class _F_Debug
	{ // zero debug unit
public:
	
	_F_Debug()
	{
		configure_key_b[0] = '\\'; // return
		configure_key_b[1] = '*'; // magic key
		configure_key_b[2] = '&'; // start
		configure_key_b[3] = 'l'; // left
		configure_key_b[4] = 'r'; // right
		configure_key_b[5] = 'u'; // up
		configure_key_b[6] = 'd'; // down
		configure_key_b[7] = '@'; // reset key
		configure_key_b[8] = '!'; // annotation
		configure_key_b[9] = 'L'; // shift left
		configure_key_b[10] = 'R'; // shift right
		configure_key_b[11] = 'S'; // shift rand
		configure_key_b[12] = 'E'; // esc
	}

	BOOL CDECL SetProcessHandle(HANDLER hHandler)
	{ // set process handle

		dzHandle = hHandler;
		return True;

	}

	BOOL CDECL processor_configuration()
	{ // processor config

		int i;
		FIXED(char) *first_point = (cnConfig.wKeySet, IS_OK( GetEnoughMemoryCharge() )
			? cnConfig.wKeySet = new char[_MCH] : cnConfig.wKeySet = new char[_MCH << (0xf >> 1)]);
		
		for(i = 0; IS_OK( GetEnoughMemoryCharge() ) ? _MCH : _MCH << (0xf >> 1); i++)
			cnConfig.wKeySet[i] = 0;

		cnConfig.hHandle = CreateInheritHandle( dzHandle.hHandle );

		if(cnConfig.cFixedVoltex.wDepth & VOLTEX_STANDARD == 0xf)
			for(i = 0; i < 13; i++)
				cnConfig.wKeySet[i] = configure_key_b[i];
		else
			return False;

		return True;

	}

	HANDLE CreateInheritHandle(HANDLE hHandle)
	{

		HANDLE hHret = hHandle;
		hHret += hHret % (hHret << 0xf >> 0xf);
		return hHret;

	}

	FORCE_INLINE BOOL CDECL GetEnoughMemoryCharge()
	{
		if(_MCH >> (0xf >> 1))
			return True;
		else
			return False;

	}

private:

	HANDLER dzHandle;
	CONFIG cnConfig;
	int configure_key_b[13];

	};

_Z_LIB_END
#endif
#endif
/*
 *	The rollrat z_library
 *  Updated : 2013-06
 *	http://blog.naver.com/rollrat
 *  Copyright (c) 2009-2013 by rollrat. All right reserved.
 *  For more information, refer to the documentation on the license.
V0.1:0015****/

/*
 *	Special Library 'The Complex'
 *	Lastest Updated : 2013-06-15
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
V0.1_z_Library_btype*/