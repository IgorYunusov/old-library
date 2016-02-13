/*************************************************************************
 *
 * FILE NAME : assemble.h
 *
 * ROLLRAT SOFTWARE Robust Assembler (RASM)
 *
 *
 * LANGUAGE : ANSI C
 * CREATION : 2015.01.03
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com, rollrat.software@gmail.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#ifndef _ASSEMBLE_
#define _ASSEMBLE_

#include "rasm.h"

#define RASM_ERROR_NOT_FIND_ENDIAN_TYPE				0x0001
#define RASM_ERROR_NOT_FIND_COMMA					0x0002
#define RASM_ERROR_NOT_COLLECT_REGISTER_NAME		0x0004
#define RASM_ERROR_NOT_FOUND_ERROR					0x0008
#define RASM_ERROR_INCOLLECT_OPERAND_LENGTH			0x0010

#define ModRM_EA_Ref								0
#define ModRM_EA_Ref8								1
#define ModRM_EA_Ref32								2
#define ModRM_EA_Reg								3

//
//	확장 그룹, Op2,3를 제외한 모든 옵코드 목록
//
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
	std,
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

void rasm_assemble_procedureinit();
void rasm_assemble_init(POption option);
BYTE *rasm_assemble_code(char *buffer, POption option, u32 *opcode, size_t *bytesize, u32 *error_n);

#endif