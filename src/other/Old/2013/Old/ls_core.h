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

#ifndef __ls_core
#define __ls_core

#include "ls_error.h"
#include "ls_def.h"
#include "lsc_function.h"

// �м���
// �� ���� �� �ҽ��� �ִ´�. *.lsd file string
LINK Analyze(std::vector<std::string>& strp, int option)
{
	std::vector<std::string> assembly;		// ����� �ڵ带 �ִ´�.
	std::vector<rtl_cal> rtl;				// ��������
	bool loop = false;						// ������?
	std::stack<rtl_for> stk;				// ��������
	LINK linkx;
#ifdef _DEBUG
	int j = 0;
#endif
	for(auto str : strp)
	{
#ifdef _DEBUG
		j++;
#endif
		// 1. �ּ�
		// ���Խ� : ^&&[\w\W]*$
		// ĸ�� : ����.
#ifdef _DEBUG
		std::tr1::regex ANNOTATION( R"(^&&[\w\W]*$)" );
#endif
		if(std::tr1::regex_match(str, ANNOTATION)){
#ifdef _DEBUG
			std::cout << j << "�� : �ּ�" << std::endl;
#endif
			continue;}

		// 2. �Ϲ�ȣ��
		// ���Խ� : (\w+)\s*\((.*?)\)
		// ĸ�� : �Լ��̸�, �Լ��μ�
#ifdef _DEBUG
		std::tr1::regex CALL( R"((\w+)\s*\((.*?)\))" );
		std::tr1::smatch CALLMATCH;
#endif
		if(std::tr1::regex_match(str, CALLMATCH, CALL)){
#ifdef _DEBUG
			std::cout << j << "�� : �Լ�ȣ��, �Լ��̸� : " << CALLMATCH[1].str() << ", �Լ��μ� : " 
				<< CALLMATCH[2].str() << std::endl;
#endif
#ifdef _NOERROR
			LSC_Call(assembly, CALLMATCH[1].str(), CALLMATCH[2].str());
#else
			LSC_Call(assembly, CALLMATCH[1].str(), CALLMATCH[2].str(), rtl);
#endif
			continue;}

		// 3. ����ȣ��
		// ���Խ� : (\w+)\s+(\w+)\s*\((.*?)\)
		// ĸ�� : ���Ժ����̸�, �Լ��̸�, �Լ��μ�
#ifdef _DEBUG
		std::tr1::regex CALLINPUT( R"((\w+)\s*\=\s*(\w+)\s*\((.*?)\))" );
		std::tr1::smatch CALLINPUTMATCH;
#endif
		if(std::tr1::regex_match(str, CALLINPUTMATCH, CALLINPUT)){
#ifdef _DEBUG
			std::cout << j << "�� : �Լ�ȣ��, �Լ��̸� : " << CALLINPUTMATCH[2].str() << ", �Լ��μ� : " 
				<< CALLINPUTMATCH[3].str() << std::endl;
#endif
#ifdef _NOERROR
			LSC_Call(assembly, CALLINPUTMATCH[1].str(), CALLINPUTMATCH[2].str(), CALLINPUTMATCH[3].str());
#else
			LSC_Call(assembly, CALLINPUTMATCH[1].str(), CALLINPUTMATCH[2].str(), CALLINPUTMATCH[3].str(), rtl);
#endif
			continue;}

		// 4. ��������
		// ���Խ� : \$(\w+)\s+(\w+)
		// ĸ�� : ��������, �����̸�
#ifdef _DEBUG
		std::tr1::regex VARIABLE( R"(\$(\w+)\s+(\w+))" );
		std::tr1::smatch VARIABLEMATCH;
#endif
		if(std::tr1::regex_match(str, VARIABLEMATCH, VARIABLE)){
#ifdef _DEBUG
			std::cout << j << "�� : ��������, ����Ÿ�� : " << VARIABLEMATCH[1].str() << ", �����̸� : " 
				<< VARIABLEMATCH[2].str() << std::endl;
#endif
			rtl_cal rc;
			rc.a = VARIABLEMATCH[1].str();
			rc.b = VARIABLEMATCH[2].str();
			rtl.push_back(rc);
			continue;}

		// 5. �������𵿽ô���
		// ���Խ� : \$(\w+)\s+(\w+)\s+\=\s*(.*?)
		// ĸ�� : ��������, �����̸�, ��
#ifdef _DEBUG
		std::tr1::regex VARIABLEWITHEQUAL( R"(\$(\w+)\s+(\w+)\s+\=\s*(.*?))" );
		std::tr1::smatch VARIABLEWITHEQUALMATCH;
#endif
		if(std::tr1::regex_match(str, VARIABLEWITHEQUALMATCH, VARIABLEWITHEQUAL)){
#ifdef _DEBUG
			std::cout << j << "�� : ��������, ����Ÿ�� : " << VARIABLEWITHEQUALMATCH[1].str() << ", �����̸� : " 
				<< VARIABLEWITHEQUALMATCH[2].str() << ", �� : " << VARIABLEWITHEQUALMATCH[3].str() << std::endl;
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

		// 6. ��������
		// ���Խ� : (\w+)\s*\=(.*?)
		// ĸ�� : ���Ժ����̸�, ��
		std::tr1::regex VARIABLEEQUAL( R"((\w+)\s*\=(.*?))" );
		std::tr1::smatch VARIABLEEQUALMATCH;
		if(std::tr1::regex_match(str, VARIABLEEQUALMATCH, VARIABLEEQUAL)){
#ifdef _DEBUG
			std::cout << j << "�� : ��������, �����̸� : " << VARIABLEEQUALMATCH[1].str() << ", �� : " 
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

		// 7. �Ϲݷ�����
		// ���Խ� : For\s+(\w+)\s*\((\w+)\s*\:(\d+)\)
		// ĸ�� : �ݺ����̸�, ī��Ʈ����, Ƚ��
#ifdef _DEBUG
		std::tr1::regex LOOP( R"(For\s+(\w+)\s*\((\w+)\s*\:(\d+)\))" );
		std::tr1::smatch LOOPMATCH;
#endif
		if(std::tr1::regex_match(str, LOOPMATCH, LOOP)){
#ifdef _DEBUG
			std::cout << j << "�� : �Ϲݷ�����" << std::endl;
#endif
			rtl_cal rc;
			rc.a = "int";
			rc.b = LOOPMATCH[2].str();
			rtl.push_back(rc);
			// LOOPMATCH[2].str()�� ������ ���ǵǾ� ���� �ƴ��Ͽ�����.
			assembly.push_back("mov " + LOOPMATCH[2].str() + " " + LOOPMATCH[3].str());
			assembly.push_back(":" + LOOPMATCH[1].str());

			rtl_for fort = {0, LOOPMATCH[1].str(), LOOPMATCH[2].str()};
			stk.push(fort);
			loop = true;
			continue;}

		// 8. ������ End
		// ���Խ� : Next\s+(\w+)
		// ĸ�� : �ݺ����̸�, ī��Ʈ����, Ƚ��
#ifdef _DEBUG
		std::tr1::regex NEXT( R"(Next\s+(\w+))" );
		std::tr1::smatch NEXTMATCH;
#endif
		if(std::tr1::regex_match(str, NEXTMATCH, NEXT) && loop){
#ifdef _DEBUG
			std::cout << j << "�� : ������ End" << std::endl;
#endif
			// ��Ģ������ �������� ����Ʈ�ڵ�м��Ⱑ �����ؿ�.
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

		// 9. ���Ƿ�����
		// ���Խ� : For\s+(\w+)\s*\((.*?)\)
		// ĸ�� : �ݺ����̸�, ����
#ifdef _DEBUG
		std::tr1::regex ILOOP( R"(For\s+(\w+)\s*\((.*?)\))" );
		std::tr1::smatch ILOOPMATCH;
#endif
		if(std::tr1::regex_match(str, ILOOPMATCH, ILOOP)){
#ifdef _DEBUG
			std::cout << j << "�� : ���Ƿ�����" << std::endl;
#endif
			// LOOPMATCH[2].str()�� ������ ���ǵǾ� �־����.
			assembly.push_back(":" + ILOOPMATCH[1].str());

#ifdef _NOERROR
			rtl_for fort = {1, ILOOPMATCH[1].str(), ILOOPMATCH[2].str()};
#else
			rtl_for fort = {1, ILOOPMATCH[1].str(), ILOOPMATCH[2].str()};
#endif
			stk.push(fort);
			loop = true;
			continue;}

		// 10. �����̴���
		// ���Խ� : (\w+)\s*([\+\-\*\/\&\^\|])\=(.*?)
		// ĸ�� : ���Ժ����̸�, ��
#ifdef _DEBUG
		std::tr1::regex VARIABLEKEQUAL( R"((\w+)\s*([\+\-\*\/\&\^\|])\=(.*?))" );
		std::tr1::smatch VARIABLEKEQUALMATCH;
#endif
		if(std::tr1::regex_match(str, VARIABLEKEQUALMATCH, VARIABLEKEQUAL)){
#ifdef _DEBUG
			std::cout << j << "�� : �����̴���, �����̸� : " << VARIABLEKEQUALMATCH[1].str() << ", �� : " 
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

// ����ȭ
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