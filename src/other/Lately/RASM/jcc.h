/*************************************************************************
 *
 * FILE NAME : jcc.h - Jump if Condition is Met
 *
 * ROLLRAT SOFTWARE IA-32 SHELL ASSEMBLER(RASM)
 *
 *
 * LANGUAGE : Macro Assembly, C++
 * VERSION  : Microsoft Macro Assembler v12.00.30501.0
 *            ISO/C++ 11-Microsoft C/C++ Optimizer Compiler 18.00.0501
 * CREATION : 2014.10.17
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com, rollrat.software@gmail.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#ifndef _JCC_
#define _JCC_

#include "rasm.h"

// Condition : Jcc <numberic>

/*struct _qw {
	WORD op;
	DWORD addr;
}*/std::vector<BYTE> rasm_jcc(std::vector<std::string> line, OPTION option)
{
	std::vector<BYTE> byte;
	//_qw byte;
	if (line[0][0] != 'j')
	{
		return byte;
	}
	int g=0;
	if (line[0] == "jo")
		if ((g = get_integer(line[1].c_str())) < 128)
			byte.push_back(0x70),
			pushb(g, byte);
		else
			byte.push_back(0x0f),
			byte.push_back(0x80),
			pushdw(g, byte, option.bigendian);
	else if (line[0] == "jno")
		if ((g = get_integer(line[1].c_str())) < 128)
			byte.push_back(0x71),
			pushb(g, byte);
		else
			byte.push_back(0x0f),
			byte.push_back(0x81),
			pushdw(g, byte, option.bigendian);
	else if (line[0] == "jb")
		if ((g = get_integer(line[1].c_str())) < 128)
			byte.push_back(0x72),
			pushb(g, byte);
		else
			byte.push_back(0x0f),
			byte.push_back(0x82),
			pushdw(g, byte, option.bigendian);
	else if (line[0] == "jnb")
		if ((g = get_integer(line[1].c_str())) < 128)
			byte.push_back(0x73),
			pushb(g, byte);
		else
			byte.push_back(0x0f),
			byte.push_back(0x83),
			pushdw(g, byte, option.bigendian);
	else if (line[0] == "jz")
		if ((g = get_integer(line[1].c_str())) < 128)
			byte.push_back(0x74),
			pushb(g, byte);
		else
			byte.push_back(0x0f),
			byte.push_back(0x84),
			pushdw(g, byte, option.bigendian);
	else if (line[0] == "jnz")
		if ((g = get_integer(line[1].c_str())) < 128)
			byte.push_back(0x75),
			pushb(g, byte);
		else
			byte.push_back(0x0f),
			byte.push_back(0x85),
			pushdw(g, byte, option.bigendian);
	else if (line[0] == "jbe")
		if ((g = get_integer(line[1].c_str())) < 128)
			byte.push_back(0x76),
			pushb(g, byte);
		else
			byte.push_back(0x0f),
			byte.push_back(0x86),
			pushdw(g, byte, option.bigendian);
	else if (line[0] == "ja")
		if ((g = get_integer(line[1].c_str())) < 128)
			byte.push_back(0x77),
			pushb(g, byte);
		else
			byte.push_back(0x0f),
			byte.push_back(0x87),
			pushdw(g, byte, option.bigendian);
	else if (line[0] == "js")
		if ((g = get_integer(line[1].c_str())) < 128)
			byte.push_back(0x78),
			pushb(g, byte);
		else
			byte.push_back(0x0f),
			byte.push_back(0x88),
			pushdw(g, byte, option.bigendian);
	else if (line[0] == "jns")
		if ((g = get_integer(line[1].c_str())) < 128)
			byte.push_back(0x79),
			pushb(g, byte);
		else
			byte.push_back(0x0f),
			byte.push_back(0x89),
			pushdw(g, byte, option.bigendian);
	else if (line[0] == "jp")
		if ((g = get_integer(line[1].c_str())) < 128)
			byte.push_back(0x7a),
			pushb(g, byte);
		else
			byte.push_back(0x0f),
			byte.push_back(0x8a),
			pushdw(g, byte, option.bigendian);
	else if (line[0] == "jnp")
		if ((g = get_integer(line[1].c_str())) < 128)
			byte.push_back(0x7b),
			pushb(g, byte);
		else
			byte.push_back(0x0f),
			byte.push_back(0x8b),
			pushdw(g, byte, option.bigendian);
	else if (line[0] == "jl")
		if ((g = get_integer(line[1].c_str())) < 128)
			byte.push_back(0x7c),
			pushb(g, byte);
		else
			byte.push_back(0x0f),
			byte.push_back(0x8c),
			pushdw(g, byte, option.bigendian);
	else if (line[0] == "jnl")
		if ((g = get_integer(line[1].c_str())) < 128)
			byte.push_back(0x7d),
			pushb(g, byte);
		else
			byte.push_back(0x0f),
			byte.push_back(0x8d),
			pushdw(g, byte, option.bigendian);
	else if (line[0] == "jle")
		if ((g = get_integer(line[1].c_str())) < 128)
			byte.push_back(0x7e),
			pushb(g, byte);
		else
			byte.push_back(0x0f),
			byte.push_back(0x8e),
			pushdw(g, byte, option.bigendian);
	else if (line[0] == "jnle")
		if ((g = get_integer(line[1].c_str())) < 128)
			byte.push_back(0x7f),
			pushb(g, byte);
		else
			byte.push_back(0x0f),
			byte.push_back(0x8f),
			pushdw(g, byte, option.bigendian);
	else if (line[0] == "jmp")
		if ((g = get_integer(line[1].c_str())) < 128)
			byte.push_back(0xeb),
			pushb(g, byte);
		else
			byte.push_back(0xe9),
			pushdw(g, byte, option.bigendian);
	return byte;
}

#endif