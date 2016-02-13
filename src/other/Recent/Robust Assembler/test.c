/*************************************************************************
 *
 * FILE NAME : test.c
 *
 * ROLLRAT SOFTWARE Robust Assembler (RASM)
 *
 *
 * LANGUAGE : ANSI C
 * CREATION : 2015.01.02
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com, rollrat.software@gmail.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#include <Windows.h>
#include "test.h"
#include "rasm.h"
#include "assemble.h"

int rasm_test(const BYTE *xtarr, size_t size, int var)
{
	HANDLE mem_handle = CreateFileMapping( 
			INVALID_HANDLE_VALUE, 
			NULL, 
			PAGE_EXECUTE_READWRITE, 
			0,  
			size, 
			NULL);
	void * function = (void *)(MapViewOfFile(
			mem_handle,
			FILE_MAP_ALL_ACCESS | FILE_MAP_EXECUTE,
			0,
			0,
			size));
	int xy;
	memcpy(function, xtarr, size);

	//
	//	_stdcall말고 _cdecl, _fastcall를 사용해도 괜찮지만
	//	보통 이런 쉘함수엔 _stdcall이 더 많이 쓰인다.
	//	변수 처리를 함수에서 하지 않아도 되어 쉘 코드가 단축되는
	//	효과를 볼 수 있다.
	//
	xy = ((int(_stdcall*)(int))function)(var);
	return xy;
}

void rasm_test_line_full(const char *cmd)
{
	size_t s1;
	u32 s2;
	BYTE *ptr, *set;
	int i;

	//
	//	malloc을 안해주면 어째선지 rasm_test에서 xtarr이
	//	0xCDCDCD...로 채워짐...
	//
	set = (BYTE *)malloc(sizeof(BYTE) * 32);
	ptr = rasm_assemble_code(cmd, 0, 0, &s1, &s2);
	for (i = 0; i < s1; i++) set[i] = ptr[i];
	rasm_test(set, s1, 0);
}