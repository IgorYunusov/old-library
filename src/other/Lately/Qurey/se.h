/*****
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   se.h

Abstract:

   Qurey security management.

------
   AUTHOR: HyunJun Jeong  2015-01-21

******/

#ifndef _SE_
#define _SE_

#include "type.h"

#define SE_STRMAX_LENGTH	32

typedef struct _qyt_512bit_ {
	DWORD e_dword1;
	DWORD e_dword2;
	DWORD e_dword3;
	DWORD e_dword4;
	DWORD e_dword5;
	DWORD e_dword6;
	DWORD e_dword7;
	DWORD e_dword8;
	DWORD e_dword9;
	DWORD e_dword10;
	DWORD e_dword11;
	DWORD e_dword12;
	DWORD e_dword13;
	DWORD e_dword14;
	DWORD e_dword15;
	DWORD e_dword16;
}	SECURITY_512, *PSECURITY_512;

typedef struct _qyt_security_ {
	DWORD CheckSum;
	BOOL Locked;				// 파일열기를 금지함
	BYTE SecurityType;
	DWORD Version;
	DWORD VersionSecurityKey;
	BYTE LockWithReWrite;		// 수정금지
	BYTE LockType;
	SECURITY_512 SeProPass;
	DWORD EasyPass;				// 간단한 숫자로 파일을 잠그는 경우
}	QUREY_SECURITY, *PQUREY_SECURITY;

#define SECURITY_LOCK_NONE			0
#define SECURITY_LOCK_SHA128		1
#define SECURITY_LOCK_SHA256		2
#define SECURITY_LOCK_SHA512		3
#define SECURITY_LOCK_MD4			4
#define SECURITY_LOCK_MD5			5
#define SECURITY_LOCK_HAS160		6
#define SECURITY_LOCK_EASY			7

typedef struct _qyt_datasecurity_ {
	BOOL UsingDataSecurity;
	BYTE SecurityType;
	DWORD RandomHashVersionInfo;
	SECURITY_512 SeProPassWithVersionInfo;
	const char PassWord[SE_STRMAX_LENGTH];
}	SECURITY_DATA, *PSECURITY_DATA;

#define SECURITY_DATA_AES128		0
#define SECURITY_DATA_AES256		1
#define SECURITY_DATA_AES512		2
#define SECURITY_DATA_XOR32			3
#define SECURITY_DATA_XOR64			4
#define SECURITY_DATA_RC5			5
#define SECURITY_DATA_IDEA			6

#endif