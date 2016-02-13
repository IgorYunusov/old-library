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

/*

	이 클래스는 25/10/2015에 10e6을 곱하는 치명적인 오류를 해결하였습니다.
	이전에 작성되었던 opreator*의 기준은 ns가 아닌 ms기준입니다.

*/

#ifndef _TIMER_9bf1541fdf7efd41b7b39543fd870ac4_
#define _TIMER_9bf1541fdf7efd41b7b39543fd870ac4_

#include <Windows.h>
#include <iostream>
#include <limits>

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
		return (_Ty)(_Ty(fin.QuadPart - str.QuadPart) * 10e8 / _Ty(fre.QuadPart));
		}

#   ifdef _TIMER_OUTPUT

	inline void out()
		{
		std::cout.precision(std::numeric_limits<long double>::digits10);
		std::cout << **this << "ns" << std::endl;
		}

	inline void outms()
		{
		std::cout.precision(std::numeric_limits<long double>::digits10);
		std::cout << (_Ty)(_Ty(fin.QuadPart - str.QuadPart) * 10e2 / _Ty(fre.QuadPart)) << "ms" << std::endl;
		}
	
	inline void outs()
		{
		std::cout.precision(std::numeric_limits<long double>::digits10);
		std::cout << (_Ty)(_Ty(fin.QuadPart - str.QuadPart) / _Ty(fre.QuadPart)) << "s" << std::endl;
		}

#   endif

	};

#endif