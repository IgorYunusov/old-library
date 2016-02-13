/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   ldr.c - [Private]
   
Abstract:

   Qurey Loader

------
   AUTHOR: HyunJun Jeong  2015-01-21

***************************************************************************/

#include <stdio.h>
#include <malloc.h>
#include "qyt.h"

/*
	LdrEntry: Entry를 로드합니다.
*/
BOOL LdrEntry(
	IN FILE *fp, 
	OUT PQUREY_ENTRY *ptr
	)
{
	fseek(fp, 0, SEEK_SET);
	fread(*ptr, sizeof(QUREY_ENTRY), 1, fp);

	return TRUE;
}

/*
	LdrCluster: Cluster 구역을 로드합니다.
*/
BOOL LdrCluster(
	IN FILE *fp, 
	IN DWORD dwAddr, 
	OUT PQUREY_CLUSTER *ptr
	)
{
	fseek(fp, dwAddr, SEEK_SET);
	fread(*ptr, sizeof(QUREY_CLUSTER), 1, fp);

	return TRUE;
}

/*
	LdrTable: 테이블을 로드합니다.
*/
BOOL LdrTable(
	IN FILE *fp, 
	IN DWORD dwAddr, 
	IN WORD wCount,
	OUT PQUREY_TABLE **ptr
	)
{
	PQUREY_TABLE qt, *pqt;

	pqt = (QUREY_TABLE **)malloc(sizeof(QUREY_TABLE)*wCount);

	fseek(fp, dwAddr, SEEK_SET);
	fread(pqt, sizeof(QUREY_TABLE), wCount, fp);

	ptr = &pqt;

	return TRUE;
}

/*
	LdrTable: 섹션을 로드합니다.
*/
BOOL LdrSectionFromTable(
	IN FILE *fp,
	IN PQUREY_TABLE pqt,
	OUT PQUREY_SECTION **ptr
	)
{
	PQUREY_SECTION qt, *pqs;

	fseek(fp, pqt->HeadAddrOfSection, SEEK_SET);
	fread(pqt, sizeof(QUREY_TABLE), pqt->NumberOfSection, fp);

	ptr = &pqs;
	return TRUE;
}