/*************************************************************************
 *
 *                    ROLLRAT AUTO PERSONA VERBOTER LIBROFEX
 *								LUNATIC SCRIPT
 *                         (C) Copyright 2009-2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

// �� ������ 2014 02 21���� �ۼ��Ǿ����ϴ�.
// ���� ������ ��¥�� *�Դϴ�.

#ifndef __lsc_function
#define __lsc_function

#include "ls_def.h"

std::string &ltrim(std::string &str)
{
	str.erase(str.begin(), std::find_if(str.begin(), str.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
	return str;
}
std::string &rtrim(std::string &str)
{
	str.erase(std::find_if(str.rbegin(), str.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), str.end());
	return str;
}
std::string &trim(std::string &str)
{
	return ltrim(rtrim(str));
}

int LSC_Call_IT(std::string str)
{
	int i = 0;
	for(auto& ch : str)
		if (ch == ',')
			i++;
	return i;
}

std::vector<std::string> split(std::string str, std::string sep)
{
	char * cstr = const_cast<char*>(str.c_str());
	char * current;
	std::vector<std::string> arr;
	current = strtok(cstr, sep.c_str());
	while (current != NULL)
	{
		arr.push_back(current);
		current = strtok(NULL, sep.c_str());
	}
	return arr;
}

//
//	@brief �� �Լ��� Call�� ���� ���� �� call�� �м��մϴ�.
//
//	@param assembly		����� ����
//	@param fname		�Լ��̸�
//	@param finja		�Լ�����
//
void LSC_Call(std::vector<std::string>& assembly, std::string fname, std::string finja
#ifndef _NOERROR
	, std::vector<rtl_cal> rtl
#endif
	)
{
	// ���ڴ� ������ ���ں��� �ִ´�. \
				����*������ ���� ǥ���� factor���� inja�� �ƴմϴ�.
	std::vector<std::string> injas;

	if(!finja.compare(""))
	{
		assembly.push_back("call " + fname);
		return;
	}
	
	if (!LSC_Call_IT(finja))
		assembly.push_back("push " + trim(finja));
	else
	{
		injas = split(finja, ",");
		std::reverse(injas.begin(), injas.end());
#ifndef _NOERROR
		for(auto& t : injas)
		{
			t = trim(t);
			for (auto& ta : rtl)
				if (ta.b == t)
					goto T;
			std::cout << "	Error LS0002: ���� '" << t << "'�� ã�� �� �����ϴ�." << std::endl;
			throw LSRTL_THIS_LOYAL_METHOD;
			T:
			assembly.push_back("push " + t);
		}
#else
		for(auto& t : injas)
			assembly.push_back("push " + trim(t));
#endif
	}

	// call �Լ��̸�
	assembly.push_back("call " + fname);
}

//
//	@brief �� �Լ��� Call�� ���� ���� �� call�� �м��մϴ�. �� �� ���ڿ� �����մϴ�.
//
//	@param assembly		����� ����
//	@param iname		�����������̸�
//	@param fname		�Լ��̸�
//	@param finja		�Լ�����
//
void LSC_Call(std::vector<std::string>& assembly, std::string iname, std::string fname, std::string finja
#ifndef _NOERROR
	, std::vector<rtl_cal> rtl
#endif
	)
{
	// ���ڴ� ������ ���ں��� �ִ´�. \
				����*������ ���� ǥ���� factor���� inja�� �ƴմϴ�.
	std::vector<std::string> injas;

	if(!finja.compare(""))
	{
		assembly.push_back("call " + fname);
		return;
	}
	
	if (!LSC_Call_IT(finja))
		assembly.push_back("push " + trim(finja));
	else
	{
		injas = split(finja, ",");
		std::reverse(injas.begin(), injas.end());
#ifndef _NOERROR
		for(auto& t : injas)
		{
			t = trim(t);
			for (auto& ta : rtl)
				if (ta.b == t)
					goto T;
			std::cout << "	Error LS0002: ���� '" << t << "'�� ã�� �� �����ϴ�." << std::endl;
			throw LSRTL_THIS_LOYAL_METHOD;
			T:
			assembly.push_back("push " + t);
		}
#else
		for(auto& t : injas)
			assembly.push_back("push " + trim(t));
#endif
	}

	// call �Լ��̸�
	assembly.push_back("call " + fname);
	
#ifndef _NOERROR
	for (auto& t : rtl)
		if (t.b == iname)
			goto NERR;
	std::cout << "	Error LS0001: ���� '" << iname << "'�� ã�� �� �����ϴ�." << std::endl;
	throw LSRTL_THIS_METHOD;
	NERR:
#endif

	// mov ���������� ���ϰ�
	assembly.push_back("mov " + iname + " " + "#ret");
}

//
//	@brief �� �Լ��� ���ڴ��Կ� ���� �Լ��Դϴ�.
//
//	@param assembly		����� ����
//	@param iname		�����������̸�
//	@param value		��
//
void LSC_Equal(std::vector<std::string>& assembly, std::string iname, std::string value
#ifndef _NOERROR
	, std::vector<rtl_cal> rtl
#endif
	)
{
#ifndef _NOERROR
	for (auto& t : rtl)
		if (t.b == iname)
			goto NERR;
	std::cout << "	Error LS0001: ���� '" << iname << "'�� ã�� �� �����ϴ�." << std::endl;
	throw LSRTL_THIS_METHOD;
	NERR:
#endif

	if (trim(value) == "")
	{
		assembly.push_back("mov " + iname + " $2");
		return;
	}

	assembly.push_back("mov " + iname + " " + trim(value));
}

//
//	@brief �� �Լ��� �������� ����մϴ�.
//
//	@param value		������ ������
//
std::string LSCP_Jkl(std::vector<std::string> assembly, std::string value)
{
	// ���Խ� : (\d+)\s*([\+\-\^\*\/])\s*(\d+)
	// ĸ�� : ��, ��ȣ, ��
#ifdef _DEBUG
	std::tr1::regex JklS1( R"((\d+)\s*([\+\-\^\*\/\&\|])\s*(\d+))" );
	std::tr1::regex JklS3( R"(([\+\-\^\*\/\&\|])\s*(\d+))" );
	std::tr1::smatch JklS2;
#endif
	if(std::tr1::regex_search(trim(value), JklS2, JklS1)){
		std::string tmp;
		switch(JklS2[2].str()[0])
			{
		case '+':
			tmp = std::to_string(std::stoi(JklS2[1].str()) + std::stoi(JklS2[3].str()));
			break;
		case '-':
			tmp = std::to_string(std::stoi(JklS2[1].str()) - std::stoi(JklS2[3].str()));
			break;
		case '*':
			tmp = std::to_string(std::stoi(JklS2[1].str()) * std::stoi(JklS2[3].str()));
			break;
		case '/':
			tmp = std::to_string(std::stoi(JklS2[1].str()) / std::stoi(JklS2[3].str()));
			break;
		case '^':
			tmp = std::to_string(std::stoi(JklS2[1].str()) ^ std::stoi(JklS2[3].str()));
			break;
		case '&':
			tmp = std::to_string(std::stoi(JklS2[1].str()) & std::stoi(JklS2[3].str()));
			break;
		case '|':
			tmp = std::to_string(std::stoi(JklS2[1].str()) | std::stoi(JklS2[3].str()));
			break;
			}
		// $1 $2 $3
		/*std::string::size_type offset = 0;
		offset = value.find(tmp, offset);
		value.replace(offset, tmp.length(), "");*/
		value = std::tr1::regex_replace(value, JklS1, tmp);
		return LSCP_Jkl(assembly, value);
		}
	else if(std::tr1::regex_search(trim(value), JklS2, JklS3)){
		switch(JklS2[1].str()[0])
			{
		case '+':
			assembly.push_back("add $l " + std::stoi(JklS2[2].str()));
			break;
		case '-':
			assembly.push_back("sub $l " + std::stoi(JklS2[2].str()));
			break;
		case '*':
			assembly.push_back("mul $l " + std::stoi(JklS2[2].str()));
			break;
		case '/':
			assembly.push_back("div $l " + std::stoi(JklS2[2].str()));
			break;
		case '^':
			assembly.push_back("xor $l " + std::stoi(JklS2[2].str()));
			break;
		case '&':
			assembly.push_back("and $l " + std::stoi(JklS2[2].str()));
			break;
		case '|':
			assembly.push_back("or $l " + std::stoi(JklS2[2].str()));
			break;
			}
		value = "";
		}
	
	return value;
}

//
//	@brief �� �Լ��� �������� ����մϴ�.
//
//	@param assembly		����� ����
//	@param value		������ ������
//	@param iname		���Ե� �μ� �̸�
//	@param rtl			rtl ����
//
std::string LSCP_Jkl(std::vector<std::string>& assembly, std::string value, std::string iname, std::vector<rtl_cal> rtl)
{
	// ���Խ� : ([a-zA-Z]+)\s*([\+\-\^\*\/\&\|])\s*(\d+)
	// ĸ�� : �μ�, ��ȣ, ��
#ifdef _DEBUG
	std::tr1::regex S1( R"(([a-zA-Z_]+)\s*([\+\-\^\*\/\&\|])\s*(\d+))" );
	std::tr1::smatch S2;
#endif
	if(std::tr1::regex_search(trim(value), S2, S1)){
		std::string tmp;
		assembly.push_back("mov $l " + S2[1].str());
		switch(S2[2].str()[0])
			{
		case '+':
			for (auto& t : rtl)
				if (t.b == S2[1].str())
				{
					assembly.push_back("add $l " + S2[3].str());
					tmp = S2[0].str();
					break;
				}
			break;
		case '-':
			for (auto& t : rtl)
				if (t.b == S2[1].str())
				{
					assembly.push_back("sub $l " + S2[3].str());
					tmp = S2[0].str();
					break;
				}
			break;
		case '*':
			for (auto& t : rtl)
				if (t.b == S2[1].str())
				{
					assembly.push_back("mul $l " + S2[3].str());
					tmp = S2[0].str();
					break;
				}
			break;
		case '/':
			for (auto& t : rtl)
				if (t.b == S2[1].str())
				{
					assembly.push_back("div $l " + S2[3].str());
					tmp = S2[0].str();
					break;
				}
			break;
		case '^':
			for (auto& t : rtl)
				if (t.b == S2[1].str())
				{
					assembly.push_back("xor $l " + S2[3].str());
					tmp = S2[0].str();
					break;
				}
			break;
		case '&':
			for (auto& t : rtl)
				if (t.b == S2[1].str())
				{
					assembly.push_back("and $l " + S2[3].str());
					tmp = S2[0].str();
					break;
				}
			break;
		case '|':
			for (auto& t : rtl)
				if (t.b == S2[1].str())
				{
					assembly.push_back("or $l " + S2[3].str());
					tmp = S2[0].str();
					break;
				}
			break;
			}
		assembly.push_back("mov $2 $l");
		std::string::size_type offset = 0;
		offset = value.find(tmp, offset);
		value.replace(offset, tmp.length(), "");
		//value = std::tr1::regex_replace(value, S1, tmp);
		return LSCP_Jkl(assembly, value, iname, rtl);
		}

	// ���Խ� : (\d+)\s*([\+\-\^\*\/\&\|])\s*([a-zA-Z]+)
	// ĸ�� : ��, ��ȣ, �μ�
#ifdef _DEBUG
	std::tr1::regex LS1( R"((\d+)\s*([\+\-\^\*\/\&\|])\s*([a-zA-Z_]+))" );
	std::tr1::smatch LS2;
#endif
	if(std::tr1::regex_search(trim(value), LS2, LS1)){
		std::string tmp;
		assembly.push_back("mov $l " + LS2[1].str());
		switch(LS2[2].str()[0])
			{
		case '+':
			for (auto& t : rtl)
				if (t.b == LS2[3].str())
				{
					assembly.push_back("add $l " + LS2[3].str());
					tmp = LS2[0].str();
					break;
				}
			break;
		case '-':
			for (auto& t : rtl)
				if (t.b == LS2[3].str())
				{
					assembly.push_back("sub $l " + LS2[3].str());
					tmp = LS2[0].str();
					break;
				}
			break;
		case '*':
			for (auto& t : rtl)
				if (t.b == LS2[3].str())
				{
					assembly.push_back("mul $l " + LS2[3].str());
					tmp = LS2[0].str();
					break;
				}
			break;
		case '/':
			for (auto& t : rtl)
				if (t.b == LS2[3].str())
				{
					assembly.push_back("div $l " + LS2[3].str());
					tmp = LS2[0].str();
					break;
				}
			break;
		case '^':
			for (auto& t : rtl)
				if (t.b == LS2[3].str())
				{
					assembly.push_back("xor $l " + LS2[3].str());
					tmp = LS2[0].str();
					break;
				}
			break;
		case '&':
			for (auto& t : rtl)
				if (t.b == LS2[3].str())
				{
					assembly.push_back("and $l " + LS2[3].str());
					tmp = LS2[0].str();
					break;
				}
			break;
		case '|':
			for (auto& t : rtl)
				if (t.b == LS2[3].str())
				{
					assembly.push_back("or $l " + LS2[3].str());
					tmp = LS2[0].str();
					break;
				}
			break;
			}
		assembly.push_back("mov $2 $l");
		std::string::size_type offset = 0;
		offset = value.find(tmp, offset);
		value.replace(offset, tmp.length(), "");
		//value = std::tr1::regex_replace(value, S1, tmp);
		return LSCP_Jkl(assembly, value, iname, rtl);
		}

	// ���Խ� : ([a-zA-Z]+)\s*([\+\-\^\*\/\&\|])\s*([a-zA-Z]+)
	// ĸ�� : �μ�, ��ȣ, �μ�
#ifdef _DEBUG
	std::tr1::regex RS1( R"(([a-zA-Z_]+)\s*([\+\-\^\*\/\&\|])\s*([a-zA-Z_]+))" );
	std::tr1::smatch RS2;
#endif
	if(std::tr1::regex_search(trim(value), RS2, RS1)){
		std::string tmp;
		assembly.push_back("mov $l " + RS2[1].str());
		switch(RS2[2].str()[0])
			{
		case '+':
			for (auto& t : rtl)
				if (t.b == RS2[1].str())
				{
					assembly.push_back("add $l " + RS2[3].str());
					tmp = RS2[0].str();
					break;
				}
			break;
		case '-':
			for (auto& t : rtl)
				if (t.b == RS2[1].str())
				{
					assembly.push_back("sub $l " + RS2[3].str());
					tmp = RS2[0].str();
					break;
				}
			break;
		case '*':
			for (auto& t : rtl)
				if (t.b == RS2[1].str())
				{
					assembly.push_back("mul $l " + RS2[3].str());
					tmp = RS2[0].str();
					break;
				}
			break;
		case '/':
			for (auto& t : rtl)
				if (t.b == RS2[1].str())
				{
					assembly.push_back("div $l " + RS2[3].str());
					tmp = RS2[0].str();
					break;
				}
			break;
		case '^':
			for (auto& t : rtl)
				if (t.b == RS2[1].str())
				{
					assembly.push_back("xor $l " + RS2[3].str());
					tmp = RS2[0].str();
					break;
				}
			break;
		case '&':
			for (auto& t : rtl)
				if (t.b == RS2[1].str())
				{
					assembly.push_back("and $l " + RS2[3].str());
					tmp = RS2[0].str();
					break;
				}
			break;
		case '|':
			for (auto& t : rtl)
				if (t.b == RS2[1].str())
				{
					assembly.push_back("or $l " + RS2[3].str());
					tmp = RS2[0].str();
					break;
				}
			break;
			}
		assembly.push_back("mov $2 $l");
		std::string::size_type offset = 0;
		offset = value.find(tmp, offset);
		value.replace(offset, tmp.length(), "");
		//value = std::tr1::regex_replace(value, S1, tmp);
		return LSCP_Jkl(assembly, value, iname, rtl);
		}
	return LSCP_Jkl(assembly, value);
}

//
//	@brief �� �Լ��� ������������ �м��մϴ�.
//
//	@param assembly		����� ����
//	@param value		������ ������
//
std::string LSCP_aIf(std::vector<std::string>& assembly, std::string value
#ifndef _NOERROR
	, std::vector<rtl_cal> rtl
#endif
	)
{
	// �� ���ǹ��� 4���Դϴ�.
	// <��> ��ȣ <��>(������)
	// <��> ��ȣ <�μ�>
	// <�μ�> ��ȣ <��>
	// <�μ�> ��ȣ <�μ�>
	
	// ���Խ� : (\d+|\w+)\s*([\<\>\=][\>\=]?)\s*(\d+|\w+)
	// ĸ�� : �μ�, ��ȣ, �μ�
#ifdef _DEBUG
	std::tr1::regex I1( R"(([\w\d]+)\s*([\<\>\=][\>\=]?)\s*([\w\d]+))" );
	std::tr1::smatch I2;
#endif
	if(std::tr1::regex_search(trim(value), I2, I1)){
		assembly.push_back("cmpa " + I2[1].str() + " " + I2[3].str());
		if (I2[2].str() == ">")
			return "ja";
		else if (I2[2].str() == ">=")
			return "jae";
		else if (I2[2].str() == "<")
			return "jb";
		else if (I2[2].str() == "<=")
			return "jbe";
		else if (I2[2].str() == "==")
			return "je";
		else if (I2[2].str() == "<>")
			return "jne";
		}

	return "jmp";
}


#endif