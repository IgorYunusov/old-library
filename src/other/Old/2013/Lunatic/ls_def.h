/*************************************************************************
 *
 *                    ROLLRAT AUTO PERSONA VERBOTER LIBROFEX
 *								LUNATIC SCRIPT
 *                         (C) Copyright 2009-2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

// �� ������ 2014 02 20���� �ۼ��Ǿ����ϴ�.
// ���� ������ ��¥�� *�Դϴ�.

#ifndef __ls_def
#define __ls_def

#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <regex>
#include <Windows.h>
#include <fstream>
#include <iostream>
#include <functional> 
#include <cctype>
#include <locale>
#include <stack>
#include <initializer_list>

#undef noexcept
#define noexcept throw()

// �⺻������ RELEASE��� �ÿ��� _NOERROR�÷��װ� �ö󰡰Ե˴ϴ�.
// �� ������ �����Ͽ� RELEASE�ÿ��� ������ �߻��ϰԲ� �� �� �ֽ��ϴ�.
#ifndef _DEBUG
#define _NOERROR
#endif

// ������ŷ����
#ifndef _NOHOOK
#pragma comment(linker, "/SECTION:.SHAREDATA,RWS")
#pragma data_seg(".SHAREDATA")
HINSTANCE gIunst = NULL;
HHOOK gHook = NULL;
HWND gWnd = NULL;
#pragma data_seg()
#endif

typedef struct __signature_base__
{
	DWORD Signature;
	DWORD BaseAddress;		// EP
	DWORD CallAddress;
	DWORD DataAddress;
	DWORD StrAddress;
	
	DWORD BaseSize;
	DWORD CallSize;
	DWORD DataSize;
	DWORD StrSize;
}	SB, *PSB;

#define LSSIGN			0x534C

#define BASE_CALL_ADDR	0x1000
#define BASE_DATA_ADDR	0x2000

#define BASE_BYTE_SIZE	0x5000

typedef struct __T
{
	std::string a;
	std::string b;
}	rtl_cal;

typedef struct __FOR
{
	int k;				// Ÿ��. 0 : �Ϲݹݺ���, 1 : ���ǹݺ���
	std::string a;		// �ݺ����̸�
	std::string b;		// ����/����
}	rtl_for;

typedef struct __JMP
{
	int pos;
	std::string rep;
}	rtl_jmp;

typedef struct __LINK
{
	std::vector<rtl_cal> rtl;
	std::vector<std::string> assembly;
}	LINK;

typedef struct __DATAVARIALBE
{
	DWORD VarType;
	DWORD VarHash;
}	VARIABLEX, *PVARIABLEX;

typedef struct __ASMV
{
	std::vector<std::string> assembly;
	std::vector<std::string> str;
}	ASMB;

typedef enum class __ttey
{
	// Logic
	AndD,			// val X dw
	And,			// val X val
	OrD,
	Or,
	XorD,
	Xor,

	// Stack Control ���� ������ ���ڵ带 ¦���� ����Ͽ��� �Ѵ�.
	PushD,			// dw
	Push,			// val
	PushA,		// type dw
	PopD,			// dw
	Pop,			// val
	PopA,		// type dw

	// two bytes
	BT,			// Ȯ�强 ���

	// Arithmetic
	Add,			// val x dw
	Sub,
	Mul,
	Div,
	AddV,			// val x val
	SubV,
	MulV,
	DivV,

	// Jump
	Cmp,
	CmpA,
	Jmp,
	Jz,				// zero
	Je,				// equal
	Jnz,			// 0�� �ƴϴ�
	Jne,			// �����ʴ�
	Ja,				// >
	Jae,			// >=
	Jb,				// <
	Jbe,			// <=
	Inc,
	Dec,

	// Function
	Call,
	CallA,			// ���� API CALL
	Ret,			// ȣ��ÿ��� ���Ǿ����.
	
	// Data
	Mov,
	MovV,

	// Special
	INT3,			// ��� ����

	// Variable
	Init,			// ������ ���� �ʱ�ȭ
}	BYTE_CODE;

// pusha�� popa�� Ÿ����.
#define TYPE_INT		1
#define TYPE_STR		2

#ifndef _DEBUG
std::tr1::regex andd( R"(andd \d+ \d+)" );
std::tr1::regex and( "and \\d+ \\d+" );
std::tr1::regex ord( "ord \\d+ \\d+" );
std::tr1::regex or( "or \\d+ \\d+" );
std::tr1::regex xord( "xord \\d+ \\d+" );
std::tr1::regex xor( "xor \\d+ \\d+" );
std::tr1::regex pushd( "pushd \\d+" );
std::tr1::regex push( "push \\d+" );
std::tr1::regex pusha( "pusha \\d+ \\d+" );
std::tr1::regex popd( "popd \\d+" );
std::tr1::regex pop( "pop \\d+" );
std::tr1::regex popa( "popa \\d+ \\d+" );
std::tr1::regex add( "add \\d+ \\d+" );
std::tr1::regex sub( "sub \\d+ \\d+" );
std::tr1::regex mul( "mul \\d+ \\d+" );
std::tr1::regex _div( "div \\d+ \\d+" );
std::tr1::regex addv( "addv \\d+ \\d+" );
std::tr1::regex subv( "subv \\d+ \\d+" );
std::tr1::regex mulv( "mulv \\d+ \\d+" );
std::tr1::regex _divv( "divv \\d+ \\d+" );
std::tr1::regex cmp( "cmp \\d+" );
std::tr1::regex cmpa( "cmpa \\d+ \\d+" );
std::tr1::regex jmp( "jmp \\d+" );
std::tr1::regex jz( "jz \\d+" );
std::tr1::regex je( "je \\d+" );
std::tr1::regex jnz( "jnz \\d+" );
std::tr1::regex jne( "jne \\d+" );
std::tr1::regex ja( "ja \\d+" );
std::tr1::regex jae( "jae \\d+" );
std::tr1::regex jb( "jb \\d+" );
std::tr1::regex jbe( "jbe \\d+" );
std::tr1::regex inc( "inc \\d+" );
std::tr1::regex _dec( "dec \\d+" );
std::tr1::regex call( "call \\d+" );
std::tr1::regex calla( "calla \\d+" );
std::tr1::regex ret( "ret" );
std::tr1::regex mov( "mov \\d+ \\d+" );
std::tr1::regex movv( "movv \\d+ \\d+" );
std::tr1::regex INT3( "INT3" );
std::tr1::regex init( "init \\d+" );

std::tr1::regex ANNOTATION( R"(^&&[\w\W]*$)" );
std::tr1::regex CALL( R"((\w+)\s*\((.*?)\))" );
std::tr1::smatch CALLMATCH;
std::tr1::regex CALLINPUT( R"((\w+)\s*\=\s*(\w+)\s*\((.*?)\))" );
std::tr1::smatch CALLINPUTMATCH;
std::tr1::regex VARIABLE( R"(\$(\w+)\s+(\w+))" );
std::tr1::smatch VARIABLEMATCH;
std::tr1::regex VARIABLEWITHEQUAL( R"(\$(\w+)\s+(\w+)\s+\=\s*(.*?))" );
std::tr1::smatch VARIABLEWITHEQUALMATCH;
std::tr1::regex VARIABLEEQUAL( R"((\w+)\s*\=(.*?))" );
std::tr1::smatch VARIABLEEQUALMATCH;
std::tr1::regex LOOP( R"(For\s+(\w+)\s*\((\w+)\s*\:(\d+)\))" );
std::tr1::smatch LOOPMATCH;
std::tr1::regex NEXT( R"(Next\s+(\w+))" );
std::tr1::smatch NEXTMATCH;
std::tr1::regex ILOOP( R"(For\s+(\w+)\s*\((.*?)\))" );
std::tr1::smatch ILOOPMATCH;
std::tr1::regex VARIABLEKEQUAL( R"((\w+)\s*([\+\-\*\/\&\^\|])\=(.*?))" );
std::tr1::smatch VARIABLEKEQUALMATCH;

std::tr1::regex JklS1( R"((\d+)\s*([\+\-\^\*\/\&\|])\s*(\d+))" );
std::tr1::regex JklS3( R"(([\+\-\^\*\/\&\|])\s*(\d+))" );
std::tr1::smatch JklS2;
std::tr1::regex S1( R"(([a-zA-Z_]+)\s*([\+\-\^\*\/\&\|])\s*(\d+))" );
std::tr1::smatch S2;
std::tr1::regex LS1( R"((\d+)\s*([\+\-\^\*\/\&\|])\s*([a-zA-Z_]+))" );
std::tr1::smatch LS2;
std::tr1::regex RS1( R"(([a-zA-Z_]+)\s*([\+\-\^\*\/\&\|])\s*([a-zA-Z_]+))" );
std::tr1::smatch RS2;
std::tr1::regex I1( R"(([\w\d]+)\s*([\<\>\=][\>\=]?)\s*([\w\d]+))" );
std::tr1::smatch I2;

std::tr1::regex __MOVNODATASET1( R"((.*?) (.*?) (.*?))" );
std::tr1::smatch __MOVNODATASETMATCH1;
std::tr1::regex __MOVNODATASET( R"(mov (.*?) (.*?))" );
std::tr1::smatch __MOVNODATASETMATCH;

std::tr1::regex TOS1( R"((.*?) ([a-zA-Z_]+) (\d+))" );
std::tr1::smatch TOS1MATCH;
std::tr1::regex TOS2( R"((.*?) ([a-zA-Z_]+) ([a-zA-Z_]+))" );
std::tr1::smatch TOS2MATCH;
std::tr1::regex TOS3( R"((\:\w+))" );
std::tr1::smatch TOS3MATCH;
std::tr1::regex TOS4( R"((\:\w+))" );
std::tr1::smatch TOS4MATCH;
std::tr1::regex TOS5( R"(mov ([a-zA-Z_]+) (\"[^\"\\]*(?:\\.[^\"\\]*)*\"))" );
std::tr1::smatch TOS5MATCH;
#endif

#endif