#include "stu_uic.h"


inline WORD swapWordEndian(WORD e)
{
	return ((e & 0xff00) >> 8) | ((e & 0xff) << 8);
}

inline DWORD swapDWordEndian(DWORD e)
{
	return ((e & 0xffff0000) >> 16) | ((e & 0xffff) << 16);
}

inline BYTE ReplaceBit(BYTE e)
{
	return ((e & 0xf) << 4) | ((e & 0xf0) >> 4);
}