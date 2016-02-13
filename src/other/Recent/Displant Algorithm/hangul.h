/*************************************************************************

   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:

   hangul.h

Project:

   Displant Algorithm

------
   AUTHOR: HyunJun Jeong  2015-05-16

***************************************************************************/

#ifndef _HANGUL_DISPLANT_
#define _HANGUL_DISPLANT_

typedef struct _hangul_initial_ {
	int initial;
	int medial;
	int final;
}	HANGUL_INITIAL;

typedef int bool;

wchar_t hangul_combination(HANGUL_INITIAL hInitial);
wchar_t hangul_combination_native(int initial, int medial, int final);
HANGUL_INITIAL hangul_distortion(wchar_t ch);
bool hangul_is(wchar_t ch);
bool hangul_is_letter(wchar_t ch);
bool hangul_is_jamo31(wchar_t ch);
bool hangul_is_jamo11(wchar_t ch);
const wchar_t *hangul_disassembly(wchar_t ch);
const wchar_t *hangul_disassembly3(wchar_t ch);
void hangul_total_disassembly(const wchar_t *what, wchar_t *buffer);
void hangul_total_disassembly3(const wchar_t *what, wchar_t *buffer);
void hangul_total_disassembly3(wchar_t *what);
void hangul_assembly(const wchar_t string[], wchar_t *buffer);
void hangul_assembly3(const wchar_t string[], wchar_t *buffer);
void hangul_initial(const wchar_t string[], wchar_t *buffer);
int hangul_startswith_compare(const wchar_t string1[], const wchar_t string2[]);

wchar_t hangul_add_to_final(const wchar_t ch, const wchar_t target);
bool hangul_is_final(const wchar_t ch);
wchar_t hangul_expression_nasalization(const wchar_t ch1, const wchar_t ch2);
bool hangul_expression_liquidization(wchar_t *ch1, wchar_t *ch2);
bool hangul_expression_palatalization(wchar_t *ch1, wchar_t *ch2);
bool hangul_expression_syllable_of_jongseong_rules(wchar_t **str);

#endif