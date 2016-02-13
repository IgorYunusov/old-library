/*************************************************************************
 *
 *                    ROLLRAT AUTO PERSONA VERBOTER LIBROFEX
 *								LUNATIC SCRIPT
 *                         (C) Copyright 2009-2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

// 이 파일은 2014 02 23부터 작성되었습니다.
// 최초 릴리즈 날짜는 *입니다.

#ifndef __lsmc_core
#define __lsmc_core

#include "ls_def.h"

#define DWORD2BYTE( t, x )		(BYTE)(((x) >> ((t) * 8)) & 0xff)

// LS DWORD를 BYTE를 넣습니다.
void PushDWord(DWORD val, std::vector<BYTE>& at)
{
	for (int a = 0; a < 4; a++)
	{
#if defined(_M_IX86) || defined(_M_IA64) || defined(_IA64) || defined(__amd64) || defined(_M_X64) || defined(_IA64) || defined(_SENDIAN)
		at.push_back(DWORD2BYTE(a, val));
#else
		at.push_back(DWORD2BYTE(3 - a, val));
#endif
	}
}

// LS 피니쉬코드 분석, 함수 분석, 임시 코드 분석 모듈
// V1
// regex를 strcmp로 분석하는 것이 성능상에서는 빠를 것임.(오류 !)
// 최초 릴리즈시 자주쓰이는 순서대로 재배열 할 것!
std::vector<BYTE> Assembly(std::vector<std::string>& strp, int option)
{
	std::vector<BYTE> bytes;
	for(auto str : strp)
	{
#ifdef _DEBUG
		std::tr1::regex andd( R"(andd \d+ \d+)" );
#endif
		if(std::tr1::regex_match(str, andd)){
			DWORD g, t;
			bytes.push_back((BYTE)(BYTE_CODE::AndD));
			sscanf_s(str.c_str(), "andd %d %d", &g, &t);
			PushDWord(g, bytes);
			PushDWord(t, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex and( R"(and \d+ \d+)" );
#endif
		if(std::tr1::regex_match(str, and)){
			DWORD g, t;
			bytes.push_back((BYTE)(BYTE_CODE::And));
			sscanf_s(str.c_str(), "and %d %d", &g, &t);
			PushDWord(g, bytes);
			PushDWord(t, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex ord( R"(ord \d+ \d+)" );
#endif
		if(std::tr1::regex_match(str, ord)){
			DWORD g, t;
			bytes.push_back((BYTE)(BYTE_CODE::OrD));
			sscanf_s(str.c_str(), "ord %d %d", &g, &t);
			PushDWord(g, bytes);
			PushDWord(t, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex or( R"(or \d+ \d+)" );
#endif
		if(std::tr1::regex_match(str, or)){
			DWORD g, t;
			bytes.push_back((BYTE)(BYTE_CODE::Or));
			sscanf_s(str.c_str(), "or %d %d", &g, &t);
			PushDWord(g, bytes);
			PushDWord(t, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex xord( R"(xord \d+ \d+)" );
#endif
		if(std::tr1::regex_match(str, xord)){
			DWORD g, t;
			bytes.push_back((BYTE)(BYTE_CODE::XorD));
			sscanf_s(str.c_str(), "xord %d %d", &g, &t);
			PushDWord(g, bytes);
			PushDWord(t, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex xor( R"(xor \d+ \d+)" );
#endif
		if(std::tr1::regex_match(str, xor)){
			DWORD g, t;
			bytes.push_back((BYTE)(BYTE_CODE::Xor));
			sscanf_s(str.c_str(), "xor %d %d", &g, &t);
			PushDWord(g, bytes);
			PushDWord(t, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex pushd( "pushd \\d+" );
#endif
		if(std::tr1::regex_match(str, pushd)){
			DWORD g;
			bytes.push_back((BYTE)(BYTE_CODE::PushD));
			sscanf_s(str.c_str(), "pushd %d", &g);
			PushDWord(g, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex push( "push \\d+" );
#endif
		if(std::tr1::regex_match(str, push)){
			DWORD g;
			bytes.push_back((BYTE)(BYTE_CODE::Push));
			sscanf_s(str.c_str(), "push %d", &g);
			PushDWord(g, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex pusha( "pusha \\d+ \\d+" );
#endif
		if(std::tr1::regex_match(str, pusha)){
			DWORD g, t;
			bytes.push_back((BYTE)(BYTE_CODE::PushA));
			sscanf_s(str.c_str(), "pusha %d %d", &g, &t);
			PushDWord(g, bytes);
			PushDWord(t, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex popd( "popd \\d+" );
#endif
		if(std::tr1::regex_match(str, popd)){
			DWORD g;
			bytes.push_back((BYTE)(BYTE_CODE::PopD));
			sscanf_s(str.c_str(), "popd %d", &g);
			PushDWord(g, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex pop( "pop \\d+" );
#endif
		if(std::tr1::regex_match(str, pop)){
			DWORD g;
			bytes.push_back((BYTE)(BYTE_CODE::Pop));
			sscanf_s(str.c_str(), "pop %d", &g);
			PushDWord(g, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex popa( "popa \\d+ \\d+" );
#endif
		if(std::tr1::regex_match(str, popa)){
			DWORD g, t;
			bytes.push_back((BYTE)(BYTE_CODE::PopA));
			sscanf_s(str.c_str(), "popa %d %d", &g, &t);
			PushDWord(g, bytes);
			PushDWord(t, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex add( "add \\d+ \\d+" );
#endif
		if(std::tr1::regex_match(str, add)){
			DWORD g, t;
			bytes.push_back((BYTE)(BYTE_CODE::Add));
			sscanf_s(str.c_str(), "add %d %d", &g, &t);
			PushDWord(g, bytes);
			PushDWord(t, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex sub( "sub \\d+ \\d+" );
#endif
		if(std::tr1::regex_match(str, sub)){
			DWORD g, t;
			bytes.push_back((BYTE)(BYTE_CODE::Sub));
			sscanf_s(str.c_str(), "sub %d %d", &g, &t);
			PushDWord(g, bytes);
			PushDWord(t, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex mul( "mul \\d+ \\d+" );
#endif
		if(std::tr1::regex_match(str, mul)){
			DWORD g, t;
			bytes.push_back((BYTE)(BYTE_CODE::Mul));
			sscanf_s(str.c_str(), "mul %d %d", &g, &t);
			PushDWord(g, bytes);
			PushDWord(t, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex _div( "div \\d+ \\d+" );
#endif
		if(std::tr1::regex_match(str, _div)){
			DWORD g, t;
			bytes.push_back((BYTE)(BYTE_CODE::Div));
			sscanf_s(str.c_str(), "div %d %d", &g, &t);
			PushDWord(g, bytes);
			PushDWord(t, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex addv( "addv \\d+ \\d+" );
#endif
		if(std::tr1::regex_match(str, addv)){
			DWORD g, t;
			bytes.push_back((BYTE)(BYTE_CODE::AddV));
			sscanf_s(str.c_str(), "addv %d %d", &g, &t);
			PushDWord(g, bytes);
			PushDWord(t, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex subv( "subv \\d+ \\d+" );
#endif
		if(std::tr1::regex_match(str, subv)){
			DWORD g, t;
			bytes.push_back((BYTE)(BYTE_CODE::SubV));
			sscanf_s(str.c_str(), "subv %d %d", &g, &t);
			PushDWord(g, bytes);
			PushDWord(t, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex mulv( "mulv \\d+ \\d+" );
#endif
		if(std::tr1::regex_match(str, mulv)){
			DWORD g, t;
			bytes.push_back((BYTE)(BYTE_CODE::MulV));
			sscanf_s(str.c_str(), "mulv %d %d", &g, &t);
			PushDWord(g, bytes);
			PushDWord(t, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex _divv( "divv \\d+ \\d+" );
#endif
		if(std::tr1::regex_match(str, _divv)){
			DWORD g, t;
			bytes.push_back((BYTE)(BYTE_CODE::DivV));
			sscanf_s(str.c_str(), "divv %d %d", &g, &t);
			PushDWord(g, bytes);
			PushDWord(t, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex cmp( "cmp \\d+" );
#endif
		if(std::tr1::regex_match(str, cmp)){
			DWORD g;
			bytes.push_back((BYTE)(BYTE_CODE::Cmp));
			sscanf_s(str.c_str(), "cmp %d", &g);
			PushDWord(g, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex cmpa( "cmpa \\d+ \\d+" );
#endif
		if(std::tr1::regex_match(str, cmpa)){
			DWORD g, t;
			bytes.push_back((BYTE)(BYTE_CODE::CmpA));
			sscanf_s(str.c_str(), "cmpa %d %d", &g, &t);
			PushDWord(g, bytes);
			PushDWord(t, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex jmp( "jmp \\d+" );
#endif
		if(std::tr1::regex_match(str, jmp)){
			DWORD g;
			bytes.push_back((BYTE)(BYTE_CODE::Jmp));
			sscanf_s(str.c_str(), "jmp %d", &g);
			PushDWord(g, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex jz( "jz \\d+" );
#endif
		if(std::tr1::regex_match(str, jz)){
			DWORD g;
			bytes.push_back((BYTE)(BYTE_CODE::Jz));
			sscanf_s(str.c_str(), "jz %d", &g);
			PushDWord(g, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex je( "je \\d+" );
#endif
		if(std::tr1::regex_match(str, je)){
			DWORD g;
			bytes.push_back((BYTE)(BYTE_CODE::Je));
			sscanf_s(str.c_str(), "je %d", &g);
			PushDWord(g, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex jnz( "jnz \\d+" );
#endif
		if(std::tr1::regex_match(str, jnz)){
			DWORD g;
			bytes.push_back((BYTE)(BYTE_CODE::Jnz));
			sscanf_s(str.c_str(), "jnz %d", &g);
			PushDWord(g, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex jne( "jne \\d+" );
#endif
		if(std::tr1::regex_match(str, jne)){
			DWORD g;
			bytes.push_back((BYTE)(BYTE_CODE::Jne));
			sscanf_s(str.c_str(), "jne %d", &g);
			PushDWord(g, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex ja( "ja \\d+" );
#endif
		if(std::tr1::regex_match(str, ja)){
			DWORD g;
			bytes.push_back((BYTE)(BYTE_CODE::Ja));
			sscanf_s(str.c_str(), "ja %d", &g);
			PushDWord(g, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex jae( "jae \\d+" );
#endif
		if(std::tr1::regex_match(str, jae)){
			DWORD g;
			bytes.push_back((BYTE)(BYTE_CODE::Jae));
			sscanf_s(str.c_str(), "jae %d", &g);
			PushDWord(g, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex jb( "jb \\d+" );
#endif
		if(std::tr1::regex_match(str, jb)){
			DWORD g;
			bytes.push_back((BYTE)(BYTE_CODE::Jb));
			sscanf_s(str.c_str(), "jb %d", &g);
			PushDWord(g, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex jbe( "jbe \\d+" );
#endif
		if(std::tr1::regex_match(str, jbe)){
			DWORD g;
			bytes.push_back((BYTE)(BYTE_CODE::Jbe));
			sscanf_s(str.c_str(), "jbe %d", &g);
			PushDWord(g, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex inc( "inc \\d+" );
#endif
		if(std::tr1::regex_match(str, inc)){
			DWORD g;
			bytes.push_back((BYTE)(BYTE_CODE::Inc));
			sscanf_s(str.c_str(), "inc %d", &g);
			PushDWord(g, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex _dec( "dec \\d+" );
#endif
		if(std::tr1::regex_match(str, _dec)){
			DWORD g;
			bytes.push_back((BYTE)(BYTE_CODE::Dec));
			sscanf_s(str.c_str(), "dec %d", &g);
			PushDWord(g, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex call( "call \\d+" );
#endif
		if(std::tr1::regex_match(str, call)){
			DWORD g;
			bytes.push_back((BYTE)(BYTE_CODE::Call));
			sscanf_s(str.c_str(), "call %d", &g);
			PushDWord(g, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex calla( "calla \\d+" );
#endif
		if(std::tr1::regex_match(str, calla)){
			DWORD g;
			bytes.push_back((BYTE)(BYTE_CODE::CallA));
			sscanf_s(str.c_str(), "calla %d", &g);
			PushDWord(g, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex ret( "ret" );
#endif
		if(std::tr1::regex_match(str, ret)){
			bytes.push_back((BYTE)(BYTE_CODE::Ret));
			continue;}
#ifdef _DEBUG
		std::tr1::regex mov( "mov \\d+ \\d+" );
#endif
		if(std::tr1::regex_match(str, mov)){
			DWORD g, t;
			bytes.push_back((BYTE)(BYTE_CODE::Mov));
			sscanf_s(str.c_str(), "mov %d %d", &g, &t);
			PushDWord(g, bytes);
			PushDWord(t, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex movv( "movv \\d+ \\d+" );
#endif
		if(std::tr1::regex_match(str, movv)){
			DWORD g, t;
			bytes.push_back((BYTE)(BYTE_CODE::MovV));
			sscanf_s(str.c_str(), "movv %d %d", &g, &t);
			PushDWord(g, bytes);
			PushDWord(t, bytes);
			continue;}
#ifdef _DEBUG
		std::tr1::regex INT3( "INT3" );
#endif
		if(std::tr1::regex_match(str, INT3)){
			bytes.push_back((BYTE)(BYTE_CODE::INT3));
			continue;}
#ifdef _DEBUG
		std::tr1::regex init( "init \\d+" );
#endif
		if(std::tr1::regex_match(str, init)){
			DWORD g;
			bytes.push_back((BYTE)(BYTE_CODE::Init));
			sscanf_s(str.c_str(), "init %d", &g);
			PushDWord(g, bytes);
			continue;}
	}
	return bytes;
}

ASMB Tosombly(std::vector<std::string> assembly, std::vector<rtl_cal> rtls)
{
	std::vector<std::string> ret;
	std::vector<rtl_jmp> jmp;
	std::vector<std::string> str;	// 스트링벡터
	ASMB txy;
	int i = 0;
	for(auto tasm : assembly)
	{
		i++;
#ifdef _DEBUG
		std::tr1::regex TOS1( R"((.*?) ([a-zA-Z_]+) (\d+))" );
		std::tr1::smatch TOS1MATCH;
#endif
		if(std::tr1::regex_match(tasm, TOS1MATCH, TOS1)){
			int count = 0;
			for(auto rtl : rtls)
				{
				if(rtl.b == TOS1MATCH[2].str())
					{
					if(TOS1MATCH[1].str() == "and" || TOS1MATCH[1].str() == "or" || TOS1MATCH[1].str() == "xor")
						{
						ret.push_back(TOS1MATCH[1].str() + "d " +
							std::to_string(count) + " " + TOS1MATCH[3].str());
						break;
						}
					ret.push_back(TOS1MATCH[1].str() + " " + 
						std::to_string(count) + " " + TOS1MATCH[3].str());
					break;
					}
				count++;
				}
			continue;
			}
#ifdef _DEBUG
		std::tr1::regex TOS2( R"((.*?) ([a-zA-Z_]+) ([a-zA-Z_]+))" );
		std::tr1::smatch TOS2MATCH;
#endif
		if(std::tr1::regex_match(tasm, TOS2MATCH, TOS2)){
			int count = 0, a, b;
			for(auto rtl : rtls){
				if (rtl.b == TOS2MATCH[2].str()){
					a = count;
					break;}
				count++;}
			count = 0;
			for(auto rtl : rtls){
				if (rtl.b == TOS2MATCH[3].str()){
					b = count;
					break;}
				count++;}
			if(TOS2MATCH[1].str() == "add" || TOS2MATCH[1].str() == "sub" || TOS2MATCH[1].str() == "mul" 
				|| TOS2MATCH[1].str() == "div" || TOS2MATCH[1].str() == "mov")
				{
				ret.push_back(TOS2MATCH[1].str() + "v " +
					std::to_string(a) + " " + std::to_string(b));
				}
			continue;
			}
#ifdef _DEBUG
		std::tr1::regex TOS3( R"((\:\w+))" );
		std::tr1::smatch TOS3MATCH;
#endif
		if(std::tr1::regex_match(tasm, TOS3MATCH, TOS3)){
			rtl_jmp tj;
			i--;
			tj.pos = i + 1;
			tj.rep = TOS3MATCH[1].str();
			jmp.push_back(tj);
			continue;
			}
#ifdef _DEBUG
		std::tr1::regex TOS4( R"((\:\w+))" );
		std::tr1::smatch TOS4MATCH;
#endif
		if(std::tr1::regex_search(tasm, TOS4MATCH, TOS4)){
			for(auto rtl : jmp)
				{
				if (rtl.rep == TOS4MATCH[1].str())
					{
					std::string::size_type offset = 0;
					offset = tasm.find(rtl.rep, offset);
					tasm.replace(offset, rtl.rep.length(), std::to_string(rtl.pos));
					break;
					}
				}
			}
#ifdef _DEBUG
		std::tr1::regex TOS5( R"(mov ([a-zA-Z_]+) (\"[^\"\\]*(?:\\.[^\"\\]*)*\"))" );
		std::tr1::smatch TOS5MATCH;
#endif
		if(std::tr1::regex_match(tasm, TOS5MATCH, TOS5)){
			int count = 0;
			for(auto rtl : rtls)
				{
				if (rtl.b == TOS5MATCH[1].str())
					{
					str.push_back(TOS5MATCH[2].str());
					ret.push_back("mov " + std::to_string(count) + " " + std::to_string(str.size() - 1));
					break;
					}
				count++;
				}
			continue;
			}
		ret.push_back(tasm);
	}
	txy.assembly = ret;
	txy.str = str;
	return txy;
}

std::vector<BYTE> Link(LINK lnk)
{
	std::vector<BYTE> ret;
	std::vector<PVARIABLEX> rtls;

	int i = 0;

	PSB sb = new SB;
	sb->Signature = LSSIGN;
	sb->BaseAddress = sizeof(SB);
	sb->CallAddress = BASE_CALL_ADDR;

	int hash = 0;
	for(auto rtl : lnk.rtl)
	{
		PVARIABLEX vtxt = new VARIABLEX;
		if (rtl.a == "int")
			vtxt->VarType = TYPE_INT;
		else if (rtl.a == "str")
			vtxt->VarType = TYPE_STR;
		vtxt->VarHash = hash++;
		rtls.push_back(vtxt);
	}

	ASMB amb = Tosombly(lnk.assembly, lnk.rtl);
	std::vector<BYTE> base = Assembly(amb.assembly, 0);
	
	sb->BaseSize = base.size();
	sb->CallSize = 0;
	sb->DataSize = rtls.size();

	sb->DataAddress = sb->BaseSize + sb->BaseAddress;
	sb->StrAddress = sb->DataAddress + rtls.size() * sizeof(VARIABLEX) + 2;
	sb->StrSize = amb.str.size();

	for (; i < sizeof(SB); i++)
		ret.push_back((BYTE)(((char *)(void *)(sb))[i]));
	for(int t = 0; t < base.size(); t++)
		ret.push_back(base[t]);
	for(int t = 0; t < rtls.size(); t++)
		for(int f = 0; f < sizeof(VARIABLEX); f++)
			ret.push_back((BYTE)(((char *)(void *)(rtls[t]))[f]));
	for(int t = 0; t < amb.str.size(); t++)
		{
		for (int f = 1; f < amb.str[t].size() - 1; f++)
			ret.push_back((BYTE)(amb.str[t][f]));
		ret.push_back((BYTE)(0));
		}
	return ret;
}

#endif