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

#include <stdio.h>

#include "rxhfile.h"

int GetFileSize(
	FILE *fp
	)
/* Get File Size */
{
	fseek(fp, 0, SEEK_END);
	return ftell(fp);
}

int ReadFileData(
	void * buffer,
	FILE *fp
	)
/* Read File Data */
{
	int file_size;

	file_size = GetFileSize(fp);

	fseek(fp, 0, SEEK_SET);
	fread(buffer, file_size, 1, fp);

	return 0;
}

int CopyFileData(
	FILE *fp_target,
	FILE *fp_sniper
	)
/* Copy File Data */
{
	char buf[0x400];

	while(!feof(fp_target))

		fgets(buf, 0x400, fp_target),

		fputs(buf, fp_sniper);

	return 0;
}