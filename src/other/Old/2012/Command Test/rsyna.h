/*******************************************************************\
 *rsyna.h -- rollrat syntax analysis library.					   *
 *																   *
 *Purpose :														   *
 *		This library was created to parse the [RollRatParser].	   *
 *		Duty and for other purposes, if you want, you need to	   *
 *		modify the library in some you can.						   *
 *																   *
 *Dealing :														   *
 *		C/C++ Language, RollRatParser							   *
 *																   *
 *Available :													   *
 *		CompilerParser, Syntax analyzer							   *
 *																   *
 *			Copyright (c) rollrat. All rights reserved.			   *
 *																   *
\*******************************************************************/

#pragma once
#ifndef _ROLLRAT_SYNA_
#define _ROLLRAT_SYNA_

#include "rtools.h"

#define NOTE( _text )
#define _STRUCTURE	typedef struct
#define _ENUM		enum 

/*
 *re-define type r-s-s-t
 */
typedef int				PARAM;
typedef char	*		PATTERN;
typedef char	*		REPLACE;
typedef char	*		TARGET;
typedef	char	*		MATCH;
typedef long			MATCH_POINT;

/*
 *if this os is x64
 */
#if defined(_current_version_x32) || !defined(_WIN32) || defined(_X32_)

typedef unsigned __int64		INS_ULONG_PTR, *PINS_ULONG_PTR, OPCODE;

#else

typedef _w64 unsigned long		INS_ULONG_PTR, *PINS_ULONG_PTR, OPCODE;

#endif

/*
 *		Basically struct
 */
_STRUCTURE Tag_Pattern_Return
{
	PATTERN		pat_o_pattern;
	PATTERN		pat_n_pattern;
	PATTERN		pat_p_pattern;

	PARAM		par_o_range;
	PARAM		par_n_range;
	PARAM		par_p_range;

	OPCODE		op_code;

}	PRET_TTEN, *LPRET_TTEN;

_STRUCTURE Tag_Pattern_Receve
{
	PATTERN		pattern;
	OPCODE		op_code;

}	PRET_RECE, *LPRET_RECE;

#define ERROR_NOTHING		0xffffffff

#define _SPEC_BASIC		'\\' // character '\'

PARAM Count_CAP(LPRET_RECE pece)
{
	int countcap;
	if ( pece->pattern == 0 )
		return ERROR_NOTHING;
	countcap = CountChar(pece->pattern,_SPEC_BASIC);
	return countcap;
}

char** Matcher(MATCH cMatch, LPRET_RECE pece)
{
	int countcap = Count_CAP(pece);
	int i=0;
	char* buf;
	char* buf_pat;
	int pat_count=0;
	char** buffer;
	buf = pece->pattern;
	while(buf[i])
	{
		switch(buf[i])
		{
		case '\\':
			if(buf[++i] == '\\')
			{
				buf_pat[pat_count++] = '\\';
			}
			else if(buf[++i] == '[')
			{
				buf_pat[pat_count++] = '[';
			}
			else if(buf[++i] == ']')
			{
				buf_pat[pat_count++] = ']';
			}
			else if(buf[++i] == '(')
			{
				buf_pat[pat_count++] = '(';
			}
			else if(buf[++i] == ')')
			{
				buf_pat[pat_count++] = ')';
			}
		}
	}
	return buffer;
}



#endif