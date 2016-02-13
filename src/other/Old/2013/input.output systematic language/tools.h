/*
            ROLLRAT INPUT OUTPUT SYSTEMATIC LANGUAGE PROJECT

             Cpy (c) 14. ALL RIGHTS RESERVED.
   */

#ifndef _TOOLS_
#define _TOOLS_

#include <Windows.h>
#include <stdio.h>

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

template<class _Ty = unsigned long int>
class File
	{
	FILE *fptr;
public:
	_Ty size;

	bool open(const char * str)
		{
		fopen_s(&fptr, str, "rb");
		return fptr == NULL;
		}

	void calcsize()
		{
		fseek(fptr, 0, SEEK_END);
		size = ftell(fptr);
		}

	void close()
		{
		fclose(fptr);
		}

	BYTE * read()
		{
		BYTE * str = new BYTE[size];
		fseek(fptr, 0, SEEK_SET);
		fread(str, size, 1, fptr);
		return str;
		}

	};

#endif