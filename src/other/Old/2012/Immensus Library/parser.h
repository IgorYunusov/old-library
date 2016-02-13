/****************************************************************
 *																*
 *																*
 *			ROLLRAT AUTO PERSONA VERBOTER LIBROFEX				*
 *																*
 *																*
 *		COPYRIGHT (c) rollrat. 2013. ALL RIGHTS RESERVED.		*
 *																*
 *																*
 ****************************************************************/

#ifndef __parser_apvl
#define __parser_apvl

#include "memory.h"
#include "pTree.h"

#define CRAETE_PARSER_ROLLRAT	0x00
#define CREATE_PARSER_LL		0x01
#define CREATE_PARSER_LR		0x02

#ifndef PARSER_LINECURRNETER
#define PARSER_LINECURRNETER	'\n'	// line feed
#endif
#ifndef PARSER_SPACE
#define PARSER_SPACE			' '		// white space
#endif
#ifndef PARSER_A_NONTEMINAL
#define PARSER_A_NONTEMINAL		"+-*/"
#endif

const char ptf[] = PARSER_A_NONTEMINAL;

template<class _TxPar = char> class
	parser
	{ // parser
	int line;
	int keyset;
	tree<_TxPar> x_tree;
	_TxPar *tyt;
public:
	explicit parser() : line(0), keyset(0) {}
	void parsing(_TxPar *parseT)
		{
		tyt = parseT;

		}
	bool match()
		{
		while(*(tyt++))
			if(*tyt == PARSER_LINECURRNETER){ line += 1; continue; }
			else if(*tyt == PARSER_SPACE) continue;
			else break;
		if(isDigit(*tyt))
			x_tree.left(*tyt);
		else if(isAnonteminal(*tyt))
			x_tree.right(*tyt);
		}
private:
	inline bool isDigit(_TxPar t)
		{
		return '0' <= t && t <= '9';
		}
	inline bool isAnonteminal(_TxPar t)
		{
		for(int i = 0; i < __length(ptf); i++)
			if(ptf[i] == t)
				return true;
		return false;
		}
	};

#endif