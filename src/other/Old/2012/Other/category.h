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

#include "utility.h"

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

			int k = ptrlen( key ), j = 2166136261;

			for( int i = 0;  i < k;  i++ )

				j  =  ( ( j  *  16777619 )  ^  key[i] ) ;

			return ( j ^ ( j >> 3 ) ) % _CSize;

		}

	};

#endif