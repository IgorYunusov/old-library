/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   reg.h - [Private]

Project:

   Robust Assembler (RASM)

------
   AUTHOR: HyunJun Jeong  2015-01-05

***************************************************************************/

#ifndef _REGISTER_
#define _REGISTER_

#include "type.h"

//
//	Pick - AX
//
#define AX				0
#define CX				1
#define DX				2
#define BX				3
#define SP				4
#define BP				5
#define SI				6
#define DI				7


//
//	Pick - AL
//
#define AL				8
#define CL				9
#define DL				10
#define BL				11
#define AH				12
#define CH				13
#define DH				14
#define BH				15


//
//	Pick - CS
//
#define CS				16
#define DS				17
#define ES				18
#define	FS				19
#define GS				20
#define SS				21

typedef struct _register_types{

	//
	//	0, 16, 32 �� �� ���� ���� ������
	//
	int bit;


	//
	//	��������, ����, �� SIB Ÿ�� ����
	//
	int reg_type;
	u32 num_type;
	int num_sign;
	int sib_type;


	//
	//	��������(���۷���) ������ �⺻ �����̴�
	//	�ذ� ���� ��ĸ� �м��� �����ϴ�
	//	<reg>, [<reg>], [<reg>+a], [<reg>*a], [<reg>*a+b], <num>
	//
	//	�� �ĵ��� �м��� �� ����
	//	[a*<reg>], [a+<reg>], [a+<reg>*b], [a+b*<reg>], [a*<reg>+b]
	//
	int type;

}	REGISTER, *PREGISTER;


#define REGISTER_TYPE_REFERENCE					1
#define REGISTER_TYPE_OPERATOR					2
#define REGISTER_TYPE_MULTIPLE					4
#define REGISTER_TYPE_SEGMENT					(REGISTER_TYPE_REFERENCE | 8)

#define REGISTER_DELIMITER						'$'

PREGISTER ParseRegister(const char *str);

#endif