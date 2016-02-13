#include "rasm.h"
#include "aghead.h"
#include <stdio.h>


int main()
{
	get_register("[ebp-03h]");
	rename("", "");
	ag_excuate_filedata("C:\\rollrat\\3.txt", "C:\\rollrat\\4.txt");

	return 0;
}