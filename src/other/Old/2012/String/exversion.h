/*-------------------------------------------------

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

-------------------------------------------------*/

#pragma once
#ifndef _ROLLRAT_FILE_
#define _ROLLRAT_FILE_

#include <stdio.h>
#include <io.h>
#include "rutil.h"

#if defined(_EX_SUCCESS)

/*
COMMON Lib Start*/
_X_LIB_BEGIN
	
	template<class _Ty, 
			class _Pointer = _Ty*, 
			class _Reference = _Ty&>
		struct _X_FILE_EX
		{ // File struct
		STR_PUBLICQ
		typedef _Ty Value_Type;
		typedef _Pointer Pointer;
		typedef _Reference Reference;
		};

	#define ERROR (-1)

	template<class _Ty>
	class FILE_EX
		: public _X_FILE_EX<_Ty>
	{
		typedef FILE_EX<_Ty>	_MyT;
		typedef typename _X_FILE_EX<_Ty>::Value_Type _MyVT;
		typedef typename _X_FILE_EX<_Ty>::Reference _MyRE;
		typedef typename _X_FILE_EX<_Ty>::Pointer _MyPI;
	public:

		explicit FILE_EX()
			: File_Pointer(0)
			{
			}

		explicit FILE_EX(char* filename)
			: File_Pointer(0), File_Name(filename)
			{
			}

		~FILE_EX()
			{
			fclose(this->file_pointer);
			}

		void SetFile(char* filename)
			{
			this->File_Name = filename;
			}

		bool FileExist(char* filename)
			{
			file_pointer = fopen(filename, "r");
			return (file_pointer == NULL);
			}

		bool FileExist()
			{
			return FileExist(this->File_Name);
			}

		int GetFileDescriptor(char* filename)
			{
			file_pointer = fopen(filename, "a+");
			if(file_pointer == NULL)
				return ERROR;
			return _fileno(file_pointer);
			}

		int GetFileDescriptor()
			{
			return GetFileDescriptor(this->File_Name);
			}

		int GetFileLenth(char* filename)
			{
			int FileDescriptor = GetFileDescriptor(filename);
			if(FileDescriptor != ERROR)
				return _filelength(FileDescriptor);
			else return ERROR;
			}

		int GetFileLenth()
			{
			return GetFileLenth(this->File_Name);
			}

	private:

		unsigned long long File_Pointer;
		char* File_Name;
		FILE * file_pointer;

	};

_X_LIB_END

#endif

#endif