/*************************************************************************
 *
 * FILE NAME : sprintf.c - std string print fortmat
 *
 * RollRat ISO Standard C Library
 *
 *
 * CREATION : 2014.12.07
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#include "_stdio.h"
#include "string.h"
#include <stdarg.h>

int _vsprintf_aes(
	char *buf,
	const char *fmt,
	va_list ap
	);

int _sprintf_aes(
	char *str,
	const char *format,
	...
	)
{
	va_list ap;
	int ret;

	va_start(ap, format);
	ret = _vsprintf_aes(str, format, ap);
	va_end(ap);

	return ret;
}

int _vsprintf_aes(
	char *buf,
	const char *fmt,
	va_list ap
	)
{
	int sign;	/*	integer sign		*/
	int zs;		/*	zero sign			*/
	int num;	/*	number sign			*/
	int hs;		/*	hex sign			*/
	int ms;		/*	minus sign			*/
	int ds;		/*	dot sign			*/
	int ps;		/*	precision sign		*/
	int ss;		/*	space sign			*/
	int nm;		/*	number system		*/
	int sc;		/*	string count		*/
	int xul;	/*	hex upper or lower	*/
	int _i;		/*	integer temp		*/
	char c;
	char *ptr;
	const char *fptr;

	ptr = buf;
	if ( ! (fptr = fmt) )
		return (-1);

	/* standard printf format */
	while(c = *fptr++) {
		ds = 0;
		zs = 0;
		sign = 0;
		ms = 0;
		num = 0;
		hs = 0;
		ss = 0;
		nm = 0;
		ps = 0;
		xul = 0;

		switch( c ) 
		{
		case '\\':

			*ptr++ = (c = *fptr++);
			break;

		case '%':

			//
			//	Setting Flags
			//
		gb_s:
			switch( *fptr )
			{
			case '#': hs = 1;
				c = *fptr++; goto gb_s;
			case '+': sign = 1;
				c = *fptr++; goto gb_s;
			case '-': ms = 1;
				c = *fptr++; goto gb_s;
			case '0': zs = 1;
				c = *fptr++; goto gb_s;
			case '.': ds = 1;
				c = *fptr++; goto gb_s;
			case ' ': ss = 1;
				c = *fptr++; goto gb_s;
			case '*': ps = 1;
				break;
			case '%':
				c = *fptr++; break; // end of flag
				break;
			}
			
			if( _isnumeric( *fptr ) )
				num = (c = *fptr++) & 0xf;

			//
			//	Set ptr
			//
			switch ( c = *fptr++ )
			{
			case 'd': nm = 8;
			case 'b': nm ^= 10;
			case 'o': nm ^= 8;
				{
					int _j;
					_i = va_arg( ap, int );

					if (!_i) {
						*ptr++ = '0';
						break;
					}

					// count number size
					for (_j = 0, sc = 0; _i; _i /= nm, sc++)
						_j = _j * nm + _i % nm;

					if( sign )
					{
						if( _i > 0 )
							*ptr++ = '+';
						else if( _i < 0 )
							*ptr++ = '-';
						sign = 0;
					}

					if (num = 0)
						for ( ; sc; _j /= nm, sc--)
							*ptr++ = (char)(_j % nm + '0');
					else if (sc > num) {
						for( ; sc; _j /= nm, sc--)
							if(sc > num)
								*ptr++ = (char)(_j % nm + '0');
					} else if (sc <= num) {
						if (ms && sc != num) {
							for ( ; sc; _j /= nm, sc--, num--)
								*ptr++ = (char)(_j % nm + '0');
							if (zs)
								for (; num; num--)
									*ptr++ = '0';
							else
								for (; num; num--)
									*ptr++ = ' ';
							ms = 0;
						} else {
							if (zs)
								for (; num; num--)
									*ptr++ = '0';
							else
								for (; num; num--)
									*ptr++ = ' ';
							ms = 0;
							for ( ; sc; _j /= nm, sc--)
								*ptr++ = (char)(_j % nm + '0');
						}
					}
				}
				break;
			case 'u': case 'D': nm = 8;
			case 'B': nm ^= 10;
			case 'O': nm ^= 8;
				{
					unsigned int _ui = va_arg( ap, unsigned int );
					unsigned int _j;

					if (!_ui) {
						*ptr++ = '0';
						break;
					}

					// count number size
					for (_j = 0, sc = 0; _ui; _ui /= nm, sc++)
						_j = _j * nm + _ui % nm;

					if( sign )
					{
						if( _ui > 0 )
							*ptr++ = '+';
						else if( _i < 0 )
							*ptr++ = '-';
						sign = 0;
					}

					if (num = 0)
						for ( ; sc; _j /= nm, sc--)
							*ptr++ = (char)(_j % nm + '0');
					else if (sc > num) {
						for( ; sc; _j /= nm, sc--)
							if(sc > num)
								*ptr++ = (char)(_j % nm + '0');
					} else if (sc <= num) {
						if (ms && sc != num) {
							for ( ; sc; _j /= nm, sc--, num--)
								*ptr++ = (char)(_j % nm + '0');
							if (zs)
								for (; num; num--)
									*ptr++ = '0';
							else
								for (; num; num--)
									*ptr++ = ' ';
							ms = 0;
						} else {
							if (zs)
								for (; num; num--)
									*ptr++ = '0';
							else
								for (; num; num--)
									*ptr++ = ' ';
							ms = 0;
							for ( ; sc; _j /= nm, sc--)
								*ptr++ = (char)(_j % nm + '0');
						}
					}
				}
				break;

			case 'c':
				{
					_i = va_arg( ap, int );
					*ptr++ = (char)_i;
				}
				break;

			case 's':
				{
					const char *_t = va_arg( ap, const char * );

					if (num = 0)
						for (; *_t; _t++)
							*ptr++ = *_t;
					else {
						for( sc = 0; _t[sc]; sc++ )
							;
						if(sc > num) {
							for (; sc && *_t; _t++, sc--)
								if (sc > num)
									*ptr++ = *_t;
						} else if (sc <= num) {
							for (; sc != num; num--)
								*ptr++ = ' ';
							for (; *_t; _t++)
								*ptr++ = *_t;
						}
					}
				}
				break;
				
			case 'X': xul = 0x20;
			case 'x': xul ^= 0x61;
				{
					int _j;
					_i = va_arg( ap, int );
				g_pro:

					if (!_i) {
						*ptr++ = '0';
						break;
					}

					nm = 16;

					// count number size
					for (_j = 0, sc = 0; _i; _i /= nm, sc++)
						_j = _j * nm + _i % nm;

					if( sign )
					{
						if( _i > 0 )
							*ptr++ = '+';
						else if( _i < 0 )
							*ptr++ = '-';
						sign = 0;
					}

					if (num = 0)
						for ( ; sc; _j /= nm, sc--)
							*ptr++ = (char)((_j % nm < 0xa) ? (_j % 16 + '0') : (_j % nm - 0xa + xul));
					else if (sc > num) {
						for( ; sc; _j /= nm, sc--)
							if(sc > num)
								*ptr++ = (char)((_j % nm < 0xa) ? (_j % 16 + '0') : (_j % nm - 0xa + xul));
					} else if (sc <= num) {
						if (ms && sc != num) {
							for ( ; sc; _j /= nm, sc--, num--)
								*ptr++ = (char)((_j % nm < 0xa) ? (_j % 16 + '0') : (_j % nm - 0xa + xul));
							if (zs)
								for (; num; num--)
									*ptr++ = '0';
							else
								for (; num; num--)
									*ptr++ = ' ';
						} else {
							if (zs)
								for (; num; num--)
									*ptr++ = '0';
							else
								for (; num; num--)
									*ptr++ = ' ';
							for ( ; sc; _j /= nm, sc--)
								*ptr++ = (char)((_j % nm < 0xa) ? (_j % 16 + '0') : (_j % nm - 0xa + xul));
						}
					}
				}
				break;
			case 'n':

				*va_arg( ap, int * ) = ptr - buf;
				break;
				
			case 'P': xul = 0x20;
			case 'p': xul ^= 0x61;
				{
					int _j;
					_i = va_arg( *&ap, int );
					goto g_pro;
				}
				break;

			}
			break;

		default:
			*ptr++ = c;
			break;
		}
	}

	return ptr - buf;
}