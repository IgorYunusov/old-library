/*-------------------------------------------------

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

-------------------------------------------------*/

#pragma once
#ifndef _ROLLRAT_CHAR_
#define _ROLLRAT_CHAR_

#include <iostream>

#include "rutil.h"

#if defined(_EX_SUCCESS)

/*
COMMON Lib Start*/
_X_LIB_BEGIN
	
	class Char
	{
	public:

		char GetCharInt(const char oper)
			{
				if('0' <= oper && oper <= '9')
					return oper - '0';
				if('A' <= oper && oper <= 'F')
					return oper - 'A' + 10;
				if('a'<= oper && oper <= 'f')
					return oper - 'a' + 10;
				return 0;
			}

		char GetIntChar(const char oper)
			{
				if(oper == 0)
					return 0;
				if(0 <= oper && oper <= 9)
					return oper + '0';
				if(10 <= oper && oper <= 16)
					return oper + 'a' - 10;
				return 0;
			}

		char CGetCharInt(const char oper)
			{
				if('0' <= oper && oper <= '9')
					return oper - '0';
				if(oper == 0)
					return 0;
			}

		char CGetIntChar(const char oper)
			{
				if(0 <= oper && oper <= 9)
					return oper + '0';
				if(oper == 0)
					return 0;
			}

		char* ReverseChar(char* oper)
			{
				int LEN = strlen(oper);
				char* buf = new char[LEN];
				for(int f = 0; f<=LEN; f++)
					buf[f] = 0;
				int i=0,k=0,j; 
				while(oper[i++]!=0)
					k++;
				for (i = 0, j = k - 1; i < k,j >= 0; i++, j--)
					buf[i] = oper[j];
				return buf;
			}

		char* ReverseChar(const char* oper)
			{
				int LEN = strlen(oper);
				char* buf = new char[LEN];
				for(int f = 0; f<=LEN; f++)
					buf[f] = 0;
				int i=0,k=0,j; 
				while(oper[i++]!=0)
					k++;
				for (i = 0, j = k - 1; i < k,j >= 0; i++, j--)
					buf[i] = oper[j];
				return buf;
			}

		char* ReverseChar(char* oper) const
			{
				int LEN = strlen(oper);
				char* buf = new char[LEN];
				for(int f = 0; f<=LEN; f++)
					buf[f] = 0;
				int i=0,k=0,j; 
				while(oper[i++]!=0)
					k++;
				for (i = 0, j = k - 1; i < k,j >= 0; i++, j--)
					buf[i] = oper[j];
				return buf;
			}

		char* ReverseChar(const char* oper) const
			{
				int LEN = strlen(oper);
				char* buf = new char[LEN];
				for(int f = 0; f<=LEN; f++)
					buf[f] = 0;
				int i=0,k=0,j; 
				while(oper[i++]!=0)
					k++;
				for (i = 0, j = k - 1; i < k,j >= 0; i++, j--)
					buf[i] = oper[j];
				return buf;
			}

		char* Trim(char* buf)
			{
				RTrim(buf);
				return LTrim(buf);
			}

		char* RTrim(char* buf)
			{
				char t[4096];
				char* end;
				strcpy(t, buf);
				end = t + strlen(t) - 1;
				while (end != t && isspace(*end))
					end--;
				*(end + 1) = 0;
				buf = t;
				return buf;
			}

		char* LTrim(char* buf)
			{
				char* begin;
				begin = buf;
				while (*begin != 0) {
					if (isspace(*begin))
						begin++;
					else {
						buf = begin;
						break;
					}
				}
				return buf;
			}
	};

_X_LIB_END
/*COMMON Lib End
*/

#endif

#endif