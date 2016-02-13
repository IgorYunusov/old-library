/*************************************************************************

   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:

   SyntaxTable.h

Project:

	RollRat C Compiler Syntax Definition Table Structure Collection

------
   AUTHOR: HyunJun Jeong  2015-08-26

***************************************************************************/

#ifndef _C_COMPILER_SYNTAX_TABLE_
#define _C_COMPILER_SYNTAX_TABLE_

typedef enum class _enum_001_ {
	_ID_Variable,
	_ID_Struct,
	_ID_Function,
	_ID_Enum,
	_ID_Type,
}	SYN_STRUCTRUE;

typedef enum class _enum_002_ {
	_ID_Auto,
	_ID_Static,
	_ID_Typedef,
	_ID_Extern,
}	SYN_SPECIFIC;

class SymbolTable {
public:

	char *m_name;

	//
	//	Auto Static Typedef
	//
	SYN_SPECIFIC m_specific;

	//
	//	Must Assembly Integer With Static Memory
	//
	int m_must;

};

#endif