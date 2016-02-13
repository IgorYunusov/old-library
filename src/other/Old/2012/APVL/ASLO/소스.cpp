#include "bitx.hpp"

#include <stdio.h>
int main()
{
	Char t[10];
	char xtt[10] = "asdfasdfo";
	for(int i = 0; i < 10; i++)
		t[i] = xtt[i];
	for(int i = 0; i < 10; i++)
		printf_s("%c", *t[i]);
	return 0;
}
