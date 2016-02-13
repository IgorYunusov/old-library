/*************************************************************************
 *
 * FILE NAME : test.h - Mini Test Assembler
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

#ifndef _TEST_
#define _TEST_

#include "rasm.h"
           
std::vector<BYTE> simple_line_assembly(std::string line, bool endian = false)
{
	std::vector<BYTE> byte;
	std::vector<std::string> arrStr = split(trim(remove_annotation(line)), " ");
	int reg1=0, reg2=0;
	if(arrStr.size() >= 2)
		if (reg1 = get_register(arrStr[1].c_str()))
			;
	if(arrStr.size() == 3)
		if (reg2 = get_register(arrStr[2].c_str()))
			;
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
			byte.push_back(0x61);
		else if(arrStr[0] == "ret")
			byte.push_back(0xc3);
		else if(arrStr[0] == "nop")
			byte.push_back(0x90);
		else if(arrStr[0] == "jo")
			if ((g=get_integer(arrStr[2].c_str())) < 128)
				byte.push_back(0x70),
				pushb(g,byte);
			else
				byte.push_back(0x0f),
				byte.push_back(0x80),
				pushdw(g,byte,endian);
		else if(arrStr[0] == "jno")
			if ((g=get_integer(arrStr[2].c_str())) < 128)
				byte.push_back(0x71),
				pushb(g,byte);
			else
				byte.push_back(0x0f),
				byte.push_back(0x81),
				pushdw(g,byte,endian);
		else if(arrStr[0] == "jb")
			if ((g=get_integer(arrStr[2].c_str())) < 128)
				byte.push_back(0x72),
				pushb(g,byte);
			else
				byte.push_back(0x0f),
				byte.push_back(0x82),
				pushdw(g,byte,endian);
		else if(arrStr[0] == "jnb")
			if ((g=get_integer(arrStr[2].c_str())) < 128)
				byte.push_back(0x73),
				pushb(g,byte);
			else
				byte.push_back(0x0f),
				byte.push_back(0x83),
				pushdw(g,byte,endian);
		else if(arrStr[0] == "jz")
			if ((g=get_integer(arrStr[2].c_str())) < 128)
				byte.push_back(0x74),
				pushb(g,byte);
			else
				byte.push_back(0x0f),
				byte.push_back(0x84),
				pushdw(g,byte,endian);
		else if(arrStr[0] == "jnz")
			if ((g=get_integer(arrStr[2].c_str())) < 128)
				byte.push_back(0x75),
				pushb(g,byte);
			else
				byte.push_back(0x0f),
				byte.push_back(0x85),
				pushdw(g,byte,endian);
		else if(arrStr[0] == "jbe")
			if ((g=get_integer(arrStr[2].c_str())) < 128)
				byte.push_back(0x76),
				pushb(g,byte);
			else
				byte.push_back(0x0f),
				byte.push_back(0x86),
				pushdw(g,byte,endian);
		else if(arrStr[0] == "ja")
			if ((g=get_integer(arrStr[2].c_str())) < 128)
				byte.push_back(0x77),
				pushb(g,byte);
			else
				byte.push_back(0x0f),
				byte.push_back(0x87),
				pushdw(g,byte,endian);
		else if(arrStr[0] == "js")
			if ((g=get_integer(arrStr[2].c_str())) < 128)
				byte.push_back(0x78),
				pushb(g,byte);
			else
				byte.push_back(0x0f),
				byte.push_back(0x88),
				pushdw(g,byte,endian);
		else if(arrStr[0] == "jns")
			if ((g=get_integer(arrStr[2].c_str())) < 128)
				byte.push_back(0x79),
				pushb(g,byte);
			else
				byte.push_back(0x0f),
				byte.push_back(0x89),
				pushdw(g,byte,endian);
		else if(arrStr[0] == "jp")
			if ((g=get_integer(arrStr[2].c_str())) < 128)
				byte.push_back(0x7a),
				pushb(g,byte);
			else
				byte.push_back(0x0f),
				byte.push_back(0x8a),
				pushdw(g,byte,endian);
		else if(arrStr[0] == "jnp")
			if ((g=get_integer(arrStr[2].c_str())) < 128)
				byte.push_back(0x7b),
				pushb(g,byte);
			else
				byte.push_back(0x0f),
				byte.push_back(0x8b),
				pushdw(g,byte,endian);
		else if(arrStr[0] == "jl")
			if ((g=get_integer(arrStr[2].c_str())) < 128)
				byte.push_back(0x7c),
				pushb(g,byte);
			else
				byte.push_back(0x0f),
				byte.push_back(0x8c),
				pushdw(g,byte,endian);
		else if(arrStr[0] == "jnl")
			if ((g=get_integer(arrStr[2].c_str())) < 128)
				byte.push_back(0x7d),
				pushb(g,byte);
			else
				byte.push_back(0x0f),
				byte.push_back(0x8d),
				pushdw(g,byte,endian);
		else if(arrStr[0] == "jle")
			if ((g=get_integer(arrStr[2].c_str())) < 128)
				byte.push_back(0x7e),
				pushb(g,byte);
			else
				byte.push_back(0x0f),
				byte.push_back(0x8e),
				pushdw(g,byte,endian);
		else if(arrStr[0] == "jnle")
			if ((g=get_integer(arrStr[2].c_str())) < 128)
				byte.push_back(0x7f),
				pushb(g,byte);
			else
				byte.push_back(0x0f),
				byte.push_back(0x8f),
				pushdw(g,byte,endian);
		else if(arrStr[0] == "jmp")
			if ((g=get_integer(arrStr[2].c_str())) < 128)
				byte.push_back(0xeb),
				pushb(g,byte);
			else
				byte.push_back(0xe9),
				pushdw(g,byte,endian);
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
		}
	return byte;
}

#endif