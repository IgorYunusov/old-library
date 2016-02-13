/*************************************************************************

   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:

   WideCharToUnicode.h

Project:

	RollRat WChar to TextEncoding or inversion.

------
   AUTHOR: HyunJun Jeong  2015-08-16

***************************************************************************/

#ifndef _WIDECHARTOUNICODE_fc994cefd170d62b5841c2c50a078d5a_
#define _WIDECHARTOUNICODE_fc994cefd170d62b5841c2c50a078d5a_

#include <tchar.h>
#include "CString.h"

class WideCharToUnicde {
public:

	char *Trandform(const wchar_t *str)
	{
		size_t Length = 0;
		const wchar_t *ptr = str;

		for( ; *ptr; ptr++)
		{
			if ( *ptr < 0xff )
				Length++;
			else
				Length += 6;
		}

		char *ret = new char[Length + 1];

		for ( int i = 0, j = 0; str[i]; i++ )
		{
			if ( str[i] < 0xff ) 
				ret[j++] = str[i];
			else
			{
				ret[j] = '\\';
				ret[j + 1] = 'u';
				int wch = (int)(str[i]);
				for (int k = 5; k > 1; k--)
				{
					int w_mod;
					if ((w_mod = (wch % 16)) < 10)
						ret[j + k] = w_mod + '0';
					else
						ret[j + k] = w_mod - 10 + 'A';
					wch /= 16;
				}

				j += 6;
			}
		}

		ret[Length] = 0;

		return ret;
	}

	wchar_t *InverseTransform(const char *set)
	{
		size_t Length = 0;
		const char *ptr = set;

		for( ; *ptr; )
		{
			if (*ptr == '\\' && * (ptr +1) == 'u')
			{
				if (byxdigit(* (ptr + 2) ) > -1)
					if (byxdigit(* (ptr + 3) ) > -1)
						if (byxdigit(* (ptr + 4) ) > -1)
							if (byxdigit(* (ptr + 5) ) > -1)
							{
								ptr += 6;
							}
			}
			else 
				ptr++;
			Length += 1;
		}

		wchar_t *ret = new wchar_t[Length + 1];

		for ( int i = 0 ; *set; i++ )
		{
			if (*set == '\\' && *( set+1 ) == 'u')
			{
				if (byxdigit(* (set + 2) ) > -1)
					if (byxdigit(* (set + 3) ) > -1)
						if (byxdigit(* (set + 4) ) > -1)
							if (byxdigit(* (set + 5) ) > -1)
							{
								int hexs;
								hexs =             byxdigit(*(set + 2));
								hexs = hexs * 16 + byxdigit(*(set + 3));
								hexs = hexs * 16 + byxdigit(*(set + 4));
								hexs = hexs * 16 + byxdigit(*(set + 5));
								ret[i] = (wchar_t)hexs;
								set += 6;
							}
			}
			else
				ret[i] = *set++;
		}

		ret[Length] = 0;

		return ret;
	}

private:

	int byxdigit(char ch)
	{
		if (isdigit(ch))
			return ch - '0';
		if ('A' <= ch && ch <= 'F')
			return ch - 'A' + 0xa;
		return -1;
	}

};

#endif