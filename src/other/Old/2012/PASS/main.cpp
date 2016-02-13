#include "bitctr.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#include "rpass.h"
#include "arpcls.hpp"

int main()
{
	printf("%08X\n", _E(0xaaff1122, 7));
	printf("%08X\n", _E_B(0xaaff1122, 3));
	printf("%08X\n", _EX_B(0xabcdef12, 0, 1));
	printf("%08X\n", _GET_CARRY(645, 4798));
	printf("%s", ProcessAll("32sdfgabdsfg", 0, "\\S\\x08:[00]\\x05:[00]>[0A]\\E"));

	char *as = "abc";

	unsigned char map[32];

	for (int count = 0; count < 32; count++)
		map[count] = 0;

	do {
		map[*as >> 3] |= (1 << (*as & 7));
	} while (*as++);

	return 0;
}