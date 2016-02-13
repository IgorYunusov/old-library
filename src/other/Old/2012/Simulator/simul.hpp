/****************************************************************
 *																*
 *																*
 *			ROLLRAT AUTO PERSONA VERBOTER LIBROFEX				*
 *																*
 *																*
 *		COPYRIGHT (c) rollrat. 2013. ALL RIGHTS RESERVED.		*
 *																*
 *																*
 ****************************************************************/

#ifndef _SIMUL
#define _SIMUL

typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef unsigned long       DWORD;
typedef unsigned long long	QWORD;
typedef unsigned int		TYPE;

typedef struct _ATS_COMMON_OPSOURCE {
	DWORD		OpCode;
	DWORD		Operand;
	DWORD		Operator;
}	COMMON_OPSOURCE, *PTR_COMMON_OPSOURCE;

typedef struct _ATS_COMMON_OPCODE {
	DWORD		VirtualAddress;
	COMMON_OPSOURCE	OpSource;
	DWORD		OpCodePrefix;
	TYPE		OperandReg;
	TYPE		OperatorReg;
}	COMMON_OPCODE, *PTR_COMMON_OPCODE;


#endif