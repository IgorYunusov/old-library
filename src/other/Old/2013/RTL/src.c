#include "error.h"

typedef int BOOL;
typedef void VOID;

#define TRUE	((BOOL)(1))
#define FALSE	((BOOL)(0))

typedef char rtl;

#define rtl_string	rtl *
#define rtl_pointer	rtl_string *
#define crtl		const rtl_string

#define _rtl_(rts)		((rtl)(*((rtl_string)*(rts))))

#define space		" \t\r\n\v\f"
#define symbol		"!@#$%^&*-+|\\>.<=\":;/?,"
#define lower		'a', 'z'
#define upper		'A', 'Z'
#define digit		'0', '9'

struct _variable_table
{
	int		Type;
	char *	Data;		// last '\0'
	char *	Variable_Name;
	BOOL	nullswitch;
}	*	STATIC_VARIABLE_TABLE;
int VARIABLE_TABLE_TIMES = 0;

void _PUSH_STATIC_VARIABLE()
{

}

#define VARIABLE_TYPE_STD		1
#define VARIABLE_TYPE_NONSTD	2

#pragma region _TOOL
BOOL __in_string(
	rtl wht, crtl target)
{
	for(; *target; target++)
	{
		if (wht == *target)
			return TRUE;
	}
	return FALSE;
}

BOOL __in_scope(
	rtl wht, rtl _Left, rtl _Right)
{
	if (_Left <= wht && wht <= _Right)
	{
		return TRUE;
	}
	return FALSE;
}

VOID _Skip_String_(rtl_pointer _Left, crtl _Right)
{
	for (; __in_string(_rtl_(_Left), _Right) != FALSE; ++(*_Left))
		;
}

VOID _Skip_Scope_(rtl_pointer _Rtl, rtl _Left, rtl _Right)
{
	for (; (_Left <= _rtl_(_Rtl)) && (_rtl_(_Rtl) <= _Right); ++(*_Rtl))
		;
}
#pragma endregion

#define condition_or			"|"
#define condition_and			"&"
#define condition_xor			"^"
#define condition_not			"~"
#define condition_logic_or		"||"
#define condition_logic_and		"&&"
#define condition_logic_not		"!"
#define condition_equal			"=="
#define condition_not_equal		"!="

BOOL _check_condition_kim(rtl_pointer _Ptr);

/*	양쪽 괄호를 모두 포함하시오.	*/
BOOL _check_condition(rtl_pointer _First, rtl_string _Last)
{
	BOOL stay_safe = TRUE;
	(*_First)++;		// '(' Skip
	_Skip_String_(&*_First, space);
	switch(_rtl_(_First))
	{
	case '(':
		if (_check_condition(&*_First, _Last) == FALSE)
			return FALSE;
		break;
	case ')':
		(*_First)++;		// ')' Skip
		return stay_safe;
	default:
		_check_condition_kim(&*_First);
	}
	if (*_First == _Last)
		return TRUE;
}

BOOL _check_condition_kim(rtl_pointer _Ptr)
{
	if (__in_scope(_rtl_(_Ptr), lower) == TRUE ||
			__in_scope(_rtl_(_Ptr), upper) == TRUE ||
			_rtl_(_Ptr) == '_')
	{

	}
}

#include <stdio.h>

maian()
{
	char aasdf[] = "(  ((as)df))";
	char *ptr = aasdf;

	//_Skip_String_(&ptr, space);
	_check_condition(&ptr, 0);

	printf("%s", ptr);
}