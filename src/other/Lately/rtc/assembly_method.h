/*************************************************************************
 *
 *					  ROLLRAT SOFTWARE LIBRARY
 *						ASSEBMLY METHOD
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *CREATION : 2014-10-31
 *************************************************************************/

#ifndef _ASSEMBLY_METHOD_
#define _ASSEMBLY_METHOD_

#include "rasm_util.hh"
#include "string.h"
#include <Windows.h>
#include <vector>
#include <stack>
#include <string>
#include <map>

char *assembly_text[0x7f] = {
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0, /* '!' */
	0, /* '"' */
	0, /* '#' */
	0, /* '$' */
		"mod", /* '%' */
		"and", /* '&' */
	0, /* ''' */
	0, /* '(' */
	0, /* ')' */
		"imul", /* '*' */
		"add", /* '+' */
	0, /* ',' */
		"sub", /* '-' */
	0, /* '.' */
		"idiv", /* '/' */
	0, /* '0' */
	0, /* '1' */
	0, /* '2' */
	0, /* '3' */
	0, /* '4' */
	0, /* '5' */
	0, /* '6' */
	0, /* '7' */
	0, /* '8' */
	0, /* '9' */
	0, /* ':' */
	0, /* ';' */
		"shl", /* '<' */
	0, /* '=' */
		"shr", /* '>' */
	0, /* '?' */
	0, /* '@' */
	0, /* 'A' */
	0, /* 'B' */
	0, /* 'C' */
	0, /* 'D' */
	0, /* 'E' */
	0, /* 'F' */
	0, /* 'G' */
	0, /* 'H' */
	0, /* 'I' */
	0, /* 'J' */
	0, /* 'K' */
	0, /* 'L' */
	0, /* 'M' */
	0, /* 'N' */
	0, /* 'O' */
	0, /* 'P' */
	0, /* 'Q' */
	0, /* 'R' */
	0, /* 'S' */
	0, /* 'T' */
	0, /* 'U' */
	0, /* 'V' */
	0, /* 'W' */
	0, /* 'X' */
	0, /* 'Y' */
	0, /* 'Z' */
	0, /* '[' */
	0, /* '\' */
	0, /* ']' */
		"xor", /* '^' */
	0, /* '_' */
	0, /* '`' */
	0, /* 'a' */
	0, /* 'b' */
	0, /* 'c' */
	0, /* 'd' */
	0, /* 'e' */
	0, /* 'f' */
	0, /* 'g' */
	0, /* 'h' */
	0, /* 'i' */
	0, /* 'j' */
	0, /* 'k' */
	0, /* 'l' */
	0, /* 'm' */
	0, /* 'n' */
	0, /* 'o' */
	0, /* 'p' */
	0, /* 'q' */
	0, /* 'r' */
	0, /* 's' */
	0, /* 't' */
	0, /* 'u' */
	0, /* 'v' */
	0, /* 'w' */
	0, /* 'x' */
	0, /* 'y' */
	0, /* 'z' */
	0, /* '{' */
		"or", /* '|' */
	0, /* '}' */
	0, /* '~' */};

typedef std::map<std::string, std::string>::value_type map_var;

std::vector<std::string> _assembly_x86_macrostyle2(std::vector<std::string> intercode)
	{
	std::vector<std::string> var;
	int ebp_set=4, ebp_get=4, last=intercode.size()-1;
	int intercode_pos = 0;
	std::vector<std::string> jcc_forward, jcc_reverse;
	bool eax_c=false, ecx_c=false, edx_c=false, ebx_c=false;
	std::map<std::string, std::string> map;
	
	auto is_number=[](std::string cptr)->bool {
		for (const char *ptr = cptr.c_str(); 
			('0' <= *ptr && *ptr <= '9') || *ptr == '.'; ptr++)
			if(!*(ptr+1)) return true;
		return false;
		};

	auto is_variable=[](std::string cptr)->bool {
		for (const char *ptr = cptr.c_str();
			('a' <= *ptr && *ptr <= 'z'); ptr++)
			if (!*(ptr + 1)) return true;
		return false;
		};

	auto is_direction_operator=[](char ch)->bool {
		if (::strchr("-/<>!~%", ch))
			return true;
		else if(::strchr("+*^&|", ch)) 
			return false;
		};

	auto nodupkey_delete=[&](std::string cptr){
		if (intercode.size() - 1 <= intercode_pos)
			return;
		int i = intercode_pos + 1;
		for(; i < intercode.size()-1; i++){
			String<> str(const_cast<char*>( intercode[i].c_str()));
			if (str.Contains(cptr.c_str()))
				return;
			}
		if (map[cptr] == "eax")
			eax_c = false;
		else if (map[cptr] == "ecx")
			ecx_c = false;
		else if (map[cptr] == "edx")
			edx_c = false;
		else if (map[cptr] == "ebx")
			ebx_c = false;
		};

	if(is_number(intercode[0])) {
		var.push_back("mov eax, " + stoll(intercode[0]));
		return var;
	}

	std::vector<std::string> frame;
	///////////////////////////// <!-- FRAME
	for(auto temp : intercode) {
		if(temp[0] == ':') {
			// ºÐ±â
		}
		std::vector<std::string> tsplit = split(temp, "=");
		if (is_variable(tsplit[1])) {
			map.insert(map_var(tsplit[0], "[ebp+" + std::to_string(ebp_get+=4) + "]"));
		} else {
			const char *_operator = tsplit[1].c_str();
			char _operator_x;
			bool direction;
			std::string first, second;
			for (bool exh=false; *_operator; _operator++)
				if (!::strchr("+-*/&^|%<>!~", *_operator) && !exh)
					first += *_operator;
				else if(!::strchr("+-*/&^|%<>!~", *_operator) && exh)
					second += *_operator;
				else
					exh = true, _operator_x = *_operator;
			/////////////////////////////////////////////////////////
			direction = is_direction_operator(_operator_x);
			if (is_number(first)) {
				if(!eax_c) {
					if (direction) {
						frame.push_back("mov eax, " + first);
						frame.push_back(std::string(assembly_text[_operator_x]) + " eax, " + map[second]);
					} else {
						frame.push_back("mov eax, " + map[second]);
						frame.push_back(std::string(assembly_text[_operator_x]) + " eax, " + first);
					}
					map.insert(map_var(tsplit[0], "eax"));
					eax_c = true;
				} else if(!ecx_c) {
					if (direction) {
						frame.push_back("mov ecx, " + first);
						frame.push_back(std::string(assembly_text[_operator_x]) + " ecx, " + map[second]);
					} else {
						frame.push_back("mov ecx, " + map[second]);
						frame.push_back(std::string(assembly_text[_operator_x]) + " ecx, " + first);
					}
					map.insert(map_var(tsplit[0], "ecx"));
					ecx_c = true;
				} else if(!edx_c) {
					if (direction) {
						frame.push_back("mov edx, " + first);
						frame.push_back(std::string(assembly_text[_operator_x]) + " edx, " + map[second]);
					} else {
						frame.push_back("mov edx, " + map[second]);
						frame.push_back(std::string(assembly_text[_operator_x]) + " edx, " + first);
					}
					map.insert(map_var(tsplit[0], "edx"));
					edx_c = true;
				} else if(!ebx_c) {
					if (direction) {
						frame.push_back("mov ebx, " + first);
						frame.push_back(std::string(assembly_text[_operator_x]) + " ebx, " + map[second]);
					} else {
						frame.push_back("mov ebx, " + map[second]);
						frame.push_back(std::string(assembly_text[_operator_x]) + " ebx, " + first);
					}
					map.insert(map_var(tsplit[0], "ebx"));
					ebx_c = true;
				} else {
					MessageBox(0, TEXT("Variable register is full. Please reduce the number of variables."), 
						TEXT("Compiler Method V1.5, _assembly_x86_macrostyle"), MB_OK | MB_ICONERROR);
				}
				if (last == intercode_pos)
					if(map[tsplit[0]] != "eax")
						frame.push_back("mov eax, " + map[tsplit[0]]);
				nodupkey_delete(second);
			} else if (is_number(second)) {
				if(!eax_c) {
					frame.push_back("mov eax, " + map[first]);
					frame.push_back(std::string(assembly_text[_operator_x]) + " eax, " + second);
					map.insert(map_var(tsplit[0], "eax"));
					eax_c = true;
				} else if(!ecx_c) {
					frame.push_back("mov ecx, " + map[first]);
					frame.push_back(std::string(assembly_text[_operator_x]) + " ecx, " + second);
					map.insert(map_var(tsplit[0], "ecx"));
					ecx_c = true;
				} else if(!edx_c) {
					frame.push_back("mov edx, " + map[first]);
					frame.push_back(std::string(assembly_text[_operator_x]) + " edx, " + second);
					map.insert(map_var(tsplit[0], "edx"));
					edx_c = true;
				} else if(!ebx_c) {
					frame.push_back("mov ebx, " + map[first]);
					frame.push_back(std::string(assembly_text[_operator_x]) + " ebx, " + second);
					map.insert(map_var(tsplit[0], "ebx"));
					ebx_c = true;
				} else {
					MessageBox(0, TEXT("Variable register is full. Please reduce the number of variables."), 
						TEXT("Compiler Method V1.5, _assembly_x86_macrostyle"), MB_OK | MB_ICONERROR);
				}
				if (last == intercode_pos)
					if(map[tsplit[0]] != "eax")
						frame.push_back("mov eax, " + map[tsplit[0]]);
				nodupkey_delete(first);
			} else {
				if(map[first][0] == '[') {
					if(!eax_c) {
						frame.push_back("mov eax, " + map[first]);
						eax_c = true;
						frame.push_back(std::string(assembly_text[_operator_x]) + " eax, " + map[second]);
						map.insert(map_var(tsplit[0], "eax"));
					} else if(!ecx_c) {
						frame.push_back("mov ecx, " + map[first]);
						ecx_c = true;
						frame.push_back(std::string(assembly_text[_operator_x]) + " ecx, " + map[second]);
						map.insert(map_var(tsplit[0], "ecx"));
					} else if(!edx_c) {
						frame.push_back("mov edx, " + map[first]);
						edx_c = true;
						frame.push_back(std::string(assembly_text[_operator_x]) + " edx, " + map[second]);
						map.insert(map_var(tsplit[0], "edx"));
					} else if(!ebx_c) {
						frame.push_back("mov ebx, " + map[first]);
						ebx_c = true;
						frame.push_back(std::string(assembly_text[_operator_x]) + " ebx, " + map[second]);
						map.insert(map_var(tsplit[0], "ebx"));
					} else {
						MessageBox(0, TEXT("Variable register is full. Please reduce the number of variables."), 
							TEXT("Compiler Method V1.5, _assembly_x86_macrostyle"), MB_OK | MB_ICONERROR);
					}
				} else {
					frame.push_back(std::string(assembly_text[_operator_x]) + " " + map[first] + ", " + map[second]);
					map.insert(map_var(tsplit[0], map[first]));
				}
				if (last == intercode_pos)
					if(map[tsplit[0]] != "eax")
						frame.push_back("mov eax, " + map[tsplit[0]]);
				//nodupkey_delete(first);
				nodupkey_delete(second);
			}
		}
		intercode_pos++;
	}
	///////////////////////////// FRAME-->
	var.push_back("push ebp");
	var.push_back("mov ebp, esp");
	var.push_back("push esi");
	if (ebp_set>4)
		var.push_back("sub esi, " + std::to_string(ebp_set));
	for(auto temp : frame)
		var.push_back(temp);
	var.push_back("pop esi");
	var.push_back("mov esp, ebp");
	var.push_back("pop ebp");
	var.push_back("ret " + std::to_string(ebp_get-4));
	return var;
	}

#endif