/*************************************************************************
 *
 *					  ROLLRAT SOFTWARE LIBRARY
 *						PRIORITY
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _PRIORITY_
#define _PRIORITY_

#include <string>

	char *priority_this[3][4] = {
		{"+", "-", "&&", "||"},   // 0
		{"*",  "<<", ">>", "/"},  // 1
		{"%", "|", "&","^"},      // 2
	};


#define priority_skip -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,\
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,\
    -1,-1,-1,-1,-1,-1,

	//
	//	숫자가 클수록 높은 우선순위를 가집니다.
	//
char priority_this2[0x7f] = {
	priority_skip
	-1, /* '!' */
	-1, /* '"' */
	-1, /* '#' */
	-1, /* '$' */
		2, /* '%' */
		2, /* '&' */
	-1, /* ''' */
	-1, /* '(' */
	-1, /* ')' */
		1, /* '*' */
		0, /* '+' */
	-1, /* ',' */
		0, /* '-' */
	-1, /* '.' */
		1, /* '/' */
	-1, /* '0' */
	-1, /* '1' */
	-1, /* '2' */
	-1, /* '3' */
	-1, /* '4' */
	-1, /* '5' */
	-1, /* '6' */
	-1, /* '7' */
	-1, /* '8' */
	-1, /* '9' */
	-1, /* ':' */
	-1, /* ';' */
		3, /* '<' */
	-1, /* '=' */
		3, /* '>' */
	-1, /* '?' */
	-1, /* '@' */
	-1, /* 'A' */
	-1, /* 'B' */
	-1, /* 'C' */
	-1, /* 'D' */
	-1, /* 'E' */
	-1, /* 'F' */
	-1, /* 'G' */
	-1, /* 'H' */
	-1, /* 'I' */
	-1, /* 'J' */
	-1, /* 'K' */
	-1, /* 'L' */
	-1, /* 'M' */
	-1, /* 'N' */
	-1, /* 'O' */
	-1, /* 'P' */
	-1, /* 'Q' */
	-1, /* 'R' */
	-1, /* 'S' */
	-1, /* 'T' */
	-1, /* 'U' */
	-1, /* 'V' */
	-1, /* 'W' */
	-1, /* 'X' */
	-1, /* 'Y' */
	-1, /* 'Z' */
	-1, /* '[' */
	-1, /* '\' */
	-1, /* ']' */
		2, /* '^' */
	-1, /* '_' */
	-1, /* '`' */
	-1, /* 'a' */
	-1, /* 'b' */
	-1, /* 'c' */
	-1, /* 'd' */
	-1, /* 'e' */
	-1, /* 'f' */
	-1, /* 'g' */
	-1, /* 'h' */
	-1, /* 'i' */
	-1, /* 'j' */
	-1, /* 'k' */
	-1, /* 'l' */
	-1, /* 'm' */
	-1, /* 'n' */
	-1, /* 'o' */
	-1, /* 'p' */
	-1, /* 'q' */
	-1, /* 'r' */
	-1, /* 's' */
	-1, /* 't' */
	-1, /* 'u' */
	-1, /* 'v' */
	-1, /* 'w' */
	-1, /* 'x' */
	-1, /* 'y' */
	-1, /* 'z' */
	-1, /* '{' */
		2, /* '|' */
	-1, /* '}' */
	-1, /* '~' */};

	//
	//	무쓸모
	//
class priority_first final
	{
public:

		// left <= right -> false
		// left > right -> true
	bool operator()(std::string left, std::string right)
		{
		int lpri=0, rpri=0;
		for (int i = 0; i < 3 && (!lpri || !rpri); i++)
			for (int j = 0; j < 4 && (!lpri || !rpri); j++)
				if (priority_this[i][j] == left)
					lpri = i;
				else if (priority_this[i][j] == right)
					rpri = i;
		return lpri > rpri;
		}

		// left < right -> false
		// left >= right -> true
	bool less_equal(std::string left, std::string right)
		{
		int lpri=0, rpri=0;
		for (int i = 0; i < 3 && (!lpri || !rpri); i++)
			for (int j = 0; j < 4 && (!lpri || !rpri); j++)
				if (priority_this[i][j] == left)
					lpri = i;
				else if (priority_this[i][j] == right)
					rpri = i;
		return lpri >= rpri;
		}

	};

class priority_second final
	{
public:

	//
	//	실제로 사용되는 부분
	//
		// left < right -> -1
		// left > right -> 1
        // left == right -> 0
	int operator()(std::string left, std::string right)
		{
		int lpri=priority_this2[left[0]], 
			rpri=priority_this2[right[0]];
        if (lpri > rpri)
            return 1;
        else if (lpri < rpri)
            return -1;
        else
            return 0;
		}
	
	};

#endif