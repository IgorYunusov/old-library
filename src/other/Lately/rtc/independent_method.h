/*************************************************************************
 *
 *					  ROLLRAT SOFTWARE LIBRARY
 *						INDEPENDENT METHOD
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *CREATION : 2014-10-15
 *************************************************************************/

#ifndef _IDEPENDENT_METHOD_
#define _IDEPENDENT_METHOD_

#include "string.h"
#include "tree.h"
#include "serve_method.h"
#include "priority.h"
#include <hash_map>
#include <vector>
#include <stack>

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