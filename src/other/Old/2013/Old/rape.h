/*************************************************************************
 *
 *				RollRat Software a p e Header
 *
 *				Version 1.0
 *				Make Individual
 *
 *				Copyright (c) 2012 Rollrat. All right reserved.
 */
#pragma once

#ifndef _APE_ROLLRAT_
#define _APE_ROLLRAT_

typedef int    BOOL;
typedef char   CHAR;
typedef char*  CHARP;
typedef float  FLOAT;
typedef long   LONG;
typedef enum   ENUM;
#define VOID                void
#define PASCAL              _pascal
#define CDECL               _cdecl
#define FALSE               0
#define TRUE                1
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef unsigned long       DWORD;
typedef unsigned int        UINT;
#define IF       if
#define ELSE     else if
#define IFELSE   else
#define FOR      for
#define FORI     int i = 0;
#define FORK     int k = 0;
#define FORF     int f = 0;
#define BRK      break;
#define TD       typedef
#define ST       struct
#define WHI      while(
#define WHIT     while(TRUE)
#define Ret      return
#define SWT(t)   switch(t)
#define CASE(t)  case(t):
#define SIZE(F)  sizeof(F)
#define TDEF(d)  typedef void d
#define TDEF_(d,i) typedef d i
#define TEMP     template
#define NS       namespace
#define LDOUBLE  long double
#define ONE(f)   f + 1
#define _Ret_Null_Void_ return ;
#define _Ret_Null_Int_  return 0;
#define _Ret_Int_
#define _Ret_CharP_
#define _Ret_Char_
#define _Ret_Dword_
#define _Ret_Uint_
#define _Ret_Byte_
#define _Retype_Function_Set_
#define _Retype_Declaration_
#define __charnull '\0'
#define __charspace ' '

#endif