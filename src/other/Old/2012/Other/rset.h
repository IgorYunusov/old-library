/*************************************************************************
 *
 *				RollRat Software Header.  # C code
 *
 *				Version 1.0
 *
 *              HEADER << rset.h >>
 *
 *				Copyright (c) 2012 Rollrat. All right reserved.
 *
 */

#include "rnull.h"
#include "rbuf.h"

#if !defined(_Setting_RollRat_Position_)
#define _Setting_RollRat_Position_

// rollrat software char controler.

char GetCharPChar(const char * cInp,int F){return cInp[F];}
char NextChar(const char cInput){return cInput+1;}
char PrevChar(const char cInput){return cInput-1;}
char * FSplit(char * pStr,char split) 
{
	static char Findp[ _R_buf_ _R_STR_SPLIT_MAX_ ]; 
	static char *pOrg; 
	int i = 0; 
	if (pStr) { 
		pOrg=pStr; 
	} 
	do{ 
		if (*pOrg == split) { 
			pOrg++; 
			goto Break; 
		}else{ 
			Findp[i] = *pOrg; 
			pOrg++; 
			i++; 
		} 
	}while(*pOrg != '\0') ;
Break: 
   Findp[i] = '\0'; 
   return Findp; 
} 
char * LSplit(char * pStr, char split)
{
	static char Findp[ _R_buf_ _R_STR_SPLIT_MAX_ ]; 
	static char *pOrg; 
	int i = 0;
	int f = 0;
	if (pStr){ 
      pOrg=pStr; 
    } 
	do{
		if (*pOrg == split){
			f = 1;
		}
		pOrg++;
		if (f==1){
			Findp[i] = *pOrg;
			i++;
		}
	}while(*pOrg != '\0');
	Findp[i] = '\0'; 
    return Findp; 
}
char * SplitFuntion(char * pStr, char split, int Max,int Value){
	static char * F [ _R_buf_ _R_STR_SPLIT_MAX_ ];
	int i;
	int f;
	F[0] = FSplit(pStr,split);
	F[1] = LSplit(pStr,split);
	Max += 2;

	for(i=2;i=Max;i++)
	{
		f = i - 1;
		F[i]=LSplit(F[f],split);
	}
	return F[Value];
}


#endif
