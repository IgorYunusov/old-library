/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   svr.c - [Private]
   
Abstract:

   Qurey Saver

------
   AUTHOR: HyunJun Jeong  2015-01-21

***************************************************************************/

#include <stdio.h>
#include <malloc.h>
#include "qyt.h"

/*
	SvrEntry: Entry를 저장합니다.
*/
BOOL SvrEntry(
	IN FILE *fp, 
	IN PQUREY_ENTRY ptr
	)
{
	fseek(fp, 0, SEEK_SET);
	fwrite(ptr, sizeof(QUREY_ENTRY), 1, fp);

	return TRUE;
}

/*
	SvrEntry: Cluster를 저장합니다.
*/
BOOL SvrCluster(
	IN FILE *fp, 
	IN DWORD dwAddr,
	IN PQUREY_CLUSTER ptr
	)
{
	fseek(fp, dwAddr, SEEK_SET);
	fwrite(ptr, sizeof(QUREY_CLUSTER), 1, fp);

	return TRUE;
}

/*
	SvrEntry: Table을 저장합니다.
*/
BOOL SvrTable(
	IN FILE *fp, 
	IN DWORD dwAddr,
	IN PTABLE_LIST ptr
	)
{
	fseek(fp, dwAddr, SEEK_SET);
	//fwrite(ptr, sizeof(QUREY_TABLE), wCount, fp);
	for(; ptr; ptr = ptr->next) {
		fwrite((PQUREY_TABLE)(ptr->qt), sizeof(QUREY_TABLE), 1, fp);
	}

	return TRUE;
}

/*
	SvrEntry: Section을 저장합니다.
*/
BOOL SvrSection(
	IN FILE *fp, 
	IN DWORD dwAddr,
	IN WORD wCount,
	IN PQUREY_SECTION *ptr
	)
{
	fseek(fp, dwAddr, SEEK_SET);
	fwrite(ptr, sizeof(QUREY_SECTION), wCount, fp);

	return TRUE;
}