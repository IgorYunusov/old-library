/*************************************************************************
 *
 * FILE NAME : fout.c - File Output Management
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

FILE *fout_open_file(const char *filename)
{ // file exist check
	FILE *fp;
	fopen_s(&fp, filename, "w");
	return fp;
}

void fout_putc(FILE *fp, char ch)
{
	fputc((int)ch, fp);
}

void fout_puts(FILE *fp, char *str)
{
	fputs(str, fp);
}
