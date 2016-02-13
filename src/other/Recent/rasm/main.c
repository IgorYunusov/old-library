/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   main.c - [Private]

Project:

   Robust Assembler (RASM)

------
   AUTHOR: HyunJun Jeong  2015-01-05

***************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <time.h>
#include <intrin.h>
#include <stdlib.h>
#include <fcntl.h>
#include <io.h>
#include <errno.h>
#include <sys/types.h>
#include <memory.h>
#include <sys/stat.h>
#include "reg.h"

#define _LEAK_TEST
#include "leak.h"

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "rocket.h"

#include "adjust.h"


unsigned long long combination(unsigned long long n, unsigned long long r)
{
	unsigned long long ret, set;
	if (n / 2 < r)
		return combination(n, n - r);
	if (r == 0 || n == r)
		return 1;
	else if (r == 1 || n - r == 1)
		return n;
	for (ret = 1, set = r; set; n--, set--)
		ret *= n;
	for (; r; r--)
		ret /= r;
	return ret;
}

perm(n, r) {
	return r ? n * perm(n - 1, r - 1) : 1;
}

fact(n) {
	return n ? n * fact(n - 1) : 1;
}

combi(n, r) {
	auto sr = n / 2 < r ? n - r : r;
	return n != r && r ? perm(n, sr) / fact(sr) : 1;
}

printn(n, b) {
	extern putchar();
	auto a;
	if (a = n / b)
		printn(a, b);
	putchar(n % b + '0');
}



unsigned long long combination1(unsigned long long n, unsigned long long r)
{
	double ret, set;
	if (n / 2 < r)
		return combination(n, n - r);
	if (r == 0 || n == r)
		return 1;
	else if (r == 1 || n - r == 1)
		return n;
	for (ret = 1, set = r; set; n--, set--)
		ret *= n/set;
	return ret;
}

int main(int argc, char *argv[])
{
	/*BYTE x[32];
	size_t tx = 0;
	BYTE *tty;
	const char *t = "roll";

	sscanft("0123456.456789", "%f");

	__asm {
		mov	edx,4		; message length
		mov	ecx,t		; message to write
		mov	ebx,1		; file descriptor (stdout)
		mov	eax,4		; system call number (sys_write)
		int 0x00f6
	}

	printf("%d", combi(5,3));

	printn(51354, 16);
	memset(x, 0, 32);

	ParseRegister("0CCCCh");
	ParseRegister("$si");

	_DeRtck_init();
	tty = (BYTE *)calloc(32, sizeof(BYTE));

	free(tty);
	tty = (BYTE *)calloc(32, sizeof(BYTE));

	_DeRtck_print_nfree();

	_DeRtck_reset();*/
	char x[] = "[^[:alnum:]]";
	char *t = x;

	DropRegexSideScope(&t, '3');

	//AdjustEqualCharacter(&t, ':');
	AdjustPreCharacter(&t, ':');

	return 0;
}