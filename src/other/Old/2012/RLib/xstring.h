/*************************************************
 *												 *
 *			RollRat Software Library			 *
 *												 *
 *	Copyright (c) rollrat. All rights reserved.  *
 *_______________________________________________*/

#pragma once

#ifndef _string_
#define _string_

#include "vector.h"
#include "xtok.h"

 #pragma warning(disable: 4100 4345)

#if defined(_EX_SUCCESS)
_X_LIB_BEGIN
	
template<class _Ty0> inline
	int strlen(_Ty0 *that)
	{ // strlen
	for( int i = 0; ; )
		if(!that[++i])
			return i;
	}

template<class _Ty0> inline
	int f_len(_Ty0 *that)
	{ // f len
	_Ty0 *pp = that;
	while(*pp++);
	return pp - that - 1;
	}

template<class _String_Element = char>
	class string
	{ // string class

	vector<_String_Element> str;
	bool reverses;

	public:

		string()
			: reverses(false)
			{ }

		string(_String_Element* _valuable_char)
			: reverses(false)
			{ // entry
			char_put(_valuable_char);
			}

		string(const _String_Element* _const_char)
			: reverses(false)
			{ // entry
			char_put(const_cast<_String_Element*> (_const_char));
			}

		inline _String_Element& operator[](int pos)
			{ // operator[]
			if(!reverses)
				return str[pos];
			else
				return str(pos);
			}

		inline void reverse()
			{ // str reverse
			reverses = true;
			}

		inline int lenth()
			{ // length
			return str.size();
			}

		_String_Element* operator*()
			{ // operator *
			int len = lenth();
			_String_Element *ret = new _String_Element[len];
			if(!reverses)
				for(int n = 0; n < len; n++)
					ret[n] = str[n]->_DATA;
			else
				for(int n = 0; n < len; n++)
					ret[n] = str(n)->_DATA;
			ret[len] = 0;
			return ret;
			}

		inline void operator+=(_String_Element* _valuable_char)
			{ // operator +=
			char_put(_valuable_char);
			}

		inline void operator+=(const _String_Element* _const_char)
			{ // operator +=
			char_put(const_cast<_String_Element*> (_const_char));
			}

		inline void operator+=(int _valuable_int)
			{ // operator +=
			char_put(itoas<char> (_valuable_int));
			}

		inline vector<_String_Element> &ch_n()
			{ // vector return
			return str;
			}

		string<_String_Element> &operator<(_String_Element *get)
			{ // operator +=
			char_put(get);
			return *this;
			}

		string<_String_Element> &operator<(const _String_Element *get)
			{ // operator +=
			char_put(const_cast<_String_Element*> (get));
			return *this;
			}

		string<_String_Element> &operator<(string<_String_Element> &get)
			{ // operator +=
			char_put(*get);
			return *this;
			}

		string<_String_Element> &operator>(_String_Element *get)
			{ // operator +=
			char_put_r(get);
			return *this;
			}

		string<_String_Element> &operator>(const _String_Element *get)
			{ // operator +=
			char_put_r(const_cast<_String_Element*> (get));
			return *this;
			}

		string<_String_Element> &operator>(string<_String_Element> &get)
			{ // operator +=
			char_put_r(*get);
			return *this;
			}

		void replace_test(string<_String_Element> &retchars, 
				string<_String_Element> &gotchars)
			{ // replace test
			_vector_replace2(str, retchars.ch_n(), gotchars.ch_n());
			}

		void replace(string<_String_Element> &retchars, 
				string<_String_Element> &gotchars)
			{ // replace
			_VECTOR_OPERATION 
				_VECTOR_NODES<_String_Element> 
					*start = str.front();
			_VECTOR_OPERATION 
				_VECTOR_NODES<_String_Element> 
					*last = str.front();
			_VECTOR_OPERATION 
				_VECTOR_NODES<_String_Element> 
					*buf = gotchars.ch_n().front();
			_VECTOR_OPERATION 
				_VECTOR_NODES<_String_Element> 
					*publicq = 0;
			int i = replace_find(retchars), 
				f = i + gotchars.lenth();
			for(int d = 0; d < i; d++)
				start = start->_NEXT;
			for(int d = 0; d <= f; d++)
				last = last->_NEXT;
			buf->_PREV = start;
			start = gotchars.ch_n().front();
			buf->_NEXT = last;
			publicq = last;
			last = gotchars.ch_n().back();
			publicq->_NEXT = last;
			}

	private:

		inline void char_put(_String_Element *_char)
			{ // char put
			int f = strlen(_char);
			if(!reverses)
				for(int i = 0; i < f; i++)
					str.push_back(_char[i]);
			else
				for(int i = 0; i < f; i++)
					str.push_front(_char[i]);
			}

		inline void char_put_r(_String_Element *_char)
			{ // char put
			int f = strlen(_char);
			if(!reverses)
				for(int i = 0; i < f; i++)
					str.push_front(_char[i]);
			else
				for(int i = 0; i < f; i++)
					str.push_back(_char[i]);
			}

		inline int replace_find(string<_String_Element> &retchars)
			{ // replace find equal
			_VECTOR_OPERATION 
				_VECTOR_NODES<_String_Element> *start = str.front();
			_VECTOR_OPERATION 
				_VECTOR_NODES<_String_Element> *s_start = retchars.ch_n().front();
			int n = retchars.lenth(), f = lenth();
			for(int i = 0; i <= f; i++, start = start->_NEXT)
				if(start->_DATA == s_start->_DATA)
					for(int fd = i; fd <= i+n; fd++, start = start->_NEXT,
							s_start = s_start->_NEXT)
						if(fd == i + n)
							return i;
						else 
							if(start->_DATA != s_start->_DATA)
								break;
			}
	
	};

_X_LIB_END
#endif

#endif
/*
 *	The rollrat x_library
 *  Updated : 2013-05
 *	http://blog.naver.com/rollrat
 *  Copyright (c) 2009-2013 by rollrat. All right reserved.
 *  For more information, refer to the documentation on the license.
V0.1:0012****/

/*
 *	This item, is available free of charge. However, if you change 
 *	yourself, you can bring fatal consequences. This project is 
 *	based on the ethical issues of the information, and began to 
 *	improve the openness of the program. You can use anyone, but 
 *	please observe the clear copyright notice. When you beat this, 
 *	you can go into the legal action.
V0.1_x_Library_btype*/