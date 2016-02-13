/*************************************************************************
 *
 *                    ROLLRAT AUTO PERSONA VERBOTER LIBROFEX
 *
 *                         (C) Copyright 2009-2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#if !defined(_sdv_sorScript_)
#define _sdv_sorScript_

#include "vector.h"		// stack
#include "RegexUtil.h"

#define reg_parse_error			0x00
#define reg_parse_default		0x01
#define reg_parse_terminal		0x03

inline int regexRegParseGetTypeOf(const char x)
{
	if(((('0' <= x) && (x <= '9')) || (('a' <= x) 
		&& (x <= 'z')) || (('A' <= x) && (x <= 'Z'))) || x == '_' || r_util::isspace(x))
			return reg_parse_default;
	if(r_util::strchr(x, "[]$\".<>:?\\!@#%^&*()-+=|{}~"))
		return reg_parse_terminal; 
	return reg_parse_error;
}

typedef struct __recursive_01 {
	struct __recursive_01* left;
	struct __recursive_01* right;
	int position;
	char data;
}	recursive_data_unit, *ptr_recursive_data_unit;

// asdb|sdfvb
// |발견시 asdb 묶고 5저장뒤 다시읽기

// asdfbcx(asdfet)?
// (발견시 asdfbcx 묶고 x위치 저장뒤 괄호 안을 전부 읽은후
// )발견시 닫음. ? 발견시 그전에 괄호가 나왔는지 확인후 재귀 돌림

const char *token;
ptr_recursive_data_unit recur;
ptr_recursive_data_unit head;
int position;

ptr_recursive_data_unit node_make() {return new recursive_data_unit;}
void set_text(const char *recurse) { token = recurse; }
void next() { token++; }
void init() {
	position = 0;
	head = node_make();
	recur = node_make();
	head->right = recur;
}

void open()	// open 유닛
{

}

void close()
{

}

#endif