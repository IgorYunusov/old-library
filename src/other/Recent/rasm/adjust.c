/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   adjust.c - [Private]

Project:

   Robust Assembler (RASM)
   
Abstract:

   Fast adjust string array used in runtime mode.
   These are not regex parser.

------
   AUTHOR: HyunJun Jeong  2015-01-15

***************************************************************************/

#include "type.h"
#include "rocket.h"
#include "adjust.h"

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

/*
	@설명: ch를 만나기 전까지 포인터를 돌립니다.
	@ptr [IN] : 분석할 문자열의 포인터
	-
	@return: 포함되는지의 여부
*/
void AdjustPreCharacter(const char const **ptr, const char ch)
{
	while ( **ptr  != ch )
		*ptr += 1;
}

/*
	@설명: ch를 만나지 않을 때까지 포인터를 돌립니다.
	@ptr [IN] : 분석할 문자열의 포인터
	-
	@return: 포함되는지의 여부
*/
void AdjustPostCharacter(const char const **ptr, const char ch)
{
	while ( **ptr  == ch )
		*ptr += 1;
}

/*
	@설명: lch와 rch의 사이의 문자열과 만날 때까지 포인터를 돌립니다.
	@ptr [IN] : 분석할 문자열의 포인터
	-
	@return: 포함되는지의 여부
*/
void AdjustPreWithScope(const char const **ptr, const char lch, const char rch)
{
	while ( !(**ptr <= lch && rch <= **ptr) )
		*ptr += 1;
}

/*
	@설명: lch와 rch의 사이의 문자열과 만나지 않을 때까지 포인터를 돌립니다.
	@ptr [IN] : 분석할 문자열의 포인터
	-
	@return: 포함되는지의 여부
*/
void AdjustPostWithScope(const char const **ptr, const char lch, const char rch)
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
BOOL AdjustEqualCharacter(const char const **ptr, const char ch)
{
	if ( **ptr == ch ) {
		*ptr += 1;
		return TRUE;
	}

	return FALSE;
}

//
//	Drop regex check module.
//

/*
	@설명: POSIX구문을 분석하고 포함되는지의 여부를 가져옵니다.
	@constant [IN] : 분석할 문자열의 포인터
	-
	@return: 포함되는지의 여부
*/
BOOL DropRegexPosixConstant(const char const **constant, const char ch)
{
	const char *ptr;

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

	AdjustEqualCharacter(constant, ':');
	AdjustPreCharacter(constant, ':');

	if (FALSE == AdjustEqualCharacter(constant, ':'))
		return FALSE;

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

	if (FALSE == AdjustEqualCharacter(scope, '['))
		return FALSE;	// error

	inverse = AdjustEqualCharacter(scope, '^');
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
				if(TRUE == AdjustEqualCharacter(scope, '-')) {
					if (FALSE == AdjustEqualCharacter(scope, '\\'))
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
						if (first == ch)
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
			if (TRUE == AdjustEqualCharacter(scope, '-')) {
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
	@설명: 차집합
	@ptr [IN] : 분석할 문자열의 포인터
	-
	@return: 해당 값
*/
BOOL DropRegexScopeSubtraction(const char const **ptr, const char ch)
{
	// [class-[subtract]]
}

/*
	@설명: 반복자
	@ptr [IN] : 분석할 문자열의 포인터
	-
	@return: 해당 값
*/
BOOL DropRegexReworks(const char const **ptr, const char const **chr)
{
}

/*
	@설명: Regex Entry
*/
BOOL DropRegexGlobal(const char *ptr, const char *chr)
{
	BOOL ret;
	const char const **ptrptr = &ptr;
	const char const **chrptr = &chr;
	char ch;
	ret = FALSE;

	while ( ch = *ptr ) {

	}

	return ret;
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