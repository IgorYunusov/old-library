/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   portable_lines.h

Project:

   Portable Lines

------
   AUTHOR: HyunJun Jeong  2015-05-24

***************************************************************************/

#ifndef _PROTABLE_LINES_34835d87c0d711550831322a4e634e361_
#define _PROTABLE_LINES_34835d87c0d711550831322a4e634e361_

#include <string>
#include <algorithm>
#include <functional> 
#include <cctype>
#include <vector>
#include <hash_map>
#include <map>
#include <tuple>

typedef struct _vartype_stt {
	bool is_var = false;
	bool init = false;
	int type;
	int typex;
	void *data;
	int idata;
	double ddata;
	std::string sdata;
	std::vector<struct _vartype_stt*> adata;
	std::map<std::string, std::vector<struct _vartype_stt*>> dicdata;
	std::string varname;
}	VARIABLE, *PVARIABLE;

typedef std::map<std::string, PVARIABLE>::value_type map_var;

class variable_map {
public:
	std::map<std::string, PVARIABLE> map;

	PVARIABLE operator[](std::string str) {
		return map[str];
	}

	bool operator()(std::string str, PVARIABLE var = nullptr) {
		if (map.find(str) == map.end()) {
			if(var != nullptr)
				map.insert(std::make_pair(str, var));
			return true;
		} else {
			return false;
		}
	}
};

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

typedef struct _asdfasdkvzlxcjpi0294ads_ {
	int a;
	const char *b;
}	_Scan_Return, *_P_Scan_Return;

_P_Scan_Return make_scan_return(int a, const char *b)
{
	_Scan_Return *ret = new _Scan_Return;
	ret->a = a;
	ret->b = b;
	return ret;
}

class _scan {
public:

	_P_Scan_Return scan_keyword(const char *keyword) {
		std::string stream;
		for (; !::isspace(*keyword) && *keyword && 
			*keyword != '.' // for function call
			; keyword++)
			stream.push_back(*keyword);
		if (stream == "if")
			return make_scan_return(KEYWORD_IF, keyword);
		else if(stream == "else") {
			const char *keywordtemp = keyword;
			if ( !*keywordtemp )
				return make_scan_return(KEYWORD_ELSE, keyword);
			for (; ::isspace(*keywordtemp); keywordtemp++)
				;
			for (stream.clear(); !::isspace(*keywordtemp) && *keywordtemp; keywordtemp++)
				stream.push_back(*keyword);
			if (keywordtemp == "if")
				return make_scan_return(KEYWORD_ELSEIF, keywordtemp);
			else
				return make_scan_return(KEYWORD_ELSE, keyword);
		} else if (stream == "for")
			return make_scan_return(KEYWORD_FOR, keyword);
		else if(stream == "do")
			return make_scan_return(KEYWORD_DO, keyword);
		else if(stream == "while")
			return make_scan_return(KEYWORD_WHILE, keyword);
		else if (stream == "switch")
			return make_scan_return(KEYWORD_SWITCH, keyword);
		else if (stream == "var")
			return make_scan_return(KEYWORD_VAR, keyword);
		else if (stream == "let")
			return make_scan_return(KEYWORD_LET, keyword);
		else if (stream == "func")
			return make_scan_return(KEYWORD_FUNCTION, keyword);
		else
			return make_scan_return(KEYWORD_NONE, keyword);
	}

	double scan_number(const char *numberic) {
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
			return std::stod(stream);
		} else {
			std::string stream;
			for (; !::isspace(*numberic) && *numberic; numberic++)
				stream.push_back(*numberic);
			return std::stoi(stream);
		}
	}

	_P_Scan_Return scan_token(const char *tokenchp) {
		switch(*tokenchp) {
		case '+':
			if(*(tokenchp+1) == '+')
				return make_scan_return(TOKEN_INCREMENT, tokenchp+2);
			else if (*(tokenchp + 1) == '=')
				return make_scan_return(TOKEN_PLUSEQUAL, tokenchp+2);
			else
				return make_scan_return(TOKEN_PLUS, tokenchp+1);
		case '-':
			if(*(tokenchp+1) == '-')
				return make_scan_return(TOKEN_DECREMENT, tokenchp+2);
			else if (*(tokenchp + 1) == '=')
				return make_scan_return(TOKEN_MINUSEQUAL, tokenchp+2);
			else
				return make_scan_return(TOKEN_MINUS, tokenchp+1);
		case '=':
			if(*(tokenchp+1) == '=')
				return make_scan_return(TOKEN_EQUALTO, tokenchp+2);
			else
				return make_scan_return(TOKEN_EQUAL, tokenchp+1);
		case '!':
			if(*(tokenchp+1) == '=')
				return make_scan_return(TOKEN_NOTEQUAL, tokenchp+2);
			else
				return make_scan_return(TOKEN_NOT, tokenchp+1);
		case '^':
			if(*(tokenchp+1) == '=')
				return make_scan_return(TOKEN_XOREQUAL, tokenchp+2);
			else
				return make_scan_return(TOKEN_XOR, tokenchp+1);
		case '>':
			if(*(tokenchp+1) == '=')
				return make_scan_return(TOKEN_GREATEREQUAL, tokenchp+2);
			else
				return make_scan_return(TOKEN_GREATER, tokenchp+1);
		case '<':
			if(*(tokenchp+1) == '=')
				return make_scan_return(TOKEN_LESSEQUAL, tokenchp+2);
			else
				return make_scan_return(TOKEN_LESS, tokenchp+1);
		case '&':
			if(*(tokenchp+1) == '&')
				return make_scan_return(TOKEN_LOGICAND, tokenchp+2);
			else
				return make_scan_return(TOKEN_AND, tokenchp+1);
		case '|':
			if(*(tokenchp+1) == '|')
				return make_scan_return(TOKEN_LOGICOR, tokenchp+2);
			else
				return make_scan_return(TOKEN_OR, tokenchp+1);
		case '*':
			if(*(tokenchp+1) == '=')
				return make_scan_return(TOKEN_MULTIPLEEQUAL, tokenchp+2);
			else
				return make_scan_return(TOKEN_MULTIPLE, tokenchp+1);
		case '/':
			if(*(tokenchp+1) == '=')
				return make_scan_return(TOKEN_DIVISIONEQUAL, tokenchp+2);
			else
				return make_scan_return(TOKEN_DIVISION, tokenchp+1);
		case '?':
			return make_scan_return(TOKEN_QUESTION, tokenchp + 1);
		case ':':
			return make_scan_return(TOKEN_COLON, tokenchp + 1);
		default:
			return make_scan_return(TOKEN_ERROR, tokenchp);
		}
	}

	_P_Scan_Return scan_type(const char *type) {
		std::string stream;
		for (; !::isspace(*type) && *type; type++)
			stream.push_back(*type);
		if (stream == "Int" || stream == "int")
			return make_scan_return(VARTYPE_INT, type);
		else if (stream == "String" || stream == "str" || stream == "string")
			return make_scan_return(VARTYPE_STRING, type);
		else if (stream == "var")
			return make_scan_return(VARTYPE_VAR, type);
		else if (stream == "array")
			return make_scan_return(VARTYPE_ARRAY, type);
		else if (stream == "dic" || stream == "dictionary")
			return make_scan_return(VARTYPE_DIC, type);
		else if (stream == "float" || stream == "double")
			return make_scan_return(VARTYPE_FLOAT, type);
		else
			return make_scan_return(VARTYPE_NONE, type);
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