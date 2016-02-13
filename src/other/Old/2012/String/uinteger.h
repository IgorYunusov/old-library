/*-------------------------------------------------

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

-------------------------------------------------*/

#pragma once
#ifndef _ROLLRAT_UINTEGER_
#define _ROLLRAT_UINTEGER_

#include "char.h"

#if defined(_EX_SUCCESS)

/*
COMMON Lib Start*/
_X_LIB_BEGIN
	
	#define MAX_CHAR 32767

	typedef enum Sign
	{
		minus	= -1,
		zero	= 0,
		plus	= 1,
	};

	typedef enum Signe
	{
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
/*COMMON Lib End
*/

#endif

#endif