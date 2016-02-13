/*************************************************************************
 *
 * FILE NAME : var.h
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

#ifndef _VAR_
#define _VAR_

#include <string>
#include <algorithm>
#include <functional> 
#include <cctype>
#include <vector>
#include <hash_map>
#include <map>
#include <tuple>
#include "type.h"

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

class _variable {
	static PVARIABLE get_array(const char *_str, PVARIABLE pvar) {
		return pvar;
	}

public:
	static PVARIABLE variable_syntax(const char *syn) {
		bool const_t = false, etj = false;
		PVARIABLE pvar = new VARIABLE;
		pvar->type = 0;
		pvar->typex = 0;

		auto skipws = [&syn]() {
			for (; isspace(*syn) && *syn; syn++)
				;
			};
		skipws();
		std::string stream;
		std::string variable_name;
		for (; !::isspace(*syn) && *syn; syn++)
			stream.push_back(*syn);
		if (stream == "var") ;
		else if (stream == "let") const_t = true;
		else return pvar;
		skipws();
		pvar->is_var = true;
		for (; !::isspace(*syn) && *syn && *syn != ':' && *syn != '='; syn++)
			variable_name.push_back(*syn);
		if (variable_name.empty())
			return new VARIABLE;	// error ? variable name
		pvar->varname = variable_name;skipws();
		if(*syn == ':') {
			syn++;skipws();
			auto st = _scan::scan_type(syn);
			syn = std::get<1>(st);
			if (std::get<0>(st) == VARTYPE_NONE)
				return pvar;	// error ? type
			pvar->type = const_t ? (std::get<0>(st) +6) : std::get<0>(st);
		} else if (*syn == '=') {
		EQUAL_TO_JMP:
			pvar->init = true;
			syn++;skipws();
			if (!*syn)
				return pvar;	// error ? value
			else if (::isdigit(*syn)) {
				auto sn = _scan::scan_number(syn);
				int type = std::get<0>(sn);
				etj ? pvar->typex : pvar->type =  const_t ? (type + 6) : type;
				if (type == VARTYPE_INT)
					pvar->idata = std::get<1>(sn);
				else if (type == VARTYPE_FLOAT)
					pvar->ddata = std::get<2>(sn);
				return pvar;		//	 success return
			} else if (::isalpha(*syn) || *syn == '_') {
				std::string var_;
				for (; !::isspace(*syn) && *syn; syn++)
					var_.push_back(*syn);
				etj ? pvar->typex : pvar->type = const_t 
					? VARTYPE_CONSTVAR : VARTYPE_VAR;
				pvar->sdata = var_;
				return pvar;		//	 success return
			} else if (*syn == '[') {
				etj ? pvar->typex : pvar->type = const_t 
					? VARTYPE_CONSTARRAY : VARTYPE_ARRAY;
				return get_array(syn, pvar);	// success return
			}
		} else
			return pvar;	// error ? type
		skipws();
		if(*syn == '=') {
			etj = true;
			goto EQUAL_TO_JMP;
		} else
			if(!const_t)
				return pvar;	// success return
			else
				MessageBox(0, TEXT("let변수는 선언과 동시에 값이 대입되어야 합니다."), TEXT("_rsst:_@variable_syntax"), MB_OK | MB_ICONERROR);
	}
};


#endif