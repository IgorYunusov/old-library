/*************************************************************************
 *
 * FILE NAME : rasm.c
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

#ifndef _REGISTER_
#define _REGISTER_

// Register

//
//	0부터 시작하지 않은 이유는 이것의 상위버전의 어셈블러에서
//	get_register함수와 같이 쓰일 알고리즘 때문입니다
//
#define AX				1
#define CX				2
#define DX				3
#define BX				4
#define SP				5
#define BP				6
#define SI				7
#define DI				8
#define AL				9
#define CL				10
#define DL				11
#define BL				12
#define AH				13
#define CH				14
#define DH				15
#define BH				16

#define EAX				1
#define ECX				2
#define EDC				3
#define EBX				4
#define ESP				5
#define EBP				6
#define ESI				7
#define EDI				8

#define RAX				1
#define RCX				2
#define RDC				3
#define RBX				4
#define RSP				5
#define RBP				6
#define RSI				7
#define RDI				8

#define EIP				256
#define EFLAGS			257
#define CS				258
#define DS				259
#define ES				260
#define FS				261
#define GS				262

typedef struct _register_types{
	int bit;
	int first, second, third, sign;
	int type;
}	REGISTER, *PREGISTER;

#define REGISTER_TYPE_NORMAL				1
#define REGISTER_TYPE_REFERENCE				2
#define REGISTER_TYPE_SIGNLE_REFERENCE		3
#define REGISTER_TYPE_NUMBERIC				4

#define REGISTER_REFERENCE_SIGN_PLUS			1	// 001
#define REGISTER_REFERENCE_SIGN_MINUS			2	// 010
#define REGISTER_REFERENCE_SIGN_MULTIPLE		3	// 011
#define REGISTER_REFERENCE_SIGN_MULTIPLE_PLUS	4	// 100
#define REGISTER_REFERENCE_SIGN_MULTIPLE_MINUS	5	// 101

#define REGISTER_DELIMITER						'$'

PREGISTER get_register(const char *str);
int get_oct(const char *_t);
int get_integer(const char *_t);
int get_hex(const char *_t);

#endif