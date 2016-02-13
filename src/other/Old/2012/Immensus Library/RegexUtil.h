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

#if !defined(_REGEX_UTIL_)
#define _REGEX_UTIL_

namespace r_util{

	template<class _undefined_variable> _undefined_variable *&
		CreateClassMethod(int x = 0)
		{
		_undefined_variable *uv = new _undefined_variable[x];
		return uv;
		}

	template<typename _Ty0> inline
		_Ty0*& itoas(int i)
		{ // itoa
		static _Ty0 buf[21];
		_Ty0 *p = buf + 19 + 1;
		if (i >= 0) 
			{while (i != 0)
				*--p = '0' + (i % 10), i /= 10;
			return p;}
		else{while (i != 0)
				*--p = '0' - (i % 10), i /= 10;
			*--p = '-';}
		return p;
		}

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

	template<class _Ty0> inline
		_Ty0 *last_ptr(_Ty0 *that)
		{ // last pointer
		_Ty0 *pp = that;
		while(*pp++);
		return pp;
		}
	
	template<typename _Ty0> inline
		bool isnumberic(_Ty0 what)
		{ // is numberic
		return '0' <= what && what <= '9';
		}

	template<typename _Ty0> inline
		_Ty0 isspace(_Ty0 c_ch)
		{ // isspace
		switch(c_ch)
			{
		case '\n':
		case '\v':
		case '\f':
		case '\t':
		case '\r':
		case  ' ':
			return 1;
			}
		return 0;
		}

	template<typename _Ty0> inline
		bool strstr(const _Ty0 x, const _Ty0 *xt)
		{ // strstr
		int f = f_len(xt);
		for(int i = 0; i < f; i++)
			if(xt[i] == x)
				return true;
		return false;
		}
}

#endif