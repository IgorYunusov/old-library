/*=================================================

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

=================================================*/

#pragma once
#ifndef _x_lib_plus
#define _x_lib_plus

#include <iostream>
#include "xstrfmy.h"

#if defined(_EX_SUCCESS)
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

	#define MAX_CHAR 32767

	typedef enum Sign
	{
		minus	= -1,
		zero	= 0,
		plus	= 1,
	};
	
	class UInteger
		: public Char
	{
	public:

		UInteger()
			: Sign(zero), Length(0)
			{ // entry point
				uintegerbuf = new char[MAX_CHAR];
				for(register int i = 0; i <= MAX_CHAR; i++)
					uintegerbuf[i] = 0;
				uintegerbuf[0] = '0';
 			}

		~UInteger()
			{
				delete[] uintegerbuf;
			}

		void SetLength()
			{ // set this length
				register long long i = 0, len = 0;
				while(uintegerbuf[i++] != 0);
				Length = len;
			}

		Sign GetSign() const
			{ // get sign
				return Sign;
			}

		long long GetLenth() const
			{ // get lenth
				return Length;
			}

		char* getbuf() const
			{
				return Char::ReverseChar(uintegerbuf);
			}

		void operator++() 
			{ // increase integer
				for(register long long i = 0; i <= Length + 1; i++)
				{
					if(uintegerbuf[i] == 0)
					{
						uintegerbuf[i] = '1';
						goto exit_for;
					}
					if('0' <= uintegerbuf[i] && uintegerbuf[i] <= '8')
					{
						uintegerbuf[i] = uintegerbuf[i] + 1;
						goto exit_for;
					}
					if(uintegerbuf[i] == '9')
						uintegerbuf[i] = '0';
				}
exit_for:
				SetLength();
			}

		void operator--() 
			{ // decrease integer
				for(register long long i = 0; i <= Length + 1; i++)
				{
					if('1' <= uintegerbuf[i] && uintegerbuf[i] <= '9')
					{
						uintegerbuf[i] = uintegerbuf[i] - 1;
						goto exit_for;
					}
					if(uintegerbuf[i] == '0')
						uintegerbuf[i] = '9';
				}
exit_for:
				SetLength();
			}

		void operator+=(const int me)
			{
				char* buf = new char[MAX_CHAR];
				itoa(me, buf, 10);
				for(register long long i = 0; i <= strlen(buf); i++)
					if ('0' <= buf[i] && buf[i] <= '9');
						else buf[i] = 0;
				operator+=(buf);
				delete[] buf;
			}

		void operator+=(const char* _me)
			{// Memory 520MB -> 1.7MB
				char* me ;//= new char[MAX_CHAR];
				//for(int i = 0; i <= MAX_CHAR; i++)
				//	me[i] = 0;
				me = Char::ReverseChar(_me);
				for(register long long i = 0; i <= strlen(me) - 1; i++)
				{
					if(0 <= (Char::CGetCharInt(me[i]) + Char::CGetCharInt(uintegerbuf[i])) && (Char::CGetCharInt(me[i]) + Char::CGetCharInt(uintegerbuf[i])) < 10)
					{
						uintegerbuf[i] = Char::CGetIntChar(Char::CGetCharInt(me[i]) + Char::CGetCharInt(uintegerbuf[i]));
					}
					else if(10 <= (Char::CGetCharInt(me[i]) + Char::CGetCharInt(uintegerbuf[i])) && (Char::CGetCharInt(me[i]) + Char::CGetCharInt(uintegerbuf[i])) <= 18 )
					{
						uintegerbuf[i] = Char::CGetIntChar(Char::CGetCharInt(me[i]) + Char::CGetCharInt(uintegerbuf[i]) - 10);
						plusencomecharinnexparameter(i + 1);
					}
				}
			}

		void operator-=(const char* _me)
			{
				char* me = new char[MAX_CHAR];
				for(register int i = 0; i <= MAX_CHAR; i++)
					me[i] = 0;
				me = Char::ReverseChar(_me);
				for(register long long i = 0; i <= strlen(me) - 1; i++)
				{
					if(1 <= (Char::CGetCharInt(uintegerbuf[i]) - Char::CGetCharInt(me[i])) && (Char::CGetCharInt(uintegerbuf[i]) - Char::CGetCharInt(me[i])) < 10)
					{
						uintegerbuf[i] = Char::CGetIntChar(Char::CGetCharInt(uintegerbuf[i]) - Char::CGetCharInt(me[i]));
					}
				}
			}

		void plusencomecharinnexparameter(long long state)
			{
				if(uintegerbuf[state] == '9')
					plusencomecharinnexparameter(state + 1);
				else
					if(uintegerbuf[state] == 0)
						uintegerbuf[state] = '1';
					else
						uintegerbuf[state] = uintegerbuf[state] + 1;
			}

		void minusencomecharinnexparameter(long long state)
			{
				if(uintegerbuf[state] == '0')
					minusencomecharinnexparameter(state + 1);
				else
					if(uintegerbuf[state] == 0)
						uintegerbuf[state] = '9';
					else
						uintegerbuf[state] = uintegerbuf[state] - 1;
			}

		unsigned long long checkprime(unsigned long long num)
			{
				unsigned long long sqrtprimenum = (unsigned long long)sqrt(num);
				register unsigned long long div = sqrtprimenum;
				for(; num % div; div--);
				return div;
			}
		
		void operator=(const UInteger& me){uintegerbuf = Char::ReverseChar(me.uintegerbuf); }
		void operator=(const int me){itoa(me, uintegerbuf, 10);uintegerbuf = Char::ReverseChar(uintegerbuf);SetLength();}
		void operator=(const char* cp){uintegerbuf = Char::ReverseChar(cp);SetLength();}

	private:

		char* uintegerbuf;
		Sign Sign;
		long long Length;

	};

	std::ostream &operator <<(std::ostream &os, const UInteger& x) 
	{
		if (x.GetSign() == Sign::minus)
			os << '-';
		os << x.getbuf();
		return os;
	}

_X_LIB_END
#endif

#endif
/*
 *	The rollrat x_library
 *  Updated : 2013-04
 *	http://blog.naver.com/rollrat
 *  Copyright (c) 2009-2013 by rollrat. All right reserved.
 *  For more information, refer to the documentation on the license.
V0.1:0012****/