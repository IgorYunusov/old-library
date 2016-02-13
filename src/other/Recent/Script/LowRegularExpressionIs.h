/*************************************************************************

   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:

   LowRegularExpressionIs.h

Project:

	RollRat Script Parser - Simple Regex Checker

------
   AUTHOR: HyunJun Jeong  2015-08-13

***************************************************************************/

#ifndef _LOWREGEX_deb5cf012b2242bfbb46f8bf378f6daf_
#define _LOWREGEX_deb5cf012b2242bfbb46f8bf378f6daf_

#include <string.h>
#include <vector>
#include <sstream>
#include <stack>
#include "CString.h"

namespace Script {

typedef enum class _enum_lre_symbol {
	Alnum = 0,
	Alpha = 1,
	Blank = 2,
	Space = 3,
	Upper = 4,
	Lower = 5,
	Punct = 6,
	Word = 7,
	Digit = 8,
	XDigit = 9,
	Tab = 10,		// \t
	Return = 11,	// \r
	LineFeed = 12,	// \n
}	LRE_SYMBOL;

class LowRegularExpressionImpl {
public:
	typedef class LowRegularExpressionImpl MyClass;

	CString m_str;
	char m_ch;
	LRE_SYMBOL m_sym;
	unsigned int m_cuhex;
	unsigned short m_cxhex;

	bool m_repeat;
	bool m_least;		// true: +, false: *
	bool m_single;		// repeat single (capture grouping)
	bool m_collect;		// [~]
	bool m_carrot;		// [^~]
	bool m_or;			// (~|~)
	bool m_capture;		// (~)<nothing>
	bool m_symbol;
	bool m_large;		// large symbol
	bool m_uhex;
	bool m_xhex;
	bool m_any;			// anything: dot(.)
	bool m_pig;			// ? or (0 or 1 times matched)
	bool m_isstr;

	class LREExpressionImpl {
	public:
		bool m_isscope;
		bool m_isch;
		bool m_isuhex;
		bool m_isxhex;
		bool m_issym;
		unsigned int m_word1;
		unsigned int m_word2;
		unsigned short m_xhex1;
		unsigned short m_xhex2;
		char m_ch1;
		char m_ch2;
		bool m_large;
		LRE_SYMBOL m_sym;
	};
	
	std::vector<LREExpressionImpl *> m_lre;
	std::vector<std::vector<MyClass *>> m_list; // or list
	MyClass *m_singlelist;	// repeat single
};

typedef LowRegularExpressionImpl::LREExpressionImpl	LREImpl;

LowRegularExpressionImpl *CreateLREUnit()
{
	LowRegularExpressionImpl *tmp = new LowRegularExpressionImpl;

	tmp->m_str = CString();
	tmp->m_repeat = false;
	tmp->m_least = false;
	tmp->m_single = false;
	tmp->m_collect = false;
	tmp->m_carrot = false;
	tmp->m_or = false;
	tmp->m_symbol = false;
	tmp->m_large = false;
	tmp->m_uhex = false;
	tmp->m_xhex = false;
	tmp->m_isstr = false;

	tmp->m_lre = std::vector<LowRegularExpressionImpl::LREExpressionImpl *>();
	//tmp->m_list = std::vector<LowRegularExpressionImpl *> ();
	tmp->m_singlelist = nullptr;

	return tmp;
}

LREImpl *CreateLREImplUnit()
{
	LREImpl *tmp = new LREImpl;
	tmp->m_isch = false;
	tmp->m_isuhex = false;
	tmp->m_isxhex = false;
	tmp->m_issym = false;
	tmp->m_large = false;
	tmp->m_isscope = false;
	return tmp;
}

class LowRegularExpressionIs {
public:

#define PATTERN_PARSE_ERROR {m_error = true; return;}

	LowRegularExpressionIs(const char *pattern)
		: m_pattern(pattern)
	{
		pattern_parse();
	}

	bool MatchIs(const char *str)
	{
		for (int i = 0; i < lre.size(); i++)
		{
			LowRegularExpressionImpl *lrep = lre[i];
			int plus_count = 0;
			int pig_count = 0;
			auto _test_return = [&] () -> bool {
				if (lrep->m_repeat && !lrep->m_least)
					return true;
				else if (lrep->m_least) {
					if (plus_count > 0)
						return true;
				} else if (lrep->m_pig) {
					if (pig_count > 0)
						return true;
				}
				return false;
			};
			if (lrep->m_symbol == true) {
				if (lrep->m_uhex == true) {
					if (*(str++) != lrep->m_cuhex)
						if (_test_return())
							return false;
				} else if (lrep->m_xhex == true) {
					if (*(str++) != lrep->m_cxhex)
						if (_test_return())
							return false;
				} else {
					if (!SymbolCheck(lrep->m_sym, *(str++)))
						if (_test_return())
							return false;
				}
			} else if (lrep->m_any == true) {
			} else if (lrep->m_collect == true) {
			} else if (lrep->m_or == true) {
			} else if (lrep->m_isstr == true) {
				for (int i = 0; i < lrep->m_str.Length(); i++) {
					if (*(str++) != lrep->m_str[i])
						if (_test_return())
							return false;
				}
			} else {
				if (*(str++) != lrep->m_ch)
					if (_test_return())
						return false;
			}
		}
		return true;
	}

private:

	bool _NextMatchTest(const char *str, int i)
	{
		LowRegularExpressionImpl *lrep = lre[i+1];
		if (lrep->m_symbol == true) {
			if (lrep->m_uhex == true) {
				if (*(str++) != lrep->m_cuhex)
					return false;
			} else if (lrep->m_xhex == true) {
				if (*(str++) != lrep->m_cxhex)
					return false;
			} else {
				if (!SymbolCheck(lrep->m_sym, *(str++)))
					return false;
			}
		} else if (lrep->m_any == true) {
		} else if (lrep->m_collect == true) {
		} else if (lrep->m_or == true) {
		} else if (lrep->m_isstr == true) {
			for (int i = 0; i < lrep->m_str.Length(); i++) {
				if (*(str++) != lrep->m_str[i])
					return false;
			}
		} else {
			if (*(str++) != lrep->m_ch)
				return false;
		}
	}

	// tools

	bool SymbolCheck(LRE_SYMBOL sym, char ch)
	{
		switch(sym)
		{
		case LRE_SYMBOL::Alnum:		if (isalnum(ch)) return true; break;
		case LRE_SYMBOL::Alpha:		if (isalpha(ch)) return true; break;
		case LRE_SYMBOL::Blank:		if (isblank(ch)) return true; break;
		case LRE_SYMBOL::Space:		if (isspace(ch)) return true; break;
		case LRE_SYMBOL::Upper:		if (isupper(ch)) return true; break;
		case LRE_SYMBOL::Lower:		if (islower(ch)) return true; break;
		case LRE_SYMBOL::Punct:		if (ispunct(ch)) return true; break;
		case LRE_SYMBOL::Word:		if (isalnum(ch) || ch == '_') return true; break;
		case LRE_SYMBOL::Digit:		if (isdigit(ch)) return true; break;
		case LRE_SYMBOL::XDigit:	if (isxdigit(ch)) return true; break;
		case LRE_SYMBOL::Tab:		if (ch == '\t') return true; break;
		case LRE_SYMBOL::Return:	if (ch == '\r') return true; break;
		case LRE_SYMBOL::LineFeed:	if (ch == '\n') return true; break;
		}
		return false;
	}

private:

	std::vector<LowRegularExpressionImpl *> lre;

	//
	//	Simple Fast Scan
	//
	void pattern_parse()
	{
		std::stack<LowRegularExpressionImpl *> capture_stack;
		std::stack<std::vector<LowRegularExpressionImpl *>> lre_stack;
		std::stack<std::vector<std::vector<LowRegularExpressionImpl *>>> or_list;
		std::stack<int>	or_count;
		std::stack<bool> is_single;
		int stack_top = 0;
	
		LowRegularExpressionImpl *implement = CreateLREUnit();
		bool is_single_key = false;
		int or_countx = 0;

		//
		//	Low Loop
		//
		for (int i = 0; i < strlen(m_pattern);)
		{
			//
			//	Pattern Unit Identifying
			//
			switch(m_pattern[i++])
			{
			case '\\':

				//
				//	Check Symbol
				//
				if (strchr("wsdulbptrnx", m_pattern[i])) {
					implement->m_symbol = true;
					implement->m_sym = GetSymbol(m_pattern[i]);
				} else if (strchr("WSDYLBPTRNX", m_pattern[i])) {
					implement->m_symbol = true;
					implement->m_large = true;
					implement->m_sym = GetSymbol(tolower(m_pattern[i]));
				} else {
					implement->m_ch = m_pattern[i];
				}

				i++;

				//
				//	Get XDigit
				//
				if (implement->m_sym == LRE_SYMBOL::XDigit) {
					if (byxdigit(m_pattern[i]) >= 0) {
						implement->m_xhex = true;
						implement->m_cxhex = byxdigit(m_pattern[i++]);
						if (byxdigit(m_pattern[i]) >= 0) {
							implement->m_cxhex = implement->m_cxhex << 4 | byxdigit(m_pattern[i++]);
							if (byxdigit(m_pattern[i]) >= 0) {
								implement->m_xhex = false;
								implement->m_uhex = true;
								implement->m_cuhex = implement->m_cxhex << 4 | byxdigit(m_pattern[i++]);
								if (byxdigit(m_pattern[i]) >= 0) {
									implement->m_cuhex = implement->m_cuhex << 4 | byxdigit(m_pattern[i++]);
								}
							}
						}
					}
				}

				//
				//	Check Loop Symbol
				//
				if (!LookupKeyword(m_pattern[i])) {
					lre.push_back(implement);
					implement = CreateLREUnit();
				}

				break;

			case '[':
				implement->m_collect = true;

				LREImpl *lre_imp;
				char ch;

				if (m_pattern[i] == '^') {
					implement->m_carrot = true;
					i++;
				}

				while (m_pattern[i] != ']' && m_pattern[i]) {
					lre_imp = CreateLREImplUnit();
					switch ( (ch = m_pattern[i++]) ) {
					case '\\':
						if (!isalnum(m_pattern[i])) {
							lre_imp->m_ch1 = m_pattern[i];
						} else {
							if (strchr("wsdulbptrnx", m_pattern[i])) {
								lre_imp->m_issym = true;
								lre_imp->m_sym = GetSymbol(m_pattern[i]);
							} else if (strchr("WSDYLBPTRNX", m_pattern[i])) {
								lre_imp->m_issym = true;
								lre_imp->m_large = true;
								lre_imp->m_sym = GetSymbol(tolower(m_pattern[i]));
							} else {
								lre_imp->m_isch = true;
								lre_imp->m_ch1 = m_pattern[i];
							}

							i++;
							
							if (lre_imp->m_sym == LRE_SYMBOL::XDigit) {
								if (byxdigit(m_pattern[i]) >= 0) {
									lre_imp->m_isxhex = true;
									lre_imp->m_xhex1 = byxdigit(m_pattern[i++]);
									if (byxdigit(m_pattern[i]) >= 0) {
										lre_imp->m_xhex1 = lre_imp->m_xhex1 << 4 | byxdigit(m_pattern[i++]);
										if (byxdigit(m_pattern[i]) >= 0) {
											lre_imp->m_isxhex = false;
											lre_imp->m_isuhex = true;
											lre_imp->m_word1 = lre_imp->m_xhex1 << 4 | byxdigit(m_pattern[i++]);
											if (byxdigit(m_pattern[i]) >= 0) {
												lre_imp->m_word1 = lre_imp->m_word1 << 4 | byxdigit(m_pattern[i++]);
											}
										}
									}
								}
							}

							if (m_pattern[i] == '-') {
								lre_imp->m_isscope = true;
								i++;
								if (lre_imp->m_issym) {
									if (lre_imp->m_sym == LRE_SYMBOL::XDigit) {
										if (m_pattern[i] == '\\') {
											i++;
											if (m_pattern[i] == 'x' && !lre_imp->m_large) {
												if (byxdigit(m_pattern[++i]) >= 0) {
													lre_imp->m_xhex2 = byxdigit(m_pattern[i++]);
													if (byxdigit(m_pattern[i]) >= 0) {
														lre_imp->m_xhex2 = lre_imp->m_xhex2 << 4 | byxdigit(m_pattern[i++]);
														if (byxdigit(m_pattern[i]) >= 0) {
															lre_imp->m_word2 = lre_imp->m_xhex2 << 4 | byxdigit(m_pattern[i++]);
															if (byxdigit(m_pattern[i]) >= 0) {
																lre_imp->m_word2 = lre_imp->m_word2 << 4 | byxdigit(m_pattern[i++]);
															}
														}
													}
												}
											} else if (m_pattern[i] == 'X' && lre_imp->m_large) {
												if (byxdigit(m_pattern[++i]) >= 0) {
													lre_imp->m_xhex2 = byxdigit(m_pattern[i++]);
													if (byxdigit(m_pattern[i]) >= 0) {
														lre_imp->m_xhex2 = lre_imp->m_xhex2 << 4 | byxdigit(m_pattern[i++]);
														if (byxdigit(m_pattern[i]) >= 0) {
															lre_imp->m_word2 = lre_imp->m_xhex2 << 4 | byxdigit(m_pattern[i++]);
															if (byxdigit(m_pattern[i]) >= 0) {
																lre_imp->m_word2 = lre_imp->m_word2 << 4 | byxdigit(m_pattern[i++]);
															}
														}
													}
												}
											} else PATTERN_PARSE_ERROR
										} else PATTERN_PARSE_ERROR
									} else PATTERN_PARSE_ERROR
								} else if (lre_imp->m_isch) {
									if (isalpha(m_pattern[i]))
										lre_imp->m_ch2 = m_pattern[i++];
								} else PATTERN_PARSE_ERROR
							}

						}
						break;
					default:
						if (isalpha(ch))
							lre_imp->m_isch = true, lre_imp->m_ch1 = ch;
						else
							PATTERN_PARSE_ERROR
					}
					implement->m_lre.push_back(lre_imp);
				}

				if (m_pattern[i] != ']')
					PATTERN_PARSE_ERROR
				
				if (!LookupKeyword(m_pattern[++i]))
				{
					lre.push_back(implement);
					implement = CreateLREUnit();
				}
				break;

			case '(':	// Capture group or or group.
				stack_top += 1;
				lre_stack.push(lre);
				lre = std::vector<LowRegularExpressionImpl *>();
				capture_stack.push(implement);
				implement = CreateLREUnit();
				break;

			case '|':
				if (stack_top > 0) {
					if (or_countx == 0) {
						std::vector<std::vector<LowRegularExpressionImpl *>> lre_vec;
						or_list.push(lre_vec);
					}
					or_list.top().push_back(lre);
					lre = std::vector<LowRegularExpressionImpl *>();
					or_countx++;
				}
				break;

			case ')':
				if (stack_top > 0) {
					if (or_countx > 0) {
						or_list.top().push_back(lre);
						implement = CreateLREUnit();
						or_countx = 0;
					}
					stack_top -= 1;
					std::vector<LowRegularExpressionImpl *> tmp_lre = lre_stack.top();
					LowRegularExpressionImpl *tmp_reim = capture_stack.top();
					if (is_single_key) {
						tmp_reim->m_single = true;
						tmp_reim->m_singlelist = implement;
						if (!LookupKeyword(m_pattern[i])) {
							tmp_reim->m_capture = true;
						}
					} else {
						tmp_reim->m_list = or_list.top();
						tmp_reim->m_or = true;
						or_list.pop();
					}
					tmp_lre.push_back(tmp_reim);
					lre = tmp_lre;
					implement = tmp_reim;
					lre_stack.pop();
					capture_stack.pop();
				} else 
					PATTERN_PARSE_ERROR
				
				break;
			case '*':
				implement->m_repeat = true;
				if (!LookupKeyword(m_pattern[i])) {
					lre.push_back(implement);
					implement = CreateLREUnit();
				}
				break;
			case '+':
				implement->m_repeat = true;
				implement->m_least = true;
				if (!LookupKeyword(m_pattern[i])) {
					lre.push_back(implement);
					implement = CreateLREUnit();
				}
				break;
			case '?':
				implement->m_pig = true;
				if (!LookupKeyword(m_pattern[i])) {
					lre.push_back(implement);
					implement = CreateLREUnit();
				}
				break;
			case '.':
				implement->m_any = true;
				if (!LookupKeyword(m_pattern[i])) {
					lre.push_back(implement);
					implement = CreateLREUnit();
				}
				break;

				//
				//	Normal Character
				//
			default:
				if (isalnum(m_pattern[--i])) {
					implement->m_ch = m_pattern[i];
					if (isalnum(m_pattern[i+1])) {
						do {
							implement->m_str.Append(m_pattern[i]);
							i++;
						} while (isalnum(m_pattern[i]));
						implement->m_isstr = true;
					}
				}
				else
					PATTERN_PARSE_ERROR
				if (!LookupKeyword(m_pattern[i]))
				{
					lre.push_back(implement);
					implement = CreateLREUnit();
				}
				break;
			}
		}
	}

	bool LookupKeyword(char ch)
	{
		if (ch == '*')
			return true;
		else if (ch == '+')
			return true;
		else if (ch == '?')
			return true;
		return false;
	}

	LRE_SYMBOL GetSymbol(char ch)
	{
		if (ch == 'w')
			return LRE_SYMBOL::Word;
		else if (ch == 's')
			return LRE_SYMBOL::Space;
		else if (ch == 'd')
			return LRE_SYMBOL::Digit;
		else if (ch == 'u')
			return LRE_SYMBOL::Upper;
		else if (ch == 'l')
			return LRE_SYMBOL::Lower;
		else if (ch == 'b')
			return LRE_SYMBOL::Blank;
		else if (ch == 'p')
			return LRE_SYMBOL::Punct;
		else if (ch == 't')
			return LRE_SYMBOL::Tab;
		else if (ch == 'r')
			return LRE_SYMBOL::Return;
		else if (ch == 'n')
			return LRE_SYMBOL::LineFeed;
		else if (ch == 'x')
			return LRE_SYMBOL::XDigit;
	}

	int byxdigit(char ch)
	{
		if (isdigit(ch))
			return ch - '0';
		char low = tolower(ch);
		/*if (isxdigit(ch))
			;*/
		if ('a' <= low && low <= 'f')
			return low - 'a' + 0xa;
		return -1;
	}

private:

	bool m_error;
	const char *m_str;
	const char *m_pattern;

};

}

#endif