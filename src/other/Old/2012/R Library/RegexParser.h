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

#if !defined(_REGEX_PARSER_)
#define _REGEX_PARSER_

#include "RegexUtil.h"

#define WUV		char

#define _THROW	// 진행불가

namespace r_regex {
#define _regex	r_regex::

// Regular And STL regex lib metacharacters list - First Check List \
        troublesome...
typedef enum {
    _Meta_lpar = '(',
    _Meta_rpar = ')',
    _Meta_dlr = '$',
    _Meta_caret = '^',
    _Meta_dot = '.',
    _Meta_star = '*',
    _Meta_plus = '+',
    _Meta_query = '?',
    _Meta_lsq = '[',
    _Meta_rsq = ']',
    _Meta_bar = '|',
    _Meta_esc = '\\',
    _Meta_dash = '-',
    _Meta_lbr = '{',
    _Meta_rbr = '}',
    _Meta_comma = ',',
    _Meta_colon = ':',
    _Meta_equal = '=',
    _Meta_exc = '!',
    _Meta_eos = -1,
    _Meta_num = 1,
    _Meta_nl = '\n',
    _Meta_cr = '\r',
    _Meta_bsp = '\b',
    _Meta_chr = 0,
    _Meta_chr_b = -8,
    _Sign_None = -2,
}    _regex_sign_check;
// CHECK : http://en.wikipedia.org/wiki/Regular_expression

#define ROLLRAT_REGEX_PARSER_VERSION	"0.1 A:1"

class parser_x{
public:
	typedef struct _gremoga_ {
		unsigned int position;	// 매치되는 처음부분
		unsigned int length;	// 매치되는 문장의 길이
	}	gremon, *ptr_gremon;
private:
	const WUV *ptr;
	const WUV *pattern;

	const WUV *ptr_precise;
	const WUV *pattern_origin;
	ptr_gremon xty;
	gremon xt_gremon;
	int gremon_size;
public:

	#define reg_parse_error			0x00
	#define reg_parse_default		0x01
	#define reg_parse_terminal		0x03

	inline int regexRegParseGetTypeOf(const WUV x)
	{
		if(((('0' <= x) && (x <= '9')) || (('a' <= x) 
			&& (x <= 'z')) || (('A' <= x) && (x <= 'Z'))) || x == '_' || r_util::isspace(x))
				return reg_parse_default;
		if(r_util::strchr(x, "[]$\".<>:?\\!@#%^&*()-+=|{}~"))
			return reg_parse_terminal; 
		return reg_parse_error;
	}

	void regexSetPattern(const WUV *pate)
	{
		pattern = pate;
		gb_token = *pate;
	}
	
	ptr_gremon regexMatch(const WUV *xt)
	{
		gremon_size = 0;
		ptr = xt;
		pattern_origin = pattern;
		while(*ptr)
		{
			error_true = false;
			already_start = false;
			i_count = 0;
			i_zero_count = 0;
			it = 0;
			gb_pre_token = *(pattern_origin + 1);
			gb_token = *pattern_origin;
			////////////////////////////////
			in_the_spar = false;
			in_the_bpar = false;
			////////////////////////////////
			exp();
			if(*ptr && xt_gremon.length)
			{
				ptr_gremon xtx = new gremon[++gremon_size];
				for(int i = 0; i < (gremon_size - 1); i++)
					xtx[i] = xty[i];
				xty = xtx;
				xty[gremon_size] = xt_gremon;
			}
		}
		return xty;
	}
	
private:

	bool error_true;	// ture = error!
	bool already_start;
	char gb_token;

	char gb_pre_token;

	int i_count;
	int i_zero_count;

	bool in_the_spar;	// in the ()
	bool in_the_bpar;	// in the []
	
	int it;

	void match(const WUV e)
	{
		if(gb_token == e)
			gb_token = getnextchar();
		else
			error();
	}

	void error()
	{
		error_true = !error_true;
		pattern = pattern_origin;
		gb_token = *pattern_origin;
	}

	const WUV getnextchar()
	{
		gb_pre_token = *(pattern + 2);
		return *(++pattern);
	}
	

	///////////////////////////////////////////////
	///////////////////////////////////////////////
	///////////////////////////////////////////////


	void exp()
	{
		while(gb_token != '\0' && *ptr)
		{
			factor();
			////////////////////////////////
			ptr++;
			i_count++;
		}
		if(xt_gremon.position)
			xt_gremon.length = i_count - 1;
	}

	void factor()
	{
		switch(regexRegParseGetTypeOf(gb_token))
			{
		case reg_parse_default:	// wnc | '\0'
			if(pre_token())
				return;
			////////////////////////////////
			match(*ptr);
			////////////////////////////////
			if(error_true)
				if(!already_start)
					error_true ^= error_true;
				else
				{
					error_true ^= error_true;
					i_count = i_zero_count;
					ptr = ptr_precise;
					already_start ^= already_start;
				}
			else
				if(!already_start)
				{
					already_start = true;
					i_zero_count = i_count;
					xt_gremon.position = i_count;
					ptr_precise = ptr;
				}
			break;
		case reg_parse_terminal:
			switch(gb_token)
				{
			case _Meta_star:
			case _Meta_plus:
			case _Meta_query:
				poly();
				break;
				}
			////////////////////////////////
			match(gb_token);
			break;
		default:
			break;
			}
	}

	bool pre_token()
	{
		switch(gb_pre_token)
			{
		case _Meta_star:
			match(gb_token);
			poly();
			match(gb_token);
			ptr--;
			i_count--;
			return true;
		case _Meta_query:
			match(gb_token);
			poly();
			match(gb_token);
			ptr--;
			i_count--;
			it = 0;
			return true;
		case _Meta_bar:
			if(*ptr == gb_token || *ptr == *(pattern + 2))
			{
				match(gb_token);
				i_count++;
				match(gb_token);
				i_count++;
				match(gb_token);
			}
			else{
				error();
				return false;}
			return true;
			}
		return false;
	}

	void poly()
	{
		if(!in_the_spar)	// 위배 되지 않는한
			switch(gb_token)
				{
			case _Meta_star:
				if(*ptr != *(pattern - 1))
					return;
				////////////////////////////////
				i_count++;
				ptr++;
				poly();
				break;
			case _Meta_plus:
				if(*ptr != *(pattern - 1))
				{
					ptr--;
					i_count--;
					return;
				}
				////////////////////////////////
				i_count++;
				ptr++;
				poly();
				break;
			case _Meta_query:
				if(*ptr != *(pattern - 1) || it++)
					return;
				////////////////////////////////
				it++;
				////////////////////////////////
				i_count++;
				ptr++;
				poly();
				break;
			default:
				_THROW;
				}
	}
	
	///////////////////////////////////////////////

};

}

#endif