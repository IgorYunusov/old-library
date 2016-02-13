/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   sscanfx.c - [Private]

Project:

   Robust Assembler (RASM)
   
Abstract:

   Non-standard extension sscanf and regex parsing module.

------
   AUTHOR: HyunJun Jeong  2015-01-12

***************************************************************************/

#include "rocket.h"
#include "type.h"
#include <stdarg.h>
#include <stdio.h>

static int vsscanft(const char *src, const char *format, va_list vl);
static void _internal_sscanft_get_int(char const const * *src, int *target);
static void _internal_sscanft_get_lint(char const const * *src, long int *target);
static void _internal_sscanft_get_llint(char const const * *src, long long int *target);
static void _internal_sscanft_get_uint(char const const * *src, unsigned int *target);
static void _internal_sscanft_get_ulint(char const const * *src, unsigned long int *target);
static void _internal_sscanft_get_ullint(char const const * *src, unsigned long long int *target);
static void _internal_sscanft_get_short(char const const * *src, short int *target);
static void _internal_sscanft_get_usint(char const const * *src, unsigned short int *target);
static void _internal_sscanft_get_double(char const const * *src, double *target);
static void _internal_sscanft_get_ldouble(char const const * *src, long double *target);
static void _internal_sscanft_get_char(char const const * *src, char *target);
static void _internal_sscanft_get_uchar(char const const * *src, unsigned char *target);

int sscanft( const char *src, const char *format, ... )
{
	va_list vl;
	int retval;
	va_start(vl, format);
	retval = vsscanft(src, format, vl);
	va_end(vl);
	return retval;
}

static int vsscanft( const char *src, const char *format, va_list vl )
{
	// no option sscanft format
	int count;
// 리턴 변수 재정의
	int _int;
	long int _lint;
	char _char;
	unsigned char _uchar;
	long long int _llint;
	unsigned int _uint;
	unsigned long int _ulint;
	unsigned long long int _ullint;
	short int _sint;
	unsigned short int _usint;
	double _double;
	long double _ldouble;
//
	void *ptr;

	count = 0;
	
	while( *src && *format ) {
		switch ( *format++ ) {
		case '%':
			switch ( *format++ ) {
			case 'd': _internal_sscanft_get_int(&src, &_int); break;
			case 'u': _internal_sscanft_get_uint(&src, &_uint); break;
			case 'b':
			case 'l':
				switch( *format ) {
				case 'l':
					switch( *(format + 1) ) {
					case 'd':
						_internal_sscanft_get_llint(&src, &_lint);
						format += 2;
						break;
					}
					break;
				case 'd':
					_internal_sscanft_get_lint(&src, &_lint);
					format++;
					break;
				case 'f':
					_internal_sscanft_get_ldouble(&src, &_ldouble);
					format++;
					break;
				default:
					_internal_sscanft_get_lint(&src, &_lint);
					break;
				}
				break;
			case 'o':
			case 'D':
			case 'B':
			case 'O':
			case 'c':
			case 's':
			case 'X':
			case 'x':
			case 'p':
			case 'P':
			case 'f': _internal_sscanft_get_double(&src, &_double); break;
			case 'L':
			case 'F':
			case 'n':
			case '#':
			case '0':
			case '[':
			case '+':
			case '-':
			case '\\':
			default:
				break;
			}
			break;
		case '#':
			break;
		case '^':
			// regex unit
			break;
		case '//':
			break;
		default:
			if (*src == *(format - 1))
				src++;
			else
				return 0; // error format or source
			break;
		}
	}

	return count;
}

static void  _internal_sscanft_get_int(char const const * *src, int *target)
{
	const char *s = *src;
	int ret = 0, minus = 1;

	if( *s == '-' ) {
		minus = -1;
		s++;
	} else if ( *s == '+' ) {
		s++;
	}

	while( _isdigit(*s) ) {
		ret = ret * 10 + *s - '0';
		s++;
	}

	*src = s;
	*target = ret * minus;
}

static void  _internal_sscanft_get_lint(char const const * *src, long int *target)
{
	const char *s = *src;
	long int ret = 0, minus = 1;

	if( *s == '-' ) {
		minus = -1;
		s++;
	} else if ( *s == '+' ) {
		s++;
	}

	while( _isdigit(*s) ) {
		ret = ret * 10 + *s - '0';
		s++;
	}

	*src = s;
	*target = ret * minus;
}

static void  _internal_sscanft_get_llint(char const const * *src, long long int *target)
{
	const char *s = *src;
	long long int ret = 0, minus = 1;

	if( *s == '-' ) {
		minus = -1;
		s++;
	} else if ( *s == '+' ) {
		s++;
	}

	while( _isdigit(*s) ) {
		ret = ret * 10 + *s - '0';
		s++;
	}

	*src = s;
	*target = ret * minus;
}

static void  _internal_sscanft_get_uint(char const const * *src, unsigned int *target)
{
	const char *s = *src;
	unsigned int ret = 0;

	while( _isdigit(*s) ) {
		ret = ret * 10 + *s - '0';
		s++;
	}

	*src = s;
	*target = ret;
}

static void  _internal_sscanft_get_ulint(char const const * *src, unsigned long int *target)
{
	const char *s = *src;
	unsigned long int ret = 0;

	while( _isdigit(*s) ) {
		ret = ret * 10 + *s - '0';
		s++;
	}

	*src = s;
	*target = ret;
}

static void  _internal_sscanft_get_ullint(char const const * *src, unsigned long long int *target)
{
	const char *s = *src;
	unsigned long long int ret = 0;

	while( _isdigit(*s) ) {
		ret = ret * 10 + *s - '0';
		s++;
	}

	*src = s;
	*target = ret;
}

static void _internal_sscanft_get_short(char const const * *src, short int *target)
{
	const char *s = *src;
	short int ret = 0, minus = 1;

	if( *s == '-' ) {
		minus = -1;
		s++;
	} else if ( *s == '+' ) {
		s++;
	}

	while( _isdigit(*s) ) {
		ret = ret * 10 + *s - '0';
		s++;
	}

	*src = s;
	*target = ret * minus;
}

static void  _internal_sscanft_get_usint(char const const * *src, unsigned short int *target)
{
	const char *s = *src;
	unsigned short int ret = 0;

	while( _isdigit(*s) ) {
		ret = ret * 10 + *s - '0';
		s++;
	}

	*src = s;
	*target = ret;
}

static void _internal_sscanft_get_double(char const const * *src, double *target)
{
	const char *s = *src;
	double ret = 1.0f, minus = 1;
	unsigned int left = 0;
	unsigned long long right = 0;
	
	if( *s == '-' ) {
		minus = -1;
		s++;
	} else if ( *s == '+' ) {
		s++;
	}

	while( _isdigit(*s) ) {
		left = left * 10 + *s - '0';
		s++;
	}

	if( *s == '.' )
	{
		s++;
		while( _isdigit(*s) ) {
			ret /= 10;
			right = right * 10 + *s - '0';
			s++;
		}
	}

	ret = (double)left + right * ret;
	*src = s;
	*target = ret * minus;
}

static void _internal_sscanft_get_ldouble(char const const * *src, long double *target)
{
	const char *s = *src;
	long double ret = 1.0f, minus = 1;
	unsigned int left = 0;
	unsigned long long right = 0;
	
	if( *s == '-' ) {
		minus = -1;
		s++;
	} else if ( *s == '+' ) {
		s++;
	}

	while( _isdigit(*s) ) {
		left = left * 10 + *s - '0';
		s++;
	}

	if( *s == '.' )
	{
		s++;
		while( _isdigit(*s) ) {
			ret /= 10;
			right = right * 10 + *s - '0';
			s++;
		}
	}

	ret = (double)left + right * ret;
	*src = s;
	*target = ret * minus;
}

static void _internal_sscanft_get_char(char const const * *src, char *target)
{
	const char *s = *src;
	if( _isalnumub(*s) )
		*target = *s;
}

static void _internal_sscanft_get_uchar(char const const * *src, unsigned char *target)
{
	const unsigned char *s = *src;
	if( _isalnumub(*s) )
		*target = *s;
}

	//unsigned char _uchar;
	//long long int _llint;
	//unsigned int _uint;
	//unsigned long int _ulint;
	//unsigned long long int _ullint;
	//short int _sint;
	//unsigned short int _usint;
	//double _double;
	//long double _ldouble;


//////////////// sscanfx regex unit

	/*

			PERFECT REGEX UNIT
	
	*/
#define REGEX_ALNUM						":alnum:"	// Alphanumeric characters
#define REGEX_WORD						":word:"	// Alphanumeric characters plus "_"
#define REGEX_ALPHA						":alpha:"	// Alphabetic characters
#define REGEX_BLANK						":blank:"	// Space and tab
#define REGEX_CNTRL						":cntrl:"	// Control characters
#define REGEX_DIGIT						":digit:"	// Digits
#define REGEX_GRAPH						":graph:"	// Visible characters
#define REGEX_LOWER						":lower:"	// Lowercase letters
#define REGEX_PRINT						":print:"	// Visible characters and the space character
#define REGEX_PUNCT						":punct:"	// Punctuation characters
#define REGEX_SPACE						":space:"	// Whitespace characters
#define REGEX_UPPER						":upper:"	// Uppercase letters
#define REGEX_XDIGIT					":xdigit:"	// Hexadecimal digits
#define REGEX_ODIGIT					":odigit:"	// Octal digits

			// POSIX OLD SCAN LIST
#define REGEX_SCAN_ALNUM				"A-Za-z0-9"
#define REGEX_SCAN_WORD					"A-Za-z0-9_"
#define REGEX_SCAN_ALPHA				"A-Za-z"
#define REGEX_SCAN_BLANK				" \\t"
#define REGEX_SCAN_CNTRL				"\\x00-\\x1F\\x7F"
#define REGEX_SCAN_DIGIT				"0-9"
#define REGEX_SCAN_GRAPH				"\\x21-\\x7E"
#define REGEX_SCAN_LOWER				"a-z"
#define REGEX_SCAN_PRINT				"\\x20-\\x7E"
#define REGEX_SCAN_PUNCT				"\\]\\[\\!\\\"\\#\\$\\%\\&\\'\\(\\)\\*\\+\\,\\.\\/\\:\\;\\<\\=\\>\\?\\@\\\\\^\\_\\`\\{\\|\\}\\~\\-"
#define REGEX_SCAN_SPACE				" \\t\\r\\n\\v\\f"
#define REGEX_SCAN_UPPER				"A-Z"
#define REGEX_SCAN_XDIGIT				"A-Fa-f0-9"
#define REGEX_SCAN_ODIGIT				"0-7"

char **sscanfr( const char *src, const char *format )
{
	char **retval=0;

	return retval;
}