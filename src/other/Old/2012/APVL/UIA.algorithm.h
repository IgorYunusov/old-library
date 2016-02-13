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

// Unlimited Intervene Algorithms

#ifndef UIA_ALGORITHM
#define UIA_ALGORITHM

#define AT(x)	(char)(x)

#define USCHAR(x)	(unsigned char *)(x)

#define INLINE	inline

#define DEKS_TEMSET template<class _UIA>
#define ATVOID		void
#define UIASTRUCT	struct

#define AFFIX_CLASSUNIT
#define UNAFIX_CLASSUNIT


//---------------------------------------------------------------------
// Security Dest List
//---------------------------------------------------------------------
#define _DEST_SECURITY_XORDX(_x, _y)		_x = _x ^ _y;
#define _DEST_SECURITY_XORDY(_x, _y, _z)	_z = _x ^ _y;
#define _DEST_ACTIVE_ATSWAP(_x, _y) \
	_DEST_SECURITY_XORDX(_x, _y) _DEST_SECURITY_XORDX(_y, _x)\
	_DEST_SECURITY_XORDX(_x, _y)
#define _DEST_COMPLEX_ACROSS(_x, _y, _z)	_z = _x; _x = _y; _y = _z;


//---------------------------------------------------------------------
// Make Helper Source List
//---------------------------------------------------------------------
#define MKCLASS(_tx)	class _tx
#define AFXCLASS(_tx)	DEKS_TEMSET class _tx
#define VERSION_RECOLLECT(__func)	((*__func())())
#define VERSION_COLLECT(__func, _tx) ((*__func())(_tx))
#define VERSION_SELECTION(__func, _tx, insu) ((*__func(insu))_tx)
#define SET_COLLECTOR( n, x ) INLINE void Set##n( x )
#define GET_COLLECTOR( n, x ) INLINE x Get##n()


//---------------------------------------------------------------------
// Basic 3 Algorithms
//---------------------------------------------------------------------
template<class _UIA_x> INLINE void 
	swap(_UIA_x &x, _UIA_x &y)
	{ // std swap
		_UIA_x t;
		_DEST_COMPLEX_ACROSS(x, y, t)
	}

template <class _UIA_x> INLINE int
    length(const _UIA_x *sWcT)
    { // strlen
        const _UIA_x *sWcTK = sWcT;
        for( ; *sWcTK; sWcTK++)
            ;
        return (sWcTK - sWcT - 1);
    }
 
template <class _UIA_x> INLINE void
    copy(const _UIA_x *sWcT, _UIA_x*& sWcTX)
    { // copy
        const _UIA_x *sWcTK = sWcT;
        _UIA_x *t = sWcTX;
        for( ; *sWcTK; sWcTK++, t++)
            *t = *sWcTK;
    }


//---------------------------------------------------------------------
// Split UIA
//---------------------------------------------------------------------
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
        return (sWcTK + length(sWcCT));
    }
 
template < class _StrWcx > INLINE const _StrWcx *
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
        Mem = new _StrWcx[length(sWcT) - f + 1];
        copy(sWcT, Mem);
        Mem[f] = 0;
        return Mem;
    }
 
template < class _StrWcx > INLINE const _StrWcx *
    _Split( const _StrWcx *sWcT, const _StrWcx *sWcCT, int n )
    { // split
        return _PutZero(_Catch(sWcT, sWcCT, n), 
            _Catch(sWcT, sWcCT, n + 1) - length(sWcCT) - 1);
    }

#endif