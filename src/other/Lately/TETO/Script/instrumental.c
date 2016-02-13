/*************************************************************
  
       ROLLRAT TETO Script

	   Version 1.0

       COPYRIGHT @ ROLLRAT. 2014 ALL RIGHTS RESERVED.

**************************************************************/

#include "TETO. Script.h"

#include <string.h>
#include <stdlib.h>

char * TextPartialMatchA(const char * _T, const char * _S)
{
#if defined(_DEBUG)
	char * _Ptr = (char *)_T, * _Sub1, * _Sub2;
	for( ; *_Ptr; _Ptr++)
		{
		_Sub1 = _Ptr;
		_Sub2 = (char *)_S;
		while (*_Sub1 && *_Sub2 && !(*_Sub1 - *_Sub2))
			_Sub1++, _Sub2++;
		if (!*_Sub2)
			return _Ptr;
		}
	return 0;
#else
	return strstr(_T, _S);
#endif
}

wchar_t * TextPartialMatchW(const wchar_t * _T, const wchar_t * _S)
{
#if defined(_DEBUG)
	wchar_t * _Ptr = (wchar_t *)_T, * _Sub1, * _Sub2;
	for( ; *_Ptr; _Ptr++)
		{
		_Sub1 = _Ptr;
		_Sub2 = (wchar_t *)_S;
		while (*_Sub1 && *_Sub2 && !(*_Sub1 - *_Sub2))
			_Sub1++, _Sub2++;
		if (!*_Sub2)
			return _Ptr;
		}
	return 0;
#else
	return wcsstr(_T, _S);
#endif
}