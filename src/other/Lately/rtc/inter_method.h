/*************************************************************************
 *
 *					  ROLLRAT SOFTWARE LIBRARY
 *						INTER METHOD
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *CREATION : 2014-10-24
 *************************************************************************/

#ifndef _INTER_METHOD_
#define _INTER_METHOD_

#include "string.h"
#include "tree.h"
#include "serve_method.h"
#include <hash_map>
#include <vector>
#include <stack>
#include <string>
#include <Windows.h>

		// INTERCODE GENERATOR for linked_rvalue with optimize
std::vector<std::string> _optimize_intercode_generator2(tree<std::string> tree)
	{
	std::stack<std::string> var;
	std::vector<std::string> tdup1, tdup2, code;
	int count = 0;
	bool pref = false;
	
	auto is_number=[](std::string cptr)->bool
		{
		for (const char *ptr = cptr.c_str(); 
			('0' <= *ptr && *ptr <= '9') || *ptr == '.'; ptr++)
			if(!*(ptr+1))
				return true;
		return false;
		};

	postorder_travel([&](std::string str)
		{
		if(::strchr("+-*/&^|%<>!~", str[0]))
			{
			std::string rvalue("$t" + std::to_string(count) + "_=");
			if (!var.empty())
				{
				bool second_number = is_number(var.top());
				std::string temp = var.top();
				var.pop();
				if (!var.empty()) {
					if(is_number(var.top()) && second_number) {
						long long v1 = std::stoll(temp), v2 = std::stoll(var.top()), v3=0.0f;
						switch(*str.c_str()) {
						case '+': v3 = v2 + v1; break;
						case '-': v3 = v2 - v1; break;
						case '*': v3 = v2 * v1; break;
						case '/': v3 = v2 / v1; break;
						case '&': v3 = v2 & v1; break;
						case '^': v3 = v2 ^ v1; break;
						case '|': v3 = v2 | v1; break;
						case '%': v3 = v2 % v1; break;
						default:
							goto JUST_EXCUATE;
						}
						var.push(std::to_string(v3));
					} else {
			JUST_EXCUATE:
						rvalue.append(var.top()+str+temp);
						var.pop();
						code.push_back(rvalue);
						var.push("$t" + std::to_string(count) + "_");
						count += 1;
						}
				} else 
					goto _LABEL_ERROR;
				}
			else
		_LABEL_ERROR:
				MessageBox(0, TEXT("Input value is incorrect. Please enter a valid expression."), TEXT("Compiler Method V1.5, _optimize_intercode_generator2"), MB_OK | MB_ICONERROR);
			}
		else
			if(is_number(str))
				var.push(str);
			else {
				bool t = false;
				for(int i = 0; i < tdup1.size(); i++)
					if(tdup2[i] == str) {
						var.push(tdup1[i]);
						t = true;
						break;
					}
				if(!t) {
					std::string rvalue("$t" + std::to_string(count) + "_=" + str);
					var.push("$t" + std::to_string(count) + "_");
					tdup1.push_back(var.top());
					tdup2.push_back(str);
					code.push_back(rvalue);
					count += 1;
				}
			}
		}
		, tree.travel());
	if (code.empty())
		code.push_back(var.top());
	return code;
	}

#endif