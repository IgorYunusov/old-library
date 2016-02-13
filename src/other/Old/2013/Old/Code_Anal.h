/*
 *	Rollrat Api
 *
 *	Function Gropup
 */

#if !defined(_R_API_Code_Anal_)
#define _R_API_Code_Anal_

#include "Api_String.h"

#define _Tab "	"

DWORD StartSuccess = 0;

DWORD Code_Head(OCHAR rCharText)
{
	char Buf[10];
	strcpy(Buf,Split(rCharText,' ',0));
	if (Buf == "<_")
	{
		StartSuccess = 1;
		return 0;
	}
	return 1;
}

#endif