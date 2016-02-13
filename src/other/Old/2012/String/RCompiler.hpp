/*******************************************************************\
 *																   *
 *				RCompiler.hpp -- rollrat Compiler.				   *
 *																   *
 *																   *
 *			Copyright (c) rollrat. All rights reserved.			   *
 *																   *
\*******************************************************************/

/***********************************************************

		 _____    __  __   ______           __
		/  __ |___\ \ \ \ /  __  | __   _ __\ \__
		| |_| | _ \ | | | | |__| |/  \_| |/___  _/
		|  __/ (_)| | | | |  _  / |(_)  |   | |
		| |  \ ___/ |_| |_| | \ \ \____/    | |
		\_/ \_\    \__\\__\_/  \_\          \_\

		RollRatSoftware-PrivateProgrammingLab

	Copyright (c) rollrat. 2009-2013 All rights reserved.


************************************************************/

#pragma once
#ifndef _ROLLRAT_COMPIL_
#define _ROLLRAT_COMPIL_

#include "regex.hpp"
#include "RString.hpp"
#include "ROption.hpp"

class RCompiler
{
public:

	/* Input Output */
	RCompiler();
	RCompiler(RString);
	RCompiler(RString, ullong);
	RCompiler(RString, OPTIONHEADER);

	/* Syntax Trees */
	CRegexpT<char> buildAnnote();

private:

	RString str;

	mutable ullong OPTION;

};

CRegexpT<char> RCompiler::buildAnnote()
{
	CRegexpT <char> regexp("/\\*(?>\n|[^*]|\\*+[^*/])*\\**\\*/");
	return regexp;
}
#endif
