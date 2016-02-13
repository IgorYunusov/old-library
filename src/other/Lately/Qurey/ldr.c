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
	//char szData[sizeof(QUREY_ENTRY)] = { 0, };
	//QUREY_ENTRY qe;
	//int i;

	fseek(fp, 0, SEEK_SET);
	//fread(szData, sizeof(QUREY_ENTRY), 1, fp);
	//
	//for (i = 0; i < sizeof(QUREY_ENTRY); i++)
	//	((char *)(&qe))[i] = szData[i];

	fread(*ptr, sizeof(QUREY_ENTRY), 1, fp);

	//*ptr = &qe;
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
	//char szData[sizeof(QUREY_CLUSTER)] = { 0, };
	//QUREY_CLUSTER qc;
	//int i;

	fseek(fp, dwAddr, SEEK_SET);

	//fread(szData, sizeof(QUREY_CLUSTER), 1, fp);
	//
	//for (i = 0; i < sizeof(QUREY_CLUSTER); i++)
	//	((char *)(&qc))[i] = szData[i];

	fread(*ptr, sizeof(QUREY_CLUSTER), 1, fp);

	//*ptr = &qc;
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
	//char szData[sizeof(QUREY_TABLE)] = { 0, };
	PQUREY_TABLE qt, *pqt;
	//int i;

	pqt = (QUREY_TABLE **)malloc(sizeof(QUREY_TABLE)*wCount);

	//for(i = 0; i < wCount; i++) {
	//	qt = (QUREY_TABLE *)malloc(sizeof(QUREY_TABLE));
	//	fseek(fp, dwAddr+sizeof(QUREY_TABLE)*i, SEEK_SET);
	//	fread(szData, sizeof(QUREY_TABLE), 1, fp);
	//	for (i = 0; i < sizeof(QUREY_TABLE); i++)
	//		((char *)(qt))[i] = szData[i];
	//	pqt[i] = qt;
	//}

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
	//char szData[sizeof(QUREY_TABLE)] = { 0, };
	PQUREY_SECTION qt, *pqs;
	//int i;

	//pqs = (QUREY_SECTION **)malloc(sizeof(QUREY_SECTION)*pqt->NumberOfSection);

	//for(i = 0; i < pqt->NumberOfSection; i++) {
	//	qt = (QUREY_SECTION *)malloc(sizeof(QUREY_SECTION));
	//	fseek(fp, pqt->HeadAddrOfSection+sizeof(QUREY_SECTION)*i, SEEK_SET);
	//	fread(szData, sizeof(QUREY_SECTION), 1, fp);
	//	for (i = 0; i < sizeof(QUREY_SECTION); i++)
	//		((char *)(qt))[i] = szData[i];
	//	pqs[i] = qt;
	//}

	fseek(fp, pqt->HeadAddrOfSection, SEEK_SET);
	fread(pqt, sizeof(QUREY_TABLE), pqt->NumberOfSection, fp);

	ptr = &pqs;
	return TRUE;
}