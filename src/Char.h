/***

   RollRat Software Project.
   Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
   Char.h

Purpose:

   RollRat Library

Author:

   10-03-2015:   HyunJun Jeong, Creation

***/

#if 0

#ifndef _CHAR_
#define _CHAR_

#include <string.h>
#include <tchar.h>

namespace Utility {

	//
	//	이 클래스는 캐릭터의 기본 단위를 나타냅니다.
	//	이 클래스는 사용되지 않습니다.
	//
	class Char
	{
		// 크기가 2 byte인 자료형을 나타냅니다.
		unsigned char ch;
#       define CHAR(c) ((unsigned char)(c))

	public:

		Char()
			: ch(0)
		{
		}

		Char(char c)
			: ch(CHAR(c))
		{
		}

		Char(short c)
			: ch(CHAR(c))
		{
		}

		Char(int c)
			: ch(CHAR(c))
		{
		}

		Char(unsigned char c)
			: ch(CHAR(c))
		{
		}

		Char(unsigned int c)
			: ch(c & 0xffff)
		{
		}

		Char(const Char& c)
			: ch(c.ch)
		{
		}

#       define CHAR_OPERATOR_ENUM(sym) \
			friend bool operator##sym( const char ch, const Char& _ch )\
			{\
				return CHAR(ch) sym _ch.ch;\
			}\
			friend bool operator##sym( const Char& _ch, const char ch )\
			{\
				return CHAR(ch) sym _ch.ch;\
			}\
			friend bool operator##sym( const Char& lch, const Char& rch )\
			{\
				return lch.ch sym rch.ch;\
			}

		CHAR_OPERATOR_ENUM(==)
		CHAR_OPERATOR_ENUM(!=)
		CHAR_OPERATOR_ENUM(>=)
		CHAR_OPERATOR_ENUM(<=)
		CHAR_OPERATOR_ENUM(>)
		CHAR_OPERATOR_ENUM(<)

#       define CHAR_CHECK_TEXT(name, func) \
			bool Is##name() const\
			{\
				return func(ch);\
			}

		CHAR_CHECK_TEXT(Space, isspace)
		CHAR_CHECK_TEXT(Numberic, isdigit)
		CHAR_CHECK_TEXT(Alpha, isalpha)
		CHAR_CHECK_TEXT(Alnum, isalnum)

		bool IsNull() const
		{
			return ch == 0;
		}

	};
}

#endif

#endif