/*-------------------------------------------------

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

-------------------------------------------------*/

// Operation Version : 1.00

#pragma once
#ifndef __MEMORY_
#define __MEMORY_

#include "rutil.h"

#if defined(_EX_SUCCESS)

_X_LIB_BEGIN
	
	class _X_Memory_Block
	{
	public:

		_X_Memory_Block(){CreateNewMemoryBlock(0);}
		~_X_Memory_Block(){Dispose();}
		void CreateNewMemoryBlock(int size){mem_block = new void[size];}
		void Dispose(){delete[] mem_block;}
		void* GetMomoryPointer(){return mem_block;}

	private:
		void* mem_block;
		int sizeofit;

	};

_X_LIB_END

#endif
#endif
