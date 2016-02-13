/****************************************************************
 *																*
 *																*
 *			ROLLRAT AUTO PERSONA VERBOTER LIBROFEX				*
 *																*
 *																*
 *		COPYRIGHT (c) rollrat. 2014. ALL RIGHTS RESERVED.		*
 *																*
 *																*
 ****************************************************************/

#if !defined(_REGEX_PREPARSER_)
#define _REGEX_PREPARSER_

#include "pure_macro_assembler.h"

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

class pre_parser{
	pma pma;
public:
	sarrmon chocolat;

	char *unique_string_yacc_undeclined(const char *unique_str)
	{
		
		return make_purescript(chocolat);
	}

	char *make_purescript(sarrmon rocket)
	{

	}

};

}

#endif