/*************************************************************
  
       ROLLRAT TETO Script

       COPYRIGHT @ ROLLRAT. 2014 ALL RIGHTS RESERVED.

**************************************************************/

#ifndef _TETO_SCRIPT_
#define _TETO_SCRIPT_

#include <string.h>
#include <stdlib.h>

char * TextPartialMatchA(const char * _T, const char * _S);
wchar_t * TextPartialMatchW(const wchar_t * _T, const wchar_t * _S);

#define _None						0x0000
#define _SetWindowsStyleCrLf		0x0001
#define _GetAssemblyCode			0x0002
#define _Optimization				0x0004
#define _CommandIsCrLf				0x0008

char * StdAssembleCode(const char * _Code, const char _Cr, const char _Lf, int option);
char * assemblycode_001_teto_s(const char * _Code, const char _Cr, const char _Lf);
char * assemblycode_001_teto_t(const char * _Code);
char * assemblecode_l(char  _JCode[0xFFFF][128]);

#ifdef _DEBUG
#define _PrintDebugString
#endif

#endif