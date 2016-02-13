/*******************************************************************************
 *******************************************************************************
 *******************************************************************************
 ********									                            ********
 ********       ROLLRAT SOFTWARE						                ********
 ********       SINCE : 2009 - 2012							            ********
 ********										                        ********
 ********       Header : <rapi.h>	      							    ********
 ********		Version: 1.0.3.1					                    ********
 ********										                        ********
 ********       Copyright ¨Ï ROLLRAT. All Rights Reserved.				********
 ********										                        ********
 *******************************************************************************
 *******************************************************************************
 *******************************************************************************/

/*

    RollRat Software Api Service << Subroutine >>

	Firest Subroutine

	INCLUDE GROUP
	       
		   stdio.h       ( Standard Input And Output )
		   rdefasc.h     ( Group ASCII CODE          )
		   racalc.h      ( Group High-Calculation    ) 
		             Disappear     ERROR(SQRT)
		   
	Type Define
	+----------+---------------------------------+
	|   TYPE   |             DEFINE              |
	+__________+_________________________________+
	| BOOL     | typedef int    BOOL;            |
	| CHAR     | typedef char   CHAR;            |
	| CHARP    | typedef char*  CHARP;           |
	| FLOAT    | typedef float  FLOAT;           |
	| LONG     | typedef long   LONG;            |
	+----------+---------------------------------+

	Study
	   
	   1. At the end of the calling function cleans up the stack after the function 
	      call to the principal
	  	    _pascal   : Clean up stack space, calls being
	  	    _stdcall  : Clean up stack space, calls being
	  	    _cdecl    : Calls to clean up the stack space
	   2. Mediators stacking direction
	        _pascal   : From left to right in order of arguments is stored on the stack
			_stdcall  : Arguments on the stack from right to left in order to save
			_cdecl    : Arguments on the stack from right to left in order to save


	Version
		 Private Version
				1.0.3.1 (Mina F)
				2012-10-17 Last  270
				2012-10-17 Last  291
				2012-10-17 Last  308
				2012-10-18 Last  332
		 Release
				Default Data
 */
#include "rstdio.h"
#include "rnull.h"
#include "rstr.h"
#ifdef __cplusplus 
extern "C" {
#endif
#if !defined(BOOL) && !defined(R_API) && !defined(_R_API_ALL_)
typedef int    BOOL;
#define BOOL_  BOOL
#endif /* BOOL */
#if !defined(CHAR) && !defined(R_API) && !defined(_R_API_ALL_)
typedef char   CHAR;
#define CHAR_  CHAR
#endif /* CHAR */
#if !defined(CHARP) && !defined(R_API) && !defined(_R_API_ALL_)
typedef char*  CHARP;
#define CHARP_ CHARP
#endif
#if !defined(FLOAT) && !defined(R_API) && !defined(_R_API_ALL_)
typedef float  FLOAT;
#define FLOAT_ FLOAT
#endif
#if !defined(LONG) && !defined(R_API) && !defined(_R_API_ALL_)
typedef long  LONG;
#define LONG_ LONG
#endif
#if !defined(R_API_Reserved) 
#define VOID                void
#define PASCAL              _pascal
#define CDECL               _cdecl
#define FALSE               0
#define TRUE                1
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef unsigned long       DWORD;
typedef unsigned int        UINT;
#endif /* ROLLRAT */
typedef void *va_list;
#define __size(x) ((sizeof(x)+sizeof(int)-1) & ~(sizeof(int)-1))
#define va_start(ap, parmN) ((void)((ap) = (va_list)((char *)(&parmN)+__size(parmN))))
#define va_arg(ap, type) (*(type *)(((*(char * *)&(ap))+=__size(type))-(__size(type))))
#define va_end(ap)          ((void)0)
#if !__STDC__
#define _va_ptr             (...)
#endif /* End of STDARG */
#define IF       if
#define ELSE     else if
#define IFELSE   else
#define FOR      for
#define FORI     int i = 0;
#define FORK     int k = 0;
#define FORF     int f = 0;
#define BRK      break;
#define WHI      while(
#define WHIT     while(TRUE)
#define Ret      return
#define SWT(t)   switch(t)
#define CASE(t)  case(t):
#define SIZE(F)  sizeof(F)
#define TDEF(d)  typedef void d
#define TDEF_(d,i) typedef d i
#define TEMP     template
#define LDOUBLE  long double // __int64
#define ONE(f)   f + 1
#define _Ret_Null_Void_ return ;
#define _Ret_Null_Int_ return 0;
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
#define __filewrite "w+"
#define __filetext  "a+"
#define __fileread  "r"
#define _string     "%s"
#define _float      "%f"
#define _int        "%d"
char * strtok ( char * str, const char * delimiters );
#if !defined(R_SU)
#define DECAL_INT(Type_F) typedef UINT Type_F
#define DECAL_CHAR(Type_F) typedef BTYE Type_F
#define DECAL_LONG(Type_F) typedef DWORD Type_F
#define DECAL_SHORT(Type_F) typedef WORD Type_F
#endif


UINT CDECL GetWindowCursurXY(void);
UINT CDECL GetWindowCursur(void);
UINT CDECL GetCursurImp(void);
UINT CDECL GetProgrambleValue(void);

#ifndef Rollrat_Funtion_Group
#ifndef R_ERROR_Funtion
#define R_ERROR_Funtion
/* R_ERROR_Funtion */
#define R_Error_WESS_A 0x00000012
#define R_Error_WESS_E 0x00000013
/* Find Error Library. */
#define R_Error_WESS_CACL_MX              0x07000000 // Max of Error Code
#define R_Error_WESS_CACL_MN              0x06000000 // Min of Error Code
#define R_Error_WESS_CACL_OF              0x06000001 // Overflow
#define R_Error_WESS_CACL_OF_             0x06001001
#define R_Error_WESS_CACL_IM              0x06000201 // Imaginary
#define R_Error_WESS_CACL_IM_             0x06001201
#define R_Error_WESS_CACL_Solve           0x06000101
#define R_Error_WESS_CACL_Solve_          0x06001101
#define R_Error_WESS_CACL_Solve_Answer    0x06000102
#define R_Error_WESS_CACL_Solve_Answer_   0x06001102

UINT WriteErrorSercher_Stamp(
	UINT uSearchCode, DWORD fSearchCode);
#define fWriteErrorSercher(uSearchCode, fSearchCode) \
	WriteErrorSercher_Stamp(uSearchCode, fSearchCode)
UINT WriteErrorSercher_Stamp(UINT uSearchCode,DWORD fSearchCode){
	IF(uSearchCode > 0){
		IF(fSearchCode < 0){
			Ret R_Error_WESS_E;
		}ELSE(fSearchCode > 0){
			/* Calculation Error */
			IF(fSearchCode > R_Error_WESS_CACL_MN && 
				R_Error_WESS_CACL_MX < R_Error_WESS_CACL_MX){
				IF(fSearchCode == R_Error_WESS_CACL_OF)
					Ret R_Error_WESS_CACL_OF_;
				ELSE(fSearchCode == R_Error_WESS_CACL_IM)
					Ret R_Error_WESS_CACL_IM_;
				ELSE(fSearchCode == R_Error_WESS_CACL_Solve)
					Ret R_Error_WESS_CACL_Solve_;
				ELSE(fSearchCode == R_Error_WESS_CACL_Solve_Answer)
					Ret R_Error_WESS_CACL_Solve_Answer_;
				//... etc...
			}
		}
	}ELSE(uSearchCode < 0){

	}
}
#endif
#endif


#define P_Find_ERROR_Funtion
/* Error Group */
#define ErrorCodeSercher 0x00000001
typedef struct {
	UINT hTotal;
	UINT hAverage;
	UINT hDevSum;
} MATH;
DWORD WriteErrorComposition(UINT rErrorCode,CHAR mErrorMessage[]);
UINT WriteErrorSercher(UINT uSearchCode,DWORD fSearchCode);
BYTE WriteErrorMessage(CHARP fAddress);
DWORD WriteErrorSet(UINT rErrorCode,BYTE mErrorMessage);
DWORD WriteErrorComposition(UINT _Retype_Declaration_ rErrorCode,
	CHAR _Retype_Declaration_ mErrorMessage[]){
	_Ret_Dword_ Ret WriteErrorSet(
		WriteErrorSercher(ErrorCodeSercher,rErrorCode),
		WriteErrorMessage(mErrorMessage));}
UINT WriteErrorSercher(UINT uSearchCode,DWORD fSearchCode){
	P_Find_ERROR_Funtion fWriteErrorSercher(uSearchCode,fSearchCode);}
BYTE WriteErrorMessage(CHARP fAddress){
	P_Find_ERROR_Funtion}
DWORD WriteErrorSet(UINT rErrorCode,BYTE mErrorMessage){
	P_Find_ERROR_Funtion}
UINT ReadCharGetArrange(CHAR _Retype_Declaration_ rCharText[]){
		FORI FOR(;;i++){IF(rCharText[i] == __charnull)BRK}Ret i;}
CHAR ReadCharGetArrangeSt(CHAR _Retype_Declaration_ rCharText[],
	UINT sCharNumberSt){Ret rCharText[sCharNumberSt];}
UINT ReadCharGetArrangeChar(CHAR _Retype_Declaration_ rCharText[],
	CHAR sCharText){FORI UINT MaxCharArrange = ReadCharGetArrange(rCharText);
		FOR(;;i++){IF(rCharText[i] == sCharText)Ret ONE(i);
			ELSE(i == MaxCharArrange)BRK}_Ret_Null_Int_}
UINT ReadCharGetSizeof(CHAR _Retype_Declaration_ rCharText[]){
	Ret SIZE(rCharText);}
CHAR ReadCharGetCutter(CHAR _Retype_Declaration_ rCharText[],
	UINT sCharNumberSt){UINT MaxCharArrange = ReadCharGetArrange(rCharText);
		Ret rCharText[MaxCharArrange - sCharNumberSt];}
UINT ReadCharGetSpace(CHAR _Retype_Declaration_ rCharText[]){
	UINT MaxCharArrange = ReadCharGetArrange(rCharText);UINT SpaceValue = 0;
	FORI FOR(;i=MaxCharArrange;i++)
		IF (rCharText[i] == __charspace)SpaceValue++;Ret SpaceValue;}
UINT ReadCharGetChar(CHAR _Retype_Declaration_ rCharText[],CHAR rChar){
	UINT MaxCharArrange = ReadCharGetArrange(rCharText);UINT SpaceValue = 0;
	FORI FOR(;i=MaxCharArrange;i++)
		IF (rCharText[i] == rChar)SpaceValue++;Ret SpaceValue;}
/* Check Error : ReadCharAttachChar // Ret AttachChar; */
CHARP ReadCharAttachChar(CHAR fCharText[], CHAR sCharText[]){
	UINT MaxCharArrangeF = ReadCharGetArrange(fCharText);
	UINT MaxCharArrangeS = ReadCharGetArrange(sCharText);
	UINT SumArrange = MaxCharArrangeF+MaxCharArrangeS;
	UINT ArrangeMinas = MaxCharArrangeF - 1;
	CHARP AttachChar;FORI FOR(;ArrangeMinas=i;i++){
		AttachChar[i] = fCharText[i];}FOR(;SumArrange=i;i++){
		AttachChar[i] = sCharText[i];}Ret AttachChar;}
/* Check Warning : ReadCharSearchWord // ALL */
UINT ReadCharSearchWord(CHAR _Retype_Declaration_ rCharText[],CHAR fCharText[]){
	UINT MaxCharArrangeR = ReadCharGetArrange(rCharText);
	UINT MaxCharArrangeF = ReadCharGetArrange(fCharText);
	IF(MaxCharArrangeR <= MaxCharArrangeF)_Ret_Null_Int_
	IFELSE{FORI FOR(;MaxCharArrangeR=i;i++){FORK FOR(;MaxCharArrangeR=k;k++){
	IF(rCharText[i] = fCharText[k]){FORF FOR(;MaxCharArrangeR=f;f++){
	IF(rCharText[i+1] = fCharText[f]){IF(f = MaxCharArrangeR)Ret ONE(i);}IFELSE BRK}}}}}}
UINT ReadCharAttachArrange(CHAR rCharText[],CHAR fCharText[]){
	UINT MaxCharArrangeF = ReadCharGetArrange(fCharText);
	UINT MaxCharArrangeS = ReadCharGetArrange(fCharText);
	UINT SumArrange = MaxCharArrangeF + MaxCharArrangeS;Ret SumArrange;}
/* Check Warning : ReadCharDeletePart // ALL */
VOID ReadCharDeletePart(CHAR fCharText[],CHAR CharArrange){
	UINT MaxCharArrange = ReadCharGetArrange(fCharText);
	FORI FOR(;i=MaxCharArrange;i++){IF(fCharText[i] == CharArrange){
			fCharText[i] = NULL;}}}
CHARP ReadCharSplit(CHAR rCharText[],CHAR fSplit[],UINT Arrange){
	CHAR * SplitData;FORI SplitData = strtok(rCharText,fSplit);
	WHI i != Arrange){SplitData = strtok(NULL,fSplit);i++;}Ret SplitData;}

VOID FileReadMake(CHAR fAddress[]){
	FILE *fstream;fstream = fopen(fAddress,__filewrite);fclose(fstream);}
VOID FileReadWriteText(CHAR fAddress[],CHAR rText[]){
	FILE *fstream = fopen(fAddress,__filewrite);
	fprintf(fstream, _string, rText);fclose(fstream);}
VOID FileReadGetText(CHAR fAddress[],CHAR rText[],UINT mArrange){
	FILE *fstream = fopen(fAddress,__fileread);
	fgets(rText,mArrange,fstream);}


#ifdef __cplusplus 
}
#endif



