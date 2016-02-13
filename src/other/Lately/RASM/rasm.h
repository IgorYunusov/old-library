/*************************************************************************
 *
 * FILE NAME : rasm.h - RASM Module
 *
 * ROLLRAT SOFTWARE IA-32 SHELL ASSEMBLER(RASM)
 *
 *
 * LANGUAGE : Macro Assembly, C++
 * VERSION  : Microsoft Macro Assembler v12.00.30501.0
 *            ISO/C++ 11-Microsoft C/C++ Optimizer Compiler 18.00.0501
 * CREATION : 2014.10.12
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com, rollrat.software@gmail.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#ifndef _RASM_
#define _RASM_

#include "util.hh"
#include "debug.h"

typedef struct _argument_option_ {

	bool error;			// argument argc error. no option
	bool standard;		// /Sd : standard assembly
	bool inc;			// /Ic : other file
	bool bigendian;		// /Be : if false is small endian
	bool report;		// /Re : report out
	char *address;		// asm address
	char *save;			// machine code save
	std::string serror;	// error string

	/////////////////////////////////////////////////////////

	std::vector<char *> otherfile;
}	OPTION, *POPTION;

// RASM Macro
#define MakeModRM(mod, reg, rm)		((rm & 7) | ((reg & 7) << 3) | ((mod & 3) << 6))

// Register
#define AX				1
#define CX				2
#define DC				3
#define BX				4
#define SP				5
#define BP				6
#define SI				7
#define DI				8

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

typedef enum class eg1{
	add,
	or,
	adc,
	sbb,
	and,
	sub,
	xor,
	cmp,
}	Extension_Group_1;

typedef enum class eg2{
	rol,
	ror,
	rcl,
	rcr,
	shl,
	shr,
	_0,
	ar,
}	Extension_Group_2;

typedef enum class eg3{
	test,
	_0,
	not,
	neg,
	mul,
	imul,
	div,
	idiv,
}	Extension_Group_3;

typedef enum class eg4{
	inc,
	dec,
}	Extension_Group_4;

typedef enum class eg5{
	inc,
	dec,
	near_call,
	far_call,
	near_jmp,
	far_jmp,
	push,
}	Extension_Group_5;

typedef enum class ty{
	byte,
	word,
	dword,
	pbyte,
	pword,
	pdword,
	string,
	array,
	pstring,
	parray,
	custom,
}	VariableType;

#define OPCODE_0		0
#define OPCODE_1		1
#define OPCODE_2		2
#define OPCODE_3		3

struct _tmx {
	const char * opname;
	WORD first;
	WORD second;
	WORD eax;
	WORD mod, reg, rm;
} bytesetal[0xff] = 
	{
		{"add", 0x83, 0x81, 0x05, 3, (int)Extension_Group_1::add, 0},
		{"sub", 0x83, 0x81, 0x2d, 3, (int)Extension_Group_1::sub, 0},
		{"and", 0x83, 0x81, 0x25, 3, (int)Extension_Group_1::and, 0},
		{"or",  0x83, 0x81, 0x0d, 3, (int)Extension_Group_1::or,  0},
		{"xor", 0x83, 0x81, 0x35, 3, (int)Extension_Group_1::xor, 0},
		{"cmp", 0x83, 0x81, 0x3d, 3, (int)Extension_Group_1::cmp, 0},
	};

std::vector<BYTE> rasm_jcc(std::vector<std::string> line, OPTION option);

//std::vector<BYTE> assemble_code(std::string code, OPTION option)
//{
//	std::vector<BYTE> byte;
//	std::vector<std::string> arrStr = split(trim(remove_annotation(code)), " ");
//
//	return byte;
//}

std::vector<BYTE> assemble_code(std::string code, OPTION option, bool endian = false)
{
	std::vector<BYTE> byte;
	std::vector<std::string> arrStr = split(trim(remove_annotation(code)), " ");
	int reg1=0, reg2=0;
	if(arrStr.size() >= 2)
		if (reg1 = get_register(arrStr[1].c_str()))
			;
	if(arrStr.size() == 3)
		if (reg2 = get_register(arrStr[2].c_str()))
			;
	if(reg1 != 255 && reg2 != 255) 
	{
		if(reg1 && !reg2) // <operator> <register> <operand>
		{
			int g=0;
			if(arrStr[0] == "add")
				if ((g=get_integer(arrStr[2].c_str())) < 128)
					byte.push_back(0x83),
					byte.push_back(MakeModRM(3,(int)Extension_Group_1::add,reg1-1)),
					pushb(g,byte);
				else if(reg1 == EAX)
					byte.push_back(0x05),
					pushdw(g,byte,endian);
				else
					byte.push_back(0x81),
					byte.push_back(MakeModRM(3,(int)Extension_Group_1::add,reg1-1)),
					pushdw(g,byte,endian);
			else if(arrStr[0] == "sub")
				if ((g=get_integer(arrStr[2].c_str())) < 128)
					byte.push_back(0x83),
					byte.push_back(MakeModRM(3,(int)Extension_Group_1::sub,reg1-1)),
					pushb(g,byte);
				else if(reg1 == EAX)
					byte.push_back(0x2d),
					pushdw(g,byte,endian);
				else
					byte.push_back(0x81),
					byte.push_back(MakeModRM(3,(int)Extension_Group_1::sub,reg1-1)),
					pushdw(g,byte,endian);
			else if(arrStr[0] == "imul")
				if ((g=get_integer(arrStr[2].c_str())) < 128)
					byte.push_back(0x6B),
					byte.push_back(MakeModRM(3,0,reg1-1)),
					pushb(g,byte);
				else
					byte.push_back(0x69),
					byte.push_back(MakeModRM(3,0,0)+0x9*(reg1-1)),
					pushdw(g,byte,endian);
			else if(arrStr[0] == "div")
				;
			else if(arrStr[0] == "and")
				if ((g=get_integer(arrStr[2].c_str())) < 128)
					byte.push_back(0x83),
					byte.push_back(MakeModRM(3,(int)Extension_Group_1::and,reg1-1)),
					pushb(g,byte);
				else if(reg1 == EAX)
					byte.push_back(0x25),
					pushdw(g,byte,endian);
				else
					byte.push_back(0x81),
					byte.push_back(MakeModRM(3,(int)Extension_Group_1::and,reg1-1)),
					pushdw(g,byte,endian);
			else if(arrStr[0] == "or")
				if ((g=get_integer(arrStr[2].c_str())) < 128)
					byte.push_back(0x83),
					byte.push_back(MakeModRM(3,(int)Extension_Group_1::or,reg1-1)),
					pushb(g,byte);
				else if(reg1 == EAX)
					byte.push_back(0x0d),
					pushdw(g,byte,endian);
				else
					byte.push_back(0x81),
					byte.push_back(MakeModRM(3,(int)Extension_Group_1::or,reg1-1)),
					pushdw(g,byte,endian);
			else if(arrStr[0] == "xor")
				if ((g=get_integer(arrStr[2].c_str())) < 128)
					byte.push_back(0x83),
					byte.push_back(MakeModRM(3,(int)Extension_Group_1::xor,reg1-1)),
					pushb(g,byte);
				else if(reg1 == EAX)
					byte.push_back(0x35),
					pushdw(g,byte,endian);
				else
					byte.push_back(0x81),
					byte.push_back(MakeModRM(3,(int)Extension_Group_1::xor,reg1-1)),
					pushdw(g,byte,endian);
			else if(arrStr[0] == "cmp")
				if ((g=get_integer(arrStr[2].c_str())) < 128)
					byte.push_back(0x83),
					byte.push_back(MakeModRM(3,(int)Extension_Group_1::cmp,reg1-1)),
					pushb(g,byte);
				else if(reg1 == EAX)
					byte.push_back(0x3d),
					pushdw(g,byte,endian);
				else
					byte.push_back(0x81),
					byte.push_back(MakeModRM(3,(int)Extension_Group_1::cmp,reg1-1)),
					pushdw(g,byte,endian);
			else if(arrStr[0] == "inc")
				byte.push_back(0x40+reg1);
			else if(arrStr[0] == "dec")
				byte.push_back(0x48+reg1);
			else if(arrStr[0] == "mov")
				byte.push_back(0xB8+reg1),
				pushdw(get_integer(arrStr[2].c_str()),byte,endian);
			else if(arrStr[0] == "push")
				byte.push_back(0x50+reg1);
			else if(arrStr[0] == "pop")
				byte.push_back(0x58+reg1);
			else if(arrStr[0] == "jmp")
				byte.push_back(0xff),
				byte.push_back(MakeModRM(3,(int)Extension_Group_5::near_jmp,reg1));
			}
		else if(!reg1 && !reg2) // <operator> ... [<operand> ... [<operand>]]
			{
			int g=0;
			if(arrStr[0] == "push")
				byte.push_back(0x68),
				pushdw(get_integer(arrStr[1].c_str()),byte,endian);
			else if(arrStr[0] == "pusha")
				byte.push_back(0x60);
			else if(arrStr[0] == "popa")
				byte.push_back(0x61);/*
			else if(arrStr[0] == "ret")
				byte.push_back(0xc3);*/
			else if(arrStr[0] == "ret")
				byte.push_back(0xc2),
				pushw(get_integer(arrStr[1].c_str()),byte,endian);
			else if(arrStr[0] == "nop")
				byte.push_back(0x90);
			}
		else if(reg1 && reg2) // <operator> <register> <register>
			{
			if (arrStr[0] == "add")
				byte.push_back(0x03),
				byte.push_back(MakeModRM(3,reg1-1,reg2-1));
			else if (arrStr[0] == "sub")
				byte.push_back(0x2b),
				byte.push_back(MakeModRM(3,reg1-1,reg2-1));
			else if (arrStr[0] == "imul")
				byte.push_back(0x0f),
				byte.push_back(0xaf),
				byte.push_back(MakeModRM(3,reg1-1,reg2-1));
			else if (arrStr[0] == "and")
				byte.push_back(0x23),
				byte.push_back(MakeModRM(3,reg1-1,reg2-1));
			else if (arrStr[0] == "or")
				byte.push_back(0x0b),
				byte.push_back(MakeModRM(3,reg1-1,reg2-1));
			else if (arrStr[0] == "xor")
				byte.push_back(0x33),
				byte.push_back(MakeModRM(3,reg1-1,reg2-1));
			else if (arrStr[0] == "cmp")
				byte.push_back(0x3b),
				byte.push_back(MakeModRM(3,reg1-1,reg2-1));
			else if (arrStr[0] == "mov")
				byte.push_back(0x8b),
				byte.push_back(MakeModRM(3,reg1-1,reg2-1));
			}
	} else if (reg1 == 255) {
		BYTE ebp_num;
		const char *t = arrStr[1].c_str();
		for (; *t != '-' && *t != '+'; t++)
			;
		bool x = false;
		if (*t++ == '-')
			ebp_num = (~(BYTE)((*(t)&0xf) * 10 + *(t+1)&0xf))+2;
		else
			ebp_num = (*(t)&0xf) * 10 + *(t+1)&0xf;
		if(reg2)
			if (arrStr[0] == "mov")
				byte.push_back(0x89),
				byte.push_back(MakeModRM(1,reg2-1,EBP-1)),
				pushb(ebp_num, byte);

	}	else if (reg2 == 255) {
		BYTE ebp_num;
		const char *t = arrStr[2].c_str();
		for (; *t != '-' && *t != '+'; t++)
			;
		bool x = false;
		ebp_num = get_integer(t+1);
		if (*t == '-')
			ebp_num = (~(BYTE)(ebp_num))+1;
		if(reg1) {
			if (arrStr[0] == "add")
				byte.push_back(0x03),
				byte.push_back(MakeModRM(1,reg1-1,EBP-1)),
				pushb(ebp_num, byte);
			else if (arrStr[0] == "sub")
				byte.push_back(0x2b),
				byte.push_back(MakeModRM(1,reg1-1,EBP-1)),
				pushb(ebp_num, byte);
			else if (arrStr[0] == "imul")
				byte.push_back(0x0f),
				byte.push_back(0xaf),
				byte.push_back(MakeModRM(1,reg1-1,EBP-1)),
				pushb(ebp_num, byte);
			else if (arrStr[0] == "and")
				byte.push_back(0x23),
				byte.push_back(MakeModRM(1,reg1-1,EBP-1)),
				pushb(ebp_num, byte);
			else if (arrStr[0] == "or")
				byte.push_back(0x0b),
				byte.push_back(MakeModRM(1,reg1-1,EBP-1)),
				pushb(ebp_num, byte);
			else if (arrStr[0] == "xor")
				byte.push_back(0x33),
				byte.push_back(MakeModRM(1,reg1-1,EBP-1)),
				pushb(ebp_num, byte);
			else if (arrStr[0] == "cmp")
				byte.push_back(0x3b),
				byte.push_back(MakeModRM(1,reg1-1,EBP-1)),
				pushb(ebp_num, byte);
			else if (arrStr[0] == "mov")
				byte.push_back(0x8B),
				byte.push_back(MakeModRM(1,reg1-1,EBP-1)),
				pushb(ebp_num, byte);
		}
	}

	return byte;
}

std::vector<BYTE> assemble_code(std::vector<std::string> code, OPTION option)
{
	std::vector<BYTE> byte;

	for(auto& ocde : code)
	{
		for (auto& ret : assemble_code(ocde, option))
			byte.push_back(ret);
	}

	return byte;
}

#endif