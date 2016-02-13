/*************************************************************************
 *
 *					  ROLLRAT SOFTWARE LIBRARY
 *						REGULAR TRANSFORM
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _REGULAR_TRANSFORM_
#define _REGULAR_TRANSFORM_

#include "string.h"
#include "tree.h"
#include "urray.h"
#include "serve_method.h"

template<typename _Ty = char> class
	regular_transform0
	{
	const _Ty* ptr;
	String<_Ty> _tmp_value;
	String<_Ty> return_string;
public:

	String<_Ty> transform0(const _Ty *target)
		{
		ptr = target;
		order1();
		if (!_tmp_value.Empty())
			return_string.Append(_tmp_value);
		return return_string;
		}

private:

	bool is_char()
		{
		if (('0' <= *ptr && *ptr <= '9') ||
			('a' <= *ptr && *ptr <= 'z') || 
			('A' <= *ptr && *ptr <= 'Z') || *ptr == '\"' || *ptr == '\'' || *ptr == '\\' || *ptr == '$')
			return true;
		return false;
		}

	void skipws()
		{
		if (isspace(*ptr))
			{
			ptr++;
			return skipws();
			}
		}

	void factor()
		{
		skipws();
		if(*ptr == '(')
			{
			ptr++;
			regular_transform0<_Ty> _tmp;
			_tmp_value.Append(_tmp.transform0(ptr));
			ptr = _tmp.ptr;
			if (*ptr == ')')
				ptr++;
			}
		else if(is_char())
			{
			variable();
			}
		skipws();
		}

	void variable()
		{
		for (; is_char();)
			_tmp_value.Append(*ptr++);
		}

	void order1()
		{
		order2();
		if(*ptr == '+' || *ptr == '-')
			{
			bool t = true;
			if (!_tmp_value.Empty()){
				return_string.Append("(");
				return_string.Append(_tmp_value);
				_tmp_value.Clear();
				}
			else{
				return_string.Insert(0, "(");
				if (o1)
					return_string.Append(")");
				o1 = false;
				t = false;
			}
			return_string.Append(*ptr++);
			order1();
			return_string.Append(_tmp_value);
			_tmp_value.Clear();
			if(t)
				return_string.Append(")");
			}
		}
	
	bool o1 = false;

	void order2()
		{
		order3();
		if (*ptr == '^' || *ptr == '&' || *ptr == '|')
			{
			bool t = true;
			if (!_tmp_value.Empty()){
				return_string.Append("(");
				return_string.Append(_tmp_value);
				_tmp_value.Clear();
				}
			else{
				return_string.Insert(0, "(");
				if (o2)
					return_string.Append(")");
				o2 = false;
				t = false;
			}
			return_string.Append(*ptr++);
			order2();
			return_string.Append(_tmp_value);
			_tmp_value.Clear();
			if(t)
			return_string.Append(")");
			o1 = true;
			}
		}
	
	bool o2 = false;

	void order3()
		{
		factor();
		if(*ptr == '*' || *ptr == '/')
			{
			if (!_tmp_value.Empty()){
				return_string.Append("(");
				return_string.Append(_tmp_value);
				_tmp_value.Clear();
				}
			else
				return_string.Insert(0, "(");
			return_string.Append(*ptr++);
			order3();
			return_string.Append(_tmp_value);
			_tmp_value.Clear();
			return_string.Append(")");
			o2 = true;
			}
		}

	};

template<typename _Ch> String<_Ch>
	make_regular(const _Ch *_str)
	{
	regular_transform0<> rt;
	String<> t = rt.transform0(_str);
	regular_transform0<> rtn;
	t = rtn.transform0(t.c_str());

	if(*t.c_str() == '(' && t.EndsWith(")"))
		{
		t.c_str()[t.Length() - 1] = 0;
		t.c_str()++;
		}

	return t;
	}

#endif