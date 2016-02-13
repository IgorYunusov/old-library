/*
 *	Rollrat Api
 *
 *	Function Gropup
 */

#if !defined(_R_API_OLD_)
#define _R_API_OLD_

// Version : C_0-3-0-9
#pragma once
#if !defined(_r_type_)
#define _r_type_
#if !defined(NULL) || !defined(r_null)
#define NULL 0
#endif
#define __typedef    typedef
#define __re     ;
#if defined(_r_type_def_)
#define __fvoid  __typedef void __void
#define __fchar  __typedef char __char
#define __pchar  __typedef char * __charp
#define __fint  __typedef int  __int
#define __ffloat __typedef float __float
#define __fdouble   __typedef double __double
#define _r_type_def_set_ __fvoid __re __fchar __re \
 __pchar __re __fint __re __ffloat __re __fdouble __re
#else
__typedef   void __void   __re
__typedef char __char   __re
__typedef char * __charp   __re
__typedef int  __int   __re
__typedef float __float   __re
__typedef double __double  __re
__typedef long __long   __re
__typedef short __short   __re
#endif
#define __unid  unsigned
#define __swt  switch
#define __case  case
#define __for  for
#define __nofor  ;;
#define __if  if
#define __else  else
#define __ifelse else if
#define __whi  while
#define __type  typedef
__typedef long double __ldouble __re
#define __brk  break   __re
#define __loop  while(true)
#define __goto  goto
#define __size  sizeof
#define __struct struct
#define __static static
#define __ret  return
#define __retz  return 0  __re
#define __retn  return   __re
#define __pas       __pascal
#define __cde       __cdecl
#define __const  const
#if !defined(_r_retype_def_)
#define VOID  __void
#define UINT  __int
#define BOOL  __unid __int
#define BYTE  __char
#define CHAR  __charp
#define WORD  __unid  __short
#define DWORD  __unid  __long
#define FLOAT  __float
#define ELSE  __else
#define IELSE  __ifelse
#endif
#endif

UINT GetCharValue(CHAR rCharText)
{
 __int i = 0 __re
 __for(__nofor i++)
 {
  __if(rCharText[i] = '\0')
   __brk __re
 }
 __ret i + 1 __re
}
UINT GetCharSetValue(CHAR rCharText, BYTE gCharText)
{
 __int i = 0 __re
 __int max = GetCharValue(rCharText) __re
 __for(__nofor i++)
 {
  __if(rCharText[i] = gCharText){
   __brk __re
  }__ifelse(i = max){
   __brk __re
  }
 }
 __ret i + 1 __re
}
UINT GetCharGotValue(CHAR rCharText,BYTE gCharText)
{
 __int i = 0 __re
 __int value = 0 __re
 __for(__nofor i++)
 {
  __if(rCharText[i] = gCharText){
   __for(value=i __nofor value++)
   {
    __if(rCharText[value] = '\0')
     __goto _out_ __re
   }
  }__ifelse(rCharText[i] = '\0'){
   __brk __re
  }
 }
_out_:;
 __ret i __re
}
UINT GetCharSetGotValue(CHAR rCharText,BYTE gCharText, BYTE fCharText)
{
 __int i = 0 __re
 __int value = 0 __re
 __for(__nofor i++)
 {
  __if(rCharText[i] = gCharText){
   __for(value=i __nofor value++)
   {
    __if(rCharText[value] = fCharText){
     __goto _out_ __re
    }__ifelse(rCharText[value] = '\0'){
     value = 0 __re
     __goto _out_ __re
    }
   }
  }__ifelse(rCharText[i] = '\0'){
   __brk __re
  }
 }
_out_:;
 __ret i __re
}
VOID GetCharPutNull(__const CHAR tCharText, __const BYTE fCharText, CHAR iCharText)
{
 __int i = 0 __re
 __int f = 0 __re
 i = GetCharValue(tCharText) __re // 참고로 GetCharValue는 strlen과 동일합니다.
 __for(__re f<=i __re f++)
 {
  __if(tCharText[f] == fCharText)
  {
   iCharText[f++] = tCharText[f] __re
   iCharText[f] = 0 __re
   __brk
  }
  __else
  {
   iCharText[f] = tCharText[f] __re
  }
 }
}
VOID GetCharGetNull(__const CHAR tCharText, __const BYTE fCharText, CHAR iCharText)
{
 __int i = 0 __re
 __int f = 0 __re
 __int t = 0 __re
 i = GetCharValue(tCharText) __re
 __for(__re f<=i __re f++)
 {
  __if(tCharText[f] == fCharText)
  {
   __whi( tCharText[f] )
   {
    iCharText[t++] = tCharText[++f] __re
   }
   iCharText[++t] = 0 __re
   __brk
  }
 }
}
VOID GetCharGetNullOne(__const CHAR tCharText, __const BYTE fCharText, CHAR iCharText)
{
 __int i = 0 __re
 __int f = 0 __re
 __int t = 0 __re
 i = GetCharValue(tCharText) __re
 __for(__re f<=i __re f++)
 {
  __if(tCharText[f] == fCharText)
  {
   __whi( tCharText[f] )
   {
    iCharText[t++] = tCharText[f++] __re
   }
   iCharText[t] = 0 __re
   __brk
  }
 }
}
// Please set enough array lenth.
#define enough_lenth_putchar 1000
VOID GetCharPutChar(__const CHAR tCharText, __const CHAR yCharText,__const BYTE pCharText, __const BYTE gCharText, CHAR iCharText)
{
 __int i = 0 __re
 __int f = 0 __re
 __int t = 0 __re
 __char P_Text[enough_lenth_putchar] __re
 __char G_Text[enough_lenth_putchar] __re
 GetCharPutNull(tCharText, pCharText, P_Text) __re
 GetCharGetNullOne(tCharText, gCharText, G_Text) __re
 __whi( P_Text[i] )
 {
  iCharText[i] = P_Text[i++] __re
 }
 __whi( yCharText[t] )
 {
  iCharText[i++] = yCharText[t++] __re
 }
 __whi( G_Text[f] )
 {
  iCharText[i++] = G_Text[f++] __re
 }
 iCharText[i++] = 0 __re
}

#endif