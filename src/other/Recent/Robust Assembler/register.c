/*************************************************************************
 *
 * FILE NAME : register.c - register analysis
 *
 * ROLLRAT SOFTWARE Robust Assembler (RASM)
 *
 *
 * LANGUAGE : ANSI C
 * CREATION : 2015.01.02
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com, rollrat.software@gmail.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#include "register.h"
#include "rocket.h"
#include "utility.h"
#include <malloc.h>

/*
	@get_register : 오퍼랜드에 들어갈 수 있는 부분을 조사하고
	                 PREGISTER를 이용하여 내보냄

	@str          : 분석중인 문자열의 포인터
*/
PREGISTER get_register(const char *str)
{
	const char *ptr = str;
	PREGISTER reg = ((PREGISTER) malloc (sizeof(REGISTER)));
	int thirdc;
	
	// 중요 : 이 함수는 다음과 같은 구문은 처리하지 못합니다
	//	[<num2> + <reg> * <num1>]
	//	[<num1> * <reg> + <num2>]
	//	[<num2>	+ <num1> * <reg>]
	//	[<num1> * <reg>]
	//	[<num1> + <reg>]

	//
	//	[<reg> * <num1> + <num2>] 형식일 경우 이 플래그는 활성화됨
	//
	thirdc = FALSE;

	//
	//	레지스터 구분자[$]를 확인하고 있으면 레지스터를,
	//	없으면 숫자와 그 밖의 것이랑 매치되는지 확인함.
	//
	if (*ptr++ != REGISTER_DELIMITER) {
		ptr--;
		if(_isdigit(*ptr) || _isxdigit(*ptr) || *ptr == '-' || *ptr == '+') {
			const char * t = ptr;
			int get;

			reg->type = REGISTER_TYPE_NUMBERIC;

			//
			//	맨 끝의 문자를 확인하기 위해 포인터를 옮김
			//
			_util_skip_function(&t, _isspace);
			_util_skip_function(&t, _isxdigit);
			_util_skip_function(&t, _isspace);

			if(*t=='o')
				get = get_oct(ptr);
			else if(*t=='h')
				get = get_hex(ptr);
			else
				get = get_integer(ptr);

			reg->first = get;

			return reg;
		} else {
			return NULL;
		}
	}

	//
	//	rxx, exx와 참조형 오퍼랜드를 분석함
	//	디폴트 값은 16bit형 오퍼랜드임
	//
RE:	switch(*ptr)
	{
	case '[':
		reg->type = REGISTER_TYPE_REFERENCE; 
		_util_skip_function(&ptr, _isspace);
		ptr++;
		goto RE;
	{ case 'e': reg->bit = 32; goto SET; }
	{ case 'r': reg->bit = 64; goto SET; }
	{ default:  reg->bit = 16; break; }
SET:
		if (reg->type != REGISTER_TYPE_REFERENCE)
			reg->type = REGISTER_TYPE_NORMAL;
		ptr++;
	}
	
	//
	//	exx, rxx에서 e, r을 넘긴 레지스터를 분석함
	//	형식은 모두 16bit로 통일
	//
	switch(*ptr)
	{
	case 'a':
		if(*(ptr+1)=='x')
			reg->first = AX;
		else if (*(ptr+1)=='l')
			reg->first = AL;
		else if (*(ptr+1)=='h')
			reg->first = AH;
		break;
	case 'b':
		if(*(ptr+1)=='p')
			reg->first = BP;
		else if(*(ptr+1)=='x')
			reg->first = BX;
		else if (*(ptr+1)=='l')
			reg->first = BL;
		else if (*(ptr+1)=='h')
			reg->first = BH;
		break;
	case 'c':
		if(*(ptr+1)=='x')
			reg->first = CX;
		else if (*(ptr+1)=='l')
			reg->first = CL;
		else if (*(ptr+1)=='h')
			reg->first = CH;
		break;
	case 'd':
		if(*(ptr+1)=='i')
			reg->first = DI;
		else if(*(ptr+1)=='x')
			reg->first = DX;
		else if (*(ptr+1)=='l')
			reg->first = DL;
		else if (*(ptr+1)=='h')
			reg->first = DH;
		break;
	case 's':
		if(*(ptr+1)=='p')
			reg->first = SP;
		else if(*(ptr+1)=='i')
			reg->first = SI;
		break;
	}

	//
	//	일반 레지스터 형식이면 더 이상 분석할 필요없으니
	//	그냥 반환함
	//
	if(reg->type == REGISTER_TYPE_NORMAL)
		return reg;

	//
	//	분석했던 레지스터의 총 길이지 2이므로
	//
	ptr += 2;
	_util_skip_function(&ptr, _isspace);

	//
	//	일반 참조형 레지스터 형식
	//
	if (*ptr == ']') {
		reg->type = REGISTER_TYPE_SIGNLE_REFERENCE;
		return reg;
	}

	//
	//	']'를 만나지 않으면 뭔가 더 있는 것임으로
	//
	if (*ptr == '+')
		reg->sign = REGISTER_REFERENCE_SIGN_PLUS;
	else if (*ptr == '-')
		reg->sign = REGISTER_REFERENCE_SIGN_MINUS;
	else if (*ptr == '*')
		reg->sign = REGISTER_REFERENCE_SIGN_MULTIPLE;
	_util_skip_function(&ptr, _isspace);

	ptr++;

	//
	//	16진수의 문자열일 경우 ffh나, a2h같은 문자가 먼저 나와있을 수 있는데
	//	이 경우엔 분석을 막아 변수로 취급한다. 그로 인해 16진수의 경우엔 
	//	0ffh, 0a2h와 같이 나타내어야 한다.
	//
	if('0' <= *ptr && *ptr <= '9')
	{
		const char * t = ptr;
		int get;
		for (; *t != ']' && *t; t++)
			if (*t == '-' || *t == '+') {

				//
				//	[<reg> * <num1> + <num2>] 형식임이 확증됨
				//
				thirdc = TRUE;
				break;
			}

		//
		//	*t == NULL이면 열린 괄호가 닫히지 않았으므로 당연한 오류
		//
		if (!*t--)
			return NULL;

		//
		//	']'가 나오기 전에 공백이 포함되어있을 수 있으므로
		//
		for (; _isspace(*t); t--)
			;


		if(*t=='o')
			get = get_oct(ptr);
		else if(*t=='h')
			get = get_hex(ptr);
		else
			get = get_integer(ptr);

		reg->second = get;
		reg->type = REGISTER_TYPE_REFERENCE;

		if (thirdc == TRUE) {
			//
			//	이 코드구역은 상기구역과 동일함
			//
			const char * ptr = t+1;
			int get;
			_util_skip_function(&ptr, _isspace);

			if (*ptr == '+')
				reg->sign = REGISTER_REFERENCE_SIGN_MULTIPLE_PLUS;
			else if (*ptr == '-')
				reg->sign = REGISTER_REFERENCE_SIGN_MULTIPLE_MINUS;
			_util_skip_function(&ptr, _isspace);

			for (; *t != ']' && *t; t++)
				;

			if (!*t--)
				return NULL;

			for (; _isspace(*t); t--)
				;

			if(*t=='o')
				get = get_oct(ptr);
			else if(*t=='h')
				get = get_hex(ptr);
			else
				get = get_integer(ptr);
			reg->third = get;
		}
	}
	else
	{
		//
		//	숫자가 나오지 않은 경우엔 변수로 취급한다.
		//에러없음
	}
	
	return reg;
}

int get_oct(const char *_t)
{
	const char *_Ptr = _t;
	int g = 0, h = 1;
	if (*_Ptr == '-')
		*_Ptr++, h = -1;
	for (; *_Ptr != 'o'; _Ptr++)
		g *= 8, g += *_Ptr & 0xf;
	return g*h;
}

int get_integer(const char *_t)
{
	const char *_Ptr = _t;
	int g = 0, h = 1;
	if (*_Ptr == '-')
		*_Ptr++, h = -1;
	for (; '0' <= *_Ptr && *_Ptr <= '9'; _Ptr++)
		 g *= 10, g += *_Ptr & 0xf;
	return g*h;
}

int get_hex(const char *_t)
{
	const char *_Ptr = _t;
	int g = 0, h = 1;
	if (*_Ptr == '-')
		*_Ptr++, h = -1;
	for (; *_Ptr != 'h'; _Ptr++)
		g *= 16, g += ('0' <= *_Ptr  && *_Ptr  <= '9') ? (*_Ptr & 0xf) : (_to_lower(*_Ptr)  - 'a' + 0xa);
	return g*h;
}