/*************************************************************************
 *
 * FILE NAME : strtol.h - x to string
 *
 * RollRat ISO Standard C Library
 *
 *
 * CREATION : 2014.12.06
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#include "string.h"

#define FL_UNSIGNED		1
#define FL_NEG			2
#define FL_OVERFLOW		4
#define FL_READDIGIT	8

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