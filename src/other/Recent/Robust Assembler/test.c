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
	//	_stdcall���� _cdecl, _fastcall�� ����ص� ��������
	//	���� �̷� ���Լ��� _stdcall�� �� ���� ���δ�.
	//	���� ó���� �Լ����� ���� �ʾƵ� �Ǿ� �� �ڵ尡 ����Ǵ�
	//	ȿ���� �� �� �ִ�.
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
	//	malloc�� �����ָ� ��°���� rasm_test���� xtarr��
	//	0xCDCDCD...�� ä����...
	//
	set = (BYTE *)malloc(sizeof(BYTE) * 32);
	ptr = rasm_assemble_code(cmd, 0, 0, &s1, &s2);
	for (i = 0; i < s1; i++) set[i] = ptr[i];
	rasm_test(set, s1, 0);
}