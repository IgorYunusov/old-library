/*************************************************************************
 *
 *                    TETO. BYTE ASSEMBLER 0.1201.1.1.0
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _TASM_DEF_
#define _TASM_DEF_

#define ASSEMBLER_CODE_AND		0x00
#define ASSEMBLER_CODE_OR		0x01
//#define ASSEMBLER_CODE_AND		0x02

#define FLAG_REG				0x01
#define FLAG_ADDR				0x02
#define FLAG_DATA				0x03


// 32bit System
#define E_X		0		// non-selected
#define EAX		1
#define ECX		2
#define EDX		3
#define EBX		4
#define ESP		5
#define EBP		6
#define ESI		7
#define EDI		8

typedef struct __data {
	char * command;
	int op1;
	int op2;
	int op3;
	int op4;
}	_DATA, *_P_DATA;



#endif