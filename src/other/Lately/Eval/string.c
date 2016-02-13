/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   string.c - [Private]

Project:

   RollRat Eval

------
   AUTHOR: HyunJun Jeong  2015-01-05

***************************************************************************/

//#include <limits.h>
#include "rocket.h"

#ifdef _DEBUG

int _atoi(
	const char * src
	)
{
#ifndef USING_DEVICE_FLAG_STRINGH
	int int_str = 0;
	int mark = 1;

	while (_isspace(*src))
		src++;

	if (*src == '-')
		mark = -1, src++;
	else if(*src == '+')
		src++;

	while (*src && _isnumeric(*src))
		int_str = (int_str * 10) + (*src++ & 0xf);

	return mark * int_str;
#else
	 return (int) _strtol_t (src, (char **) NULL, 10);
#endif
}

double _atof(
	const char * src
	)
{
	double _integer = 0.0;
	double _minority = 0.0;
	double _set = 1;
	double mark = 1;

	while (_isspace(*src))
		src++;
	
	if (*src == '-')
		mark = -1, src++;
	else if(*src == '+')
		src++;
	
	while (*src && _isnumeric(*src))
		_integer = (_integer * 10) + (*src++ & 0xf);

	if (*src == '.')
		src++;

	while (*src && _isnumeric(*src))
		_minority = (_minority * 10) + (*src++ & 0xf),
		_set *= 0.1;
	
	return mark * (_integer + _minority * _set);
}

long _atol(
	const char * src
	)
{
#ifndef USING_DEVICE_FLAG_STRINGH
	long int_str = 0;
	long mark = 1;

	while (_isspace(*src))
		src++;

	if (*src == '-')
		mark = -1, src++;
	else if(*src == '+')
		src++;

	while (*src && _isnumeric(*src))
		int_str = (int_str * 10) + (*src++ & 0xf);

	return mark * int_str;
#else
	 return (long) _strtol_t (src, (char **) NULL, 10);
#endif
}

unsigned long _atoul(
	const char * src
	)
{
#ifndef USING_DEVICE_FLAG_STRINGH
	unsigned long int_str = 0;
	unsigned long mark = 1;

	while (_isspace(*src))
		src++;

	if (*src == '-')
		mark = -1, src++;
	else if(*src == '+')
		src++;

	while (*src && _isnumeric(*src))
		int_str = (int_str * 10) + (*src++ & 0xf);

	return mark * int_str;
#else
	 return _strtoul_t (src, (char **) NULL, 10);
#endif
}

int _isspace(
	int ch
	)
{
	int ret = 0;

	switch ( ch )
	{
	case ' ':
	case '\t':
	case '\n':
	case '\f':
	case '\r':
	case '\0':
		ret = 1;
	}

	return ret;
}

int _isnumeric(
	int ch
	)
{
	int ret = 0;

	if( '0' <= ch && ch <= '9' )
		ret = 1;

	return ret;
}

int _isdigit(
	int ch
	)
{
	return _isnumeric(ch);
}

int _isalpha(
	int ch
	)
{
	int ret = 0;

	if( 'a' <= ch && ch <= 'z' )
		ret = ch;
	else if( 'A' <= ch && ch <= 'Z' )
		ret = ch;

	return ret;
}

int _isupper(
	int ch
	)
{
	int ret = 0;

	if ( 'A' <= ch && ch <= 'Z' )
		ret = ch;

	return ret;
}

int _islower(
	int ch
	)
{
	int ret = 0;

	if ( 'a' <= ch && ch <= 'z' )
		ret = ch;

	return ret;
}

int _isalnum(
	int ch
	)
{
	int ret = 0;

	if (_isalpha(ch) || _isdigit(ch))
		ret = ch;

	return ret;
}
#endif

int _isnspace(
	int ch
	)
{
	return !_isspace(ch);
}

int _isnnumeric(
	int ch
	)
{
	return !_isdigit(ch);
}

int _isndigit(
	int ch
	)
{
	return !_isdigit(ch);
}

int _isnalpha(
	int ch
	)
{
	return !_isalpha(ch);
}

int _isnupper(
	int ch
	)
{
	return !_isupper(ch);
}

int _isnlower(
	int ch
	)
{
	return !_islower(ch);
}

int _isnalnum(
	int ch
	)
{
	return !_isalnum(ch);
}

int _isnalnumub(
	int ch
	)
{
	return !_isalnumub(ch);
}

int _isnreturn(
	int ch
	)
{
	return !_isreturn(ch);
}

int _isnxdigit(
	int ch
	)
{
	return !_isxdigit(ch);
}

int _isalnumub(
	int ch
	)
{
	int ret = 0;

	if (_isalnum(ch) || ch == '_')
		ret = ch;

	return ret;
}

int _isreturn(
	int ch
	)
{
	int ret = 0;

	switch ( ch )
	{
	case '\n':
	case '\r':
	case '\0':
		ret = 1;
	}

	return ret;
}

#ifdef _DEBUG
int _isxdigit(
	int ch
	)
{
	int ret = 0;

	if (_isdigit(ch) || 
		('a' <= ch && ch <= 'f') || 
		('A' <= ch && ch <= 'Z'))
		ret = ch;

	return ret;
}

char * _strcat_asc(
	char * dest,
	const char * src
	)
{
	char * dest_ptr = dest;

	while( *dest_ptr )
		dest_ptr++;

	while( *dest_ptr++ = *src++ )
		;

	return dest;
}

_wchar_t * _strcat_w(
	_wchar_t * dest,
	const _wchar_t * src
	)
{
	_wchar_t * dest_ptr = dest;
	
	while( *dest_ptr )
		dest_ptr++;

	while( *dest_ptr++ = *src++ )
		;

	return dest;
}

char * _strchr_asc(
	const char * str,
	int ch
	)
{
	while( *str && (*str != ch) )
		str++;

	if (*str == ch)
		return (char *)str;

	return _NULL;
}

int _strcmp_asc(
	const char * s1,
	const char * s2
	)
{
	int ret = 0;

	// ¼öÁ¤: 2015-01-29
	if (s1 == s2)
		return 0;

	while( *s2 && !(ret = *s1 - *s2) )
		s1++, s2++;

	if (ret < 0)
		return -1;
	else if (ret > 0)
		return 1;
	
	return 0;
}

char * _strcpy_asc(
	char * dest,
	const char * src
	)
{
	char * dest_ptr = dest;

	while( *dest_ptr++ = *src++ )
		;

	return dest;
}

_wchar_t * _strcpy_w(
	_wchar_t * dest,
	const _wchar_t * src
	)
{
	_wchar_t * dest_ptr = dest;

	while( *dest_ptr++ = *src++ )
		;

	return dest;
}

_size_t _strcspn_asc(
	const char * str1,
	const char * str2
	)
{
	const char * s1 = str1, *s2;

	while( *s1 ){
		for( s2 = str2; *s2; s2++ )
			if( *s1 == *s2 )
				return s1 - str1;
		s1++;
	}

	return s1 - str1;
}

_size_t _strlen_asc(
	const char * str
	)
{
#ifndef USING_DEVICE_FLAG_STRINGH
	const char * ptr = str;

	while( *ptr++ )
		;

	return ptr - str - 1;
#else
	_size_t size = 0;

	while( str[i] )
		i++;

	return i;
#endif
}

char * _strlwr_asc(
	char * str
	)
{
	char * ptr = str;

	while( *ptr )
		*ptr++ = _to_lower(str);

	return ptr;
}

char * _strncat_asc(
	char * dest,
	const char * src,
	_size_t n
	)
{
	char * dest_ptr = dest;

	while( *dest_ptr )
		dest_ptr++;

	while( (*dest_ptr++ = *src++) && n-- )
		;

	if( *src )
		*dest_ptr = '\0';

	return dest;
}

_wchar_t * _strncat_w(
	_wchar_t * dest,
	const _wchar_t * src,
	_size_t n
	)
{
	_wchar_t * dest_ptr = dest;
	
	while( *dest_ptr )
		dest_ptr++;

	while( (*dest_ptr++ = *src++) && n-- )
		;
	
	if( *src )
		*dest_ptr = '\0';

	return dest;
}

int _strncmp_asc(
	const char * s1,
	const char * s2,
	_size_t n
	)
{
	int ret = 0;

	while( n-- && *s1 ) {
		if( *s1 != *s2)
			if ( *s1 > *s2 )
				return 1;
			else
				return -1;
		s1++, s2++;
	}
	
	return 0;
}

char * _strncpy_asc(
	char * dest,
	const char * src,
	_size_t n
	)
{
	char * dest_ptr = dest;
	const char * target_ptr = src;

	while( *target_ptr && n--)
		*dest_ptr++ = *target_ptr++;

	*dest_ptr = _NULL;
	
	return dest;
}

_wchar_t * _strncpy_w(
	_wchar_t * dest,
	const _wchar_t * src,
	_size_t n
	)
{
	_wchar_t * dest_ptr = dest;
	const _wchar_t * target_ptr = src;

	while( *target_ptr && n--)
		*dest_ptr++ = *target_ptr++;
	
	*dest_ptr = _NULL;

	return dest;
}

_size_t _strnlen_asc(
	const char * str,
	_size_t n
	)
{
	const char * ptr = str;

	while( *ptr++ && n-- )
		;

	return ptr - str + 1;
}

char * _strnset_asc(
	char * str,
	int ch,
	_size_t n
	)
{
	char * ptr = str;

	while ( *str && (*str++ = (char) ch) && n--)
		;
	
	return ptr;
}

char * _strpbrk_asc(
	const char * str,
	const char * src
	)
{
	const char * ptr = str;
	const char * p = src;

	while( *ptr )
	{
		p = src;
		while( *p )
		{
			if( *ptr == *p )
				return str;
			p++;
		}
		ptr++;
	}

	return str;
}

char * _strrchr_asc(
	const char * str,
	int ch
	)
{
	const char * str_ptr = str;

	while( *str++ )
		;

	while( --str != str_ptr && (*str != ch) )
		;

	if (*str == ch)
		return (char *)str;

	return _NULL;
}

char * _strrev_asc(
	char * str
	)
{
	char * start = str;
	char * ptr = str;
	char ch;

	while( *str++ )
		;
	str -= 2;

	while( ptr < str )
	{
		ch = *ptr;
		*ptr++ = *str;
		*str-- = ch;
	}

	return start;
}

char * _strset_asc(
	char * str,
	int ch
	)
{
	char * ptr = str;

	while ( *str && (*str++ = (char) ch) )
		;
	
	return ptr;
}

_size_t _strspn_asc(
	const char * str1,
	const char * str2
	)
{
	const char * s1 = str1, *s2;

	while( *s1 ) {
		for( s2 = str2; *s2; s2++ )
			if( *s1 == *s2 )
				goto X;
		break;
	X:
		s1++;
	}

	return s1 - str1;
}

char * _strstr_asc(
	const char * s1,
	const char * s2
	)
{
	char * ptr = (char *)s1;
	char *p1, *p2;

	while( *ptr )
	{
		p1 = ptr, p2 = s2;

		while(*p1 && *p2)
		{
			if (*p1 != *p2)
				break;
			p1++, p2++;
		}
		if( *p2 == 0 )
			return ptr;

		ptr++;
	}

	return _NULL;
}

char * _strtok_asc(
	char * str,
	const char * src
	)
{
	static char * ptr;
	const char * p;

	if( str == _NULL )
		str = ptr;
	else
		ptr = str;

	while( *ptr )
	{
		p = src;
		while( *p )
		{
			if( *ptr == *p )
			{
				*ptr = '\0';
				ptr++;
				return str;
			}
			p++;
		}
		ptr++;
	}

	return str;
}

static unsigned long _strtoxl_asc(
	const char *nptr,
	char **endptr,
	register int base,
	int flags
	)
{
	register const char *n_ptr = nptr;
	register char c;
	register unsigned long number = 0;
	register unsigned digval;
	register unsigned long maxval;
	
	c = *n_ptr++;

	while (_isspace(*n_ptr))
		c = *n_ptr++;
	
	if (c == '-') {
		flags |= FL_NEG;
		c = *n_ptr++;
	}
	else if(c == '+')
		c = *n_ptr++;

	if(base < 0 || base > 36 || base == 1) {
		if (endptr) 
			*endptr = nptr;
		return 0L;
	} else if(base == 0) {
		if (c != '0')
			base = 10;
		else if (*n_ptr == 'x' || *n_ptr == 'X')
			base = 16;
		else
			base = 8;
	} else if (base == 16) {
		if (c == '0' && (*n_ptr == 'x' || *n_ptr == 'X')) {
			++n_ptr;
			c = *n_ptr++;
		}
	}
	
	maxval = _ULONG_MAX / base;

	for (;;) {
		if (_isdigit((int)(unsigned char)c))
			digval = c - '0';
		else if (_isalpha((int)(unsigned char)c))
			digval = _to_upper(c) & 0xf + 10;
		else
			break;
		if (digval >= (unsigned)base) break;
		flags |= FL_READDIGIT;
		if (number < maxval || (number == maxval 
			&& (unsigned long)digval <= _ULONG_MAX %base)) {

			number = number * base + digval;
		} else {
			flags |= FL_OVERFLOW;
			if (endptr == _NULL)
				break;
		}
		c = *n_ptr++;
	}

	--n_ptr;

	if (!(flags & FL_READDIGIT))
	{
		if (endptr) 
			n_ptr = nptr;
		number = 0L;
	}
	else if ((flags & FL_OVERFLOW) || 
		(!(flags & FL_UNSIGNED) && 
		(((flags & FL_NEG) && (number > -_LONG_MIN)) || 
		(!(flags & FL_NEG) && (number > _LONG_MAX)))))
	{
		if (flags & FL_UNSIGNED)
			number = _ULONG_MAX;
		else if (flags & FL_NEG)
			number = (unsigned long)(-_LONG_MIN);
		else
			number = _LONG_MAX;
	}

	if (endptr != _NULL) 
		*endptr = n_ptr;

	if (flags & FL_NEG) 
		number = (unsigned long)(-(long)number);

	return number;
}

long _strtol_asc(
	const char *nptr, 
	char **endptr,
	int base
	)
{
	return (long)_strtoxl_asc(nptr, endptr, base, 0);
}

unsigned long _strtoul_asc(
	const char *nptr, 
	char **endptr,
	int base
	)
{
	return _strtoxl_asc(nptr, endptr, base, 0);
}


unsigned long _strtoul_t(
	const char *nptr, 
	char **endptr, 
	register int base
	)
{
	register const char *s = nptr;
	register unsigned long acc;
	register int c;
	register unsigned long cutoff;
	register int neg = 0, any, cutlim;

	do {
		c = *s++;
	} while (_isspace(c));
	if (c == '-') {
		neg = 1;
		c = *s++;
	} else if (c == '+')
		c = *s++;
	if ((base == 0 || base == 16) &&
	    c == '0' && (*s == 'x' || *s == 'X')) {
		c = s[1];
		s += 2;
		base = 16;
	}
	if (base == 0)
		base = c == '0' ? 8 : 10;

	cutoff = neg ? (~((unsigned long)_LONG_MIN)+1) : _LONG_MAX;
	cutlim = cutoff % (unsigned long)base;
	cutoff /= (unsigned long)base;
	for (acc = 0, any = 0;; c = *s++) {
		if (_isdigit(c))
			c -= '0';
		else if (_isalpha(c))
			c -= _to_upper(c) & 0xf + 10;
		else
			break;
		if (c >= base)
			break;
		if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
			any = -1;
		else {
			any = 1;
			acc *= base;
			acc += c;
		}
	}
	if (any < 0) {
		acc = neg ? _LONG_MIN : _LONG_MAX;
	} else if (neg)
		acc = ~acc+1;
	if (endptr != 0)
		*endptr = (char *) (any ? s - 1 : nptr);
	return (acc);
}

long _strtol_t(
	const char *nptr, 
	char **endptr,
	int base
	)
{
	return (long) _strtoul_t(nptr, endptr, base, 0);
}

char * _strupr_asc(
	char * str
	)
{
	char * ptr = str;

	while( *ptr )
		*ptr++ = _to_upper(str);

	return ptr;
}

int _to_upper(
	int ch
	)
{
	int ret = ch;

	if ('a' <= ret && ret <= 'z')
		ret -= 'a' - 'A';
	
	return ret;
}

int _to_lower(
	int ch
	)
{
	int ret = ch;

	/*if (!_isalpha(ret))
		return ch;

	ret |= 0x20;*/
	
	if ('A' <= ret && ret <= 'Z')
		ret += 'a' - 'A';

	return ret;
}
#endif

int _to_xdigit(
	int ch
	)
{
	int ret;

	if (_isdigit(ch))
		ret = ch - '0';
	else if (_isxdigit(ch))
		ret = _to_lower(ch) - 'a' + 0xa;

	return ret;
}

char *__itoa(
	int i
	)
{
	static char buf[21];
	char *p = buf + 19 + 1;
	if (i >= 0) {
		while (i != 0) { 
			*--p = '0' + (i % 10); 
			i /= 10; 
		}
		return p;
	} else {
		while (i != 0) { 
			*--p = '0' - (i % 10); 
			i /= 10; 
		}
		*--p = '-';
	}
	return p;
}