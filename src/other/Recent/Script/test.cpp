/*************************************************************************

   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:

   test.cpp

Project:

	RollRat Script Parser

------
   AUTHOR: HyunJun Jeong  2015-08-14

***************************************************************************/

#include "LowRegularExpressionIs.h"


#include <regex>
#include <string>
#include <algorithm>
#include <iostream>
#include "WideCharToUnicode.h"

#include "NonOverlappedRandomNumberGenerator.h"

#include "CString.h"

#include "UltimateBinaryTree.h"

#include "StringGenetic.h"

int main()
{
	/*Script::CString cs("rollrat");

	cs.Append("software");*/

	//Script::LowRegularExpressionIs lrei("([\\d]+|rollrat|soft)");
	/*Script::LowRegularExpressionIs lre("soft");

	NonOverlappedRandomNumberGenerator nolrng(0, 10000);

	for (int i = 0; i < nolrng.size(); i++)
		std::cout << nolrng[i] << std::endl;

	lre.MatchIs("soft");*/

	/*Script::CString cs("rotcrotcrotc  ");
	cs.Split("tc");
	Script::CString re = cs.Replace("ro", "12", 2);
	std::cout << *re;*/
	
	//CString cs((long double)123456.123456);
	////Script::CString cs("12346.456");
	//std::cout.precision(15);
	//std::cout << (cs.ToDouble());

	/*WideCharToUnicde wctu;
	std::cout << wctu.Trandform(_TEXT("유니코드 테스트")) << std::endl;
	
	std::wcout.imbue(std::locale("kor"));
	std::wcout << wctu.InverseTransform(wctu.Trandform(_TEXT("유니코드 테스트")));
	
	int i = 0;
	putchar("FFFFFEDCBAA"[int(i*0.09)]);

	tree<std::string> tree;
	tree.postorder_travel([] (std::string) {});*/

	// 3%
	char text[] = "rollrat";
	StringGeneticField<sizeof(text) / sizeof(text[0]) - 1, 10, 100, 100> sgf(text);

	do {
		//sgf.print_all();
		sgf.evolution();
	} while( !sgf.check_generation() );
	sgf.print_all();
	std::cout << std::endl << "Evolution Count: " << sgf.get_generation();
}