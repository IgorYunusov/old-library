#include <stdio.h>

#include <string.h>
#include <malloc.h>

// ROLLRAT PASSWORD ENC_DEC ALGORITHM

// ENC ALGORITHM
inline unsigned char get(unsigned char y)
	{
const unsigned char libcode[] = {230, 229, 223, 247, 146, 134, 161, 116, 209, 58, 
		136, 74, 50, 129, 41, 190, 184, 84, 97, 238, 33, 47, 82, 13, 195, 
		231, 218, 114, 104, 115, 202, 191, 117, 59, 135, 14, 166, 6, 208, 
		226, 130, 206, 37, 71, 163, 32, 128, 2, 224, 219, 120, 91, 213, 
		221, 183, 210, 52, 169, 171, 46, 255, 11, 94, 111, 200, 212, 245, 160, 
		176, 18, 77, 143, 158, 96, 45, 197, 31, 198, 89, 150, 81, 100, 92, 
		189, 243, 179, 118, 112, 180, 126, 42, 201, 63, 87, 101, 12, 20, 
		131, 29, 99, 53, 153, 172, 159, 177, 241, 106, 40, 239, 80, 156, 227, 204, 
		38, 211, 28, 102, 142, 93, 244, 168, 26, 39, 185, 56, 95, 23, 236, 
		70, 109, 174, 44, 249, 246, 124, 65, 182, 188, 90, 157, 162, 57, 5, 
		254, 105, 69, 173, 79, 19, 64, 199, 17, 175, 141, 86, 9, 119, 123, 
		220, 167, 49, 151, 125, 43, 186, 35, 149, 140, 55, 155, 113, 51, 
		144, 98, 83, 228, 10, 27, 78, 170, 217, 88, 24, 252, 138, 72, 68, 
		25, 240, 203, 133, 187, 205, 139, 145, 7, 0, 154, 147, 164, 66, 194, 
		132, 193, 234, 110, 248, 148, 3, 121, 8, 36, 122, 253, 137, 75, 34, 
		54, 30, 4, 233, 61, 107, 16, 235, 85, 250, 215, 251, 152, 181, 60, 
		108, 232, 214, 15, 103, 222, 73, 196, 216, 165, 62, 48, 76, 192, 1, 
		225, 127, 237, 242, 21, 22, 67, 207, 178};
const unsigned char libcodex[] = {
		0xE6, 0xE5, 0xDF, 0xF7, 0x92, 0x86, 0xA1, 0x74, 
		0xD1, 0x3A, 0x88, 0x4A, 0x32, 0x81, 0x29, 0xBE, 
		0xB8, 0x54, 0x61, 0xEE, 0x21, 0x2F, 0x52, 0x0D, 
		0xC3, 0xE7, 0xDA, 0x72, 0x68, 0x73, 0xCA, 0xBF, 
		0x75, 0x3B, 0x87, 0x0E, 0xA6, 0x06, 0xD0, 0xE2, 
		0x82, 0xCE, 0x25, 0x47, 0xA3, 0x20, 0x80, 0x02, 
		0xE0, 0xDB, 0x78, 0x5B, 0xD5, 0xDD, 0xB7, 0xD2, 
		0x34, 0xA9, 0xAB, 0x2E, 0xFF, 0x0B, 0x5E, 0x6F, 
		0xC8, 0xD4, 0xF5, 0xA0, 0xB0, 0x12, 0x4D, 0x8F, 
		0x9E, 0x60, 0x2D, 0xC5, 0x1F, 0xC6, 0x59, 0x96, 
		0x51, 0x64, 0x5C, 0xBD, 0xF3, 0xB3, 0x76, 0x70, 
		0xB4, 0x7E, 0x2A, 0xC9, 0x3F, 0x57, 0x65, 0x0C, 
		0x14, 0x83, 0x1D, 0x63, 0x35, 0x99, 0xAC, 0x9F, 
		0xB1, 0xF1, 0x6A, 0x28, 0xEF, 0x50, 0x9C, 0xE3, 
		0xCC, 0x26, 0xD3, 0x1C, 0x66, 0x8E, 0x5D, 0xF4, 
		0xA8, 0x1A, 0x27, 0xB9, 0x38, 0x5F, 0x17, 0xEC, 
		0x46, 0x6D, 0xAE, 0x2C, 0xF9, 0xF6, 0x7C, 0x41, 
		0xB6, 0xBC, 0x5A, 0x9D, 0xA2, 0x39, 0x05, 0xFE, 
		0x69, 0x45, 0xAD, 0x4F, 0x13, 0x40, 0xC7, 0x11, 
		0xAF, 0x8D, 0x56, 0x09, 0x77, 0x7B, 0xDC, 0xA7, 
		0x31, 0x97, 0x7D, 0x2B, 0xBA, 0x23, 0x95, 0x8C, 
		0x37, 0x9B, 0x71, 0x33, 0x90, 0x62, 0x53, 0xE4, 
		0x0A, 0x1B, 0x4E, 0xAA, 0xD9, 0x58, 0x18, 0xFC, 
		0x8A, 0x48, 0x44, 0x19, 0xF0, 0xCB, 0x85, 0xBB, 
		0xCD, 0x8B, 0x91, 0x07, 0x00, 0x9A, 0x93, 0xA4, 
		0x42, 0xC2, 0x84, 0xC1, 0xEA, 0x6E, 0xF8, 0x94, 
		0x03, 0x79, 0x08, 0x24, 0x7A, 0xFD, 0x89, 0x4B, 
		0x22, 0x36, 0x1E, 0x04, 0xE9, 0x3D, 0x6B, 0x10, 
		0xEB, 0x55, 0xFA, 0xD7, 0xFB, 0x98, 0xB5, 0x3C, 
		0x6C, 0xE8, 0xD6, 0x0F, 0x67, 0xDE, 0x49, 0xC4, 
		0xD8, 0xA5, 0x3E, 0x30, 0x4C, 0xC0, 0x01, 0xE1, 
		0x7F, 0xED, 0xF2, 0x15, 0x16, 0x43, 0xCF, 0xB2
	};
	return libcode[y];
	}

////////////////// 암호화 1단계 - 문자 암호화 //////////////////////////////////
//
// 1 : 문자하나하나 마다 1A ~ 4D, 32 ~ 35로 Xor연산하여 16글자로 부풀린다.
// 2 : (1, 3), (2, 2)를 바꾼다.
// 3 : 가로 1번째 줄을 1번 시프트, 두번째 줄을 2번 시프트한다.
// 4 : 한 배열에 전부 채우고 리턴한다.
inline unsigned char * enc_c(unsigned char s)
	{ // encryption character
	unsigned char ret[4][4];
	unsigned char *sret, buf;
	int i, f, z = 0;
	sret = (unsigned char *) malloc (sizeof(unsigned char) * 16);
	for(i = 0; i < 4; i++)
		for(f = 0; f < 4; f++)
			ret[i][f] = s;
	for(f = 0; f < 4; f++)
		for(i = 0; i < 4; i++)
			ret[i][f] ^= (i << 4) | (i + 0xA);
	for(i = 0; i < 4; i++)
		for(f = 0; f < 4; f++)
			ret[i][f] ^= 0x30 | (f + 0x2);
	buf = ret[1][3];
	ret[1][3] = ret[2][2];
	ret[2][2] = buf;
	buf = ret[1][0];
	for(f = 0; f < 3; f++)
		ret[1][f] = ret[1][f + 1];
	ret[1][3] = buf;
	buf = ret[2][0];
	for(f = 0; f < 3; f++)
		ret[2][f] = ret[2][f + 1];
	ret[2][3] = buf;
	buf = ret[2][0];
	for(f = 0; f < 3; f++)
		ret[2][f] = ret[2][f + 1];
	ret[2][3] = buf;
	for(f = 0; f < 4; f++)
		for(i = 0; i < 4; i++, z++)
			sret[z] = ret[i][f];
	return sret;
	}

////////////////// 암호화 2단계 - 키 암호화 //////////////////////////////////
//
// 1 : KEY사이즈 만큼 문자하나하나 전부 XOR연산을 한다. (1개당 15개 모두)
// 2 : 리턴한다.
inline  unsigned char **enc_k(unsigned char ** s, int strsize, unsigned char * key, int keysize)
	{ // encryption with key
	int i, f, g;
	for(f = 0; f <= strsize; f++)
		for(i = 0; i <= keysize; i++)
			for(g = 0; g <= 15; g++)
				s[f][g] ^= key[i];
	return s;
	}

////////////////// 암호화 3단계 - 치환 //////////////////////////////////
//
// 1 : GET함수에서 치환된 Hex값을 가져온다.
// 2 : 적용하고 리턴한다.
inline unsigned char **enc_h(unsigned char ** s, int strsize)
	{ // encryption hex
	int i, f;
	for(f = 0; f <= strsize; f++)
		for(i = 0; i <= 15; i++)
			s[f][i] = get(s[f][i]);
	return s;
	}

////////////////// 암호화 메인 //////////////////////////////////
unsigned char *Encryption(unsigned char *what, int whatsize, unsigned char *key, int keysize)
	{ // encryption main
	unsigned char **enc = 0;
	unsigned char *ret = (unsigned char *) malloc (sizeof(unsigned char) * whatsize * 16);
	int i, z = 0;
	enc = (unsigned char **) malloc (sizeof(unsigned char *) * ( whatsize * 16 + 1));
	for(i = 0; i <= whatsize; i++)
		enc[i] = (unsigned char *) malloc (sizeof(unsigned char) * 16);
	for(i = 0; i <= whatsize; i++)
		enc[i] = enc_c(what[i]);
	enc_k(enc, whatsize, key, keysize);
	enc_h(enc, whatsize);
	for(i = 0; i <= whatsize; i++)
		for(int f = 0; f <= 15; f++, z++)
			ret[z] = enc[i][f];
	return ret;
	}

// DEC ALGORITHM
inline unsigned char get_d(unsigned char y)
	{
const unsigned char libcode_d[0xff] = {
		195, 245, 47, 207, 218, 141, 37, 194, 209, 154, 175, 60, 94, 23, 35, 234, 222, 150, 
		68, 147, 95, 250, 251, 125, 181, 186, 120, 176, 114, 97, 217, 75, 45, 20, 215, 164, 
		210, 42, 112, 121, 106, 14, 89, 162, 130, 73, 59, 21, 242, 159, 12, 170, 56, 99, 
		216, 167, 123, 140, 9, 33, 230, 220, 241, 91, 148, 134, 199, 252, 185, 144, 127, 43, 
		184, 237, 11, 214, 243, 69, 177, 146, 108, 79, 22, 173, 17, 224, 153, 92, 180, 77, 
		137, 51, 81, 117, 61, 124, 72, 18, 172, 98, 80, 93, 115, 235, 28, 143, 105, 
		221, 231, 128, 204, 62, 86, 169, 27, 29, 7, 32, 85, 155, 50, 208, 211, 156, 133, 
		161, 88, 247, 46, 13, 40, 96, 201, 189, 5, 34, 10, 213, 183, 192, 166, 152, 116, 
		70, 171, 193, 4, 197, 206, 165, 78, 160, 228, 100, 196, 168, 109, 138, 71, 102, 
		66, 6, 139, 44, 198, 240, 36, 158, 119, 57, 178, 58, 101, 145, 129, 151, 67, 103, 
		254, 84, 87, 229, 135, 54, 16, 122, 163, 190, 136, 82, 15, 31, 244, 202, 200, 24, 
		238, 74, 76, 149, 63, 90, 30, 188, 111, 191, 41, 253, 38, 8, 55, 113, 64, 52, 233, 
		226, 239, 179, 26, 49, 157, 53, 236, 2, 48, 246, 39, 110, 174, 1, 0, 25, 232, 219, 
		203, 223, 126, 248, 19, 107, 187, 104, 249, 83, 118, 65, 132, 3, 205, 131, 225, 227, 
		182, 212, 142};
	return libcode_d[y];
	}

////////////////// 복호화 1단계 - 치환 //////////////////////////////////
//
// 1 : GET함수에서 치환된 Hex값을 가져온다.
// 2 : 적용하고 리턴한다.
inline unsigned char **dec_h(unsigned char **s, int strsize)
	{ // decryption hex
	int i, f;
	for(f = 0; f <= strsize; f++)
		for(i = 0; i <= 15; i++)
			s[f][i] = get_d(s[f][i]);
	return s;
	}

////////////////// 복호화 2단계 - 키 복호화 //////////////////////////////////
//
// 1 : KEY사이즈 만큼 문자하나하나 전부 XOR연산을 한다. (1개당 15개 모두)
// 2 : 리턴한다.
inline unsigned char **dec_k(unsigned char ** s, int strsize, unsigned char * key, int keysize)
	{ // decryption with key
	int i, f, g;
	for(f = 0; f <= strsize; f++)
		for(i = 0; i <= keysize; i++)
			for(g = 0; g <= 15; g++)
				s[f][g] ^= key[i];
	return s;
	}

////////////////// 복호화 3단계 - 문자 복호화 //////////////////////////////////
//
// 1 : 가로 두번째 줄을 2번 시프트, 1번째 줄을 1번 시프트한다.
// 2 : (1, 3), (2, 2)을 바꾼다.
// 3 : 문자하나하나 마다 35 ~ 32, 4D ~ 1A로 Xor연산하여 16글자에서 1글자만 가져온다.
//              0, 3 이 정확하다.
// 4 : 그것을 리턴한다.
inline unsigned char dec_c(unsigned char *s)
	{ // decryption character
	unsigned char ret[4][4], buf;
	int i, f, z = 0;
	for(i = 0; i < 4; i++)
		for(f = 0; f < 4; f++, z++)
			ret[i][f] = s[z];
	buf = ret[1][3];
	for(f = 3; f > 0; f--)
		ret[1][f] = ret[1][f - 1];
	ret[1][0] = buf;
	buf = ret[2][3];
	for(f = 3; f > 0; f--)
		ret[2][f] = ret[2][f - 1];
	ret[2][0] = buf;
	buf = ret[2][3];
	for(f = 3; f > 0; f--)
		ret[2][f] = ret[2][f - 1];
	ret[2][0] = buf;
	buf = ret[1][3];
	ret[1][3] = ret[2][2];
	ret[2][2] = buf;
	for(i = 0; i < 4; i++)
		for(f = 0; f < 4; f++)
			ret[i][f] ^= 0x30 | (0x5 - f);
	for(f = 0; f < 4; f++)
		for(i = 0, z = 3; i < 4; i++, z--)
			ret[i][f] ^= (z << 4) | (z + 0xA);
	return ret[0][3];
	}

////////////////// 복호화 메인 //////////////////////////////////
unsigned char *Decryption(unsigned char *what, int whatsize, unsigned char *key, int keysize)
	{ // decryption main
	unsigned char **dec = 0;
	unsigned char *ret = (unsigned char *) malloc (sizeof(unsigned char) * (whatsize / 16 + 1));
	int i, z = 0;
	dec = (unsigned char **) malloc (sizeof(unsigned char *) * ( whatsize * 16 ));
	for(i = 0; i <= whatsize / 16; i++)
		dec[i] = (unsigned char *) malloc (sizeof(unsigned char) * 16);
	for(i = 0; i <= whatsize / 16; i++)
		for(int f = 0; f <= 15; f++, z++)
			dec[i][f] = what[z];
	dec_h(dec, whatsize / 16);
	dec_k(dec, whatsize / 16, key, keysize);
	for(i = 0; i <= whatsize / 16; i++)
		ret[i] = dec_c(dec[i]);
	ret[whatsize / 16] = '\0';
	return ret;
	}

int main()
{
	printf("%s\n\n", Encryption((unsigned char *)"asjkldfhjk", strlen("asjkldfhjk"), (unsigned char *)"asdfs", strlen("asdfs")));
	printf("%s\n\n", Decryption(Encryption((unsigned char *)"asjkldfhjk", strlen("asjkldfhjk"), (unsigned char *)"asdfs", strlen("asdfs")), 
		strlen((char *)Encryption((unsigned char *)"asjkldfhjk", strlen("asjkldfhjk"), (unsigned char *)"asdfs", strlen("asdfs"))),
		(unsigned char *)"asdfs", strlen("asdfs")));
	printf("%c\n", dec_c(enc_c('a')));

	unsigned char libcode[0xff+1];
	for(int i = 0; i < 256; i++){
		printf("%d ", libcode[get(i)] = i);
		if (!(i % 8))
			printf("\n");
	}
	printf("\n\n");
	for(int i = 0; i < 256; i++){
		printf("%d, ", libcode[i]);
		if (!(i % 8))
			printf("\n");
	}
	return 0;
}
