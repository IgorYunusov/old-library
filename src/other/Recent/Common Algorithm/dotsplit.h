/*************************************************************************

   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:

   dotsplit.h

Project:

   ��ħǥ�� �߽����� ���ڸ� ����

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

	�� �޼���� ������ ���� �м��� �����մϴ�. ������� point.x�� 
	point�� x�� ���� �и��մϴ�. �̴� �޼����� ����ü�� x�� y�� 
	���Ե� ��� �̺�Ʈ�� �߻��մϴ�. ����ü�� ������ ���� �����մϴ�.

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
