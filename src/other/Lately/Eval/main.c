/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   main.c - [Private]

Project:

   RollRat Eval

------
   AUTHOR: HyunJun Jeong  2015-01-25

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


#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "rocket.h"

#include "adjust.h"

#define _LEAK_TEST
#include "leak.h"

#include "sort.h"

int main(int argc, char *argv[])
{
	char x[] = "[asdf]+[^\\w]+[\\d]+      ";
	char *xt = x;

	_DeRtck_init();

	//DropRegexSideScope(&t, '3');

	//AdjustEqualCharacter(&t, ':');
	//AdjustPreCharacter(&t, ':');

	//DropStartsWith(x, "[^[");
	
	AdjustRightTrim(&xt);

	DropRegexGlobal(x, "asdfasdf*2655");

	Split("asdfwexcfwe32546fwexcvzcv", "fwe")[2];

	DropEndsWith("asdfasdfasdfzxcvetqwfdzxcvcxbqfdg", "asdfasdfasdfzxcvetqwfdzxcvcxbqfdg");
	printf("%s", Split("asdfwexcfwe32546fwexcvzcv", "fwe")[2]);

	EvalCompareString("adsfasdfcxvzxcvzxcv", "adsfasdfcxvzxcvzxcv1", 20);

	{
		int i;
		char **ptr = (char **)malloc(sizeof(char *) * 4);
		ptr[0] = "alasdjlvkcxnvlk";
		ptr[1] = "zxcvcbjklkdfjgs";
		ptr[2] = "akxlvjrlnlksdff";
		ptr[3] = "zxcvdgjklkdfjgs";
		EvalQuickSort(ptr, 4, sizeof(char *), EvalInternalCompareString);
		//EvalSortArrayUp(ptr, 4);
		for (i = 0; i < 4; i++)
			printf("%s\n", ptr[i]);
	}

	_DeRtck_print_all();
	//_DeRtck_print_nfree();
	_DeRtck_reset();

	return 0;
}
