/*************************************************************************
 *
 * FILE NAME : costume.c - Custom to string by format
 *
 * RollRat Invention Compiler 
 *
 *
 * CREATION : 2014.12.25
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

/****

			COSTUME. Custom to string by format. Ver 0.1

	process_costume이 처리함수이며 왼쪽 인자부터 분석될 문자열, 결과가 출력될 문자열, 형식을 넣어주면 됩니다.

	형식 문법
	1. 시작과 끝을 ;을 이용하여 나타냅니다.
	2. @, $는 각각 정수형 변수 선언, 문자열 변수 선언을 나타냅니다. 이 변수는 변경불가능 합니다.
	3. %~%는 함수 호출로, 현재 분석될 문자열의 길이를 가져오는 length만 존재합니다.
	4. ?는 조건문입니다. ?(~)에서 ~에 조건을 맞추면, 해당 조건이 TRUE일경우 :, 또는 /전까지, FALSE일경우 /까지 문을 진행 시킵니다.
	5. :는 조건문의 그 밖에 있는 조건을 뜻합니다. /를 만날때 까지 진행 시킵니다.
	6. 조건 문안에 조건문을 넣을 수 없습니다.
	7. /는 구분자로 모든 형식 문법을 구분 가능합니다.
	8. 문자열 초기화시 "~", 또는 [~]를 이용해야합니다. "~"는 일반 문자열을 대입하고, [~]는 임시 문자열을 대입합니다.
	9. 임시 문자열 문법은 다음과 같습니다.
		ㄱ. 임시 문자열 문법 시작시 결과가 출력될 문자열의 포인터를 초기화합니다.
		ㄴ. *는 문자열 포인터를 이동시키며, *뒤엔 !, \, ^, <ch>가 붙을 수 있습니다. (<ch>는 _또는 숫자 또는 알파벳 하나를 나타냅니다.)
		ㄷ. ^는 not을 나타내며 바로 뒤에 !, \, <ch>의 조건의 반대 연산을 수행시킵니다.
		ㄹ. !은 s, S, w, W, d, D, \n, \r, \t, \f, \<ch>와 매치되며 각각 공백, 공백이외, <ch>, <ch>이외, 숫자, 숫자이외, 기타 공백 문자입니다.
		ㅁ. +는 임시문자열에 추가시키는 명령으로 *명령을 진행하되 단계마다 결과 문자열에 추가시킵니다.
		ㅂ. 그 이외 \~ 형식이나 숫자, 알파벳이 올경우 그것을 임시문자열에 추가합니다.
	10. +는 @, $의 형식을 결과 문자열에 추가합니다.

	조건문 우선순위
	1. (), 숫자, 문자
	2. *, /
	3. +, -
	4. <, <=, >, >=
	5. &, |, ^

	예제
	;@c=%length%?(3<c&c<10)@d=5:@d=4/$x=\"kktu\"/$x1=[*^!s+@d*!s+*^!s+$x]+$x1;

	;
	@c=%length%
	?(3<c&c<10)
	 @d=5
	:
	 @d=4
	/
	$x="kktu"
	/
	$x1=[
		*^!s
		 +@d
		*!s
		+*^!s
		+$x
		]
	+$x1
	;
	////////////////
	시작
	c에 문자 크기 대입
	c가 조건을 만족할 경우 d에 5를 대입하고, 아니면 4를 대입함
	x에 kktu대입
	x1에선 포인터를 공백전까지 옮기고, 
	d를 임시문자열에 대입하고, 
	포인터를 공백까지 옮기고,
	임시문자열에 공백전까지 대입한 후
	x를 임시문자열에 대입합니다.
	x1을 결과 문자열에 추가
	종료

***************************************************************************/

#include <malloc.h>
#include <memory.h>

#include "costume.h"
#include "rocket.h"

pcostumex costume_init()
{
	pcostumex def = (pcostumex) malloc (sizeof(costumex));
	def->data = 0;
	def->name = 0;
	def->_Next = 0;
	return def;
}

void costume_release(pcostumex pd)
{
	for (; pd; pd = pd->_Next) {
		free(pd->name);
	}
}

pcostumestrx costumestr_init()
{
	pcostumestrx def = (pcostumestrx) malloc (sizeof(costumestrx));
	def->data = 0;
	def->name = 0;
	def->_Next = 0;
	return def;
}

void costumestr_release(pcostumestrx pd)
{
	for (; pd; pd = (pcostumestrx)(pd->_Next)) {
		free(pd->name);
		free(pd->data);
	}
}

pcostumex _costume_find_variable(const pcostumex cxlist, const char *variable_name);
pcostumestrx _costume_find_strvariable(const pcostumestrx cxlist, const char *variable_name);
u32 _costume_process_function(const pcostumex cxlist, const char *function_name, const char *target);
const char *_costume_ict; // _costume_internal_condition_text
BOOL _costume_if(const pcostumex cxlist, const char *condition_text);
BOOL __costume_internal_if_and_or(const pcostumex cxlist);
BOOL __costume_internal_if_var(const pcostumex cxlist);
BOOL __costume_internal_if_sec(const pcostumex cxlist);
BOOL __costume_internal_if_condition(const pcostumex cxlist);
BOOL __costume_internal_if_factor(const pcostumex cxlist);
char *_costume_get_string(const pcostumestrx cxstrlist, const pcostumex cxlist, const CHAR *target, const CHAR *format);

BOOL process_costume(const CHAR *target, CHAR *source, const CHAR *format)
{
	pcostumex variables, selected, temp, last_var;
	pcostumestrx strvariables, strselected, strtemp, strlast_var;
	PCHAR pointer;
	char *_temp;
	int count, value;
	BOOL ifcon;
	CHAR *srcptr;

	pointer = (char *)format;
	srcptr = source;
	ifcon = FALSE;
	last_var = variables = costume_init();
	strlast_var = strvariables = costumestr_init();
	selected = NULL, strselected = NULL;

	for (; *pointer != _COTM_OPEN && *pointer; pointer++)
		;

	if (*pointer == '\0')
		return _CTOM_ERROR_NOT_EXIST_FORAMT;

	pointer++;

	do {
		switch (*pointer++)
		{
		case _COTM_CLOSE:
			costume_release(variables);
			return _CTOM_SUCCESS;	// end

		case _COTM_FUNCTION: // function call @var=%func%
			if (selected == NULL)
				return _CTOM_ERROR_FUNCTIONCALL_BEFOR_LVALUE;
			
			_temp = (char *)malloc(sizeof(char) * 20);
			for (count = 0; *pointer && *pointer != _COTM_FUNCTION; pointer++, count++)
				_temp[count] = *pointer;
			_temp[count] = 0;

			pointer++; // *pointer is pointer to '%'
if(ifcon == FALSE){
				// no-operate error
			selected->data = _costume_process_function(variables, _temp, target);
			selected = NULL; // abort selected variable
}
			break;

		case _COTM_VARIABLE: // @asdf, @asdf=
			temp = costume_init();

			_temp = (char *)malloc(sizeof(char) * 20);
			for (count = 0; _isalnumub((int)(*pointer)); pointer++, count++)
				_temp[count] = *pointer;
			_temp[count] = 0;

			if (NULL != (selected = _costume_find_variable(variables, _temp)))
if(ifcon == FALSE){
				return _CTOM_ERROR_ALREADY_EXIST_VARIABLE;
} else;
			
if(ifcon == FALSE){
			temp->name = _temp;
			last_var->_Next = temp;
			last_var = temp;
}
			if(*pointer == _COTM_LVALUE) {
				selected = temp;
				pointer++;
			}
			break;

		case _COTM_STRVARIABLE: // $asdf, $asdf="~~~"
			strtemp = costumestr_init();

			_temp = (char *)malloc(sizeof(char) * 20);
			for (count = 0; _isalnumub((int)(*pointer)); pointer++, count++)
				_temp[count] = *pointer;
			_temp[count] = 0;

			if (NULL != (strselected = _costume_find_strvariable(strvariables, _temp)))
if(ifcon == FALSE){
				return _CTOM_ERROR_ALREADY_EXIST_VARIABLE;
} else;
			
if(ifcon == FALSE){
			strtemp->name = _temp;
			strlast_var->_Next = (struct _costume_str* )strtemp;
			strlast_var = strtemp;
}
			if(*pointer == _COTM_LVALUE) {
				strselected = strtemp;
				pointer++;
			}
			break;

		case _COTM_IF:
			if (*pointer++ != _COTM_BRET_OPEN)
				return _CTOM_ERROR_NOT_FOUND_IF_SCOPE;

			value = _costume_if(variables, pointer);
			if (value)
				ifcon = FALSE;
			else
				ifcon = TRUE;

			pointer = (PCHAR)_costume_ict;

			if (*pointer == _COTM_BRET_CLOSE)
				pointer++;
			else
				return _CTOM_ERROR_NOT_FOUND_SCOPE_CLOSE;
			break;

		case _COTM_ELSE:
			if (ifcon == FALSE)
				ifcon = TRUE;
			else
				ifcon = FALSE;
			break;

		case _COTM_DELIMITER:
			ifcon = FALSE;
			break;

		case _COTM_SHARP:
			switch(*pointer++)
			{
			case '#': *srcptr++ = '0'; *srcptr++ = 'x'; break;
			}
			break;

		case _COTM_OPTIONS: // add function
			switch(*pointer++)
			{
			case 'n': *srcptr++ = '\n'; break;
			case 'r': *srcptr++ = '\r'; break;
			case 't': *srcptr++ = '\t'; break;
			case 'f': *srcptr++ = '\f'; break;
			default: *srcptr++ = *(pointer-1); break;
			}
			break;

		case _COTM_CONNECTION:
			switch(*pointer++)
			{
			case _COTM_VARIABLE:
				_temp = (char *)malloc(sizeof(char) * 20);
				for (count = 0; _isalnumub((int)(*pointer)); pointer++, count++)
					_temp[count] = *pointer;
				_temp[count] = 0;

				if (NULL == (selected = _costume_find_variable(variables, _temp)))
					return _CTOM_ERROR_NOT_FOUND_VARIABLE;

				free(_temp);
				
if(ifcon == FALSE){
				_temp = __itoa(selected->data);

				for (; *_temp; _temp++)
					*srcptr++ = *_temp;
}
				selected = NULL;
				break;

			case _COTM_STRVARIABLE:
				_temp = (char *)malloc(sizeof(char) * 20);
				for (count = 0; _isalnumub((int)(*pointer)); pointer++, count++)
					_temp[count] = *pointer;
				_temp[count] = 0;
				
				if (NULL == (strselected = _costume_find_strvariable(strvariables, _temp)))
					return _CTOM_ERROR_NOT_FOUND_VARIABLE;

				free(_temp);
				
if(ifcon == FALSE){
				_temp = strselected->data;

				for (; *_temp; _temp++)
					*srcptr++ = *_temp;
}
				strselected = NULL;
				break;

			default:
				return _CTOM_ERROR_NOT_EXIST_FORAMT;
			}
			break;

		default:
			if(selected != NULL || strselected != NULL) {
				pointer--; // for 'pointer++'
				
				if(*pointer == _COTM_STRDELIMITER) {
					if (strselected == NULL)
						return _CTOM_ERROR_STRINGPTR_BEFOR_LVALUE;
					pointer++;

					_temp = (char *)malloc(sizeof(char) * 256);
					for (count = 0; *pointer != _COTM_STRDELIMITER; pointer++, count++)
						if(*pointer == _COTM_OPTIONS) {
							pointer++;
							_temp[count] = *pointer;
						} else {
							_temp[count] = *pointer;
						}
					_temp[count] = 0;

					pointer++;
if(ifcon == FALSE){
					strselected->data = _temp;
					strselected = NULL;
}
					break;
				} else if(*pointer == _COTM_PAREN_OPEN) {
					if (strselected == NULL)
						return _CTOM_ERROR_STRINGPTR_BEFOR_LVALUE;
					pointer++;

					_temp = _costume_get_string(strvariables, variables, target, pointer);

					pointer = (PCHAR)++_costume_ict;
					
if(ifcon == FALSE){
					strselected->data = _temp;
}
					break;
				} else {
					if (selected == NULL)
						return _CTOM_ERROR_INTEGERPTR_BEFOR_LVALUE;

					_temp = (char *)malloc(sizeof(char) * 20);
					for (count = 0; _isdigit(*pointer); pointer++, count++)
						_temp[count] = *pointer;
					_temp[count] = 0;
if(ifcon == FALSE){
					selected->data = _atoi(_temp);
					selected = NULL;
}
					break;
				}
			} else
				return _CTOM_ERROR_NOT_FOUND_OPTION;
		}
	} while (*pointer);

	return _CTOM_SUCCESS;
}

pcostumex _costume_find_variable(const pcostumex cxlist, const char *variable_name)
{
	const costumex *ptr = cxlist->_Next;

	for (; ptr != NULL; ptr = ptr->_Next)
		if(!_strcmp_asc(ptr->name, variable_name))
			return (pcostumex)ptr;

	return NULL;
}

pcostumestrx _costume_find_strvariable(const pcostumestrx cxlist, const char *variable_name)
{
	const costumestrx *ptr = (const costumestrx *)(cxlist->_Next);

	for (; ptr != NULL; ptr = (pcostumestrx)(ptr->_Next))
		if(!_strcmp_asc(ptr->name, variable_name))
			return (pcostumestrx)ptr;

	return NULL;
}

u32 _costume_process_function(const pcostumex cxlist, const char *function_name, const char *target)
{
	if (!_strcmp_asc(function_name, "length"))
		return _strlen_asc(target);

	return NULL;
}

BOOL _costume_if(const pcostumex cxlist, const char *condition_text)
{
	_costume_ict = condition_text;
	return __costume_internal_if_and_or(cxlist);
}
	
/////////////////////////////////////////////////////////////////////////////////////
	BOOL __costume_internal_if_and_or(const pcostumex cxlist)
	{
		BOOL tmp = __costume_internal_if_condition(cxlist);
		if (*_costume_ict == '&'){
			_costume_ict++;
			if (tmp && __costume_internal_if_and_or(cxlist))
				return TRUE;
			else
				return FALSE;
		} else if (*_costume_ict == '|') {
			_costume_ict++;
			if (tmp || __costume_internal_if_and_or(cxlist))
				return TRUE;
			else
				return FALSE;
		} else if (*_costume_ict == '^') {
			_costume_ict++;
			if (tmp != __costume_internal_if_and_or(cxlist))
				return TRUE;
			else
				return FALSE;
		}
		return tmp;
	}

	BOOL __costume_internal_if_condition(const pcostumex cxlist)
	{
		BOOL tmp = __costume_internal_if_var(cxlist);
		if (*_costume_ict == '<') {
			_costume_ict++;
			if(*(_costume_ict + 1) == '='){
				_costume_ict++;
				if (tmp <= __costume_internal_if_var(cxlist))
					return TRUE;
				else
					return FALSE;
			} else {
				if (tmp < __costume_internal_if_var(cxlist))
					return TRUE;
				else
					return FALSE;
			}
		} else if (*_costume_ict == '>') {
			_costume_ict++;
			if(*(_costume_ict + 1) == '='){
				_costume_ict++;
				if (tmp >= __costume_internal_if_var(cxlist))
					return TRUE;
				else
					return FALSE;
			} else {
				if (tmp > __costume_internal_if_var(cxlist))
					return TRUE;
				else
					return FALSE;
			}
		} else if (*_costume_ict == '=') {
			_costume_ict++;
			if (tmp == __costume_internal_if_var(cxlist))
				return TRUE;
			else
				return FALSE;
		}
		return tmp;
	}

	BOOL __costume_internal_if_var(const pcostumex cxlist)
	{
		BOOL ret = __costume_internal_if_sec(cxlist);
		while ((*_costume_ict == '+') || (*_costume_ict == '-')) {
			if(*_costume_ict == '+') {
				_costume_ict++;
				ret += __costume_internal_if_factor(cxlist);
			} else if (*_costume_ict == '-') {
				_costume_ict++;
				ret -= __costume_internal_if_factor(cxlist);
			}
		}
		return ret;
	}

	BOOL __costume_internal_if_sec(const pcostumex cxlist)
	{
		BOOL ret = __costume_internal_if_factor(cxlist);
		while ((*_costume_ict == '*') || (*_costume_ict == '/')) {
			if(*_costume_ict == '*') {
				_costume_ict++;
				ret *= __costume_internal_if_factor(cxlist);
			} else if (*_costume_ict == '/') {
				_costume_ict++;
				ret /= __costume_internal_if_factor(cxlist);
			}
		}
		return ret;
	}

	BOOL __costume_internal_if_factor(const pcostumex cxlist)
	{
		BOOL ret = 0;
		if(*_costume_ict == '(') {
			_costume_ict++;
			ret = __costume_internal_if_and_or(cxlist);
			_costume_ict++;
		} else if (_isnumeric(*_costume_ict)) {
			if(*_costume_ict == '0') {
				if(*++_costume_ict == 'x') { // only lower
					_costume_ict++;
					while(TRUE) {
						if(_isnumeric(*_costume_ict)) {
							ret = ret * 16 + *_costume_ict - '0';
							_costume_ict++;
						} else if (_isalpha(*_costume_ict)) {
							ret = ret * 16 + _to_lower(*_costume_ict) - 'a';
							_costume_ict++;
						} else {
							break;
						}
					}
				} else {
					while(_isnumeric(*_costume_ict)) {
						ret = ret * 8 + *_costume_ict++ - '0';
					}
				}
			} else {
				while(_isnumeric(*_costume_ict)) {
					ret = ret * 10 + *_costume_ict++ - '0';
				}
			}
		} else if (_isalpha(*_costume_ict) || *_costume_ict == '_') {
			char _temp[20] = {0,}; // find temp
			int count;
			pcostumex tmp;

			for (count = 0; _isalnumub((int)(*_costume_ict)); _costume_ict++, count++)
				_temp[count] = *_costume_ict;
			_temp[count] = 0;

			if (NULL == (tmp = _costume_find_variable(cxlist, _temp)))
				return -1; // error

			ret = (BOOL)tmp->data;
		}
		return ret;
	}
/////////////////////////////////////////////////////////////////////////////////////
	
char *_costume_get_string(const pcostumestrx cxstrlist, const pcostumex cxlist, const CHAR *target, const CHAR *format)
{
	char *ret = (char *) malloc (sizeof(char) * 1024);
	char *ptr = ret, *tmpptr, *tarptr;
	char tmp;
	char _temp[20] = {0,}; // find temp
	u32 inttmp;
	int count;
	pcostumex costmp;
	pcostumestrx cosstrtmp;
	BOOL not;

#define CONDITION(x) ((x) && not) || (!(x) && !not)
	tarptr = (char *)target;
	_costume_ict = format;
	memset(ret, 0, sizeof(char) * 1024);
	
	do {
		switch(*_costume_ict++)
		{
		case '+': // add variable to ret
			switch(*_costume_ict++) {
			case _COTM_VARIABLE:
				for (count = 0; _isalnumub((int)(*_costume_ict)); _costume_ict++, count++)
					_temp[count] = *_costume_ict;
				_temp[count] = 0;
				
				if (NULL == (costmp = _costume_find_variable(cxlist, _temp)))
					return (char *)-1; // error
				inttmp = costmp->data;

				tmpptr = __itoa(inttmp);
				for (; *tmpptr; tmpptr++)
					*ptr++ = *tmpptr;

				break;

			case _COTM_STRVARIABLE:
				for (count = 0; _isalnumub((int)(*_costume_ict)); _costume_ict++, count++)
					_temp[count] = *_costume_ict;
				_temp[count] = 0;
				
				if (NULL == (cosstrtmp = _costume_find_strvariable(cxstrlist, _temp)))
					return (char *)-1; // error

				tmpptr = cosstrtmp->data;
				for (; *tmpptr; tmpptr++)
					*ptr++ = *tmpptr;

				break;

			case '*': // *x, *@int, *$str, *!x
			RE1:
				switch(*_costume_ict++) {
				case '!':
					switch(*_costume_ict++) {
					case 's': while (CONDITION(_isspace(*tarptr))) *ptr++ = *tarptr++; break;
					case 'S': while (CONDITION(!_isspace(*tarptr))) *ptr++ = *tarptr++; break;
					case 'd': while (CONDITION(_isnumeric(*tarptr))) *ptr++ = *tarptr++; break;
					case 'D': while (CONDITION(!_isnumeric(*tarptr))) *ptr++ = *tarptr++; break;
					case 'w': while (CONDITION(_isalnumub(*tarptr))) *ptr++ = *tarptr++; break;
					case 'W': while (CONDITION(!_isalnumub(*tarptr))) *ptr++ = *tarptr++; break;
					case '\\':
						switch(*_costume_ict++)
						{
						case 'n': while (CONDITION(*tarptr == '\n')) *ptr++ = *tarptr++; break;
						case 'r': while (CONDITION(*tarptr == '\r')) *ptr++ = *tarptr++; break;
						case 't': while (CONDITION(*tarptr == '\t')) *ptr++ = *tarptr++; break;
						case 'f': while (CONDITION(*tarptr == '\f')) *ptr++ = *tarptr++; break;
						default: while(CONDITION(*tarptr == *(_costume_ict-1))) *ptr++ = *tarptr++; break;
						}
						break;

					}
					not = TRUE;
					break;

				case '\\':
					switch(*_costume_ict++)
					{
					case 'n': if(CONDITION(*tarptr == '\n')) *ptr++ = *tarptr++; break;
					case 'r': if(CONDITION(*tarptr == '\r')) *ptr++ = *tarptr++; break;
					case 't': if(CONDITION(*tarptr == '\t')) *ptr++ = *tarptr++; break;
					case 'f': if(CONDITION(*tarptr == '\f')) *ptr++ = *tarptr++; break;
					default: if(CONDITION(*tarptr == *(_costume_ict-1))) *ptr++ = *tarptr++; break;
					}
					not = TRUE;
					break;

				case '^': // not
					not = FALSE;
					goto RE1;
					break;

				default:
					if(_isalnumub((int)(*_costume_ict))) {
						if(CONDITION(*tarptr == *_costume_ict)) 
							*ptr++ = *tarptr++;
						not = TRUE;
					}
					break;
				}
				break;

			}
			break;

		case '*': // *x, *@int, *$str, *!x
		RE2:
			switch(*_costume_ict++) {
			case '!':
				switch(*_costume_ict++) {
				case 's': while (CONDITION(_isspace(*tarptr))) tarptr++; break;
				case 'S': while (CONDITION(!_isspace(*tarptr))) tarptr++; break;
				case 'd': while (CONDITION(_isnumeric(*tarptr))) tarptr++; break;
				case 'D': while (CONDITION(!_isnumeric(*tarptr))) tarptr++; break;
				case 'w': while (CONDITION(_isalnumub(*tarptr))) tarptr++; break;
				case 'W': while (CONDITION(!_isalnumub(*tarptr))) tarptr++; break;
				case '\\':
					switch(*_costume_ict++)
					{
					case 'n': while (CONDITION(*tarptr == '\n')) tarptr++; break;
					case 'r': while (CONDITION(*tarptr == '\r')) tarptr++; break;
					case 't': while (CONDITION(*tarptr == '\t')) tarptr++; break;
					case 'f': while (CONDITION(*tarptr == '\f')) tarptr++; break;
					default: while(CONDITION(*tarptr == *(_costume_ict-1))) tarptr++; break;
					}
					break;

				}
				not = TRUE;
				break;

			case '\\':
				switch(*_costume_ict++)
				{
				case 'n': if(CONDITION(*tarptr == '\n')) tarptr++; break;
				case 'r': if(CONDITION(*tarptr == '\r')) tarptr++; break;
				case 't': if(CONDITION(*tarptr == '\t')) tarptr++; break;
				case 'f': if(CONDITION(*tarptr == '\f')) tarptr++; break;
				default: if(CONDITION(*tarptr == *(_costume_ict-1))) tarptr++; break;
				}
				not = TRUE;
				break;

			case '^': // not
				not = FALSE;
				goto RE2;
				break;

			default:
				if(_isalnumub((int)(*_costume_ict))) {
					if(CONDITION(*tarptr == *_costume_ict)) 
						*tarptr++;
					not = TRUE;
				}
				break;
			}
			break;

		case '/': // Delimiter
			break;

		case '\\':
			switch(*_costume_ict++)
			{
			case 'n': *ptr++ = '\n'; break;
			case 'r': *ptr++ = '\r'; break;
			case 't': *ptr++ = '\t'; break;
			case 'f': *ptr++ = '\f'; break;
			default: *ptr++ = *(_costume_ict-1); break;
			}
			break;

		default:
			if (_isalnum((int)(tmp = *(_costume_ict - 1)))) {
				*ptr++ = tmp;
				for (; _isalnum((int)*_costume_ict); _costume_ict++)
					*ptr++ = *_costume_ict;
			}
			break;
		}
	} while (*_costume_ict && *_costume_ict != ']');
	return ret;
}