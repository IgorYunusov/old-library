#include "rtl.h"

#include <stdio.h>

main()
{
	char test[] = "  (asf";
	char * ptr = test;
	_sString(&ptr, SKIP_SPACE);

	//if_full(&ptr, 0);
	printf("%s", ptr);

	return 0;
}