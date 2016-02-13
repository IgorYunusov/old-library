/*************************************************************************
 *
 *                    ROLLRAT AUTO PERSONA VERBOTER LIBROFEX
 *								DE RESEARCH PAPER
 *
 *                         (C) Copyright 2009-2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _RXHIO
#define _RXHIO

int ReadFileData(
	void * buffer,
	FILE *fp
	);

int CopyFileData(
	FILE *fp_target,
	FILE *fp_sniper
	);

int GetFileSize(
	FILE *fp
	);

#endif