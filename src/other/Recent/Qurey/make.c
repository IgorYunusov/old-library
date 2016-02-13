/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   make.c - [Private]
   
Abstract:

   Structure initialization method.

------
   AUTHOR: HyunJun Jeong  2015-05-13

***************************************************************************/

#include <stdio.h>
#include <string.h>
#include "type.h"
#include "qyt.h"
#include <malloc.h>
#include <time.h>

//////////////////////////////////////////
//
//			ÃÊ±âÈ­
//
//////////////////////////////////////////

BOOL InitQureyEntry(
	OUT PQUREY_ENTRY *p_qe,
	IN const char *_author
	)
{
	PQUREY_ENTRY p_qe_ret;
	time_t times;
	QUREY_SECURITY p_qs;
	size_t strlen_ts;

	p_qe_ret = (QUREY_ENTRY *)malloc(sizeof(QUREY_ENTRY));

	p_qe_ret->Magic = IMAGE_QUREY_MAGIC;

	memset(p_qe_ret->Author, 0, QYT_STRMAX_LENGTH);
	if ((strlen_ts = strlen(_author)) > QYT_STRMAX_LENGTH - 1)
		return FALSE;
	strcpy_s(p_qe_ret->Author, strlen_ts+1, _author);

	p_qe_ret->ClusterStatementAddr = DEFAULT_CLUSTERNADDR;

	time(&times);

	p_qe_ret->CreationStamp = times;
	p_qe_ret->LastestStamp = times;
	p_qe_ret->ReadOnly = FALSE;
	//InitQureySecurityDefault(&p_qs);
	//p_qe_ret->QureySecurity = p_qs;

	*p_qe = p_qe_ret;

	return TRUE;
}

BOOL InitQureySecurityDefault(
	OUT QUREY_SECURITY *p_qs
	)
{
	QUREY_SECURITY p_qs_ret;

	p_qs_ret.CheckSum = 0;
	p_qs_ret.Locked = FALSE;
	p_qs_ret.SecurityType = SECURITY_LOCK_NONE;

	*p_qs = p_qs_ret;
	return TRUE;
}

BOOL InitQureyCluster(
	OUT PQUREY_CLUSTER *p_qc,
	IN WORD _id,
	IN const char *_name
	)
{
	PQUREY_CLUSTER p_qc_ret;
	size_t strlen_ts;
	
	p_qc_ret = (PQUREY_CLUSTER *)malloc(sizeof(PQUREY_CLUSTER));
	p_qc_ret->ClusterID = _id;

	memset(p_qc_ret->ClusterName, 0, QYT_STRMAX_LENGTH);
	if ((strlen_ts = strlen(_name)) > QYT_STRMAX_LENGTH - 1)
		return FALSE;
	strcpy_s(p_qc_ret->ClusterName, strlen_ts+1, _name);

	p_qc_ret->NumberOfTable = 0;
	p_qc_ret->HeadAddrOfTable = DEFAULT_TABLEADDR;
	
	*p_qc = p_qc_ret;
	return TRUE;
}

BOOL InitTable(
	OUT PQUREY_TABLE *p_qt,
	IN WORD _id,
	IN const char *_name
	)
{
	PQUREY_TABLE p_qt_ret;
	size_t strlen_ts;
	
	p_qt_ret = (PQUREY_TABLE *)malloc(sizeof(PQUREY_TABLE));
	p_qt_ret->TableID = _id;

	memset(p_qt_ret->TableName, 0, QYT_STRMAX_LENGTH);
	if ((strlen_ts = strlen(_name)) > QYT_STRMAX_LENGTH - 1)
		return FALSE;
	strcpy_s(p_qt_ret->TableName, strlen_ts+1, _name);

	p_qt_ret->NumberOfSection = 0;
	p_qt_ret->HeadAddrOfSection = DEFAULT_SECTIONADDR;
	
	*p_qt = p_qt_ret;
	return TRUE;
}

//////////////////////////////////////////
//
//			»ðÀÔ
//
//////////////////////////////////////////