/*****
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   qyt.h

Abstract:

   Qurey interface format template.

------
   AUTHOR: HyunJun Jeong  2015-01-21

******/

#ifndef _QYT_
#define _QYT_

#define IN
#define OUT
#define INTERNAL

#include "type.h"
#include "se.h"
#include <time.h>
#include <stdio.h>

#define QYT_STRMAX_LENGTH	10

#define IMAGE_QUREY_MAGIC	(WORD)(0x514C)

typedef struct _qyt_entry_ {
	WORD Magic;
	time_t CreationStamp;
	time_t LastestStamp;
	QUREY_SECURITY QureySecurity;
	BOOL ReadOnly;
	char Author[QYT_STRMAX_LENGTH];
	DWORD ClusterStatementAddr;
}	QUREY_ENTRY, *PQUREY_ENTRY;

#define DEFAULT_CLUSTERNADDR			sizeof(QUREY_ENTRY)

typedef struct _qyt_table_cluster_ {
	WORD ClusterID;
	char ClusterName[QYT_STRMAX_LENGTH];
	WORD NumberOfTable;
	DWORD HeadAddrOfTable;
}	QUREY_CLUSTER, *PQUREY_CLUSTER;

typedef struct _qyt_table_ {
	WORD TableID;
	char TableName[QYT_STRMAX_LENGTH];
	WORD NumberOfSection;
	DWORD HeadAddrOfSection;
}	QUREY_TABLE, *PQUREY_TABLE;

typedef struct _qyt_section_ {
	WORD SectionID;
	char SectionName[QYT_STRMAX_LENGTH];
	SECURITY_DATA SecurityData;
	BYTE Flags;
	BYTE SectionDataType;
	DWORD SpecificDelimiter;
	DWORD SizeOfDataBase;
	DWORD HeadAddrOfDataBase;
}	QUREY_SECTION, *PQUREY_SECTION;

#define SECTION_DATATYPE_BINARY		0
#define SECTION_DATATYPE_STRING		1
#define SECTION_DATATYPE_LIST		2
#define SECTION_DATATYPE_INTEGER	3
#define SECTION_DATATYPE_LONGINT	4
#define SECTION_DATATYPE_DATE		5

#ifndef _FLAGS_MAKE /* !_FLAGS_MAKE */
#define _FLAGS_MAKE(c, s)			(s << c)
#endif

	// Flag = 0는 기본 설정사항입니다.

	// Endian 타입
#define FLAG_LITTLEENDIAN			_FLAGS_MAKE(0,0)
#define FLAG_BIGENDIAN				_FLAGS_MAKE(0,1)

	// 구분자 사용여부
#define FLAG_LOCKDELIMITER			_FLAGS_MAKE(1,0)	// 사용않함
#define FLAG_UNLOCKDELIMITER		_FLAGS_MAKE(1,1)

	// 구분자
#define FLAG_DELIMITER_BYTE			_FLAGS_MAKE(2,1)
#define FLAG_DELIMITER_WORD			_FLAGS_MAKE(3,1)
#define FLAG_DELIMITER_DWORD		_FLAGS_MAKE(4,1)

BOOL LdrEntry(FILE *fp, OUT PQUREY_ENTRY *ptr);
BOOL LdrCluster(FILE *fp, DWORD dwAddr, OUT PQUREY_CLUSTER *ptr);
BOOL LdrTable(FILE *fp, DWORD dwAddr, WORD wCount, OUT PQUREY_TABLE **ptr);
BOOL LdrSectionFromTable(FILE *fp, PQUREY_TABLE pqt,  OUT PQUREY_SECTION **ptr);

BOOL SvrEntry(FILE *fp, PQUREY_ENTRY ptr);
BOOL SvrCluster(FILE *fp, DWORD dwAddr, PQUREY_CLUSTER ptr);
BOOL SvrTable(FILE *fp, DWORD dwAddr, WORD wCount, PQUREY_TABLE *ptr);
BOOL SvrSection(FILE *fp, DWORD dwAddr, WORD wCount, PQUREY_SECTION *ptr);

BOOL QryTableWithId(PQUREY_TABLE *qt, WORD wId, WORD wNumberOfTable, 
	OUT PQUREY_TABLE *ptr);
BOOL QryTableWithName(PQUREY_TABLE *qt, const char chpName[QYT_STRMAX_LENGTH], 
	WORD wNumberOfTable, OUT PQUREY_TABLE *ptr);

typedef struct _tag_db_bin_ *QUREY_DBBINARY;
typedef struct _tag_db_bin_ *QUREY_DBSTRING;

#endif