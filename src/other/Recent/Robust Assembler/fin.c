/*************************************************************************
 *
 * FILE NAME : fin.c - File Input Management
 *
 * ROLLRAT SOFTWARE Robust Assembler (RASM)
 *
 *
 * LANGUAGE : ANSI C
 * CREATION : 2015.01.02
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com, rollrat.software@gmail.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#include <stdio.h>
#include <malloc.h>

FILE *fin_open_file(const char *filename)
{ // file exist check
	FILE *fp;
	//fp = fopen(filename, "r");
	fopen_s(&fp, filename, "r");
	return fp;
}

void f_close_file(FILE *fp)
{
	fclose(fp);
}

char fin_getc(FILE *fp)
{
	char ret;
	ret = (char)fgetc(fp);
	return ret;
}

char *fin_gets(FILE *fp, size_t size)
{
	char *ret;
	ret = (char *)malloc(size);
	fgets(fp, size, fp);
	return ret;
}

void f_refresh(FILE *fp)
{
	rewind(fp);
}

size_t fin_file_size(FILE *fp)
{
	size_t ret;
	fseek(fp, 0, SEEK_END);
	ret = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	return ret;
}
