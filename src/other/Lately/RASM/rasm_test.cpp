/*************************************************************************
 *
 * FILE NAME : rasm.cpp
 *
 * ROLLRAT SOFTWARE IA-32 SHELL ASSEMBLER(RASM)
 *
 * VERSION  : 0.0.1031.4
 *
 * LANGUAGE : Macro Assembly, C++
 * COMPILER : Microsoft Macro Assembler v12.00.30501.0
 *            ISO/C++ 11-Microsoft C/C++ Optimizer Compiler 18.00.30501
 * CREATION : 2014.10.12
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com, rollrat.software@gmail.com
 *
 * (C) Copyright 2014. rollrat. All Rights Reserved
 *
 **************************************************************************/


#include <iostream>
#include <fstream>
#include <random>

#include "rasm.h"
#include "line.h"
#include "timer.h"

void *rasm_test(std::vector<BYTE> xtarr)
{
	HANDLE mem_handle = CreateFileMapping( 
			INVALID_HANDLE_VALUE, 
			NULL, 
			PAGE_EXECUTE_READWRITE, 
			0,  
			xtarr.size(), 
			NULL);
	
	void * function = (void *)(MapViewOfFile(
			mem_handle,
			FILE_MAP_ALL_ACCESS | FILE_MAP_EXECUTE,
			0,
			0,
			xtarr.size()));
	BYTE* byteset= new BYTE[xtarr.size()], *ptr=byteset;
	//std::copy(xtarr.begin(), xtarr.end(), byteset);
	auto begin = xtarr.begin();
	for (; begin != xtarr.end(); ++ptr, ++begin)
		*ptr = *begin;
	memcpy(function, byteset, xtarr.size());
	((void(*)())function)();
	return function;
}

OPTION argument_parsing(int argc, char *argv[])
{
	OPTION option={false,};
	
	if(argc < 3){
		option.error = true, 
		option.serror = "Argument count should be more two argument for correct execution!";
		goto ENDCS;}
	else if(argc == 3){
		option.standard = true;
		option.address = argv[1];
		option.save = argv[2];
		goto ENDCS;}
	else
		{
		}

ENDCS:
	return option;
}

int main(int argc, char *argv[])
{

//#if _DEBUGGING_MODE == 1
//	std::vector<BYTE> xtarr;
//	xtarr.push_back(0x81);
//	xtarr.push_back(0x45);
//	xtarr.push_back(~0x08+1);
//#endif
////////////////////////////////////////////////////

#if _DEBUGGING_MODE == 1
	build_count();
	std::cout << "Build : " << get_build_count() << std::endl << std::endl;
#endif

//////////////////////////////////////////////////// FILE INPUT
	OPTION option;
	((void(*)())rasm_test(assemble_code("ret 8",option)))();

	std::cout << "RollRat IA-32 Shell Assembler¢â Version 0.0.1031.4" << std::endl 
			  << "Copyright (C) rollrat. All rights reserved." << std::endl;
	
	option = argument_parsing(argc, argv);
	if (option.error) {
		std::cerr << std::endl  << "Error : " << std::endl <<
			option.serror << std::endl << std::endl;
		return 1;
	}
	
	std::ifstream inf(option.address, std::ios::in);
	if (inf.fail()) {
		std::cerr << std::endl  << "Error : " << std::endl <<
			"Unable to open file for reading!" << std::endl << std::endl;
		return 1;
	}

	std::vector<std::string> str;
	int line = 0;

	while(!inf.eof())
	{
		char size_f[256];
		inf.getline(size_f, 256);
		str.push_back(size_f);
		line++;
	}

	inf.close();

////////////////////////////////////////////////////
	
//#if _DEBUGGING_MODE == 1
////	std::vector<BYTE> xtarr;
//	xtarr.push_back(0x81);
//	xtarr.push_back(0x45);
//	xtarr.push_back(3);
//	((void(*)())rasm_test(xtarr))();
//#endif

//////////////////////////////////////////////////// FILE OUTPUT

	std::vector<BYTE> arrbyte;
	arrbyte = assemble_code(str, option);

	std::ofstream onf(option.save, std::ios::out);
	for(auto byte : arrbyte)
		onf << byte;

////////////////////////////////////////////////////
	
	onf.close();

	std::cout << std::endl <<
		"Assembly Complete!";

	return 0;

////////////////////////////////////////////////////
}