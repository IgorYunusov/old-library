/*
			RCL - ROLLRAT TRANSPLATABLE LIBRARY
				 R COMPILER LANGUAGE PROJECT
					NATIVE C Librorum

			 Cpy (c) 13-14. ALL RIGHTS RESERVED.
   */

// REGEX VERSION		1.0

/* Check R COMPILER */
#ifdef _RCL_LIT
#pragma _local("%/lib", RCL_NONE_OF_FLAG)
#pragma _local("%/extable", RCL_ANY_OF_FLAG)
#pragma _local("%/extable/string", unsigned char)

#pragma _native("^memory/allocate", RCL_ANY_OF_FLAG)
#else
#include <malloc.h>
#define Allocate	malloc
#define Release		free
#endif

#define RTL_REGEX			0x456C
#define UNICODE				unsigned char
#define UNICODE_STRING		UNICODE *

typedef int		BOOL;
typedef unsigned long ULONG, *UPLONG;

#define TRUE		1
#define FALSE		0

// USELESS
#if defined(DEBUG) || defined(_DEBUG) || defined(_CRT_MODE)
# define error_set			1
#else
# define error_set			0
#endif

#ifndef _UNICODE_LISTF
#define LIST_NULL			0L
typedef struct _list_stt{
	struct _list_stt* _Next;
	struct _list_stt* _Prev;
	UNICODE _Data;
}	list, *plist;
typedef struct _Regex_pattern_List{
	struct _Regex_pattern_List* _Next;
	struct _Regex_pattern_List* _Prev;
	ULONG _Type;
	UNICODE _Data;
}	*regex_pattern, rpall;
plist _CreateList(UNICODE _Data){
	plist _New = (plist) Allocate ( sizeof(list) );
	_New->_Next = LIST_NULL;
	_New->_Prev = LIST_NULL;
	_New->_Data = _Data;
	return _New;}
regex_pattern _CreatePatn(){
	regex_pattern _New = (regex_pattern) Allocate ( sizeof(rpall) );
	_New->_Next = LIST_NULL;
	_New->_Prev = LIST_NULL;
	return _New;}
#endif

#ifndef _UNICODE_STACKF
typedef struct _stack_stt{plist Top;}	stack;
void _Pushs(stack *_Stack, UNICODE _Data){
	if (_Stack->Top == LIST_NULL)
		_Stack->Top = _CreateList(_Data);
	else{plist _Ko = _CreateList(_Data);
		_Ko->_Prev = _Stack->Top;
		_Stack->Top = _Ko;}}
UNICODE _Pops(stack *_Stack){
	UNICODE Ret = _Stack->Top->_Data;
	plist _Prev = _Stack->Top->_Prev;
	Release(_Stack->Top);
	_Stack->Top = _Prev;
	return Ret;}
#else
typedef struct _stack_stt{regex_pattern Top;}	stack;
void _Pushs(stack *_Stack, UNICODE _Data){
	if (_Stack->Top == LIST_NULL)
		_Stack->Top = _CreateList(_Data);
	else{regex_pattern _Ko = _CreateList(_Data);
		_Ko->_Prev = _Stack->Top;
		_Stack->Top = _Ko;}}
UNICODE _Pops(stack *_Stack){
	UNICODE Ret = _Stack->Top->_Data;
	regex_pattern _Prev = _Stack->Top->_Prev;
	Release(_Stack->Top);
	_Stack->Top = _Prev;
	return Ret;}
//	Extend

#endif


	/*

			PERFECT REGEX UNIT
	
	*/

// By WIKIPEDIA Regular_expression Documents

			// POSIX LIST
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
#define REGEX_SCAN_ALNUM				"A-Za-z0-9"
#define REGEX_SCAN_WORD					"A-Za-z0-9_"
#define REGEX_SCAN_ALPHA				"A-Za-z"
#define REGEX_SCAN_BLANK				" \\t"
#define REGEX_SCAN_CNTRL				"\\x00-\\x1F\\x7F"
#define REGEX_SCAN_DIGIT				"0-9"
#define REGEX_SCAN_GRAPH				"\\x21-\\x7E"
#define REGEX_SCAN_LOWER				"a-z"
#define REGEX_SCAN_PRINT				"\\x20-\\x7E"
#define REGEX_SCAN_PUNCT				"\\]\\[\\!\\\"\\#\\$\\%\\&\\'\\(\\)\\*\\+\\,\\.\\/\\:\\;\\<\\=\\>\\?\\@\\\\\^\\_\\`\\{\\|\\}\\~\\-"
#define REGEX_SCAN_SPACE				" \\t\\r\\n\\v\\f"
#define REGEX_SCAN_UPPER				"A-Z"
#define REGEX_SCAN_XDIGIT				"A-Fa-f0-9"
#define REGEX_SCAN_ODIGIT				"0-7"

#define REGEX_PATTERN_WHWHMATCH			1L		// Useless Flag
#define REGEX_PATTERN_CRLF				2L
#define REGEX_PATTERN_LOYAL				3L		// Normal Character
#define REGEX_PATTERN_LOOP				4L
#define REGEX_PATTERN_CAPTURE			5L
#define REGEX_PATTERN_META				6L
#define REGEX_PATTERN_POSIX_META		7L
#define REGEX_PATTERN_CARROT			8L

#define REGEX_MATCH_CAPTURE				0x0001
#define REGEX_MATCH_FULLMATCH			0x0002
#define REGEX_MATCH_REPLACE				0x0003
#define REGEX_MATCH_UPLOWDO				0x0004		// do not consider upper and lower
#define REGEX_MATCH_MULLINE				0x0008		// multi line

// Used into compiling.
#define REGEX_MATCH_NOTEQUAL			0x0010
#define REGEX_MATCH_PLP					0x0020		// '('

#pragma region REGEX
//
//	SAVE REGEX PATTERN
//
static regex_pattern rp;

void _Push(ULONG _Type, UNICODE _Datat)
{
	const UNICODE _Data = _Datat;
	if (rp == LIST_NULL)
	{
		rp = _CreatePatn();
		rp->_Data = _Data;
		rp->_Type = _Type;
	}
	else
	{
		regex_pattern _Ko = _CreatePatn();
		_Ko->_Prev = rp;
		rp->_Next = _Ko;
		_Ko->_Next = 0;
		rp->_Data = _Data;
		rp->_Type = _Type;
		rp = _Ko;
	}
}

void _Pop()
{
	regex_pattern _Prev = rp->_Prev;
	Release(rp);
	rp = _Prev;
}

void _Goto(int pos)
{
	int i;
	for (; ; rp = rp->_Prev)
		if(!rp->_Prev)
			break;
	for (i = 0; i < pos; i++, rp = rp->_Next)
		;
}

int _Now()
{
	int i;
	regex_pattern cct = rp;
	for (; ; rp = rp->_Prev)
		if(!rp->_Prev)
			break;
	for (i = 0; rp != cct; i++, rp = rp->_Next)
		;
	return i;
}

void _ScanRegex(UNICODE_STRING patn);
BOOL _ToolScanLast(UNICODE_STRING patn, UNICODE wht);
UNICODE_STRING _ScanRegexMod(UNICODE_STRING patn);

regex_pattern ScanRegex(UNICODE_STRING patn)
{
	rp = _CreatePatn();
	_ScanRegex(patn);
	for (; ; rp = rp->_Prev)
		if(!rp->_Prev)
			break;
	return rp;
}

void _ScanRegex(UNICODE_STRING patn)
{
	if(*patn == '^'){
		if (_ToolScanLast(patn, '$') == FALSE)
			return;
		_Push(REGEX_PATTERN_WHWHMATCH, '\0');
		patn++;}
	_ScanRegexMod(patn, '\0');
}

#pragma region TTL_SRC
void _ScanUnit(UNICODE_STRING patn);
UNICODE_STRING _ScanGroup(UNICODE_STRING patn);
BOOL _ToolScanList(UNICODE a, const UNICODE_STRING pscn);
BOOL _ToolScanGroup(UNICODE a, UNICODE b, UNICODE c);
void _ScanGroupTypeA(UNICODE_STRING patn);
void _ScanGroupTypeB(UNICODE_STRING patn);
void _ScanGroupTypeC(UNICODE_STRING patn);
UNICODE _ToolTorrent(UNICODE A, const UNICODE_STRING B, const UNICODE_STRING C);
UNICODE_STRING _ToolMatchX(UNICODE_STRING t, UNICODE_STRING a);

UNICODE_STRING _ScanRegexMod(UNICODE_STRING patn, UNICODE cht)
{
	const UNICODE ch = cht;
	if (ch == ']')
		if(*patn == '-')
		{
			_Push(REGEX_PATTERN_LOOP, *patn);
			patn++;
		}
		else if (*patn == ':')
		{
			UNICODE_STRING tmp;
			_Pop();
			if(tmp = _ToolMatchX(REGEX_ALNUM, patn))
				_Push(REGEX_PATTERN_POSIX_META, 'a');	// alnum
			else if(tmp = _ToolMatchX(REGEX_WORD, patn))
				_Push(REGEX_PATTERN_POSIX_META, 'w');	// word
			else if(tmp = _ToolMatchX(REGEX_ALPHA, patn))
				_Push(REGEX_PATTERN_POSIX_META, 'l');	// alpha
			else if(tmp = _ToolMatchX(REGEX_BLANK, patn))
				_Push(REGEX_PATTERN_POSIX_META, 'b');	// blank
			else if(tmp = _ToolMatchX(REGEX_CNTRL, patn))
				_Push(REGEX_PATTERN_POSIX_META, 'c');	// cntrl
			else if(tmp = _ToolMatchX(REGEX_DIGIT, patn))
				_Push(REGEX_PATTERN_POSIX_META, 'd');	// digit
			else if(tmp = _ToolMatchX(REGEX_GRAPH, patn))
				_Push(REGEX_PATTERN_POSIX_META, 'g');	// graph
			else if(tmp = _ToolMatchX(REGEX_LOWER, patn))
				_Push(REGEX_PATTERN_POSIX_META, 'o');	// lower
			else if(tmp = _ToolMatchX(REGEX_PRINT, patn))
				_Push(REGEX_PATTERN_POSIX_META, 'p');	// print
			else if(tmp = _ToolMatchX(REGEX_PUNCT, patn))
				_Push(REGEX_PATTERN_POSIX_META, 'u');	// punct
			else if(tmp = _ToolMatchX(REGEX_SPACE, patn))
				_Push(REGEX_PATTERN_POSIX_META, 's');	// space
			else if(tmp = _ToolMatchX(REGEX_UPPER, patn))
				_Push(REGEX_PATTERN_POSIX_META, 'e');	// upper
			else if(tmp = _ToolMatchX(REGEX_XDIGIT, patn))
				_Push(REGEX_PATTERN_POSIX_META, 'x');	// xdigit
			else if(tmp = _ToolMatchX(REGEX_ODIGIT, patn))
				_Push(REGEX_PATTERN_POSIX_META, 't');	// odigit
			patn = tmp;
		}
		else if(*patn == '^')
		{
			_Push(REGEX_PATTERN_CARROT, *patn);
		}
	if (*patn == ch)
		return patn;
	switch(*patn)
	{
	case '\\':
		patn++;
		_ScanUnit(patn);
		patn++;
		break;

	case '(':
	case '[':
	case '{':
		// Group Start Flag
		_Push(REGEX_PATTERN_LOOP, *patn);

		patn = _ScanGroup(patn);

		// Group End Flag
		_Push(REGEX_PATTERN_LOOP, *patn);
		patn++;

		break;

	case '+':
	case '*':
	case '?':
	case '.':
		_Push(REGEX_PATTERN_LOOP, *patn);
		patn++;
		break;

	default:
		_Push(REGEX_PATTERN_LOYAL, *patn);
		patn++;
		break;
	}
	patn = _ScanRegexMod(patn, ch);
}

void _ScanUnit(UNICODE_STRING patn)
{
	BOOL Th;

	if ((Th = _ToolScanGroup(*patn, 'a', 'z')) == FALSE)
		;
	else if (Th = _ToolScanGroup(*patn, 'A', 'Z'))
		;

	if (Th == TRUE)
		_Push(REGEX_PATTERN_LOYAL, *patn);
	else 
		_Push(REGEX_PATTERN_META, *patn);

	return;
}

UNICODE_STRING _ScanGroup(UNICODE_STRING patn)
{
	if (_ToolScanList(*patn, ")]}") == TRUE)
		return;

	patn++;
	return _ScanRegexMod(patn, 
		_ToolTorrent(*(patn - 1), "([{", ")]}")
		);
}

#pragma endregion
#pragma endregion

#pragma region MATCH

#define REGEX_MATCHT_EXTMAP case 'w': check = __match_expand(REGEX_SCAN_WORD, *target); break;\
		case 'W': check = __match_cexpand(REGEX_SCAN_WORD, *target); break;\
		case 'd': check = __match_expand(REGEX_SCAN_DIGIT, *target); break;\
		case 'D': check = __match_cexpand(REGEX_SCAN_DIGIT, *target); break;\
		case 'a': check =  __match_expand(REGEX_SCAN_ALPHA, *target); break;\
		case 'l': check =  __match_expand(REGEX_SCAN_LOWER, *target); break;\
		case 'p': check =  __match_expand(REGEX_SCAN_PRINT, *target); break;\
		case 's': check =  __match_expand(REGEX_SCAN_SPACE, *target); break;\
		case 'S': check = __match_cexpand(REGEX_SCAN_SPACE, *target); break;\
		case 'u': check =  __match_expand(REGEX_SCAN_UPPER, *target); break;\
		case 'x': check =  __match_expand(REGEX_SCAN_XDIGIT, *target); break;\
		case 'o': check =  __match_expand(REGEX_SCAN_ODIGIT, *target); break;

#define REGEX_MATCHT_XETMAP case 'a': check = __match_expand(REGEX_SCAN_ALNUM, *target); break;\
		case 'w': check = __match_expand(REGEX_SCAN_WORD, *target); break;\
		case 'l': check = __match_expand(REGEX_SCAN_ALPHA, *target); break;\
		case 'b': check = __match_expand(REGEX_SCAN_BLANK, *target); break;\
		case 'c': check = __match_expand(REGEX_SCAN_CNTRL, *target); break;\
		case 'd': check = __match_expand(REGEX_SCAN_DIGIT, *target); break;\
		case 'g': check = __match_expand(REGEX_SCAN_GRAPH, *target); break;\
		case 'o': check = __match_expand(REGEX_SCAN_LOWER, *target); break;\
		case 'p': check = __match_expand(REGEX_SCAN_PRINT, *target); break;\
		case 'u': check = __match_expand(REGEX_SCAN_PUNCT, *target); break;\
		case 's': check = __match_expand(REGEX_SCAN_SPACE, *target); break;\
		case 'e': check = __match_expand(REGEX_SCAN_UPPER, *target); break;\
		case 'x': check = __match_expand(REGEX_SCAN_XDIGIT, *target); break;\
		case 't': check = __match_expand(REGEX_SCAN_ODIGIT, *target); break;

typedef struct _matchreturn{
	int Size;
	UNICODE_STRING *array;
}	Match;

//
//	Save Match Result
//
Match mt;

//
//	Save Target
//
UNICODE_STRING target;

//
//	Last Group
//
ULONG ppos;
UNICODE pcode;

//
//	Next Match
//
ULONG ntype;
UNICODE ncode;

#pragma region TTM_SRC
BOOL _ToolScanList(UNICODE a, const UNICODE_STRING pscn);
BOOL _ToolScanGroup(UNICODE a, UNICODE b, UNICODE c);
UNICODE _ToolTorrent(UNICODE A, const UNICODE_STRING B, const UNICODE_STRING C);
UNICODE_STRING _ToolMatchX(UNICODE_STRING t, UNICODE_STRING a);
void __match(regex_pattern patn, UNICODE_STRING target, ULONG option);
void __capturemode(regex_pattern patn, UNICODE_STRING target, ULONG option);
void __fullmatchmode(regex_pattern patn, UNICODE_STRING target, ULONG option);
BOOL __match_if(regex_pattern patn, UNICODE_STRING target, ULONG option);
regex_pattern __match_ifex(regex_pattern patn, UNICODE_STRING target, ULONG option, UNICODE ch);
BOOL __match_expand(UNICODE_STRING wht, UNICODE target);
BOOL __match_cexpand(UNICODE_STRING wht, UNICODE target);
BOOL __match_expandp(UNICODE target);
BOOL __match_cexpandp(UNICODE target);
regex_pattern __match_ifext(ULONG option, UNICODE ch);

Match regex_search(regex_pattern patn, UNICODE_STRING target)
{
	__match(patn, target, REGEX_MATCH_CAPTURE);
	return mt;
}

Match regex_match(regex_pattern patn, UNICODE_STRING target)
{
	__match(patn, target, REGEX_MATCH_FULLMATCH);
	return mt;
}

void __match(regex_pattern patn, UNICODE_STRING target, ULONG option)
{
	if ((option & 0x3) == REGEX_MATCH_CAPTURE)
		return __capturemode(patn, target, option);
	if ((option & 0x3) == REGEX_MATCH_FULLMATCH)
		return __fullmatchmode(patn, target, option);
}

void __capturemode(regex_pattern patn, UNICODE_STRING target, ULONG option)
{
}

void __fullmatchmode(regex_pattern patn, UNICODE_STRING targett, ULONG option)
{
	regex_pattern first = patn;		// Save
	rp = patn;
	target = targett;
	patn = __match_ifext(option, '\0');	// loop it
	if (patn == TRUE)
		mt.Size = 1;			// Success Check Test
}

regex_pattern __match_ifex(regex_pattern patn, UNICODE_STRING target, ULONG option, UNICODE ch)
{
	BOOL check = FALSE;
	regex_pattern back = patn;
	if ((patn->_Data == ch && patn->_Type == REGEX_PATTERN_LOOP) || 
		(option == REGEX_MATCH_NOTEQUAL && (*target != ch)))
		return TRUE;
	if (patn->_Next == LIST_NULL)
		return TRUE;
	switch(patn->_Type)
	{
	case 0:

		target++;
		return __match_ifex(patn, target, option, ch);

	case REGEX_PATTERN_LOYAL:
		if (*target == patn->_Data)
			check = TRUE;
		else
			check = FALSE;
		break;
	case REGEX_PATTERN_META:
		switch(patn->_Data)
		{
		REGEX_MATCHT_EXTMAP
		}
		break;
	case REGEX_PATTERN_POSIX_META:
		switch(patn->_Data)
		{
		REGEX_MATCHT_XETMAP
		}
		patn = patn->_Next;		// Skip ']'
		break;
	case REGEX_PATTERN_LOOP:
		switch(patn->_Data)
		{
		case '+':

			if(patn->_Prev->_Type == REGEX_PATTERN_LOYAL ||
				patn->_Prev->_Type == REGEX_PATTERN_META ||
				patn->_Prev->_Type == REGEX_PATTERN_POSIX_META)
			{
				patn->_Prev->_Type = 0;
				check = __match_ifex(patn->_Prev, target, REGEX_MATCH_NOTEQUAL, patn->_Data);
			}
			break;

		case '*':	// X
		case '.':	// X
		case '?':	// X
		case '(':

			back = patn;
			check = __match_ifex(patn, target, 0, ')');
			check = TRUE;
			break;

		case '[':
			patn = patn->_Next;

			if (*target == '^')
			{
				patn = patn->_Next;
				patn = __match_cexpandp(patn, *target);
			}
			else
				patn = __match_expandp(patn, *target);
			patn = patn->_Next;
			check = patn->_Data;
			break;
		case '{':
			break;
		}
		break;
	}
	target++;
	patn = patn->_Next;
	if (check == FALSE)
	{
		if(patn->_Data == '?')
			return __match_ifex(patn, target, option, 1);
		else if(patn->_Data == '*')
			return __match_ifex(patn, target, option, 2);
		return FALSE;
	}
	return __match_ifex(patn, target, option, ch);
}

regex_pattern __match_ifext(ULONG option, UNICODE ch)
{
	BOOL check = FALSE;
	if (rp->_Next == LIST_NULL)
		return TRUE;
	if ((option == REGEX_MATCH_NOTEQUAL) && (*target != ch))
		return TRUE;
	if (rp->_Data == ch)
		return TRUE;
	if (option == REGEX_MATCH_NOTEQUAL)
	{
		if(ntype == REGEX_PATTERN_LOYAL){if (*target == ncode)
				return TRUE;}
		else if(ntype == REGEX_PATTERN_META)
		{switch(ch)
			{REGEX_MATCHT_EXTMAP}
			if (check == TRUE)return TRUE;}
		else if(ntype == REGEX_PATTERN_POSIX_META)
		{switch(ch)
			{REGEX_MATCHT_XETMAP}
			if (check == TRUE)return TRUE;}
		/////////////////////////
		target++;
		return __match_ifext(option, ch);
	}
	else if (option == REGEX_PATTERN_META)
	{
		if(ntype == REGEX_PATTERN_LOYAL){if (*target == ncode)
				return TRUE;}
		else if(ntype == REGEX_PATTERN_META)
		{switch(ch)
			{REGEX_MATCHT_EXTMAP}
			if (check == TRUE)return TRUE;}
		else if(ntype == REGEX_PATTERN_POSIX_META)
		{switch(ch)
			{REGEX_MATCHT_XETMAP}
			if (check == TRUE)return TRUE;}
		/////////////////////////
		switch(ch)
		{
		REGEX_MATCHT_EXTMAP
		}
		target++;
		if (check == FALSE)
			return TRUE;
		else
			return __match_ifext(option, ch);
	}
	else if (option == REGEX_PATTERN_POSIX_META)
	{
		if(ntype == REGEX_PATTERN_LOYAL){if (*target == ncode)
				return TRUE;}
		else if(ntype == REGEX_PATTERN_META)
		{switch(ch)
			{REGEX_MATCHT_EXTMAP}
			if (check == TRUE)return TRUE;}
		else if(ntype == REGEX_PATTERN_POSIX_META)
		{switch(ch)
			{REGEX_MATCHT_XETMAP}
			if (check == TRUE)return TRUE;}
		/////////////////
		switch(ch)
		{
		REGEX_MATCHT_XETMAP
		}
		target++;
		if (check == FALSE)
			return TRUE;
		else
			return __match_ifext(option, ch);
	}
	else if (option == REGEX_PATTERN_LOOP)
	{
		if(ntype == REGEX_PATTERN_LOYAL){if (*target == ncode)
				return TRUE;}
		else if(ntype == REGEX_PATTERN_META)
		{switch(ch)
			{REGEX_MATCHT_EXTMAP}
			if (check == TRUE)return TRUE;}
		else if(ntype == REGEX_PATTERN_POSIX_META)
		{switch(ch)
			{REGEX_MATCHT_XETMAP}
			if (check == TRUE)return TRUE;}
		/////////////////
		_Goto(ppos);
		if(pcode == ']')
		{
			if (*target == '^') // Carrot
			{
				rp = rp->_Next;
				check = __match_cexpandp(*target);
			}
			else
				check = __match_expandp(*target);
			for (; rp->_Data != ']'; rp = rp->_Next)
				;
			rp = rp->_Next;

			target++;
			if (!*target)
				return TRUE;
			if (check == FALSE)
				return TRUE;
			else
				return __match_ifext(option, ch);
		}
		else if (pcode == ')')
		{
			rp = rp->_Next;
			check = __match_ifext(REGEX_MATCH_PLP, ')');
			if (rp == LIST_NULL)
				return TRUE;
			if (check == FALSE)
				return TRUE;
			else
				return __match_ifext(option, ch);
		}
	}
	switch(rp->_Type)
	{
	case REGEX_PATTERN_LOYAL:
		if (*target == rp->_Data)
			check = TRUE;
		else
			check = FALSE;
		break;
	case REGEX_PATTERN_META:
		switch(rp->_Data)
		{
		REGEX_MATCHT_EXTMAP
		}
		break;
	case REGEX_PATTERN_POSIX_META:
		switch(rp->_Data)
		{
		REGEX_MATCHT_XETMAP
		}
		rp = rp->_Next;		// Skip ']'
		break;
	case REGEX_PATTERN_LOOP:
		switch(rp->_Data)
		{
		case '[':
			ppos = _Now();
			rp = rp->_Next;
			if (*target == '^') // Carrot
			{
				rp = rp->_Next;
				check = __match_cexpandp(*target);
			}
			else
				check = __match_expandp(*target);
			for (; rp->_Data != ']'; rp = rp->_Next)
				;
			pcode = rp->_Data;
			if (rp->_Next == LIST_NULL)
				return TRUE;
			break;
		case '(':
			ppos = _Now();
			rp = rp->_Next;
			check = __match_ifext(REGEX_MATCH_PLP | option, ')');
			pcode = rp->_Data;
			if (rp == LIST_NULL)
				return TRUE;
			break;
		case '+':
			ntype = rp->_Next->_Type;
			ncode = rp->_Next->_Data;
			if(rp->_Prev->_Type == REGEX_PATTERN_LOYAL)
			{
				check = __match_ifext(REGEX_MATCH_NOTEQUAL, rp->_Prev->_Data);
				target--;		// xxxxxx...xx(x) <-1
			}
			else if(rp->_Prev->_Type == REGEX_PATTERN_META)
			{
				check = __match_ifext(REGEX_PATTERN_META, rp->_Prev->_Data);
				target--;		// xxxxxx...xx(x) <-1
			}
			else if(rp->_Prev->_Type == REGEX_PATTERN_POSIX_META)
			{
				check = __match_ifext(REGEX_PATTERN_POSIX_META, rp->_Prev->_Data);
				target--;		// xxxxxx...xx(x) <-1
			}
			else if(rp->_Prev->_Type == REGEX_PATTERN_LOOP)
			{
				check = __match_ifext(REGEX_PATTERN_LOOP, 0);
				target--;		// xxxxxx...xx(x) <-1
				rp = rp->_Next;
			}
			break;
		case '.':
			check = TRUE;
			break;
		}
		break;
	}
	target++;
	rp = rp->_Next;
	if (check == FALSE)
	{
		if(rp->_Data == '?')
			return __match_ifext(target, option, 1);
		else if(rp->_Data == '*')
			return __match_ifext(target, option, 2);

		return FALSE;
	}
	return __match_ifext(option, ch);
}

BOOL __match_expand(UNICODE_STRING wht, UNICODE target)
{ // for meta
	regex_pattern rpx;
	UNICODE cha[2];
	if (*wht == '\0')
		return FALSE;
	switch(*wht)
	{
	case '\\':
		wht++;
		switch(*wht)
		{
		case 't':
			if ('\t' == target)
				return TRUE;
			break;
		case 'r':
			if ('\r' == target)
				return TRUE;
			break;
		case 'n':
			if ('\n' == target)
				return TRUE;
			break;
		case 'x':
			break;
		default:
			if (*wht == target)
				return TRUE;
			rpx = _CreatePatn();
			rpx->_Next = 0;
			rpx->_Data = *wht;
			rpx->_Type = REGEX_PATTERN_META;
			cha[0] = *wht; cha[1] = 0;
			if (__match_ifex(rpx, cha, 0, 0) == TRUE)
				return TRUE;
			break;
		}
		wht += 2;
	default:
		if(*(wht + 1) == '-')
		{
			if (_ToolScanGroup(target, *wht, *(wht + 2)) == TRUE)
				return TRUE;
			wht += 3;
			break;
		}
		else if(*wht == target)
		{
			return TRUE;
		}
		wht++;
		break;
	}
	return __match_expand(wht, target);
}

BOOL __match_cexpand(UNICODE_STRING wht, UNICODE target)
{ // for meta
	return !__match_expand(wht, target);
}

BOOL __match_expandp(UNICODE target)
{ // for path
	regex_pattern rpx;
	UNICODE cha[2];
	if (rp->_Data == ']')
		return FALSE;
	switch(rp->_Type)
	{
	case REGEX_PATTERN_META:
		rpx = _CreatePatn();
		rpx->_Next = 0;
		rpx->_Data = rp->_Data;
		rpx->_Type = REGEX_PATTERN_META;
		cha[0] = rp->_Data; cha[1] = 0;
		if (__match_ifex(rpx, cha, 0, 0) == TRUE)
			return TRUE;
		rp = rp->_Next;
		break;
	case REGEX_PATTERN_LOYAL:
		if (rp->_Data == target)
			return TRUE;
		rp = rp->_Next;
		break;
	default:
		if(rp->_Next->_Data == '-')
		{
			if (_ToolScanGroup(target, rp->_Data, 
				rp->_Next->_Next->_Data) == TRUE)
				return TRUE;
			rp = rp->_Next->_Next->_Next;
			break;
		}
		else if(rp->_Data == target)
		{
			return TRUE;
		}
		rp = rp->_Next;
		break;
	}
	return __match_expandp(target);
}

BOOL __match_cexpandp(UNICODE target)
{ // for meta
	return !__match_expandp(target);
}

#pragma endregion
#pragma endregion

#pragma region TTL_TOOL_SRC
BOOL _ToolScanList(UNICODE a, const UNICODE_STRING pscn)
{
	for (; *pscn; pscn++)
		if (a == *pscn)
			return TRUE;
	return FALSE;
}

BOOL _ToolScanGroup(UNICODE a, UNICODE b, UNICODE c)
{
	//int i;
	//for(i = b; b != c; b++)
	//	if (i == a)
	//		return TRUE;
	//	else if (i > 255)
	//		return FALSE;
	if (b <= a && a <= c)
		return TRUE;
	return FALSE;
}

BOOL _ToolScanLast(UNICODE_STRING patn, UNICODE wht)
{
	const UNICODE_STRING	t = patn;
	for (; *t; t++)
		;
	if (*(t - 1) == wht)
		return TRUE;
	return FALSE;
}

UNICODE _ToolTorrent(UNICODE A, const UNICODE_STRING B, const UNICODE_STRING C)
{
	int t;
	for(t = 0; *B; B++, t++)
		if (*B == A)
			return C[t];
}

UNICODE_STRING _ToolMatchX(UNICODE_STRING t, UNICODE_STRING a)
{
	const UNICODE_STRING tx = t, *ax = a;
	for(; *tx; tx++, ax++)
		if (*tx != *ax)
			return (UNICODE_STRING)FALSE;
	return ax;
}
#pragma endregion

#include <stdio.h>

main()
{
	regex_pattern k;

	k = ScanRegex("\\d+1");

	/*for (; ; k = k->_Next)
	{
		printf("%c", k->_Data);
		if(!k->_Next)
			break;
	}*/

	Match mx = regex_match(k, "0001");

	return 0;
}