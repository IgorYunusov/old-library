/*************************************************************
  
       ROLLRAT LIBRARY REGULAR EXPRESSION V2

       COPYRIGHT @ ROLLRAT. 2014 ALL RIGHTS RESERVED.

**************************************************************/

#ifndef _REGEX_V2_
#define _REGEX_V2_

#include <vector>
#include <stack>

// This is independent library for c++.

	// FROM RCL_RTL_REGEX.c

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

#define SCAN_GOTO_FLAG					1

typedef enum class ___regex_pattern{
	_LOYAL = 0,		// normal metacharacter
	_LOOP,
	_CAPTURE,
	_META,
	_POSIXMETA,
	_CARROT,
}	_regex_pattern;

typedef enum ___regex_option{
	none = 0,
	crlf_skip,		// skip crlf

}	_regex_option;

template <typename _regex_array = char> class
	regex
	{
public:
	_regex_array *pointer;
	_regex_option option;

	typedef struct _emitter {
		_emitter(_regex_array _ch, _regex_pattern _pat)
			: ch(_ch), pat(_pat), option(0), _connection(nullptr)
			{
			}
		explicit _emitter(_regex_array _ch)
			: _emitter(_ch, _regex_pattern::_LOYAL)
			{
			}
		explicit _emitter()
			: _emitter(0)
			{
			}
		_regex_array ch;
		_regex_pattern pat;
		struct _emitter * _connection;
		int option;
	} emitter;

	std::vector<struct emitter *> _Vector;

	std::stack<struct emitter *> _Stack;

	regex()
		: pointer(nullptr)
		{
		}

	explicit regex(_regex_array *_pointer)
		: pointer(_pointer), option(none)
		{
		}

	explicit regex(_regex_array *_pointer, _regex_option _option)
		: pointer(_pointer), option(_option)
		{
		}

	void analysis()
		{
		_cosistents();
		}

	void analysis(_regex_array *_pointer)
		{
		pointer = _pointer;
		analysis();
		}

private:

	void _cosistents()
		{
		emitter *_Tmp;
		_Vector.clear();
		while( *pointer )
			{
#define NEW_EMITTER new struct emitter
			switch(*pointer)
				{
			case '\\':
				check_reverseslash_unit() ?
				_Vector.push_back(NEW_EMITTER(*pointer++, _regex_pattern::_META)) : 
				_Vector.push_back(NEW_EMITTER(*pointer++));
				break;
			case '(':
				_Tmp = NEW_EMITTER(*pointer++, _regex_pattern::_CAPTURE);
				_Stack.push(_Tmp);
				_Vector.push_back(_Tmp);
				break;
			case '[':
				_Tmp = NEW_EMITTER(*pointer++, _regex_pattern::_CAPTURE);
				_Stack.push(_Tmp);
				if(*pointer == '^')
					{
					_Vector.push_back(NEW_EMITTER(*pointer++, _regex_pattern::_CARROT));
					pointer++;
					}
				break;
			case ')':
				_Tmp = NEW_EMITTER(*pointer++, _regex_pattern::_CAPTURE);
				_Tmp->_connection = _Stack.top();
				_Tmp->option = SCAN_GOTO_FLAG;
				_Stack.pop();
				_Vector.push_back(_Tmp);
				break;
			case ']':
				_Tmp = NEW_EMITTER(*pointer++, _regex_pattern::_CAPTURE);
				_Tmp->_connection = _Stack.top();
				_Tmp->option = SCAN_GOTO_FLAG;
				_Stack.pop();
				_Vector.push_back(_Tmp);
				break;
			case '-':
			case '+':
			case '*':
			case '|':
			case '$':
			case '.':
				_Vector.push_back(NEW_EMITTER(*pointer++, _regex_pattern::_META));
				break;
			default:
				_Vector.push_back(NEW_EMITTER(*pointer++));
				break;
				}
			}
		}

	bool check_reverseslash_unit()
		{
		if (('a' <= *pointer && *pointer <= 'z') ||
			('A' <= *pointer && *pointer <= 'Z') ||
			('0' <= *pointer && *pointer <= '9'))
			return true;
		return false;
		}

	};


template <typename _regex_array = char> class
	match
	{

	};

#endif