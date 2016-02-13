#include "structure.h"
#include "argvs.h"
#include <stdio.h>

struct xasfd{
	int x, y, z;
};

int main()
{
	xasfd yt = {0x1234, 0x4567, 0x8910};
	char *sxt = "asdfasdfaszxcv";
	int x = 0;
	___tg8_lock_ptr<char *, int> xtt;
	___tg8_argv_ptr<int> xttsx;


	x = xtt.Lock(sxt);
	sxt = xtt.UnLock(x + _INTSIZEOF(char));

	xttsx << 123;

	printf_s("%x %x", sizeof(int), _INTSIZEOF(int));

	return 0;
}