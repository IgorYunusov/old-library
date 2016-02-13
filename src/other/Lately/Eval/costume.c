/*************************************************************************
 *
 * FILE NAME : costume.c
 *
 * ROLLRAT SOFTWARE Robust Assembler (RASM)
 *
 *
 * LANGUAGE : ANSI C
 * CREATION : 2014.12.27
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com, rollrat.software@gmail.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

/****

			COSTUME. Custom to string by format. Ver 0.1

***************************************************************************/

#include <malloc.h>
#include <memory.h>

#include "costume.h"
#include "rocket.h"
#include "rasm.h"

#define _LEAK_TEST
#include "leak.h"

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
	for (; pd; pd = pd->_Next) {
		free(pd->name);
		free(pd->data);
	}
}

pcostumex _costume_find_variable(const pcostumex cxlist, const char *variable_name);
pcostumestrx _costume_find_strvariable(const pcostumestrx cxlist, const char *variable_name);
u32 _costume_process_function(const pcostumex cxlist, const char *function_name, const char *target);
const char *_costume_ict; // _costume_internal_condition_text
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

	pointer = format;
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
			strlast_var->_Next = strtemp;
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

			pointer = _costume_ict;

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

					pointer = ++_costume_ict;
					
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
			return ptr;

	return NULL;
}

pcostumestrx _costume_find_strvariable(const pcostumestrx cxlist, const char *variable_name)
{
	const costumestrx *ptr = cxlist->_Next;

	for (; ptr != NULL; ptr = ptr->_Next)
		if(!_strcmp_asc(ptr->name, variable_name))
			return ptr;

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
	tarptr = target;
	_costume_ict = format;
	ZeroSet(ret, sizeof(char) * 1024);
	
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
					return -1; // error
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
					return -1; // error

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