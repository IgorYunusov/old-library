#include "rtl.h"

void _sCharacter(ptr, target)
	UNICODE_STRING *ptr;
	const UNICODE target;
{
	for (; **ptr != target;(*ptr)++)
		;
}

void _sString(ptr, target)
	UNICODE_STRING *ptr;
	const UNICODE_STRING target;
{
	for (; InStr(**ptr, target) != FALSE;(*ptr)++)
		;
}

void _sScope(ptr, _First, _Last)
	UNICODE_STRING *ptr; 
	UNICODE _First; 
	UNICODE _Last;
{
	for (; InScope(**ptr, _First, _Last) != FALSE;(*ptr)++)
		;
}