/*************************************************************************

   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:

   SHA_512.c

Project:

	RollRat DB Mmg SHA 512

------
   AUTHOR: HyunJun Jeong  2015-08-27

***************************************************************************/

#include <stdio.h>
#include <memory.h>
#include <string.h>
#include "SHA_256.h"
#include "SHA_512.h"

#define _Rotate_Left(x, r, n, t)  ((t)((x) << (r)) | (t)((x) >> ((n)-(r))))
#define _Rotate_Right(x, r, n, t)  ((t)((x) >> (r)) | (t)((x) << ((n)-(r))))
#define RR_UL(x, r)      _Rotate_Right(x, r, 32, SHA_ULONG)
#define RL_UL(x, r)      _Rotate_Left(x, r, 32, SHA_ULONG)
#define RR_ULL(x, r)     _Rotate_Right(x, r, 64, SHA_ULONGLONG)
#define RL_ULL(x, r)     _Rotate_Left(x, r, 64, SHA_ULONGLONG)

#define SHA_512_Ch(E,F,G)  (((E) & (F)) ^ ((~E) & (G)))
#define SHA_512_Maj(A,B,C)  (((A) & (B)) ^ ((B) & (C)) ^ ((C) & (A)))

#define SHA_512_SIGMA0(A)  (RR_ULL(A, 28) ^ RR_ULL(A, 34) ^ RR_ULL(A, 39))
#define SHA_512_SIGMA1(E)  (RR_ULL(E, 14) ^ RR_ULL(E, 18) ^ RR_ULL(E, 41))

#define SHA_512_s0(wi_15)  (RR_ULL(wi_15, 1) ^ RR_ULL(wi_15, 8) ^ (wi_15 >>  7))
#define SHA_512_s1(wi_2)   (RR_ULL(wi_2, 19) ^ RR_ULL(wi_2,  61) ^ (wi_2  >> 6))

#define SHA_512_LOOP(a, b, c, d, e, f, g, h ,i, t1, t2) {\
	t1 = h+SHA_512_SIGMA1(e)+SHA_512_Ch(e,f,g)+SHA_512_K[i]+w[i];\
	t2 = SHA_512_SIGMA0(a)+SHA_512_Maj(a,b,c);\
	}

#define SHA_512_XROLL(a, b, c, d, e, f, g, h, t1, t2) {\
 h = g, g = f, f = e, e = d + t1, d = c, c = b, b = a, a = t1 + t2;\
	 }

#define CONVERT_TO_LITTLE_ENDIAN(x) ((0x000000ff & x) << 24 | (0x0000ff00 & x) << 8 | (0x00ff0000 & x) >> 8 | (0xff000000 & x) >> 24)

#define CONVERT_TO_LITTLE_ENDIAN64(x) (CONVERT_TO_LITTLE_ENDIAN(x >> 32) | (CONVERT_TO_LITTLE_ENDIAN(x & 0xffffffff) << 32))

#define CONVERT_TO_LITTLE_ENDIAN64(x) \
	(\
		(SHA_ULONGLONG)(0x00000000000000ff & x) << 56 | \
		(SHA_ULONGLONG)(0x000000000000ff00 & x) << 40 | \
		(SHA_ULONGLONG)(0x0000000000ff0000 & x) << 24 | \
		(SHA_ULONGLONG)(0x00000000ff000000 & x) << 8  | \
		(SHA_ULONGLONG)(0x000000ff00000000 & x) >> 8  | \
		(SHA_ULONGLONG)(0x0000ff0000000000 & x) >> 24 | \
		(SHA_ULONGLONG)(0x00ff000000000000 & x) >> 40 | \
		(SHA_ULONGLONG)(0xff00000000000000 & x) >> 56   \
		)

typedef struct _sha512_context {
	SHA_ULONGLONG outdexs[8];
	SHA_BYTE buffer[128];
	size_t bytes;
	//SHA_ULONGLONG residue, inces;	// count
} SHA512_CONTEXT, *PSHA512_CONTEXT;

const SHA_ULONG SHA_512_K[80] = {
	0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc, 0x3956c25bf348b538, 
	0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118, 0xd807aa98a3030242, 0x12835b0145706fbe, 
	0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2, 0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235, 
	0xc19bf174cf692694, 0xe49b69c19ef14ad2, 0xefbe4786384f25e3, 0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
	0x2de92c6f592b0275, 0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5, 0x983e5152ee66dfab, 
	0xa831c66d2db43210, 0xb00327c898fb213f, 0xbf597fc7beef0ee4, 0xc6e00bf33da88fc2, 0xd5a79147930aa725, 
	0x06ca6351e003826f, 0x142929670a0e6e70, 0x27b70a8546d22ffc, 0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 
	0x53380d139d95b3df, 0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6, 0x92722c851482353b,
	0xa2bfe8a14cf10364, 0xa81a664bbc423001, 0xc24b8b70d0f89791, 0xc76c51a30654be30, 0xd192e819d6ef5218, 
	0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8, 0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 
	0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8, 0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb, 0x5b9cca4f7763e373, 
	0x682e6ff3d6b2b8a3, 0x748f82ee5defb2fc, 0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
	0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915, 0xc67178f2e372532b, 0xca273eceea26619c, 
	0xd186b8c721c0c207, 0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178, 0x06f067aa72176fba, 0x0a637dc5a2c898a6, 
	0x113f9804bef90dae, 0x1b710b35131c471b, 0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc, 
	0x431d67c49c100d4c, 0x4cc5d4becb3e42b6, 0x597f299cfc657e2a, 0x5fcb6fab3ad6faec, 0x6c44198c4a475817,
};

const SHA_BYTE pad[128] = { 0x80 };

void SHA512_Mixing(SHA_PULONGLONG indexs, SHA_PULONGLONG outdexs)
{
	SHA_ULONGLONG w[80];
	SHA_ULONGLONG i, a, b, c, d, e, f, g, h, t1, t2;
	
	for (i = 0; i < 16; i++)
		w[i] = CONVERT_TO_LITTLE_ENDIAN64(indexs[i]);

	for (i = 16; i < 80; i++)
		w[i] = SHA_512_s0(w[i - 15]) + w[i - 16] + w[i - 7] + SHA_512_s1(w[i - 2]);

	a = outdexs[0];
	b = outdexs[1];
	c = outdexs[2];
	d = outdexs[3];
	e = outdexs[4];
	f = outdexs[5];
	g = outdexs[6];
	h = outdexs[7];

	for (i = 0; i < 80; i++) {
		SHA_512_LOOP(a, b, c, d, e, f, g, h, i, t1, t2);
		SHA_512_LOOP(h, a, b, c, d, e, f, g, i + 1, t1, t2);
		SHA_512_LOOP(g, h, a, b, c, d, e, f, i + 2, t1, t2);
		SHA_512_LOOP(f, g, h, a, b, c, d, e, i + 3, t1, t2);
		SHA_512_LOOP(e, f, g, h, a, b, c, d, i + 4, t1, t2);
		SHA_512_LOOP(d, e, f, g, h, a, b, c, i + 5, t1, t2);
		SHA_512_LOOP(c, d, e, f, g, h, a, b, i + 6, t1, t2);
		SHA_512_LOOP(b, c, d, e, f, g, h, a, i + 7, t1, t2);
		i += 8;
	}
	
	/*

	Auto Generated.

	
        For i = 0 To 80
            RichTextBox1.AppendText("t1 = h + SHA_512_SIGMA1(e) + SHA_512_Ch(e, f, g) + SHA_512_K[" & i & "] + w[" & i & "];" & vbCrLf)
            RichTextBox1.AppendText("t2 = SHA_512_SIGMA0(a) + SHA_512_Maj(a, b, c);    d += t1;    h = t1 + t2;" & vbCrLf)
        Next

	*/

	outdexs[0] += a;
	outdexs[1] += b;
	outdexs[2] += c;
	outdexs[3] += d;
	outdexs[4] += e;
	outdexs[5] += f;
	outdexs[6] += g;
	outdexs[7] += h;
}

void SHA512_Update(PSHA512_CONTEXT cnxt, const SHA_BYTE *target, size_t size)
{
	/*SHA_ULONG i;

	cnxt->inces += size << 3;

	if (cnxt->inces < 0)
		cnxt->residue++;

	cnxt->residue += size >> 29;*/

	if (size == 0)
		return;

	const SHA_BYTE *end = target + size;
	size_t szbuf = cnxt->bytes % 128;

	//if (szbuf > 0)
	//	if (szbuf + size >= 128)
	//	{
	//		memcpy((SHA_PULONG)cnxt->buffer + szbuf, target, (size_t)(128 - szbuf));
	//		size -= 128 - szbuf;
	//		target += 128 - szbuf;
	//		cnxt->bytes += 128 - szbuf;
	//		SHA512_Mixing(target, cnxt->outdexs);
	//		szbuf = 0;
	//	}

	//while (size >= 128) {
	//	//memcpy((SHA_PULONG)cnxt->buffer, target, (size_t)size);
	//	SHA512_Mixing(target, cnxt->outdexs);
	//	target += 128;
	//	size -= 128;
	//	cnxt->bytes += 128;
	//}

	//if (size) 
	//{
	//	memcpy((SHA_PULONG)cnxt->buffer + szbuf, target, size);
	//	cnxt->bytes += size;
	//}

	/*cnxt->outdexs[0] += size;

	if (cnxt->outdexs[0] < size)
		cnxt->outdexs[1] += 1;*/

	if (szbuf > 0)
		if (szbuf + size >= 128)
		{
			memcpy((void *)(cnxt->buffer + szbuf), target, 128 - szbuf);
			cnxt->bytes += 128 - szbuf;
			target += 128 - szbuf;
			SHA512_Mixing(cnxt->buffer, cnxt->outdexs);
			szbuf = 0;
		}

	while (end >= target + 128) {
		SHA512_Mixing(cnxt->buffer, cnxt->outdexs);
		target += 128;
		cnxt->bytes += 128;
	}
	
	if (end > target) 
	{
		memcpy((void *)(cnxt->buffer + szbuf), target, end - target);
		cnxt->bytes += end - target;
	}
}

void SHA512_Final(PSHA512_CONTEXT cnxt, SHA_BYTE *bytes)
{
	SHA_ULONGLONG i; // , j, index, len;

	/*index = (cnxt->inces >> 3) % 128;
	cnxt->buffer[index++] = 0x80;

	if (index > 56) {
		memset((SHA_ULONGLONG)cnxt->buffer + index, 0, 64 - index);
		SHA512_Mixing((SHA_ULONGLONG)cnxt->buffer, cnxt->outdexs);
		memset((SHA_ULONGLONG)cnxt->buffer, 0, 56);
	}
	else
		memset((SHA_ULONGLONG)cnxt->buffer + index, 0, 56 - index);

	cnxt->buffer[14] = CONVERT_TO_LITTLE_ENDIAN64(cnxt->residue);
	cnxt->buffer[15] = CONVERT_TO_LITTLE_ENDIAN64(cnxt->inces);

	SHA512_Mixing((SHA_PULONGLONG)cnxt->buffer, cnxt->outdexs);*/

	SHA_BYTE desc[16] = { 0 };
	*(SHA_ULONGLONG *)(&desc[8]) = CONVERT_TO_LITTLE_ENDIAN64(cnxt->bytes << 3);
	SHA_ULONGLONG len = 1 + ((239 - (cnxt->bytes % 128)) % 128);
	//memset(desc, cnxt->bytes << 3, 8 * sizeof(SHA_BYTE));
	SHA512_Update(cnxt, pad, len);
	SHA512_Update(cnxt, desc, 16);

	for (i = 0; i < 64; i += 8)
		*(SHA_ULONGLONG *)(&bytes[i]) = CONVERT_TO_LITTLE_ENDIAN64((SHA_ULONGLONG)(cnxt->outdexs[i / 8]));
}

void SHA512_Init(PSHA512_CONTEXT init_tgt)
{
	/*init_tgt->residue = 0;
	init_tgt->inces = 0;*/
	init_tgt->bytes = 0;

	init_tgt->outdexs[0] = 0x6a09e667f3bcc908;
	init_tgt->outdexs[1] = 0xbb67ae8584caa73b;
	init_tgt->outdexs[2] = 0x3c6ef372fe94f82b;
	init_tgt->outdexs[3] = 0xa54ff53a5f1d36f1;
	init_tgt->outdexs[4] = 0x510e527fade682d1;
	init_tgt->outdexs[5] = 0x9b05688c2b3e6c1f;
	init_tgt->outdexs[6] = 0x1f83d9abfb41bd6b;
	init_tgt->outdexs[7] = 0x5be0cd19137e2179;
}

void SHA512(const SHA_BYTE *target, size_t len, SHA_BYTE *source)
{
	static SHA512_CONTEXT cnxt;

	SHA512_Init(&cnxt);
	SHA512_Update(&cnxt, target, len);
	SHA512_Final(&cnxt, source);
}

int main()
{
	SHA_BYTE x[64];
	int t1, t2;

	SHA512("abc", strlen("abc"), x);
	for (t1 = 0; t1 < 64; t1++)
		printf("%02x", x[t1]);
	putchar('\n');
	SHA512("abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu", strlen("abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu"), x);
	for (t1 = 0; t1 < 64; t1++)
		printf("%02x", x[t1]);
	putchar('\n');
	SHA512("rollratrollratrollratrollrat", strlen("rollratrollratrollratrollrat"), x);
	for (t1 = 0; t1 < 64; t1++)
		printf("%02x", x[t1]);
	putchar('\n');
	
	return 0;
}