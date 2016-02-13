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
	time_t CreationStamp;			// 생성일자
	time_t LastestStamp;			// 최근 액세스일자
	//QUREY_SECURITY QureySecurity;	// 독립쿼리 보호
	BOOL ReadOnly;					// 쓰기 불가능
	char Author[QYT_STRMAX_LENGTH];	// 쿼리 작성자
	DWORD ClusterStatementAddr;		// 클러스터 시작 주소
}	QUREY_ENTRY, *PQUREY_ENTRY;

#define DEFAULT_CLUSTERNADDR			sizeof(QUREY_ENTRY)
#define DEFAULT_TABLEADDR				DEFAULT_CLUSTERNADDR+sizeof(QUREY_ENTRY)
#define DEFAULT_SECTIONADDR				DEFAULT_TABLEADDR+sizeof(QUREY_TABLE)

typedef struct _qyt_table_cluster_ {
	WORD ClusterID;							// 클러스터 아이디
	char ClusterName[QYT_STRMAX_LENGTH];	// 클러스터 이름
	WORD NumberOfTable;						// 클러스터에 포함된 테이블 수
	DWORD HeadAddrOfTable;					// 테이플 시작 주소
}	QUREY_CLUSTER, *PQUREY_CLUSTER;

typedef struct _qyt_table_ {
	WORD TableID;							// 테이블 아이디
	char TableName[QYT_STRMAX_LENGTH];		// 테이블 이름
	WORD NumberOfSection;					// 테이플에 포함된 섹션개수
	DWORD HeadAddrOfSection;				// 섹션 시작 주소
}	QUREY_TABLE, *PQUREY_TABLE;

typedef struct _qyt_section_ {
	WORD SectionID;							// 섹션 아이디
	char SectionName[QYT_STRMAX_LENGTH];	// 섹션 이름
	//SECURITY_DATA SecurityData;				// 보안정보
	BYTE Flags;								// 플래그
	BYTE SectionDataType;					// 섹샨 데이터 타입
	DWORD SpecificDelimiter;				// 구분자
	DWORD SizeOfDataBase;					// 데이터크기
	DWORD HeadAddrOfDataBase;				// 데이터베이스 시작주소
	DWORD TailAddrOfDataBase;				// 데이터베이스 끝주소
}	QUREY_SECTION, *PQUREY_SECTION;

#define SECTION_DATATYPE_BINARY		0
#define SECTION_DATATYPE_STRING		1
#define SECTION_DATATYPE_LIST		2
#define SECTION_DATATYPE_INTEGER	3
#define SECTION_DATATYPE_LONGINT	4
#define SECTION_DATATYPE_DATE		5
#define SECTION_DATATYPE_FILE		6

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

typedef struct _table_list {
	char *qt;
	struct _table_list *next;
}	TABLE_LIST, *PTABLE_LIST;

BOOL LdrEntry(FILE *fp, OUT PQUREY_ENTRY *ptr);
BOOL LdrCluster(FILE *fp, DWORD dwAddr, OUT PQUREY_CLUSTER *ptr);
BOOL LdrTable(FILE *fp, DWORD dwAddr, WORD wCount, OUT PQUREY_TABLE **ptr);
BOOL LdrSectionFromTable(FILE *fp, PQUREY_TABLE pqt,  OUT PQUREY_SECTION **ptr);

BOOL SvrEntry(FILE *fp, PQUREY_ENTRY ptr);
BOOL SvrCluster(FILE *fp, DWORD dwAddr, PQUREY_CLUSTER ptr);
BOOL SvrTable(FILE *fp, DWORD dwAddr, PTABLE_LIST *ptr);
BOOL SvrSection(FILE *fp, DWORD dwAddr, WORD wCount, PQUREY_SECTION *ptr);

BOOL QryTableWithId(PQUREY_TABLE *qt, WORD wId, WORD wNumberOfTable, 
	OUT PQUREY_TABLE *ptr);
BOOL QryTableWithName(PQUREY_TABLE *qt, const char chpName[QYT_STRMAX_LENGTH], 
	WORD wNumberOfTable, OUT PQUREY_TABLE *ptr);

BOOL InitQureyEntry(OUT PQUREY_ENTRY *p_qe, IN const char *_author);
BOOL InitQureySecurityDefault(OUT QUREY_SECURITY *p_qs);
BOOL InitQureyCluster(OUT PQUREY_CLUSTER *p_qc, IN WORD _id, IN const char *_name);
BOOL InitTable(OUT PQUREY_TABLE *p_qt, IN WORD _id, IN const char *_name);

typedef struct _tag_db_bin_ *QUREY_DBBINARY;
typedef struct _tag_db_bin_ *QUREY_DBSTRING;

BOOL TListInit(OUT PTABLE_LIST *p_tl, IN char *qt);
BOOL TListPushBack(OUT PTABLE_LIST tl, IN PQUREY_TABLE qt);

#endif