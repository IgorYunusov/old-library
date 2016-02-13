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
	SvrEntry: Entry�� �����մϴ�.
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
	SvrEntry: Cluster�� �����մϴ�.
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
	SvrEntry: Table�� �����մϴ�.
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
	SvrEntry: Section�� �����մϴ�.
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