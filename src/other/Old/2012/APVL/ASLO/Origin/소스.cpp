#include "asloanal.h"
#include <stdio.h>

int main()
{
	char asd[1000];
	for(int i = 0; i < 1000; i++)
		asd[i] = 0;
	 __m_process<char> ("", 0, asd);
	printf("%s", asd);
	return 0;
}