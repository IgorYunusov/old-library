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
	@����: ���۷��忡 �� �� �ִ� �κ��� ����
	@str [IN] : �м����� ���ڿ��� ������
	-
	@return: �������� ������ ������
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
	//	�������� �����ڰ� �ƴ� ��� ���ڸ� Ȯ����
	//
	if (*ptr != REGISTER_DELIMITER) {
		no_check_end = TRUE;
		goto SYMBOL;
	}

	//
	//	������ ������������ Ȯ��
	//
	if (*++ptr == '[') {
		reg->bit = 32;
		reg->type |= REGISTER_TYPE_REFERENCE;
		RgpSkipFunc(&ptr, _isspace); // ��������
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
		//	�������ͺ��� ���ڰ� ���� ���� ���� / �� ���������� ������ �����̹Ƿ� ����
		//
		return NULL;

	} else {

		//
		//	������ �������Ϳ� 16bit �������͸� �������� ���
		//
		if (reg->type & REGISTER_TYPE_REFERENCE)
			return NULL;

		reg->bit = 16;
	}

	//
	//	���������� ������ ����
	//
	reg->reg_type = _Hash_Registers[_to_lower(*ptr++)][_to_lower(*ptr++)];
	
	RgpSkipFunc(&ptr, _isspace); // ��������

	//
	//	�Ϲ� �������� �����̰ų� �ܼ������������� �����̸� 
	//	�� �̻� �м��� �ʿ䰡 ������ �׳� ��ȯ
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
		//	���ڸ� ó���� ���
		//
	else if (no_check_end == TRUE) {
		reg->type |= REGISTER_TYPE_OPERATOR;
		ch = reg->num_sign = '+';
	} else

		//
		//	���� ó�� ����
		//
		return NULL;
	

	/* ������ �ǳʶٱ� */
	if(no_check_end == FALSE)
		ch = *ptr++;
	RgpSkipFunc(&ptr, _isspace); // ��������

	//
	//	+, -, * ����ó��
	//
	if (_isnumeric(*ptr)) {
		const char *p = ptr;

		//
		//	���ڿ� ��ġ�Ǵ� ��� ���� �������� ���� h, o�� ���Ͽ� 
		//	16������ 8������ �������Ѵ�.
		//
		RgpSkipFunc(&p, _isxdigit);

		//
		//	�ش� ������ �´� ���ڸ� ������ ������ ó�� ������ �°� ����
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
		//	��ȣ �ǳʶٱ�
		//
		if (*p == 'o' || *p == 'h')
			ptr = p + 1;
		else
			ptr = p;

	} else {

		//
		//	���ڰ� �ƴϸ� �����̹Ƿ� ������ �����Ѵ�
		//

	}

	RgpSkipFunc(&ptr, _isspace); // ��������

	//
	//	������ ������ �ʾҴٸ� ���� ������ ���� ���������Ƿ�
	//
	if (*ptr != ']' && !no_check_end)
		goto SYMBOL;

	return reg;
}

/*
	@����: �Էµ� �Լ��� False�� ���ö����� �����͸� ������Ŵ
	@target [OUT] : �м����� ���ڿ��� ������
	@func   [IN]  : �Է��� �Լ��� ������
	-
	@return : ������Ų �������� ũ��
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
	@����: �Էµ� �Լ��� True�� ���ö����� �����͸� ������Ŵ
	@target [OUT] : �м����� ���ڿ��� ������
	@func   [IN]  : �Է��� �Լ��� ������
	-
	@return : ������Ų �������� ũ��
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
	@����: ��ȣ���� 32��Ʈ 8������ ������
	@ptr [IN] : �м����� ���ڿ��� ������
	-
	@return : ����� ����
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
	@����: ��ȣ���� 32��Ʈ 16������ ������
	@ptr [IN] : �м����� ���ڿ��� ������
	-
	@return : ����� ����
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
	@����: ��ȣ���� 32��Ʈ 10������ ������
	@ptr [IN] : �м����� ���ڿ��� ������
	-
	@return : ����� ����
*/
static int RgpMakeDec(const char *ptr)
{
	const char *_Ptr = ptr;
	int g = 0;
	for (; '0' <= *_Ptr && *_Ptr <= '9'; _Ptr++)
		 g *= 10, g += *_Ptr & 0xf;
	return g;
}