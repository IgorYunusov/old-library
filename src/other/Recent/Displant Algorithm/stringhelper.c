/*************************************************************************

   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:

   hangul.c

Project:

   Displant Algorithm

------
   AUTHOR: HyunJun Jeong  2015-05-23

***************************************************************************/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>

typedef int			bool;
#define FALSE	0
#define TRUE	1

#ifdef _MSC_VER
#ifdef _DEBUG
#define _Debugging
#endif
#endif

bool strEquals(const char *_left, const char *_right, int _length)
{
#ifdef _Debugging
	char *lp, *rp;
	
	if (!_left || !_right || !_length)
		return FALSE;

	lp = (char *)_left;
	rp = (char *)_right;

	while(_length >= 10) {
		if (*(int *) lp != *(int *) rp)
			return FALSE;
		if (*(int *)(lp + 2) != *(int *)(rp + 2))
			return FALSE;
		if (*(int *)(lp + 4) != *(int *)(rp + 4))
			return FALSE;
		if (*(int *)(lp + 6) != *(int *)(rp + 6))
			return FALSE;
		if (*(int *)(lp + 8) != *(int *)(rp + 8))
			return FALSE;
		lp += 10;
		rp += 10;
		_length -= 10;
	}

	while ( _length > 0) {
		if (*(int *) lp != *(int *) rp)
			return FALSE;
		lp += 2;
		rp += 2;
		_length -= 2;
	}

	return _length <= 0;
#else
	return !strcmp(_left, _right);
#endif
}

int strLength(const char *_str)
{
	const char *_proc = _str;

	/*

	*/
	for(; (int)_proc & (sizeof(int) - 1); _proc++) {
		if (*_proc == '\0')
			return _proc - _str;
	}
}



int sstrlen(char const* s)
{
    /* Search index.
    * The input pointer is still needed for length calculation.
    */
    char const* p = s;

    /* Bit patterns (32 bit system), temporary.
    * The three used 32 bit patterns are 0x7efefeff (7efefeff,
    * 7efefeffh, m), 0x81010101 (81010101, 81010101h, -m) and 0x81010100
    * (81010100, 81010100h, ~m).
    * On 64 bit systems, the pattern would be 0x7efefefefefefeff (its
    * complement 0x8101010101010101).
    */
    int m = 0x7efefeff, n = ~m, i;

    /* Advance the search index until it is aligned to the data size
    * used in the following search loop; do a conventional search on
    * that unaligned part at the same time, since the string may be
    * short (shorter than sizeof(int)-1).
    * This loop is not entered in the more optimal case of an input
    * string being aligned (compilers may chose to e.g. align string
    * literals, dynamically allocated buffers are aligned, etc).
    * Alignment of the subsequent multi-byte data accesses is an
    * optimization, since misaligned data accesses include a performance
    * penalty and possibly use more than one cache line, or are even
    * disallowed and generate a bus error, e.g. in RISC architectures.
    * This step will take less than sizeof(int) loop iterations.
    * The &(sizeof(int)-1) operation is an optimized %sizeof(int)
    * (assuming sizeof(int) is a power-of-two), since bit operations are
    * more performant than arithmetic operations (in this case, with an
    * operand that is known at compile time, the compiler/optimizer
    * might generate the same code for the %-operation).
    * The !=0 part is left away here (and also at other places) in the
    * conditional expression , which might be a reflection of the fact
    * that the compiler may directly use the zero-conditional produced
    * by the &-operation.
    */
    for (; (int)p & (sizeof(int) - 1); p++) {

        /* Check for end-of-string too (relevant with small, unaligned
        * strings, see earlier comment too).
        */
        if (!*p) {
            return p - s;
        }
    }

    /* Aligned multi-byte data search loop, in pieces of sizeof(int)
    * (by C language definition, int is the most natural data size for
    * CPUs to operate on; maybe not with 64 bit systems in LP64 mode
    * [only longs and pointers native; int remains 32 bit, for software
    * compatibility and/or resource saving], in which long may be the
    * natural data size).
    * One multi-byte data-access is done per iteration instead of
    * sizeof(int) single-byte data-accesses (a single multi-byte
    * data-access may even be faster than one single-byte data-access).
    * Each iteration uses one subtraction/addition/comparison instead
    * of sizeof(int).
    */
    for (;;) {

        /* Next sizeof(int) aligned string bytes.
        * We may read up to sizeof(int)-1 bytes beyond the string
        * (excluding its terminating nul byte), which is not a problem
        * with memory (page) maps, since the (mapped) pages are aligned
        * to a multiple of sizeof(int) and so an aligned int can't cross
        * two pages.
        * However, memory boundary check tools may trigger warnings
        * (such as uninitialized memory read, etc).
        */
        i = *(int const*)p;

        /* Check if this chunk is a candidate for having embedded nul
        * bytes.
        * This algorithm assumes two's complement integer
        * representation.
        * i+0x7efefeff is the same as i-0x81010101.
        * Subtracting 1 from each (possible nul) byte will flip its
        * least significant bit, and possibly some more, depending on
        * the input (all bits up to the least significant set bit).
        * If the byte was zero (all bits cleared, a nul byte), all bits
        * are flipped and a carry bit is generated into the next
        * significant byte, which flips the next byte's least
        * significant bit a second time.
        * Since we cannot (and don't want) to check the
        * int-carry-out-bit (the most significant byte's carry) in C,
        * the most significant byte's most significant bit is used to do
        * that check, which leads to false candidates if only that bit
        * was set in the most significant byte (i.e. the most
        * significant byte was a \x80 byte).
        * These false candidates weaken the search algorithm's
        * performance a bit.
        * Comparing the subtraction-flip result with the logic-flip
        * result (^~i), while only considering the sizeof(int) bits of
        * interest (&0x81010100), will reveal if carries have occurred
        * (double-bit-flip vs. single-bit-flip).
        */
        if (!(((i + m) ^ ~i) & n)) {

            /* This chunk is not a candidate, which means it does not
            * include nul bytes.
            * Advance sizeof(int) bytes.
            */
            p += sizeof(int);

        } else {

            /* This chunk is a candidate, which means it may include nul
            * bytes or, at the most significant byte, a \x80.
            * Searches on strings containing lots of such bytes will be
            * less-than-optimized.
            * Conventionally search for a nul (and its position) in
            * sizeof(int) bytes and continue chunked search if none is
            * found (with a false candidate, see comments above), in
            * which case the search index is advanced too by sizeof(int)
            * bytes.
            */
            for (i = sizeof(int); i; p++, i--) {
                if (!*p) {
                    return p - s;
                }
            }
        }
    }
}