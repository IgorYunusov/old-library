/*************************************************************************
 *
 *                    ROLLRAT AUTO PERSONA VERBOTER LIBROFEX
 *
 *                         (C) Copyright 2009-2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _IS_POINTER
#define _IS_POINTER

template<class _Val, _Val x>
	struct _exp
	{
	static const _Val value = x;

	operator _Val()
		{
			return x;
		}
	};

template<bool>
	struct __Cat_base
		: _exp<bool, false>
	{
	};

template<>
	struct __Cat_base<true>
		: _exp<bool, true>
	{
	};

template<typename _Ty> 
	struct _Is_String
		: _exp<bool, false>
	{
	};

template<> 
	struct _Is_String<char *>
		: _exp<bool, true>
	{
	};

template<typename _Ty> 
	struct _Is_Unicode
		: _exp<bool, false>
	{
	};

template<> 
	struct _Is_Unicode<unsigned char *>
		: _exp<bool, true>
	{
	};

template<typename _Ty>
	struct _rm_cst
	{
	typedef _Ty type;
	};

template<typename _Ty>
	struct _rm_cst<const _Ty>
	{
	typedef _Ty type;
	};

template<class _Ty>
	struct _rm_cst<const _Ty[]>
	{
	typedef _Ty type[];
	};

template<class _Ty>
	struct _rm_ref
	{
	typedef _Ty type;
	};

template<class _Ty>
	struct _rm_ref<_Ty&>
	{
	typedef _Ty type;
	};

template<class _Ty>
	struct _rm_ref<_Ty&&>
	{
	typedef _Ty type;
	};

template<typename _Ty>
	struct is_pointer
		: __Cat_base<
			_Is_String<_Ty>::value 
				|| _Is_Unicode<
				_Ty>::value>
	{
	};

#endif