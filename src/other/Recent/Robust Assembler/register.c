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
	@get_register : ���۷��忡 �� �� �ִ� �κ��� �����ϰ�
	                 PREGISTER�� �̿��Ͽ� ������

	@str          : �м����� ���ڿ��� ������
*/
PREGISTER get_register(const char *str)
{
	const char *ptr = str;
	PREGISTER reg = ((PREGISTER) malloc (sizeof(REGISTER)));
	int thirdc;
	
	// �߿� : �� �Լ��� ������ ���� ������ ó������ ���մϴ�
	//	[<num2> + <reg> * <num1>]
	//	[<num1> * <reg> + <num2>]
	//	[<num2>	+ <num1> * <reg>]
	//	[<num1> * <reg>]
	//	[<num1> + <reg>]

	//
	//	[<reg> * <num1> + <num2>] ������ ��� �� �÷��״� Ȱ��ȭ��
	//
	thirdc = FALSE;

	//
	//	�������� ������[$]�� Ȯ���ϰ� ������ �������͸�,
	//	������ ���ڿ� �� ���� ���̶� ��ġ�Ǵ��� Ȯ����.
	//
	if (*ptr++ != REGISTER_DELIMITER) {
		ptr--;
		if(_isdigit(*ptr) || _isxdigit(*ptr) || *ptr == '-' || *ptr == '+') {
			const char * t = ptr;
			int get;

			reg->type = REGISTER_TYPE_NUMBERIC;

			//
			//	�� ���� ���ڸ� Ȯ���ϱ� ���� �����͸� �ű�
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
	//	rxx, exx�� ������ ���۷��带 �м���
	//	����Ʈ ���� 16bit�� ���۷�����
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
	//	exx, rxx���� e, r�� �ѱ� �������͸� �м���
	//	������ ��� 16bit�� ����
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
	//	�Ϲ� �������� �����̸� �� �̻� �м��� �ʿ������
	//	�׳� ��ȯ��
	//
	if(reg->type == REGISTER_TYPE_NORMAL)
		return reg;

	//
	//	�м��ߴ� ���������� �� ������ 2�̹Ƿ�
	//
	ptr += 2;
	_util_skip_function(&ptr, _isspace);

	//
	//	�Ϲ� ������ �������� ����
	//
	if (*ptr == ']') {
		reg->type = REGISTER_TYPE_SIGNLE_REFERENCE;
		return reg;
	}

	//
	//	']'�� ������ ������ ���� �� �ִ� ��������
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
	//	16������ ���ڿ��� ��� ffh��, a2h���� ���ڰ� ���� �������� �� �ִµ�
	//	�� ��쿣 �м��� ���� ������ ����Ѵ�. �׷� ���� 16������ ��쿣 
	//	0ffh, 0a2h�� ���� ��Ÿ����� �Ѵ�.
	//
	if('0' <= *ptr && *ptr <= '9')
	{
		const char * t = ptr;
		int get;
		for (; *t != ']' && *t; t++)
			if (*t == '-' || *t == '+') {

				//
				//	[<reg> * <num1> + <num2>] �������� Ȯ����
				//
				thirdc = TRUE;
				break;
			}

		//
		//	*t == NULL�̸� ���� ��ȣ�� ������ �ʾ����Ƿ� �翬�� ����
		//
		if (!*t--)
			return NULL;

		//
		//	']'�� ������ ���� ������ ���ԵǾ����� �� �����Ƿ�
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
			//	�� �ڵ屸���� ��ⱸ���� ������
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
		//	���ڰ� ������ ���� ��쿣 ������ ����Ѵ�.
		//��������
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