/*************************************************
 *												 *
 *			RollRat Software Library			 *
 *												 *
 *	Copyright (c) rollrat. All rights reserved.  *
 *_______________________________________________*/

#pragma once

#ifndef _sprintf_
#define _sprintf_

#include "xtok.h"

 #pragma warning(disable: 4100 4345)

_X_LIB_BEGIN

		// MEMORY READER
#define _ADDRESSOF(v)   ( &reinterpret_cast<const char &>(v) )
#define _INTSIZEOF(n)   ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )

typedef char *  va_list;

#define va_start(ap,v)  ( ap = (va_list)_ADDRESSOF(v) + _INTSIZEOF(v) )
#define va_arg(ap,t)    ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) )
#define va_end(ap)      ( ap = (va_list)0 )

#define _check_eng_char(c) \
		((('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) ? 1 : 0 )
#define _check_numberic(c) (('0' <= c && c <= '9') ? 1 : 0)

template<class _Ty0>
	_Ty0 *sprintf(_Ty0 *w_judice_p, const _Ty0 * w_char_p, ... )
	{ // standard sprintf function
	const _Ty0 *p_start = w_char_p;
	_Ty0 *j_start = w_judice_p;
	_Ty0 pt_temp[10];
	_Ty0 pt_float[3];
	char *f_char_c, *i_char_c;

	va_list ap;
	va_start(ap, w_char_p); // set start point

	for( ; *p_start; p_start++)
		{
		switch(*p_start)
			{
		case '%':{
			for( ; (!_check_eng_char(*p_start))
					&& (*p_start != 0); p_start++){
				*pt_temp = *p_start;
				pt_temp++;
				}
			switch(*p_start)
				{
			case 'a': // Hexadecimal floating point, lowercase
			case 'b':
			case 'c': // char
				char i_temp = va_arg(ap, char);
				*j_start++ = i_temp;
				break;
			case 'd': // signed decimal integer
				int i_temp = va_arg(ap, int);
				i_char_c = itoas<char> 
					(i_temp);
				for( ; *i_char_c; i_char_c++)
					*j_start++ = *i_char_c;
				break;
			case 'e':
			case 'f': case ('F'):// signed float numberic
				int float_state = 21;
				if(f_char_c[0] == '.')
					{
					for( ; _check_numberic(*f_char_c);
						++f_char_c)
						*pt_float++ = *f_char_c;
					float_state = itoas<char>
						(pt_float);
					}
				float f_temp = va_arg(ap, float);
				f_char_c = ftoa<char>
					(f_temp);
				for( ; *f_char_c &&
					float_state; f_char_c++, float_state--)
					*j_start++ = *f_char_c;
				break;
			case 'g':
			case 'h':
			case 'i': case ('I'):// signed decimal integer
				int i_temp = va_arg(ap, int);
				i_char_c = itoas<char> 
					(i_temp);
				for( ; *i_char_c; i_char_c++)
					*j_start++ = *i_char_c;
				break;
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p': // point

			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':
			default:
				;
				}
			}
		case '\\':
			switch(*++p_start)
				{
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':
				};
		default:
			*j_start++ = *p_start;
			};
		}
	va_end(ap);
	return w_judice_p;
	}

_X_LIB_END
#endif

/*
 *	The rollrat x_library
 *  Updated : 2013-05
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