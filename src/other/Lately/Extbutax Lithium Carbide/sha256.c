#include <stdio.h>
#include <memory.h>
#include <string.h>
#include "elc.h"

#undef _Rotate_Left
#undef _Rotate_Right
#define _Rotate_Left(x, r, b, n)		(((x) << (r)) | ((b) >> ((n)-(r))))
#define _Rotate_Right(x, r, b, n)		(((x) >> (r)) | ((b) << ((n)-(r))))
#define RR_UL(x, r)						_Rotate_Right(x, r, 32, SHA_ULONG)
#define RL_UL(x, r)						_Rotate_Left(x, r, 32, SHA_ULONG)
#define RR_ULL(x, r)					_Rotate_Right(x, r, 64, unsigned long long)
#define RL_ULL(x, r)					_Rotate_Left(x, r, 64, unsigned long long)

#ifndef BIG_ENDIAN
#define CONVERT_TO_LITTLE_ENDIAN(x) ((0x000000ff & x) << 24 | (0x0000ff00 & x) << 8 | (0x00ff0000 & x) >> 8 | (0xff000000 & x) >> 24)
#else
#define CONVERT_TO_LITTLE_ENDIAN(x) x
#endif

const SHA_ULONG SHA_256_K[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

const SHA_ULONG SHA_256_H[8] = {
	0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
};

#define SHA_256_SIGMA0(A)		(RR_UL(A, 2) ^ RR_UL(A, 13) ^ RR_UL(A, 22))
#define SHA_256_SIGMA1(E)		(RR_UL(E, 6) ^ RR_UL(E, 11) ^ RR_UL(E, 25))

#define SHA_256_Ch(E,F,G)		(((E) & (F)) ^ ((~E) & (G)))
#define SHA_256_Maj(A,B,C)		(((A) & (B)) ^ ((B) & (C)) ^ ((C) & (A)))

#define SHA_256_s0(wi_15)		(RR_UL(wi_15, 7) ^ RR_UL(wi_15, 18) ^ (wi_15 >>  3))
#define SHA_256_s1(wi_2)		(RR_UL(wi_2, 17) ^ RR_UL(wi_2,  19) ^ (wi_2  >> 10))

#define SHA_256_LOOP(a, b, c, d, e, f, g, h ,i, t1, t2) {\
	t1 = h+SHA_256_SIGMA1(e)+SHA_256_Ch(e,f,g)+SHA_256_K[i]+w[i];\
	t2 = SHA_256_SIGMA0(a)+SHA_256_Maj(a,b,c);\
	}

#define SHA_256_XROLL(a, b, c, d, e, f, g, h, t1, t2) {\
	h = g, g = f, f = e, e = d + t1, d = c, c = b, b = a, a = t1 + t2;\
	}

void SHA256_Mixing(SHA_PULONG indexs, SHA_PULONG outdexs)
{
	SHA_ULONG w[64];
	SHA_ULONG i, a, b, c, d, e, f, g, h, t1, t2;

	for (i = 0; i < 16; i++)
		w[i] = CONVERT_TO_LITTLE_ENDIAN(indexs[i]);

	for(i = 16; i < 64; i++)
		w[i] = SHA_256_s0(w[i - 15]) + w[i - 16] + w[i - 7] + SHA_256_s1(w[i - 2]);

	a = outdexs[0];
	b = outdexs[1];
	c = outdexs[2];
	d = outdexs[3];
	e = outdexs[4];
	f = outdexs[5];
	g = outdexs[6];
	h = outdexs[7];
	
	for (i = 0; i < 64; i++) {
		SHA_256_LOOP(a, b, c, d, e, f, g, h, i, t1, t2);
		SHA_256_XROLL(a, b, c, d, e, f, g, h, t1, t2);
	}

	outdexs[0] += a;
	outdexs[1] += b;
	outdexs[2] += c;
	outdexs[3] += d;
	outdexs[4] += e;
	outdexs[5] += f;
	outdexs[6] += g;
	outdexs[7] += h;
}

void SHA256_Init(PSHA256_CONTEXT init_tgt)
{
	SHA_ULONG i;

	init_tgt->residue = 0;
	init_tgt->inces = 0;
	for (i = 0; i < 8; i++)
		init_tgt->outdexs[i] = SHA_256_H[i];
}

void SHA256_Update(PSHA256_CONTEXT cnxt, const SHA_BYTE *target, SHA_ULONG size)
{
	SHA_ULONG i;
	//const SHA_BYTE *tar;

	//tar = target;

	cnxt->inces += size << 3;

	if (cnxt->inces < 0)
		cnxt->residue++;

	cnxt->residue += size >> 29;

	//i = 0;

	/*if((cnxt->residue & 0x3f + size) > 64) {
		if(cnxt->residue) {
			i = cnxt->residue;
			i = 0-i;
			memcpy(cnxt->buffer + (cnxt->residue & 0x3f), target, i + 64);
			tar = cnxt->buffer;
		}
*/
		while (size >= 64) {
			memcpy((SHA_PULONG)cnxt->buffer, target, (size_t)size);
			SHA256_Mixing(target, cnxt->outdexs);
			target += 64;
			size -= 64;
			//tar = i + target;
		}/*
		i = 0;
	}*/

	memcpy((SHA_PULONG)cnxt->buffer, target, size);
	//cnxt->residue = size;
}

void SHA256_Final(PSHA256_CONTEXT cnxt, SHA_BYTE *bytes)
{
	SHA_ULONG i, j, index, len;
	//static const SHA_ULONG padding[64] = { 0x80, };

	//index = cnxt->residue & 0x3f;

	/*if (index < 56)
		len = (64 + 56) - index;
	else
		len = 56 - index;*/

	index = (cnxt->inces >> 3) % 64;
	cnxt->buffer[index++] = 0x80;

	//SHA256_Mixing((SHA_PULONG)cnxt->buffer, cnxt->outdexs);
	//j = cnxt->residue << 3;

	if(index > 56) {
		memset((SHA_ULONG)cnxt->buffer + index, 0, 64 - index);
		SHA256_Mixing((SHA_PULONG)cnxt->buffer, cnxt->outdexs);
		memset((SHA_ULONG)cnxt->buffer, 0, 56);
	}
	else
		memset((SHA_ULONG)cnxt->buffer + index, 0, 56 - index);

	cnxt->buffer[14] = CONVERT_TO_LITTLE_ENDIAN(cnxt->residue);
	cnxt->buffer[15] = CONVERT_TO_LITTLE_ENDIAN(cnxt->inces);

	//SHA256_Update(cnxt, padding, len);
	//SHA256_Update(cnxt, (const SHA_BYTE *)&j, sizeof(j));

	SHA256_Mixing((SHA_PULONG)cnxt->buffer, cnxt->outdexs);

	for (i = 0; i < 32; i += 4)
		*(SHA_ULONG *)(&bytes[i]) = CONVERT_TO_LITTLE_ENDIAN((SHA_ULONG)(cnxt->outdexs[i / 4]));
}

void SHA256(const SHA_BYTE *target, SHA_ULONG len, SHA_BYTE *source)
{
	static SHA256_CONTEXT cnxt;

	SHA256_Init(&cnxt);
	SHA256_Update(&cnxt, target, len);
	SHA256_Final(&cnxt, source);
}

//int main()
//{
//	int a = 'a', z = 'z', A = 'A', Z = 'Z', _0 = '0', _9 = '9';
//	int t1, t2;
//
//	SHA_BYTE x[32];
//
//	SHA256("", strlen(""), x);
//	for (t1 = 0; t1 < 32; t1++)
//		printf("%02x", x[t1]);
//	putchar('\n');
//	SHA256("rollratrollratrollratrollrat.", strlen("rollratrollratrollratrollrat."), x);
//	for (t1 = 0; t1 < 32; t1++)
//		printf("%02x", x[t1]);
//	putchar('\n');
//	//SHA256_Encrpyt("", strlen(""), x);
//	//for (t1 = 0; t1 < 32; t1++)
//	//	printf("%02x", x[t1]);
//	//putchar('\n');
//
//	printf("start\n");
//	for (t1 = a; t1 <= z; t1++)
//		for (t2 = A; t2 <= Z; t2++)
//			//for (t3 = _0; t3 <= _9; t3++)
//			printf("{'%c', '%c'}\n", t1, t2);//(t1^t2)|(t1 << t2));
//
//	return 0;
//}