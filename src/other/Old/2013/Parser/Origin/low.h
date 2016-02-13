/*
            ROLLRAT MATHEMATICS PROJECT

             Cpy (c) 14. ALL RIGHTS RESERVED.
   */

#ifndef _LOW_
#define _LOW_
#pragma once

#include "mathematics.h"

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

// 명령이 두 번째 피연산자를 필요로하지 않는 경우 레지스트리 / 작동 코드 필드가 작동 코드 확장으로 사용할 수있다.
// 이 사용은 테이블의 6 행 ( "(op 코드) / 숫자"라는 레이블)로 표시된다. 6 행의 값을 10 진수로 표현되는 것에주의하십시오.
// 표 2-1 및 표 2-2 (라벨 "하는 ModR / M 바이트의 값 (16 진수)"아래)의 본체는 8 배열 32 일 수 (16 진수하는 ModR / M 바이트의 256 개의 값 모든 발표가 포함되어 있습니다). 비트 3, 그림 4와 그림 5는에 의해 지정된
// 바이트가 상주하는 테이블의 행. 및 비트 6,7 행은 비트 0,1,2을 지정한다. 아래 그림은 1 테이블 값의 해석을 보여줍니다.

// If the instruction does not require a second operand, then the Reg/Opcode field may be used as an opcode extension.
// This use is represented by the sixth row in the tables (labeled “/digit (Opcode)”). Note that values in row six
// are represented in decimal form.
// The body of Table 2-1 and Table 2-2 (under the label “Value of ModR/M Byte (in Hexadecimal)”) contains a 32 by 8
// array that presents all of 256 values of the ModR/M byte (in hexadecimal). Bits 3, 4 and 5 are specified by the
// column of the table in which a byte resides. The row specifies bits 0, 1 and 2; and bits 6 and 7. The figure below
// demonstrates interpretation of one table value.
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

// GENERAL-PURPOSE INSTRUCTION FORMATS AND ENCODINGS FOR NON-64-BIT MODES
typedef enum _ATS_COMMON_GENERAL {
	ADC,
	ADD,
	AND,
	ARPL,
	BOUND,
	BSF,
	BSR,
	BSWAP,
	BT,
	BTC,
	BTR,
	BTS,
	CALL,
	CBW,
	CDQ,
	CLC,
	CLD,
	CLI,
	CLTS,
	CMC,
	CMP,
	CMPS,
	CMPSB,
	CMPSW,
	CMPSD,
	CMPSQ,
	CMPXCHG,
	CPUID,
	CWD,
	CWDE,
	DAA,
	DAS,
	DEC,
	DIV,
	HLT,
	IDIV,
	IMUL,
	IN,
	INC,
	INS,
	INTn,
	INT,
	INTO,
	INVD,
	INVLPG,
	INVPCID,
	IRETO,
	Jcc,
	JCXZ,
	JECXZ,
	JMP,
	LAR,
	LEA,
	LEAVE,
	LFS,
	LGDT,
	LGS,
	LIDT,
	LLDT,
	LMSW,
	LOCK,
	LODS,
	LODSB,
	LODSW,
	LODSD,
	LODSQ,
	LOOP,
	LOOPE,
	KOOPNE,
	LOOPNZ,
	LSL,
	LSS,
	LTR,
	MOV,
	MOVBE,
	MOVS,
	MOVSB,
	MOVSW,
	MOVSD,
	MOVSQ,
	MOVSX,
	MOVXD,
	MOVZX,
	MUL,
	NEG,
	NOP,
	NOT,
	OR,
	OUT,
	OUTS,
	POP,
	POPF,
	POPFQ,
	PUSH,
	PUSHF,
	PUSHFD,
	RCL,
	RCR,
	RDMSR,
	RDPMC,
	RDTSC,
	RDTSCP,
	REP_INS,
	REP_LODS,
	REP_OUTS,
	REP_STOS,
	REPE_CMPS,
	REPE_SCAS,
	REPNE_CMPS,
	REPNE_SCAS,
	RET,
	ROL,
	ROR,
	RSM,
	SAL,
	SAR,
	SBB,
	SCAS,
	SCASB,
	SCASW,
	SCASD,
	SETcc,
	SGDT,
	SHL,
	SHLD,
	SHR,
	SHRD,
	SIDT,
	SLDT,
	SMSW,
	STC,
	STD,
	STI,
	STOS,
	STOSB,
	STOSW,
	STOSD,
	STOSQ,
	STR,
	SUB,
	SWAPGS,
	SYSCALL,
	SYSRET,
	TEST,
	UD2,
	VERR,
	VERW,
	WAIT,
	WBINVD,
	WRMSR,
	XADD,
	XCHG,
	XLAT,
	XLATB,
	XOR,
}	GENERAL;

	// OLLYDBG SOURCE

#ifdef __BORLANDC__
#pragma option -K                      // Unsigned char
#endif

#if (char)0xFF!=255
#error Please set default char type to unsigned
#endif

#define NEGLIMIT       (-16384)        // Limit to display constans as signed
#define PSEUDOOP       128             // Base for pseudooperands
#define TEXTLEN        256             // Maximal length of text string

// Special command features.
#define WW             0x01            // Bit W (size of operand)
#define SS             0x02            // Bit S (sign extention of immediate)
#define WS             0x03            // Bits W and S
#define W3             0x08            // Bit W at position 3
#define CC             0x10            // Conditional jump
#define FF             0x20            // Forced 16-bit size
#define LL             0x40            // Conditional loop
#define PR             0x80            // Protected command
#define WP             0x81            // I/O command with bit W

// All possible types of operands in 80x86. A bit more than you expected, he?
#define NNN            0               // No operand
#define REG            1               // Integer register in Reg field
#define RCM            2               // Integer register in command byte
#define RG4            3               // Integer 4-byte register in Reg field
#define RAC            4               // Accumulator (AL/AX/EAX, implicit)
#define RAX            5               // AX (2-byte, implicit)
#define RDX            6               // DX (16-bit implicit port address)
#define RCL            7               // Implicit CL register (for shifts)
#define RS0            8               // Top of FPU stack (ST(0), implicit)
#define RST            9               // FPU register (ST(i)) in command byte
#define RMX            10              // MMX register MMx
#define R3D            11              // 3DNow! register MMx
#define MRG            12              // Memory/register in ModRM byte
#define MR1            13              // 1-byte memory/register in ModRM byte
#define MR2            14              // 2-byte memory/register in ModRM byte
#define MR4            15              // 4-byte memory/register in ModRM byte
#define RR4            16              // 4-byte memory/register (register only)
#define MR8            17              // 8-byte memory/MMX register in ModRM
#define RR8            18              // 8-byte MMX register only in ModRM
#define MRD            19              // 8-byte memory/3DNow! register in ModRM
#define RRD            20              // 8-byte memory/3DNow! (register only)
#define MRJ            21              // Memory/reg in ModRM as JUMP target
#define MMA            22              // Memory address in ModRM byte for LEA
#define MML            23              // Memory in ModRM byte (for LES)
#define MMS            24              // Memory in ModRM byte (as SEG:OFFS)
#define MM6            25              // Memory in ModRm (6-byte descriptor)
#define MMB            26              // Two adjacent memory locations (BOUND)
#define MD2            27              // Memory in ModRM (16-bit integer)
#define MB2            28              // Memory in ModRM (16-bit binary)
#define MD4            29              // Memory in ModRM byte (32-bit integer)
#define MD8            30              // Memory in ModRM byte (64-bit integer)
#define MDA            31              // Memory in ModRM byte (80-bit BCD)
#define MF4            32              // Memory in ModRM byte (32-bit float)
#define MF8            33              // Memory in ModRM byte (64-bit float)
#define MFA            34              // Memory in ModRM byte (80-bit float)
#define MFE            35              // Memory in ModRM byte (FPU environment)
#define MFS            36              // Memory in ModRM byte (FPU state)
#define MFX            37              // Memory in ModRM byte (ext. FPU state)
#define MSO            38              // Source in string op's ([ESI])
#define MDE            39              // Destination in string op's ([EDI])
#define MXL            40              // XLAT operand ([EBX+AL])
#define IMM            41              // Immediate data (8 or 16/32)
#define IMU            42              // Immediate unsigned data (8 or 16/32)
#define VXD            43              // VxD service
#define IMX            44              // Immediate sign-extendable byte
#define C01            45              // Implicit constant 1 (for shifts)
#define IMS            46              // Immediate byte (for shifts)
#define IM1            47              // Immediate byte
#define IM2            48              // Immediate word (ENTER/RET)
#define IMA            49              // Immediate absolute near data address
#define JOB            50              // Immediate byte offset (for jumps)
#define JOW            51              // Immediate full offset (for jumps)
#define JMF            52              // Immediate absolute far jump/call addr
#define SGM            53              // Segment register in ModRM byte
#define SCM            54              // Segment register in command byte
#define CRX            55              // Control register CRx
#define DRX            56              // Debug register DRx
// Pseudooperands (implicit operands, never appear in assembler commands). Must
// have index equal to or exceeding PSEUDOOP.
#define PRN            (PSEUDOOP+0)    // Near return address
#define PRF            (PSEUDOOP+1)    // Far return address
#define PAC            (PSEUDOOP+2)    // Accumulator (AL/AX/EAX)
#define PAH            (PSEUDOOP+3)    // AH (in LAHF/SAHF commands)
#define PFL            (PSEUDOOP+4)    // Lower byte of flags (in LAHF/SAHF)
#define PS0            (PSEUDOOP+5)    // Top of FPU stack (ST(0))
#define PS1            (PSEUDOOP+6)    // ST(1)
#define PCX            (PSEUDOOP+7)    // CX/ECX
#define PDI            (PSEUDOOP+8)    // EDI (in MMX extentions)

// Errors detected during command disassembling.
#define DAE_NOERR      0               // No error
#define DAE_BADCMD     1               // Unrecognized command
#define DAE_CROSS      2               // Command crosses end of memory block
#define DAE_BADSEG     3               // Undefined segment register
#define DAE_MEMORY     4               // Register where only memory allowed
#define DAE_REGISTER   5               // Memory where only register allowed
#define DAE_INTERN     6               // Internal error

typedef unsigned char  uchar;          // Unsigned character (byte)
typedef unsigned short ushort;         // Unsigned short
typedef unsigned int   uint;           // Unsigned integer
typedef unsigned long  ulong;          // Unsigned long

typedef struct t_addrdec {
  int            defseg;
  char           *descr;
} t_addrdec;

typedef struct t_cmddata {
  ulong          mask;                 // Mask for first 4 bytes of the command
  ulong          code;                 // Compare masked bytes with this
  char           len;                  // Length of the main command code
  char           bits;                 // Special bits within the command
  char           arg1,arg2,arg3;       // Types of possible arguments
  char           type;                 // C_xxx + additional information
  char           *name;                // Symbolic name for this command
} t_cmddata;

// Initialized constant data structures used by all programs from assembler
// package. Contain names of register, register combinations or commands and
// their properties.
extern const char      *regname[3][9];
extern const char      *segname[8];
extern const char      *sizename[11];
extern const t_addrdec addr16[8];
extern const t_addrdec addr32[8];
extern const char      *fpuname[9];
extern const char      *mmxname[9];
extern const char      *crname[9];
extern const char      *drname[9];
extern const char      *condition[16];
extern const t_cmddata cmddata[];
extern const t_cmddata vxdcmd;
extern const t_cmddata dangerous[];



////////////////////////////////////////////////////////////////////////////////
//////////////////// ASSEMBLER, DISASSEMBLER AND EXPRESSIONS ///////////////////

#define MAXCMDSIZE     16              // Maximal length of 80x86 command
#define MAXCALSIZE     8               // Max length of CALL without prefixes
#define NMODELS        8               // Number of assembler search models

#define INT3           0xCC            // Code of 1-byte breakpoint
#define NOP            0x90            // Code of 1-byte NOP command
#define TRAPFLAG       0x00000100      // Trap flag in CPU flag register

#define REG_EAX        0               // Indexes of general-purpose registers
#define REG_ECX        1               // in t_reg.
#define REG_EDX        2
#define REG_EBX        3
#define REG_ESP        4
#define REG_EBP        5
#define REG_ESI        6
#define REG_EDI        7

#define SEG_UNDEF     -1
#define SEG_ES         0               // Indexes of segment/selector registers
#define SEG_CS         1
#define SEG_SS         2
#define SEG_DS         3
#define SEG_FS         4
#define SEG_GS         5

#define C_TYPEMASK     0xF0            // Mask for command type
#define   C_CMD        0x00            // Ordinary instruction
#define   C_PSH        0x10            // 1-word PUSH instruction
#define   C_POP        0x20            // 1-word POP instruction
#define   C_MMX        0x30            // MMX instruction
#define   C_FLT        0x40            // FPU instruction
#define   C_JMP        0x50            // JUMP instruction
#define   C_JMC        0x60            // Conditional JUMP instruction
#define   C_CAL        0x70            // CALL instruction
#define   C_RET        0x80            // RET instruction
#define   C_FLG        0x90            // Changes system flags
#define   C_RTF        0xA0            // C_JMP and C_FLG simultaneously
#define   C_REP        0xB0            // Instruction with REPxx prefix
#define   C_PRI        0xC0            // Privileged instruction
#define   C_DAT        0xD0            // Data (address) doubleword
#define   C_NOW        0xE0            // 3DNow! instruction
#define   C_BAD        0xF0            // Unrecognized command
#define C_RARE         0x08            // Rare command, seldom used in programs
#define C_SIZEMASK     0x07            // MMX data size or special flag
#define   C_EXPL       0x01            // (non-MMX) Specify explicit memory size

#define C_DANGER95     0x01            // Command is dangerous under Win95/98
#define C_DANGER       0x03            // Command is dangerous everywhere
#define C_DANGERLOCK   0x07            // Dangerous with LOCK prefix

#define DEC_TYPEMASK   0x1F            // Type of memory byte
#define   DEC_UNKNOWN  0x00            // Unknown type
#define   DEC_BYTE     0x01            // Accessed as byte
#define   DEC_WORD     0x02            // Accessed as short
#define   DEC_NEXTDATA 0x03            // Subsequent byte of code or data
#define   DEC_DWORD    0x04            // Accessed as long
#define   DEC_FLOAT4   0x05            // Accessed as float
#define   DEC_FWORD    0x06            // Accessed as descriptor/long pointer
#define   DEC_FLOAT8   0x07            // Accessed as double
#define   DEC_QWORD    0x08            // Accessed as 8-byte integer
#define   DEC_FLOAT10  0x09            // Accessed as long double
#define   DEC_TBYTE    0x0A            // Accessed as 10-byte integer
#define   DEC_STRING   0x0B            // Zero-terminated ASCII string
#define   DEC_UNICODE  0x0C            // Zero-terminated UNICODE string
#define   DEC_3DNOW    0x0D            // Accessed as 3Dnow operand
#define   DEC_BYTESW   0x11            // Accessed as byte index to switch
#define   DEC_NEXTCODE 0x13            // Subsequent byte of command
#define   DEC_COMMAND  0x1D            // First byte of command
#define   DEC_JMPDEST  0x1E            // Jump destination
#define   DEC_CALLDEST 0x1F            // Call (and maybe jump) destination
#define DEC_PROCMASK   0x60            // Procedure analysis
#define   DEC_PROC     0x20            // Start of procedure
#define   DEC_PBODY    0x40            // Body of procedure
#define   DEC_PEND     0x60            // End of procedure
#define DEC_CHECKED    0x80            // Byte was analysed

#define DECR_TYPEMASK  0x3F            // Type of register or memory
#define   DECR_BYTE    0x21            // Byte register
#define   DECR_WORD    0x22            // Short integer register
#define   DECR_DWORD   0x24            // Long integer register
#define   DECR_QWORD   0x28            // MMX register
#define   DECR_FLOAT10 0x29            // Floating-point register
#define   DECR_SEG     0x2A            // Segment register
#define   DECR_3DNOW   0x2D            // 3Dnow! register
#define DECR_ISREG     0x20            // Mask to check that operand is register

#define DISASM_SIZE    0               // Determine command size only
#define DISASM_DATA    1               // Determine size and analysis data
#define DISASM_FILE    3               // Disassembly, no symbols
#define DISASM_CODE    4               // Full disassembly

// Warnings issued by Disasm():
#define DAW_FARADDR    0x0001          // Command is a far jump, call or return
#define DAW_SEGMENT    0x0002          // Command loads segment register
#define DAW_PRIV       0x0004          // Privileged command
#define DAW_IO         0x0008          // I/O command
#define DAW_SHIFT      0x0010          // Shift constant out of range 1..31
#define DAW_PREFIX     0x0020          // Superfluous prefix
#define DAW_LOCK       0x0040          // Command has LOCK prefix
#define DAW_STACK      0x0080          // Unaligned stack operation
#define DAW_DANGER95   0x1000          // May mess up Win95 if executed
#define DAW_DANGEROUS  0x3000          // May mess up any OS if executed

typedef struct t_disasm {              // Results of disassembling
  ulong          ip;                   // Instrucion pointer
  char           dump[TEXTLEN];        // Hexadecimal dump of the command
  char           result[TEXTLEN];      // Disassembled command
  char           comment[TEXTLEN];     // Brief comment
  int            cmdtype;              // One of C_xxx
  int            memtype;              // Type of addressed variable in memory
  int            nprefix;              // Number of prefixes
  int            indexed;              // Address contains register(s)
  ulong          jmpconst;             // Constant jump address
  ulong          jmptable;             // Possible address of switch table
  ulong          adrconst;             // Constant part of address
  ulong          immconst;             // Immediate constant
  int            zeroconst;            // Whether contains zero constant
  int            fixupoffset;          // Possible offset of 32-bit fixups
  int            fixupsize;            // Possible total size of fixups or 0
  int            error;                // Error while disassembling command
  int            warnings;             // Combination of DAW_xxx
} t_disasm;

typedef struct t_asmmodel {            // Model to search for assembler command
  char           code[MAXCMDSIZE];     // Binary code
  char           mask[MAXCMDSIZE];     // Mask for binary code (0: bit ignored)
  int            length;               // Length of code, bytes (0: empty)
  int            jmpsize;              // Offset size if relative jump
  int            jmpoffset;            // Offset relative to IP
  int            jmppos;               // Position of jump offset in command
} t_asmmodel;

// List of available processor commands with decoding, types of parameters and
// other useful information. Last element has field mask=0. If mnemonic begins
// with ampersand ('&'), its mnemonic decodes differently depending on operand
// size (16 or 32 bits). If mnemonic begins with dollar ('$'), this mnemonic
// depends on address size. Semicolon (':') separates 16-bit form from 32-bit,
// asterisk ('*') will be substituted by either W (16), D (32) or none (16/32)
// character. If command is of type C_MMX or C_NOW, or if type contains C_EXPL
// (=0x01), Disassembler must specify explicit size of memory operand.
const t_cmddata cmddata[] = {
	{ 0x0000FF, 0x000090, 1, 00, NNN, NNN, NNN, C_CMD + 0, "NOP" },
	{ 0x0000FE, 0x00008A, 1, WW, REG, MRG, NNN, C_CMD + 0, "MOV" },
	{ 0x0000F8, 0x000050, 1, 00, RCM, NNN, NNN, C_PSH + 0, "PUSH" },
	{ 0x0000FE, 0x000088, 1, WW, MRG, REG, NNN, C_CMD + 0, "MOV" },
	{ 0x0000FF, 0x0000E8, 1, 00, JOW, NNN, NNN, C_CAL + 0, "CALL" },
	{ 0x0000FD, 0x000068, 1, SS, IMM, NNN, NNN, C_PSH + 0, "PUSH" },
	{ 0x0000FF, 0x00008D, 1, 00, REG, MMA, NNN, C_CMD + 0, "LEA" },
	{ 0x0000FF, 0x000074, 1, CC, JOB, NNN, NNN, C_JMC + 0, "JE,JZ" },
	{ 0x0000F8, 0x000058, 1, 00, RCM, NNN, NNN, C_POP + 0, "POP" },
	{ 0x0038FC, 0x000080, 1, WS, MRG, IMM, NNN, C_CMD + 1, "ADD" },
	{ 0x0000FF, 0x000075, 1, CC, JOB, NNN, NNN, C_JMC + 0, "JNZ,JNE" },
	{ 0x0000FF, 0x0000EB, 1, 00, JOB, NNN, NNN, C_JMP + 0, "JMP" },
	{ 0x0000FF, 0x0000E9, 1, 00, JOW, NNN, NNN, C_JMP + 0, "JMP" },
	{ 0x0000FE, 0x000084, 1, WW, MRG, REG, NNN, C_CMD + 0, "TEST" },
	{ 0x0038FE, 0x0000C6, 1, WW, MRG, IMM, NNN, C_CMD + 1, "MOV" },
	{ 0x0000FE, 0x000032, 1, WW, REG, MRG, NNN, C_CMD + 0, "XOR" },
	{ 0x0000FE, 0x00003A, 1, WW, REG, MRG, NNN, C_CMD + 0, "CMP" },
	{ 0x0038FC, 0x003880, 1, WS, MRG, IMM, NNN, C_CMD + 1, "CMP" },
	{ 0x0038FF, 0x0010FF, 1, 00, MRJ, NNN, NNN, C_CAL + 0, "CALL" },
	{ 0x0000FF, 0x0000C3, 1, 00, PRN, NNN, NNN, C_RET + 0, "RETN,RET" },
	{ 0x0000F0, 0x0000B0, 1, W3, RCM, IMM, NNN, C_CMD + 0, "MOV" },
	{ 0x0000FE, 0x0000A0, 1, WW, RAC, IMA, NNN, C_CMD + 0, "MOV" },
	{ 0x00FFFF, 0x00840F, 2, CC, JOW, NNN, NNN, C_JMC + 0, "JE,JZ" },
	{ 0x0000F8, 0x000040, 1, 00, RCM, NNN, NNN, C_CMD + 0, "INC" },
	{ 0x0038FE, 0x0000F6, 1, WW, MRG, IMU, NNN, C_CMD + 1, "TEST" },
	{ 0x0000FE, 0x0000A2, 1, WW, IMA, RAC, NNN, C_CMD + 0, "MOV" },
	{ 0x0000FE, 0x00002A, 1, WW, REG, MRG, NNN, C_CMD + 0, "SUB" },
	{ 0x0000FF, 0x00007E, 1, CC, JOB, NNN, NNN, C_JMC + 0, "JLE,JNG" },
	{ 0x00FFFF, 0x00850F, 2, CC, JOW, NNN, NNN, C_JMC + 0, "JNZ,JNE" },
	{ 0x0000FF, 0x0000C2, 1, 00, IM2, PRN, NNN, C_RET + 0, "RETN" },
	{ 0x0038FF, 0x0030FF, 1, 00, MRG, NNN, NNN, C_PSH + 1, "PUSH" },
	{ 0x0038FC, 0x000880, 1, WS, MRG, IMU, NNN, C_CMD + 1, "OR" },
	{ 0x0038FC, 0x002880, 1, WS, MRG, IMM, NNN, C_CMD + 1, "SUB" },
	{ 0x0000F8, 0x000048, 1, 00, RCM, NNN, NNN, C_CMD + 0, "DEC" },
	{ 0x00FFFF, 0x00BF0F, 2, 00, REG, MR2, NNN, C_CMD + 1, "MOVSX" },
	{ 0x0000FF, 0x00007C, 1, CC, JOB, NNN, NNN, C_JMC + 0, "JL,JNGE" },
	{ 0x0000FE, 0x000002, 1, WW, REG, MRG, NNN, C_CMD + 0, "ADD" },
	{ 0x0038FC, 0x002080, 1, WS, MRG, IMU, NNN, C_CMD + 1, "AND" },
	{ 0x0000FE, 0x00003C, 1, WW, RAC, IMM, NNN, C_CMD + 0, "CMP" },
	{ 0x0038FF, 0x0020FF, 1, 00, MRJ, NNN, NNN, C_JMP + 0, "JMP" },
	{ 0x0038FE, 0x0010F6, 1, WW, MRG, NNN, NNN, C_CMD + 1, "NOT" },
	{ 0x0038FE, 0x0028C0, 1, WW, MRG, IMS, NNN, C_CMD + 1, "SHR" },
	{ 0x0000FE, 0x000038, 1, WW, MRG, REG, NNN, C_CMD + 0, "CMP" },
	{ 0x0000FF, 0x00007D, 1, CC, JOB, NNN, NNN, C_JMC + 0, "JGE,JNL" },
	{ 0x0000FF, 0x00007F, 1, CC, JOB, NNN, NNN, C_JMC + 0, "JG,JNLE" },
	{ 0x0038FE, 0x0020C0, 1, WW, MRG, IMS, NNN, C_CMD + 1, "SHL" },
	{ 0x0000FE, 0x00001A, 1, WW, REG, MRG, NNN, C_CMD + 0, "SBB" },
	{ 0x0038FE, 0x0018F6, 1, WW, MRG, NNN, NNN, C_CMD + 1, "NEG" },
	{ 0x0000FF, 0x0000C9, 1, 00, NNN, NNN, NNN, C_CMD + 0, "LEAVE" },
	{ 0x0000FF, 0x000060, 1, 00, NNN, NNN, NNN, C_CMD + C_RARE + 0, "&PUSHA*" },
	{ 0x0038FF, 0x00008F, 1, 00, MRG, NNN, NNN, C_POP + 1, "POP" },
	{ 0x0000FF, 0x000061, 1, 00, NNN, NNN, NNN, C_CMD + C_RARE + 0, "&POPA*" },
	{ 0x0000F8, 0x000090, 1, 00, RAC, RCM, NNN, C_CMD + 0, "XCHG" },
	{ 0x0000FE, 0x000086, 1, WW, MRG, REG, NNN, C_CMD + 0, "XCHG" },
	{ 0x0000FE, 0x000000, 1, WW, MRG, REG, NNN, C_CMD + 0, "ADD" },
	{ 0x0000FE, 0x000010, 1, WW, MRG, REG, NNN, C_CMD + C_RARE + 0, "ADC" },
	{ 0x0000FE, 0x000012, 1, WW, REG, MRG, NNN, C_CMD + C_RARE + 0, "ADC" },
	{ 0x0000FE, 0x000020, 1, WW, MRG, REG, NNN, C_CMD + 0, "AND" },
	{ 0x0000FE, 0x000022, 1, WW, REG, MRG, NNN, C_CMD + 0, "AND" },
	{ 0x0000FE, 0x000008, 1, WW, MRG, REG, NNN, C_CMD + 0, "OR" },
	{ 0x0000FE, 0x00000A, 1, WW, REG, MRG, NNN, C_CMD + 0, "OR" },
	{ 0x0000FE, 0x000028, 1, WW, MRG, REG, NNN, C_CMD + 0, "SUB" },
	{ 0x0000FE, 0x000018, 1, WW, MRG, REG, NNN, C_CMD + C_RARE + 0, "SBB" },
	{ 0x0000FE, 0x000030, 1, WW, MRG, REG, NNN, C_CMD + 0, "XOR" },
	{ 0x0038FC, 0x001080, 1, WS, MRG, IMM, NNN, C_CMD + C_RARE + 1, "ADC" },
	{ 0x0038FC, 0x001880, 1, WS, MRG, IMM, NNN, C_CMD + C_RARE + 1, "SBB" },
	{ 0x0038FC, 0x003080, 1, WS, MRG, IMU, NNN, C_CMD + 1, "XOR" },
	{ 0x0000FE, 0x000004, 1, WW, RAC, IMM, NNN, C_CMD + 0, "ADD" },
	{ 0x0000FE, 0x000014, 1, WW, RAC, IMM, NNN, C_CMD + C_RARE + 0, "ADC" },
	{ 0x0000FE, 0x000024, 1, WW, RAC, IMU, NNN, C_CMD + 0, "AND" },
	{ 0x0000FE, 0x00000C, 1, WW, RAC, IMU, NNN, C_CMD + 0, "OR" },
	{ 0x0000FE, 0x00002C, 1, WW, RAC, IMM, NNN, C_CMD + 0, "SUB" },
	{ 0x0000FE, 0x00001C, 1, WW, RAC, IMM, NNN, C_CMD + C_RARE + 0, "SBB" },
	{ 0x0000FE, 0x000034, 1, WW, RAC, IMU, NNN, C_CMD + 0, "XOR" },
	{ 0x0038FE, 0x0000FE, 1, WW, MRG, NNN, NNN, C_CMD + 1, "INC" },
	{ 0x0038FE, 0x0008FE, 1, WW, MRG, NNN, NNN, C_CMD + 1, "DEC" },
	{ 0x0000FE, 0x0000A8, 1, WW, RAC, IMU, NNN, C_CMD + 0, "TEST" },
	{ 0x0038FE, 0x0020F6, 1, WW, MRG, NNN, NNN, C_CMD + 1, "MUL" },
	{ 0x0038FE, 0x0028F6, 1, WW, MRG, NNN, NNN, C_CMD + 1, "IMUL" },
	{ 0x00FFFF, 0x00AF0F, 2, 00, REG, MRG, NNN, C_CMD + 0, "IMUL" },
	{ 0x0000FF, 0x00006B, 1, 00, REG, MRG, IMX, C_CMD + C_RARE + 0, "IMUL" },
	{ 0x0000FF, 0x000069, 1, 00, REG, MRG, IMM, C_CMD + C_RARE + 0, "IMUL" },
	{ 0x0038FE, 0x0030F6, 1, WW, MRG, NNN, NNN, C_CMD + 1, "DIV" },
	{ 0x0038FE, 0x0038F6, 1, WW, MRG, NNN, NNN, C_CMD + 1, "IDIV" },
	{ 0x0000FF, 0x000098, 1, 00, NNN, NNN, NNN, C_CMD + 0, "&CBW:CWDE" },
	{ 0x0000FF, 0x000099, 1, 00, NNN, NNN, NNN, C_CMD + 0, "&CWD:CDQ" },
	{ 0x0038FE, 0x0000D0, 1, WW, MRG, C01, NNN, C_CMD + 1, "ROL" },
	{ 0x0038FE, 0x0008D0, 1, WW, MRG, C01, NNN, C_CMD + 1, "ROR" },
	{ 0x0038FE, 0x0010D0, 1, WW, MRG, C01, NNN, C_CMD + 1, "RCL" },
	{ 0x0038FE, 0x0018D0, 1, WW, MRG, C01, NNN, C_CMD + 1, "RCR" },
	{ 0x0038FE, 0x0020D0, 1, WW, MRG, C01, NNN, C_CMD + 1, "SHL" },
	{ 0x0038FE, 0x0028D0, 1, WW, MRG, C01, NNN, C_CMD + 1, "SHR" },
	{ 0x0038FE, 0x0038D0, 1, WW, MRG, C01, NNN, C_CMD + 1, "SAR" },
	{ 0x0038FE, 0x0000D2, 1, WW, MRG, RCL, NNN, C_CMD + 1, "ROL" },
	{ 0x0038FE, 0x0008D2, 1, WW, MRG, RCL, NNN, C_CMD + 1, "ROR" },
	{ 0x0038FE, 0x0010D2, 1, WW, MRG, RCL, NNN, C_CMD + 1, "RCL" },
	{ 0x0038FE, 0x0018D2, 1, WW, MRG, RCL, NNN, C_CMD + 1, "RCR" },
	{ 0x0038FE, 0x0020D2, 1, WW, MRG, RCL, NNN, C_CMD + 1, "SHL" },
	{ 0x0038FE, 0x0028D2, 1, WW, MRG, RCL, NNN, C_CMD + 1, "SHR" },
	{ 0x0038FE, 0x0038D2, 1, WW, MRG, RCL, NNN, C_CMD + 1, "SAR" },
	{ 0x0038FE, 0x0000C0, 1, WW, MRG, IMS, NNN, C_CMD + 1, "ROL" },
	{ 0x0038FE, 0x0008C0, 1, WW, MRG, IMS, NNN, C_CMD + 1, "ROR" },
	{ 0x0038FE, 0x0010C0, 1, WW, MRG, IMS, NNN, C_CMD + 1, "RCL" },
	{ 0x0038FE, 0x0018C0, 1, WW, MRG, IMS, NNN, C_CMD + 1, "RCR" },
	{ 0x0038FE, 0x0038C0, 1, WW, MRG, IMS, NNN, C_CMD + 1, "SAR" },
	{ 0x0000FF, 0x000070, 1, CC, JOB, NNN, NNN, C_JMC + 0, "JO" },
	{ 0x0000FF, 0x000071, 1, CC, JOB, NNN, NNN, C_JMC + 0, "JNO" },
	{ 0x0000FF, 0x000072, 1, CC, JOB, NNN, NNN, C_JMC + 0, "JB,JC" },
	{ 0x0000FF, 0x000073, 1, CC, JOB, NNN, NNN, C_JMC + 0, "JNB,JNC" },
	{ 0x0000FF, 0x000076, 1, CC, JOB, NNN, NNN, C_JMC + 0, "JBE,JNA" },
	{ 0x0000FF, 0x000077, 1, CC, JOB, NNN, NNN, C_JMC + 0, "JA,JNBE" },
	{ 0x0000FF, 0x000078, 1, CC, JOB, NNN, NNN, C_JMC + 0, "JS" },
	{ 0x0000FF, 0x000079, 1, CC, JOB, NNN, NNN, C_JMC + 0, "JNS" },
	{ 0x0000FF, 0x00007A, 1, CC, JOB, NNN, NNN, C_JMC + C_RARE + 0, "JPE,JP" },
	{ 0x0000FF, 0x00007B, 1, CC, JOB, NNN, NNN, C_JMC + C_RARE + 0, "JPO,JNP" },
	{ 0x0000FF, 0x0000E3, 1, 00, JOB, NNN, NNN, C_JMC + C_RARE + 0, "$JCXZ:JECXZ" },
	{ 0x00FFFF, 0x00800F, 2, CC, JOW, NNN, NNN, C_JMC + 0, "JO" },
	{ 0x00FFFF, 0x00810F, 2, CC, JOW, NNN, NNN, C_JMC + 0, "JNO" },
	{ 0x00FFFF, 0x00820F, 2, CC, JOW, NNN, NNN, C_JMC + 0, "JB,JC" },
	{ 0x00FFFF, 0x00830F, 2, CC, JOW, NNN, NNN, C_JMC + 0, "JNB,JNC" },
	{ 0x00FFFF, 0x00860F, 2, CC, JOW, NNN, NNN, C_JMC + 0, "JBE,JNA" },
	{ 0x00FFFF, 0x00870F, 2, CC, JOW, NNN, NNN, C_JMC + 0, "JA,JNBE" },
	{ 0x00FFFF, 0x00880F, 2, CC, JOW, NNN, NNN, C_JMC + 0, "JS" },
	{ 0x00FFFF, 0x00890F, 2, CC, JOW, NNN, NNN, C_JMC + 0, "JNS" },
	{ 0x00FFFF, 0x008A0F, 2, CC, JOW, NNN, NNN, C_JMC + C_RARE + 0, "JPE,JP" },
	{ 0x00FFFF, 0x008B0F, 2, CC, JOW, NNN, NNN, C_JMC + C_RARE + 0, "JPO,JNP" },
	{ 0x00FFFF, 0x008C0F, 2, CC, JOW, NNN, NNN, C_JMC + 0, "JL,JNGE" },
	{ 0x00FFFF, 0x008D0F, 2, CC, JOW, NNN, NNN, C_JMC + 0, "JGE,JNL" },
	{ 0x00FFFF, 0x008E0F, 2, CC, JOW, NNN, NNN, C_JMC + 0, "JLE,JNG" },
	{ 0x00FFFF, 0x008F0F, 2, CC, JOW, NNN, NNN, C_JMC + 0, "JG,JNLE" },
	{ 0x0000FF, 0x0000F8, 1, 00, NNN, NNN, NNN, C_CMD + 0, "CLC" },
	{ 0x0000FF, 0x0000F9, 1, 00, NNN, NNN, NNN, C_CMD + 0, "STC" },
	{ 0x0000FF, 0x0000F5, 1, 00, NNN, NNN, NNN, C_CMD + C_RARE + 0, "CMC" },
	{ 0x0000FF, 0x0000FC, 1, 00, NNN, NNN, NNN, C_CMD + 0, "CLD" },
	{ 0x0000FF, 0x0000FD, 1, 00, NNN, NNN, NNN, C_CMD + 0, "STD" },
	{ 0x0000FF, 0x0000FA, 1, 00, NNN, NNN, NNN, C_CMD + C_RARE + 0, "CLI" },
	{ 0x0000FF, 0x0000FB, 1, 00, NNN, NNN, NNN, C_CMD + C_RARE + 0, "STI" },
	{ 0x0000FF, 0x00008C, 1, FF, MRG, SGM, NNN, C_CMD + C_RARE + 0, "MOV" },
	{ 0x0000FF, 0x00008E, 1, FF, SGM, MRG, NNN, C_CMD + C_RARE + 0, "MOV" },
	{ 0x0000FE, 0x0000A6, 1, WW, MSO, MDE, NNN, C_CMD + 1, "CMPS" },
	{ 0x0000FE, 0x0000AC, 1, WW, MSO, NNN, NNN, C_CMD + 1, "LODS" },
	{ 0x0000FE, 0x0000A4, 1, WW, MDE, MSO, NNN, C_CMD + 1, "MOVS" },
	{ 0x0000FE, 0x0000AE, 1, WW, MDE, PAC, NNN, C_CMD + 1, "SCAS" },
	{ 0x0000FE, 0x0000AA, 1, WW, MDE, PAC, NNN, C_CMD + 1, "STOS" },
	{ 0x00FEFF, 0x00A4F3, 1, WW, MDE, MSO, PCX, C_REP + 1, "REP MOVS" },
	{ 0x00FEFF, 0x00ACF3, 1, WW, MSO, PAC, PCX, C_REP + C_RARE + 1, "REP LODS" },
	{ 0x00FEFF, 0x00AAF3, 1, WW, MDE, PAC, PCX, C_REP + 1, "REP STOS" },
	{ 0x00FEFF, 0x00A6F3, 1, WW, MDE, MSO, PCX, C_REP + 1, "REPE CMPS" },
	{ 0x00FEFF, 0x00AEF3, 1, WW, MDE, PAC, PCX, C_REP + 1, "REPE SCAS" },
	{ 0x00FEFF, 0x00A6F2, 1, WW, MDE, MSO, PCX, C_REP + 1, "REPNE CMPS" },
	{ 0x00FEFF, 0x00AEF2, 1, WW, MDE, PAC, PCX, C_REP + 1, "REPNE SCAS" },
	{ 0x0000FF, 0x0000EA, 1, 00, JMF, NNN, NNN, C_JMP + C_RARE + 0, "JMP" },
	{ 0x0038FF, 0x0028FF, 1, 00, MMS, NNN, NNN, C_JMP + C_RARE + 1, "JMP" },
	{ 0x0000FF, 0x00009A, 1, 00, JMF, NNN, NNN, C_CAL + C_RARE + 0, "CALL" },
	{ 0x0038FF, 0x0018FF, 1, 00, MMS, NNN, NNN, C_CAL + C_RARE + 1, "CALL" },
	{ 0x0000FF, 0x0000CB, 1, 00, PRF, NNN, NNN, C_RET + C_RARE + 0, "RETF" },
	{ 0x0000FF, 0x0000CA, 1, 00, IM2, PRF, NNN, C_RET + C_RARE + 0, "RETF" },
	{ 0x00FFFF, 0x00A40F, 2, 00, MRG, REG, IMS, C_CMD + 0, "SHLD" },
	{ 0x00FFFF, 0x00AC0F, 2, 00, MRG, REG, IMS, C_CMD + 0, "SHRD" },
	{ 0x00FFFF, 0x00A50F, 2, 00, MRG, REG, RCL, C_CMD + 0, "SHLD" },
	{ 0x00FFFF, 0x00AD0F, 2, 00, MRG, REG, RCL, C_CMD + 0, "SHRD" },
	{ 0x00F8FF, 0x00C80F, 2, 00, RCM, NNN, NNN, C_CMD + C_RARE + 0, "BSWAP" },
	{ 0x00FEFF, 0x00C00F, 2, WW, MRG, REG, NNN, C_CMD + C_RARE + 0, "XADD" },
	{ 0x0000FF, 0x0000E2, 1, LL, JOB, PCX, NNN, C_JMC + 0, "$LOOP*" },
	{ 0x0000FF, 0x0000E1, 1, LL, JOB, PCX, NNN, C_JMC + 0, "$LOOP*E" },
	{ 0x0000FF, 0x0000E0, 1, LL, JOB, PCX, NNN, C_JMC + 0, "$LOOP*NE" },
	{ 0x0000FF, 0x0000C8, 1, 00, IM2, IM1, NNN, C_CMD + 0, "ENTER" },
	{ 0x0000FE, 0x0000E4, 1, WP, RAC, IM1, NNN, C_CMD + C_RARE + 0, "IN" },
	{ 0x0000FE, 0x0000EC, 1, WP, RAC, RDX, NNN, C_CMD + C_RARE + 0, "IN" },
	{ 0x0000FE, 0x0000E6, 1, WP, IM1, RAC, NNN, C_CMD + C_RARE + 0, "OUT" },
	{ 0x0000FE, 0x0000EE, 1, WP, RDX, RAC, NNN, C_CMD + C_RARE + 0, "OUT" },
	{ 0x0000FE, 0x00006C, 1, WP, MDE, RDX, NNN, C_CMD + C_RARE + 1, "INS" },
	{ 0x0000FE, 0x00006E, 1, WP, RDX, MDE, NNN, C_CMD + C_RARE + 1, "OUTS" },
	{ 0x00FEFF, 0x006CF3, 1, WP, MDE, RDX, PCX, C_REP + C_RARE + 1, "REP INS" },
	{ 0x00FEFF, 0x006EF3, 1, WP, RDX, MDE, PCX, C_REP + C_RARE + 1, "REP OUTS" },
	{ 0x0000FF, 0x000037, 1, 00, NNN, NNN, NNN, C_CMD + C_RARE + 0, "AAA" },
	{ 0x0000FF, 0x00003F, 1, 00, NNN, NNN, NNN, C_CMD + C_RARE + 0, "AAS" },
	{ 0x00FFFF, 0x000AD4, 2, 00, NNN, NNN, NNN, C_CMD + C_RARE + 0, "AAM" },
	{ 0x0000FF, 0x0000D4, 1, 00, IM1, NNN, NNN, C_CMD + C_RARE + 0, "AAM" },
	{ 0x00FFFF, 0x000AD5, 2, 00, NNN, NNN, NNN, C_CMD + C_RARE + 0, "AAD" },
	{ 0x0000FF, 0x0000D5, 1, 00, IM1, NNN, NNN, C_CMD + C_RARE + 0, "AAD" },
	{ 0x0000FF, 0x000027, 1, 00, NNN, NNN, NNN, C_CMD + C_RARE + 0, "DAA" },
	{ 0x0000FF, 0x00002F, 1, 00, NNN, NNN, NNN, C_CMD + C_RARE + 0, "DAS" },
	{ 0x0000FF, 0x0000F4, 1, PR, NNN, NNN, NNN, C_PRI + C_RARE + 0, "HLT" },
	{ 0x0000FF, 0x00000E, 1, 00, SCM, NNN, NNN, C_PSH + C_RARE + 0, "PUSH" },
	{ 0x0000FF, 0x000016, 1, 00, SCM, NNN, NNN, C_PSH + C_RARE + 0, "PUSH" },
	{ 0x0000FF, 0x00001E, 1, 00, SCM, NNN, NNN, C_PSH + C_RARE + 0, "PUSH" },
	{ 0x0000FF, 0x000006, 1, 00, SCM, NNN, NNN, C_PSH + C_RARE + 0, "PUSH" },
	{ 0x00FFFF, 0x00A00F, 2, 00, SCM, NNN, NNN, C_PSH + C_RARE + 0, "PUSH" },
	{ 0x00FFFF, 0x00A80F, 2, 00, SCM, NNN, NNN, C_PSH + C_RARE + 0, "PUSH" },
	{ 0x0000FF, 0x00001F, 1, 00, SCM, NNN, NNN, C_POP + C_RARE + 0, "POP" },
	{ 0x0000FF, 0x000007, 1, 00, SCM, NNN, NNN, C_POP + C_RARE + 0, "POP" },
	{ 0x0000FF, 0x000017, 1, 00, SCM, NNN, NNN, C_POP + C_RARE + 0, "POP" },
	{ 0x00FFFF, 0x00A10F, 2, 00, SCM, NNN, NNN, C_POP + C_RARE + 0, "POP" },
	{ 0x00FFFF, 0x00A90F, 2, 00, SCM, NNN, NNN, C_POP + C_RARE + 0, "POP" },
	{ 0x0000FF, 0x0000D7, 1, 00, MXL, NNN, NNN, C_CMD + C_RARE + 1, "XLAT" },
	{ 0x00FFFF, 0x00BE0F, 2, 00, REG, MR1, NNN, C_CMD + 1, "MOVSX" },
	{ 0x00FFFF, 0x00B60F, 2, 00, REG, MR1, NNN, C_CMD + 1, "MOVZX" },
	{ 0x00FFFF, 0x00B70F, 2, 00, REG, MR2, NNN, C_CMD + 1, "MOVZX" },
	{ 0x0000FF, 0x00009B, 1, 00, NNN, NNN, NNN, C_CMD + 0, "WAIT" },
	{ 0x0000FF, 0x00009F, 1, 00, PAH, PFL, NNN, C_CMD + C_RARE + 0, "LAHF" },
	{ 0x0000FF, 0x00009E, 1, 00, PFL, PAH, NNN, C_CMD + C_RARE + 0, "SAHF" },
	{ 0x0000FF, 0x00009C, 1, 00, NNN, NNN, NNN, C_PSH + 0, "&PUSHF*" },
	{ 0x0000FF, 0x00009D, 1, 00, NNN, NNN, NNN, C_FLG + 0, "&POPF*" },
	{ 0x0000FF, 0x0000CD, 1, 00, IM1, NNN, NNN, C_CAL + C_RARE + 0, "INT" },
	{ 0x0000FF, 0x0000CC, 1, 00, NNN, NNN, NNN, C_CAL + C_RARE + 0, "INT3" },
	{ 0x0000FF, 0x0000CE, 1, 00, NNN, NNN, NNN, C_CAL + C_RARE + 0, "INTO" },
	{ 0x0000FF, 0x0000CF, 1, 00, NNN, NNN, NNN, C_RTF + C_RARE + 0, "&IRET*" },
	{ 0x00FFFF, 0x00900F, 2, CC, MR1, NNN, NNN, C_CMD + 0, "SETO" },
	{ 0x00FFFF, 0x00910F, 2, CC, MR1, NNN, NNN, C_CMD + 0, "SETNO" },
	{ 0x00FFFF, 0x00920F, 2, CC, MR1, NNN, NNN, C_CMD + 0, "SETB,SETC" },
	{ 0x00FFFF, 0x00930F, 2, CC, MR1, NNN, NNN, C_CMD + 0, "SETNB,SETNC" },
	{ 0x00FFFF, 0x00940F, 2, CC, MR1, NNN, NNN, C_CMD + 0, "SETE,SETZ" },
	{ 0x00FFFF, 0x00950F, 2, CC, MR1, NNN, NNN, C_CMD + 0, "SETNE,SETNZ" },
	{ 0x00FFFF, 0x00960F, 2, CC, MR1, NNN, NNN, C_CMD + 0, "SETBE,SETNA" },
	{ 0x00FFFF, 0x00970F, 2, CC, MR1, NNN, NNN, C_CMD + 0, "SETA,SETNBE" },
	{ 0x00FFFF, 0x00980F, 2, CC, MR1, NNN, NNN, C_CMD + 0, "SETS" },
	{ 0x00FFFF, 0x00990F, 2, CC, MR1, NNN, NNN, C_CMD + 0, "SETNS" },
	{ 0x00FFFF, 0x009A0F, 2, CC, MR1, NNN, NNN, C_CMD + C_RARE + 0, "SETPE,SETP" },
	{ 0x00FFFF, 0x009B0F, 2, CC, MR1, NNN, NNN, C_CMD + C_RARE + 0, "SETPO,SETNP" },
	{ 0x00FFFF, 0x009C0F, 2, CC, MR1, NNN, NNN, C_CMD + 0, "SETL,SETNGE" },
	{ 0x00FFFF, 0x009D0F, 2, CC, MR1, NNN, NNN, C_CMD + 0, "SETGE,SETNL" },
	{ 0x00FFFF, 0x009E0F, 2, CC, MR1, NNN, NNN, C_CMD + 0, "SETLE,SETNG" },
	{ 0x00FFFF, 0x009F0F, 2, CC, MR1, NNN, NNN, C_CMD + 0, "SETG,SETNLE" },
	{ 0x38FFFF, 0x20BA0F, 2, 00, MRG, IM1, NNN, C_CMD + C_RARE + 1, "BT" },
	{ 0x38FFFF, 0x28BA0F, 2, 00, MRG, IM1, NNN, C_CMD + C_RARE + 1, "BTS" },
	{ 0x38FFFF, 0x30BA0F, 2, 00, MRG, IM1, NNN, C_CMD + C_RARE + 1, "BTR" },
	{ 0x38FFFF, 0x38BA0F, 2, 00, MRG, IM1, NNN, C_CMD + C_RARE + 1, "BTC" },
	{ 0x00FFFF, 0x00A30F, 2, 00, MRG, REG, NNN, C_CMD + C_RARE + 1, "BT" },
	{ 0x00FFFF, 0x00AB0F, 2, 00, MRG, REG, NNN, C_CMD + C_RARE + 1, "BTS" },
	{ 0x00FFFF, 0x00B30F, 2, 00, MRG, REG, NNN, C_CMD + C_RARE + 1, "BTR" },
	{ 0x00FFFF, 0x00BB0F, 2, 00, MRG, REG, NNN, C_CMD + C_RARE + 1, "BTC" },
	{ 0x0000FF, 0x0000C5, 1, 00, REG, MML, NNN, C_CMD + C_RARE + 0, "LDS" },
	{ 0x0000FF, 0x0000C4, 1, 00, REG, MML, NNN, C_CMD + C_RARE + 0, "LES" },
	{ 0x00FFFF, 0x00B40F, 2, 00, REG, MML, NNN, C_CMD + C_RARE + 0, "LFS" },
	{ 0x00FFFF, 0x00B50F, 2, 00, REG, MML, NNN, C_CMD + C_RARE + 0, "LGS" },
	{ 0x00FFFF, 0x00B20F, 2, 00, REG, MML, NNN, C_CMD + C_RARE + 0, "LSS" },
	{ 0x0000FF, 0x000063, 1, 00, MRG, REG, NNN, C_CMD + C_RARE + 0, "ARPL" },
	{ 0x0000FF, 0x000062, 1, 00, REG, MMB, NNN, C_CMD + C_RARE + 0, "BOUND" },
	{ 0x00FFFF, 0x00BC0F, 2, 00, REG, MRG, NNN, C_CMD + C_RARE + 0, "BSF" },
	{ 0x00FFFF, 0x00BD0F, 2, 00, REG, MRG, NNN, C_CMD + C_RARE + 0, "BSR" },
	{ 0x00FFFF, 0x00060F, 2, PR, NNN, NNN, NNN, C_CMD + C_RARE + 0, "CLTS" },
	{ 0x00FFFF, 0x00400F, 2, CC, REG, MRG, NNN, C_CMD + 0, "CMOVO" },
	{ 0x00FFFF, 0x00410F, 2, CC, REG, MRG, NNN, C_CMD + 0, "CMOVNO" },
	{ 0x00FFFF, 0x00420F, 2, CC, REG, MRG, NNN, C_CMD + 0, "CMOVB,CMOVC" },
	{ 0x00FFFF, 0x00430F, 2, CC, REG, MRG, NNN, C_CMD + 0, "CMOVNB,CMOVNC" },
	{ 0x00FFFF, 0x00440F, 2, CC, REG, MRG, NNN, C_CMD + 0, "CMOVE,CMOVZ" },
	{ 0x00FFFF, 0x00450F, 2, CC, REG, MRG, NNN, C_CMD + 0, "CMOVNE,CMOVNZ" },
	{ 0x00FFFF, 0x00460F, 2, CC, REG, MRG, NNN, C_CMD + 0, "CMOVBE,CMOVNA" },
	{ 0x00FFFF, 0x00470F, 2, CC, REG, MRG, NNN, C_CMD + 0, "CMOVA,CMOVNBE" },
	{ 0x00FFFF, 0x00480F, 2, CC, REG, MRG, NNN, C_CMD + 0, "CMOVS" },
	{ 0x00FFFF, 0x00490F, 2, CC, REG, MRG, NNN, C_CMD + 0, "CMOVNS" },
	{ 0x00FFFF, 0x004A0F, 2, CC, REG, MRG, NNN, C_CMD + 0, "CMOVPE,CMOVP" },
	{ 0x00FFFF, 0x004B0F, 2, CC, REG, MRG, NNN, C_CMD + 0, "CMOVPO,CMOVNP" },
	{ 0x00FFFF, 0x004C0F, 2, CC, REG, MRG, NNN, C_CMD + 0, "CMOVL,CMOVNGE" },
	{ 0x00FFFF, 0x004D0F, 2, CC, REG, MRG, NNN, C_CMD + 0, "CMOVGE,CMOVNL" },
	{ 0x00FFFF, 0x004E0F, 2, CC, REG, MRG, NNN, C_CMD + 0, "CMOVLE,CMOVNG" },
	{ 0x00FFFF, 0x004F0F, 2, CC, REG, MRG, NNN, C_CMD + 0, "CMOVG,CMOVNLE" },
	{ 0x00FEFF, 0x00B00F, 2, WW, MRG, REG, NNN, C_CMD + C_RARE + 0, "CMPXCHG" },
	{ 0x38FFFF, 0x08C70F, 2, 00, MD8, NNN, NNN, C_CMD + C_RARE + 1, "CMPXCHG8B" },
	{ 0x00FFFF, 0x00A20F, 2, 00, NNN, NNN, NNN, C_CMD + 0, "CPUID" },
	{ 0x00FFFF, 0x00080F, 2, PR, NNN, NNN, NNN, C_CMD + C_RARE + 0, "INVD" },
	{ 0x00FFFF, 0x00020F, 2, 00, REG, MRG, NNN, C_CMD + C_RARE + 0, "LAR" },
	{ 0x00FFFF, 0x00030F, 2, 00, REG, MRG, NNN, C_CMD + C_RARE + 0, "LSL" },
	{ 0x38FFFF, 0x38010F, 2, PR, MR1, NNN, NNN, C_CMD + C_RARE + 0, "INVLPG" },
	{ 0x00FFFF, 0x00090F, 2, PR, NNN, NNN, NNN, C_CMD + C_RARE + 0, "WBINVD" },
	{ 0x38FFFF, 0x10010F, 2, PR, MM6, NNN, NNN, C_CMD + C_RARE + 0, "LGDT" },
	{ 0x38FFFF, 0x00010F, 2, 00, MM6, NNN, NNN, C_CMD + C_RARE + 0, "SGDT" },
	{ 0x38FFFF, 0x18010F, 2, PR, MM6, NNN, NNN, C_CMD + C_RARE + 0, "LIDT" },
	{ 0x38FFFF, 0x08010F, 2, 00, MM6, NNN, NNN, C_CMD + C_RARE + 0, "SIDT" },
	{ 0x38FFFF, 0x10000F, 2, PR, MR2, NNN, NNN, C_CMD + C_RARE + 0, "LLDT" },
	{ 0x38FFFF, 0x00000F, 2, 00, MR2, NNN, NNN, C_CMD + C_RARE + 0, "SLDT" },
	{ 0x38FFFF, 0x18000F, 2, PR, MR2, NNN, NNN, C_CMD + C_RARE + 0, "LTR" },
	{ 0x38FFFF, 0x08000F, 2, 00, MR2, NNN, NNN, C_CMD + C_RARE + 0, "STR" },
	{ 0x38FFFF, 0x30010F, 2, PR, MR2, NNN, NNN, C_CMD + C_RARE + 0, "LMSW" },
	{ 0x38FFFF, 0x20010F, 2, 00, MR2, NNN, NNN, C_CMD + C_RARE + 0, "SMSW" },
	{ 0x38FFFF, 0x20000F, 2, 00, MR2, NNN, NNN, C_CMD + C_RARE + 0, "VERR" },
	{ 0x38FFFF, 0x28000F, 2, 00, MR2, NNN, NNN, C_CMD + C_RARE + 0, "VERW" },
	{ 0xC0FFFF, 0xC0220F, 2, PR, CRX, RR4, NNN, C_CMD + C_RARE + 0, "MOV" },
	{ 0xC0FFFF, 0xC0200F, 2, 00, RR4, CRX, NNN, C_CMD + C_RARE + 0, "MOV" },
	{ 0xC0FFFF, 0xC0230F, 2, PR, DRX, RR4, NNN, C_CMD + C_RARE + 0, "MOV" },
	{ 0xC0FFFF, 0xC0210F, 2, PR, RR4, DRX, NNN, C_CMD + C_RARE + 0, "MOV" },
	{ 0x00FFFF, 0x00310F, 2, 00, NNN, NNN, NNN, C_CMD + C_RARE + 0, "RDTSC" },
	{ 0x00FFFF, 0x00320F, 2, PR, NNN, NNN, NNN, C_CMD + C_RARE + 0, "RDMSR" },
	{ 0x00FFFF, 0x00300F, 2, PR, NNN, NNN, NNN, C_CMD + C_RARE + 0, "WRMSR" },
	{ 0x00FFFF, 0x00330F, 2, PR, NNN, NNN, NNN, C_CMD + C_RARE + 0, "RDPMC" },
	{ 0x00FFFF, 0x00AA0F, 2, PR, NNN, NNN, NNN, C_RTF + C_RARE + 0, "RSM" },
	{ 0x00FFFF, 0x000B0F, 2, 00, NNN, NNN, NNN, C_CMD + C_RARE + 0, "UD2" },
	{ 0x00FFFF, 0x00340F, 2, 00, NNN, NNN, NNN, C_CMD + C_RARE + 0, "SYSENTER" },
	{ 0x00FFFF, 0x00350F, 2, PR, NNN, NNN, NNN, C_CMD + C_RARE + 0, "SYSEXIT" },
	{ 0x0000FF, 0x0000D6, 1, 00, NNN, NNN, NNN, C_CMD + C_RARE + 0, "SALC" },
	// FPU instructions. Never change the order of instructions!
	{ 0x00FFFF, 0x00F0D9, 2, 00, PS0, NNN, NNN, C_FLT + 0, "F2XM1" },
	{ 0x00FFFF, 0x00E0D9, 2, 00, PS0, NNN, NNN, C_FLT + 0, "FCHS" },
	{ 0x00FFFF, 0x00E1D9, 2, 00, PS0, NNN, NNN, C_FLT + 0, "FABS" },
	{ 0x00FFFF, 0x00E2DB, 2, 00, NNN, NNN, NNN, C_FLT + 0, "FCLEX" },
	{ 0x00FFFF, 0x00E3DB, 2, 00, NNN, NNN, NNN, C_FLT + 0, "FINIT" },
	{ 0x00FFFF, 0x00F6D9, 2, 00, NNN, NNN, NNN, C_FLT + 0, "FDECSTP" },
	{ 0x00FFFF, 0x00F7D9, 2, 00, NNN, NNN, NNN, C_FLT + 0, "FINCSTP" },
	{ 0x00FFFF, 0x00E4D9, 2, 00, PS0, NNN, NNN, C_FLT + 0, "FTST" },
	{ 0x00FFFF, 0x00FAD9, 2, 00, PS0, NNN, NNN, C_FLT + 0, "FSQRT" },
	{ 0x00FFFF, 0x00FED9, 2, 00, PS0, NNN, NNN, C_FLT + 0, "FSIN" },
	{ 0x00FFFF, 0x00FFD9, 2, 00, PS0, NNN, NNN, C_FLT + 0, "FCOS" },
	{ 0x00FFFF, 0x00FBD9, 2, 00, PS0, NNN, NNN, C_FLT + 0, "FSINCOS" },
	{ 0x00FFFF, 0x00F2D9, 2, 00, PS0, NNN, NNN, C_FLT + 0, "FPTAN" },
	{ 0x00FFFF, 0x00F3D9, 2, 00, PS0, PS1, NNN, C_FLT + 0, "FPATAN" },
	{ 0x00FFFF, 0x00F8D9, 2, 00, PS1, PS0, NNN, C_FLT + 0, "FPREM" },
	{ 0x00FFFF, 0x00F5D9, 2, 00, PS1, PS0, NNN, C_FLT + 0, "FPREM1" },
	{ 0x00FFFF, 0x00F1D9, 2, 00, PS0, PS1, NNN, C_FLT + 0, "FYL2X" },
	{ 0x00FFFF, 0x00F9D9, 2, 00, PS0, PS1, NNN, C_FLT + 0, "FYL2XP1" },
	{ 0x00FFFF, 0x00FCD9, 2, 00, PS0, NNN, NNN, C_FLT + 0, "FRNDINT" },
	{ 0x00FFFF, 0x00E8D9, 2, 00, NNN, NNN, NNN, C_FLT + 0, "FLD1" },
	{ 0x00FFFF, 0x00E9D9, 2, 00, NNN, NNN, NNN, C_FLT + 0, "FLDL2T" },
	{ 0x00FFFF, 0x00EAD9, 2, 00, NNN, NNN, NNN, C_FLT + 0, "FLDL2E" },
	{ 0x00FFFF, 0x00EBD9, 2, 00, NNN, NNN, NNN, C_FLT + 0, "FLDPI" },
	{ 0x00FFFF, 0x00ECD9, 2, 00, NNN, NNN, NNN, C_FLT + 0, "FLDLG2" },
	{ 0x00FFFF, 0x00EDD9, 2, 00, NNN, NNN, NNN, C_FLT + 0, "FLDLN2" },
	{ 0x00FFFF, 0x00EED9, 2, 00, NNN, NNN, NNN, C_FLT + 0, "FLDZ" },
	{ 0x00FFFF, 0x00FDD9, 2, 00, PS0, PS1, NNN, C_FLT + 0, "FSCALE" },
	{ 0x00FFFF, 0x00D0D9, 2, 00, NNN, NNN, NNN, C_FLT + 0, "FNOP" },
	{ 0x00FFFF, 0x00E0DF, 2, FF, RAX, NNN, NNN, C_FLT + 0, "FSTSW" },
	{ 0x00FFFF, 0x00E5D9, 2, 00, PS0, NNN, NNN, C_FLT + 0, "FXAM" },
	{ 0x00FFFF, 0x00F4D9, 2, 00, PS0, NNN, NNN, C_FLT + 0, "FXTRACT" },
	{ 0x00FFFF, 0x00D9DE, 2, 00, PS0, PS1, NNN, C_FLT + 0, "FCOMPP" },
	{ 0x00FFFF, 0x00E9DA, 2, 00, PS0, PS1, NNN, C_FLT + 0, "FUCOMPP" },
	{ 0x00F8FF, 0x00C0DD, 2, 00, RST, NNN, NNN, C_FLT + 0, "FFREE" },
	{ 0x00F8FF, 0x00C0DA, 2, 00, RS0, RST, NNN, C_FLT + 0, "FCMOVB" },
	{ 0x00F8FF, 0x00C8DA, 2, 00, RS0, RST, NNN, C_FLT + 0, "FCMOVE" },
	{ 0x00F8FF, 0x00D0DA, 2, 00, RS0, RST, NNN, C_FLT + 0, "FCMOVBE" },
	{ 0x00F8FF, 0x00D8DA, 2, 00, RS0, RST, NNN, C_FLT + 0, "FCMOVU" },
	{ 0x00F8FF, 0x00C0DB, 2, 00, RS0, RST, NNN, C_FLT + 0, "FCMOVNB" },
	{ 0x00F8FF, 0x00C8DB, 2, 00, RS0, RST, NNN, C_FLT + 0, "FCMOVNE" },
	{ 0x00F8FF, 0x00D0DB, 2, 00, RS0, RST, NNN, C_FLT + 0, "FCMOVNBE" },
	{ 0x00F8FF, 0x00D8DB, 2, 00, RS0, RST, NNN, C_FLT + 0, "FCMOVNU" },
	{ 0x00F8FF, 0x00F0DB, 2, 00, RS0, RST, NNN, C_FLT + 0, "FCOMI" },
	{ 0x00F8FF, 0x00F0DF, 2, 00, RS0, RST, NNN, C_FLT + 0, "FCOMIP" },
	{ 0x00F8FF, 0x00E8DB, 2, 00, RS0, RST, NNN, C_FLT + 0, "FUCOMI" },
	{ 0x00F8FF, 0x00E8DF, 2, 00, RS0, RST, NNN, C_FLT + 0, "FUCOMIP" },
	{ 0x00F8FF, 0x00C0D8, 2, 00, RS0, RST, NNN, C_FLT + 0, "FADD" },
	{ 0x00F8FF, 0x00C0DC, 2, 00, RST, RS0, NNN, C_FLT + 0, "FADD" },
	{ 0x00F8FF, 0x00C0DE, 2, 00, RST, RS0, NNN, C_FLT + 0, "FADDP" },
	{ 0x00F8FF, 0x00E0D8, 2, 00, RS0, RST, NNN, C_FLT + 0, "FSUB" },
	{ 0x00F8FF, 0x00E8DC, 2, 00, RST, RS0, NNN, C_FLT + 0, "FSUB" },
	{ 0x00F8FF, 0x00E8DE, 2, 00, RST, RS0, NNN, C_FLT + 0, "FSUBP" },
	{ 0x00F8FF, 0x00E8D8, 2, 00, RS0, RST, NNN, C_FLT + 0, "FSUBR" },
	{ 0x00F8FF, 0x00E0DC, 2, 00, RST, RS0, NNN, C_FLT + 0, "FSUBR" },
	{ 0x00F8FF, 0x00E0DE, 2, 00, RST, RS0, NNN, C_FLT + 0, "FSUBRP" },
	{ 0x00F8FF, 0x00C8D8, 2, 00, RS0, RST, NNN, C_FLT + 0, "FMUL" },
	{ 0x00F8FF, 0x00C8DC, 2, 00, RST, RS0, NNN, C_FLT + 0, "FMUL" },
	{ 0x00F8FF, 0x00C8DE, 2, 00, RST, RS0, NNN, C_FLT + 0, "FMULP" },
	{ 0x00F8FF, 0x00D0D8, 2, 00, RST, PS0, NNN, C_FLT + 0, "FCOM" },
	{ 0x00F8FF, 0x00D8D8, 2, 00, RST, PS0, NNN, C_FLT + 0, "FCOMP" },
	{ 0x00F8FF, 0x00E0DD, 2, 00, RST, PS0, NNN, C_FLT + 0, "FUCOM" },
	{ 0x00F8FF, 0x00E8DD, 2, 00, RST, PS0, NNN, C_FLT + 0, "FUCOMP" },
	{ 0x00F8FF, 0x00F0D8, 2, 00, RS0, RST, NNN, C_FLT + 0, "FDIV" },
	{ 0x00F8FF, 0x00F8DC, 2, 00, RST, RS0, NNN, C_FLT + 0, "FDIV" },
	{ 0x00F8FF, 0x00F8DE, 2, 00, RST, RS0, NNN, C_FLT + 0, "FDIVP" },
	{ 0x00F8FF, 0x00F8D8, 2, 00, RS0, RST, NNN, C_FLT + 0, "FDIVR" },
	{ 0x00F8FF, 0x00F0DC, 2, 00, RST, RS0, NNN, C_FLT + 0, "FDIVR" },
	{ 0x00F8FF, 0x00F0DE, 2, 00, RST, RS0, NNN, C_FLT + 0, "FDIVRP" },
	{ 0x00F8FF, 0x00C0D9, 2, 00, RST, NNN, NNN, C_FLT + 0, "FLD" },
	{ 0x00F8FF, 0x00D0DD, 2, 00, RST, PS0, NNN, C_FLT + 0, "FST" },
	{ 0x00F8FF, 0x00D8DD, 2, 00, RST, PS0, NNN, C_FLT + 0, "FSTP" },
	{ 0x00F8FF, 0x00C8D9, 2, 00, RST, PS0, NNN, C_FLT + 0, "FXCH" },
	{ 0x0038FF, 0x0000D8, 1, 00, MF4, PS0, NNN, C_FLT + 1, "FADD" },
	{ 0x0038FF, 0x0000DC, 1, 00, MF8, PS0, NNN, C_FLT + 1, "FADD" },
	{ 0x0038FF, 0x0000DA, 1, 00, MD4, PS0, NNN, C_FLT + 1, "FIADD" },
	{ 0x0038FF, 0x0000DE, 1, 00, MD2, PS0, NNN, C_FLT + 1, "FIADD" },
	{ 0x0038FF, 0x0020D8, 1, 00, MF4, PS0, NNN, C_FLT + 1, "FSUB" },
	{ 0x0038FF, 0x0020DC, 1, 00, MF8, PS0, NNN, C_FLT + 1, "FSUB" },
	{ 0x0038FF, 0x0020DA, 1, 00, MD4, PS0, NNN, C_FLT + 1, "FISUB" },
	{ 0x0038FF, 0x0020DE, 1, 00, MD2, PS0, NNN, C_FLT + 1, "FISUB" },
	{ 0x0038FF, 0x0028D8, 1, 00, MF4, PS0, NNN, C_FLT + 1, "FSUBR" },
	{ 0x0038FF, 0x0028DC, 1, 00, MF8, PS0, NNN, C_FLT + 1, "FSUBR" },
	{ 0x0038FF, 0x0028DA, 1, 00, MD4, PS0, NNN, C_FLT + 1, "FISUBR" },
	{ 0x0038FF, 0x0028DE, 1, 00, MD2, PS0, NNN, C_FLT + 1, "FISUBR" },
	{ 0x0038FF, 0x0008D8, 1, 00, MF4, PS0, NNN, C_FLT + 1, "FMUL" },
	{ 0x0038FF, 0x0008DC, 1, 00, MF8, PS0, NNN, C_FLT + 1, "FMUL" },
	{ 0x0038FF, 0x0008DA, 1, 00, MD4, PS0, NNN, C_FLT + 1, "FIMUL" },
	{ 0x0038FF, 0x0008DE, 1, 00, MD2, PS0, NNN, C_FLT + 1, "FIMUL" },
	{ 0x0038FF, 0x0010D8, 1, 00, MF4, PS0, NNN, C_FLT + 1, "FCOM" },
	{ 0x0038FF, 0x0010DC, 1, 00, MF8, PS0, NNN, C_FLT + 1, "FCOM" },
	{ 0x0038FF, 0x0018D8, 1, 00, MF4, PS0, NNN, C_FLT + 1, "FCOMP" },
	{ 0x0038FF, 0x0018DC, 1, 00, MF8, PS0, NNN, C_FLT + 1, "FCOMP" },
	{ 0x0038FF, 0x0030D8, 1, 00, MF4, PS0, NNN, C_FLT + 1, "FDIV" },
	{ 0x0038FF, 0x0030DC, 1, 00, MF8, PS0, NNN, C_FLT + 1, "FDIV" },
	{ 0x0038FF, 0x0030DA, 1, 00, MD4, PS0, NNN, C_FLT + 1, "FIDIV" },
	{ 0x0038FF, 0x0030DE, 1, 00, MD2, PS0, NNN, C_FLT + 1, "FIDIV" },
	{ 0x0038FF, 0x0038D8, 1, 00, MF4, PS0, NNN, C_FLT + 1, "FDIVR" },
	{ 0x0038FF, 0x0038DC, 1, 00, MF8, PS0, NNN, C_FLT + 1, "FDIVR" },
	{ 0x0038FF, 0x0038DA, 1, 00, MD4, PS0, NNN, C_FLT + 1, "FIDIVR" },
	{ 0x0038FF, 0x0038DE, 1, 00, MD2, PS0, NNN, C_FLT + 1, "FIDIVR" },
	{ 0x0038FF, 0x0020DF, 1, 00, MDA, NNN, NNN, C_FLT + C_RARE + 1, "FBLD" },
	{ 0x0038FF, 0x0030DF, 1, 00, MDA, PS0, NNN, C_FLT + C_RARE + 1, "FBSTP" },
	{ 0x0038FF, 0x0010DE, 1, 00, MD2, PS0, NNN, C_FLT + 1, "FICOM" },
	{ 0x0038FF, 0x0010DA, 1, 00, MD4, PS0, NNN, C_FLT + 1, "FICOM" },
	{ 0x0038FF, 0x0018DE, 1, 00, MD2, PS0, NNN, C_FLT + 1, "FICOMP" },
	{ 0x0038FF, 0x0018DA, 1, 00, MD4, PS0, NNN, C_FLT + 1, "FICOMP" },
	{ 0x0038FF, 0x0000DF, 1, 00, MD2, NNN, NNN, C_FLT + 1, "FILD" },
	{ 0x0038FF, 0x0000DB, 1, 00, MD4, NNN, NNN, C_FLT + 1, "FILD" },
	{ 0x0038FF, 0x0028DF, 1, 00, MD8, NNN, NNN, C_FLT + 1, "FILD" },
	{ 0x0038FF, 0x0010DF, 1, 00, MD2, PS0, NNN, C_FLT + 1, "FIST" },
	{ 0x0038FF, 0x0010DB, 1, 00, MD4, PS0, NNN, C_FLT + 1, "FIST" },
	{ 0x0038FF, 0x0018DF, 1, 00, MD2, PS0, NNN, C_FLT + 1, "FISTP" },
	{ 0x0038FF, 0x0018DB, 1, 00, MD4, PS0, NNN, C_FLT + 1, "FISTP" },
	{ 0x0038FF, 0x0038DF, 1, 00, MD8, PS0, NNN, C_FLT + 1, "FISTP" },
	{ 0x0038FF, 0x0000D9, 1, 00, MF4, NNN, NNN, C_FLT + 1, "FLD" },
	{ 0x0038FF, 0x0000DD, 1, 00, MF8, NNN, NNN, C_FLT + 1, "FLD" },
	{ 0x0038FF, 0x0028DB, 1, 00, MFA, NNN, NNN, C_FLT + 1, "FLD" },
	{ 0x0038FF, 0x0010D9, 1, 00, MF4, PS0, NNN, C_FLT + 1, "FST" },
	{ 0x0038FF, 0x0010DD, 1, 00, MF8, PS0, NNN, C_FLT + 1, "FST" },
	{ 0x0038FF, 0x0018D9, 1, 00, MF4, PS0, NNN, C_FLT + 1, "FSTP" },
	{ 0x0038FF, 0x0018DD, 1, 00, MF8, PS0, NNN, C_FLT + 1, "FSTP" },
	{ 0x0038FF, 0x0038DB, 1, 00, MFA, PS0, NNN, C_FLT + 1, "FSTP" },
	{ 0x0038FF, 0x0028D9, 1, 00, MB2, NNN, NNN, C_FLT + 0, "FLDCW" },
	{ 0x0038FF, 0x0038D9, 1, 00, MB2, NNN, NNN, C_FLT + 0, "FSTCW" },
	{ 0x0038FF, 0x0020D9, 1, 00, MFE, NNN, NNN, C_FLT + 0, "FLDENV" },
	{ 0x0038FF, 0x0030D9, 1, 00, MFE, NNN, NNN, C_FLT + 0, "FSTENV" },
	{ 0x0038FF, 0x0020DD, 1, 00, MFS, NNN, NNN, C_FLT + 0, "FRSTOR" },
	{ 0x0038FF, 0x0030DD, 1, 00, MFS, NNN, NNN, C_FLT + 0, "FSAVE" },
	{ 0x0038FF, 0x0038DD, 1, 00, MB2, NNN, NNN, C_FLT + 0, "FSTSW" },
	{ 0x38FFFF, 0x08AE0F, 2, 00, MFX, NNN, NNN, C_FLT + 0, "FXRSTOR" },
	{ 0x38FFFF, 0x00AE0F, 2, 00, MFX, NNN, NNN, C_FLT + 0, "FXSAVE" },
	{ 0x00FFFF, 0x00E0DB, 2, 00, NNN, NNN, NNN, C_FLT + 0, "FENI" },
	{ 0x00FFFF, 0x00E1DB, 2, 00, NNN, NNN, NNN, C_FLT + 0, "FDISI" },
	// MMX instructions. Length of MMX operand fields (in bytes) is added to the
	// type, length of 0 means 8-byte MMX operand.
	{ 0x00FFFF, 0x00770F, 2, 00, NNN, NNN, NNN, C_MMX + 0, "EMMS" },
	{ 0x00FFFF, 0x006E0F, 2, 00, RMX, MR4, NNN, C_MMX + 0, "MOVD" },
	{ 0x00FFFF, 0x007E0F, 2, 00, MR4, RMX, NNN, C_MMX + 0, "MOVD" },
	{ 0x00FFFF, 0x006F0F, 2, 00, RMX, MR8, NNN, C_MMX + 0, "MOVQ" },
	{ 0x00FFFF, 0x007F0F, 2, 00, MR8, RMX, NNN, C_MMX + 0, "MOVQ" },
	{ 0x00FFFF, 0x00630F, 2, 00, RMX, MR8, NNN, C_MMX + 2, "PACKSSWB" },
	{ 0x00FFFF, 0x006B0F, 2, 00, RMX, MR8, NNN, C_MMX + 4, "PACKSSDW" },
	{ 0x00FFFF, 0x00670F, 2, 00, RMX, MR8, NNN, C_MMX + 2, "PACKUSWB" },
	{ 0x00FFFF, 0x00FC0F, 2, 00, RMX, MR8, NNN, C_MMX + 1, "PADDB" },
	{ 0x00FFFF, 0x00FD0F, 2, 00, RMX, MR8, NNN, C_MMX + 2, "PADDW" },
	{ 0x00FFFF, 0x00FE0F, 2, 00, RMX, MR8, NNN, C_MMX + 4, "PADDD" },
	{ 0x00FFFF, 0x00F80F, 2, 00, RMX, MR8, NNN, C_MMX + 1, "PSUBB" },
	{ 0x00FFFF, 0x00F90F, 2, 00, RMX, MR8, NNN, C_MMX + 2, "PSUBW" },
	{ 0x00FFFF, 0x00FA0F, 2, 00, RMX, MR8, NNN, C_MMX + 4, "PSUBD" },
	{ 0x00FFFF, 0x00EC0F, 2, 00, RMX, MR8, NNN, C_MMX + 1, "PADDSB" },
	{ 0x00FFFF, 0x00ED0F, 2, 00, RMX, MR8, NNN, C_MMX + 2, "PADDSW" },
	{ 0x00FFFF, 0x00E80F, 2, 00, RMX, MR8, NNN, C_MMX + 1, "PSUBSB" },
	{ 0x00FFFF, 0x00E90F, 2, 00, RMX, MR8, NNN, C_MMX + 2, "PSUBSW" },
	{ 0x00FFFF, 0x00DC0F, 2, 00, RMX, MR8, NNN, C_MMX + 1, "PADDUSB" },
	{ 0x00FFFF, 0x00DD0F, 2, 00, RMX, MR8, NNN, C_MMX + 2, "PADDUSW" },
	{ 0x00FFFF, 0x00D80F, 2, 00, RMX, MR8, NNN, C_MMX + 1, "PSUBUSB" },
	{ 0x00FFFF, 0x00D90F, 2, 00, RMX, MR8, NNN, C_MMX + 2, "PSUBUSW" },
	{ 0x00FFFF, 0x00DB0F, 2, 00, RMX, MR8, NNN, C_MMX + 0, "PAND" },
	{ 0x00FFFF, 0x00DF0F, 2, 00, RMX, MR8, NNN, C_MMX + 0, "PANDN" },
	{ 0x00FFFF, 0x00740F, 2, 00, RMX, MR8, NNN, C_MMX + 1, "PCMPEQB" },
	{ 0x00FFFF, 0x00750F, 2, 00, RMX, MR8, NNN, C_MMX + 2, "PCMPEQW" },
	{ 0x00FFFF, 0x00760F, 2, 00, RMX, MR8, NNN, C_MMX + 4, "PCMPEQD" },
	{ 0x00FFFF, 0x00640F, 2, 00, RMX, MR8, NNN, C_MMX + 1, "PCMPGTB" },
	{ 0x00FFFF, 0x00650F, 2, 00, RMX, MR8, NNN, C_MMX + 2, "PCMPGTW" },
	{ 0x00FFFF, 0x00660F, 2, 00, RMX, MR8, NNN, C_MMX + 4, "PCMPGTD" },
	{ 0x00FFFF, 0x00F50F, 2, 00, RMX, MR8, NNN, C_MMX + 2, "PMADDWD" },
	{ 0x00FFFF, 0x00E50F, 2, 00, RMX, MR8, NNN, C_MMX + 2, "PMULHW" },
	{ 0x00FFFF, 0x00D50F, 2, 00, RMX, MR8, NNN, C_MMX + 2, "PMULLW" },
	{ 0x00FFFF, 0x00EB0F, 2, 00, RMX, MR8, NNN, C_MMX + 0, "POR" },
	{ 0x00FFFF, 0x00F10F, 2, 00, RMX, MR8, NNN, C_MMX + 2, "PSLLW" },
	{ 0x38FFFF, 0x30710F, 2, 00, MR8, IM1, NNN, C_MMX + 2, "PSLLW" },
	{ 0x00FFFF, 0x00F20F, 2, 00, RMX, MR8, NNN, C_MMX + 4, "PSLLD" },
	{ 0x38FFFF, 0x30720F, 2, 00, MR8, IM1, NNN, C_MMX + 4, "PSLLD" },
	{ 0x00FFFF, 0x00F30F, 2, 00, RMX, MR8, NNN, C_MMX + 0, "PSLLQ" },
	{ 0x38FFFF, 0x30730F, 2, 00, MR8, IM1, NNN, C_MMX + 0, "PSLLQ" },
	{ 0x00FFFF, 0x00E10F, 2, 00, RMX, MR8, NNN, C_MMX + 2, "PSRAW" },
	{ 0x38FFFF, 0x20710F, 2, 00, MR8, IM1, NNN, C_MMX + 2, "PSRAW" },
	{ 0x00FFFF, 0x00E20F, 2, 00, RMX, MR8, NNN, C_MMX + 4, "PSRAD" },
	{ 0x38FFFF, 0x20720F, 2, 00, MR8, IM1, NNN, C_MMX + 4, "PSRAD" },
	{ 0x00FFFF, 0x00D10F, 2, 00, RMX, MR8, NNN, C_MMX + 2, "PSRLW" },
	{ 0x38FFFF, 0x10710F, 2, 00, MR8, IM1, NNN, C_MMX + 2, "PSRLW" },
	{ 0x00FFFF, 0x00D20F, 2, 00, RMX, MR8, NNN, C_MMX + 4, "PSRLD" },
	{ 0x38FFFF, 0x10720F, 2, 00, MR8, IM1, NNN, C_MMX + 4, "PSRLD" },
	{ 0x00FFFF, 0x00D30F, 2, 00, RMX, MR8, NNN, C_MMX + 0, "PSRLQ" },
	{ 0x38FFFF, 0x10730F, 2, 00, MR8, IM1, NNN, C_MMX + 0, "PSRLQ" },
	{ 0x00FFFF, 0x00680F, 2, 00, RMX, MR8, NNN, C_MMX + 1, "PUNPCKHBW" },
	{ 0x00FFFF, 0x00690F, 2, 00, RMX, MR8, NNN, C_MMX + 2, "PUNPCKHWD" },
	{ 0x00FFFF, 0x006A0F, 2, 00, RMX, MR8, NNN, C_MMX + 4, "PUNPCKHDQ" },
	{ 0x00FFFF, 0x00600F, 2, 00, RMX, MR8, NNN, C_MMX + 1, "PUNPCKLBW" },
	{ 0x00FFFF, 0x00610F, 2, 00, RMX, MR8, NNN, C_MMX + 2, "PUNPCKLWD" },
	{ 0x00FFFF, 0x00620F, 2, 00, RMX, MR8, NNN, C_MMX + 4, "PUNPCKLDQ" },
	{ 0x00FFFF, 0x00EF0F, 2, 00, RMX, MR8, NNN, C_MMX + 0, "PXOR" },
	// AMD extentions to MMX command set (including Athlon/PIII extentions).
	{ 0x00FFFF, 0x000E0F, 2, 00, NNN, NNN, NNN, C_MMX + 0, "FEMMS" },
	{ 0x38FFFF, 0x000D0F, 2, 00, MD8, NNN, NNN, C_MMX + 0, "PREFETCH" },
	{ 0x38FFFF, 0x080D0F, 2, 00, MD8, NNN, NNN, C_MMX + 0, "PREFETCHW" },
	{ 0x00FFFF, 0x00F70F, 2, 00, RMX, RR8, PDI, C_MMX + 1, "MASKMOVQ" },
	{ 0x00FFFF, 0x00E70F, 2, 00, MD8, RMX, NNN, C_MMX + 0, "MOVNTQ" },
	{ 0x00FFFF, 0x00E00F, 2, 00, RMX, MR8, NNN, C_MMX + 1, "PAVGB" },
	{ 0x00FFFF, 0x00E30F, 2, 00, RMX, MR8, NNN, C_MMX + 2, "PAVGW" },
	{ 0x00FFFF, 0x00C50F, 2, 00, RR4, RMX, IM1, C_MMX + 2, "PEXTRW" },
	{ 0x00FFFF, 0x00C40F, 2, 00, RMX, MR2, IM1, C_MMX + 2, "PINSRW" },
	{ 0x00FFFF, 0x00EE0F, 2, 00, RMX, MR8, NNN, C_MMX + 2, "PMAXSW" },
	{ 0x00FFFF, 0x00DE0F, 2, 00, RMX, MR8, NNN, C_MMX + 1, "PMAXUB" },
	{ 0x00FFFF, 0x00EA0F, 2, 00, RMX, MR8, NNN, C_MMX + 2, "PMINSW" },
	{ 0x00FFFF, 0x00DA0F, 2, 00, RMX, MR8, NNN, C_MMX + 1, "PMINUB" },
	{ 0x00FFFF, 0x00D70F, 2, 00, RG4, RR8, NNN, C_MMX + 1, "PMOVMSKB" },
	{ 0x00FFFF, 0x00E40F, 2, 00, RMX, MR8, NNN, C_MMX + 2, "PMULHUW" },
	{ 0x38FFFF, 0x00180F, 2, 00, MD8, NNN, NNN, C_MMX + 0, "PREFETCHNTA" },
	{ 0x38FFFF, 0x08180F, 2, 00, MD8, NNN, NNN, C_MMX + 0, "PREFETCHT0" },
	{ 0x38FFFF, 0x10180F, 2, 00, MD8, NNN, NNN, C_MMX + 0, "PREFETCHT1" },
	{ 0x38FFFF, 0x18180F, 2, 00, MD8, NNN, NNN, C_MMX + 0, "PREFETCHT2" },
	{ 0x00FFFF, 0x00F60F, 2, 00, RMX, MR8, NNN, C_MMX + 1, "PSADBW" },
	{ 0x00FFFF, 0x00700F, 2, 00, RMX, MR8, IM1, C_MMX + 2, "PSHUFW" },
	{ 0xFFFFFF, 0xF8AE0F, 2, 00, NNN, NNN, NNN, C_MMX + 0, "SFENCE" },
	// AMD 3DNow! instructions (including Athlon extentions).
	{ 0x00FFFF, 0xBF0F0F, 2, 00, RMX, MR8, NNN, C_NOW + 1, "PAVGUSB" },
	{ 0x00FFFF, 0x9E0F0F, 2, 00, R3D, MRD, NNN, C_NOW + 4, "PFADD" },
	{ 0x00FFFF, 0x9A0F0F, 2, 00, R3D, MRD, NNN, C_NOW + 4, "PFSUB" },
	{ 0x00FFFF, 0xAA0F0F, 2, 00, R3D, MRD, NNN, C_NOW + 4, "PFSUBR" },
	{ 0x00FFFF, 0xAE0F0F, 2, 00, R3D, MRD, NNN, C_NOW + 4, "PFACC" },
	{ 0x00FFFF, 0x900F0F, 2, 00, RMX, MRD, NNN, C_NOW + 4, "PFCMPGE" },
	{ 0x00FFFF, 0xA00F0F, 2, 00, RMX, MRD, NNN, C_NOW + 4, "PFCMPGT" },
	{ 0x00FFFF, 0xB00F0F, 2, 00, RMX, MRD, NNN, C_NOW + 4, "PFCMPEQ" },
	{ 0x00FFFF, 0x940F0F, 2, 00, R3D, MRD, NNN, C_NOW + 4, "PFMIN" },
	{ 0x00FFFF, 0xA40F0F, 2, 00, R3D, MRD, NNN, C_NOW + 4, "PFMAX" },
	{ 0x00FFFF, 0x0D0F0F, 2, 00, R3D, MR8, NNN, C_NOW + 4, "PI2FD" },
	{ 0x00FFFF, 0x1D0F0F, 2, 00, RMX, MRD, NNN, C_NOW + 4, "PF2ID" },
	{ 0x00FFFF, 0x960F0F, 2, 00, R3D, MRD, NNN, C_NOW + 4, "PFRCP" },
	{ 0x00FFFF, 0x970F0F, 2, 00, R3D, MRD, NNN, C_NOW + 4, "PFRSQRT" },
	{ 0x00FFFF, 0xB40F0F, 2, 00, R3D, MRD, NNN, C_NOW + 4, "PFMUL" },
	{ 0x00FFFF, 0xA60F0F, 2, 00, R3D, MRD, NNN, C_NOW + 4, "PFRCPIT1" },
	{ 0x00FFFF, 0xA70F0F, 2, 00, R3D, MRD, NNN, C_NOW + 4, "PFRSQIT1" },
	{ 0x00FFFF, 0xB60F0F, 2, 00, R3D, MRD, NNN, C_NOW + 4, "PFRCPIT2" },
	{ 0x00FFFF, 0xB70F0F, 2, 00, RMX, MR8, NNN, C_NOW + 2, "PMULHRW" },
	{ 0x00FFFF, 0x1C0F0F, 2, 00, RMX, MRD, NNN, C_NOW + 4, "PF2IW" },
	{ 0x00FFFF, 0x8A0F0F, 2, 00, R3D, MRD, NNN, C_NOW + 4, "PFNACC" },
	{ 0x00FFFF, 0x8E0F0F, 2, 00, R3D, MRD, NNN, C_NOW + 4, "PFPNACC" },
	{ 0x00FFFF, 0x0C0F0F, 2, 00, R3D, MR8, NNN, C_NOW + 4, "PI2FW" },
	{ 0x00FFFF, 0xBB0F0F, 2, 00, R3D, MRD, NNN, C_NOW + 4, "PSWAPD" },
	// Some alternative mnemonics for Assembler, not used by Disassembler (so
	// implicit pseudooperands are not marked).
	{ 0x0000FF, 0x0000A6, 1, 00, NNN, NNN, NNN, C_CMD + 0, "CMPSB" },
	{ 0x00FFFF, 0x00A766, 2, 00, NNN, NNN, NNN, C_CMD + 0, "CMPSW" },
	{ 0x0000FF, 0x0000A7, 1, 00, NNN, NNN, NNN, C_CMD + 0, "CMPSD" },
	{ 0x0000FF, 0x0000AC, 1, 00, NNN, NNN, NNN, C_CMD + 0, "LODSB" },
	{ 0x00FFFF, 0x00AD66, 2, 00, NNN, NNN, NNN, C_CMD + 0, "LODSW" },
	{ 0x0000FF, 0x0000AD, 1, 00, NNN, NNN, NNN, C_CMD + 0, "LODSD" },
	{ 0x0000FF, 0x0000A4, 1, 00, NNN, NNN, NNN, C_CMD + 0, "MOVSB" },
	{ 0x00FFFF, 0x00A566, 2, 00, NNN, NNN, NNN, C_CMD + 0, "MOVSW" },
	{ 0x0000FF, 0x0000A5, 1, 00, NNN, NNN, NNN, C_CMD + 0, "MOVSD" },
	{ 0x0000FF, 0x0000AE, 1, 00, NNN, NNN, NNN, C_CMD + 0, "SCASB" },
	{ 0x00FFFF, 0x00AF66, 1, 00, NNN, NNN, NNN, C_CMD + 0, "SCASW" },
	{ 0x0000FF, 0x0000AF, 1, 00, NNN, NNN, NNN, C_CMD + 0, "SCASD" },
	{ 0x0000FF, 0x0000AA, 1, 00, NNN, NNN, NNN, C_CMD + 0, "STOSB" },
	{ 0x00FFFF, 0x00AB66, 2, 00, NNN, NNN, NNN, C_CMD + 0, "STOSW" },
	{ 0x0000FF, 0x0000AB, 1, 00, NNN, NNN, NNN, C_CMD + 0, "STOSD" },
	{ 0x00FFFF, 0x00A4F3, 1, 00, NNN, NNN, NNN, C_REP + 0, "REP MOVSB" },
	{ 0xFFFFFF, 0xA5F366, 2, 00, NNN, NNN, NNN, C_REP + 0, "REP MOVSW" },
	{ 0x00FFFF, 0x00A5F3, 1, 00, NNN, NNN, NNN, C_REP + 0, "REP MOVSD" },
	{ 0x00FFFF, 0x00ACF3, 1, 00, NNN, NNN, NNN, C_REP + 0, "REP LODSB" },
	{ 0xFFFFFF, 0xADF366, 2, 00, NNN, NNN, NNN, C_REP + 0, "REP LODSW" },
	{ 0x00FFFF, 0x00ADF3, 1, 00, NNN, NNN, NNN, C_REP + 0, "REP LODSD" },
	{ 0x00FFFF, 0x00AAF3, 1, 00, NNN, NNN, NNN, C_REP + 0, "REP STOSB" },
	{ 0xFFFFFF, 0xABF366, 2, 00, NNN, NNN, NNN, C_REP + 0, "REP STOSW" },
	{ 0x00FFFF, 0x00ABF3, 1, 00, NNN, NNN, NNN, C_REP + 0, "REP STOSD" },
	{ 0x00FFFF, 0x00A6F3, 1, 00, NNN, NNN, NNN, C_REP + 0, "REPE CMPSB" },
	{ 0xFFFFFF, 0xA7F366, 2, 00, NNN, NNN, NNN, C_REP + 0, "REPE CMPSW" },
	{ 0x00FFFF, 0x00A7F3, 1, 00, NNN, NNN, NNN, C_REP + 0, "REPE CMPSD" },
	{ 0x00FFFF, 0x00AEF3, 1, 00, NNN, NNN, NNN, C_REP + 0, "REPE SCASB" },
	{ 0xFFFFFF, 0xAFF366, 2, 00, NNN, NNN, NNN, C_REP + 0, "REPE SCASW" },
	{ 0x00FFFF, 0x00AFF3, 1, 00, NNN, NNN, NNN, C_REP + 0, "REPE SCASD" },
	{ 0x00FFFF, 0x00A6F2, 1, 00, NNN, NNN, NNN, C_REP + 0, "REPNE CMPSB" },
	{ 0xFFFFFF, 0xA7F266, 2, 00, NNN, NNN, NNN, C_REP + 0, "REPNE CMPSW" },
	{ 0x00FFFF, 0x00A7F2, 1, 00, NNN, NNN, NNN, C_REP + 0, "REPNE CMPSD" },
	{ 0x00FFFF, 0x00AEF2, 1, 00, NNN, NNN, NNN, C_REP + 0, "REPNE SCASB" },
	{ 0xFFFFFF, 0xAFF266, 2, 00, NNN, NNN, NNN, C_REP + 0, "REPNE SCASW" },
	{ 0x00FFFF, 0x00AFF2, 1, 00, NNN, NNN, NNN, C_REP + 0, "REPNE SCASD" },
	{ 0x0000FF, 0x00006C, 1, 00, NNN, NNN, NNN, C_CMD + C_RARE + 0, "INSB" },
	{ 0x00FFFF, 0x006D66, 2, 00, NNN, NNN, NNN, C_CMD + C_RARE + 0, "INSW" },
	{ 0x0000FF, 0x00006D, 1, 00, NNN, NNN, NNN, C_CMD + C_RARE + 0, "INSD" },
	{ 0x0000FF, 0x00006E, 1, 00, NNN, NNN, NNN, C_CMD + C_RARE + 0, "OUTSB" },
	{ 0x00FFFF, 0x006F66, 2, 00, NNN, NNN, NNN, C_CMD + C_RARE + 0, "OUTSW" },
	{ 0x0000FF, 0x00006F, 1, 00, NNN, NNN, NNN, C_CMD + C_RARE + 0, "OUTSD" },
	{ 0x00FFFF, 0x006CF3, 1, 00, NNN, NNN, NNN, C_REP + 0, "REP INSB" },
	{ 0xFFFFFF, 0x6DF366, 2, 00, NNN, NNN, NNN, C_REP + 0, "REP INSW" },
	{ 0x00FFFF, 0x006DF3, 1, 00, NNN, NNN, NNN, C_REP + 0, "REP INSD" },
	{ 0x00FFFF, 0x006EF3, 1, 00, NNN, NNN, NNN, C_REP + 0, "REP OUTSB" },
	{ 0xFFFFFF, 0x6FF366, 2, 00, NNN, NNN, NNN, C_REP + 0, "REP OUTSW" },
	{ 0x00FFFF, 0x006FF3, 1, 00, NNN, NNN, NNN, C_REP + 0, "REP OUTSD" },
	{ 0x0000FF, 0x0000E1, 1, 00, JOB, NNN, NNN, C_JMC + 0, "$LOOP*Z" },
	{ 0x0000FF, 0x0000E0, 1, 00, JOB, NNN, NNN, C_JMC + 0, "$LOOP*NZ" },
	{ 0x0000FF, 0x00009B, 1, 00, NNN, NNN, NNN, C_CMD + 0, "FWAIT" },
	{ 0x0000FF, 0x0000D7, 1, 00, NNN, NNN, NNN, C_CMD + 0, "XLATB" },
	{ 0x00FFFF, 0x00C40F, 2, 00, RMX, RR4, IM1, C_MMX + 2, "PINSRW" },
	{ 0x00FFFF, 0x0020CD, 2, 00, VXD, NNN, NNN, C_CAL + C_RARE + 0, "VxDCall" },
	// Pseudocommands used by Assembler for masked search only.
	{ 0x0000F0, 0x000070, 1, CC, JOB, NNN, NNN, C_JMC + 0, "JCC" },
	{ 0x00F0FF, 0x00800F, 2, CC, JOW, NNN, NNN, C_JMC + 0, "JCC" },
	{ 0x00F0FF, 0x00900F, 2, CC, MR1, NNN, NNN, C_CMD + 1, "SETCC" },
	{ 0x00F0FF, 0x00400F, 2, CC, REG, MRG, NNN, C_CMD + 0, "CMOVCC" },
	// End of command table.
	{ 0x000000, 0x000000, 0, 00, NNN, NNN, NNN, C_CMD + 0, "" }
};

#endif