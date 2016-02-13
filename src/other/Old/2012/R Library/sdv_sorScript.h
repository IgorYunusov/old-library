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
// |�߽߰� asdb ���� 5����� �ٽ��б�

// asdfbcx(asdfet)?
// (�߽߰� asdfbcx ���� x��ġ ����� ��ȣ ���� ���� ������
// )�߽߰� ����. ? �߽߰� ������ ��ȣ�� ���Դ��� Ȯ���� ��� ����

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

void open()	// open ����
{

}

void close()
{

}

#endif