/****************************************************************
 *																*
 *																*
 *			ROLLRAT AUTO PERSONA VERBOTER LIBROFEX				*
 *																*
 *																*
 *		COPYRIGHT (c) rollrat. 2013. ALL RIGHTS RESERVED.		*
 *																*
 *																*
 ****************************************************************/


#ifndef _regex_engine_
#define _regex_engine_

#include "strweapon.h"

/*------------------------------------------------------------------

		ROLLRAT EXPRESSION ENGINE - REGEX SUPPLEMENTARY

	- http://en.wikipedia.org/wiki/Regular_expression -

			META LIST

	Nick			: \
	All-Match		: .
	Division		: |
	REGEX-MATCH		: *, +
	Group	1		: []
	Group	2		: ()
	Quantifier		: {}, {,}
	Idle Q			: ?(0 or 1 time)
	Range			: -
	Negative		: ^(carrot)
	P-Look Ahead	: (?=)
	P-Look Around	: (?<=)
	N-Look Ahead	: (?!)
	N-Look Around	: (?<!)

------------------------------------------------------------------*/


template < class _RegExp > FORCE_INLINE int
	__strpermatch_sizethat( const _RegExp D_REGEX, const _RegExp *MATCH)
	{ // str match by one charCH
		const _RegExp *M = MATCH;
		for( ; *M; M++)
			if(*M == D_REGEX)
				return 1;
		return 0;
	}

template < class _RegExp > FORCE_INLINE int
	__strpermatch_atob( const _RegExp D_REGEX, 
		const _RegExp MATCH1, const _RegExp MATCH2)
	{ // str match by one charCH
		if(MATCH1 == MATCH2)
			return -1;
		if(MATCH1 < MATCH2)
			for(int i = MATCH1; i == MATCH2; i++)
				if(i == D_REGEX)
					return 1;
		if(MATCH1 > MATCH2)
			for(int i = MATCH2; i == MATCH1; i++)
				if(i == D_REGEX)
					return 1;
		return 0;
	}

template < class _RegExp > FORCE_INLINE int
	__strpermatch_gtog( const _RegExp *D_REGEX, 
		const _RegExp MATCH1, const _RegExp MATCH2)
	{ // g to g
		const _RegExp *D_ = D_REGEX;
		int i = 0;
		for( ; *D_; D_++)
			if(MATCH1 == *D_)
				i++;
			else if(MATCH2 == *D_)
			{
				i--;
				if(!i)
					break;
			}
		return D_ - D_REGEX - 1;
	}

template < class _RegExp > FORCE_INLINE int
	__strpermatch_whitespace( const _RegExp D_REGEX )
	{
		return 0;
	}

//////////////////////////////////////////////////////////
//		TEXTOUT CLASS
//////////////////////////////////////////////////////////

template<class _EC102> class
	TEXTOUT_exc
	{ // textout exc helper
public:

	TEXTOUT_exc(_EC102 *t)
		: stdtd(t) 
	{
		FPtr = t;
		for( ; *stdtd; stdtd++)
			;
		LPtr = stdtd;
		stdtd = FPtr;
	}

	int Length() 
	{
		return _Length(stdtd);
	}

	void exc_ptr_first_pos() 
	{
		stdtd = FPtr;
	}

	_EC102 operator*()
	{
		return *stdtd;
	}

	_EC102 operator[](int i)
	{
		return stdtd[i];
	}

	_EC102 *operator++()
	{
		return (++stdtd);
	}

	_EC102 *operator--()
	{
		return (--stdtd);
	}

	_EC102 *operator+=(int i)
	{
		return (stdtd, stdtd += i);
	}

	_EC102 *operator-=(int i)
	{
		return (stdtd, stdtd -= i);
	}

	void exc_ptr_save()
	{
		savePtr = stdtd;
	}
	
	void exc_ptr_open()
	{
		stdtd = savePtr;
	}

	_EC102 *stdtd;
	_EC102 *FPtr;
	_EC102 *LPtr;
	_EC102 *savePtr;

	};


//////////////////////////////////////////////////////////
//		SERVE	-	ENGINE
//////////////////////////////////////////////////////////

template<class _EC103> class
	SERVEexc
	{ // serve func
public:

	SERVEexc(TEXTOUT_exc<_EC103> c) : stdtd(c) {}


private:
	TEXTOUT_exc<_EC103> stdtd;

	};

//////////////////////////////////////////////////////////
//		MAIN	-	ENGINE
//////////////////////////////////////////////////////////

#define REGEX_NONE				0
#define REGEX_SUCCESS			1
#define REGEX_BACKSLASH			2
#define REGEX_BRACE				3

#define REGEX_AL				"abcdefghijklmnopqrstuwxyz"
#define REGEX_ALT				"ABCDEFGHIJKLMNOPQRSTUWXYZ"
#define REGEX_NUM				"0123456789"
#define REGEX_W					REGEX_AL REGEX_ALT REGEX_NUM "_"

template<class _RegExp = char> class
	regex_compiler
	{ // compiler
public:

	regex_compiler(_RegExp *that) : stdtd(that) {}

	int compile_std(_RegExp *ptr, int flag = 0, _RegExp *ptrt = 0)
	{
		_RegExp *str = ptr;
		switch(flag)
		{
		case REGEX_NONE:
			for( ; *str; str++)
				switch(*stdtd)
				{
				case '\\':
					if(!compile_std(stdtd.stdtd, REGEX_BACKSLASH, str))
						stdtd.exc_ptr_first_pos();
					break;
				case '[':
					if(!compile_std(stdtd.stdtd, REGEX_BRACE, str))
						stdtd.exc_ptr_first_pos();
					break;
				case '.':
					stdtd++;
					break;
				case '$':
				case '^':
				default:
					if(*stdtd == *(stdtd.LPtr))
						; // std저장에 대한 입력
					if(*stdtd != *str)
						stdtd.exc_ptr_first_pos();
					else
						stdtd++;
					break;
				}
			break;
		case REGEX_BACKSLASH:
			switch(*(stdtd++))
			{
			case 'A':
			case 'B':
			case 'C':
			case 'D':
				if(!__strpermatch_atob(*ptrt, '0', '9'))
					return REGEX_SUCCESS;
				return REGEX_NONE;
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
				if(!__strpermatch_whitespace(*ptrt))
					return REGEX_SUCCESS;
				return REGEX_NONE;
			case 'T':
			case 'U':
			case 'W':
				if(!__strpermatch_sizethat(*ptrt, REGEX_W))
					return REGEX_SUCCESS;
				return REGEX_NONE;
			case 'X':
			case 'Y':
			case 'Z':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
				if(__strpermatch_atob(*ptrt, '0', '9'))
					return REGEX_SUCCESS;
				return REGEX_NONE;
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
				if(*ptrt == '\n')
					return REGEX_SUCCESS;
				return REGEX_NONE;
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
				if(__strpermatch_whitespace(*ptrt))
					return REGEX_SUCCESS;
				return REGEX_NONE;
			case 't':
			case 'u':
			case 'w':
				if(__strpermatch_sizethat(*ptrt, REGEX_W))
					return REGEX_SUCCESS;
				return REGEX_NONE;
			case 'x':
			case 'y':
			case 'z':
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			default:
				return *stdtd == *ptrt;
			}
		}
		return 0;
	}

private:

	char **binary;
	char *binary_set;
	TEXTOUT_exc<_RegExp> stdtd;

	};

#endif