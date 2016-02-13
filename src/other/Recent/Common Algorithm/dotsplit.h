/*************************************************************************

   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:

   dotsplit.h

Project:

   마침표를 중심으로 글자를 나눔

------
   AUTHOR: HyunJun Jeong  2015-07-18

***************************************************************************/

#ifndef _DOTSPLIT_
#define _DOTSPLIT_

#include <vector>
#include <string>
#include "mutable_handler.h"

std::vector<std::string> dot_split(std::string str, std::string src = ".")
{
	const char *str_t = str.c_str();
	size_t len = CPMC::adjust::DropContainsLength(str_t, src.c_str())+1;
	char **ptr = CPMC::adjust::DropSplit(str_t, src.c_str());
	std::vector<std::string> ret;
	for (int i = 0; i < len; i++)
		ret.push_back(ptr[i]);
	return ret;
}
/****

	이 메서드는 참조형 구문 분석에 적합합니다. 예를들어 point.x를 
	point와 x로 서로 분리합니다. 이는 메서드의 구조체에 x와 y가 
	포함될 경우 이벤트가 발생합니다. 구조체는 다음과 같이 생성합니다.

	format file:
		/ifs@exist/structure{pointer}
			/create@structure{point{x,y}}
		/eif

	source file:
		pointer.x = 0

****/
typedef struct _ts_split_method_ {
}	split_method, split_method_ptr;

split_method_ptr split(std::string str, std::string src, int option)
{
}

#endif
