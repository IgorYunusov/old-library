/*****************************************************************************
 *****************************************************************************
 *********                                                           *********
 *********                     TETO SCRIPT MOD                       *********
 *********                         ROLLRAT                           *********
 *********                           1.0                             *********
 *********                                                           *********
 *********               COPYRIGHT. (C)ROLLRAT. 2014                 *********
 *********                                                           *********
 *****************************************************************************
 *****************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

const char * TextPartialMatchLastA(const char * _T, const char * _S);
const char * TextPartialMatchFirstA(const char * _T, const char * _S);
const char * SkipWS(const char * _T);	// 스킵용
const char * SkipIWS(const char * _T);	// 만나기까지...
void PutText(const char * _Ptr, char * _P, int len);
const char * skip_str(const char * _Ptr, const char * _Wh, int len);

#define MatchLast	TextPartialMatchLastA
#define MatchFirst	TextPartialMatchFirstA
#define SkipWH		SkipWS
#define SkipIWH		SkipIWS

typedef struct _a_function *ptr;
typedef struct _a_funciton {
	int pos;
	char *Name;
	struct inja {
		char *name;
		char *type;
		int type_o;
		struct inja *next;
	} *INJAS;
	struct _a_function *next;
}	FUNCTION_LIST;

void _teto_excute_function_others(const char * _Ptr, FUNCTION_LIST *_F_Head);

#define InitFList(a)		{ (a)->Name = 0;\
						(a)->INJAS = 0;\
						(a)->next = 0; }

#define InitIList(a)		{ (a)->name = 0;\
						(a)->type = 0;\
						(a)->type_o = 0;\
						(a)->next = 0; }

#define TETO_MATCH_FUNCTION		"function"

#define TETO_FUNCTION_MAX		64
#define TETO_FUNCTION_DETAIL	"<="

char * _teto_excute_modx86(const char * code)
{
	char *_Ptr = (char *)code, *_Tmp;
	int count_function = 0;
	FUNCTION_LIST *_F_Head = 0;
	int string_len_tmp = 0;
	
	_F_Head = (FUNCTION_LIST *)malloc(sizeof(FUNCTION_LIST));

	// function MATCH
	// function\s+<functionname>\s*
	if (_Ptr = MatchLast(code, TETO_MATCH_FUNCTION))
	{
		InitFList(_F_Head);
		if (!(_Ptr = SkipWH(_Ptr)))
			;		// throw
		_Tmp = SkipIWH(_Ptr);
		string_len_tmp = _Tmp - _Ptr;
		_Ptr = _Tmp;
		//////////////////////////////////
		_Tmp = (char *)malloc(string_len_tmp + 1);
		PutText(_Ptr, _Tmp, string_len_tmp);
		_F_Head->Name = _Tmp;
		//////////////////////////////////
		_teto_excute_function_others(_Ptr, _F_Head);
	}
}

void _teto_excute_function_others(const char * _Ptr, FUNCTION_LIST *_F_Head)
{
	char *_type, *_name;
	int string_len_tmp;
	if (!(_Ptr = SkipWH(_Ptr)))
			return;		// 추가정보 없음.
	if (!skip_str(_Ptr, TETO_FUNCTION_DETAIL, 2))
			return;		// 다른용도의 공백이다.
	_Ptr += 2;
	if (!(_Ptr = SkipWH(_Ptr)))
			return;		// 추가정보 없음.
	/////////////////////////////////////////////////////
	if (skip_str(_Ptr, "get", 3))
		{
			_Ptr += 3;
			_F_Head->INJAS = (struct inja *)malloc(sizeof(struct inja));
			for (; *_Ptr == ' '; _Ptr++)
				;
			if (*_Ptr++ != '[')
				; //error
			_type = SkipIWH(_Ptr);
			string_len_tmp = _type - _Ptr;
			_Ptr = _type;
			//////////////////////////////////
			_Ptr = (char *)malloc(string_len_tmp + 1);
			PutText(_type, _Ptr, string_len_tmp);
			_F_Head->INJAS->name = _Ptr;
			//////////////////////////////////

		}
	else if (skip_str(_Ptr, "set", 3))
		;
	else if (skip_str(_Ptr, "override", 8))
		;
	else if (skip_str(_Ptr, "overload", 8))
		;
	else if (skip_str(_Ptr, "style", 5))
		;
	else if (skip_str(_Ptr, "import", 6))
		;
	else if (skip_str(_Ptr, "extend", 6))
		;
	else
		;	// 에러
}

const char * TextPartialMatchFirstA(const char * _T, const char * _S)
{
#if defined(_DEBUG)
	const char * _Ptr = _T, * _Sub1, * _Sub2;
	for( ; *_Ptr; _Ptr++)
		{
		_Sub1 = _Ptr;
		_Sub2 = _S;
		while (*_Sub1 && *_Sub2 && !(*_Sub1 - *_Sub2))
			_Sub1++, _Sub2++;
		if (!*_Sub2)
			return _Ptr;
		}
	return 0;
#else
	return strstr(_T, _S);
#endif
}
const char * TextPartialMatchLastA(const char * _T, const char * _S)
{
	const char * _Ptr = _T, * _Sub1, * _Sub2, *_T1;
	for( ; *_Ptr; _Ptr++)
		{
		_Sub1 = _Ptr;
		_Sub2 = _S;
		_T1 = _Ptr;
		while (*_Sub1 && *_Sub2 && !(*_Sub1 - *_Sub2))
			_Sub1++, _Sub2++, _Ptr++;
		if (!*_Sub2)
			return _Ptr;
		_Ptr = _T1;
		}
	return 0;
}
const char * SkipWS(const char * _T)
{
	const char * _T1 = _T;
	for (; isspace(*_T1) && *_T1 != '\n'; _T1++)
		;
	if (_T1 != _T)
		return _T1;
	return 0;
}
const char * SkipIWS(const char * _T)
{
	const char * _T1 = _T;
	for (; !isspace(*_T1) && *_T1 != '\n'; _T1++)
		;
	if (_T1 != _T)
		return _T1;
	return 0;
}
void PutText(const char * _Ptr, char * _P, int len)
{
	int i;
	for (i = 0; i < len; i++, _Ptr++)
		_P[i] = *_Ptr;
	_P[i] = '\0';
}
const char * skip_str(const char * _Ptr, const char * _Wh, int len)
{
	int i;
	const char * _Tmp = _Ptr;
	for (i = 0; i < len; i++, _Tmp++, _Wh++)
		if (*_Tmp != *_Wh)
			return 0;
	return _Tmp;
}

int done()
{
	return 0;
}

struct link {
	struct link *ref;
	int dat;
};
void shift(struct link *y) {
	y->ref = y;
	if (!done())
		/* call with extended parameter + an offset */
		shift((struct link *)(&y->dat));
}

int main()
{
	char t[] = "function intkro <= get [string : t]";
	char *x;
	struct link tx, ty;
	ptr xt;
	struct _a_funciton tt;

	ty.dat = 123;
	tx.dat = &ty;
	xt = &tt;

	shift(&tx);
	x = (char *)malloc(5);
	PutText("asdf", x, 4);
	printf("%s", x);
	_teto_excute_modx86(t);
}