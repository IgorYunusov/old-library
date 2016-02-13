/*************************************************************************
 *
 *					  ROLLRAT SOFTWARE LIBRARY
 *						IA-32 SIMPLE ASSEMBLER
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

// VERSION 0.8

#ifndef _SASM_
#define _SASM_

#include <Windows.h>
#include <string>
#include <algorithm>
#include <functional> 
#include <cctype>
#include <vector>
#include <hash_map>
#include "serve_method.h"

#define MakeModRM(mod, reg, rm)		((rm & 7) | ((reg & 7) << 3) | ((mod & 3) << 6))

std::string& ltrim(std::string& str)
	{
	str.erase(str.begin(), std::find_if(str.begin(), str.end(), 
		std::not1(std::ptr_fun<int, int>(std::isspace))));
	return str;
	}

std::string& rtrim(std::string& str)
	{
	str.erase(std::find_if(str.rbegin(), str.rend(), 
		std::not1(std::ptr_fun<int, int>(std::isspace))).base(), str.end());
	return str;
	}

std::string& trim(std::string& str)
	{
	return ltrim(rtrim(str));
	}

std::string& remove_annotation(std::string& str)
	{
	if (str.find(';') != false)
		return str;
	str.erase(std::find_if(str.rbegin(), str.rend(), 
		[](int _Ch){return _Ch == ';'; }).base()-1, str.end());
	return str;
	}

std::string& right(std::string& str, size_t count)
	{
	str.erase(str.begin(), str.end()-count);
	return str;
	}

std::string& left(std::string& str, size_t count)
	{
	str.erase(str.begin()+count, str.end());
	return str;
	}

std::string& lset(std::string& str, size_t count)
	{
	if (str.size() > count)
		str.resize(count);
	else if (str.size() < count)
		str.insert(str.length(), count-str.length(), ' ');
	return str;
	}

std::string& rset(std::string& str, size_t count)
	{
	if (str.size() > count)
		str.resize(count);
	else if (str.size() < count)
		str.insert(0, count-str.length(), ' ');
	return str;
	}

#define DWORD2BYTE( t, tx )		(BYTE)(((tx) >> ((t) * 8)) & 0xff)

void pushdw(DWORD val, std::vector<BYTE>& at, bool be)
{
	if (!be)
		for (int xa = 0; xa < 4; xa++)
			at.push_back(DWORD2BYTE(xa, val));
	else
		for (int xa = 0; xa < 4; xa++)
			at.push_back(DWORD2BYTE(3 - xa, val));
}

void pushw(WORD val, std::vector<BYTE>& at, bool be)
{
	if (!be)
		{
		at.push_back(val & 0xff);
		at.push_back((val >> 8) & 0xff);
		}
	else
		{
		at.push_back((val >> 8) & 0xff);
		at.push_back(val & 0xff);
		}
}

void pushb(BYTE val, std::vector<BYTE>& at)
{
	at.push_back(val);
}

int get_register(const char* _T)
{
	const char * _Ptr = _T; 
	char _Tmp;
	if (*_Ptr == ' ')
		_Ptr++;
	if (*_Ptr == '[')
		return 255;
	if (*_Ptr++ != 'e')
		return 0;
	switch (*(_Ptr + 1))
	{
	case 'x':
		_Tmp = *_Ptr - 'a';
		return (((_Tmp ^ 0x2) + (_Tmp >> 1)) & 
			((_Tmp << 1) | (_Tmp >> 1) | _Tmp))+1;
	case 'p':
		return (~*_Ptr & 1) + 5;
	case 'i':
		return (~*_Ptr & 1) + 7;
	}
	return 0;
}

int get_oct(const char *_t)
{
	const char *_Ptr = _t;
	int g = 0, h = 1;
	if (*_t == '-')
		*_t++, h = -1;
	for (; *_Ptr != ' ' && *_Ptr && *_Ptr != ',' && *_Ptr != 'o'; _Ptr++)
		g *= 8, g += *_Ptr & 0xf;
	return g*h;
}

int get_integer(const char *_t)
{
	const char *_Ptr = _t;
	int g = 0, h = 1;
	if (*_t == '-')
		*_t++, h = -1;
	for (; *_Ptr != ' ' && *_Ptr && *_Ptr != ',' && *_Ptr != 'i' && *_Ptr != ']'; _Ptr++)
		 g *= 10, g += *_Ptr & 0xf;
	return g*h;
}

int get_hex(const char *_t)
{
	const char *_Ptr = _t;
	int g = 0;
	for (; *_Ptr != ' ' && *_Ptr && *_Ptr != ',' && *_Ptr != 'h'; _Ptr++)
		g *= 16, g += ('0' <= *_Ptr  && *_Ptr  <= '9') ? (*_Ptr & 0xf) : (*_Ptr  - 'a' + 0xa);
	return g;
}


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


std::vector<BYTE> assemble_code(std::string code, bool endian = false)
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
				byte.push_back(0x40+reg1-1);
			else if(arrStr[0] == "dec")
				byte.push_back(0x48+reg1-1);
			else if(arrStr[0] == "mov")
				byte.push_back(0xB8+reg1-1),
				pushdw(get_integer(arrStr[2].c_str()),byte,endian);
			else if(arrStr[0] == "push")
				byte.push_back(0x50+reg1-1);
			else if(arrStr[0] == "pop")
				byte.push_back(0x58+reg1-1);
			else if(arrStr[0] == "jmp")
				byte.push_back(0xff),
				byte.push_back(MakeModRM(3,(int)Extension_Group_5::near_jmp,reg1-1));
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

std::vector<BYTE> assemble_code(std::vector<std::string> code)
{
	std::vector<BYTE> byte;

	for(auto& ocde : code)
	{
		for (auto& ret : assemble_code(ocde))
			byte.push_back(ret);
	}

	return byte;
}


#endif