/*************************************************************************
 *
 *					  ROLLRAT SOFTWARE LIBRARY
 *						OPTIMIZE METHOD
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _INTER_METHOD_
#define _INTER_METHOD_

#include "tree.h"
#include "serve_method.h"
#include <vector>
#include <stack>
#include <string>

void _optimize_intercode2(std::vector<std::string> intercode)
	{
	std::vector<std::string> src;	// 소스
	std::vector<std::string> dest;	// 대상
	std::vector<std::string> code;
	auto is_operator=[](char ptr)->bool
		{
		if(::strchr("+-*/&^|%<>!~", ptr))
			return true;
		return false;
		};
	for(std::string temp : intercode)
		{
		std::vector<std::string> x(split(temp, "="));
		bool this_nop=true;
		for (const char *ptr = x[1].c_str(); !is_operator(*ptr); ptr++)
			if (!ptr)
			{
				src.push_back(x[0]), dest.push_back(x[1]);
				this_nop = false;
				break;
			}
		if(this_nop)
			for(int i = 0; i < src.size(); i++)
				{
				//temp.replace(src[i], dest[i]);
				}

		}
	}


#endif