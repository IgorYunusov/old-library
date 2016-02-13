/*************************************************************************
 *
 *					  ROLLRAT SOFTWARE LIBRARY
 *						MAS METHOD
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _MAS_METHOD_
#define _MAS_METHOD_

#include "string.h"
#include "tree.h"
#include "urray.h"
#include "serve_method.h"
#include <hash_map>
#include <vector>
#include <stack>

template<typename _Ty = char> class
	condition1
	{ // purely condition string to , second , MAS METHOD LIBRARY
	tree<String<_Ty>> _tree;
	const _Ty* ptr;
	String<_Ty> _tmp_str;
public:
	tree<String<_Ty>> start(const _Ty *_S)
		{
		ptr = _S ;
		var(ptr);
		return _tree;
		}

	String<> pnt_assembly(tree<String<_Ty>> tree_)
		{ // rollrat compiler intermeiate code transration
		_tree = tree_;
		String<> _xtestt;
		String<> _tmp, _tmp1;
		urray<String<>> _ret;
		preorder_travel(
			[&](String<> str) 
		{ 
			if (str == "&&")
				_xtestt.Append("and\n");
			else if(str == "||")
				_xtestt.Append("or\n");
			else if(str == "<")
				_tmp1.Append("jg");
			else if(str == ">")
				_tmp1.Append("jl");
			else if(str == "<=")
				_tmp1.Append("jge");
			else if(str == ">=")
				_tmp1.Append("jle");
			else if(str == "==")
				_tmp1.Append("je");
			else if(str == "!=")
				_tmp1.Append("jne");
			else
				{
				if(_tmp.Empty())
					{
					_tmp.Append(str);
					_tmp.Append(", ");
					}
				else
					{
					_tmp.Append(str);
					if (!_tmp.Empty())
						{
						_xtestt.Append(_tmp1);
						_xtestt.Append(" ");
						_xtestt.Append(_tmp);
						_ret.Add(_xtestt);
						_xtestt.Clear();
						}
					else
						{
						_xtestt.Append(_tmp1);
						_ret.Add(_xtestt);
						_xtestt.Clear();
						}
					_tmp1.Clear();
					_tmp.Clear();
					}
				return;
				}
		}, 
			_tree.travel());
		for (int i = 0; i < _ret.size(); i++)
		{
			_xtestt.Append(_ret[i]);
			_xtestt.Append('\n');
		}
		// ndfa search
		return _xtestt;
		}

private:

	bool is_not()
		{
		if ((('0' <= *ptr && *ptr <= '9') ||
			('a' <= *ptr && *ptr <= 'z') ||
			('A' <= *ptr && *ptr <= 'Z') || *ptr == ' ' || *ptr == '_' || *ptr == 0))
			return false;
		return true;
		}

	bool is_char()
		{
		if (('0' <= *ptr && *ptr <= '9') ||
			('a' <= *ptr && *ptr <= 'z') || 
			('A' <= *ptr && *ptr <= 'Z') || *ptr == '\"' || *ptr == '\'' || *ptr == '\\')
			return true;
		return false;
		}

	const void* exp(const void *)
		{
		skipws(ptr);
		vari(ptr);
		if(*ptr == '(')
			{
			if (_tree.is_left() && !_tree.is_right())
				_tree.push_right(), _tree.into_right();
			else if(!_tree.is_left())
				_tree.push_left(), _tree.into_left();
			var(ptr++);
			if (*ptr == ')')
				ptr++;
			_tree.escape();
			}
		skipws(ptr);
		return ptr;
		}

	const void* skipws(const void *)
		{
		if (isspace(*ptr))
			return skipws(ptr++);
		return ptr;
		}

	const void* var(const void *)
		{
		exp(ptr);
		symbol(ptr);
		exp(ptr);
		return ptr;
		}

	const void* vari(const void *)
		{
		if(is_char())
			{
			for (; is_char();)
				_tmp_str.Append(*ptr++);
			if (_tree.is_left())
				_tree.push_right(_tmp_str.Trim());
			else
				_tree.push_left(_tmp_str.Trim());
			_tmp_str.Clear();
			}
		return ptr;
		}

	const void* symbol(const void *)
		{
		if(is_not())
			{
			for (; is_not();)
				_tmp_str.Append(*ptr++);
			*_tree = _tmp_str;
			_tmp_str.Clear();
			}
		return ptr;
		}

	};

template<typename _Ty = char> class
	rvalue
	{ // Right Value Parsing Class , first , MAS METHOD LIBRARY
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

	String<> pnt_assembly(tree<String<_Ty>> tree_)
		{ // rollrat compiler intermeiate code transration
		_tree = tree_;
		String<> _xtestt;
		String<> _tmp, _tmp1;
		urray<String<>> _ret;
		postorder_travel(
			[&](String<> str) 
		{ 
			if (str == "+")
				_tmp.Append("add");
			else if (str == "-")
				_tmp.Append("sub");
			else if (str == "*")
				_tmp.Append("mul");
			else if (str == "/")
				_tmp.Append("div");
			else
				{
				_stack.push(str);
				return;
				}
			if(!_stack.empty())
				{
				_tmp.Append(" ");
				_tmp.Append(_stack.top().c_str());
				_stack.pop();
				}
			if(!_stack.empty())
				{
				_tmp.Append(" ");
				_tmp.Append(_stack.top().c_str());
				_stack.pop();
				}
			_ret.Add(_tmp);
			_tmp.Clear();
		}, 
			_tree.travel(),
			_tree.travel());
		for (int i = 0; i < _ret.size(); i++)
		{
			_xtestt.Append(_ret[i]);
			_xtestt.Append('\n');
		}
		// ndfa search
		return _xtestt;
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
		if (isspace(*ptr))
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
			if (_tree.is_left())
				_tree.push_right(_tmp_str.Trim());
			else if(!_tree.is_right())
				_tree.push_left(_tmp_str.Trim());
			else
				{
				_tree.into_left();
				_tree.push_left(_tmp_str.Trim());
				}
			_tmp_str.Clear();
			}
		return ptr;
		}

	};


#endif