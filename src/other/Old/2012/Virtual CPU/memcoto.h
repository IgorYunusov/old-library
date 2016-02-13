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

#ifndef __MEMCOTO		// Memory Copy 
#define __MEMCOTO

#include "transti.h"

#define MaxMemoryAlloc				0xffffff		// 32 bit max memory

#define Bit32Max					0xffffffff

#define L1CacheMemoryMax			0xffff			// 0008 KB
#define L2CacheMemoryMax			0xffffff		// 0002 MB

class _aligSxt_32
	{ // 32 bit memory
	Transti **x;
public:
	_aligSxt_32()
		{
			x = new Transti*[0x20];
			for(int i = 0; i < 0x20; i++)
				x[i] = new Transti[MaxMemoryAlloc];
		}
	~_aligSxt_32()
		{
			delete[] x;
		}
	Transti**& GetLocalMemory()
		{
			return x;
		}
	};

#endif