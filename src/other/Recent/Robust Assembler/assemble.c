/*************************************************************************
 *
 * FILE NAME : assemble.c
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

/*
 *      !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 *      !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 *	!!!!!!!IF YOU CHANGE TABS TO SPACES, YOU WILL BE KILLED!!!!!!!
 *      !!!!!!!!!!!!!!DOING SO FUCKS THE BUILD PROCESS!!!!!!!!!!!!!!!!
 *      !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 *      !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 */ // ms humor

///////////////////////////////////////////////
//////
//////		for Intel Processor
//////
///////////////////////////////////////////////

#include <stdio.h>
#include "rasm.h"
#include "utility.h"
#include "rocket.h"
#include "assemble.h"
#include "register.h"

static Option rasm_option;
static u32 rasm_error_n;

/*
	the address of the line,
	current address of bytes file or the procedure.
	this variable using in jump method or filling last bytes.
*/
static u32 rasm_$;
static u32 rams_p$;

static void rasm_process_command(enum _Internal_asmdc iasc, BYTE *bytes, size_t *bytesize, PREGISTER e1, PREGISTER e2, PREGISTER e3);

/*
	@rasm_assemble_init : rasm line ����� ����� �ʱ�ȭ��

	@option          : �ʱ� �ɼ��� ������
*/
void rasm_assemble_init(POption option)
{
	rasm_$ = 0;
	rams_p$ = 0;
	rasm_error_n = 0;
	rasm_option = *option;
}

/*
	@rasm_assemble_procedureinit : ���ν��� ����� ����� �ʱ�ȭ��
*/
void rasm_assemble_procedureinit()
{
	rams_p$ = 0;
}

static void rasm_push_byte(BYTE target, BYTE *bytes, size_t *bytesize)
{
	bytes[(*bytesize)++] = target;
}

static void rasm_push_word(WORD target, BYTE *bytes, size_t *bytesize)
{
	if(rasm_option.endian == RASM_OPTION_SMALLENDIAN) {

		//
		//	WORD�� ĸ���Ͽ� ����ص� ������ �׷��� CPU ����� ���� ����
		//	target ���°� ���ϹǷ� ĸ���ϸ� �ȵȴ�.
		//
		bytes[(*bytesize)++] = (BYTE)(target);
		bytes[(*bytesize)++] = (BYTE)(target >> 8);
	} else if (rasm_option.endian == RASM_OPTION_BIGENDIAN) {
		bytes[(*bytesize)++] = (BYTE)(target >> 8);
		bytes[(*bytesize)++] = (BYTE)(target);
	} else {
		rasm_error_n |= RASM_ERROR_NOT_FIND_ENDIAN_TYPE;
	}
}

static void rasm_push_dword(DWORD target, BYTE *bytes, size_t *bytesize)
{
	if(rasm_option.endian == RASM_OPTION_SMALLENDIAN) {
		bytes[(*bytesize)++] = (BYTE)(((target) >> ((0) * 8)) & 0xff);
		bytes[(*bytesize)++] = (BYTE)(((target) >> ((1) * 8)) & 0xff);
		bytes[(*bytesize)++] = (BYTE)(((target) >> ((2) * 8)) & 0xff);
		bytes[(*bytesize)++] = (BYTE)(((target) >> ((3) * 8)) & 0xff);
	} else if (rasm_option.endian == RASM_OPTION_BIGENDIAN) {
		bytes[(*bytesize)++] = (BYTE)(((target) >> ((3) * 8)) & 0xff);
		bytes[(*bytesize)++] = (BYTE)(((target) >> ((2) * 8)) & 0xff);
		bytes[(*bytesize)++] = (BYTE)(((target) >> ((1) * 8)) & 0xff);
		bytes[(*bytesize)++] = (BYTE)(((target) >> ((0) * 8)) & 0xff);
	} else {
		rasm_error_n |= RASM_ERROR_NOT_FIND_ENDIAN_TYPE;
	}
}

/*
	@rasm_get_byte_from_command : rasm line ��������� ó�� �Լ�

	@buffer    : ó���� ���ڿ� [��, @�� ����]
	@bytes     : ���� ����Ʈ�� ����� ������
	@bytesize  : ����Ʈ ����� ����Ű�� ������
*/
static void rasm_get_byte_from_command(char *buffer, BYTE *bytes, size_t *bytesize)
{
	// no hash
	PREGISTER e1, e2, e3;
	char *ptr = buffer;

	e1 = 0;
	e2 = 0;
	e3 = 0;
	
	// get @cmm [$e1[, $e2[, $e3]]] 
	_util_find_function(&ptr, _isspace);
	_util_skip_function(&ptr, _isspace);
	// for future

	//
	//	�� ����, ���� ��� MASM�� ��� DWORD PTR ���� ������ ó���� �� �ֽ��ϴ�
	//
	if(!(e1 = get_register(ptr)))
		goto CODE_GET;

	//
	//	�޸��� ���� ���, �ϴ� ������ �ɾ��
	//	���� ��� @imul eax ebx, 1 ���� ��� eax������ �޸��� ������ ������ �ɸ�
	//
	_util_find_function(&ptr, _isspace);
	if (*(ptr - 1) != ',')
		rasm_error_n |= RASM_ERROR_NOT_FIND_COMMA;
	_util_skip_function(&ptr, _isspace);

	// for future
	if(!(e2 = get_register(ptr)))
		goto CODE_GET;

	//
	//	e2�� NULL�� �ƴ϶�� �� 3�� ������ �̻��̹Ƿ� �޸��� ������
	//	������ ����� �Լ� ����
	//
	if (rasm_error_n & RASM_ERROR_NOT_FIND_COMMA)
		return;

	_util_find_function(&ptr, _isspace);
	if (*(ptr - 1) != ',')
		rasm_error_n |= RASM_ERROR_NOT_FIND_COMMA;
	_util_skip_function(&ptr, _isspace);

	// for future
	if(!(e3 = get_register(ptr)))
		goto CODE_GET;
	if (rasm_error_n & RASM_ERROR_NOT_FIND_COMMA)
		return;

CODE_GET:

	//
	//	4�� �����ڰ� �ƴϸ� �̰����� ������ detach��
	//
	if (rasm_error_n & RASM_ERROR_NOT_FIND_COMMA)
		rasm_error_n ^= RASM_ERROR_NOT_FIND_COMMA;

	// i'll make hashtable in released mode !
	// this version is beta program !
	
	//
	//	�̷� ���� ����� ȿ������ �������Ƿ� �ݵ�� �ؽ��� �������մϴ�
	//
	if(!_strcmp_asc(buffer, "add")) {
		rasm_process_command(add, bytes, bytesize, e1, e2, e3);
	} else if (!_strcmp_asc(buffer, "sub"  )) {
		rasm_process_command(sub, bytes, bytesize, e1, e2, e3);
	} else if (!_strcmp_asc(buffer, "mul"  )) {
		rasm_process_command(mul, bytes, bytesize, e1, e2, e3);
	} else if (!_strcmp_asc(buffer, "div"  )) {
		rasm_process_command(_div, bytes, bytesize, e1, e2, e3);
	} else if (!_strcmp_asc(buffer, "xor"  )) {
		rasm_process_command(xor, bytes, bytesize, e1, e2, e3);
	} else if (!_strcmp_asc(buffer, "or"   )) {
		rasm_process_command(or, bytes, bytesize, e1, e2, e3);
	} else if (!_strcmp_asc(buffer, "and"  )) {
		rasm_process_command(and, bytes, bytesize, e1, e2, e3);
	} else if (!_strcmp_asc(buffer, "not"  )) {
		rasm_process_command(not, bytes, bytesize, e1, e2, e3);
	} else if (!_strcmp_asc(buffer, "cmp"  )) {
		rasm_process_command(cmp, bytes, bytesize, e1, e2, e3);
	} else if (!_strcmp_asc(buffer, "inc"  )) {
		rasm_process_command(inc, bytes, bytesize, e1, e2, e3);
	} else if (!_strcmp_asc(buffer, "dec"  )) {
		rasm_process_command(dec, bytes, bytesize, e1, e2, e3);
	} else if (!_strcmp_asc(buffer, "mov"  )) {
		rasm_process_command(mov, bytes, bytesize, e1, e2, e3);

		//
		//	strcmp�� Ư���� �̿��Ͽ� �Լ��� �����Ͽ����Ƿ� �ǿ������� ���̰� ��
		//	�����ڰ� ĸ���ع��� �б�� �� �ֱ� ������ �� �ͺ��� ��ġ
		//
	} else if (!_strcmp_asc(buffer, "pusha")) {
		rasm_process_command(pusha, bytes, bytesize, e1, e2, e3);	// strcmp Ư��
	} else if (!_strcmp_asc(buffer, "popa" )) {
		rasm_process_command(popa, bytes, bytesize, e1, e2, e3);
	} else if (!_strcmp_asc(buffer, "push" )) {
		rasm_process_command(push, bytes, bytesize, e1, e2, e3);
	} else if (!_strcmp_asc(buffer, "pop"  )) {
		rasm_process_command(pop, bytes, bytesize, e1, e2, e3);
	} else if (!_strcmp_asc(buffer, "jmp"  )) {
		rasm_process_command(jmp, bytes, bytesize, e1, e2, e3);
	} else if (!_strcmp_asc(buffer, "ret"  )) {
		rasm_process_command(ret, bytes, bytesize, e1, e2, e3);
	} else if (!_strcmp_asc(buffer, "nop"  )) {
		rasm_process_command(nop, bytes, bytesize, e1, e2, e3);
	} else if (!_strcmp_asc(buffer, "rol"  )) {
		rasm_process_command(rol, bytes, bytesize, e1, e2, e3);
	} else if (!_strcmp_asc(buffer, "ror"  )) {
		rasm_process_command(ror, bytes, bytesize, e1, e2, e3);
	} else if (!_strcmp_asc(buffer, "rcl"  )) {
		rasm_process_command(rcl, bytes, bytesize, e1, e2, e3);
	} else if (!_strcmp_asc(buffer, "rcr"  )) {
		rasm_process_command(rcr, bytes, bytesize, e1, e2, e3);
	} else if (!_strcmp_asc(buffer, "shl"  )) {
		rasm_process_command(shl, bytes, bytesize, e1, e2, e3);
	} else if (!_strcmp_asc(buffer, "shr"  )) {
		rasm_process_command(shr, bytes, bytesize, e1, e2, e3);
	} else if (!_strcmp_asc(buffer, "sar"  )) {
		rasm_process_command(sar, bytes, bytesize, e1, e2, e3);
	} 
}

static int rasm_get_regc(PREGISTER e1, PREGISTER e2, PREGISTER e3)
{
	//
	//	������� ó���ϸ�    : ������ ����
	//	���迬������ ó���ϸ� : ������� ������ ����
	//	���������� ó���ϸ� : �׳��� ������
	//
	return !!e1 + !!e2 + !!e3;
}

/*
	@rasm_process_command : rasm line ����� ���� ó���Լ�

	@iasc      : ���ڵ� ����
	@bytes     : ����Ʈ�� ����� ������
	@bytesize  : ����Ʈ ����� ����Ű�� ������
	@e1        : ù ���� ���۷���
	@e2        : �� ��° ���۷���
	@e3        : �� ��° ���۷���
*/
static void rasm_process_command(enum _Internal_asmdc iasc, BYTE *bytes, size_t *bytesize, PREGISTER e1, PREGISTER e2, PREGISTER e3)
{
	int regc;
	BYTE eax_op, ax_op;

	//
	//	���۷����� ������ ������
	//
	regc = rasm_get_regc(e1, e2, e3);

	//
	//	����ȭ: ModRM byte �κ��� ������ ��� �ٸ� �Լ����� ó��
	//
	switch(iasc)
	{
	case add: /* ax_op = 0x04; */ eax_op = 0x05; goto G1;
	case  or: /* ax_op = 0x2c; */ eax_op = 0x2d; goto G1;
	case adc: /* ax_op = 0x14; */ eax_op = 0x15; goto G1;
	case sbb: /* ax_op = 0x1c; */ eax_op = 0x1d; goto G1;
	case and: /* ax_op = 0x24; */ eax_op = 0x25; goto G1;
	case sub: /* ax_op = 0x2c; */ eax_op = 0x2d; goto G1;
	case xor: /* ax_op = 0x34; */ eax_op = 0x35; goto G1;
	case cmp: /* ax_op = 0x3c; */ eax_op = 0x3d;
	G1:
		if (e1->type != REGISTER_TYPE_NORMAL) {
			rasm_error_n |= RASM_ERROR_NOT_COLLECT_REGISTER_NAME; 
			return;
		} else if (regc != 2) {
			rasm_error_n |= RASM_ERROR_INCOLLECT_OPERAND_LENGTH;
			return;
		}

		if (e1->bit == 16) {
			if(e1->first == AL && e2->type  == REGISTER_TYPE_NUMBERIC) {
				rasm_push_byte(eax_op-1, bytes, bytesize);
				rasm_push_byte(e2->first, bytes, bytesize);
			} else if (e2->type == REGISTER_TYPE_NORMAL) {
				rasm_push_byte(0x66, bytes, bytesize);	// size operand prefix
				rasm_push_byte(eax_op-2, bytes, bytesize);

				//
				//	XL, XH Error, ���� �߰� ����
				//
				rasm_push_byte(MakeModRM(ModRM_EA_Reg,e1->first-1,e2->first-1),bytes,bytesize);
			}
		} else if (e1->bit == 32) {
			if(e1->first == AX && e2->type  == REGISTER_TYPE_NUMBERIC) {
				if(e2->first < 128 && e2->first > -128) {
					rasm_push_byte(0x83, bytes, bytesize);
					rasm_push_byte(MakeModRM(ModRM_EA_Reg,iasc-add,e1->first-1),bytes,bytesize);
					rasm_push_byte((BYTE)(e2->first), bytes, bytesize);
				} else {
					rasm_push_byte(eax_op, bytes, bytesize);
					rasm_push_dword(e2->first, bytes, bytesize);
				}
				return;
			} else if (e2->type == REGISTER_TYPE_NORMAL) {
				rasm_push_byte(eax_op-2, bytes, bytesize);
				rasm_push_byte(MakeModRM(ModRM_EA_Reg,e1->first-1,e2->first-1),bytes,bytesize);
			} else if (e2->type == REGISTER_TYPE_NUMBERIC) {
				rasm_push_byte(0x81, bytes, bytesize);
				rasm_push_byte(MakeModRM(ModRM_EA_Reg,iasc-add,e1->first-1),bytes,bytesize);
				rasm_push_dword((DWORD)(e2->first), bytes, bytesize);
			} else if (e2->type == REGISTER_TYPE_SIGNLE_REFERENCE) {
				rasm_push_byte(eax_op-2, bytes, bytesize);
				rasm_push_byte(MakeModRM(ModRM_EA_Ref,e1->first-1,e2->first-1),bytes,bytesize);
			} else if (e2->type == REGISTER_TYPE_REFERENCE) {
				if (e2->sign == REGISTER_REFERENCE_SIGN_MINUS) {
					if(e2->second < 128) {
						rasm_push_byte(eax_op-2, bytes, bytesize);
						rasm_push_byte(MakeModRM(ModRM_EA_Ref8,e1->first-1,e2->first-1),bytes,bytesize);
						rasm_push_byte(-(BYTE)(e2->second),bytes,bytesize);
					} else {
						rasm_push_byte(eax_op-2, bytes, bytesize);
						rasm_push_byte(MakeModRM(ModRM_EA_Ref32,e1->first-1,e2->first-1),bytes,bytesize);

						//
						//	GCC���� -�� ó���ص� ������ �ɸ��� �ʽ��ϴ�
						//
						rasm_push_dword(~(DWORD)(e2->second)+1,bytes,bytesize);
					}

					//
					//	e1�� �� ��쿡�� �۵��ǵ��� �ݵ�� ���� ó���� �ؾ��մϴ�
					//
				} else if (e2->sign == REGISTER_REFERENCE_SIGN_PLUS) {
					if(e2->second < 128) {
						rasm_push_byte(eax_op-2, bytes, bytesize);
						rasm_push_byte(MakeModRM(ModRM_EA_Ref8,e1->first-1,e2->first-1),bytes,bytesize);
						rasm_push_byte((BYTE)(e2->second),bytes,bytesize);
					} else {
						rasm_push_byte(eax_op-2, bytes, bytesize);
						rasm_push_byte(MakeModRM(ModRM_EA_Ref32,e1->first-1,e2->first-1),bytes,bytesize);
						rasm_push_dword((DWORD)(e2->second),bytes,bytesize);
					}
				} else if (e2->sign == REGISTER_REFERENCE_SIGN_MULTIPLE) { // sib
					/*rasm_push_byte(MakeModRM(1,e1->first-1,4),bytes,bytesize);
					if(e2->second == 2) {
						rasm_push_byte(eax_op-2, bytes, bytesize);
						rasm_push_byte(MakeSIB(1,5,e2->first-1),bytes,bytesize);
					} else if (e2->second == 4) {
						rasm_push_byte(eax_op-2, bytes, bytesize);
						rasm_push_byte(MakeSIB(2,5,e2->first-1),bytes,bytesize);
					} else if (e2->second == 8) {
						rasm_push_byte(eax_op-2, bytes, bytesize);
						rasm_push_byte(MakeSIB(3,5,e2->first-1),bytes,bytesize);
					}*/
				} else if (e2->sign == REGISTER_REFERENCE_SIGN_MULTIPLE_MINUS) { // sib
				} else if (e2->sign == REGISTER_REFERENCE_SIGN_MULTIPLE_PLUS) { // sib
				}
			}
		} else if (e1->bit == 64) {
			// ?
		} else {
			rasm_error_n |= RASM_ERROR_NOT_FOUND_ERROR; 
			return;
		}
		break;
		
	case  inc: eax_op = 0x40; goto G2;
	case  dec: eax_op = 0x48; goto G2;
	case push: eax_op = 0x50; goto G2;
	case  pop: eax_op = 0x58; goto G2;
	G2:
		if (e1->type != REGISTER_TYPE_NORMAL) {
			rasm_error_n |= RASM_ERROR_NOT_COLLECT_REGISTER_NAME; 
			return;
		} else if (regc != 1) {
			rasm_error_n |= RASM_ERROR_INCOLLECT_OPERAND_LENGTH;
			return;
		}

		rasm_push_byte(eax_op+e1->first-1,bytes,bytesize);
		break;

	case pusha: case pushad:
		if (regc != 0) {
			rasm_error_n |= RASM_ERROR_INCOLLECT_OPERAND_LENGTH;
			return;
		}

		rasm_push_byte(0x60,bytes,bytesize);
		break;

	case popa: case popad:
		if (regc != 0) {
			rasm_error_n |= RASM_ERROR_INCOLLECT_OPERAND_LENGTH;
			return;
		}

		rasm_push_byte(0x61,bytes,bytesize);
		break;

	case rol:
	case ror:
	case rcl:
	case rcr:
	case shl:
	case shr:
	case _0: 
	case sar:
		if (e1->type != REGISTER_TYPE_NORMAL) {
			rasm_error_n |= RASM_ERROR_NOT_COLLECT_REGISTER_NAME; 
			return;
		} else if (regc != 2) {
			rasm_error_n |= RASM_ERROR_INCOLLECT_OPERAND_LENGTH;
			return;
		}
		
		if (e1->bit == 16) {
			if(e1->first < AL) {
				rasm_push_byte(0x66,bytes,bytesize);
				if(e2->first == 1) {
					rasm_push_byte(0xd1,bytes,bytesize);
					rasm_push_byte(MakeModRM(ModRM_EA_Reg,iasc-rol,e1->first-1),bytes,bytesize);
				} else if (e2->first < 0x100) {
					rasm_push_byte(0xc1,bytes,bytesize);
					rasm_push_byte(MakeModRM(ModRM_EA_Reg,iasc-rol,e1->first-1),bytes,bytesize);
					rasm_push_byte(e2->first,bytes,bytesize);
				} else {
					rasm_error_n |= RASM_ERROR_INCOLLECT_OPERAND_LENGTH;
					return;
				}
			} else {
				if(e2->first == 1) {
					rasm_push_byte(0xd0,bytes,bytesize);
					rasm_push_byte(MakeModRM(ModRM_EA_Reg,iasc-rol,e1->first-AL),bytes,bytesize);
				} else if (e2->first < 0x100) {
					rasm_push_byte(0xc0,bytes,bytesize);
					rasm_push_byte(MakeModRM(ModRM_EA_Reg,iasc-rol,e1->first-AL),bytes,bytesize);
					rasm_push_byte(e2->first,bytes,bytesize);
				} else {
					rasm_error_n |= RASM_ERROR_INCOLLECT_OPERAND_LENGTH;
					return;
				}
			}
		} else if (e1->bit == 32) {
			if(e2->first == 1) {
				rasm_push_byte(0xd1,bytes,bytesize);
				rasm_push_byte(MakeModRM(ModRM_EA_Reg,iasc-rol,e1->first-1),bytes,bytesize);
			} else if(e2->first < 0x100) {
				rasm_push_byte(0xc1,bytes,bytesize);
				rasm_push_byte(MakeModRM(ModRM_EA_Reg,iasc-rol,e1->first-1),bytes,bytesize);
				rasm_push_byte(e2->first,bytes,bytesize);
			} else {
				rasm_error_n |= RASM_ERROR_INCOLLECT_OPERAND_LENGTH;
				return;
			}
		} else if (e1->bit == 64) {
			// ?
		} else {
			rasm_error_n |= RASM_ERROR_NOT_FOUND_ERROR; 
			return;
		}

		break;

	case mov:
		break;

	case test:
	case _1:
	case not:
	case neg:
	case mul:
	case imul:
	case _div:
	case idiv:
		break;
	}
}

/*
	@rasm_assemble_code : rasm line ����� �Լ�

	@buffer    : ó���� ���ڿ�
	@option    : rasm �ɼ�
	@opcode    : /R�ɼ� ����� ó���Ǵ� �κ� (report option)
	@bytesize  : ����Ʈ ����� ����Ű�� ������
	@error_n   : ���� ������ ��µ� ������
	@��ȯ��     : ���� ����Ʈ ������
*/
BYTE *rasm_assemble_code(char *buffer, POption option, u32 *opcode, size_t *bytesize, u32 *error_n)
{
	BYTE ret[32];
	BYTE *ptr = ret;

	*error_n = 0;
	*bytesize = 0;

	_util_skip_function(&buffer, _isspace);

BACK:
	switch(*buffer++) {
	case ';': return 0;		// annotation
	case '@':				// command
		rasm_get_byte_from_command(buffer, &ret, bytesize);
		break;
	case '.':				// file option
	case ':':				// jmp target(?) default ó���ؾ���
		;
	}

	*error_n |= rasm_error_n;
	rams_p$ = rasm_$ += *bytesize;
	return ptr;
}


