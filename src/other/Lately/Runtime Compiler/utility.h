/*************************************************************************
 *
 * FILE NAME : utility.h - utility
 *
 * ROLLRAT SOFTWARE RUNTIME COMPILER(RTC)
 *
 *
 * LANGUAGE : Macro Assembly, C++
 * VERSION  : Microsoft Macro Assembler v12.00.30501.0
 *            ISO/C++ 11-Microsoft C/C++ Optimizer Compiler 18.00.0501
 * CREATION : 2014.11.6
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com, rollrat.software@gmail.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#ifndef _UTILITY_
#define _UTILITY_

#include <Windows.h>

//-----------------------------------------------------
//		Data Structue
//-----------------------------------------------------
typedef struct _token{
	struct _token* _Next;
	struct _token* _Prev;
	// Compiler Token
	ULONG type;
	char *data;
}	list, *plist;

typedef struct {
	plist (*create)();
	void (*push)(plist, ULONG, char *);
	void (*pop)(plist);
} listcontrol;

typedef struct _stack_stt{
	plist Top;
}	stack, *pstack;

typedef struct {
	pstack (*create)();
	void (*push)(pstack, ULONG, char *);
	void (*pop)(pstack);
}	stackcontrol;

typedef struct _tree{
	struct _tree* _Left;
	struct _tree* _Right;
	struct _tree* _Parent;
	ULONG type;
	char *data;
}	tree, *ptree;

typedef struct {
	ptree (*create)();
	void (*push_right)(ptree, ULONG, char *);
	void (*push_left)(ptree, ULONG, char *);
	void (*into_right)(ptree);
	void (*into_left)(ptree);
	void (*escape)(ptree);
	void (*ground)(ptree);
	BOOL (*is_right)(ptree);
	BOOL (*is_left)(ptree);
	BOOL (*is_ground)(ptree);
}	treecontrol;

plist CreateList();
pstack CreateStack();
ptree CreateTree();
void stack_push(pstack stack, ULONG, char *);
void stack_pop(pstack stack);
void list_push(plist list, ULONG, char *);
void list_pop(plist list);
void tree_pushright(ptree tree, ULONG, char *);
void tree_pushleft(ptree tree, ULONG, char *);
void into_right(ptree tree);
void into_left(ptree tree);
void escape(ptree tree);
void gound(ptree tree);
BOOL is_right(ptree tree);
BOOL is_left(ptree tree);
BOOL is_gound(ptree tree);
void inorder_travel(ptree tree, void(*)(ULONG, char*));
void postorder_travel(ptree tree, void(*)(ULONG, char*));
void preorder_travel(ptree tree, void(*)(ULONG, char*));

extern listcontrol clist;
extern stackcontrol cstack;
extern treecontrol ctree;

#endif