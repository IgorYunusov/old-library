
#include <stdio.h>
#include "RegexParser.h"
#include "psoab.h"

int main()
{
	_4faoc<> faoc;
	faoc.charset("5*14/3+6*2+4*(9+5*(4+3)-6)-10");
	// 23 + 12 + 38*4 -10 = 25 + 152 = 177
	printf_s("%d", faoc.exp());
	return 0;
}