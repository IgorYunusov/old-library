/****************************************************************
 *																*
 *																*
 *			ROLLRAT AUTO PERSONA VERBOTER LIBROFEX				*
 *																*
 *					SPIN OFF PROJECT Vol 1						*
 *																*
 *		COPYRIGHT (c) rollrat. 2013. ALL RIGHTS RESERVED.		*
 *																*
 *																*
 ****************************************************************/

#ifndef _EFLAG
#define _EFLAG

/*--------------------------------------------------------------------------------------------

	IA EFLAGS Register Structure(Status Word)

	Table A-1
	+==========================================================================+
	|31  ~  22|21| 20| 19|18|17|16|15|14|13|12|11|10| 9| 8| 7| 6|5| 4|3| 2|1| 0|
	| Reserved|ID|VIP|VIF|AC|VF|RF| 0|NT| IOPL|OF|DF|IF|TF|SF|ZF|0|AF|0|PF|1|CF|
	|         |X |X  |X  |X |X |X |  |X |X    |S |C |X |X |S |S | |S | |S | |S |
	+==========================================================================+
						X ; System Flag		C ; Control Flag	S ; Status Flag

	Assembly EFLAGS Status | Set(1), Clear(0)

	Status Flag List
		Carry Flag(CF)    : STC CLC CMC, get Carry Out
		Parity Flag(PF)   : If First bit = 1
		Adjust Flag(AF)   : If (P 3 Bit) as Carry set! -> BCD Algorithm
		Zero Flag(ZF)     : If Thing = 0
		Sign Flag(SF)     : If Most Significant Byte(MSB) = 1 -> Adder-Subtractor
		Overflow Flag(OF) : If Thing(without MSB) > Max

	Control Flag List
		Direction Flag(DF): MOVS LODS CMPS STOS SCAS, STD set CLD clear
			* If 1=> High Address ~> Low Address
			  else   Low Address  ~> High Address.

	System Flag List
		Trap Flag(TF)     : While Debugging, single step mode = 1
		Interrupt Flag(If): Control Interrupt Processor Error CCC
		I/O Priviliege Level(IOPL) : Command to Program or Task, I/O Special Level
		Nested Task Flag(NT) : Manage Interrupted or Called Task connection.
		Resume Flag(RF)   : Control Processor Debug Excutition
		Virtual 8086 Flag(VF) : None
		Alignment Check Flag(AC) : Using Memory Array, when Memory reference
		Virtual Interrupt Flag(VIF) : Virtual Mod Extended Admission
		Virutal Interrupt Pending Flag(VIP) : Pending Y/X
		Identification Flag(ID) : CPUID provide status

	Reserved
		Mean : DO NOT use this flag cus' will used in future

--------------------------------------------------------------------------------------------*/

#define EFLAGS								unsigned int

#define EFLAGS_LOCK							0x00000002	// 0000 0000 0000 0000 0000 0000 0000 0010

#define EFLAGS_ADJUST						0x00000010	// 0000 0000 0000 0000 0000 0000 0001 0000
#define EFLAGS_ALIGNMENTCHECK				0x00040000	// 0000 0000 0000 0100 0000 0000 0000 0000
#define EFLAGS_CARRY						0x00000001	// 0000 0000 0000 0000 0000 0000 0000 0001
#define EFLAGS_DIRECTION					0x00000400	// 0000 0000 0000 0000 0000 0100 0000 0000
#define EFLAGS_IDENTIFICATION				0x00200000	// 0000 0000 0010 0000 0000 0000 0000 0000
#define EFLAGS_INTERRUPT					0x00000200	// 0000 0000 0000 0000 0000 0010 0000 0000
#define EFLAGS_IOPRIVILIEGE					0x00003000	// 0000 0000 0000 0000 0011 0000 0000 0000
#define EFLAGS_NESTEDTASK					0x00004000	// 0000 0000 0000 0000 0100 0000 0000 0000
#define EFLAGS_OVERFLOW						0x00000800	// 0000 0000 0000 0000 0000 1000 0000 0000
#define EFLAGS_PARITY						0x00000004	// 0000 0000 0000 0000 0000 0000 0000 0100
#define EFLAGS_RESUME						0x00010000	// 0000 0000 0000 0001 0000 0000 0000 0000
#define EFLAGS_SIGN							0x00000080	// 0000 0000 0000 0000 0000 0000 1000 0000
#define EFLAGS_TRAP							0x00000100	// 0000 0000 0000 0000 0000 0001 0000 0000
#define EFLAGS_VIRTUAL8086					0x00020000	// 0000 0000 0000 0010 0000 0000 0000 0000
#define EFLAGS_VIRTUALINTERRUPT				0x00080000	// 0000 0000 0000 1000 0000 0000 0000 0000
#define EFLAGS_VIRTUALINTERRUPTPENDING		0x00100000	// 0000 0000 0001 0000 0000 0000 0000 0000
#define EFLAGS_ZERO							0x00000040	// 0000 0000 0000 0000 0000 0000 0100 0000

#endif