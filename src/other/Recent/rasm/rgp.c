/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   rgp.c - [Private]

Project:

   Robust Assembler (RASM)
   
Abstract:

   Register parser

------
   AUTHOR: HyunJun Jeong  2015-01-05

***************************************************************************/

#include "reg.h"
#include "rocket.h"
#include <malloc.h>

#define HASH_BEFORE_SMALL_A \
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

static const char _Hash_Register_A[123] = {
	HASH_BEFORE_SMALL_A
	0,  /* 'a' */
	0,  /* 'b' */
	0,  /* 'c' */
	0,  /* 'd' */
	0,  /* 'e' */
	0,  /* 'f' */
	0,  /* 'g' */
	AH, /* 'h' */
	0,  /* 'i' */
	0,  /* 'j' */
	0,  /* 'k' */
	AL, /* 'l' */
	0,  /* 'm' */
	0,  /* 'n' */
	0,  /* 'o' */
	0,  /* 'p' */
	0,  /* 'q' */
	0,  /* 'r' */
	0,  /* 's' */
	0,  /* 't' */
	0,  /* 'u' */
	0,  /* 'v' */
	0,  /* 'w' */
	AX, /* 'x' */
	0,  /* 'y' */
	0,  /* 'z' */
};

static const char _Hash_Register_B[123] = {
	HASH_BEFORE_SMALL_A
	0,  /* 'a' */
	0,  /* 'b' */
	0,  /* 'c' */
	0,  /* 'd' */
	0,  /* 'e' */
	0,  /* 'f' */
	0,  /* 'g' */
	BH, /* 'h' */
	0,  /* 'i' */
	0,  /* 'j' */
	0,  /* 'k' */
	BL, /* 'l' */
	0,  /* 'm' */
	0,  /* 'n' */
	0,  /* 'o' */
	BP, /* 'p' */
	0,  /* 'q' */
	0,  /* 'r' */
	0,  /* 's' */
	0,  /* 't' */
	0,  /* 'u' */
	0,  /* 'v' */
	0,  /* 'w' */
	BX, /* 'x' */
	0,  /* 'y' */
	0,  /* 'z' */
};

static const char _Hash_Register_C[123] = {
	HASH_BEFORE_SMALL_A
	0,  /* 'a' */
	0,  /* 'b' */
	0,  /* 'c' */
	0,  /* 'd' */
	0,  /* 'e' */
	0,  /* 'f' */
	0,  /* 'g' */
	CH, /* 'h' */
	0,  /* 'i' */
	0,  /* 'j' */
	0,  /* 'k' */
	CL, /* 'l' */
	0,  /* 'm' */
	0,  /* 'n' */
	0,  /* 'o' */
	0,  /* 'p' */
	0,  /* 'q' */
	0,  /* 'r' */
	CS, /* 's' */
	0,  /* 't' */
	0,  /* 'u' */
	0,  /* 'v' */
	0,  /* 'w' */
	CX, /* 'x' */
	0,  /* 'y' */
	0,  /* 'z' */
};

static const char _Hash_Register_D[123] = {
	HASH_BEFORE_SMALL_A
	0,  /* 'a' */
	0,  /* 'b' */
	0,  /* 'c' */
	0,  /* 'd' */
	0,  /* 'e' */
	0,  /* 'f' */
	0,  /* 'g' */
	DH, /* 'h' */
	DI, /* 'i' */
	0,  /* 'j' */
	0,  /* 'k' */
	DL, /* 'l' */
	0,  /* 'm' */
	0,  /* 'n' */
	0,  /* 'o' */
	0,  /* 'p' */
	0,  /* 'q' */
	0,  /* 'r' */
	DS, /* 's' */
	0,  /* 't' */
	0,  /* 'u' */
	0,  /* 'v' */
	0,  /* 'w' */
	DX, /* 'x' */
	0,  /* 'y' */
	0,  /* 'z' */
};

static const char _Hash_Register_E[123] = {
	HASH_BEFORE_SMALL_A
	0,  /* 'a' */
	0,  /* 'b' */
	0,  /* 'c' */
	0,  /* 'd' */
	0,  /* 'e' */
	0,  /* 'f' */
	0,  /* 'g' */
	0,  /* 'h' */
	0,  /* 'i' */
	0,  /* 'j' */
	0,  /* 'k' */
	0,  /* 'l' */
	0,  /* 'm' */
	0,  /* 'n' */
	0,  /* 'o' */
	0,  /* 'p' */
	0,  /* 'q' */
	0,  /* 'r' */
	ES, /* 's' */
	0,  /* 't' */
	0,  /* 'u' */
	0,  /* 'v' */
	0,  /* 'w' */
	0,  /* 'x' */
	0,  /* 'y' */
	0,  /* 'z' */
};

static const char _Hash_Register_F[123] = {
	HASH_BEFORE_SMALL_A
	0,  /* 'a' */
	0,  /* 'b' */
	0,  /* 'c' */
	0,  /* 'd' */
	0,  /* 'e' */
	0,  /* 'f' */
	0,  /* 'g' */
	0,  /* 'h' */
	0,  /* 'i' */
	0,  /* 'j' */
	0,  /* 'k' */
	0,  /* 'l' */
	0,  /* 'm' */
	0,  /* 'n' */
	0,  /* 'o' */
	0,  /* 'p' */
	0,  /* 'q' */
	0,  /* 'r' */
	FS, /* 's' */
	0,  /* 't' */
	0,  /* 'u' */
	0,  /* 'v' */
	0,  /* 'w' */
	0,  /* 'x' */
	0,  /* 'y' */
	0,  /* 'z' */
};

static const char _Hash_Register_G[123] = {
	HASH_BEFORE_SMALL_A
	0,  /* 'a' */
	0,  /* 'b' */
	0,  /* 'c' */
	0,  /* 'd' */
	0,  /* 'e' */
	0,  /* 'f' */
	0,  /* 'g' */
	0,  /* 'h' */
	0,  /* 'i' */
	0,  /* 'j' */
	0,  /* 'k' */
	0,  /* 'l' */
	0,  /* 'm' */
	0,  /* 'n' */
	0,  /* 'o' */
	0,  /* 'p' */
	0,  /* 'q' */
	0,  /* 'r' */
	GS, /* 's' */
	0,  /* 't' */
	0,  /* 'u' */
	0,  /* 'v' */
	0,  /* 'w' */
	0,  /* 'x' */
	0,  /* 'y' */
	0,  /* 'z' */
};

static const char _Hash_Register_S[123] = {
	HASH_BEFORE_SMALL_A
	0,  /* 'a' */
	0,  /* 'b' */
	0,  /* 'c' */
	0,  /* 'd' */
	0,  /* 'e' */
	0,  /* 'f' */
	0,  /* 'g' */
	0,  /* 'h' */
	SI, /* 'i' */
	0,  /* 'j' */
	0,  /* 'k' */
	0,  /* 'l' */
	0,  /* 'm' */
	0,  /* 'n' */
	0,  /* 'o' */
	SP, /* 'p' */
	0,  /* 'q' */
	0,  /* 'r' */
	SS, /* 's' */
	0,  /* 't' */
	0,  /* 'u' */
	0,  /* 'v' */
	0,  /* 'w' */
	0,  /* 'x' */
	0,  /* 'y' */
	0,  /* 'z' */
};

static const char *_Hash_Registers[123] = { 
	HASH_BEFORE_SMALL_A
	_Hash_Register_A, /* 'a' */
	_Hash_Register_B, /* 'b' */
	_Hash_Register_C, /* 'c' */
	_Hash_Register_D, /* 'd' */
	_Hash_Register_E, /* 'e' */
	_Hash_Register_F, /* 'f' */
	_Hash_Register_G, /* 'g' */
	0, /* 'h' */
	0, /* 'i' */
	0, /* 'j' */
	0, /* 'k' */
	0, /* 'l' */
	0, /* 'm' */
	0, /* 'n' */
	0, /* 'o' */
	0, /* 'p' */
	0, /* 'q' */
	0, /* 'r' */
	_Hash_Register_S, /* 's' */
	0, /* 't' */
	0, /* 'u' */
	0, /* 'v' */
	0, /* 'w' */
	0, /* 'x' */
	0, /* 'y' */
	0, /* 'z' */
};

static void ParseRegisterNumeric(const char *str, PREGISTER reg);
static size_t RgpSkipFunc(CHAR const const* *target, void *(*func(void *)));
static size_t RgpFindFunc(CHAR const const* *target, void *(*func(void *)));
static u32 RgpMakeOct(const char *ptr);
static u32 RgpMakeHex(const char *ptr);
static u32 RgpMakeDec(const char *ptr);

/*
	@설명: 오퍼랜드에 들어갈 수 있는 부분을 조사
	@str [IN] : 분석중인 문자열의 포인터
	-
	@return: 레지스터 형식의 포인터
*/
PREGISTER ParseRegister(const char *str)
{
	PREGISTER reg = ((PREGISTER) malloc (sizeof(REGISTER)));
	const char *ptr = str;
	int ch;
	BOOL no_check_end;

	no_check_end = FALSE;
	reg->type = reg->bit = 0;

	//
	//	레지스터 연산자가 아닐 경우 숫자를 확인함
	//
	if (*ptr != REGISTER_DELIMITER) {
		no_check_end = TRUE;
		goto SYMBOL;
	}

	//
	//	참조형 레지스터형식 확인
	//
	if (*++ptr == '[') {
		reg->bit = 32;
		reg->type |= REGISTER_TYPE_REFERENCE;
		RgpSkipFunc(&ptr, _isspace); // 공백제거
		ptr++;
	}
	
	//
	//	32bit
	//
	if (_to_lower(*ptr) == 'e') {

		reg->bit = 32;
		ptr++;

	} else if (_isnumeric(*ptr) && reg->type & REGISTER_TYPE_REFERENCE) {

		//
		//	레지스터보다 숫자가 먼저 나온 형식 / 현 버전에서는 비정규 형식이므로 오류
		//
		return NULL;

	} else {

		//
		//	참조형 레지스터에 16bit 레지스터를 대입했을 경우
		//
		if (reg->type & REGISTER_TYPE_REFERENCE)
			return NULL;

		reg->bit = 16;
	}

	//
	//	레지스터의 정보를 얻어옮
	//
	reg->reg_type = _Hash_Registers[_to_lower(*ptr++)][_to_lower(*ptr++)];
	
	RgpSkipFunc(&ptr, _isspace); // 공백제거

	//
	//	일반 레지스터 형식이거나 단순참조레지스터 형식이면 
	//	더 이상 분석할 필요가 없으니 그냥 반환
	//
	if (!reg->type || *ptr == ']')
		return reg;
	
SYMBOL:
	if (*ptr == '+' || *ptr == '-') {
		reg->type |= REGISTER_TYPE_OPERATOR;
		reg->num_sign = *ptr;
	}
	else if (*ptr == '*')
		reg->type |= REGISTER_TYPE_MULTIPLE;

		//
		//	숫자만 처리할 경우
		//
	else if (no_check_end == TRUE) {
		reg->type |= REGISTER_TYPE_OPERATOR;
		ch = reg->num_sign = '+';
	} else

		//
		//	문법 처리 오류
		//
		return NULL;
	

	/* 연산자 건너뛰기 */
	if(no_check_end == FALSE)
		ch = *ptr++;
	RgpSkipFunc(&ptr, _isspace); // 공백제거

	//
	//	+, -, * 연산처리
	//
	if (_isnumeric(*ptr)) {
		const char *p = ptr;

		//
		//	숫자와 매치되는 경우 숫자 마지막에 붙은 h, o를 통하여 
		//	16진수와 8진수를 가려야한다.
		//
		RgpSkipFunc(&p, _isxdigit);

		//
		//	해당 진수에 맞는 숫자를 가져와 연산자 처리 순서에 맞게 넣음
		//
		if( ch == '*' ) {
			if (*p == 'o')
				reg->sib_type = RgpMakeOct(ptr);
			else if (*p == 'h')
				reg->sib_type = RgpMakeHex(ptr);
			else
				reg->sib_type = RgpMakeDec(ptr);
		} else {
			if (*p == 'o')
				reg->num_type = RgpMakeOct(ptr);
			else if (*p == 'h')
				reg->num_type = RgpMakeHex(ptr);
			else
				reg->num_type = RgpMakeDec(ptr);
		}

		//
		//	기호 건너뛰기
		//
		if (*p == 'o' || *p == 'h')
			ptr = p + 1;
		else
			ptr = p;

	} else {

		//
		//	숫자가 아니면 변수이므로 변수를 저장한다
		//

	}

	RgpSkipFunc(&ptr, _isspace); // 공백제거

	//
	//	참조가 끝나지 않았다면 무언가 연산할 것이 남아있으므로
	//
	if (*ptr != ']' && !no_check_end)
		goto SYMBOL;

	return reg;
}

/*
	@설명: 입력된 함수가 False가 나올때까지 포인터를 증가시킴
	@target [OUT] : 분석중인 문자열의 포인터
	@func   [IN]  : 입력할 함수의 포인터
	-
	@return : 증가시킨 포인터의 크기
*/
static size_t RgpSkipFunc(CHAR const const* *target, void *(*func(void *)))
{
	const CHAR *p = *target, *o = *target;

	while(*p)
		if(!(char *)func((void *)*p))
			return (*target = p) - o;
		else
			p++;

	*target = p;
	return -1;
}

/*
	@설명: 입력된 함수가 True가 나올때까지 포인터를 증가시킴
	@target [OUT] : 분석중인 문자열의 포인터
	@func   [IN]  : 입력할 함수의 포인터
	-
	@return : 증가시킨 포인터의 크기
*/
static size_t RgpFindFunc(CHAR const const* *target, void *(*func(void *)))
{
	const CHAR *p = *target, *o = *target;

	while(*p)
		if((char *)func((void *)*p))
			return (*target = p) - o;
		else
			p++;

	*target = p;
	return -1;
}

/*
	@설명: 부호없는 32비트 8진수를 가져옮
	@ptr [IN] : 분석중인 문자열의 포인터
	-
	@return : 추출된 숫자
*/
static u32 RgpMakeOct(const char *ptr)
{
	const char *_Ptr = ptr;
	int g = 0;
	for (; *_Ptr != 'o'; _Ptr++)
		g *= 8, g += *_Ptr & 0xf;
	return g;
}

/*
	@설명: 부호없는 32비트 16진수를 가져옮
	@ptr [IN] : 분석중인 문자열의 포인터
	-
	@return : 추출된 숫자
*/
static u32 RgpMakeHex(const char *ptr)
{
	const char *_Ptr = ptr;
	int g = 0;
	for (; *_Ptr != 'h'; _Ptr++)
		g *= 16, g += ('0' <= *_Ptr  && *_Ptr  <= '9') ? (*_Ptr & 0xf) : (_to_lower(*_Ptr)  - 'a' + 0xa);
	return g;
}

/*
	@설명: 부호없는 32비트 10진수를 가져옮
	@ptr [IN] : 분석중인 문자열의 포인터
	-
	@return : 추출된 숫자
*/
static int RgpMakeDec(const char *ptr)
{
	const char *_Ptr = ptr;
	int g = 0;
	for (; '0' <= *_Ptr && *_Ptr <= '9'; _Ptr++)
		 g *= 10, g += *_Ptr & 0xf;
	return g;
}