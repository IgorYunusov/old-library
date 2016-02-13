/*
			RCL - ROLLRAT TRANSPLATABLE LIBRARY
				 R COMPILER LANGUAGE PROJECT
					NATIVE C Librorum

			 Cpy (c) 13-14. ALL RIGHTS RESERVED.
   */

#ifndef _rtl
#define _rtl

		// CC1 TANS LOCALAZATION

#define _Check_ptr_alterable_

#define _Style_recusive_
#define _Style_for_

#define UNICODE			unsigned char
#define UNICODE_STRING	UNICODE *

typedef int			BOOL;
#define TRUE			1
#define FALSE			0

BOOL InStr(const UNICODE wht, const UNICODE_STRING target);
BOOL InScope(const UNICODE wht, UNICODE _First, UNICODE _Last);

#define SKIP_SPACE			" \t\r\n\v\f"

void _sCharacter(UNICODE_STRING *ptr, const UNICODE target);
void _sString(UNICODE_STRING *ptr, const UNICODE_STRING target);
void _sScope(UNICODE_STRING *ptr, UNICODE _First, UNICODE _Last);

BOOL if_full(
	_Check_ptr_alterable_ UNICODE_STRING * _First,
	UNICODE_STRING _Last
	);

#endif