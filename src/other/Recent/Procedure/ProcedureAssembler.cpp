/***

   RollRat Software Project.
   Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
   ProcedureAssembler.cpp

Purpose:

   Evaluates a string as though it were an expression,
   and returns a result fastly.
   For Intel x86 Processor.

Author:

   08-29-2015:   HyunJun Jeong, Creation

***/

#include <vector>
#include <type_traits>
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

#define EXX				32

#define EIP				256
#define EFLAGS			257
#define CS				258
#define DS				259
#define ES				260
#define FS				261
#define GS				262

typedef enum class eg1{
	add,
	or,
	adc,
	sbb,
	and,
	sub,
	xor,
	cmp,
}	ExtensionGroup1;

typedef enum class eg2{
	rol,
	ror,
	rcl,
	rcr,
	shl,
	shr,
	_0,
	ar,
}	ExtensionGroup2;

typedef enum class eg3{
	test,
	_0,
	not,
	neg,
	mul,
	imul,
	div,
	idiv,
}	ExtensionGroup3;

typedef enum class eg4{
	inc,
	dec,
}	ExtensionGroup4;

typedef enum class eg5{
	inc,
	dec,
	near_call,
	far_call,
	near_jmp,
	far_jmp,
	push,
}	ExtensionGroup5;

typedef enum class _prefix_ {
	_PF_ONLY,		// 일반 pusha, 같은거
	_PF_SHIFT,
	_PF_RET,
	_PF_JCC,
	_PF_CALL,
	_PF_STACK,		// push, pop
	_PF_ONE,		// inc dec
	_PF_ATH,		// add adc sbb sub
	_PF_FLT,		// mul div
	_PF_LOC,		// xor and or
	_PF_MOV,
	_PF_CMP,		// cmp test
	_PF_MR,			// mem-reg, reg	: [ebp-n]		->  <register> <register>
	_PF_RM,			// reg, mem-reg				    ->  <register> <operand>
	_PF_OM,			// mem-reg		ex) call eax+n
	_PF_LOOP,
	_PF_BT,
	_PF_ALIGN,
	_PF_DB,			// DB
	_PF_ERR,
}	PREFIX;

#define ModRM(mod, reg, rm)		((rm & 7) | ((reg & 7) << 3) | ((mod & 3) << 6))

typedef struct {
	char name[10];
	PREFIX prefix;

	/*
		0: Opcode
		1: Register Target
		2: Short/Long
		3: mem-reg, reg/reg, mem-reg/mem-reg
		4~5: mod rm info
	*/
	BYTE option[6];
}	INSTRUCTIONS;

static const INSTRUCTIONS inst_info[] = {
	{"ERR",	PREFIX::_PF_ERR},

	// Priority: Short > EAX > Long
	{"ADD", PREFIX::_PF_ATH, 0x83, 0, 0, (BYTE)PREFIX::_PF_RM, ModRM(3,(int)ExtensionGroup1::add,0)},
	{"ADD", PREFIX::_PF_ATH, 0x05, AX|EXX, 0, (BYTE)PREFIX::_PF_RM},
	{"ADD", PREFIX::_PF_ATH, 0x81, 0, 1, (BYTE)PREFIX::_PF_RM, ModRM(3,(int)ExtensionGroup1::add,0)},
	{"ADD", PREFIX::_PF_ATH, 0x03, 0, 0, (BYTE)PREFIX::_PF_MR},

	{"AND", PREFIX::_PF_LOC, 0x83, 0, 0, (BYTE)PREFIX::_PF_RM, ModRM(3,(int)ExtensionGroup1::and,0)},
	{"AND", PREFIX::_PF_LOC, 0x25, AX|EXX, 0, (BYTE)PREFIX::_PF_RM},
	{"AND", PREFIX::_PF_LOC, 0x81, 0, 1, (BYTE)PREFIX::_PF_RM, ModRM(3,(int)ExtensionGroup1::and,0)},
	{"AND", PREFIX::_PF_LOC, 0x23, 0, 0, (BYTE)PREFIX::_PF_MR},
	
	{ "OR", PREFIX::_PF_LOC, 0x83, 0, 0, (BYTE)PREFIX::_PF_RM, ModRM(3,(int)ExtensionGroup1::or,0)},
	{ "OR", PREFIX::_PF_LOC, 0x0d, AX|EXX, 0, (BYTE)PREFIX::_PF_RM},
	{ "OR", PREFIX::_PF_LOC, 0x81, 0, 1, (BYTE)PREFIX::_PF_RM, ModRM(3,(int)ExtensionGroup1::or,0)},
	{ "OR", PREFIX::_PF_LOC, 0x0b, 0, 0, (BYTE)PREFIX::_PF_MR},
	
	{"SUB", PREFIX::_PF_ATH, 0x83, 0, 0, 0, ModRM(3,(int)ExtensionGroup1::sub,0)},
	{"SUB", PREFIX::_PF_ATH, 0x2d, AX|EXX, 0, (BYTE)PREFIX::_PF_RM},
	{"SUB", PREFIX::_PF_ATH, 0x81, 0, 1, 0, ModRM(3,(int)ExtensionGroup1::sub,0)},
	{"SUB", PREFIX::_PF_ATH, 0x2b, 0, 0, (BYTE)PREFIX::_PF_MR},
	
	{"XOR", PREFIX::_PF_LOC, 0x83, 0, 0, (BYTE)PREFIX::_PF_RM, ModRM(3,(int)ExtensionGroup1::xor,0)},
	{"XOR", PREFIX::_PF_LOC, 0x35, AX|EXX, 0, (BYTE)PREFIX::_PF_RM},
	{"XOR", PREFIX::_PF_LOC, 0x81, 0, 1, (BYTE)PREFIX::_PF_RM, ModRM(3,(int)ExtensionGroup1::xor,0)},
	{"XOR", PREFIX::_PF_LOC, 0x33, 0, 0, (BYTE)PREFIX::_PF_MR},
	
	{"CMP", PREFIX::_PF_CMP, 0x83, 0, 0, (BYTE)PREFIX::_PF_RM, ModRM(3,(int)ExtensionGroup1::cmp,0)},
	{"CMP", PREFIX::_PF_CMP, 0x3d, AX|EXX, 0, (BYTE)PREFIX::_PF_RM},
	{"CMP", PREFIX::_PF_CMP, 0x81, 0, 1, (BYTE)PREFIX::_PF_RM, ModRM(3,(int)ExtensionGroup1::cmp,0)},
	{"CMP", PREFIX::_PF_CMP, 0x3b, 0, 0, (BYTE)PREFIX::_PF_MR},
	
	{"INC", PREFIX::_PF_ONE, 0x40, 0, 0, (BYTE)PREFIX::_PF_OM},
	{"DEC", PREFIX::_PF_ONE, 0x48, 0, 0, (BYTE)PREFIX::_PF_OM},
	{"PUSH", PREFIX::_PF_STACK, 0x50, 0, 0, (BYTE)PREFIX::_PF_OM},
	{"POP", PREFIX::_PF_STACK, 0x58, 0, 0, (BYTE)PREFIX::_PF_OM},

	{"MOV", PREFIX::_PF_MOV, 0xb8, 0, 0, (BYTE)PREFIX::_PF_RM},
	
	{"ADC", PREFIX::_PF_ATH, 0x15},
	{"SBB", PREFIX::_PF_ATH, 0x1d},

	{"PUSHA", PREFIX::_PF_ONLY, 0x60},
	{"PUSHD", PREFIX::_PF_ONLY, 0x60},
	{"POPA", PREFIX::_PF_ONLY, 0x61},
	{"POPD", PREFIX::_PF_ONLY, 0x61},

	{"RET", PREFIX::_PF_ONLY, 0xc3},
	{"NOP", PREFIX::_PF_ONLY, 0x90},

	{ "JO", PREFIX::_PF_JCC, 0x70, 0, 1},
	{ "JO", PREFIX::_PF_JCC, 0x0f, 0x80, 0},
	{"JNO", PREFIX::_PF_JCC, 0x71, 0, 1},
	{"JNO", PREFIX::_PF_JCC, 0x0f, 0x81, 0},
	{ "JB", PREFIX::_PF_JCC, 0x72, 0, 1},
	{ "JB", PREFIX::_PF_JCC, 0x0f, 0x82, 0},
	{"JNB", PREFIX::_PF_JCC, 0x73, 0, 1},
	{"JNB", PREFIX::_PF_JCC, 0x0f, 0x83, 0},
	{ "JZ", PREFIX::_PF_JCC, 0x74, 0, 1},
	{ "JZ", PREFIX::_PF_JCC, 0x0f, 0x84, 0},
	{"JNZ", PREFIX::_PF_JCC, 0x75, 0, 1},
	{"JNZ", PREFIX::_PF_JCC, 0x0f, 0x85, 0},
	{"JBE", PREFIX::_PF_JCC, 0x76, 0, 1},
	{"JBE", PREFIX::_PF_JCC, 0x0f, 0x86, 0},
	{ "JA", PREFIX::_PF_JCC, 0x77, 0, 1},
	{ "JA", PREFIX::_PF_JCC, 0x0f, 0x87, 0},
	{ "JS", PREFIX::_PF_JCC, 0x78, 0, 1},
	{ "JS", PREFIX::_PF_JCC, 0x0f, 0x88, 0},
	{"JNS", PREFIX::_PF_JCC, 0x79, 0, 1},
	{"JNS", PREFIX::_PF_JCC, 0x0f, 0x89, 0},
	{ "JP", PREFIX::_PF_JCC, 0x7a, 0, 1},
	{ "JP", PREFIX::_PF_JCC, 0x0f, 0x8a, 0},
	{"JNP", PREFIX::_PF_JCC, 0x7b, 0, 1},
	{"JNP", PREFIX::_PF_JCC, 0x0f, 0x8b, 0},
	{ "JL", PREFIX::_PF_JCC, 0x7c, 0, 1},
	{ "JL", PREFIX::_PF_JCC, 0x0f, 0x8c, 0},
	{"JNL", PREFIX::_PF_JCC, 0x7d, 0, 1},
	{"JNL", PREFIX::_PF_JCC, 0x0f, 0x8d, 0},
	{"JLE", PREFIX::_PF_JCC, 0x7e, 0, 1},
	{"JLE", PREFIX::_PF_JCC, 0x0f, 0x8e, 0},
	{"JNLE", PREFIX::_PF_JCC, 0x7f, 0, 1},
	{"JNLE", PREFIX::_PF_JCC, 0x0f, 0x8f, 0},
	{"JMP", PREFIX::_PF_JCC, 0xeb, 0, 1},
	{"JMP", PREFIX::_PF_JCC, 0xe9, 0, 0},
	{"JMP", PREFIX::_PF_JCC, 0xff, 0, 0, (BYTE)PREFIX::_PF_OM, ModRM(3,(int)ExtensionGroup5::near_jmp,0)},
};

typedef enum _tmp_010_
{
	_Not_Found_Error = 0,
	_Not_Find_Comma,
	_Not_Found_Register,
}	SYNTAX_ERROR;

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

typedef struct
{
	int first;
	int second;
	int third;
	int bit;			// 16/32
	SYNTAX_ERROR error;
	REG_SIGN sign;
	REG_TYPE type;
	bool isprocess;
}	ASM_REG, *PASM_REG;

#define ASM_REG_BIT_16			16
#define ASM_REG_BIT_32			32

#define STRUCTURE_SIZE_OF(ptr)		sizeof(ptr)/sizeof(*ptr)

typedef struct _asm_data_
{
	PREFIX prefix;
	SYNTAX_ERROR error;
	INSTRUCTIONS opcode;
	ASM_REG registers[3];
	BYTE szreg;
	bool processed;
	size_t lineno;
	BYTE bytes[20];
	size_t szbyte;
	bool setlabel;
	char labelname[32];
	int labelindex;
	char procname[32];
	struct _asm_data_ *next;
}	ASM_DATA, *PASM_DATA;

void SkipWS(const char const* *ptr) {
	const char *p = *ptr;
	while (*p)
		if (!isspace(*p)) break;
		else p++;
	*ptr = p; }
void FindWS(const char const* *ptr) {
	const char *p = *ptr;
	while (*p)
		if (isspace(*p)) break;
		else p++;
	*ptr = p; }
template<class _Func>
void SkipFunc(const char const* *ptr, _Func& func) {
	const char *p = *ptr;
	while (*p)
		if (!func(*p)) break;
		else p++;
	*ptr = p; }
template<class _Func> 
void FindFunc(const char const* *ptr, _Func& func) {
	const char *p = *ptr;
	while (*p)
		if (func(*p)) break;
		else p++;
	*ptr = p; }
int get_oct(const char *ptr) {
	int num = 0, sign = 1;
	if (*ptr == '-')
		*ptr++, sign = -1;
	for (; *ptr != 'o'; ptr++)
		num *= 8, num += *ptr & 0xf;
	return num * sign; }
int get_dec(const char *ptr) {
	int num = 0, sign = 1;
	if (*ptr == '-')
		*ptr++, sign = -1;
	for (; isdigit(*ptr); ptr++)
		num *= 10, num += *ptr & 0xf;
	return num * sign; }
int get_hex(const char *ptr) {
	int num = 0, sign = 1;
	if (*ptr == '-')
		*ptr++, sign = -1;
	for (; *ptr != 'h'; ptr++) {
		num *= 16;
		num += isdigit(*ptr) ? *ptr & 0xf
			:  tolower(*ptr) - 'a' + 0xA;}
	return num * sign; }
void LastPoint(const char const* *ptr) {
	for (; **ptr; *((*ptr)++))
		; }
template<typename _Enum>
auto to_integer(_Enum e) ->typename std::underlying_type<_Enum>::type {
	return static_cast<typename std::underlying_type<_Enum>::type>(e); }

static int label_index = 0;
static int _$ = 0;

void GetRegister(const char const* *m_str, PASM_REG m_reg)
{
	const char *m_ptr = *m_str;
	ASM_REG reg = *m_reg;
	int thirdc;
	const char *m_ch;
	
	// 중요 : 이 함수는 다음과 같은 구문은 처리하지 못합니다.
	//	[<num2> + <reg> * <num1>]
	//	[<num1> * <reg> + <num2>]
	//	[<num2>	+ <num1> * <reg>]
	//	[<num1> * <reg>]
	//	[<num1> + <reg>]

	if (reg.isprocess)
		return;
	reg.isprocess = true;
	reg.error = SYNTAX_ERROR::_Not_Found_Error;
	
	//	[<reg> * <num1> + <num2>] 형식일 경우 이 플래그는 활성화됨
	thirdc = FALSE;

	//	상수식 분석
	if ( isdigit(*m_ptr)  ||
	  // isxdigit(*m_ptr) ||
		 *m_ptr == '-'    ||
		 *m_ptr == '+'       )
	{
		const char *foresee = m_ptr + 1;
		int get;
		int radix = 0;

		reg.type = REG_TYPE::_Reg_Numberic;
		
		//	맨 끝의 문자를 확인하기 위해 포인터를 옮김
	 // SkipFunc(&foresee, isspace);
		SkipFunc(&foresee, isxdigit);
	 // SkipFunc(&foresee, isspace);

		if (*foresee == 'o')
			get = get_oct(m_ptr);
		else if (*foresee == 'x')
			get = get_hex(m_ptr);
		else
			get = get_dec(m_ptr);

		reg.first = get;

		m_ptr = foresee + 1;
		goto PROC_END;
	}
	
	//
	//	rxx, exx와 참조형 오퍼랜드를 분석함
	//	디폴트 값은 16bit형 오퍼랜드임
	//
RE:	switch(tolower(*m_ptr))
	{
	case '[':
		reg.type = REG_TYPE::_Reg_Reference;
		SkipWS(&m_ptr);
		m_ptr++;
		goto RE;
	{ case 'e': reg.bit = 32; goto SET; }
 // { case 'r': bit = 64; goto SET; }
	{ default:  reg.bit = 16; break; }
SET:
		if (reg.type != REG_TYPE::_Reg_Reference)
			reg.type = REG_TYPE::_Reg_Normal;
		m_ptr++;
	}
	
	//
	//	exx에서 e을 넘긴 레지스터를 분석함
	//	형식은 모두 16bit로 통일
	//
	switch(tolower(*((m_ch = m_ptr + 1) - 1)))
	{
	case 'a': 
		if      (*m_ch == 'x') reg.first = AX;
		else if (*m_ch == 'l') reg.first = AL;
		else if (*m_ch == 'h') reg.first = AH;
		break;
	case 'b':
		if      (*m_ch == 'p') reg.first = BP;
		else if (*m_ch == 'x') reg.first = BX;
		else if (*m_ch == 'l') reg.first = BL;
		else if (*m_ch == 'h') reg.first = BH;
		break;
	case 'c':
		if      (*m_ch == 'x') reg.first = CX;
		else if (*m_ch == 'l') reg.first = CL;
		else if (*m_ch == 'h') reg.first = CH;
		break;
	case 'd':
		if      (*m_ch == 'i') reg.first = DI;
		else if (*m_ch == 'x') reg.first = DX;
		else if (*m_ch == 'l') reg.first = DL;
		else if (*m_ch == 'h') reg.first = DH;
		break;
	case 's':
		if      (*m_ch == 'p') reg.first = SP;
		else if (*m_ch == 'i') reg.first = SI;
		break;
	}
	
	//
	//	분석했던 레지스터의 총 길이가 2이므로
	//
	m_ptr += 2;
	SkipWS(&m_ptr);

	//
	//	일반 레지스터 형식이면 더 이상 분석할 필요없으니
	//	그냥 끝냄
	//
	if (reg.type == REG_TYPE::_Reg_Normal)
		goto PROC_END;

	//
	//	일반 참조형 레지스터 형식
	//
	if (*m_ptr == ']') {
		reg.type = REG_TYPE::_Reg_SingleReference;
		goto PROC_END;
	}
	
	//
	//	']'를 만나지 않으면 뭔가 더 있는 것임으로
	//
	if (*m_ptr == '+')
		reg.sign = REG_SIGN::_Sign_Plus;
	else if (*m_ptr == '-')
		reg.sign = REG_SIGN::_Sign_Minus;
	else if (*m_ptr == '*')
		reg.sign = REG_SIGN::_Sign_Multiple;
	SkipWS(&m_ptr);

	m_ptr++;

	//
	//	16진수의 문자열일 경우 ffh나, a2h같은 문자가 먼저 나와있을 수 있는데
	//	이 경우엔 분석을 막아 변수로 취급한다. 그로 인해 16진수의 경우엔 
	//	0ffh, 0a2h와 같이 나타내어야 한다.
	//
	if(isdigit(*m_ptr))
	{
		const char * t = m_ptr;
		int get;
		for (; *t != ']' && *t; t++)
			if (*t == '-' || *t == '+') {

				//
				//	[<reg> * <num1> + <num2>] 형식임이 확증됨
				//
				thirdc = TRUE;
				break;
			}

		//
		//	*t == NULL이면 열린 괄호가 닫히지 않았으므로 당연한 오류
		//
		if (!*t--) {
			reg.error = SYNTAX_ERROR::_Not_Find_Comma;
			goto PROC_END;
		}

		//
		//	']'가 나오기 전에 공백이 포함되어있을 수 있으므로
		//
		for (; isspace(*t); t--)
			;

		if (*t == 'o')
			get = get_oct(m_ptr);
		else if (*t == 'h')
			get = get_hex(m_ptr);
		else
			get = get_dec(m_ptr);

		reg.second = get;
		reg.type = REG_TYPE::_Reg_Reference;
		m_ptr = t + 1;

		if (thirdc == TRUE) {
			//
			//	이 코드구역은 상기구역과 동일함
			//
			const char * ptr = t+1;
			int get;
			SkipWS(&m_ptr);

			if (*ptr == '+')
				reg.sign = REG_SIGN::_Sign_Multiple_Plus;
			else if (*ptr == '-')
				reg.sign = REG_SIGN::_Sign_Multiple_Minus;
			SkipWS(&m_ptr);

			for (; *t != ']' && *t; t++)
				;
			
			if (!*t--) {
				reg.error = SYNTAX_ERROR::_Not_Find_Comma;
				goto PROC_END;
			}

			for (; isspace(*t); t--)
				;
			
			if (*t == 'o')
				get = get_oct(m_ptr);
			else if (*t == 'h')
				get = get_hex(m_ptr);
			else
				get = get_dec(m_ptr);

			reg.third = get;
			m_ptr = ptr + 1;
		}
	}

PROC_END:
	*m_reg = reg;
	*m_str = m_ptr;
}

ASM_DATA *CreateAsmData()
{
	ASM_DATA *ret = new ASM_DATA;
	ret->processed = false;
	ret->lineno = -1;
	ret->szbyte = 0;
	ret->next = nullptr;
	ret->registers[0].isprocess = false;
	ret->registers[1].isprocess = false;
	ret->registers[2].isprocess = false;
	ret->setlabel = false;
	return ret;
}

INSTRUCTIONS GetOpcode(const char const** m_str)
{
	char opcode[10];
	const char *m_ptr = *m_str, *m_iter = *m_str;

	FindWS(&m_ptr);

	for (; m_iter < m_ptr; m_iter++)
		opcode[int(m_iter) - int(*m_str)] = 
			toupper((*m_str)[int(m_iter) - int(*m_str)]);
	opcode[int(m_iter) - int(*m_str)] = 0;

	*m_str = m_ptr + 1;	// skip ws

	for (int i = 0; i < STRUCTURE_SIZE_OF(inst_info); i++)
	{
		if (!strcmp(inst_info[i].name, opcode))
			return inst_info[i];
	}

	return inst_info[0];
}

ASM_DATA *GetAsmInternal(const char *m_line, int lineno)
{
	ASM_DATA *ret = CreateAsmData();
	const char *ptr;
	int regsize = 0;

	ret->lineno = lineno;

	SkipWS(&m_line);
	LastPoint(&(ptr = m_line));
	ptr -= 1;

	//
	//	Jcc용 라벨
	//
	if (*ptr == ':')
	{
		ret->setlabel = true;
		ret->labelindex = label_index++;
		int i = 0;
		for (; m_line[i]; i++)
			ret->labelname[i] = m_line[i];
		ret->labelname[i] = 0;
	}
	else
	{
		ret->opcode = GetOpcode(&m_line);
	}

	return ret;
}

ASM_DATA *AssembleCode(std::vector<char *> m_lines)
{
	ASM_DATA *ret = CreateAsmData();
	PASM_DATA last = ret;

	for (int i = 0; i < m_lines.size(); i++)
	{
		last->next = GetAsmInternal(m_lines[i], i+1);
		last = last->next;
	}

	_$ = 0;

	return ret;
}

int main()
{
	const char *p = "add [ebp-02h], 20";
	ASM_DATA *asms = CreateAsmData();

	GetOpcode(&p);
	GetRegister(&p, &(asms->registers[0]));
}