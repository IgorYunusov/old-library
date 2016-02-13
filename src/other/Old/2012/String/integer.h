/*-------------------------------------------------

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

-------------------------------------------------*/

#pragma once
#ifndef _ROLLRAT_INTEGER_
#define _ROLLRAT_INTEGER_

#include <iostream>
#include "vector.h"

typedef enum Sign
{
	minus	= -1,
	zero	= 0,
	plus	= 1,
};

class Integer
{
public:

	Integer()
		: LEN(256)
	{
		EX_BUFFER = new char[256];
		for(int i = 0; i <= 256; i++)
			EX_BUFFER[i] = 0;
		EX_BUFFER[0] = '0';
	}

	void operator++()
	{
		for(long long i = 0; i <= 256; i++)
		{
			if(EX_BUFFER[i] == 0)
			{
				EX_BUFFER[i] == '1';
				goto END_OPER_PP;
			}
			if('0' <= EX_BUFFER[i] && EX_BUFFER[i] <= '8')
			{
				EX_BUFFER[i] = EX_BUFFER[i] + 1;
				goto END_OPER_PP;
			}
			if(EX_BUFFER[i] == '9')
				EX_BUFFER[i] = '0';
		}
		END_OPER_PP:
		LEN = strlen(EX_BUFFER);
	}

	void operator--()
	{
		for(long long i = 0; i <= 256; i++)
		{
			if('1' <= EX_BUFFER[i] && EX_BUFFER[i] <= '9')
			{
				EX_BUFFER[i] = EX_BUFFER[i] - 1;
				goto END_OPER_PP;
			}
			if(EX_BUFFER[i] == '0')
				EX_BUFFER[i] = '9';
		}
		END_OPER_PP:
		LEN = strlen(EX_BUFFER);
	}

	void operator+=(const char* oper)
	{
		for(long long i = 0; i <= atoi(oper); i++)
			operator++();
		LEN = strlen(EX_BUFFER);
	}

	void charplus(const char oper, const int i)
	{
		if(oper != '0')
		{
			if(('1' <= EX_BUFFER[i]) && (EX_BUFFER[i] <= ('9' - getcharint(oper))))
				EX_BUFFER[i] = EX_BUFFER[i] + getcharint(oper);
			if(EX_BUFFER[i] == '9')
			{
				EX_BUFFER[i] = '0';
				charplus('1', i + 1);
			}
		}
		LEN = strlen(EX_BUFFER);
	}

	char getcharint(const char oper)
	{
		return oper - '0';
	}
	char* reversechar(char* oper)
	{
		char* buf = new char[LEN];
		for(int f = 0; f<=LEN; f++)
			buf[f] = 0;
		int i=0,k=0,j; 
		while(oper[i++]!=0)
			k++;
		for (i = 0,j=k-1; i <k,j>=0 ; i++,j--)
			buf[i] = oper[j];
		return buf;
	}
	char* reversechar(const char* oper)
	{
		char* buf = new char[LEN];
		for(int f = 0; f<=LEN; f++)
			buf[f] = 0;
		int i=0,k=0,j; 
		while(oper[i++]!=0)
			k++;
		for (i = 0,j=k-1; i <k,j>=0 ; i++,j--)
			buf[i] = oper[j];
		return buf;
	}
	char* reversechar(char* oper) const
	{
		char* buf = new char[LEN];
		for(int f = 0; f<=LEN; f++)
			buf[f] = 0;
		int i=0,k=0,j; 
		while(oper[i++]!=0)
			k++;
		for (i = 0,j=k-1; i <k,j>=0 ; i++,j--)
			buf[i] = oper[j];
		return buf;
	}
	char* reversechar(const char* oper) const
	{
		char* buf = new char[LEN];
		for(int f = 0; f<=LEN; f++)
			buf[f] = 0;
		int i=0,k=0,j; 
		while(oper[i++]!=0)
			k++;
		for (i = 0,j=k-1; i <k,j>=0 ; i++,j--)
			buf[i] = oper[j];
		return buf;
	}
	Sign GetSign() const {return sign;}
	void operator=(const Integer& me) {EX_BUFFER = reversechar(me.EX_BUFFER); }
	void operator=(const int me){itoa(me, EX_BUFFER, 10);EX_BUFFER = reversechar(EX_BUFFER);LEN = strlen(EX_BUFFER);}
	char* getbuf() const {return reversechar(EX_BUFFER);}
	long long len() const { return strlen(EX_BUFFER);}

private:

	Sign sign;
	long long LEN;
	char* EX_BUFFER;

};

std::ostream &operator <<(std::ostream &os, const Integer& x) 
{
	if (x.GetSign() == Sign::minus)
		os << '-';
	os << x.getbuf();
	return os;
}


#endif