/*--------------------------------------------------------------------

		AIM Library
		(Another Imaginary Management)

		Copyright (c) Kuroko_decs. 2013. All rights reserved.

--------------------------------------------------------------------*/

#pragma once

#ifndef _AIM_LIB_CLONE
#define _AIM_LIB_CLONE

#if defined(_CCLN_001)
#define CLONE_EXCUSE		1
#else /* !_CCLN_001 */
#define CLONE_EXCUSE		0
#endif /* _CCLN_001 End */

template<class _Acl>
	struct __cl_type
	{ // str type
	typedef _Acl value_type;
	typedef _Acl &reference;
	typedef _Acl &pointer;
	};

#define __cl_type_c( _A )  __cl_type<const _A>

#if defined(CPP_0X_FLAG)
template<class _Acl>
	struct __cl_type_p
	{ // str type 0x
	typedef _Acl &&rValue;
	typedef _Acl &lValue;
	};
#endif /* CPP_0X_FLAG End */

template<class _Acl> 
	class clo_facility
	{ // clone facility
	typedef typename __cl_type<_Acl>::value_type _MyVal;
	typedef typename __cl_type<_Acl>::reference	 _MyRef;
	typedef typename __cl_type<_Acl>::pointer	 _MyPtr;

public:
	
	explicit clo_facility(size t_size) : LeNth(t_size), _arrY(new _MyVal[t_size])
	{

	}

private:

	size LeNth;
	_MyPtr _arrY;

	};


#endif