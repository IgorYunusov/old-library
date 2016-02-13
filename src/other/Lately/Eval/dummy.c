/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   dummy.c - [Private]

Project:

   Robust Assembler (RASM)
   
Abstract:

   Test functions

------
   AUTHOR: HyunJun Jeong  2015-01-05

***************************************************************************/

int dummy0(int argc, char *argv[])
{
	char hash[32];
	int i = 0;
	memset(hash, 0, 32);

	//printf("%d\n", hash['a' ^ 'x'] = AX /* 25 */);
	//printf("%d\n", hash['a' ^ 'l'] = AL /* 13 */);
	//printf("%d\n", hash['a' ^ 'h'] = AH /*  9 */);
	//printf("%d\n", hash['b' ^ 'p'] = BP /* 18 */);
	//printf("%d\n", hash['b' ^ 'x'] = BX /* 26 */); //
	//printf("%d\n", hash['b' ^ 'l'] = BL /* 14 */);
	//printf("%d\n", hash['b' ^ 'h'] = BH /* 10 */);
	//printf("%d\n", hash['c' ^ 'x'] = CX /* 27 */);
	//printf("%d\n", hash['c' ^ 'l'] = CL /* 15 */);
	//printf("%d\n", hash['c' ^ 'h'] = CH /* 11 */);
	//printf("%d\n", hash['d' ^ 'i'] = DI /* 13 */);
	//printf("%d\n", hash['d' ^ 'x'] = DX /* 28 */);
	//printf("%d\n", hash['d' ^ 'l'] = DL /*  8 */);
	//printf("%d\n", hash['d' ^ 'h'] = DH /* 12 */);
	//printf("%d\n", hash['s' ^ 'p'] = SP /*  3 */);
	//printf("%d\n", hash['s' ^ 'i'] = SI /* 26 */); //

	//printf("%d\n", ('a' + 'x') );
	//printf("%d\n", ('a' + 'l') );
	//printf("%d\n", ('a' + 'h') );
	//printf("%d\n", ('b' + 'p') );
	//printf("%d\n", ('b' + 'x') ); //
	//printf("%d\n", ('b' + 'l') );
	//printf("%d\n", ('b' + 'h') );
	//printf("%d\n", ('c' + 'x') );
	//printf("%d\n", ('c' + 'l') );
	//printf("%d\n", ('c' + 'h') );
	//printf("%d\n", ('d' + 'i') );
	//printf("%d\n", ('d' + 'x') );
	//printf("%d\n", ('d' + 'l') );
	//printf("%d\n", ('d' + 'h') );
	//printf("%d\n", ('s' + 'p') );
	//printf("%d\n", ('s' + 'i') ); //

	ParseRegister("$eax");
	ParseRegister("$si");

	for (; i <= 'z'; i++)
		if ('a' <= i && i <= 'z')
			printf("\n\t%d, /* '%c' */", 0, i);
		else
			printf("%d,", 0);

	printf("\n %d", i);

	return 0;
}