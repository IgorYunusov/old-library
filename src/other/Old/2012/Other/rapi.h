/*
 *
 *			ROLLRAT SOFTWARE SUBROUTINE
 *			SINCE : 2009 - 2012
 *
 *			Version: 1.2.1.5
 *
 *
 *			Copyright (c) ROLLRAT. All Rights Reserved.
 *
 *
 ***************************************************************************/

#pragma once
#if !defined(__R_API__) /* !(__R_API__)    */
#define __R_API__
#include "rapifunc.h"
#include "rapiasc.h"
#include "rRetype.h"
#include "rcalc.h"
#include "rinfiniti.h"
#include "rsaner.h"
#include "rascii.h"
#include "rdefine.h"
#include "rtypeset.h"
#include "rstringall.h"
#include "rstring.h"
#include "rstack.h"
#include "rmath.h"
#ifndef _MATH_R_
#define _MATH_R_ /* !(_MATH_R_) */
__ldouble GetSin(UINT fNumber)
{
	__if(fNumber > 90 && fNumber <= 180)
		__ret sin(abs(360 - fNumber)) __re
	__else
		__ret sin(abs(fNumber)) __re
}
__ldouble GetCos(UINT fNumber)
{
	__if(fNumber > 270 && fNumber <= 360)
		__ret cos(abs(360 - fNumber)) __re
	__else
		__ret cos(abs(fNumber)) __re
}
__ldouble GetTan(UINT fNumber)
{
	__if(fNumber > 180 && fNumber <= 270)
		__ret sin(abs(360 - fNumber)) / cos(abs(360 - fNumber))  __re
	__else
		__ret sin(abs(fNumber)) / cos(abs(fNumber)) __re
}
__ldouble GetTanSC(UINT fNumber)
{
	__if(fNumber > 180 && fNumber <= 270)
		__ret tan(abs(360 - fNumber)) __re
	__else
		__ret tan(abs(fNumber)) __re
}
#endif /* !(_MATH_R_) */
#ifndef _Char_ /* !(_Char_) */
#define _Char_ /* English   */
VOID GetCharLower(__const CHAR tCharText,CHAR fCharText)
{
	__int i = 0 __re
	__int f = 0 __re
	i = GetCharValue(tCharText) __re
	__for(__re f<=i __re f++)
	{
		__if(tCharText[f] == NULL)
		{
			fCharText[f] = NULL __re
			__brk
		}
		fCharText[f] = tCharText[f] + 32 __re
	}
}
VOID GetCharUpper(__const CHAR tCharText,CHAR fCharText)
{
	__int i = 0 __re
	__int f = 0 __re
	i = GetCharValue(tCharText) __re
	__for(__re f<=i __re f++)
	{
		__if(tCharText[f] == NULL)
		{
			fCharText[f] = NULL __re
			__brk
		}
		fCharText[f] = tCharText[f] - 32 __re
	}
}
VOID GetCharLU(__const CHAR tCharText,CHAR fCharText)
{
	__int i = 0 __re
	__int f = 0 __re
	i = GetCharValue(tCharText) __re
	__for(__re f<=i __re f++)
	{
		__if(tCharText[f] == NULL)
		{
			fCharText[f] = NULL __re
			__brk
		}
		__if(tCharText[f] >= 'A' && tCharText[f] < 'a')
		{
			fCharText[f] = tCharText[f] + 32 __re
		}
		__ifelse(tCharText[f] >= 'a' && tCharText[f] <= 'z')
		{
			fCharText[f] = tCharText[f] - 32 __re
		}
	}
}
VOID GetCharPutNull(__const CHAR tCharText, __const BYTE fCharText, CHAR iCharText)
{
	__int i = 0 __re
	__int f = 0 __re
	i = GetCharValue(tCharText) __re
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
VOID GetCharPutChar(__const CHAR tCharText, __const CHAR yCharText,__const BYTE pCharText, __const BYTE gCharText, CHAR iCharText)
{
	__int i = 0 __re
	__int f = 0 __re
	__int t = 0 __re
	__char P_Text[ enough_lenth_putchar ] __re
	__char G_Text[ enough_lenth_putchar ] __re
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
VOID GetCharStackCopy(CHAR rCharText, UINT fNumber, CHAR fCharText)
{
	__int i = 0 __re
	__for(__re i<=fNumber __re i++)
	{
		fCharText[i] = rCharText[i];
	}
}
#endif /* !(_Char_)    */
#endif /* !(__R_API__) */