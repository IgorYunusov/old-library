/*=================================================

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

=================================================*/

#pragma once
#ifndef _x_lib_str
#define _x_lib_str

#include "vector.h"

template<class _Ty0 = char>
	class str_n
	{ // string class

	vector<_Ty0> str;
	unsigned int point;

public:

	str_n()
		: point(0)
		{ }

	str_n(_Ty0 *_valuable_char)
		: point(0)
		{ // entry
		char_put(_valuable_char);
		}

	str_n(const _Ty0 *_const_char)
		: point(0)
		{ // entry
		char_put(const_cast<_Ty0 *> (_const_char));
		}

	inline _Ty0& operator[](int pos)
		{ // operator[]
		return str[pos];
		}

	inline _Ty0& operator()(int pos)
		{ // operator[]
		return str[pos];
		}

	inline int length()
		{ // length
		return str.size();
		}

	void operator++()
		{ // pre ++
		point++;
		}

	void operator--()
		{ // pre --
		point--;
		}

	_Ty0& operator*()
		{ // operator*
		return str[point];
		}

	void push(_Ty0 ch)
		{
		str.push_back(ch);
		}

#if defined(_STRESS_COM)

	inline vector<_Ty0> &ch_n()
		{ // vector return
		return str;
		}

#endif

#if !defined(_COMPARED_EXCEPTED) \
	&& !defined(_CONCEPTION)

	str_n<_Ty0> &operator<<(_Ty0 *get)
		{ // operator +=
		char_put(get);
		return *this;
		}

	str_n<_Ty0> &operator<<(const _Ty0 *get)
		{ // operator +=
		char_put(const_cast<_Ty0*> (get));
		return *this;
		}

	str_n<_Ty0> &operator<<(str_n<_Ty0> &get)
		{ // operator +=
		char_put(*get);
		return *this;
		}

	str_n<_Ty0> &operator<<(_Ty0 &get)
		{ // operator +=
		str.push_back(get);
		return *this;
		}

	str_n<_Ty0> &operator>>(_Ty0 *get)
		{ // operator +=
		char_put_r(get);
		return *this;
		}

	str_n<_Ty0> &operator>>(const _Ty0 *get)
		{ // operator +=
		char_put_r(const_cast<_Ty0*> (get));
		return *this;
		}

	str_n<_Ty0> &operator>>(str_n<_Ty0> &get)
		{ // operator +=
		char_put_r(*get);
		return *this;
		}

	str_n<_Ty0> &operator>>(_Ty0 &get)
		{ // operator +=
		str.push_front(get);
		return *this;
		}

#endif

private:

	inline int strlen(_Ty0 *that)
		{ // strlen
		for( int i = 0; ; )
			if(!that[++i])
				return i;
		}

	inline void char_put(_Ty0 *_char)
		{ // char put
		int f = strlen(_char);
		for(int i = 0; i < f; i++)
			str.push_back(_char[i]);
		}

	inline void char_put_r(_Ty0 *_char)
		{ // char put
		int f = strlen(_char);
		for(int i = 0; i < f; i++)
			str.push_front(_char[i]);
		}

	};

#endif
/*
 *	The rollrat x_library
 *  Updated : 2013-04
 *	http://blog.naver.com/rollrat
 *  Copyright (c) 2009-2013 by rollrat. All right reserved.
 *  For more information, refer to the documentation on the license.
V0.1:0012****/