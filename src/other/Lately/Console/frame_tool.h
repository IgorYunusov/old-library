/*************************************************************************
 *
 *					  ROLLRAT SOFTWARE LIBRARY
 *						ULTRIMATE TREE CLASS-STL STYLE
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _FRAME_TOOL_
#define _FRAME_TOOL_

#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <map>

void getch_c(std::string& tmp)
{
	char ch=0;
	std::cout << "# password : ";
	while(ch != 13){
		tmp.push_back(ch = _getch());
		//cout << '*';
	}
	tmp.pop_back();
}

void out_rootcontext(std::string name, bool is_root = false)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "[";
	SetConsoleTextAttribute(hConsole, 10);
	std::cout << name;
	SetConsoleTextAttribute(hConsole, 7);
	std::cout << "@";
	if (is_root) {
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << "root ~";
	} else {
		SetConsoleTextAttribute(hConsole, 6);
		std::cout << "guest ~";
	}
	SetConsoleTextAttribute(hConsole, 7);
	std::cout << "]$ ";
}

void in_command(char cmd[256])
{
	// c style : fgets (cmd, 256, stdin);
	std::cin.ignore(std::cin.rdbuf()->in_avail(),'\n');
	std::cin.getline(cmd, 256);
}

void get_command_line(std::vector<std::string>& vec, std::string cmd)
{
	std::string stream;
	bool wh_skip = false;
	for(auto tmp : cmd)
	{
		if (tmp == '\"')
			wh_skip = !wh_skip;
		else if (tmp == ' ' && !wh_skip)
			vec.push_back(stream), stream.clear();
		else
			stream.push_back(tmp);
	}
	vec.push_back(stream);
}


#endif