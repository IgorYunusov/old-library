/*************************************************************************
 *
 *					  ROLLRAT SOFTWARE LIBRARY
 *						INDEPENDENT METHOD
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _IDEPENDENT_METHOD_
#define _IDEPENDENT_METHOD_

#include "string.h"
#include "tree.h"
#include "urray.h"
#include "serve_method.h"
#include "priority.h"
#include <hash_map>
#include <vector>
#include <stack>

template<typename _Ty = char> class
	perpect_rvalue
	{ // Right Value Parsing Class , first , IDEPENDENT LIBRARY
	tree<String<_Ty>> _tree;
	const _Ty* ptr;
	String<_Ty> _tmp_str;
	std::stack<String<_Ty>> _stack;
public:

	tree<String<_Ty>> start(const _Ty *_S)
		{
		ptr = _S ;
		var(ptr);
		return _tree;
		}

private:

	bool is_char()
		{
		if (('0' <= *ptr && *ptr <= '9') ||
			('a' <= *ptr && *ptr <= 'z') || 
			('A' <= *ptr && *ptr <= 'Z') || *ptr == '\"' || *ptr == '\'' || *ptr == '\\')
			return true;
		return false;
		}

	const void* skipws(const void *)
		{
		if (!*ptr)
			;
		else if (isspace(*ptr))
			return skipws(ptr++);
		return ptr;
		}

	const void* factor(const void *)
		{
		skipws(ptr);
		if(*ptr == '(')
			{
			if (_tree.is_left() && !_tree.is_right())
				_tree.push_right(), _tree.into_right();
			else if (!_tree.is_left())
				_tree.push_left(), _tree.into_left();
			var(++ptr);
			if (*ptr == ')')
				ptr++;
			else
				; // error
			_tree.escape();
			}
		else if(is_char())
			{
			variable(ptr);
			factor(ptr);
			}
		return ptr;
		}

	const void* exp(const void *)
		{
		factor(ptr);
		skipws(ptr);
		if(*ptr == '*' || *ptr == '/')
			{
			if (_tree.is_data())
				{
				_tree.into_right();
				_tree.push_left();
				_tree.dswap_left();
				}
			_tmp_str.Append(*ptr++);
			*_tree = _tmp_str;
			_tmp_str.Clear();
			exp(ptr);
			}
		return ptr;
		}

	const void* var(const void *)
		{
		exp(ptr);
		skipws(ptr);
		if(*ptr == '+' || *ptr == '-')
			{
			if (_tree.is_data())
				{
				_tree.into_right();
				_tree.push_left();
				_tree.dswap_left();
				}
			_tmp_str.Append(*ptr++);
			*_tree = _tmp_str;
			_tmp_str.Clear();
			var(ptr);
			}
		return ptr;
		}

	const void* variable(const void *)
		{
		if(is_char())
			{
			for (; is_char();)
				_tmp_str.Append(*ptr++);
			if (_tree.is_left() && !_tree.is_right())
				_tree.push_right(_tmp_str.Trim());
			else if(!_tree.is_right())
				_tree.push_left(_tmp_str.Trim());
			else
				{
				_tree.into_right();
				_tree.push_right(_tmp_str.Trim());
				}
			_tmp_str.Clear();
			}
		return ptr;
		}

	};
	
template<class priority_type> class linked_rvalue
	{
	priority_type pf;
	tree<std::string> ps_tree;
	std::string temp;
	bool prev_pa=false;
	const char* ptr;

	typedef linked_rvalue _Myrv;
public:

	tree<std::string> start(const char *_S)
		{
		ptr = _S ;
		var(ptr);
		return ps_tree;
		}

protected:
	bool is_char()
		{
		if (('0' <= *ptr && *ptr <= '9') || *ptr == '.' || ('a' <= *ptr && *ptr <= 'z') || 
			('A' <= *ptr && *ptr <= 'Z') || *ptr == '\"' || *ptr == '\'' || 
			*ptr == '\\' || *ptr == '_' || *ptr == '@')
			return true;
		return false;
		}
	bool is_operator()
		{ // operator
		if (!*ptr)
			return false;
		return strchr("+-*/&^|%<>!~", *ptr);
		}

	const void* skipws(const void *)
		{
		if (!*ptr)
			;
		else if (isspace(*ptr))
			return skipws(ptr++);
		return ptr;
		}

	const void* var(const void *)
		{
		factor(ptr);
		skipws(ptr);
		if(is_operator())
			{
			std::string optr;
			for (; is_operator(); ptr++)
				optr.push_back(*ptr);
			skipws(ptr);
			if(!ps_tree.is_data())
				*ps_tree = optr;
			else
				if (!pf(*ps_tree, optr) && !prev_pa) {   
					ps_tree.into_right();
					ps_tree.push_left(optr);
					ps_tree.dswap_left();
				} else {
					ps_tree.make_head_left(optr);
					ps_tree.escape();
				}
			prev_pa = false;
			var(ptr);
			}
		return ptr;
		}

	const void* factor(const void *)
		{
		skipws(ptr);
		if(*ptr == '(')
			{
			ptr++;
			_Myrv rvtemp;
			if (ps_tree.is_left() && !ps_tree.is_right())
				ps_tree.attach_right_tree(rvtemp.start(ptr).travel());
			else if (!ps_tree.is_left())
				ps_tree.attach_left_tree(rvtemp.start(ptr).travel());
			ptr = rvtemp.ptr;
			if (*ptr == ')') 
				ptr++;
			else
				; // error
			ps_tree.escape();
			prev_pa = true;
			}
		else if(*ptr == ')')
			;
		else if(is_char()) {
			variable(ptr);
			factor(ptr);
			}
		return ptr;
		}

	const void* variable(const void *)
		{
		skipws(ptr);
		if(is_char())
			{
			for (; is_char();)
				temp.push_back(*ptr++);
			if (!ps_tree.is_left())
				ps_tree.push_left(temp);
			else if (!ps_tree.is_right())
				ps_tree.push_right(temp);
			temp.clear();
			}
		return ptr;
		}
	};

#endif