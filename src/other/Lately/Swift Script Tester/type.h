/*************************************************************************
 *
 * FILE NAME : type.h
 *
 * ROLLRAT Swift Script Tester (RSST)
 *
 *
 * LANGUAGE : Macro Assembly, C++
 * VERSION  : Microsoft Macro Assembler v12.00.30501.0
 *            ISO/C++ 11-Microsoft C/C++ Optimizer Compiler 18.00.0501
 * CREATION : 2014.11.12
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com, rollrat.software@gmail.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#ifndef _TYPE_
#define _TYPE_

#include <string>
#include <algorithm>
#include <functional> 
#include <cctype>
#include <vector>
#include <hash_map>
#include <map>
#include <tuple>

#define VARTYPE_NONE		0
#define VARTYPE_INT			1
#define VARTYPE_STRING		2
#define VARTYPE_VAR			3
#define VARTYPE_ARRAY		4
#define VARTYPE_DIC			5
#define VARTYPE_FLOAT		6
#define VARTYPE_CONSTINT	7
#define VARTYPE_CONSTSTRING 8
#define VARTYPE_CONSTVAR	9
#define VARTYPE_CONSTARRAY	10
#define VARTYPE_CONSTDIC	11
#define VARTYPE_CONSTFLOAT	12

#define KEYWORD_NONE		0
#define KEYWORD_IF			1
#define KEYWORD_ELSEIF		2
#define KEYWORD_ELSE		3
#define KEYWORD_FOR			4
#define KEYWORD_DO			5
#define KEYWORD_WHILE		6
#define KEYWORD_SWITCH		7
#define KEYWORD_VAR			8
#define KEYWORD_LET			9
#define KEYWORD_FUNCTION	10

#define TOKEN_ERROR			0	// not found
#define TOKEN_PLUS			1	// +
#define TOKEN_MINUS			2	// -
#define TOKEN_EQUAL			3	// =
#define TOKEN_EQUALTO		4	// ==
#define TOKEN_PLUSEQUAL		5	// +=
#define TOKEN_MINUSEQUAL	6	// -=
#define TOKEN_NOTEQUAL		7	// !=
#define TOKEN_GREATER		8	// >
#define TOKEN_LESS			9	// <
#define TOKEN_GREATEREQUAL	10	// >=
#define TOKEN_LESSEQUAL		11	// <=
#define TOKEN_AND			12	// &
#define TOKEN_LOGICAND		13	// &&
#define TOKEN_OR			14	// |
#define TOKEN_LOGICOR		15	// ||
#define TOKEN_INCREMENT		16	// ++
#define TOKEN_DECREMENT		17	// --
#define TOKEN_XOR			18	// ^
#define TOKEN_XOREQUAL		19	// ^=
#define TOKEN_NOT			20	// !
#define TOKEN_MULTIPLE		21	// *
#define TOKEN_MULTIPLEEQUAL	22	// *=
#define TOKEN_DIVISION		23	// /
#define TOKEN_DIVISIONEQUAL	24	// /=
#define TOKEN_QUESTION		25	// ?
#define TOKEN_COLON			26	// :

#define NUM_INTEGER			1	// (+|-)<numberic>
#define NUM_FLOAT			2	// (+|-)<numberic>.<numberic>

class token {
public:
	int token_int;
	token(int ti) : token_int(ti) {}
	int operator*(){return token_int;}
};

class _scan {
public:
	static std::tuple<int, const char *> scan_keyword(const char *keyword) {
		std::string stream;
		for (; !::isspace(*keyword) && *keyword && 
			*keyword != '.' // for function call
			; keyword++)
			stream.push_back(*keyword);
		if (stream == "if")
			return std::make_tuple(KEYWORD_IF, keyword);
		else if(stream == "else") {
			const char *keywordtemp = keyword;
			if ( !*keywordtemp )
				return std::make_tuple(KEYWORD_ELSE, keyword);
			for (; ::isspace(*keywordtemp); keywordtemp++)
				;
			for (stream.clear(); !::isspace(*keywordtemp) && *keywordtemp; keywordtemp++)
				stream.push_back(*keyword);
			if (keywordtemp == "if")
				return std::make_tuple(KEYWORD_ELSEIF, keywordtemp);
			else
				return std::make_tuple(KEYWORD_ELSE, keyword);
		} else if (stream == "for")
			return std::make_tuple(KEYWORD_FOR, keyword);
		else if(stream == "do")
			return std::make_tuple(KEYWORD_DO, keyword);
		else if(stream == "while")
			return std::make_tuple(KEYWORD_WHILE, keyword);
		else if (stream == "switch")
			return std::make_tuple(KEYWORD_SWITCH, keyword);
		else if (stream == "var")
			return std::make_tuple(KEYWORD_VAR, keyword);
		else if (stream == "let")
			return std::make_tuple(KEYWORD_LET, keyword);
		else if (stream == "func")
			return std::make_tuple(KEYWORD_FUNCTION, keyword);
		else
			return std::make_tuple(KEYWORD_NONE, keyword);
	}

	static std::tuple<int, int, double> scan_number(const char *numberic) {
		int minus = 1;
		int ox = 10;
		if (*numberic == '+')
			numberic++;
		else if(*numberic == '-') {
			numberic++;
			minus = -1; 
		} else if(*numberic == '0') {
			if(*(numberic +1 ) == 'x' || *(numberic+1) == 'X') {
				numberic += 2;
				ox = 16;
			} else if(::isdigit(*(numberic + 1))) {
				numberic++;
				ox = 8;
			}
		}
		auto is_float = [](const char *test, int ox)->bool {
				if (ox != 10)
					return false;
				const char *temp = test;
				for (; ::isdigit(*temp) && *temp != '.'; temp++)
					;
				if (*temp == '.')
					return true;
				else
					return false;
			};
		if(is_float(numberic, ox)) {
			std::string stream;
			for (; !::isspace(*numberic) && *numberic; numberic++)
				stream.push_back(*numberic);
			double real = std::stod(stream);
			return std::make_tuple(NUM_FLOAT, 0, real);
		} else {
			std::string stream;
			for (; !::isspace(*numberic) && *numberic; numberic++)
				stream.push_back(*numberic);
			int num = std::stoi(stream);
			return std::make_tuple(NUM_INTEGER, num, 0);
		}
	}

	static std::tuple<int, const char *> scan_token(const char *tokenchp) {
		switch(*tokenchp) {
		case '+':
			if(*(tokenchp+1) == '+')
				return std::make_tuple(TOKEN_INCREMENT, tokenchp+2);
			else if (*(tokenchp + 1) == '=')
				return std::make_tuple(TOKEN_PLUSEQUAL, tokenchp+2);
			else
				return std::make_tuple(TOKEN_PLUS, tokenchp+1);
		case '-':
			if(*(tokenchp+1) == '-')
				return std::make_tuple(TOKEN_DECREMENT, tokenchp+2);
			else if (*(tokenchp + 1) == '=')
				return std::make_tuple(TOKEN_MINUSEQUAL, tokenchp+2);
			else
				return std::make_tuple(TOKEN_MINUS, tokenchp+1);
		case '=':
			if(*(tokenchp+1) == '=')
				return std::make_tuple(TOKEN_EQUALTO, tokenchp+2);
			else
				return std::make_tuple(TOKEN_EQUAL, tokenchp+1);
		case '!':
			if(*(tokenchp+1) == '=')
				return std::make_tuple(TOKEN_NOTEQUAL, tokenchp+2);
			else
				return std::make_tuple(TOKEN_NOT, tokenchp+1);
		case '^':
			if(*(tokenchp+1) == '=')
				return std::make_tuple(TOKEN_XOREQUAL, tokenchp+2);
			else
				return std::make_tuple(TOKEN_XOR, tokenchp+1);
		case '>':
			if(*(tokenchp+1) == '=')
				return std::make_tuple(TOKEN_GREATEREQUAL, tokenchp+2);
			else
				return std::make_tuple(TOKEN_GREATER, tokenchp+1);
		case '<':
			if(*(tokenchp+1) == '=')
				return std::make_tuple(TOKEN_LESSEQUAL, tokenchp+2);
			else
				return std::make_tuple(TOKEN_LESS, tokenchp+1);
		case '&':
			if(*(tokenchp+1) == '&')
				return std::make_tuple(TOKEN_LOGICAND, tokenchp+2);
			else
				return std::make_tuple(TOKEN_AND, tokenchp+1);
		case '|':
			if(*(tokenchp+1) == '|')
				return std::make_tuple(TOKEN_LOGICOR, tokenchp+2);
			else
				return std::make_tuple(TOKEN_OR, tokenchp+1);
		case '*':
			if(*(tokenchp+1) == '=')
				return std::make_tuple(TOKEN_MULTIPLEEQUAL, tokenchp+2);
			else
				return std::make_tuple(TOKEN_MULTIPLE, tokenchp+1);
		case '/':
			if(*(tokenchp+1) == '=')
				return std::make_tuple(TOKEN_DIVISIONEQUAL, tokenchp+2);
			else
				return std::make_tuple(TOKEN_DIVISION, tokenchp+1);
		case '?':
			return std::make_tuple(TOKEN_QUESTION, tokenchp + 1);
		case ':':
			return std::make_tuple(TOKEN_COLON, tokenchp + 1);
		default:
			return std::make_tuple(TOKEN_ERROR, tokenchp);
		}
	}

	static std::tuple<int, const char *> scan_type(const char *type) {
		std::string stream;
		for (; !::isspace(*type) && *type; type++)
			stream.push_back(*type);
		if (stream == "Int" || stream == "int")
			return std::make_tuple(VARTYPE_INT, type);
		else if (stream == "String" || stream == "str" || stream == "string")
			return std::make_tuple(VARTYPE_STRING, type);
		else if (stream == "var")
			return std::make_tuple(VARTYPE_VAR, type);
		else if (stream == "array")
			return std::make_tuple(VARTYPE_ARRAY, type);
		else if (stream == "dic" || stream == "dictionary")
			return std::make_tuple(VARTYPE_DIC, type);
		else if (stream == "float" || stream == "double")
			return std::make_tuple(VARTYPE_FLOAT, type);
		else
			return std::make_tuple(VARTYPE_NONE, type);
	}

	std::string operator()(int tokend) {
		switch(tokend) {
		case 0:		return "";
		case 1:		return "+";
		case 2:		return "-";
		case 3:		return "=";
		case 4:		return "==";
		case 5:		return "+=";
		case 6:		return "-=";
		case 7:		return "!=";
		case 8:		return ">";
		case 9:		return "<";
		case 10:	return ">=";
		case 11:	return "<=";
		case 12:	return "&";
		case 13:	return "&&";
		case 14:	return "|";
		case 15:	return "||";
		case 16:	return "++";
		case 17:	return "--";
		case 18:	return "^";
		case 19:	return "^=";
		case 20:	return "!";
		case 21:	return "*";
		case 22:	return "*=";
		case 23:	return "/";
		case 24:	return "/=";
		case 25:	return "?";
		case 26:	return ":";
		}
	}
};


#endif