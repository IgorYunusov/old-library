/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   second_layer_priorty.h - [Private]

Project:

   Compiler Method Second

------
   AUTHOR: HyunJun Jeong  2015-02-23

***************************************************************************/

#ifndef _SECOND_LAYER_PRIORTY_
#define _SECOND_LAYER_PRIORTY_

#include <string>

#define priority_skip -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,\
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,\
    -1,-1,-1,-1,-1,-1,

#define priority_skip_number \
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,

#define prioirty_skip_alpha  -1,-1,-1,-1,-1,-1,-1,-1,-1,\
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,

/*
    Second Layer Priority ����

    1����: *, /
    2����: +, -
    3����: %
    4����: <<, >>
    5����: <=, >=, <, >, ==, !=
    6����: &, ^, |
    7����: &&, ||
*/

	//
	//	���ڰ� Ŭ���� ���� �켱������ �����ϴ�.
	//
char priority_this_second_layer1[0x7f] = {
	priority_skip
	-1, /* '!' */
	-1, /* '"' */
	-1, /* '#' */
	-1, /* '$' */
		4, /* '%' */
		1, /* '&' */
	-1, /* ''' */
	-1, /* '(' */
	-1, /* ')' */
		6, /* '*' */
		5, /* '+' */
	-1, /* ',' */
		5, /* '-' */
	-1, /* '.' */
		6, /* '/' */
    priority_skip_number
	-1, /* ':' */
	-1, /* ';' */
		2, /* '<' */
	-1, /* '=' */
		2, /* '>' */
	-1, /* '?' */
	-1, /* '@' */
    prioirty_skip_alpha
	-1, /* '[' */
	-1, /* '\' */
	-1, /* ']' */
		1, /* '^' */
	-1, /* '_' */
	-1, /* '`' */
	prioirty_skip_alpha
	-1, /* '{' */
		1, /* '|' */
	-1, /* '}' */
	-1, /* '~' */};

char priority_this_second_layer2[0x7f] = {
	priority_skip
	-1, /* '!' */
	-1, /* '"' */
	-1, /* '#' */
	-1, /* '$' */
	-1, /* '%' */
		0, /* '&' */
	-1, /* ''' */
	-1, /* '(' */
	-1, /* ')' */
	-1, /* '*' */
	-1, /* '+' */
	-1, /* ',' */
	-1, /* '-' */
	-1, /* '.' */
	-1, /* '/' */
    priority_skip_number
	-1, /* ':' */
	-1, /* ';' */
		3, /* '<' */
		2, /* '=' */
		3, /* '>' */
	-1, /* '?' */
	-1, /* '@' */
    prioirty_skip_alpha
	-1, /* '[' */
	-1, /* '\' */
	-1, /* ']' */
	-1, /* '^' */
	-1, /* '_' */
	-1, /* '`' */
	prioirty_skip_alpha
	-1, /* '{' */
		0, /* '|' */
	-1, /* '}' */
	-1, /* '~' */};

class priority_second_layer final
{
public:

		// left < right -> -1
		// left > right -> 1
        // left == right -> 0
	int operator()(std::string left, std::string right)
	{
        int lpri, rpri;
        if (left.length() == 1)
            lpri = priority_this_second_layer1[left[0]];
        else if (check_enable_operator(left[0], left[1]))
            lpri = priority_this_second_layer2[left[1]];
        if (right.length() == 1)
            rpri = priority_this_second_layer1[right[0]];
        else if (check_enable_operator(right[0], right[1]))
            rpri = priority_this_second_layer2[right[1]];

        // ���� �����ڴ� ���⼭ ������ ����
        if (lpri > rpri)
            return 1;
        else if (lpri < rpri)
            return -1;
        else
            return 0;
	}

    bool check_enable_operator(char first, char second)
    {
        if(first == '&') {
            if(second == '&')
                return true;
        } else if (first == '|') {
            if(second == '|')
                return true;
        } else if (first == '<') {
            if (second == '<' || second == '=')
                return true;
        } else if (first == '>') {
            if (second == '>' || second == '=')
                return true;
        } else if (first == '=') {
            if(second == '=')
                return true;
        } else if (first == '!') {
            if(second == '=')
                return true;
        }
        return false;
    }
	
};

#endif