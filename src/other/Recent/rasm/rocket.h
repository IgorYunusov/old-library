/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   rocket.h - [Private]

Project:

   Robust Assembler (RASM)

------
   AUTHOR: HyunJun Jeong  2015-01-05

***************************************************************************/

#ifndef _ROCKET_
#define _ROCKET_

#include "type.h"

#ifdef USING_DEVICE
#define USING_DEVICE_FLAG_STRINGH
#endif

#if defined(_DEBUG) || defined(DEBUG)
#define _NULL		0L

#define FL_UNSIGNED		1
#define FL_NEG			2
#define FL_OVERFLOW		4
#define FL_READDIGIT	8

#define _SHRT_MIN	(-32768)
#define _SHRT_MAX	  32767
#define _USHRT_MAX	  0xffff
#define _INT_MIN	(-2147483647 - 1)
#define _INT_MAX	  2147483647
#define _UINT_MAX	  0xffffffff
#define _LONG_MIN	(-2147483647L - 1)
#define _LONG_MAX	  2147483647L
#define _ULONG_MAX	  0xffffffffUL
#define _LLONG_MAX	  9223372036854775807i64
#define _LLONG_MIN	(-9223372036854775807i64 - 1)
#define _ULLONG_MAX	  0xffffffffffffffffui64

typedef unsigned short _wchar_t;
typedef unsigned int   _size_t;

int _isspace(int ch);
int _isnumeric(int ch);
int _isdigit(int ch);
int _isalpha(int ch);
int _isupper(int ch);
int _islower(int ch);
int _isalnum(int ch);
int _isalnumub(int ch);
int _isxdigit(int ch);
int _isreturn(int ch);

int _isnspace(int ch);
int _isnnumeric(int ch);
int _isndigit(int ch);
int _isnalpha(int ch);
int _isnupper(int ch);
int _isnlower(int ch);
int _isnalnum(int ch);
int _isnalnumub(int ch);
int _isnxdigit(int ch);
int _isnreturn(int ch);

char * _strcpy_asc(char * dest, const char * src);
_wchar_t * _strcpy_w(_wchar_t * dest, const _wchar_t * src);
char * _strncpy_asc(char * dest, const char * src, _size_t n);
_wchar_t * _strncpy_w(char * dest, const _wchar_t * src, _size_t n);
int _strcmp_asc(const char * s1, const char * s2);
int _strncmp_asc(const char * s1, const char * s2, _size_t n);
char * _strcat_asc(char * dest, const char * src);
_wchar_t * _strcat_w(_wchar_t * dest, const _wchar_t * src);
char * _strchr_asc(const char * str, int ch);
char * _strrchr_asc(const char * str, int ch);
_size_t _strspn_asc(const char * str1, const char * str2);
_size_t _strcspn_asc(const char * str1, const char * str2);
_size_t _strlen_asc(const char * str);
_size_t _strnlen_asc(const char * str, _size_t n);
char * _strupr_asc(char * str);
char * _strlwr_asc(char * str);
char * _strncat_asc(char * dest, const char * src, _size_t n);
_wchar_t * _strncat_w(_wchar_t * dest, const _wchar_t * src, _size_t n);
char * _strset_asc(char * str, int ch);
char * _strnset_asc(char * str, int ch, _size_t n);
char * _strrev_asc(char * str);
char * _strstr_asc(const char * s1, const char * s2);
char * _strtok_asc(char * str, const char * src);
char * _strpbrk_asc(const char * str, const char * src);
long _strtol_asc(const char *nptr, char **endptr, int base);
long _strtol_t(const char *nptr, char **endptr, int base);
unsigned long _strtoul_asc(const char *nptr, char **endptr, int base);
unsigned long _strtoul_t(const char *nptr, char **endptr, register int base);

int _atoi(const char * src);
double _atof(const char * src);
long _atol(const char * src);
char *__itoa(int i);

int _to_upper(int ch);
int _to_lower(int ch);
int _to_xdigit(int ch);

#else
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define _isspace isspace
#define _isnumeric isdigit
#define _isdigit isdigit
#define _isalpha isalpha
#define _isupper isupper
#define _islower islower
#define _isalnum isalnum
int _isalnumub(int ch);
#define _isxdigit isxdigit
int _isnspace(int ch);
int _isnnumeric(int ch);
int _isndigit(int ch);
int _isnalpha(int ch);
int _isnupper(int ch);
int _isnlower(int ch);
int _isnalnum(int ch);
int _isnalnumub(int ch);
int _isnxdigit(int ch);
int _isnreturn(int ch);

#define _strcpy_asc strcpy
#define _strcpy_w wcscpy
#define _strncpy_asc strncpy
#define _strncpy_w wcsncpy
#define _strcmp_asc strcmp
#define _strncmp_asc strncmp
#define _strcat_asc strcat
#define _strcat_w wcscat
#define _strchr_asc strchr
#define _strrchr_asc strrchr
#define _strspn_asc strspn
#define _strcspn_asc strcspn
#define _strlen_asc strlen
#define _strnlen_asc strnlen
#define _strupr_asc strupr
#define _strlwr_asc strlwr
#define _strncat_asc strncat
#define _strncat_w wcsncat
#define _strset_asc strset
#define _strnset_asc strnset
#define _strrev_asc strrev
#define _strstr_asc strstr
#define _strtok_asc strtok
#define _strpbrk_asc strpbrk
#define _strtol_asc strtol
#define _strtol_t strtol
#define _strtoul_asc strtoul
#define _strtoul_t strtoul

#define _atoi atoi
#define _atof atof
#define _atol atol
//#define __itoa itoa
char *__itoa(int i);

#define _to_upper toupper
#define _to_lower tolower
int _to_xdigit(int ch);
#endif

#pragma pack( push )

//-----------------------------------------------------
//		Data Structue
//-----------------------------------------------------
typedef struct _token{
	struct _token* _Next;
	struct _token* _Prev;

	// Compiler Token
	u32 type;
	char *data;
}	list, *plist;

typedef struct {
	plist (*create)();
	
	/* push to list */
	void (*push)(plist, u32, char *);

	/* pop to list */
	void (*pop)(plist);

} listcontrol;

typedef struct _stack_stt{
	plist Top;
}	stack, *pstack;

typedef struct {
	pstack (*create)();

	/* push to stack */
	void (*push)(pstack, u32, char *);

	/* pop to stack */
	void (*pop)(pstack);

}	stackcontrol;

typedef struct _tree{
	struct _tree* _Left;
	struct _tree* _Right;
	struct _tree* _Parent;
	
	// Compiler Token
	u32 type;
	char *data;
}	tree, *ptree;

typedef struct {
	ptree (*create)();

	/* push to tree */
	void (*push_right)(ptree, u32, char *);
	void (*push_left)(ptree, u32, char *);
	
	/* into tree */
	void (*into_right)(ptree);
	void (*into_left)(ptree);
	
	/* escape this position */
	void (*escape)(ptree);

	/* goto ground */
	void (*ground)(ptree);

	BOOL (*is_right)(ptree);
	BOOL (*is_left)(ptree);
	BOOL (*is_ground)(ptree);
}	treecontrol;

#pragma pack( pop )

plist CreateList();
pstack CreateStack();
ptree CreateTree();
void stack_push(pstack stack, u32, char *);
void stack_pop(pstack stack);
void list_push(plist list, u32, char *);
void list_pop(plist list);
void tree_pushright(ptree tree, u32, char *);
void tree_pushleft(ptree tree, u32, char *);
void into_right(ptree tree);
void into_left(ptree tree);
void escape(ptree tree);
void gound(ptree tree);
BOOL is_right(ptree tree);
BOOL is_left(ptree tree);
BOOL is_gound(ptree tree);
void inorder_travel(ptree tree, void(*)(u32, char*));
void postorder_travel(ptree tree, void(*)(u32, char*));
void preorder_travel(ptree tree, void(*)(u32, char*));

// extern datas
extern listcontrol clist;
extern stackcontrol cstack;
extern treecontrol ctree;

int sscanft(const char *src, const char *format, ...);

#endif