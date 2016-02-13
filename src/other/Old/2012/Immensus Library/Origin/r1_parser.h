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

#ifndef _r1_parser
#define _r1_parser

/*************************************************************

	RollRat r1 Parser
	
*************************************************************/

#define unfinished_unicode_template		char
#define __DirectllyServentMachine		static
#define _IS_DIGIT(x) (('0' <= x) && (x <= '9'))
#define _TOKEN		gb_token
#define _FACTOR_FAMILY(x, y) \
		(_TOKEN == x)\
		{\
			match(x);\
			temp = exp();\
			match(y); \
		}

template<class _UTF = unfinished_unicode_template> class
	_r1parser_token
	{ // r1 parser token
	_UTF *_token;
	const _UTF *_token_ptr;
public:

	};

template<class _UTF = unfinished_unicode_template> class
	_r1parser_string
	{ // r1 parser token
	const _UTF *_str;
	const _UTF *_str_ptr;
	_UTF x_token;
public:
	void SetString(const _UTF *str) {_str = str;_str_ptr = _str;}
	void match(const _UTF e) {if(x_token == e)	x_token = *this->operator++();}
	const _UTF operator[](int i) const {return _str[i];}
	const _UTF operator()(int i) const {return _str_ptr[i];}
	const _UTF operator++() const {return *(_str_ptr++);}
	const _UTF operator--() const {return *(_str_ptr--);}
	const _UTF *GetStringByValue(int f, int l)
		{
			_UTF *f = new _UTF[l - f + 1];
			for(int i = f; i <= l; i++)
				f[i] = _str[i];
			f[l + 1] = '\0';
			return f;
		}
	const _UTF *GetStringByValueEx(int f, int l)
		{
			_UTF *f = new _UTF[l - f + 1];
			for(int i = f; i <= l; i++)
				f[i] = _str_ptr[i];
			f[l + 1] = '\0';
			return f;
		}
	};

template<class _UTF = unfinished_unicode_template> class
	_r1parser_module_sample
		:	public _r1parser_token<_UTF>
	{ // r1 parser module sample
	_UTF gb_token;
	const _UTF *ptr;
	void charset(const char *st){ptr = st;gb_token = getnextchar();}
	void match(_UTF e){if(gb_token == e)gb_token = getnextchar();}
	void forward(){ptr--;}
	_UTF getnextchar(){ptr++;return *(ptr - 1);}
public:
	/**********************************************
	:MODULE
		e -> IF ELSE OR AND
		  | <exp> -> <term> { <%rex%> <term> }
		  | <%rex%> -> 
		  | <term> -> <factor> { <%reg%> <factor> }
		  | <%reg%> -> 
		  | <factor> -> ( <exp> )
	**********************************************/
	int factor()
		{
		}
	int exp()
		{
			int temp = term();
		}
	int term()
		{
			int temp = factor();
		}
	};

template<class _UTF = unfinished_unicode_template> class
	_r1parser_regex_matcher
		:	public _r1parser_module_sample<_UTF>
	{ // r1 parser module sample
	_UTF gb_token;
	const _UTF *ptr;
private:
	void charset(const char *st){ptr = st;gb_token = getnextchar();}
	void match(_UTF e){if(gb_token == e)gb_token = getnextchar();}
	void forward(){ptr--;}
	_UTF getnextchar(){ptr++;return *(ptr - 1);}
public:
	/*******************************************************************************************
	:MODULE
		%Expression
			process -> regex_automata
			regex_automata -> regex_automata servent | servent
			servent -> paten | type_specifier | function | one_match
			paten -> '(' | ')' | '[' | ']' | '{' | '}'
			type_specifier -> '\' | '@' | '$' | '^' | '%' | '&' | '*' | '+' | '-' | '?' 
						| ':' | '!' | '=' | '.' | ','
			function -> ( function ) | ( var_stmt ) | Ɛ
			var_stmt -> var_stmt type_specifier | type_specifier | num(0-9) | char(a-zA-Z)
			one_match -> type_specifier one_match | [ function ] | [ one_match ] | [ var_stmt ]
	*******************************************************************************************/
	
	};

#endif