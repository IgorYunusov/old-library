#include "IA_32-64_architectures.h"

int main()
{
	int zas = 3;
	__asm{
		push eax
		mov eax, 10
		mov eax, zas
	};
	ServerTerrior[5].name;
	return 0;
}