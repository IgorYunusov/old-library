/*************************************************************************
 *
 *                    ROLLRAT AUTO PERSONA VERBOTER LIBROFEX
 *								LUNATIC SCRIPT
 *                         (C) Copyright 2009-2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

// 이 파일은 2014 02 20부터 작성되었습니다.
// 최초 릴리즈 날짜는 *입니다.

#ifndef __ls_core
#define __ls_core

#include "ls_error.h"
#include "ls_def.h"
#include "lsc_function.h"

// 분석기
// 이 곳에 총 소스를 넣는다. *.lsd file string
LINK Analyze(std::vector<std::string>& strp, int option)
{
	std::vector<std::string> assembly;		// 어셈블리 코드를 넣는다.
	std::vector<rtl_cal> rtl;				// 변수벡터
	bool loop = false;						// 루프임?
	std::stack<rtl_for> stk;				// 루프스택
	LINK linkx;
#ifdef _DEBUG
	int j = 0;
#endif
	for(auto str : strp)
	{
#ifdef _DEBUG
		j++;
#endif
		// 1. 주석
		// 정규식 : ^&&[\w\W]*$
		// 캡쳐 : 없음.
#ifdef _DEBUG
		std::tr1::regex ANNOTATION( R"(^&&[\w\W]*$)" );
#endif
		if(std::tr1::regex_match(str, ANNOTATION)){
#ifdef _DEBUG
			std::cout << j << "줄 : 주석" << std::endl;
#endif
			continue;}

		// 2. 일반호출
		// 정규식 : (\w+)\s*\((.*?)\)
		// 캡쳐 : 함수이름, 함수인수
#ifdef _DEBUG
		std::tr1::regex CALL( R"((\w+)\s*\((.*?)\))" );
		std::tr1::smatch CALLMATCH;
#endif
		if(std::tr1::regex_match(str, CALLMATCH, CALL)){
#ifdef _DEBUG
			std::cout << j << "줄 : 함수호출, 함수이름 : " << CALLMATCH[1].str() << ", 함수인수 : " 
				<< CALLMATCH[2].str() << std::endl;
#endif
#ifdef _NOERROR
			LSC_Call(assembly, CALLMATCH[1].str(), CALLMATCH[2].str());
#else
			LSC_Call(assembly, CALLMATCH[1].str(), CALLMATCH[2].str(), rtl);
#endif
			continue;}

		// 3. 대입호출
		// 정규식 : (\w+)\s+(\w+)\s*\((.*?)\)
		// 캡쳐 : 대입변수이름, 함수이름, 함수인수
#ifdef _DEBUG
		std::tr1::regex CALLINPUT( R"((\w+)\s*\=\s*(\w+)\s*\((.*?)\))" );
		std::tr1::smatch CALLINPUTMATCH;
#endif
		if(std::tr1::regex_match(str, CALLINPUTMATCH, CALLINPUT)){
#ifdef _DEBUG
			std::cout << j << "줄 : 함수호출, 함수이름 : " << CALLINPUTMATCH[2].str() << ", 함수인수 : " 
				<< CALLINPUTMATCH[3].str() << std::endl;
#endif
#ifdef _NOERROR
			LSC_Call(assembly, CALLINPUTMATCH[1].str(), CALLINPUTMATCH[2].str(), CALLINPUTMATCH[3].str());
#else
			LSC_Call(assembly, CALLINPUTMATCH[1].str(), CALLINPUTMATCH[2].str(), CALLINPUTMATCH[3].str(), rtl);
#endif
			continue;}

		// 4. 변수선언
		// 정규식 : \$(\w+)\s+(\w+)
		// 캡쳐 : 변수형태, 변수이름
#ifdef _DEBUG
		std::tr1::regex VARIABLE( R"(\$(\w+)\s+(\w+))" );
		std::tr1::smatch VARIABLEMATCH;
#endif
		if(std::tr1::regex_match(str, VARIABLEMATCH, VARIABLE)){
#ifdef _DEBUG
			std::cout << j << "줄 : 변수선언, 변수타입 : " << VARIABLEMATCH[1].str() << ", 변수이름 : " 
				<< VARIABLEMATCH[2].str() << std::endl;
#endif
			rtl_cal rc;
			rc.a = VARIABLEMATCH[1].str();
			rc.b = VARIABLEMATCH[2].str();
			rtl.push_back(rc);
			continue;}

		// 5. 변수선언동시대입
		// 정규식 : \$(\w+)\s+(\w+)\s+\=\s*(.*?)
		// 캡쳐 : 변수형태, 변수이름, 값
#ifdef _DEBUG
		std::tr1::regex VARIABLEWITHEQUAL( R"(\$(\w+)\s+(\w+)\s+\=\s*(.*?))" );
		std::tr1::smatch VARIABLEWITHEQUALMATCH;
#endif
		if(std::tr1::regex_match(str, VARIABLEWITHEQUALMATCH, VARIABLEWITHEQUAL)){
#ifdef _DEBUG
			std::cout << j << "줄 : 변수선언, 변수타입 : " << VARIABLEWITHEQUALMATCH[1].str() << ", 변수이름 : " 
				<< VARIABLEWITHEQUALMATCH[2].str() << ", 값 : " << VARIABLEWITHEQUALMATCH[3].str() << std::endl;
#endif
			rtl_cal rc;
			rc.a = VARIABLEWITHEQUALMATCH[1].str();
			rc.b = VARIABLEWITHEQUALMATCH[2].str();
			rtl.push_back(rc);
			//assembly.push_back("init " + VARIABLEWITHEQUALMATCH[2].str());
#ifdef _NOERROR
			LSC_Equal(assembly, VARIABLEWITHEQUALMATCH[2].str(), 
				LSCP_Jkl(assembly, VARIABLEWITHEQUALMATCH[3].str(), VARIABLEWITHEQUALMATCH[2].str(), rtl)
				);
#else
			LSC_Equal(assembly, VARIABLEWITHEQUALMATCH[2].str(),
				LSCP_Jkl(assembly, VARIABLEWITHEQUALMATCH[3].str(), VARIABLEWITHEQUALMATCH[2].str(), rtl)
				, rtl);
#endif
			continue;}

		// 6. 변수대입
		// 정규식 : (\w+)\s*\=(.*?)
		// 캡쳐 : 대입변수이름, 값
		std::tr1::regex VARIABLEEQUAL( R"((\w+)\s*\=(.*?))" );
		std::tr1::smatch VARIABLEEQUALMATCH;
		if(std::tr1::regex_match(str, VARIABLEEQUALMATCH, VARIABLEEQUAL)){
#ifdef _DEBUG
			std::cout << j << "줄 : 변수대입, 변수이름 : " << VARIABLEEQUALMATCH[1].str() << ", 값 : " 
				<< VARIABLEEQUALMATCH[2].str() << std::endl;
#endif
			//assembly.push_back("init " + VARIABLEEQUALMATCH[1].str());
#ifdef _NOERROR
			LSC_Equal(assembly, VARIABLEEQUALMATCH[1].str(), 
				LSCP_Jkl(assembly, VARIABLEEQUALMATCH[2].str(), VARIABLEEQUALMATCH[1].str(), rtl)
					);
#else
			LSC_Equal(assembly, VARIABLEEQUALMATCH[1].str(),
				LSCP_Jkl(assembly, VARIABLEEQUALMATCH[2].str(), VARIABLEEQUALMATCH[1].str(), rtl)
				, rtl);
#endif
			continue;}

		// 7. 일반루프문
		// 정규식 : For\s+(\w+)\s*\((\w+)\s*\:(\d+)\)
		// 캡쳐 : 반복문이름, 카운트변수, 횟수
#ifdef _DEBUG
		std::tr1::regex LOOP( R"(For\s+(\w+)\s*\((\w+)\s*\:(\d+)\))" );
		std::tr1::smatch LOOPMATCH;
#endif
		if(std::tr1::regex_match(str, LOOPMATCH, LOOP)){
#ifdef _DEBUG
			std::cout << j << "줄 : 일반루프문" << std::endl;
#endif
			rtl_cal rc;
			rc.a = "int";
			rc.b = LOOPMATCH[2].str();
			rtl.push_back(rc);
			// LOOPMATCH[2].str()의 변수가 정의되어 있지 아니하여야함.
			assembly.push_back("mov " + LOOPMATCH[2].str() + " " + LOOPMATCH[3].str());
			assembly.push_back(":" + LOOPMATCH[1].str());

			rtl_for fort = {0, LOOPMATCH[1].str(), LOOPMATCH[2].str()};
			stk.push(fort);
			loop = true;
			continue;}

		// 8. 루프문 End
		// 정규식 : Next\s+(\w+)
		// 캡쳐 : 반복문이름, 카운트변수, 횟수
#ifdef _DEBUG
		std::tr1::regex NEXT( R"(Next\s+(\w+))" );
		std::tr1::smatch NEXTMATCH;
#endif
		if(std::tr1::regex_match(str, NEXTMATCH, NEXT) && loop){
#ifdef _DEBUG
			std::cout << j << "줄 : 루프문 End" << std::endl;
#endif
			// 규칙위반의 루프문은 바이트코드분석기가 아파해요.
			if(stk.top().k == 0)
			{
				assembly.push_back("dec " + stk.top().b);
				assembly.push_back("cmp " + stk.top().b);
				assembly.push_back("jnz :" + NEXTMATCH[1].str());
				stk.pop();
			}
			else if(stk.top().k == 1)
			{
#ifdef _NOERROR
				assembly.push_back(LSCP_aIf(assembly, stk.top().b) + " :" + stk.top().a);
#else
				assembly.push_back(LSCP_aIf(assembly, stk.top().b, rtl) + " :" + stk.top().a);
#endif
				stk.pop();
			}
			if(stk.size() == 0)
				loop = false;
			continue;}

		// 9. 조건루프문
		// 정규식 : For\s+(\w+)\s*\((.*?)\)
		// 캡쳐 : 반복문이름, 조건
#ifdef _DEBUG
		std::tr1::regex ILOOP( R"(For\s+(\w+)\s*\((.*?)\))" );
		std::tr1::smatch ILOOPMATCH;
#endif
		if(std::tr1::regex_match(str, ILOOPMATCH, ILOOP)){
#ifdef _DEBUG
			std::cout << j << "줄 : 조건루프문" << std::endl;
#endif
			// LOOPMATCH[2].str()의 변수가 정의되어 있어야함.
			assembly.push_back(":" + ILOOPMATCH[1].str());

#ifdef _NOERROR
			rtl_for fort = {1, ILOOPMATCH[1].str(), ILOOPMATCH[2].str()};
#else
			rtl_for fort = {1, ILOOPMATCH[1].str(), ILOOPMATCH[2].str()};
#endif
			stk.push(fort);
			loop = true;
			continue;}

		// 10. 변수이대입
		// 정규식 : (\w+)\s*([\+\-\*\/\&\^\|])\=(.*?)
		// 캡쳐 : 대입변수이름, 값
#ifdef _DEBUG
		std::tr1::regex VARIABLEKEQUAL( R"((\w+)\s*([\+\-\*\/\&\^\|])\=(.*?))" );
		std::tr1::smatch VARIABLEKEQUALMATCH;
#endif
		if(std::tr1::regex_match(str, VARIABLEKEQUALMATCH, VARIABLEKEQUAL)){
#ifdef _DEBUG
			std::cout << j << "줄 : 변수이대입, 변수이름 : " << VARIABLEKEQUALMATCH[1].str() << ", 값 : " 
				<< VARIABLEKEQUALMATCH[3].str() << std::endl;
#endif
			//assembly.push_back("init " + VARIABLEKEQUALMATCH[1].str());
#ifdef _NOERROR
			LSC_Equal(assembly, VARIABLEKEQUALMATCH[1].str(), 
				LSCP_Jkl(assembly, VARIABLEKEQUALMATCH[1].str() +
				VARIABLEKEQUALMATCH[2].str() + VARIABLEKEQUALMATCH[3].str(), VARIABLEKEQUALMATCH[1].str(), rtl)
				);
#else
			LSC_Equal(assembly, VARIABLEKEQUALMATCH[1].str(), 
				LSCP_Jkl(assembly, VARIABLEKEQUALMATCH[1].str() +
				VARIABLEKEQUALMATCH[2].str() + VARIABLEKEQUALMATCH[3].str(), VARIABLEKEQUALMATCH[1].str(), rtl)
				, rtl);
#endif
			continue;}
	}
	assembly.push_back("ret");
	linkx.assembly = assembly;
	linkx.rtl = rtl;
	return linkx;
}

// 최적화
std::vector<std::string> Optimization(std::vector<std::string> strp)
{
	std::vector<std::string> ret;
	std::string left, right;
	for(auto& str : strp)
	{
	T:
#ifdef _DEBUG
		std::tr1::regex __MOVNODATASET1( R"((.*?) (.*?) (.*?))" );
		std::tr1::smatch __MOVNODATASETMATCH1;
#endif
		if(std::tr1::regex_match(str, __MOVNODATASETMATCH1, __MOVNODATASET1)){
			if(__MOVNODATASETMATCH1[2].str() == left)
				{
				str = __MOVNODATASETMATCH1[1].str() + " " + right + " " + __MOVNODATASETMATCH1[3].str();
				goto T;
				}
			if(__MOVNODATASETMATCH1[3].str() == left)
				{
				str = __MOVNODATASETMATCH1[1].str() + " " + __MOVNODATASETMATCH1[2].str() + " " + right;
				goto T;
				}
			}
		
#ifdef _DEBUG
		std::tr1::regex __MOVNODATASET( R"(mov (.*?) (.*?))" );
		std::tr1::smatch __MOVNODATASETMATCH;
#endif
		if(std::tr1::regex_match(str, __MOVNODATASETMATCH, __MOVNODATASET)){
			if(__MOVNODATASETMATCH[1].str() == __MOVNODATASETMATCH[2].str())
				continue;
			if(__MOVNODATASETMATCH[1].str()[0] == '\$')
				{
				left = __MOVNODATASETMATCH[1].str(); right = __MOVNODATASETMATCH[2].str();
				continue;
				}
			}

		ret.push_back(str);
	}
	return ret;
}

#endif