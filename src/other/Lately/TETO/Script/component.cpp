/*************************************************************
  
       ROLLRAT TETO Script

	   Version 1.0

       COPYRIGHT @ ROLLRAT. 2014 ALL RIGHTS RESERVED.

**************************************************************/

#include "TETO. Script.h"

#include <string>
#include <windows.h>

#if defined(_PrintDebugString)
#define _DebugString(_tt)	OutputDebugString(L#_tt)
#endif

char * StdAssembleCode(const char * _Code, const char _Cr, const char _Lf, int option)
{
	char _cr = _Cr, _lf = _Lf;
	char * _assemblecode ;
	if (option & _SetWindowsStyleCrLf)
		_cr = '\r', _lf = '\n';
	if(option & _CommandIsCrLf)
		_assemblecode = assemblycode_001_teto_t(_Code);
	else
		_assemblecode = assemblycode_001_teto_s(_Code, _cr, _lf);
	return 0;
}

char * assemblycode_001_teto_s(const char * _Code, const char _Cr, const char _Lf)
{
	
	return 0;
}

char * assemblycode_001_teto_t(const char * _Code)
{
	char code[512][128] = {0, };
	int i, j;
	const char * _Ptr = _Code;
	for (i = 0, j = 0; *_Ptr; _Ptr++)
		if (*_Ptr < 0x20)
			j++, i = 0;
		else
			code[j][i++] = *_Ptr;
	return assemblecode_l(code);
}

char * assemblecode_l(char _JCode[512][128])
{
	int j;
	std::string str;
	for( j = 0; j < 512; j++)
	{
		switch(_JCode[j][0])
		{
		case '#':
			// Annotation Process
			continue;
		case '\0':
			break;
		default:
			;
		}
	}
	return 0;
}

int main()
{
	StdAssembleCode("#asdfasdfasdfas\nasdfqwerqwerqwer", 0, 0, _CommandIsCrLf);
}