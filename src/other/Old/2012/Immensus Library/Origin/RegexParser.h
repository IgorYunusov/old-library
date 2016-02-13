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

class parser_x{
public:
	typedef struct _gremoga_ {
		unsigned int position;	// 매치되는 처음부분
		unsigned int length;	// 매치되는 문장의 길이
		int hash_code;			// 부여되는 해쉬코드(의미 없음)
	}	gremon, *ptr_gremon;
private:
	const char *ptr;
	const char *ptr_last;
	const char *ptr_origin;
	const char *pattern;
	const char *pattern_origin;
	bool err;
	int i;
	int sizeof_ptr;
	ptr_gremon gremons;
	int gremonsx;
	gremon v_tx;
	#pragma region REGEXP_DO_NOT_TOUCHING_AREA
public:

	parser_x() : gremons(0), gremonsx(0) {}

	inline int make_hash(int count, int mount){return mount << 16 | count;}

	#define reg_parse_error			0x00
	#define reg_parse_default		0x01
	#define reg_parse_otomata		0x02
	#define reg_parse_terminal		0x03

	inline int regexRegParseGetTypeOf(const char x, bool lrs)
	{
		if(((('0' <= x) && (x <= '9')) || (('a' <= x) 
			&& (x <= 'z')) || (('A' <= x) && (x <= 'Z'))) || r_util::strstr(x, " _") || r_util::isspace(x))
			if(lrs) 
				return reg_parse_otomata; 
			else 
				return reg_parse_default;
		if(r_util::strstr(x, "[]$\".<>:?\\!@#%^&*()-+=|{}~"))
			return reg_parse_terminal; 
		return 0;
	}

	void regexSetPattern(const char *pate)
	{
		pattern = pate;
		pattern_origin = pate;
		gb_token = *pate;
	}

	ptr_gremon regexMatch(const char *xt)
	{
		i = 0;
		sizeof_ptr = r_util::strlen(xt);
		v_tx.length = 0;
		v_tx.position = 0;
		err = false;
		ptr = xt;
		ptr_last = 0;

		while(true)
		{
			exp();
			if(!i)
				break;
			else
			{
				ptr_gremon xt = new gremon[++gremonsx];
				xt[gremonsx] = v_tx;
				for(int fxt = 0; fxt < (gremonsx - 1); fxt++)
					xt[fxt] = gremons[fxt];
				gremons = xt;
			}
			regexSetPattern(pattern_origin);
			v_tx.length = 0;
			v_tx.position = 0;
		}

		return gremons;
	}
	
private:

	void match(const char e)
	{
		if(gb_token == e)
			gb_token = getnextchar();
		else
			error();
	}

	void error()
	{
		if(ptr_last)
			ptr = ptr_last;
		ptr_last = 0;
		v_tx.position = 0;
		err = true;
		gb_token = *pattern_origin;
		pattern = pattern_origin + 1;
	}

	const char getnextchar()
	{
		return *(pattern++);
	}

	#pragma endregion

private:
	char gb_token;

	void exp()
	{
		term();
		while(regexRegParseGetTypeOf(gb_token, false))
		{
			if(sizeof_ptr == i)
				return;
			////////////////////////////////
			err = false;
			factor();
			////////////////////////////////
			ptr++;
			i++;
		}
		if(v_tx.position)
			v_tx.length = i;
		else
			i = 0;
	}

	void factor()
	{
		if(regexRegParseGetTypeOf(gb_token, false) == reg_parse_default)
		{
			match(*ptr);
			if(!err && !ptr_last)
			{
				ptr_last = ptr + 1;
				v_tx.position = i;
			}
		}
	}

	void term()
	{
		factor();
	}
	

};

#endif