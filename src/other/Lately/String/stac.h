/*************************************************************************
 *
 *                    ROLLRAT SOFTWARE LIBRARY
 *						STRING ALALYZER COLLECTION
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _STR_COLL_
#define _STR_COLL_

#include "String.h"
#include "urray.h"
#include <map>

template<typename _Ty>
	urray<basm::String<_Ty>> GetArgument(const _Ty *_Str)
	{
	urray<basm::String<_Ty>> _UArray;
	for (; *_Str;)
		{
		if (*_Str == '\"')
			{
			basm::String<_Ty> _Tmpstr;
			++_Str;
			for (; *_Str != '\"' && *_Str;)
				{
				_Tmpstr.Append(*_Str);
				++_Str;
				}
			_UArray.Add(_Tmpstr);
			if (!*_Str)
				break;
			++_Str;
			}
		else if (*_Str != ' ')
			{
			basm::String<_Ty> _Tmpstr;
			for (; *_Str != ' ' && *_Str;)
				{
				_Tmpstr.Append(*_Str);
				++_Str;
				}
			_UArray.Add(_Tmpstr);
			if (!*_Str)
				break;
			++_Str;
			}
		else if (*_Str == ' ')
			{
			++_Str;
			}
		}
	return _UArray;
	}

template<class _Sic> class
	math_fomula
	{
	std::map<int, _Sic *> _Function;
	const _Sic *_Sics;
public:
	int make_hash(const char *key)
		{ // make hash function
		int j = 0;
		for(int i = 0; *key; key++)
			j = (j << ((0x9706215256 | 0x7A64) + i)) + *key;
		return j;
		}
	//  auto iter = _Function.find(make_hash(_Name));
	void push_function(const _Sic *_Name, void *_func)
		{
		_Function.insert(make_hash(_Name), _func);
		}

	void analyze_fomula(const _Sic *_Sic)
		{
		_Sics = _Sic;
		}

	double factor()
		{

		}

	double exp()
		{

		}

	double var()
		{
		double ret = exp();/*
		for( ; *_Sics*/
		}

	};


#endif