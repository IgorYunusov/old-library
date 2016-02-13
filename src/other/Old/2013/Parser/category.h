/*************************************************************************
 *
 *                    ROLLRAT AUTO PERSONA VERBOTER LIBROFEX
 *
 *                         (C) Copyright 2009-2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _CATEGORY
#define _CATEGORY

#include "hash.h"

template<class _Val, _Val x>
	struct _exp{
	static const _Val value = x;
	operator _Val(){return x;}};
template<bool>
	struct __Cat_base
		: _exp<bool, false>{};
template<>
	struct __Cat_base<true>
		: _exp<bool, true>{};
template<typename _Ty> 
	struct _Is_String
		: _exp<bool, false>{};
template<> 
	struct _Is_String<char *>
		: _exp<bool, true>{};
template<typename _Ty> 
	struct _Is_Unicode
		: _exp<bool, false>{};
template<> 
	struct _Is_Unicode<unsigned char *>
		: _exp<bool, true>{};
template<typename _Ty>
	struct _rm_cst
	{typedef _Ty type;};
template<typename _Ty>
	struct _rm_cst<const _Ty>
	{typedef _Ty type;};
template<class _Ty>
	struct _rm_cst<const _Ty[]>
	{typedef _Ty type[];};
template<class _Ty>
	struct _rm_ref
	{typedef _Ty type;};
template<class _Ty>
	struct _rm_ref<_Ty&>
	{typedef _Ty type;};
template<class _Ty>
	struct _rm_ref<_Ty&&>
	{typedef _Ty type;};
template<typename _Ty>
	struct is_pointer
		: __Cat_base<
			_Is_String<_Ty>::value 
				|| _Is_Unicode<
				_Ty>::value>{};

template<class _Category = char *, 
	int _Size = 0xFFFF, 
	int _CSize = 0xFF>
class
	_category_scr
	{ // category scr
	typedef typename _rm_cst<_Category>::type _MyPtr;
	typedef hash<_MyPtr, _MyPtr, _Size>* _MyHash;
	_MyHash category;
	is_pointer<_MyPtr> _Capture;
public:

	_category_scr()
		{
			if( _Capture )
				category = new hash<_MyPtr, _MyPtr, _Size>[_CSize];
		}

	~_category_scr()
		{
			delete[] category;
		}

	hash<_MyPtr, _MyPtr, _Size> &
		operator[] ( const _MyPtr key )
		{
			int addr = hf( key );
			return category [ addr ];
		}

private:
	
	int hf( const _MyPtr key )
		{ // create hash key
			int k = strlen( key ), j = 2166136261;
			for( int i = 0;  i < k;  i++ )
				j  =  ( ( j  *  16777619 )  ^  key[i] ) ;
			return ( j ^ ( j >> 3 ) ) % _CSize;
		}
	};

#endif