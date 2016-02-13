/***

   RollRat Software Project.
   Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
   ProcedureAssembler.h

Purpose:

   Evaluates a string as though it were an expression,
   and returns a result fastly.
   For Intel x86 Processor.

Author:

   08-27-2015:   HyunJun Jeong, Creation

***/

#ifndef _PROCEDURE_ASSEMBLER_
#define _PROCEDURE_ASSEMBLER_

#include <vector>
#include <Windows.h>

#define AX				1
#define CX				2
#define DX				3
#define BX				4
#define SP				5
#define BP				6
#define SI				7
#define DI				8
#define AL				9
#define CL				10
#define DL				11
#define BL				12
#define AH				13
#define CH				14
#define DH				15
#define BH				16

#define EAX				1
#define ECX				2
#define EDC				3
#define EBX				4
#define ESP				5
#define EBP				6
#define ESI				7
#define EDI				8

#define BitReversion(bit)	~(DWORD)(bit)+1

typedef enum _Internal_asmdc {
	// g1 [80-83]
	add = 0,
	or,
	adc,
	sbb,
	and,
	sub,
	xor,
	cmp,
	// g1a [8f]
	pop,
	// g2 [C0, C1, D0, D1, D2, D3] , Shift Grp 2
	rol,
	ror,
	rcl,
	rcr,
	shl,
	shr,
	_0,
	sar,
	// g3 [f6, f7]
	test,
	_1,
	not,
	neg,
	mul,
	imul,
	_div,
	idiv,
	// g4 [fe]  g5 [ff]
	inc,
	dec,
	ncall, // near call
	fcall, // far call
	njmp,
	fjmp,
	pushd64,
	// g6 [0f 00]
	sldt,
	str,
	lldt,
	ltr,
	verr,
	verw,
	// g7 [0f 01]
	sgdt,
	sidt,
	lgdt,
	lidt,
	smsw,
	_2,
	lmsw,
	invlpg,
	// g8 [0f ba]
	_3,
	_4,
	_5,
	_6,
	bt,
	bts,
	btr,
	btc,

	// another and rasm word
	mov,
	lw,
	push,
	pusha, pushad,
	popa, popad,
	call,
	gdt,
	ldgt,
	ret,
	nop,
	jcc,
	db,
	les,
	lds,
	bound,
	xchg,
	in,
	out,
	hlt,
	cmc,
	lock,
	repne,
	rep,
	repe,
	loop,
	loopne, loopnz,
	loope, loopz,
	lea,
	iret,
	_int,
	_int3,
	into,
	clc,
	stc,
	cli,
	sti,
	cld,
//	std,
	enter,
	leave,
	cbw, cwde, cdqe,
	cwd, cdq, cqo,
	fwait, wait,
	pushf, pushd, pushq,
	popf, popd, popq,
	shaf,
	lahf,
	stos, stob,
	stow, stod, stoq,
	lods, lodb,
	lodw, lodd, lodq,
	scas, scab,
	scaw, scad, scaq,

	jmp,
	jo,
	jno,
	jb, jnae, jc,
	jnb, jae, jnc,
	jz, je,
	jnz, jne,
	jbe, jna,
	jnbe, ja,
	js,
	jns,
	jp, jpe,
	jnp, jpo,
	jl,
	jnge,
	jnl, jge,
	jle, jng,
	jnle, jg,


	// float
	// [D8 Opmap ModR/M 00~BF]
	// [DC Opmap ModR/M 00~BF]
	fadd,
	fcom,
	fsub,
	fdiv,
	fmul,
	fcmop,
	fsubr,
	fdivr,
	// [D9 Opmap ModR/M 00~BF]
	fld,
	_7,
	fst,
	fstp,
	fldenv,
	fldcw,
	fstenv,
	fstcw,
	// [DA Opmap ModR/M 00~BF]
	// [DE Opmap ModR/M 00~BF]
	fiadd,
	fimul,
	ficom,
	ficomp,
	fisub,
	fisubr,
	fidiv,
	fidivr,
	// [DB Opmap ModR/M 00~BF]
	fild,
	fisttp,
	fist,
	fistp,
	_8,
	bfld,
	_9,
	bfstp,
	// [DD Opmap ModR/M 00~BF]
	_fld,
	_fisttp,
	_fst,
	_fstp,
	_frstor,
	_10,
	_fsave,
	_fstsw,
	// [DF Opmap ModR/M 00~BF]
	_w_fild,
	_ffisttp,
	_fist,
	_w_fistp,
	_fbld,
	_q_fild,
	_fbstp,
	_q_fistp
};

typedef enum class _tmp_001_ {
	_Cdecl,
	_Syscall,
	_Pascal,
	_Fastcall,
	_Stdcall,
}	CALLING_CONVENTION;

typedef enum class _opcode_ {
	_N_ATH_ADD,
	_N_ATH_ADC,
	_N_ATH_SBB,
	_N_ATH_SUB,
	_N_ATH_IMUL,
	_N_ATH_DIV,
	_N_LGC_OR,
	_N_LGC_AND,
	_N_LGC_XOR,
	_N_FUN_INC,
	_N_FUN_DEC,
	_N_FUN_CMP,
	_N_FUN_TEST,
	_N_FUN_MOV,
	_N_FUN_CALL,
	_N_FUN_RET,
	_N_FUN_RETN,
	_N_FUN_PUSH,
	_N_FUN_POP,
	_N_FUN_PUSHA,
	_N_FUN_POPA,
	_N_JMP,
	_N_JO,
	_N_JNO,
	_N_JB,
	_N_JNB,
	_N_JZ,
	_N_JNZ,
	_N_JBE,
	_N_JA,
	_N_JS,
	_N_JNS,
	_N_JP,
	_N_JNP,
	_N_JNL,
	_N_JLE,
	_N_JNLE,
}	OP_CODE_SPECIFIC;

typedef enum class _prefix_ {
	_PF_ONLY,		// �Ϲ� pusha, ������
	_PF_SHIFT,
	_PF_RET,
	_PF_JCC,
	_PF_CALL,
	_PF_STACK,		// push, pop
	_PF_ONE,		// inc dec
	_PF_ATH,		// add adc sbb sub
	_PF_FLT,		// mul div
	_PF_MOV,
	_PF_CMP,		// cmp test
	_PF_MR,			// mem-reg, reg	: [ebp-n]
	_PF_RM,			// reg, mem-reg
	_PF_OM,			// mem-reg		ex) call eax
	_PF_LOOP,
	_PF_BT,
	_PF_ALIGN,
	_PF_DB,			// DB
}	PREFIX;

typedef enum _tmp_010_
{
	_Not_Find_Comma = 1,
}	SYNTAX_ERROR;

#define IMM			// Direct put

typedef struct {
	char name[10];
	PREFIX prefix;
	BYTE option[4];
}	INSTRUCTIONS;

static const INSTRUCTIONS inst_info[] = {
	{"ADD", PREFIX::_PF_ATH, 0x05}
};

//-------------------------------------
//
//		Char Pointer Utility
//
//-------------------------------------

class PointerUtility
{
public:

	template<class _Func>
	static void skip_function(char const const* *target, _Func& func)
	{
		const char *p = *target;

		while (*p)
			if (!func(*p))
				return;
			else
				p++;

		*target = p;
	}

	template<class _Func>
	static void find_function(char const const* *target, _Func& func)
	{
		const char *p = *target;

		while (*p)
			if (func(*p))
			{
				*target = p;
				return;
			}
			else
				p++;
	}

	static int get_integer_from_oct(const char *t)
	{
		const char *_Ptr = t;
		int g = 0, h = 1;
		if (*_Ptr == '-')
			*_Ptr++, h = -1;
		for (; *_Ptr != 'o'; _Ptr++)
			g *= 8, g += *_Ptr & 0xf;
		return g*h;
	}

	static int get_integer_from_decimal(const char *t)
	{
		const char *_Ptr = t;
		int g = 0, h = 1;
		if (*_Ptr == '-')
			*_Ptr++, h = -1;
		for (; '0' <= *_Ptr && *_Ptr <= '9'; _Ptr++)
			 g *= 10, g += *_Ptr & 0xf;
		return g*h;
	}

	static int get_integer_from_hex(const char *t)
	{
		const char *_Ptr = t;
		int g = 0, h = 1;
		if (*_Ptr == '-')
			*_Ptr++, h = -1;
		for (; *_Ptr != 'h'; _Ptr++)
			g *= 16, g += ('0' <= *_Ptr  && *_Ptr  <= '9') ? 
				(*_Ptr & 0xf) 
					: 
				(tolower(*_Ptr)  - 'a' + 0xa);
		return g*h;
	}
};

//-------------------------------------
//
//		Register Reference
//
//-------------------------------------

typedef enum class _tmp_003_ {
	_Reg_Normal,
	_Reg_Reference,
	_Reg_SingleReference,
	_Reg_Numberic,		// imm
}	REG_TYPE;

typedef enum class _tmp_004_ {
	_Sign_Plus,
	_Sign_Minus,
	_Sign_Multiple,
	_Sign_Multiple_Plus,
	_Sign_Multiple_Minus,
}	REG_SIGN;

/*
	@RegisterType : ���۷��忡 �� �� �ִ� �κ��� ������.
*/
class RegisterType 
{
public:

	RegisterType()
		: isprocess(false)
	{
	}

	bool operator!()
	{
		return !isprocess;
	}

	bool set(const char *str) 
	{
		const char *ptr = str;
		int thirdc;

		isprocess = true;

		// �߿� : �� �Լ��� ������ ���� ������ ó������ ���մϴ�.
		//	[<num2> + <reg> * <num1>]
		//	[<num1> * <reg> + <num2>]
		//	[<num2>	+ <num1> * <reg>]
		//	[<num1> * <reg>]
		//	[<num1> + <reg>]

		//
		//	[<reg> * <num1> + <num2>] ������ ��� �� �÷��״� Ȱ��ȭ��
		//
		thirdc = FALSE;

		//
		//	�������� ������[$]�� Ȯ���ϰ� ������ �������͸�,
		//	������ ���ڿ� �� ���� ���̶� ��ġ�Ǵ��� Ȯ����.
		//
		if (*ptr++ != '$') 
		{
			ptr--;
			if (isdigit(*ptr) || isxdigit(*ptr) || *ptr == '-' || *ptr == '+') 
			{
				const char * t = ptr;
				int get;

				type = REG_TYPE::_Reg_Numberic;
				
				//
				//	�� ���� ���ڸ� Ȯ���ϱ� ���� �����͸� �ű�
				//
				PointerUtility::skip_function(&t, isspace);
				PointerUtility::skip_function(&t, isxdigit);
				PointerUtility::skip_function(&t, isspace);

				if (*t == 'o')
					get = PointerUtility::get_integer_from_oct(ptr);
				else if (*t == 'h')
					get = PointerUtility::get_integer_from_hex(ptr);
				else
					get = PointerUtility::get_integer_from_decimal(ptr);

				first = get;

				return true;
			} else {
				return false;
			}
		}

		//
		//	rxx, exx�� ������ ���۷��带 �м���
		//	����Ʈ ���� 16bit�� ���۷�����
		//
RE:		switch(*ptr)
		{
		case '[':
			type = REG_TYPE::_Reg_Reference; 
			PointerUtility::skip_function(&ptr, isspace);
			ptr++;
			goto RE;
		{ case 'e': bit = 32; goto SET; }
	 // { case 'r': bit = 64; goto SET; }
		{ default:  bit = 16; break; }
SET:
			if (type != REG_TYPE::_Reg_Reference)
				type = REG_TYPE::_Reg_Normal;
			ptr++;
		}
		
		//
		//	exx���� e�� �ѱ� �������͸� �м���
		//	������ ��� 16bit�� ����
		//
		switch(*ptr)
		{
		case 'a':
			if(*(ptr+1)=='x')
				first = AX;
			else if (*(ptr+1)=='l')
				first = AL;
			else if (*(ptr+1)=='h')
				first = AH;
			break;
		case 'b':
			if(*(ptr+1)=='p')
				first = BP;
			else if(*(ptr+1)=='x')
				first = BX;
			else if (*(ptr+1)=='l')
				first = BL;
			else if (*(ptr+1)=='h')
				first = BH;
			break;
		case 'c':
			if(*(ptr+1)=='x')
				first = CX;
			else if (*(ptr+1)=='l')
				first = CL;
			else if (*(ptr+1)=='h')
				first = CH;
			break;
		case 'd':
			if(*(ptr+1)=='i')
				first = DI;
			else if(*(ptr+1)=='x')
				first = DX;
			else if (*(ptr+1)=='l')
				first = DL;
			else if (*(ptr+1)=='h')
				first = DH;
			break;
		case 's':
			if(*(ptr+1)=='p')
				first = SP;
			else if(*(ptr+1)=='i')
				first = SI;
			break;
		}
		
		//
		//	�Ϲ� �������� �����̸� �� �̻� �м��� �ʿ������
		//	�׳� ����
		//
		if(type == REG_TYPE::_Reg_Normal)
			return true;

		//
		//	�м��ߴ� ���������� �� ���̰� 2�̹Ƿ�
		//
		ptr += 2;
		PointerUtility::skip_function(&ptr, isspace);

		//
		//	�Ϲ� ������ �������� ����
		//
		if (*ptr == ']') {
			type = REG_TYPE::_Reg_SingleReference;
			return true;
		}

		//
		//	']'�� ������ ������ ���� �� �ִ� ��������
		//
		if (*ptr == '+')
			sign = REG_SIGN::_Sign_Plus;
		else if (*ptr == '-')
			sign = REG_SIGN::_Sign_Minus;
		else if (*ptr == '*')
			sign = REG_SIGN::_Sign_Multiple;
		PointerUtility::skip_function(&ptr, isspace);

		ptr++;

		//
		//	16������ ���ڿ��� ��� ffh��, a2h���� ���ڰ� ���� �������� �� �ִµ�
		//	�� ��쿣 �м��� ���� ������ ����Ѵ�. �׷� ���� 16������ ��쿣 
		//	0ffh, 0a2h�� ���� ��Ÿ����� �Ѵ�.
		//
		if('0' <= *ptr && *ptr <= '9')
		{
			const char * t = ptr;
			int get;
			for (; *t != ']' && *t; t++)
				if (*t == '-' || *t == '+') {

					//
					//	[<reg> * <num1> + <num2>] �������� Ȯ����
					//
					thirdc = TRUE;
					break;
				}

			//
			//	*t == NULL�̸� ���� ��ȣ�� ������ �ʾ����Ƿ� �翬�� ����
			//
			if (!*t--)
				return false;

			//
			//	']'�� ������ ���� ������ ���ԵǾ����� �� �����Ƿ�
			//
			for (; isspace(*t); t--)
				;

			if (*t == 'o')
				get = PointerUtility::get_integer_from_oct(ptr);
			else if (*t == 'h')
				get = PointerUtility::get_integer_from_hex(ptr);
			else
				get = PointerUtility::get_integer_from_decimal(ptr);

			second = get;
			type = REG_TYPE::_Reg_Reference;

			if (thirdc == TRUE) {
				//
				//	�� �ڵ屸���� ��ⱸ���� ������
				//
				const char * ptr = t+1;
				int get;
				PointerUtility::skip_function(&ptr, isspace);

				if (*ptr == '+')
					sign = REG_SIGN::_Sign_Multiple_Plus;
				else if (*ptr == '-')
					sign = REG_SIGN::_Sign_Multiple_Minus;
				PointerUtility::skip_function(&ptr, isspace);

				for (; *t != ']' && *t; t++)
					;

				if (!*t--)
					return false;

				for (; isspace(*t); t--)
					;
				
				if (*t == 'o')
					get = PointerUtility::get_integer_from_oct(ptr);
				else if (*t == 'h')
					get = PointerUtility::get_integer_from_hex(ptr);
				else
					get = PointerUtility::get_integer_from_decimal(ptr);

				third = get;
			}
		}
		else
		{
			//
			//	���ڰ� ������ ���� ��쿣 ������ ����Ѵ�.
			//��������
		}

		return true;
	}

	const char *m_ptr;
	int first;
	int second;
	int third;
	int bit;
	REG_SIGN sign;
	REG_TYPE type;

	bool isprocess;
};

//-------------------------------------
//
//		Opcode ����� �м���
//
//-------------------------------------

class Command
{
public:

	Command(const char *ptr)
	{

	}
};



//-------------------------------------
//
//		Assembler Main Module
//
//-------------------------------------

class ProcedureAssembler {
public:

	ProcedureAssembler(const std::vector<char *> m_lines)
		: m_lines(m_lines)
	{
	}

	std::vector<BYTE> AssembleCode()
	{
	}

private:
	
	std::vector<BYTE> GetCode(const char *ptr)
	{
		RegisterType e1, e2, e3;

		// get @cmm [$e1[, $e2[, $e3]]]
		PointerUtility::find_function(&ptr, isspace);
		PointerUtility::skip_function(&ptr, isspace);
		
		//
		//	�� ������, ���� ��� MASM�� ��� DWORD PTR ���� ������ ó���� �� �ֽ��ϴ�
		//
		if (!e1.set(ptr))
			goto CODE_GET;

		//
		//	�޸��� ���� ���, �ϴ� ������ �ɾ��
		//	���� ��� @imul eax ebx, 1 ���� ��� eax������ �޸��� ������ ������ �ɸ�
		//
		PointerUtility::find_function(&ptr, isspace);
		if (*(ptr - 1) != ',')
			error_n |= _Not_Find_Comma;
		PointerUtility::skip_function(&ptr, isspace);
		
		// for future
		if (!e2.set(ptr))
			goto CODE_GET;
		
		//
		//	e2�� NULL�� �ƴ϶�� �� 3�� ������ �̻��̹Ƿ� �޸��� ������
		//	������ ����� �Լ� ����
		//
		if (error_n & _Not_Find_Comma)
			return;
		
		PointerUtility::find_function(&ptr, isspace);
		if (*(ptr - 1) != ',')
			error_n |= _Not_Find_Comma;
		PointerUtility::skip_function(&ptr, isspace);

		// for future
		if (!e2.set(ptr))
			goto CODE_GET;
		if (error_n & _Not_Find_Comma)
			return;

	CODE_GET:

		//
		//	4�� �����ڰ� �ƴϸ� �̰����� ������ detach��
		//
		if (error_n & _Not_Find_Comma)
			error_n ^= _Not_Find_Comma;

		int reg_size;
		reg_size = !!e1 + !!e2 + !!e3;

	}

	void SkipWS(const char const **ptr)
	{
		const char *p = *ptr;

		while ( *p ) {
			if ( !isspace(*p) )
				break;
			p++;
		}

		*ptr = p;
	}

private:

	int _$;
	int _p$;
	int error_n;
	std::vector<BYTE> m_bytes;
	std::vector<char *> m_lines;
};

//void *rasm_test(std::vector<BYTE> xtarr)
//{
//	HANDLE mem_handle = CreateFileMapping( 
//			INVALID_HANDLE_VALUE, 
//			NULL, 
//			PAGE_EXECUTE_READWRITE, 
//			0,  
//			xtarr.size(), 
//			NULL);
//	
//	void * function = (void *)(MapViewOfFile(
//			mem_handle,
//			FILE_MAP_ALL_ACCESS | FILE_MAP_EXECUTE,
//			0,
//			0,
//			xtarr.size()));
//	BYTE* byteset= new BYTE[xtarr.size()], *ptr=byteset;
//	//std::copy(xtarr.begin(), xtarr.end(), byteset);
//	auto begin = xtarr.begin();
//	for (; begin != xtarr.end(); ++ptr, ++begin)
//		*ptr = *begin;
//	memcpy(function, byteset, xtarr.size());
//	int x = ((int(_stdcall*)(int))function)(2);
//	std::cout << "����� : "<<x;
//	return function;
//}

#endif