/*
ROLLRAT BYTE ASSEMBLER 2014

    ���� ���̼��� ��� ������ħ

���̼��� : 2014.09.19
����ð� : 2016.09.19
�� �ҽ��ڵ�� ���̺귯��ȭ �Ǿ�� �ȵǸ� �ݵ�� ���α׷� ���� ���
�Ǿ���Ѵ�. ������ ���Ǿ��� ���, ����, ���� �� ���۱� ���� ������
���ݵǴ� ������ �� �� �������� ó������ �� ������ ��Ÿ ������������
��� �����Ѵ�.
�� ������Ʈ�� ����Ʈ �ڵ带 �����ϱ����� ������� MASM, TASM, NA
SM, GNU ASSEMBLER �� �ڵ� ������ʹ� �ٸ� �뵵�̸� CPU�󿡼� ��
������ �ʰ� Ư�����α׷����� �����ϴ� �ڵ� ����������̴�. �� ����
���ݻ����� ���ϰ� ��� ������ �����ϴ�.
�ӽ� ���̼����Ⱓ�� 2���̰�, ���̼����� ����Ǹ� ���¼ҽ� ���� �뵵��
��밡���ϴ�. �Ⱓ�ô� 0�÷� ���ϸ� �� ������ ��� ������ �� ���̼���
��࿡ ��õȴ�� ����ȴ�.
�� ������ ������ �䱸�Ǵ� ���̼��� �׸����� �ڼ��� ������ ������ ��
�̼��� ������ �����Ͻÿ�.
�� ������ �� ������Ʈ�� ��� ���Ͽ� �����.
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