/*************************************************************************
 *
 * FILE NAME : main.h - Entry Point
 *
 * RollRat Compiler x4 Language Invention Compiler 
 *
 *
 * CREATION : 2014.12.23
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include "elc.h"
#include "rocket.h"
#include "costume.h"
#include "utility.h"

int main(int argc, char *argv[])
{
	char x[50];
	//zeroset(x, 50);
	/*
		;
		@c=%length%
		?(3<c&c<10)
			@d=5
		:
			@d=4
		/
		$x="kktu"
		/
		$x1=[
			*^!s
			+@d
			*!s
			+*^!s
			+$x
			]
		+$x1
		;
	*/
	//process_costume("cc, ccc ", x, ";@c=%length%?(3<c&c<10)@d=5:@d=4/$x=\"kktu\"/$x1=[*^!s+@d*!s+*^!s+$x]+$x1;");
	//printf("%s", x);
	
	char xt[50];
	char *t = xt;
	//zeroset(xt, 50);
	strcpy_s(xt, 50, "xxt \nttx\n\rtyx");
	_util_move_next_line(&t);
	printf("%s", t);
	_util_move_next_line(&t);
	printf("%s", t);
	strcpy_s(xt, 50, "rrsadfasdfasdf");
	t = xt;
	_util_find_strchr(&t, "zxcav");
	printf("\n%s", t);
	strcpy_s(xt, 50, "!@#$#@%@%#$%1^^^^%^%qwerasdf");
	t = xt;
	_util_find_function(&t, _isalnum);
	printf("\n%s", t);
	return 0;
}