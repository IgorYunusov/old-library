/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   qy.c - [Private]
   
Abstract:

   Approach qurey algorithm.

------
   AUTHOR: HyunJun Jeong  2015-01-21

***************************************************************************/

#include <string.h>
#include "qyt.h"

/*
	QryTableWithId: Table�� ID�� �����մϴ�.
*/
BOOL QryTableWithId(
	IN PQUREY_TABLE *qt,
	IN WORD wId,
	IN WORD wNumberOfTable,
	OUT PQUREY_TABLE *ptr
	)
{
	WORD ic;

	for(ic = 0; ic < wNumberOfTable; ic++) {
		if(qt[ic]->TableID == wId) {
			*ptr = qt[ic];
			return TRUE;
		}
	}

	return FALSE;
}

/*
	QryTableWithId: Table�� Name���� �����մϴ�.
*/
BOOL QryTableWithName(
	IN PQUREY_TABLE *qt,
	IN const char chpName[QYT_STRMAX_LENGTH],
	IN WORD wNumberOfTable,
	OUT PQUREY_TABLE *ptr
	)
{
	WORD ic;

	for(ic = 0; ic < wNumberOfTable; ic++) {
		if(!strcmp(qt[ic]->TableName, chpName)) {
			*ptr = qt[ic];
			return TRUE;
		}
	}

	return FALSE;
}

/*
	QrySectionWithId: Section�� ID�� �����մϴ�.
*/
BOOL QrySectionWithId(
	IN PQUREY_SECTION *qs,
	IN WORD wId,
	IN WORD wNumberOfSection,
	OUT PQUREY_SECTION *ptr
	)
{
	WORD ic;

	for(ic = 0; ic < wNumberOfSection; ic++) {
		if(qs[ic]->SectionID == wId) {
			*ptr = qs[ic];
			return TRUE;
		}
	}

	return FALSE;
}

/*
	QrySectionWithId: Section�� ID�� �����մϴ�.
*/
BOOL QrySectionWithName(
	IN PQUREY_SECTION *qs,
	IN const char chpName[QYT_STRMAX_LENGTH],
	IN WORD wNumberOfSection,
	OUT PQUREY_SECTION *ptr
	)
{
	WORD ic;

	for(ic = 0; ic < wNumberOfSection; ic++) {
		if(!strcmp(qs[ic]->SectionName, chpName)) {
			*ptr = qs[ic];
			return TRUE;
		}
	}

	return FALSE;
}


//////////////////////////////////////////////////
////
////	Qurey Algorithm Set
////
////	��������
////
//////////////////////////////////////////////////

/*
	QryiSectionStringInformation: �����ͷ� �ּҸ� �����ɴϴ�.
*/
BOOL 
INTERNAL
QryiSectionStringInformation(
	IN PQUREY_SECTION qs,
	IN QUREY_DBSTRING qdb,
	IN QUREY_DBSTRING qdbsrc,
	IN DWORD wLength,
	OUT DWORD *dwAddr
	)
{
	DWORD Address;
	DWORD i;

	Address = qdb;
	i = 0;

	if(qs->Flags & FLAG_UNLOCKDELIMITER) {
		for(; i < qs->SizeOfDataBase;) {
			if(*(char *)Address != *(char *)qdbsrc) {
				QryiiSectionStringDelimiterNextInto(qs,
													Address,
													1,
													&Address);
				i = Address - qs->HeadAddrOfDataBase;
				continue;
			}
			if(!strncmp((char *)Address, qdbsrc, wLength)) {
				*dwAddr = Address;
				return TRUE;
			}
			
		}
		
	}

	//
	// �����ڰ� ������ Ž���� �� ����
	return FALSE;
}

/*
	QryiiSectionStringDelimiterNextInto: �����ڷ� �Ͽ��� w��° �����͸� �����ɴϴ�.
*/
BOOL
INTERNAL
QryiiSectionStringDelimiterNextInto(
	IN PQUREY_SECTION qs,
	IN QUREY_DBSTRING qdb,
	IN DWORD wLength,
	OUT QUREY_DBSTRING *ptr
	)
{
	BYTE bDelimiter;
	WORD wDelimiter;
	DWORD dwDelimiter;
	DWORD addr;
	DWORD i, j;

	i = 0;
	j = 1;
	addr = (DWORD)qdb;

	if(qs->Flags & FLAG_DELIMITER_BYTE) {
		bDelimiter = (BYTE)(qs->SpecificDelimiter & 0xff);
		for(; i < qs->SizeOfDataBase && j < wLength; i++) {
			if (*(BYTE *)qdb == bDelimiter)
				j++;
			(BYTE *)qdb += 1;
		}
		if (j != wLength)
			return FALSE;
	} else if (qs->Flags & FLAG_DELIMITER_WORD) {
		wDelimiter = (WORD)(qs->SpecificDelimiter & 0xffff);
		for(; i < qs->SizeOfDataBase && j < wLength; i++) {
			if (*(WORD *)qdb == wDelimiter)
				j++;
			(WORD *)qdb += 1;
		}
		if (j != wLength)
			return FALSE;
	} else if (qs->Flags & FLAG_DELIMITER_DWORD) {
		dwDelimiter = (DWORD)(qs->SpecificDelimiter & 0xffffffff);
		for(; i < qs->SizeOfDataBase && j < wLength; i++) {
			if (*(DWORD *)qdb == dwDelimiter)
				j++;
			(DWORD *)qdb += 1;
		}
		if (j != wLength)
			return FALSE;
	} else {
		return FALSE;
	}

	addr += i;
	(DWORD)*ptr = addr;
	return TRUE;
}