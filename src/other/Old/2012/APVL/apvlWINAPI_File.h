/************************************************************
 *															*
 *															*
 *			ROLLRAT AUTO PERSONA VERBOTER LIBROFEX			*
 *															*
 *															*
 *		COPYRIGHT (c) rollrat. 2013. ALL RIGHTS RESERVED.	*
 *															*
 *															*
 ************************************************************/

#pragma once

#ifndef __APVL_FILE
#define __APVL_FILE

#include <Windows.h>

#define FILE_SUCCESS		0
#define FILE_INVALID		1

int WINAPI ApvlFileOpen(char * FileName)
{
	HANDLE x = CreateFile(FileName, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if(x == INVALID_HANDLE_VALUE)
		return FILE_INVALID;
	else
		return FILE_SUCCESS;
}

int WINAPI ApvlFileOpenH(char * FileName, PHANDLE hFileHandle)
{
	hFileHandle = (HANDLE *)CreateFile(FileName, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if(hFileHandle == INVALID_HANDLE_VALUE)
		return FILE_INVALID;
	else
		return FILE_SUCCESS;
}

void WINAPI ApvlFileClose(PHANDLE hFileHandle)
{
	CloseHandle(&hFileHandle);
}

int WINAPI ApvlFileCreate(char * FileName, PHANDLE hFileHandle)
{
	hFileHandle = (HANDLE *)CreateFile(FileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, NULL);
	if(hFileHandle == INVALID_HANDLE_VALUE)
		return FILE_INVALID;
	else
		return FILE_SUCCESS;
	
}

#endif
