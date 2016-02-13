/*************************************************************************
  
   RollRat Software Common Parser Method Collection

   [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]
===++                                                                ++===
                             File: mutable_handler.h
                         Abstract: Regular Expression Class
                         Creation: 2015-03-10
===--                                                                --===
   [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]

   Copyright (C) 2015. rollrat. All Rights Reserved.

***************************************************************************/

#ifndef _REGEX_08faa3e0cf0c3401ab5fbeb7b45d18b7_
#define _REGEX_08faa3e0cf0c3401ab5fbeb7b45d18b7_

#include <string>
#include <ctype.h>
#include "type.h"
#include "rocket.h"

namespace CPMC {
	
	/*

			PERFECT REGEX UNIT
	
	*/
	#define REGEX_ALNUM						":alnum:"	// Alphanumeric characters
	#define REGEX_WORD						":word:"	// Alphanumeric characters plus "_"
	#define REGEX_ALPHA						":alpha:"	// Alphabetic characters
	#define REGEX_BLANK						":blank:"	// Space and tab
	#define REGEX_CNTRL						":cntrl:"	// Control characters
	#define REGEX_DIGIT						":digit:"	// Digits
	#define REGEX_GRAPH						":graph:"	// Visible characters
	#define REGEX_LOWER						":lower:"	// Lowercase letters
	#define REGEX_PRINT						":print:"	// Visible characters and the space character
	#define REGEX_PUNCT						":punct:"	// Punctuation characters
	#define REGEX_SPACE						":space:"	// Whitespace characters
	#define REGEX_UPPER						":upper:"	// Uppercase letters
	#define REGEX_XDIGIT					":xdigit:"	// Hexadecimal digits
	#define REGEX_ODIGIT					":odigit:"	// Octal digits
	
				// POSIX OLD SCAN LIST
	#define REGEX_SCAN_ALNUM				"[A-Za-z0-9]"
	#define REGEX_SCAN_WORD					"[A-Za-z0-9_]"
	#define REGEX_SCAN_ALPHA				"[A-Za-z]"
	#define REGEX_SCAN_BLANK				"[\\ \\t]"
	#define REGEX_SCAN_CNTRL				"[\\x00-\\x1F\\x7F]"
	#define REGEX_SCAN_DIGIT				"[0-9]"
	#define REGEX_SCAN_GRAPH				"[\\x21-\\x7E]"
	#define REGEX_SCAN_LOWER				"[a-z]"
	#define REGEX_SCAN_PRINT				"[\\x20-\\x7E]"
	#define REGEX_SCAN_PUNCT				"[\\]\\[\\!\\\"\\#\\$\\%\\&\\'\\(\\)\\*\\+\\,\\.\\/\\:\\;\\<\\=\\>\\?\\@\\\\\^\\_\\`\\{\\|\\}\\~\\-]"
	#define REGEX_SCAN_SPACE				"[\\ \\t\\r\\n\\v\\f]"
	#define REGEX_SCAN_UPPER				"[A-Z]"
	#define REGEX_SCAN_XDIGIT				"[A-Fa-f0-9]"
	#define REGEX_SCAN_ODIGIT				"[0-7]"

	using namespace std;
	
	class adjust {
	public:
		
		/*
			@ptr [IN] : 분석할 문자열의 포인터
			-
			@return: 포함되는지의 여부
		*/
		static BOOL AdjustCharacter(const char const **ptr, const char ch)
		{
			if( **ptr != ch )
				return FALSE;
			*ptr++;
			return TRUE;
		}
		
		/*
			@설명: ch를 만나기 전까지 포인터를 돌립니다.
			@ptr [IN] : 분석할 문자열의 포인터
			-
		*/
		static void AdjustPreCharacter(const char const **ptr, const char ch)
		{
			while ( **ptr  != ch )
				*ptr += 1;
		}
		
		/*
			@설명: ch를 만나지 않을 때까지 포인터를 돌립니다.
			@ptr [IN] : 분석할 문자열의 포인터
			-
		*/
		static void AdjustPostCharacter(const char const **ptr, const char ch)
		{
			while ( **ptr  == ch )
				*ptr += 1;
		}
		
		/*
			@설명: lch와 rch의 사이의 문자열과 만날 때까지 포인터를 돌립니다.
			@ptr [IN] : 분석할 문자열의 포인터
			-
		*/
		static void AdjustPreWithScope(const char const **ptr, const char lch, const char rch)
		{
			while ( !(**ptr <= lch && rch <= **ptr) )
				*ptr += 1;
		}
		
		/*
			@설명: lch와 rch의 사이의 문자열과 만나지 않을 때까지 포인터를 돌립니다.
			@ptr [IN] : 분석할 문자열의 포인터
			-
		*/
		static void AdjustPostWithScope(const char const **ptr, const char lch, const char rch)
		{
			while ( **ptr <= lch && rch <= **ptr )
				*ptr += 1;
		}
		
		/*
			@설명: 문자토큰을 확인합니다.
			@ptr [IN] : 분석할 문자열의 포인터
			-
			@return: 포함되는지의 여부
		*/
		static BOOL AdjustEqualCharacter(const char const **ptr, const char ch)
		{
			if ( **ptr == ch ) {
				*ptr += 1;
				return TRUE;
			}
		
			return FALSE;
		}
		
		/*
			@설명: 괄호토큰을 확인합니다.
			@ptr [IN] : 분석할 문자열의 포인터
			-
		*/
		static void AdjustBracketCharacter(const char const **ptr, const char ch1, const char ch2)
		{
			int iCount;
		
			for (iCount = 0; **ptr != ch2; *ptr += 1)
				if (**ptr == ch1)
					iCount++;
		
			for (; iCount > 0; *ptr += 1)
				if (**ptr == ch2)
					iCount--;
		}
		
		/*
			@설명: 함수를 이용하여 1반환시 건너뜁니다.
			@ptr [IN] : 분석할 문자열의 포인터
			-
			@return: 건너뛴 문자의 개수
		*/
		static size_t AdjustPreFindFunction(const char const **ptr, void *(*func(void *)))
		{
			const char *p = *ptr, *o = *ptr;
		
			while ( *p ) {
				if((char *)func((void *)*p))
					return (*ptr = p) - o;
				p++;
			}
		
			*ptr = p;
			return -1;
		}
		
		/*
			@설명: 함수를 이용하여 0반환시 건너뜁니다.
			@ptr [IN] : 분석할 문자열의 포인터
			-
			@return: 건너뛴 문자의 개수
		*/
		static size_t AdjustPreSkipFunction(const char const **ptr, void *(*func(void *)))
		{
			const char *p = *ptr, *o = *ptr;
		
			while ( *p ) {
				if(!(char *)func((void *)*p))
					return (*ptr = p) - o;
				p++;
			}
		
			*ptr = p;
			return -1;
		}
		
		/*
			@설명: 함수를 이용하여 1반환시 건너뜁니다.
			@ptr [IN] : 분석할 문자열의 포인터
			-
			@return: 건너뛴 문자의 개수
		*/
		static size_t AdjustPostFindFunction(const char const **ptr, void *(*func(void *)))
		{
			const char *p = *ptr, *o = *ptr;
		
			while ( *p ) {
				if((char *)func((void *)*p))
					return o - (*ptr = p);
				p--;
			}
		
			*ptr = p;
			return -1;
		}
		
		/*
			@설명: 함수를 이용하여 0반환시 건너뜁니다.
			@ptr [IN] : 분석할 문자열의 포인터
			-
			@return: 건너뛴 문자의 개수
		*/
		static size_t AdjustPostSkipFunction(const char const **ptr, void *(*func(void *)))
		{
			const char *p = *ptr, *o = *ptr;
		
			while ( *p ) {
				if(!(char *)func((void *)*p))
					return o - (*ptr = p);
				p--;
			}
		
			*ptr = p;
			return -1;
		}
		
		/*
			@설명: 좌측 선형공백을 삭제합니다. 
				Returns a string copy of the specified string does not have (Trim) space 
				leading spaces (LTrim), trailing spaces (RTrim), 
				at the beginning or end is included.
			@ptr [IN] : 분석할 문자열의 포인터
			-
		*/
		static void AdjustLeftTrim(const char const **ptr)
		{
			AdjustPreSkipFunction(ptr, _isspace);
		}
		
		/*
			@설명: 우측 선형공백을 삭제합니다.
				Returns a string copy of the specified string does not have (Trim) space 
				leading spaces (LTrim), trailing spaces (RTrim), 
				at the beginning or end is included.
			@ptr [IN] : 분석할 문자열의 포인터
			-
		*/
		static void AdjustRightTrim(char **ptr)
		{
			char *o = *ptr;
			AdjustLastPointer(ptr);
			AdjustPostSkipFunction(ptr, _isspace);
			*(*ptr + 1) = 0;
			*ptr = o;
		}
		
		/*
			@설명: 포인터를 끝으로 옮깁니다. (\0은 포함하지 않습니다.)
			@ptr [IN] : 분석할 문자열의 포인터
			-
		*/
		static void AdjustLastPointer(const char const **ptr)
		{
			for (; **ptr; *ptr += 1)
				;
			*ptr -= 1;
		}
		
		/*
			@설명: CString style Left Function.
			@ptr [IN] : 분석할 문자열
			-
		*/
		static char *DropLeft(const char *ptr, const size_t sz)
		{
			char *ret, *p = (char *)ptr;
			ret = (char *)malloc(sizeof(char) * sz + 1);
			memcpy(ret, p, sz);
			ret[sz] = 0;
			return ret;
		}
		
		/*
			@설명: CString style Right Function.
			@ptr [IN] : 분석할 문자열
			-
		*/
		static char *DropRight(const char *ptr, const size_t sz)
		{
			char *ret, *p = (char *)ptr;
			while ( *p++ )
				;
			p -= sz + 1;
			ret = (char *)malloc(sizeof(char) * sz + 1);
			memcpy(ret, p, sz);
			ret[sz] = 0;
			return ret;
		}
		
		/*
			@설명: CString style Mid Function.
			@ptr [IN] : 분석할 문자열
			-
		*/
		static char *DropMid(const char *ptr, const size_t _Left, const size_t _Right)
		{
			char *ret;
			ret = DropLeft(ptr += _Left, _Right);
			return ret;
		}
		
		/*
			@설명: Visual Basic style LSet Function.
				Adjust to match the length that you specify, in a string 
				that has been specified, returns a string 
				that matches the left.
			@ptr [IN] : 분석할 문자열
			-
		*/
		static char *DropLSet(const char *ptr, const size_t sz)
		{
			char *ret, *p = (char *)ptr;
			int i;
			ret = (char *)malloc(sizeof(char) * sz + 1);
			for (i = 0; *p && i < sz; i++, p++)
				ret[i] = *p;
			if (!*p)
				for (; i < sz; i++)
					ret[i] = ' ';
			ret[sz] = 0;
			return ret;
		}
		
		/*
			@설명: Visual Basic style RSet Function.
				Returns a string that matches the right 
				to match the length that is specified.
			@ptr [IN] : 분석할 문자열
			-
		*/
		static char *DropRSet(const char *ptr, const size_t sz)
		{
			char *ret, *p = (char *)ptr;
			int i = sz;
			while ( *p++ )
				;
			ret = (char *)malloc(sizeof(char) * sz + 1);
			p -= 2;
			for (; p != (ptr - 1) && i; i--, p--)
				ret[i-1] = *p;
			if (p == (ptr - 1)) {
				for (; i; i--)
					ret[i] = ' ';
				*ret = ' ';
			}
			ret[sz] = 0;
			return ret;
		}
		
		/*
			@설명: 문자열안에 몇개의 문자열이 들어갔는지 알아봅니다. 
				Visual Basic Len Function.
			@ptr [IN] : 분석할 문자열의 포인터
			-
			@return: 포함되는지의 여부
		*/
		static size_t DropContainsLength(const char *src, const char *ptr)
		{
			const char *s1, *s2, *_ptr = ptr;
			size_t ret = 0;
			for(; *_ptr; _ptr++) {
				s1 = src;
				s2 = ptr;
				while(*s1 && *s2 && !(*s1 - *s2))
					s1++, s2++;
				if(!*s2)
					_ptr = s1 - 1, ret++;
			}
			return ret;
		}
		
		/*
			@설명: Visual Basic style Split Method.
			@repeat [IN] : 분석될 문자열의 포인터
			-
		*/
		static char **DropSplit(const char *_Ptr, const char *_T)
		{
			int ic = DropContainsLength(_Ptr, _T) + 1;
			char **_ret = (char **)malloc(sizeof(char *)*ic), *s1, *s2, *tmp;
			int i = 0, t = strlen(_T), f;
			char **_ret_;
			
			for (s1 = (char *)_Ptr; (s2 = strstr(s1, _T)) != NULL; i++) {
				tmp = (char *)malloc(sizeof(char)*(s2-s1+1));
				memcpy(tmp, s1, s2 - s1);
				tmp[s2 - s1] = 0;
				_ret[i] = tmp;
				s1 += s2 - s1 + t;
			}
			
			if(*s1) {
				for (s2 = s1; *s2; s2++)
					;
				tmp = (char *)malloc(sizeof(char)*(s2-s1+1));
				memcpy(tmp, s1, s2 - s1);
				tmp[s2 - s1] = 0;
				_ret[i] = tmp;
				i++;
			}
		
			return _ret;
		}
		
		/*
			@설명: 문자열 시작과 문자열이 일치하는 지의 여부를 가져옵니다.
				Make sure at the start of this string instance, 
				string that you specify as to whether or not the match.
			@src [IN] : 분석할 문자열
			-
			@return: 포함되는지의 여부
		*/
		static BOOL DropStartsWith(const char *src, const char *chp)
		{
			while( *src == *chp && *src && *chp )
				src++, chp++;
		
			if(*chp)
				return FALSE;
		
			return TRUE;
		}
		
		/*
			@설명: 문자열 끝과 문자열이 일치하는 지의 여부를 가져옵니다.
				Make sure at the end of this string instance, 
				string that you specify as to whether or not the match.
			@src [IN] : 분석할 문자열
			-
			@return: 포함되는지의 여부
		*/
		static BOOL DropEndsWith(const char *src, const char *chp)
		{
			const char *p1 = src, *p2 = chp;
		
			AdjustLastPointer(&p1);
			AdjustLastPointer(&p2);
		
			while ( p2 != chp && p1 != src ) {
				if (*p1 != *p2)
					return FALSE;
				p1--;
				p2--;
			}
		
			if ( p2 == chp || p1 == src ) {
				if ( *p1 != *p2 )
					return FALSE;
			}
		
			return TRUE;
		}

	};

	typedef struct _anchor_{
		WORD uhex;
		BYTE posix;
		BYTE xhex;
		BOOL inverse;
		int type;	// 0:uhex, 1:posix, 2:xhex
	}	AdjustAnchor, *PAdjustAnchor;

	class regex_perfect_match {
	public:

		bool start()
		{
		}

	private:

		
		/*
			@설명: POSIX구문을 분석하고 포함되는지의 여부를 가져옵니다.
			@constant [IN] : 분석할 문자열의 포인터
			-
			@return: 포함되는지의 여부
		*/
		BOOL DropRegexPosixConstant(const char const **constant, const char ch)
		{
			const char *ptr;
			BOOL ret;
		
			if (!_strcmp_asc(*constant, REGEX_ALNUM))
				ptr = REGEX_SCAN_ALNUM;
			else if (!_strcmp_asc(*constant, REGEX_WORD))
				ptr = REGEX_SCAN_WORD;
			else if (!_strcmp_asc(*constant, REGEX_ALPHA))
				ptr = REGEX_SCAN_ALPHA;
			else if (!_strcmp_asc(*constant, REGEX_BLANK))
				ptr = REGEX_SCAN_BLANK;
			else if (!_strcmp_asc(*constant, REGEX_CNTRL))
				ptr = REGEX_SCAN_CNTRL;
			else if (!_strcmp_asc(*constant, REGEX_DIGIT))
				ptr = REGEX_SCAN_DIGIT;
			else if (!_strcmp_asc(*constant, REGEX_GRAPH))
				ptr = REGEX_SCAN_GRAPH;
			else if (!_strcmp_asc(*constant, REGEX_LOWER))
				ptr = REGEX_SCAN_LOWER;
			else if (!_strcmp_asc(*constant, REGEX_PRINT))
				ptr = REGEX_SCAN_PRINT;
			else if (!_strcmp_asc(*constant, REGEX_PUNCT))
				ptr = REGEX_SCAN_PUNCT;
			else if (!_strcmp_asc(*constant, REGEX_SPACE))
				ptr = REGEX_SCAN_SPACE;
			else if (!_strcmp_asc(*constant, REGEX_UPPER))
				ptr = REGEX_SCAN_UPPER;
			else if (!_strcmp_asc(*constant, REGEX_XDIGIT))
				ptr = REGEX_SCAN_XDIGIT;
			else if (!_strcmp_asc(*constant, REGEX_ODIGIT))
				ptr = REGEX_SCAN_ODIGIT;
			else
				return; // error
		
			adjust::AdjustEqualCharacter(constant, ':');
			adjust::AdjustPreCharacter(constant, ':');
		
			if (FALSE == adjust::AdjustEqualCharacter(constant, ':'))
				return FALSE;
		
			adjust::AdjustEqualCharacter(constant, ']');
		
			return DropRegexSideScope(&ptr, ch);
		}

		/*
			@설명: [A-F]와 같은 regex구문을 분석하고 포함되는지의 여부를 가져옵니다.
			@scope [IN] : 분석할 문자열의 포인터
			-
			@return: 포함되는지의 여부
		*/
		BOOL DropRegexSideScope(const char const **scope, const char ch)
		{
			BOOL inverse, ret, finverse;
			PAdjustAnchor first, second;
			BYTE fxhex;
			BYTE fposix;
			WORD fwhex;
			char ph;
		
			if (FALSE == adjust::AdjustEqualCharacter(scope, '['))
				return FALSE;	// error
		
			inverse = adjust::AdjustEqualCharacter(scope, '^');
			ret = FALSE;
		
			if (**scope == '[') {
				if (*++*scope == ':')
					return DropRegexPosixConstant(scope, ch) ^ inverse;
				return FALSE; //error
			}
		
			while( **scope && **scope != ']' ) {
				switch ( (ph = *(*scope)++) ) {
				case '\\':
					if( _isnalpha(**scope) ){
						if ((ph = *(*scope)++) == ch)
							return inverse ^ TRUE;
					} else {
						first = DropRegexAnchor(scope);
						finverse = first->inverse;
						if(TRUE == adjust::AdjustEqualCharacter(scope, '-')) {
							if (FALSE == adjust::AdjustEqualCharacter(scope, '\\'))
								break; //error
							if (first->type == 2) {
								fxhex = first->xhex;
								second = DropRegexAnchor(scope);
								if (fxhex <= ch && ch <= second->xhex)
									return finverse ^ inverse ^ TRUE;
							}
						} else {
							if (first->type == 2) {
								fxhex = first->xhex;
								if (fxhex == ch)
									return finverse ^ inverse ^ TRUE;
							} else if (first->type == 1) {
								fposix = first->posix;
								if(TRUE == DropRegexPosixMatch(fposix, ch))
									return finverse ^ inverse ^ TRUE;
							}
						}
					}
					break;
				default:
					if (TRUE == adjust::AdjustEqualCharacter(scope, '-')) {
						if (ph <= ch && ch <= (ph = **scope)) {
							(*scope)++;
							return inverse ^ TRUE;
						}
						(*scope)++;
					} else {
						if (_isalnumub(ph))
							if (ph == ch)
								return inverse ^ TRUE;
					}
					break;
				}
			}
		
			return inverse ^ ret;
		}
		
		/*
			@설명: POSIX Match. 0:\w, 1:\s, 2:\d, 3:\a
			@posix [IN] : 위 숫자 중 하나
			-
			@return: 해당 값
		*/
		BOOL DropRegexPosixMatch(BYTE posix, char ch)
		{
			if(posix == 0) {
				if(_isalnumub(ch))
					return TRUE;
			} else if (posix == 1) {
				if(_isspace(ch))
					return TRUE;	// is multi line of
			} else if (posix == 2) {
				if(_isdigit(ch))
					return TRUE;
			} else if (posix == 3) {
				if(_isalpha(ch))
					return TRUE;
			} else if (posix == 4) {
				if(_islower(ch))
					return TRUE;
			} else if (posix == 5) {
				if (0x20 <= ch && ch <= 0x7E)
					return TRUE;
			} else if (posix == 6) {
				if(_isupper(ch))
					return TRUE;
			} else if (posix == 7) {
				if(0 <= ch && ch <= 7)
					return TRUE;
			}
			return FALSE;
		}

		/*
			@설명: \<alpha>와 관련된 문자검색
			@ptr [IN] : 분석할 문자열의 포인터
			-
			@return: 해당 값
		*/
		PAdjustAnchor DropRegexAnchor(const char const **ptr)
		{
			static AdjustAnchor anch;
		
			if (_islower(**ptr))
				anch.inverse = FALSE;
			else
				anch.inverse = TRUE;
		
			switch (_to_lower(*(*ptr)++)) {
			case 'w': anch.type = 1; anch.posix = 0; break;
			case 's': anch.type = 1; anch.posix = 1; break;
			case 'd': anch.type = 1; anch.posix = 2; break;
			case 'a': anch.type = 1; anch.posix = 3; break;
		
			case 'l': anch.type = 1; anch.posix = 4; break;
			case 'p': anch.type = 1; anch.posix = 5; break;
			case 'u': anch.type = 1; anch.posix = 6; break;
			case 'o': anch.type = 1; anch.posix = 7; break;
		
			case 'x':
		
				if(!_isxdigit(**ptr)) {
					anch.type = 1; anch.posix = 8;
					break;
				}
		
				// {~}에서는... 나도 몰라요
				anch.type = 2;
				anch.xhex = _to_xdigit(*(*ptr)++);
				if(_isxdigit(**ptr)) {
					anch.xhex = anch.xhex << 4 | _to_xdigit(*(*ptr)++);
				} else break;
				if(_isxdigit(**ptr)) {
					anch.type = 0;
					anch.uhex = anch.xhex << 4 | _to_xdigit(*(*ptr)++);
				} else break;
				if(_isxdigit(**ptr)) {
					anch.uhex = anch.uhex << 4 | _to_xdigit(*(*ptr)++);
				}
				break;
		
				// white space
			case 't': anch.type = 2; anch.posix = '\t'; break;
			case 'r': anch.type = 2; anch.posix = '\r'; break;
			case 'n': anch.type = 2; anch.posix = '\n'; break;
			}
		
			return &anch;
		}
		
		/*
			@설명: Regex Entry
		*/
		BOOL DropRegexGlobal(const char *ptr, const char *chr)
		{
			const char const **ptrptr = &ptr, *setptr = 0, *optr = 0;
			const char const **chrptr = &chr;
			BOOL bigblack, bigFALSE;
			char ch;
		
			bigblack = FALSE;
			bigFALSE = FALSE;
		
			while ( ch = **ptrptr ) {
				if (bigblack == FALSE && bigFALSE == TRUE)
					return FALSE;
				switch (ch) {
				case '\\':
					if (!adjust::AdjustCharacter(chrptr, *(*ptrptr + 1)))
						return FALSE;
					*ptrptr += 2;
					break;
				case '[':
					bigblack = TRUE;
					setptr = *ptrptr;
					if (!DropRegexSideScope(ptrptr, **chrptr))
						bigFALSE = TRUE;
					*chrptr += 1;
					*ptrptr = setptr;
					adjust::AdjustBracketCharacter(ptrptr, '[', ']');
					optr = *ptrptr;
					break;
				case '+':
					if (bigblack == TRUE) {
						*ptrptr = setptr;
						if (bigFALSE == TRUE)
							return FALSE;
						while (DropRegexSideScope(ptrptr, **chrptr))
							*ptrptr = setptr, *chrptr += 1;
						bigblack = FALSE;
					}
					*ptrptr = optr;
					adjust::AdjustEqualCharacter(ptrptr, '+');
					break;
				case '*':
					if (bigblack == TRUE) {
						*ptrptr = setptr;
						while (DropRegexSideScope(ptrptr, **chrptr))
							*ptrptr = setptr, *chrptr += 1;
						bigblack = bigFALSE = FALSE;
					}
					*ptrptr = optr;
					adjust::AdjustEqualCharacter(ptrptr, '*');
					break;
				default:;
				}
			}
		
			return TRUE;
		}
		
		/*
			@설명: 캡쳐할 문구를 일치할 때까지 반복하여 그 여부를 가져옵니다.
			@repeat [IN] : 분석될 문자열의 포인터
			-
			@return: 포함되는지의 여부
		*/
		BOOL DropRegexPreRepeatCharacter(const char const **repeat, const char ch, size_t count)
		{
			while (**repeat != ch && **repeat && count--)
				*repeat += 1;
		
			if (count == 0)
				return TRUE;
			else
				return FALSE;
		}
		
		/*
			@설명: 캡쳐할 문구를 일치하지 않을 때까지 반복하여 그 여부를 가져옵니다.
			@repeat [IN] : 분석될 문자열의 포인터
			-
			@return: 포함되는지의 여부
		*/
		BOOL DropRegexPostRepeatCharacter(const char const **repeat, const char ch, size_t count)
		{
			while (**repeat == ch && **repeat && count--)
				*repeat += 1;
		
			if (count == 0)
				return TRUE;
			else
				return FALSE;
		}

	};

}

#endif