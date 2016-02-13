/*************************************************
 *												 *
 *			RollRat Software Library			 *
 *												 *
 *	Copyright (c) rollrat. All rights reserved.  *
 *_______________________________________________*/

#pragma once

#ifndef _xtok_
#define _xtok_

#include "xstrfmy.h"

 #pragma warning(disable: 4100 4345)

#if defined(_EX_SUCCESS)
_X_LIB_BEGIN
	
template<typename _Ty0> inline
	_Ty0*& itoas(int i)
	{ // itoa
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

template<typename _Ty11> inline
	_Ty11*& ftoa(float i)
	{ // float to char
	static _Ty11 buf[100];
	_Ty11 *p = buf + 99;
	if (i >= 0)
		{
		while(i >= 1)
			{
			*--p = '0' + ((int)i % 10);
			i /= 10;
			}
		*--p = '.';
		while(i > 0){
			i *= 10;
			*--p = '0' + (int)((int)i % 10);
			i -= (int)((int)i % 10);
			}
		}
	else
		{
		while(i >= 1)
			*--p = '0' + ((int)i % 10), i /= 10;
		*--p = '.';
		while(i != 0)
			*--p = '0' + (int)(i * 10), i -= (int)i % 10;
		*--p = '-';
		}
	return p;
	}

template<typename _Ty0> inline
	double atof(_Ty0* chars)
	{ // atof
	_Ty0* point = chars;
	double dev, floa, floating;
	bool sign = false;
	while(*point && isspace(*point))
		point++;
	if(!*point)
		return 0;
	else if(!isnumberic(*point))
		sign = ((*point++ - 43 == 0) ? 0 : 1);
	while(*point && isnumberic(*point) || *point == '.')
		{
			if(*point == '.')
			{
				*point++;
				while(*point && isnumberic(*point))
				{
					floa = floa * 10 + *point - 48;
					floating = 0.1 * floating;
					*point++;
				}
				floa = floa * floating;
			}
			else
			{
				dev = dev * 10 + dev - 48;
				*point++;
			}
		}
	if (sign)
		return -1 * (dev + floa);
	return dev + floa;
	}

template<typename _Ty0> inline
	bool isnumberic(_Ty0 what)
	{ // is numberic
	return '0' <= what && what <= '9';
	}

template<typename _Ty0> inline
	_Ty0 isspace(_Ty0 c_ch)
	{ // isspace
	switch(c_ch)
		{
		case '\n':
		case '\v':
		case '\f':
		case '\t':
		case '\r':
		case  ' ':
			return 1;
		}
	return 0;
	}

template<typename _Ty0>
	_Ty0* strtok(_Ty0* strToken, const _Ty0* strDelimit)
	{ // strtok
	char *str;
	const char *ctrl = strDelimit;
	unsigned char map[32];
	int count;

	for (count = 0; count < 32; count++)
		map[count] = 0;

	do {
		map[*ctrl >> 3] |= (1 << (*ctrl & 7));
	} while (*ctrl++);

	if (strToken)
		str = strToken;

	while ((map[*str >> 3] & (1 << (*str & 7))) && *str)
		str++;

	strToken = str;

	for ( ; *str ; str++ )
		if ( map[*str >> 3] & (1 << (*str & 7)) ) {
			*str++ = '\0';
			break;
		}

	if ( strToken == str ) 
		return 0;
	else 
		return strToken;
	}

_X_LIB_END
#endif

#endif
/*
 *	The rollrat x_library
 *  Updated : 2013-04
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