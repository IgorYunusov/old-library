/*************************************************************************
 *
 *					  ROLLRAT SOFTWARE LIBRARY [Private]
 *						TIMER
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *[INSIDE METHOD]
 *************************************************************************/

#ifndef _TIMER_
#define _TIMER_

#include <Windows.h>

template<class _Ty>
class Timer
	{
public:
	LARGE_INTEGER str, fre, fin;
	
	inline void start()
		{
		QueryPerformanceFrequency(&fre);
		QueryPerformanceCounter(&str);
		}

	inline void finish()
		{
		QueryPerformanceCounter(&fin);
		}
	
	inline _Ty operator*()
		{
		return (_Ty)(_Ty(fin.QuadPart - str.QuadPart) * 1000000 / _Ty(fre.QuadPart));
		}

	};

#endif