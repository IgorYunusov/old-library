#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "tasm_def.h"
#include "register.h"
#include "address.h"

_DATA _data_e[0xFF] = 
{
	{"and", FLAG_REG, FLAG_DATA, 0, 0}, 
	{"or", FLAG_REG, FLAG_DATA, 0, 0}, 
	{"xor", FLAG_REG, FLAG_DATA, 0, 0}, 
	{"add", FLAG_REG, FLAG_DATA, 0, 0}, 
	{"adc", FLAG_REG, FLAG_DATA, 0, 0}, 
	{"sub", FLAG_REG, FLAG_DATA, 0, 0}, 
	{"sbb", FLAG_REG, FLAG_DATA, 0, 0}, 
	{"mul", FLAG_REG, FLAG_DATA, 0, 0}, 
	{"div", FLAG_REG, FLAG_DATA, 0, 0},
	{"cmp", FLAG_REG, FLAG_DATA, 0, 0}, 
	{"shl", FLAG_REG, FLAG_DATA, 0, 0}, 
	{"shr", FLAG_REG, FLAG_DATA, 0, 0}, 

	{"and", FLAG_REG, FLAG_ADDR, 0, 0}, 
	{"or", FLAG_REG, FLAG_ADDR, 0, 0}, 
	{"xor", FLAG_REG, FLAG_ADDR, 0, 0}, 
	{"add", FLAG_REG, FLAG_ADDR, 0, 0}, 
	{"adc", FLAG_REG, FLAG_ADDR, 0, 0}, 
	{"sub", FLAG_REG, FLAG_ADDR, 0, 0}, 
	{"sbb", FLAG_REG, FLAG_ADDR, 0, 0}, 
	{"mul", FLAG_REG, FLAG_ADDR, 0, 0}, 
	{"div", FLAG_REG, FLAG_ADDR, 0, 0}, 
	{"cmp", FLAG_REG, FLAG_ADDR, 0, 0}, 
	{"shl", FLAG_REG, FLAG_ADDR, 0, 0}, 
	{"shr", FLAG_REG, FLAG_ADDR, 0, 0}, 

	{"and", FLAG_REG, FLAG_REG, 0, 0}, 
	{"or", FLAG_REG, FLAG_REG, 0, 0}, 
	{"xor", FLAG_REG, FLAG_REG, 0, 0}, 
	{"add", FLAG_REG, FLAG_REG, 0, 0}, 
	{"adc", FLAG_REG, FLAG_REG, 0, 0}, 
	{"sub", FLAG_REG, FLAG_REG, 0, 0}, 
	{"sbb", FLAG_REG, FLAG_REG, 0, 0}, 
	{"mul", FLAG_REG, FLAG_REG, 0, 0}, 
	{"div", FLAG_REG, FLAG_REG, 0, 0}, 
	{"cmp", FLAG_REG, FLAG_REG, 0, 0}, 
	{"shl", FLAG_REG, FLAG_REG, 0, 0}, 
	{"shr", FLAG_REG, FLAG_REG, 0, 0}, 

	// push <operator>
	// pop <operator>
	{"push", FLAG_REG, 0, EAX, 0},
	{"push", FLAG_REG, 0, ECX, 0},
	{"push", FLAG_REG, 0, EDX, 0},
	{"push", FLAG_REG, 0, EBX, 0},
	{"push", FLAG_REG, 0, ESP, 0},
	{"push", FLAG_REG, 0, EBP, 0},
	{"push", FLAG_REG, 0, ESI, 0},
	{"push", FLAG_REG, 0, EDI, 0},
	{"pop", FLAG_REG, 0, EAX, 0},
	{"pop", FLAG_REG, 0, ECX, 0},
	{"pop", FLAG_REG, 0, EDX, 0},
	{"pop", FLAG_REG, 0, EBX, 0},
	{"pop", FLAG_REG, 0, ESP, 0},
	{"pop", FLAG_REG, 0, EBP, 0},
	{"pop", FLAG_REG, 0, ESI, 0},
	{"pop", FLAG_REG, 0, EDI, 0},
	{"push", FLAG_ADDR, 0, 0, 0},

	// inc
	{"inc", FLAG_REG, 0, EAX, 0},
	{"inc", FLAG_REG, 0, ECX, 0},
	{"inc", FLAG_REG, 0, EDX, 0},
	{"inc", FLAG_REG, 0, EBX, 0},
	{"inc", FLAG_REG, 0, ESP, 0},
	{"inc", FLAG_REG, 0, EBP, 0},
	{"inc", FLAG_REG, 0, ESI, 0},
	{"inc", FLAG_REG, 0, EDI, 0},
	{"dec", FLAG_REG, 0, EAX, 0},
	{"dec", FLAG_REG, 0, ECX, 0},
	{"dec", FLAG_REG, 0, EDX, 0},
	{"dec", FLAG_REG, 0, EBX, 0},
	{"dec", FLAG_REG, 0, ESP, 0},
	{"dec", FLAG_REG, 0, EBP, 0},
	{"dec", FLAG_REG, 0, ESI, 0},
	{"dec", FLAG_REG, 0, EDI, 0},

	// mov
	{"mov", FLAG_REG, FLAG_ADDR, EAX, 0},
	{"mov", FLAG_REG, FLAG_ADDR, ECX, 0},
	{"mov", FLAG_REG, FLAG_ADDR, EDX, 0},
	{"mov", FLAG_REG, FLAG_ADDR, EBX, 0},
	{"mov", FLAG_REG, FLAG_ADDR, ESP, 0},
	{"mov", FLAG_REG, FLAG_ADDR, EBP, 0},
	{"mov", FLAG_REG, FLAG_ADDR, ESI, 0},
	{"mov", FLAG_REG, FLAG_ADDR, EDI, 0},
	{"mov", FLAG_ADDR, FLAG_REG, 0, EAX},
	{"mov", FLAG_ADDR, FLAG_REG, 0, ECX},
	{"mov", FLAG_ADDR, FLAG_REG, 0, EDX},
	{"mov", FLAG_ADDR, FLAG_REG, 0, EBX},
	{"mov", FLAG_ADDR, FLAG_REG, 0, ESP},
	{"mov", FLAG_ADDR, FLAG_REG, 0, EBP},
	{"mov", FLAG_ADDR, FLAG_REG, 0, ESI},
	{"mov", FLAG_ADDR, FLAG_REG, 0, EDI},
	{"mov", FLAG_REG, FLAG_REG, EAX, EAX},
	{"mov", FLAG_REG, FLAG_REG, ECX, ECX},
	{"mov", FLAG_REG, FLAG_REG, EDX, EDX},
	{"mov", FLAG_REG, FLAG_REG, EBX, EBX},
	{"mov", FLAG_REG, FLAG_REG, ESP, ESP},
	{"mov", FLAG_REG, FLAG_REG, EBP, EBP},
	{"mov", FLAG_REG, FLAG_REG, ESI, ESI},
	{"mov", FLAG_REG, FLAG_REG, EDI, EDI},

	// jump
	{"jo", FLAG_ADDR, 0, 0, 0},
	{"jno", FLAG_ADDR, 0, 0, 0},
	{"jb", FLAG_ADDR, 0, 0, 0},
	{"jnb", FLAG_ADDR, 0, 0, 0},
	{"jz", FLAG_ADDR, 0, 0, 0},
	{"jnz", FLAG_ADDR, 0, 0, 0},
	{"jbe", FLAG_ADDR, 0, 0, 0},
	{"ja", FLAG_ADDR, 0, 0, 0},
	{"js", FLAG_ADDR, 0, 0, 0},
	{"jnx", FLAG_ADDR, 0, 0, 0},
	{"jp", FLAG_ADDR, 0, 0, 0},
	{"jnp", FLAG_ADDR, 0, 0, 0},
	{"jl", FLAG_ADDR, 0, 0, 0},
	{"jnl", FLAG_ADDR, 0, 0, 0},
	{"jle", FLAG_ADDR, 0, 0, 0},
	{"jnle", FLAG_ADDR, 0, 0, 0},
	{"jmp", FLAG_ADDR, 0, 0, 0},

	{"call", FLAG_ADDR, 0, 0, 0},
	{"ret", 0, 0, 0, 0},

	{"lea", 0, 0, 0, 0},
	
	{"std", 0, 0, 0, 0},// http://bab2min.tistory.com/245
	{"cld", 0, 0, 0, 0},
	{"lodsd", 0, 0, 0, 0},
	{"stosd", 0, 0, 0, 0},

	{"pushf", FLAG_ADDR, 0, 0, 0},
	{"pusha", 0, 0, 0, 0},
	{"pop", FLAG_ADDR, 0, 0, 0},
	{"pop", 0, 0, 0, 0},

	{"nop", 0, 0, 0, 0},
	{"INT3", 0, 0, 0, 0},

};

void main_module(FILE *sfp, char *_Ptr)
{
	for (; isspace(*_Ptr); _Ptr++)
		;

	// 贸澜 林籍 贸府
	if (*_Ptr == ';')
		return;


}

void m_assembly(FILE *fp, FILE *sfp, int op1, int op2)
{
	char _Tmp[255];
	char *_Ptr;
	if( fp != NULL )
	{
		while( !feof(fp) )
		{
			_Ptr = fgets(_Tmp, sizeof(_Tmp), fp);
			main_module(sfp, _Ptr);
		}
		fclose(fp);
	}
}

#include <Windows.h>

int main(int argc, char * argv[])
{
	FILE *fp, *sfp;
	char* shell = "\xeb\x1e\x59\xb8\x04\x00\x00\x00\xbb\x01\x00\x00\x00\xba\x0f\x00\x00\x00\xcd\x80\xb8\x01\x00\x00\x00\xbb\x00\x00\x00\x00\xcd\x80\xe8\xdd\xff\xff\xff\x48\x65\x6c\x6c\x6f\x2c\x20\x57\x6f\x72\x6c\x64\x21\x0a\x00";
	void (*func)(void);
	char t[30];
	scanf("%s", &t);
	puts(get_register_big(t));
#ifdef _DEBUG
	fp = fopen("c:\\1.txt", "r");
	sfp = fopen("c:\\2.txt", "wb");
#else
	if (argc >= 2)
		return;
	if (*argv[1] != '/')
		return;
	if(*(argv[1] + 1) == 'A')
		fp = fopen(argv[2], "r");
#endif
	//m_assembly(fp, sfp, 0, 0);



	printf("%s", _data_e[0xCC].command);

	printf("%d", get_address_small("ffffffff"));

	func = VirtualAlloc(0, sizeof shell, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	memcpy(func, shell, sizeof shell);
 /*func = (void *)shell;*/
func();/*
	func = (int(*)())&shell;
 ((void(*)())func)();*/

	return 0;
}