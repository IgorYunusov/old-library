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

#ifndef __vtpx		// Virtual Tunnel Pointer Extension
#define __vtpx

#include "memory.h"

#ifndef __VTPX_LOCAL_CEN
#define __VTPX_LOCAL_CEN char
#endif

#define LOCK_CENT

template<class _AxNetw> class
	__vtp__network__cen
	{ // vtp Network
	___tg8_lock_ptr<_AxNetw, int> _tg9;
	int lock_ptr;
public:
	__vtp__network__cen(_AxNetw XT) : lock_ptr(_tg9.Lock(XT)) {}
	void Connect(int ptr_gt = 0, int ptr_tt = 0, int ptr_et = 0, int ptr_vt = 0)
		{

		}
	};

__vtp__network__cen<__VTPX_LOCAL_CEN> VTP_NETWORK;

template<class _AxVtpx> class
	vtp
	{ // virtual tunnel pointer

public:
	};

#endif