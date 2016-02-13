/****************************************************************
 *																*
 *																*
 *			ROLLRAT AUTO PERSONA VERBOTER LIBROFEX				*
 *																*
 *					SPIN OFF PROJECT Vol 1						*
 *																*
 *		COPYRIGHT (c) rollrat. 2013. ALL RIGHTS RESERVED.		*
 *																*
 *																*
 ****************************************************************/

#ifndef __VCPUX
#define __VCPUX

#include "alu.h"
#include "cu.h"
#include "memcoto.h"

class _VcpuX
	{ // Cpu Module
	_aligSxt_32 __8memorySet;
	Transti **TranstiPtr;
	_32bitALU alu;
	float clock;
	_algnCxk cu;
public:
	_VcpuX()
		{ // get bit mem
			TranstiPtr = __8memorySet.GetLocalMemory();
			alu.MemSet(TranstiPtr);
		}
	void __klocalhostGetClock()
		{

		}
	};

#endif