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

#pragma once

#ifndef __STRWEPAON
#define __STRWEPAON

#include "stddef.h"
#include "vceffmem.h"

template < class _StrWcx > INLINE int
	_Length( const _StrWcx *sWcT )
	{ // strlen
		const _StrWcx *sWcTK = sWcT;
		for( ; *sWcTK; sWcTK++)
			;
		return (sWcTK - sWcT - 1);
	}

template < class _StrWcx > INLINE void
	_Copy( const _StrWcx *sWcT, _StrWcx*& sWcTX )
	{ // copy
		const _StrWcx *sWcTK = sWcT;
		_StrWcx *t = sWcTX;
		for( ; *sWcTK; sWcTK++, t++)
			*t = *sWcTK;
	}

template < class _StrWcx > INLINE int
	_Count( const _StrWcx *sWcT, const _StrWcx sWcCH )
	{ // count char
		const _StrWcx *sWcTK = sWcT;
		int i = 0;
		for( ; *sWcTK; sWcTK++)
			if(*sWcTK == sWcCH)
				i++;
		return i;
	}

template < class _StrWcx > INLINE int
	_Count( const _StrWcx *sWcT, const _StrWcx *sWcCT )
	{ // counst char *
		const _StrWcx *sWcTK = sWcT, *sWcCTK = sWcCT, *sWc;
		int i = 0;
		for( ; *sWcTK; sWcTK++)
			if(*sWcTK == *sWcCT)
				for( sWcCTK = sWcCT, sWc = sWcTK; ; sWcCTK++, sWc++)
					if(!*sWcCTK) {
						i++; break;}
					else if(*sWcCTK != *sWc || !*sWc)
						break;
		return i;
	}

template < class _StrWcx > INLINE const _StrWcx *
	_Catch( const _StrWcx *sWcT, const _StrWcx *sWcCT, int n )
	{ // split - catch
		const _StrWcx *sWcTK = sWcT, *sWcCTK = sWcCT, *sWc;
		if(n == 0)
			return sWcTK;
		for(int i = 0; *sWcTK; sWcTK++)
			if(*sWcTK == *sWcCT)
			{
				for( sWcCTK = sWcCT, sWc = sWcTK; ; sWcCTK++, sWc++)
					if(!*sWcCTK)
					{
						i++;
						if(i == n)
							break;
						break;
					}
					else if(*sWcCTK != *sWc || !*sWc)
						break;
			}
			else if(i == n)
				break;
		return (sWcTK + _Length(sWcCT));
	}

template < class _StrWcx > INLINE _StrWcx *
	_PutZero( const _StrWcx *sWcT, const _StrWcx *sWcJ)
	{ // split - put zero
		const _StrWcx *sWcTK = sWcT, *sWcCTK = sWcJ, *sWc;
		_StrWcx *Mem;
		int f = 0;
		for( ; ; sWcTK++, f++)
			if(*sWcTK == *sWcJ)
			{
				for( sWcCTK = sWcJ, sWc = sWcTK; ; sWcCTK++, sWc++)
					if(!*sWcCTK)
						break;
					else if(*sWcCTK != *sWc || !*sWc)
						break;
				if(!*sWcCTK)
					break;
			}
		Mem = new _StrWcx[_Length(sWcT) - f + 1];
		_Copy(sWcT, Mem);
		Mem[f] = 0;
		return Mem;
	}

template < class _StrWcx > INLINE _StrWcx *
	_Split( const _StrWcx *sWcT, const _StrWcx *sWcCT, int n )
	{ // split
		return _PutZero(_Catch(sWcT, sWcCT, n), 
			_Catch(sWcT, sWcCT, n + 1) - _Length(sWcCT) - 1);
	}

#endif