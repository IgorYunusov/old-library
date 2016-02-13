/*************************************************************************
 *
 * FILE NAME : main.c
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
#include <inttypes.h>
#include <time.h>
#include <intrin.h>
#include <stdlib.h>
#include <fcntl.h>
#include <io.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "rasm.h"
#include "version.h"
#include "type.h"
#include "assemble.h"
#include "test.h"

static time_t _rasm_begin_time;
static time_t _rasm_end_time;

static FILE *_rasm_input_file;
static FILE *_rasm_output_file;

static u32 give_code[5];

static Option rasm_option;

static u32 emer_end;

static void rasm_echo()
{
	printf("RollRat Robust Assembler - Version " _RASM_VERSION_STRING "\n");
	printf("Copyright (c) 2015. rollrat. All rights reserved.\n\n");
}

static void rasm_echo_help()
{
	printf("RASM Option\n");
	printf("\n");
	printf("\tFile set option\n");
	printf("\t\t-o : Set output file with next cmd\n");
	printf("\t\t-i : Set input file with next cmd\n");
	printf("\n");
	printf("\tAssembler option\n");
	printf("\t\t/N : Assemble code in native mode\n");
	printf("\t\t/S : Assemble code in Shell-Code mode\n");
	printf("\t\t/E : Assemble code in Excuate mode\n");
	printf("\t\t/b : Force set output with big endian\n");
	printf("\t\t/s : Force set output with small endian\n");
	printf("\n");
}

static void rasm_emergency_error(const char *t, const char *s)
{
	printf("%s%s", t, s);
	emer_end = TRUE;
}

static void set_cpu()
{
#if USING_COMPILER == 1
	u32 a, b;
	for (a = 0; a < 5; a++) {
		__asm__("cpuid;"
		        :"=a"(b)
		        :"0"(a)
		        :"%ebx","%ecx","%edx");
		give_code[a] = b;
	}
#elif USING_COMPILER == 2 || USING_COMPILER == 3
	__asm {
		mov eax, 0
		cpuid
		mov give_code[0], eax
		mov give_code[1], ecx
		mov give_code[2], edx
		mov give_code[3], ebx
		mov give_code[4], 0
	}
#endif
}

static void init_option()
{
	rasm_option.assembly_type = RASM_OPTION_ASSEMBLY_TYPE_SHELLCODE;
	rasm_option.endian = RASM_OPTION_SMALLENDIAN;
	_rasm_input_file = 0;
	_rasm_output_file = 0;
	emer_end = FALSE;
}

static void parse_cmdline(int argc, char *argv[])
{
	BOOL input, output, lock_input, lock_output;
	int f = 1;
	input = FALSE;
	output = FALSE;
	lock_input = FALSE;
	lock_output = FALSE;

	if(argc == 1) {
		rasm_echo_help();
		emer_end = TRUE;
		return 0;
	}

	for(; f<argc; f++) {
		if(*argv[f] == '/') {
			switch(*(argv[f]+1))
			{
			case 'N': rasm_option.assembly_type = RASM_OPTION_ASSEMBLY_TYPE_NATIVE; break;
			case 'S': rasm_option.assembly_type = RASM_OPTION_ASSEMBLY_TYPE_SHELLCODE; break;
			case 'E': rasm_option.assembly_type = RASM_OPTION_ASSEMBLY_TYPE_EXCUATE; break;
			case 'b': rasm_option.endian = RASM_OPTION_BIGENDIAN; break;
			case 's': rasm_option.endian = RASM_OPTION_SMALLENDIAN; break;

			default:
				rasm_emergency_error("Cannot find option!\nCommand: ", argv[f]);
				return;
			}
			
		} else if (input == TRUE && lock_input == FALSE) {
			fopen_s(&_rasm_input_file, argv[f], "r");
			if(!_rasm_input_file) {
				rasm_emergency_error("Cannot find source file!\nFile name:", argv[f]); return; }
			lock_input = TRUE;
			input = FALSE;
		} else if (output == TRUE && lock_output == FALSE) {
			fopen_s(&_rasm_output_file, argv[f], "r");
			if(!_rasm_output_file) {
				rasm_emergency_error("Cannot find target file!\nFile name:", argv[f]); return; }
			lock_output = TRUE;
			output = FALSE;
		} else if(*argv[f] == '-') {
			switch(*(argv[f]+1))
			{
			case 'o': output = TRUE; break;
			case 'i': input = TRUE; break;
			default:
				rasm_emergency_error("Cannot find option!\nCommand: ", argv[f]);
				return;
			}
		}
	}
	if (_rasm_input_file == 0 || _rasm_output_file == 0)
		rasm_emergency_error("\nCheck cmd line option, not find input or output target file!","");
}

static void rasm_start()
{
	char line[256];
	size_t bytesize;
	BYTE *bytes;
	u32 error_n;
	while(fgets(line, sizeof(line), _rasm_input_file)) {
		if(!(bytes = rasm_assemble_code(line, &rasm_option, 0, &bytesize, &error_n)))
			continue;
	}
}

int main(int argc, char *argv[])
{
#if _DEBUGGING_MODE == 1

	__asm {
		/*
		C1 C0 00             rol         eax,0  
		C1 C8 00             ror         eax,0  
		C1 D0 00             rcl         eax,0  
		C1 D8 00             rcr         eax,0  
		C1 E0 00             shl         eax,0  
		C1 E8 00             shr         eax,0  
		C1 F8 00             sar         eax,0  

		C1 C1 FF             rol         ecx,0FFh
		C1 C9 0F             ror         ecx,0Fh 
		C1 D1 0F             rcl         ecx,0Fh 
		C1 D9 0F             rcr         ecx,0Fh 
		C1 E1 0F             shl         ecx,0Fh 
		C1 E9 0F             shr         ecx,0Fh 
		C1 F9 0F             sar         ecx,0Fh 

		D1 C0                rol         eax,1  
		D1 C8                ror         eax,1  
		D1 D0                rcl         eax,1  
		D1 D8                rcr         eax,1  
		D1 E0                shl         eax,1  
		D1 E8                shr         eax,1  
		D1 F8                sar         eax,1  

		C1 C0 02             rol         eax,2  
		C1 C8 02             ror         eax,2  
		C1 D0 02             rcl         eax,2  
		C1 D8 02             rcr         eax,2  
		C1 E0 02             shl         eax,2  
		C1 E8 02             shr         eax,2  
		C1 F8 02             sar         eax,2  

		66 D1 C0             rol         ax,1  
		66 C1 C0 00          rol         ax,0  
		C0 C0 00             rol         al,0  
		D0 C0                rol         al,1  
		C0 C4 00             rol         ah,0  
		D0 C4                rol         ah,1  
		66 D1 C1             rol         cx,1  
		66 C1 C1 00          rol         cx,0  
		C0 C1 00             rol         cl,0  
		D0 C1                rol         cl,1  
		C0 C5 00             rol         ch,0  
		D0 C5                rol         ch,1  
		*/
		mov eax, [eax+4]
	}
	
	/*set = (BYTE *)malloc(sizeof(BYTE) * 32);
	ptr = rasm_assemble_code("@add $eax, -126", 0, 0, &s1, &s2);
	for (i = 0; i < s1; i++) set[i] = ptr[i];
	rasm_test(set, s1, 0);*/
	rasm_test_line_full("@add $eax, $[ebp-3]");
	rasm_test_line_full("@add $ebx, $[eax*2]");
	rasm_test_line_full("@add $ebx, 80000000h");
	rasm_test_line_full("@add $al,  10h");
	rasm_test_line_full("@add $esi, 00000075h");

	argc = 3;
	argv[1] = "-o";
	argv[2] = "c:\\rollrat\\test1.asm";

#endif

	rasm_echo();
	set_cpu();

	time(&_rasm_begin_time);

	init_option();
	parse_cmdline(argc, argv);
	if (emer_end || _rasm_input_file == 0 || _rasm_output_file == 0)
		return 1;

	rasm_assemble_init(&rasm_option);

	if(rasm_option.assembly_type == RASM_OPTION_ASSEMBLY_TYPE_SHELLCODE) {

		rasm_start();
	}

	time(&_rasm_end_time);

	return 0;
}