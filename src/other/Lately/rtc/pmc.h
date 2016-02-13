/*************************************************************************
 *
 *					  ROLLRAT SOFTWARE LIBRARY [Private]
 *						PUT MACHINE CODE
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *[INSIDE METHOD]
 *************************************************************************/

#ifndef _PMC_
#define _PMC_

#include <Windows.h>

template<typename code = char, typename _func = void *> class
	pmc
	{
public:
	_func function;

	void Load(code *code, size_t size)
		{
		HANDLE mem_handle = CreateFileMapping( 
			INVALID_HANDLE_VALUE, 
			NULL, 
			PAGE_EXECUTE_READWRITE, 
			0,  
			size, 
			NULL);

		function = _func(MapViewOfFile( 
			mem_handle, 
			FILE_MAP_ALL_ACCESS | FILE_MAP_EXECUTE, 
			0, 
			0, 
			size));

		memcpy(function, code, sizeof(code));
		}

	inline void Call()
		{
		((_func(*)())function)();
		}

	};

#endif