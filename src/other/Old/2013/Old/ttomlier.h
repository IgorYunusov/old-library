/*************************************************************
  
       ROLLRAT LIBRARY TTOMLIER V1

       COPYRIGHT @ ROLLRAT. 2014 ALL RIGHTS RESERVED.

**************************************************************/

#ifndef _TTOMLIER_
#define _TTOMLIER_

#define _MULTILINE_SKIP(yyalv) (yyalv != '\r' && yyalv != '\n')

#include "unicode.h"
#include "cpunroll.h"
#include "tree.h"

template <class u_type>
class StackNodeEx{
public:
	StackNodeEx() :
		_Next(nullptr)
		{
		}
	StackNodeEx<u_type> * _Next;
	u_type _Data;
	};

template<class u_type>
class stack{
public:
	typedef StackNodeEx<u_type> _MyNode;

	_MyNode * _Current;

	stack()
		{
		_Current = nullptr;
		}

	void push(u_type what)
		{ // push data
		_MyNode *_Tmp = new _MyNode();
		_Tmp->_Data = what;
		if (_Current == nullptr)
			_Current = _Tmp;
		else
			{
			_Tmp->_Next = _Current;
			_Current = _Tmp;
			}
		}

	u_type top()
		{ // get top data
		return _Current->_Data;
		}

	void pop()
		{ // pop data
		_MyNode * _Next = _Current->_Next;
		delete _Current;
		_Current = _Next;
		}

	};

template<class _compiler_char = char, class _uni = wchar_t> class
	ttomlier
	{
	typename _compiler_char * _cp_arry;
	_compiler_char const typename * const _constI;
	stack<_compiler_char *> _stack;
	
	//////////////////////////////////////////////////
	// OPTION BIT SET
	// 0:multi_line   1:back_postition
	unsigned long long option;

	typedef typename _compiler_char _compa;

	inline _compa *& unLock(_compiler_char const typename * const _px)
		{ // Lock
		_compa * _x =
			const_cast<_compa*>(_px);
		return _x;
		}
public:

#define _unck		(unLock(_constI))

	ttomlier()
		: option(0), _constI(nullptr)
		{
		}

	explicit ttomlier(_compa *_set)
		: _constI(_set), _cp_arry(_set)
		{
		}

	_compa *& operator*()
		{
		return _cp_arry;
		}

	void swap(_compa *_cp_arry)
		{ // swap??
		this->_cp_arry = _cp_arry;
		}
	
	enum { multi_line = 1 };
	void setInput(_compa *_cp_arry, bool _multi_line, int option = 0)
		{
		this->_cp_arry = _cp_arry;
		this->option |= _multi_line ? multi_line : 0;
		_stack.push(_unck);
		}

	void setLast()
		{ // zero set
		for (; *_cp_arry++;)
			;
		}

	void setLast2()
		{ // zero prev
		setLast();
		_cp_arry--;
		}

	void setFirst()
		{
		_cp_arry = _unck;
		}

	_compa * getLast()
		{
		const _compa * _f;
		setLast();
		_f = _cp_arry;
		setFirst()
		return _f;
		}

	bool isIn(_compa *tc, _compa ch)
		{
		for(_compa *vc; *vc; vc++)
			if (*vc == ch)
				return true;
		return false;
		}

	bool isOut(_compa *tc, _compa ch)
		{
		return !isIn(tc, ch);
		}

	bool isIn(_compa ch1, _compa *tc, _compa ch2)
		{
		return (ch1 <= *tc && *tc <= ch2);
		}

#define __sml	1	// skip multi line
//#define __sbp	2	// start back position
	void forwardChar(_compa _ch, int option = 0)
		{
		if(option > 0)	// FORCE CHANEL
			if (option & __sml)
				goto sml;
			else;
		else
			{
			if(~this->option & multi_line)
				for(_compa * _i = _cp_arry; *_i; _i++)
					if (_MULTILINE_SKIP(*_i))
						break;
					else if (_ch == *_i)
						{
						_cp_arry = _i; break;
						}
					else ;
			else
				sml:
				for(_compa * _i = _cp_arry; *_i; _i++)
					if (_ch == *_i)
						{
						_cp_arry = _i; break;
						}
			}
		}

	void backChar(_compa _ch, int option = 0)
		{
		if(option > 0)	// FORCE CHANEL
			if (option & __sml)
				goto sml;
			else;
		else
			{
			_compa * _ety = _cp_arry;
			setLast2();
			if(~this->option & multi_line)
				for(_compa * _j = _cp_arry; _j != _ety; _j--)
					if (_MULTILINE_SKIP(*_i))
						break;
					else if (_ch == *_i)
						{
						_cp_arry = _i; break;
						}
					else;
			else
				sml:
				for(_compa * _i = _cp_arry; _j != _ety; _i--)
					if (_ch == *_i)
						{
						_cp_arry = _i; break;
						}
			}
		}

	/////////////////////////////
	//	HANGUL UNICODE SETUP
	/////////////////////////////

#define _make_h_alpha(cho, jung, jong)		(0xac00 + cho * 588 + jung * 28 + jong)

	_uni getHnumber(_uni wy)
		{
		_uni * Cho =
			L"ぁあいぇえぉけげこさざしじすずせぜそぞ";
		_uni * Jung =
			L"ただちぢっつづてでとどなにぬねのはばぱひび";
		_uni * Jong =
			L"ぁあぃいぅうぇぉおかがきぎくぐけげごさざしじずせぜそぞ";
		for(const _uni * _j = Cho; *_j; _j++)
			if (wy == *_j)
				return (_j - Cho - 2);
		for(const _uni * _j = Jung; *_j; _j++)
			if (wy == *_j)
				return (_j - Jung - 2);
		for(const _uni * _j = Jong; *_j; _j++)
			if (wy == *_j)
				return (_j - Jong - 1);
		return (-1);
		}

	struct _junk{
		int jong, jung, cho;
		}; 

	_junk disassembleHcode(_uni wy)
		{
		wy -= 0xac00;
		_junk _r;
		_r.jong = wy % 28;
		_r.jung = (wy / 28) % 21;
		_r.cho = wy / 28 / 21;
		return _r;
		}

#define whtspcList		"\v\f\r\n\t "
#define whtspcList2		"\v\f\t "

	void whitespaceSkip(int option = 0)
		{
		if(option > 0)	// FORCE CHANEL
			if (option & __sml)
				goto sml;
			else;
		else
			if(~this->option & multi_line)
				for(; *_cp_arry ; _cp_arry++)
					if (!isIn(whtspcList2))
						break;
					else;
			else
				sml:
				for(; *_cp_arry ; _cp_arry++)
					if (!isIn(whtspcList))
						break;
		}

	void skipCh(_compa ch)
		{
		for (; *_cp_arry == ch; _cp_arry++)
			;
		}

#define engasciiFCV			0x20

	void upper(_compa *_cp_arry_t)
		{
		for (_compa *tmp = _cp_arry_t; *tmp; tmp++)
			*tmp &= ~engasciiFCV;
		}

	void lower(_compa *_cp_arry_t)
		{
		for (_compa *tmp = _cp_arry_t; *tmp; tmp++)
			*tmp |= engasciiFCV;
		}

#define numasciiFC			0x0f

	void numberic(_compa *_cp_arry_t)
		{
		for (_compa *tmp = _cp_arry_t; *tmp; tmp++)
			*tmp &= numasciiFC;
		}

	void pushSite()
		{
		_stack.push(_cp_arry);
		}

	void popSite()
		{
		_cp_arry = _stack.top();
		_stack.pop();
		}

	int getLenth(_compa *_cp_arry_t)
		{
		const _compa *_cp_arry_c = _cp_arry_t;
		for( ; *_cp_arry_c; _cp_arry_c++)
			;
		return (_cp_arry_c - _cp_arry_t - 1);
		}

	void alphabetSkip(int option = 0)
		{
		for(; *_cp_arry ; _cp_arry++)
			if (!(isIn('a', *_cp_arry, 'z') 
				|| isIn('A', *_cp_arry, 'Z')))
				break;
		}

	void numbericSkip(int option = 0)
		{
		for(; *_cp_arry ; _cp_arry++)
			if (!isIn('0', *_cp_arry, '9'))
				break;
		}

	typename typedef _compa _Atm;

	///////////////////
	// ATM Functions
	///////////////////
	int _strchr(_In_ _Atm *left, _In_ _Atm right) 
		{	// E : search character in string
		const char * ptr = left;
		for(; *ptr; ptr++){
			if(*ptr == right)
				return ptr - left + 1;
			}
		return 0;
		}

	int strchr_(_In_ _Atm *left, _In_ _Atm right) 
		{	// E : search character in string
		const char * ptr = left;
		while(*ptr++)
			;
		for(; ptr != left; ptr--){
			if(*ptr == right)
				return ptr - left + 1;
			}
		return 0;
		}

	_Atm *__strchr(_In_ _Atm *left, _In_ _Atm right) 
		{	// E : search character in string
		char * ptr = (char *)left;
		for(; *ptr; ptr++){
			if(*ptr == right)
				return ptr;
			}
		return 0;
		}

	_Atm *strchr__(_In_ _Atm *left, _In_ _Atm right) 
		{	// E : search character in string
		char * ptr = (char *)left;
		while(*ptr++)
			;
		for(; ptr != left; ptr--){
			if(*ptr == right)
				return ptr;
			}
		return 0;
		}
	
		// STRSTR Functions
	_Atm *_strstr(_In_ _Atm *left, _In_ _Atm *right)
		{	// E : search string in string
		char * ptr = (char *)left;
		char * s1, * s2;
		for(; *ptr; ptr++){
			s1 = ptr;
			s2 = (char *)right;
			while (*s1 && *s2 && !(*s1 - *s2))
				s1++, s2++;
			if (!*s2)
				return (ptr);
			}
		return 0;
		}

	_Atm *strstr_(_In_ _Atm *left, _In_ _Atm *right)
		{	// E : search string in string
		char * ptr = (char *)left;
		char * s1, * s2;
		while(*ptr++)
			;
		for(; ptr != left; ptr--){
			s1 = ptr;
			s2 = (char *)right;
			while (*s1 && *s2 && !(*s1 - *s2))
				s1++, s2++;
			if (!*s2)
				return (ptr);
			}
		return 0;
		}

	_Atm *_m_d_strstr(_In_ _Atm *left, _In_ _Atm *right)
		{	// E : search string in string
		char * ptr = (char *)left;
		char * s1, * s2;
		for(; *ptr; ptr++){
			s1 = ptr;
			s2 = (char *)right;
			while (*s1 && *s2 && !(*s1 - *s2))
				s1++, s2++;
			if (!*s2)
				return (s1);
		}
		return 0;
		}

	_Atm *_strspc(_In_ _Atm *left, _In_ _Atm middle1, _In_ _Atm middle2, _Out_ _Atm *right)
		{	// E : search character character in string
		char * ptr = right;
		char * s1, * s2;
		if(!(s1 = __strchr( left, middle1 )))
			right = 0;
		if(!(s2 = strchr__( left, middle2 )))
			right = 0;
		for(s1 += 1; s1 != s2; s1++, ptr++)
			*ptr = *s1;
		return right;
		}

	_Atm *_strspc(_In_ _Atm *left, _In_ _Atm *middle1, _In_ _Atm *middle2, _Out_ _Atm *right)
		{	// E : search character character in string
		char * ptr = right;
		char * s1, * s2;
		if(!(s1 = _m_d_strstr( left, middle1 )))
			right = 0;
		if(!(s2 = strstr_( left, middle2 )))
			right = 0;
		for(; s1 != s2; s1++, ptr++)
			*ptr = *s1;
		return right;
		}

	_Atm *strspc_(_In_ _Atm *left, _In_ _Atm middle1, _In_ _Atm middle2, _Out_ _Atm *right)
		{	// E : search character character in string
		char * ptr = right;
		char * s1, * s2;
		if(!(s1 = __strchr( left, middle1 )))
			right = 0;
		if(!(s2 = __strchr( s1, middle2 )))
			right = 0;
		for(s1 += 1; s1 != s2; s1++, ptr++)
			*ptr = *s1;
		return right;
		}

	_Atm *strspc_(_In_ _Atm *left, _In_ _Atm *middle1, _In_ _Atm *middle2, _Out_ _Atm *right)
		{	// E : search character character in string
		char * ptr = right;
		char * s1, * s2;
		if(!(s1 = _m_d_strstr( left, middle1 )))
			right = 0;
		if(!(s2 = _strstr( s1, middle2 )))
			right = 0;
		for(; s1 != s2; s1++, ptr++)
			*ptr = *s1;
		return right;
		}


	/*-------------------------------------------------------------------------------------------------*/
	//
	//        RCL - ROLLRAT TRANSPLATABLE LIBRARY
	//			 R COMPILER LANGUAGE PROJECT
	//				NATIVE C Librorum
	//
	/*-------------------------------------------------------------------------------------------------*/
	
#pragma region PREPARE

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

#pragma endregion

#pragma region REGEX
	//
	//	SAVE REGEX PATTERN
	//
	regex_pattern rp;
	
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

public:

	/*-------------------------------------------------------------------------------------------------*/
	//
	//       for Toleration Compiler Programmer
	//			 R COMPILER LANGUAGE PROJECT
	//				NATIVE C Librorum
	//
	/*-------------------------------------------------------------------------------------------------*/

	xtree<_compa> _mk_tree;



	};

#endif