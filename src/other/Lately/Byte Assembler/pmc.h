/*************************************************************************
 *
 *					  ROLLRAT SOFTWARE LIBRARY [Private]
 *						PUT MACHINE CODE
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *[INSIDE METHOD]
 *************************************************************************/

#ifndef _PMC_
#define _PMC_

#include <Windows.h>

template<typename code = char, typename _func = void *> class
	pmc
	{
public:
	_func function;

	void Load(code *code, size_t size)
		{
		HANDLE mem_handle = CreateFileMapping( 
			INVALID_HANDLE_VALUE, 
			NULL, 
			PAGE_EXECUTE_READWRITE, 
			0,  
			size, 
			NULL);

		function = _func(MapViewOfFile( 
			mem_handle, 
			FILE_MAP_ALL_ACCESS | FILE_MAP_EXECUTE, 
			0, 
			0, 
			size));
		}

	void Call()
		{
		((_func(*)())function)();
		}

	};

typedef unsigned int			uint_t;
typedef unsigned long int		uint32_t;
typedef unsigned long long int	uint64_t;

#pragma pack (1)
	typedef struct REGISTERS
	{
		uint_t reg_EBX;
		uint_t reg_EDX;
		uint_t reg_ECX;
		uint_t reg_EAX;
		uint_t reg_EDI;
		uint_t reg_ESI;
		uint_t reg_Flags;
	} REGISTERS;
#pragma pack ()

// Accumulator for operands and results data
#define EAX		1

// EBX — Pointer to data in the DS segment
#define EBX		2

// ECX — Counter for string and loop operations
#define ECX		3

// EDX — I/O pointer
#define EDX		4

// ESI — Pointer to data in the segment pointed to by the DS register; source pointer for string operations
#define ESI		5

// EDI — Pointer to data (or destination) in the segment pointed to by the ES register; destination pointer for string operations
#define EDI		6

// ESP — Stack pointer (in the SS segment)
#define ESP		7

// EBP — Pointer to data on the stack (in the SS segment)
#define EBP		8

// Direct address: the instruction has no ModR/M byte; the address 
// of the operand is encoded in the instruction. No base register, 
// index register, or scaling factor can be applied (for example, far JMP (EA)).
#define A		9

// The VEX.vvvv field of the VEX prefix selects a general purpose register.
#define B		10

// The reg field of the ModR/M byte selects a control register 
// (for example, MOV (0F20, 0F22)).
#define C		11

// The reg field of the ModR/M byte selects a debug register (for example,
// MOV (0F21,0F23)).
#define D		12

// A ModR/M byte follows the opcode and specifies the operand. The 
// operand is either a general-purpose register or a memory address.
// If it is a memory address, the address is computed from a segment
// register and any of the following values: a base register, an 
// index register, a scaling factor, a displacement.
#define E		13

// EFLAGS/RFLAGS Register.
#define F		14

// The reg field of the ModR/M byte selects a general register (for example, AX (000)).
#define G		15

// The VEX.vvvv field of the VEX prefix selects a 128-bit XMM register
// or a 256-bit YMM register, determined by operand type. For legacy
// SSE encodings this operand does not exist, changing the instruction to destructive form.
#define H		16

// Immediate data: the operand value is encoded in subsequent bytes of the instruction.
#define I		17

// The instruction contains a relative offset to be added to the instruction 
// pointer register (for example, JMP(0E9), LOOP).
#define J		18

// The upper 4 bits of the 8-bit immediate selects a 128-bit XMM register 
// or a 256-bit YMM register, determined by operand type. (the MSB is ignored in 32-bit mode)
#define L		19

// The ModR/M byte may refer only to memory (for example, 
// BOUND, LES, LDS, LSS, LFS, LGS, CMPXCHG8B).
#define M		20

// The R/M field of the ModR/M byte selects a packed-quadword, MMX technology register.
#define N		21

// The instruction has no ModR/M byte. The offset of the operand is coded as a word or double word
// (depending on address size attribute) in the instruction. No base register, index register, or scaling factor
// can be applied (for example, MOV (A0–A3)).
#define O		22

// The reg field of the ModR/M byte selects a packed quadword MMX technology register.
#define P		23

// A ModR/M byte follows the opcode and specifies the operand. The operand is either an MMX technology
// register or a memory address. If it is a memory address, the address is computed from a segment register
// and any of the following values: a base register, an index register, a scaling factor, and a displacement.
#define Q		24

// The R/M field of the ModR/M byte may refer only to a general register (for example, MOV (0F20-0F23)).
#define R		25

// The reg field of the ModR/M byte selects a segment register (for example, MOV (8C,8E)).
#define S		26

// The R/M field of the ModR/M byte selects a 128-bit XMM register or a 256-bit YMM 
// register, determined by operand type.
#define U		27

// The reg field of the ModR/M byte selects a 128-bit XMM register or a 256-bit YMM
// register, determined by operand type.
#define V		28

// A ModR/M byte follows the opcode and specifies the operand. The operand is either a 128-bit XMM register,
// a 256-bit YMM register (determined by operand type), or a memory address. If it is a memory address, the
// address is computed from a segment register and any of the following values: a base register, an index
// register, a scaling factor, and a displacement.
#define W		29

// Memory addressed by the DS:rSI register pair (for example, MOVS, CMPS, OUTS, or LODS).
#define X		30

// Memory addressed by the ES:rDI register pair (for example, MOVS, CMPS, INS, STOS, or SCAS).
#define Y		31

// Two one-word operands in memory or two double-word operands in memory, depending on operand-size
// attribute (used only by the BOUND instruction).
#define a		32

// Byte, regardless of operand-size attribute.
#define b		33

// Byte or word, depending on operand-size attribute.
#define c		34

// Doubleword, regardless of operand-size attribute.
#define d		35

// Double-quadword, regardless of operand-size attribute.
#define dq		36

// 32-bit, 48-bit, or 80-bit pointer, depending on operand-size attribute.
#define p		37

// 128-bit or 256-bit packed double-precision floating-point data.
#define pd		38

// Quadword MMX technology register (for example: mm0).
#define pi		39

// 128-bit or 256-bit packed single-precision floating-point data.
#define ps		40

// Quadword, regardless of operand-size attribute.
#define q		41

// Quad-Quadword (256-bits), regardless of operand-size attribute.
#define qq		42

// 6-byte or 10-byte pseudo-descriptor.
#define s		43

// Scalar element of a 128-bit double-precision floating data.
#define sd		44

// Scalar element of a 128-bit single-precision floating data.
#define ss		45

// Doubleword integer register (for example: eax).
#define si		46

// Word, doubleword or quadword (in 64-bit mode), depending on operand-size attribute.
#define v		47

// Word, regardless of operand-size attribute.
#define w		48

// dq or qq based on the operand-size attribute.
#define x		49

// Doubleword or quadword (in 64-bit mode), depending on operand-size attribute.
#define y		50

// Word for 16-bit operand-size or doubleword for 32 or 64-bit operand-size.
#define z		51

const char *RegisterServe[3][9] = {
	{ "AL", "CL", "DL", "BL", "AH", "CH", "DH", "BH", "R8"  },
	{ "AX", "CX", "DX", "BX", "SP", "BP", "SI", "DI", "R16" },
	{ "EAX","ECX","EDX","EBX","ESP","EBP","ESI","EDI","R32" } };

const char *SegmentRegisterServe[6] = {
	"ES","CS","SS","DS","FS","GS"};

#define ES		26
#define CS		27
#define SS		28
#define DS		29
#define FS		30
#define GS		31

#define MakeModRM(mod, rm, reg)		rm & 0xfff | ((reg & 0xfff) << 3) | ((mod & 0xff) << 6)

typedef struct x_operation {
	unsigned short command;
	int Operandc;
	char op1, op2;
	char op3, op4;
	char op5, op6;
	char *name;
}	x_operation;

const x_operation ServerTerrior[] = {
	{ 0x00,0x02,	E,b,	G,b,	0,0, 	"ADD"     },
	{ 0x01,0x02,	E,v,	G,v,	0,0,  	"ADD"     },
	{ 0x02,0x02,	G,b,	E,b,	0,0,  	"ADD"     },
	{ 0x03,0x02,	G,v,	E,v,	0,0,  	"ADD"     },
	{ 0x04,0x02,	A,L,	I,b,	0,0,  	"ADD"     },
	{ 0x05,0x02,	EAX,0, 	I,z,	0,0, 	"ADD"     },
	{ 0x06,0x01,	ES,0,	0,0,	0,0, 	"PUSH"    },
	{ 0x07,0x01,	ES,0,	0,0,	0,0, 	"POP"     },
	{ 0x08,0x02,	E,b,	G,b,	0,0,  	"OR"      },
	{ 0x09,0x02,	E,v,	G,v,	0,0,  	"OR"      },
	{ 0x0A,0x02,	G,b,	E,b,	0,0,  	"OR"      },
	{ 0x0B,0x02,	G,v,	E,v,	0,0,  	"OR"      },
	{ 0x0C,0x02,	A,L,	I,b,	0,0,  	"OR"      },
	{ 0x0D,0x02,	EAX,0, 	I,z,	0,0, 	"OR"      },
	{ 0x0E,0x01,	CS,0,	0,0,	0,0, 	"PUSH"    },
	{ 0x0F,0x00,	0,0,	0,0,	0,0, 	"TB"      },
	{ 0x10,0x02,	E,b,	G,b,	0,0, 	"ADC"     },
	{ 0x11,0x02,	E,v,	G,v,	0,0, 	"ADC"     },
	{ 0x12,0x02,	G,b,	E,b,	0,0, 	"ADC"     },
	{ 0x13,0x02,	G,v,	E,v,	0,0, 	"ADC"     },
	{ 0x14,0x02,	A,L,	I,b,	0,0, 	"ADC"     },
	{ 0x15,0x02,	EAX,0, 	I,z,	0,0,	"ADC"     },
	{ 0x16,0x01,	SS,0,	0,0,	0,0,	"PUSH"    },
	{ 0x17,0x01,	SS,0,	0,0,	0,0,	"POP"     },
	{ 0x18,0x02,	E,b,	G,b,	0,0, 	"SBB"     },
	{ 0x19,0x02,	E,v,	G,v,	0,0, 	"SBB"     },
	{ 0x1A,0x02,	G,b,	E,b,	0,0, 	"SBB"     },
	{ 0x1B,0x02,	G,v,	E,v,	0,0, 	"SBB"     },
	{ 0x1C,0x02,	A,L,	I,b,	0,0, 	"SBB"     },
	{ 0x1D,0x02,	EAX,0, 	I,z,	0,0,	"SBB"     },
	{ 0x1E,0x01,	DS,0,	0,0,	0,0,	"PUSH"    },
	{ 0x1F,0x01,	DS,0,	0,0,	0,0,	"POP"     },
	{ 0x20,0x02,	E,b,	G,b,	0,0, 	"AND"     },
	{ 0x21,0x02,	E,v,	G,v,	0,0, 	"AND"     },
	{ 0x22,0x02,	G,b,	E,b,	0,0, 	"AND"     },
	{ 0x23,0x02,	G,v,	E,v,	0,0, 	"AND"     },
	{ 0x24,0x02,	A,L,	I,b,	0,0, 	"AND"     },
	{ 0x25,0x02,	EAX,0, 	I,z,	0,0,	"AND"     },
	{ 0x26,0x00,	0,0,	0,0,	0,0,	"ES:"     },
	{ 0x27,0x00,	0,0,	0,0,	0,0,	"DAA"     },
	{ 0x28,0x02,	E,b,	G,b,	0,0, 	"SUB"     },
	{ 0x29,0x02,	E,v,	G,v,	0,0, 	"SUB"     },
	{ 0x2A,0x02,	G,b,	E,b,	0,0, 	"SUB"     },
	{ 0x2B,0x02,	G,v,	E,v,	0,0, 	"SUB"     },
	{ 0x2C,0x02,	A,L,	I,b,	0,0, 	"SUB"     },
	{ 0x2D,0x02,	EAX,0, 	I,z,	0,0,	"SUB"     },
	{ 0x2E,0x00,	0,0,	0,0,	0,0,	"CS:"     },
	{ 0x2F,0x00,	0,0,	0,0,	0,0,	"DAS"     },
	{ 0x30,0x02,	E,b,	G,b,	0,0, 	"XOR"     },
	{ 0x31,0x02,	E,v,	G,v,	0,0, 	"XOR"     },
	{ 0x32,0x02,	G,b,	E,b,	0,0, 	"XOR"     },
	{ 0x33,0x02,	G,v,	E,v,	0,0, 	"XOR"     },
	{ 0x34,0x02,	A,L,	I,b,	0,0, 	"XOR"     },
	{ 0x35,0x02,	EAX,0, 	I,z,	0,0,	"XOR"     },
	{ 0x36,0x00,	0,0,	0,0,	0,0,	"SS:"     },
	{ 0x37,0x00,	0,0,	0,0,	0,0,	"AAA"     },
	{ 0x38,0x02,	E,b,	G,b,	0,0, 	"CMP"     },
	{ 0x39,0x02,	E,v,	G,v,	0,0, 	"CMP"     },
	{ 0x3A,0x02,	G,b,	E,b,	0,0, 	"CMP"     },
	{ 0x3B,0x02,	G,v,	E,v,	0,0, 	"CMP"     },
	{ 0x3C,0x02,	A,L,	I,b,	0,0, 	"CMP"     },
	{ 0x3D,0x02,	EAX,0, 	I,z,	0,0,	"CMP"     },
	{ 0x3E,0x00,	0,0,	0,0,	0,0,	"DS:"     },
	{ 0x3F,0x00,	0,0,	0,0,	0,0,	"AAS"     },
	{ 0x40,0x01,	EAX,0,	0,0,	0,0,	"INC"     },
	{ 0x41,0x01,	ECX,0,	0,0,	0,0,	"INC"     },
	{ 0x42,0x01,	EDX,0,	0,0,	0,0,	"INC"     },
	{ 0x43,0x01,	EBX,0,	0,0,	0,0,	"INC"     },
	{ 0x44,0x01,	ESP,0,	0,0,	0,0,	"INC"     },
	{ 0x45,0x01,	EBP,0,	0,0,	0,0,	"INC"     },
	{ 0x46,0x01,	ESI,0,	0,0,	0,0,	"INC"     },
	{ 0x47,0x01,	EDI,0,	0,0,	0,0,	"INC"     },
	{ 0x48,0x01,	EAX,0,	0,0,	0,0,	"DEC"     },
	{ 0x49,0x01,	ECX,0,	0,0,	0,0,	"DEC"     },
	{ 0x4A,0x01,	EDX,0,	0,0,	0,0,	"DEC"     },
	{ 0x4B,0x01,	EBX,0,	0,0,	0,0,	"DEC"     },
	{ 0x4C,0x01,	ESP,0,	0,0,	0,0,	"DEC"     },
	{ 0x4D,0x01,	EBP,0,	0,0,	0,0,	"DEC"     },
	{ 0x4E,0x01,	ESI,0,	0,0,	0,0,	"DEC"     },
	{ 0x4F,0x01,	EDI,0,	0,0,	0,0,	"DEC"     },
	{ 0x50,0x01,	EAX,0,	0,0,	0,0,	"PUSH"    },
	{ 0x51,0x01,	ECX,0,	0,0,	0,0,	"PUSH"    },
	{ 0x52,0x01,	EDX,0,	0,0,	0,0,	"PUSH"    },
	{ 0x53,0x01,	EBX,0,	0,0,	0,0,	"PUSH"    },
	{ 0x54,0x01,	ESP,0,	0,0,	0,0,	"PUSH"    },
	{ 0x55,0x01,	EBP,0,	0,0,	0,0,	"PUSH"    },
	{ 0x56,0x01,	ESI,0,	0,0,	0,0,	"PUSH"    },
	{ 0x57,0x01,	EDI,0,	0,0,	0,0,	"PUSH"    },
	{ 0x58,0x01,	EAX,0,	0,0,	0,0,	"POP"     },
	{ 0x59,0x01,	ECX,0,	0,0,	0,0,	"POP"     },
	{ 0x5A,0x01,	EDX,0,	0,0,	0,0,	"POP"     },
	{ 0x5B,0x01,	EBX,0,	0,0,	0,0,	"POP"     },
	{ 0x5C,0x01,	ESP,0,	0,0,	0,0,	"POP"     },
	{ 0x5D,0x01,	EBP,0,	0,0,	0,0,	"POP"     },
	{ 0x5E,0x01,	ESI,0,	0,0,	0,0,	"POP"     },
	{ 0x5F,0x01,	EDI,0,	0,0,	0,0,	"POP"     },
	{ 0x60,0x00,	0,0,	0,0,	0,0,	"PUSHA"   },
	{ 0x61,0x00,	0,0,	0,0,	0,0,	"POPA"    },
	{ 0x62,0x02,	G,v,	M,a,	0,0,	"BOUND"   },
	{ 0x63,0x02,	E,w,	E,w,	0,0,	"ARPL"    },
	{ 0x64,0x00,	0,0,	0,0,	0,0,	"FS:"     },
	{ 0x65,0x00,	0,0,	0,0,	0,0,	"GS:"     },
	{ 0x66,0x00,	0,0,	0,0,	0,0,	"OPSIZE:" },
	{ 0x67,0x00,	0,0,	0,0,	0,0,	"ADSIZE:" },
	{ 0x68,0x01,	I,z,	0,0,	0,0,	"PUSH"    },
	{ 0x69,0x03,	G,v,	E,v,	I,z,	"IMUL"    },
	{ 0x6A,0x01,	I,b,	0,0,	0,0,	"PUSH"    },
	{ 0x6B,0x03,	G,v,	E,v,	I,b,	"IMUL"    },
	{ 0x6C,0x02,	Y,b,	D,X,	0,0,	"INSB"    },
	{ 0x6D,0x02,	Y,z,	D,X,	0,0,	"INSW"    },
	{ 0x6E,0x02,	D,X,	X,b,	0,0,	"OUTSB"   },
	{ 0x6F,0x02,	D,X,	X,z,	0,0,	"OUTSW"   },
	{ 0x70,0x01,	J,b,	0,0,	0,0,	"JO"      },
	{ 0x71,0x01,	J,b,	0,0,	0,0,	"JNO"     },
	{ 0x72,0x01,	J,b,	0,0,	0,0,	"JB"      },
	{ 0x73,0x01,	J,b,	0,0,	0,0,	"JNB"     },
	{ 0x74,0x01,	J,b,	0,0,	0,0,	"JZ"      },
	{ 0x75,0x01,	J,b,	0,0,	0,0,	"JNZ"     },
	{ 0x76,0x01,	J,b,	0,0,	0,0,	"JBE"     },
	{ 0x77,0x01,	J,b,	0,0,	0,0,	"JA"      },
	{ 0x78,0x01,	J,b,	0,0,	0,0,	"JS"      },
	{ 0x79,0x01,	J,b,	0,0,	0,0,	"JNS"     },
	{ 0x7A,0x01,	J,b,	0,0,	0,0,	"JP"      },
	{ 0x7B,0x01,	J,b,	0,0,	0,0,	"JNP"     },
	{ 0x7C,0x01,	J,b,	0,0,	0,0,	"JL"      },
	{ 0x7D,0x01,	J,b,	0,0,	0,0,	"JNL"     },
	{ 0x7E,0x01,	J,b,	0,0,	0,0,	"JLE"     },
	{ 0x7F,0x01,	J,b,	0,0,	0,0,	"JNLE"    },
	{ 0x80,0x02,	E,b,	I,b,	0,0, 	"ADD"     },
	{ 0x81,0x02,	E,v,	I,z,	0,0, 	"ADD"     },
	{ 0x82,0x02,	E,b,	I,b,	0,0, 	"SUB"     },
	{ 0x83,0x02,	E,v,	I,z,	0,0, 	"SUB"     },
	{ 0x84,0x02,	E,b,	G,b,	0,0, 	"TEST"    },
	{ 0x85,0x02,	E,v, 	G,v,	0,0,	"TEST"    },
	{ 0x86,0x02,	E,b,	G,b,	0,0,	"XCHG"    },
	{ 0x87,0x02,	E,v, 	G,v,	0,0,	"XCHG"    },
	{ 0x88,0x02,	E,b,	G,b,	0,0, 	"MOV"     },
	{ 0x89,0x02,	E,v, 	G,v,	0,0, 	"MOV"     },
	{ 0x8A,0x02,	G,b,	E,b,	0,0, 	"MOV"     },
	{ 0x8B,0x02,	G,v, 	E,v,	0,0, 	"MOV"     },
	{ 0x8C,0x02,	E,v,	S,w,	0,0, 	"MOV"     },
	{ 0x8D,0x02,	G,v, 	M,0,	0,0,	"LEA"     },
	{ 0x8E,0x02,	S,w,	E,w,	0,0,	"MOV"     },
	{ 0x8F,0x01,	E,v,	0,0,	0,0,	"POP"     },
	{ 0x90,0x00,	0,0,	0,0,	0,0, 	"NOP"     },
	{ 0x91,0x02,	EAX,0,	ECX,0,	0,0, 	"XCHG"    },
	{ 0x92,0x02,	EAX,0,	EDX,0,	0,0, 	"XCHG"    },
	{ 0x93,0x02,	EAX,0,	EBX,0,	0,0, 	"XCHG"    },
	{ 0x94,0x02,	EAX,0,	ESP,0,	0,0, 	"XCHG"    },
	{ 0x95,0x02,	EAX,0, 	EBP,0,	0,0,	"XCHG"    },
	{ 0x96,0x02,	EAX,0,	ESI,0,	0,0,	"XCHG"    },
	{ 0x97,0x02,	EAX,0,	EDI,0,	0,0,	"XCHG"    },
	{ 0x98,0x00,	0,0,	0,0,	0,0, 	"CBW"     },
	{ 0x99,0x00,	0,0,	0,0,	0,0, 	"CWD"     },
	{ 0x9A,0x01,	A,p,	0,0,	0,0, 	"CALL"    },
	{ 0x9B,0x00,	0,0,	0,0,	0,0, 	"WAIT"    },
	{ 0x9C,0x00,	F,v,	0,0,	0,0, 	"PUSHF"   },
	{ 0x9D,0x00,	F,v, 	0,0,	0,0,	"POPF"    },
	{ 0x9E,0x00,	0,0,	0,0,	0,0,	"SAHF"    },
	{ 0x9F,0x00,	0,0,	0,0,	0,0,	"LAHF"    },
	{ 0xA0,0x02,	A,L,	O,b,	0,0, 	"MOV"     },
	{ 0xA1,0x02,	EAX,0,	O,v,	0,0, 	"MOV"     },
	{ 0xA2,0x02,	O,b,	A,L,	0,0, 	"MOV"     },
	{ 0xA3,0x02,	O,v,	EAX,0,	0,0, 	"MOV"     },
	{ 0xA4,0x02,	X,b,	Y,b,	0,0, 	"MOVSB"   },
	{ 0xA5,0x02,	X,v, 	Y,v,	0,0,	"MOVSB"   },
	{ 0xA6,0x02,	X,b,	Y,b,	0,0,	"CMPSB"   },
	{ 0xA7,0x02,	X,v, 	Y,v,	0,0,	"CMPSB"   },
	{ 0xA8,0x02,	A,L,	I,b,	0,0, 	"TEST"    },
	{ 0xA9,0x02,	EAX,0,	I,z,	0,0, 	"TEST"    },
	{ 0xAA,0x02,	Y,b,	A,L,	0,0, 	"STOSB"   },
	{ 0xAB,0x02,	Y,v,	EAX,0,	0,0, 	"STOSW"   },
	{ 0xAC,0x02,	A,L,	X,b,	0,0, 	"LODSB"   },
	{ 0xAD,0x02,	EAX,0, 	X,v,	0,0,	"LODSW"   },
	{ 0xAE,0x02,	A,L,	Y,b,	0,0,	"SCASB"   },
	{ 0xAF,0x02,	EAX,0,	Y,v,	0,0,	"SCASW"   },
	{ 0xB0,0x02,	A,L,	I,b,	0,0, 	"MOV"     },
	{ 0xB1,0x02,	C,L,	I,b,	0,0, 	"MOV"     },
	{ 0xB2,0x02,	D,L,	I,b,	0,0, 	"MOV"     },
	{ 0xB3,0x02,	B,L,	I,b,	0,0, 	"MOV"     },
	{ 0xB4,0x02,	A,H,	I,b,	0,0, 	"MOV"     },
	{ 0xB5,0x02,	C,H, 	I,b,	0,0,	"MOV"     },
	{ 0xB6,0x02,	D,H,	I,b,	0,0,	"MOV"     },
	{ 0xB7,0x02,	B,H,	I,b,	0,0,	"MOV"     },
	{ 0xB8,0x02,	EAX,0,	I,v,	0,0, 	"MOV"     },
	{ 0xB9,0x02,	ECX,0,	I,v,	0,0, 	"MOV"     },
	{ 0xBA,0x02,	EDX,0,	I,v,	0,0, 	"MOV"     },
	{ 0xBB,0x02,	EBX,0,	I,v,	0,0, 	"MOV"     },
	{ 0xBC,0x02,	ESP,0,	I,v,	0,0, 	"MOV"     },
	{ 0xBD,0x02,	EBP,0, 	I,v,	0,0,	"MOV"     },
	{ 0xBE,0x02,	ESI,0,	I,v,	0,0,	"MOV"     },
	{ 0xBF,0x02,	EDI,0,	I,v,	0,0,	"MOV"     },
	{ 0xC0,0x02,	E,b,	I,b,	0,0, 	"ROR"     },
	{ 0xC1,0x02,	E,v,	I,b,	0,0, 	"SHR"     },
	{ 0xC2,0x01,	I,w,	0,0,	0,0, 	"RETN"    },
	{ 0xC3,0x00,	0,0,	0,0,	0,0, 	"RETN"    },
	{ 0xC4,0x02,	G,v,	M,p,	0,0, 	"LES"     },
	{ 0xC5,0x02,	G,v, 	M,p,	0,0,	"LDS"     },
	{ 0xC6,0x02,	E,b,	I,b,	0,0,	"MOV"     },
	{ 0xC7,0x02,	E,v,	I,v,	0,0,	"MOV"     },
	{ 0xC8,0x02,	I,w,	I,b,	0,0, 	"ENTER"   },
	{ 0xC9,0x00,	0,0,	0,0,	0,0, 	"LEAVE"   },
	{ 0xCA,0x01,	I,w,	0,0,	0,0, 	"RETF"    },
	{ 0xCB,0x00,	0,0,	0,0,	0,0, 	"RETF"    },
	{ 0xCC,0x00,	0,0,	0,0,	0,0, 	"INT3"    },
	{ 0xCD,0x01,	I,b, 	0,0,	0,0,	"INT"     },
	{ 0xCE,0x00,	0,0,	0,0,	0,0,	"INTO"    },
	{ 0xCF,0x00,	0,0,	0,0,	0,0,	"IRET"    },
	{ 0xD0,0x11,	E,b,	0,0,	1,0, 	"RCL"     },
	{ 0xD1,0x11,	E,v,	0,0,	1,0, 	"SHL"     },
	{ 0xD2,0x02,	E,b,	C,L,	0,0, 	"RCL"     },
	{ 0xD3,0x02,	E,v,	C,L,	0,0, 	"ROR"     },
	{ 0xD4,0x01,	I,b,	0,0,	0,0, 	"AAM"     },
	{ 0xD5,0x01,	I,b, 	0,0,	0,0,	"AAD"     },
	{ 0xD6,0x00,	0,0,	0,0,	0,0,	"SALC"    },
	{ 0xD7,0x00,	0,0,	0,0,	0,0,	"XLAT"    },
	{ 0xD8,0x01,	0,0,	0,0,	0,0, 	"ESC"     },
	{ 0xD9,0x10,	0,0,	0,0,	1,0, 	"ESC"     },
	{ 0xDA,0x10,	0,0,	0,0,	2,0, 	"ESC"     },
	{ 0xDB,0x10,	0,0,	0,0,	3,0, 	"ESC"     },
	{ 0xDC,0x10,	0,0,	0,0,	4,0, 	"ESC"     },
	{ 0xDD,0x10,	0,0, 	0,0,	5,0,	"ESC"     },
	{ 0xDE,0x10,	0,0,	0,0,	6,0,	"ESC"     },
	{ 0xDF,0x10,	0,0,	0,0,	7,0,	"ESC"     },
	{ 0xE0,0x01,	J,b,	0,0,	0,0, 	"LOOPNZ"  },
	{ 0xE1,0x01,	J,b,	0,0,	0,0, 	"LOOPZ"   },
	{ 0xE2,0x01,	J,b,	0,0,	0,0, 	"LOOP"    },
	{ 0xE3,0x01,	J,b,	0,0,	0,0, 	"JCXZ"    },
	{ 0xE4,0x02,	A,L,	I,b,	0,0, 	"IN"      },
	{ 0xE5,0x02,	EAX,0, 	I,b,	0,0,	"IN"      },
	{ 0xE6,0x02,	I,b,	A,L,	0,0,	"OUT"     },
	{ 0xE7,0x02,	I,b,	EAX,0,	0,0,	"OUT"     },
	{ 0xE8,0x01,	J,z,	0,0,	0,0, 	"CALL"    },
	{ 0xE9,0x01,	J,z,	0,0,	0,0, 	"JMP"     },
	{ 0xEA,0x01,	A,p,	0,0,	0,0, 	"JMP"     },
	{ 0xEB,0x01,	J,b,	0,0,	0,0, 	"JMP"     },
	{ 0xEC,0x02,	A,L,	D,X,	0,0, 	"IN"      },
	{ 0xED,0x02,	EAX,0, 	D,X,	0,0,	"IN"      },
	{ 0xEE,0x02,	D,X,	A,L,	0,0,	"OUT"     },
	{ 0xEF,0x02,	D,X,	EAX,0,	0,0,	"OUT"     },
	{ 0xF0,0x00,	0,0,	0,0,	0,0, 	"LOCK:"   },
	{ 0xF1,0x00,	0,0,	0,0,	0,0, 	"INT1"    },
	{ 0xF2,0x00,	0,0,	0,0,	0,0, 	"REPNE:"  },
	{ 0xF3,0x00,	0,0,	0,0,	0,0, 	"REP:"    },
	{ 0xF4,0x00,	0,0,	0,0,	0,0, 	"HLT"     },
	{ 0xF5,0x00,	0,0, 	0,0,	0,0,	"CMC"     },
	{ 0xF6,0x01,	E,b,	0,0,	0,0,	"TEST"    },
	{ 0xF7,0x01,	E,v,	0,0,	0,0,	"TEST"    },
	{ 0xF8,0x00,	0,0,	0,0,	0,0, 	"CLC"     },
	{ 0xF9,0x00,	0,0,	0,0,	0,0, 	"STC"     },
	{ 0xFA,0x00,	0,0,	0,0,	0,0, 	"CLI"     },
	{ 0xFB,0x00,	0,0,	0,0,	0,0, 	"STI"     },
	{ 0xFC,0x00,	0,0,	0,0,	0,0, 	"CLD"     },
	{ 0xFD,0x00,	0,0, 	0,0,	0,0,	"STD"     },
	{ 0xFE,0x00,	0,0,	0,0,	0,0,	"INC,DEC" },
	{ 0xFF,0x00,	0,0,	0,0,	0,0,	"INC,DEC" }, };

#endif