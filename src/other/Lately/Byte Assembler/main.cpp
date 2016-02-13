/*
ROLLRAT BYTE ASSEMBLER 2014

    공동 라이센스 계약 참고지침

라이센스 : 2014.09.19
만료시간 : 2016.09.19
이 소스코드는 라이브러리화 되어서는 안되며 반드시 프로그램 내에 상속
되어야한다. 개발자 동의없이 사용, 수정, 배포 등 저작권 관련 법률에
위반되는 행위를 할 시 법적으로 처벌받을 수 있으며 기타 범법행위들을
모두 금지한다.
이 프로젝트는 바이트 코드를 제작하기위한 어셈블러로 MASM, TASM, NA
SM, GNU ASSEMBLER 등 코드 어셈블러와는 다른 용도이며 CPU상에선 동
작하지 않고 특정프로그램에서 동작하는 코드 어셈블리조각이다. 위 법률
위반사항을 제하고선 모든 행위는 가능하다.
임시 라이센스기간은 2년이고, 라이센스가 만료되면 오픈소스 등의 용도로
사용가능하다. 기간시는 0시로 정하며 그 이전의 모든 행위는 위 라이센스
계약에 명시된대로 이행된다.
위 내용은 절차상 요구되는 라이센스 항목으로 자세한 설명은 별도의 라
이센스 설명을 참조하시오.
이 사항은 이 프로젝트의 모든 파일에 적용됨.
*********************************************************/

#pragma optimize("", off)

#include "tasm_m.h"
template<class _Ty>
class Timera
	{
public:
	LARGE_INTEGER str, fre, fin;
	
	inline void start()
		{
		QueryPerformanceFrequency(&fre);
		QueryPerformanceCounter(&str);
		}

	inline void finish()
		{
		QueryPerformanceCounter(&fin);
		}
	
	inline _Ty operator*()
		{
		return (_Ty)(_Ty(fin.QuadPart - str.QuadPart) * 1000000 / _Ty(fre.QuadPart));
		}

	};

int main(int argc, char * argv[])
{
	Timera<double> taa;
	taa.start();
	std::cout << "             %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl
			  << "             %                                                     %" << std::endl
			  << "             %     ROLLRAT TETO. BYTE ASSEMBLER   0.1201.1.1.0     %" << std::endl
			  << "             %                                                     %" << std::endl
			  << "             %     COPYRIGHT ROLLRAT(C) 2014.                      %" << std::endl
			  << "             %                                                     %" << std::endl
			  << "             %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;
	
	taa.finish();
	std::cout << *taa;


	std::vector<std::string> s;
	s.push_back("pusha");
	s.push_back("mov eax, 2");
	s.push_back("add eax, 3");
	s.push_back("mov esi, eax");
	s.push_back("popa");
	std::vector<BYTE> byte = assemble(s, TASM_OPTION_STDR);

	for(auto s : byte)
	{
		std::cout << std::hex << (int)s << " ";
	}

	std::cout << std::endl << std::bitset<8>(bit_switch(3));

#ifndef _DEBUG
	if (argc != 3)
	{
		std::cout << "T : <target> <save>" << std::endl;
		return 0;
	}
	std::ifstream inf(argv[1], std::ios::in);
	std::ofstream onf(argv[2], std::ios::out);
#else
	std::string redfile;
	std::cout << "openfilename : ";
	std::cin >> redfile;
	std::ifstream inf(redfile, std::ios::in);

	if (inf.fail()) {
		std::cerr << "Unable to open file for reading!" << std::endl;
		return 1;
	}

	std::vector<std::string> str;
	int a = 0;

	while(!inf.eof())
	{
		char size_f[256];
		inf.getline(size_f, 256);
		str.push_back(size_f);
		a++;
	}

	inf.close();

	std::cout << "Lines : " << a << std::endl;

	std::string wrtfile;
	std::cout << "savefilename : " << std::endl;
	std::cin >> wrtfile;
	std::ofstream onf(wrtfile, std::ios::binary);
#endif


}