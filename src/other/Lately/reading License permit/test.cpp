#include "AesInterns.h"
#include "EfAES.h"
#include <iostream>

static uint8 key[16]={
		0x41, 0x3E, 0xF0, 0xA1, 0xC6, 0x11, 0xE5, 0x50,
		0x35, 0x8E, 0x7C, 0x36, 0x20, 0xF4, 0xA1, 0x77
};


//static uint8 input_vector[16] = 
//{
//	0x41, 0x3E, 0xF0, 0xA1, 0xC6, 0x11, 0xE5, 0x50,
//	0x35, 0x8E, 0x7C, 0x36, 0x20, 0xF4, 0xA1, 0x77
//};

int main()
{
	//char *t = new char[50];
	//AesCtx ctx;
#define TEST_BUFF_SZ   (10*1024*1024)
	unsigned char * buff = new unsigned char[TEST_BUFF_SZ+16];
	unsigned char * encrypted = new unsigned char[TEST_BUFF_SZ + 16];
	unsigned char * decrypted = new unsigned char[TEST_BUFF_SZ+16];

	for (int i = 0; i < TEST_BUFF_SZ + 16; i++)
	{
		encrypted[i] = 0;
		decrypted[i] = 0;
	}

	char *t = "qlwkj;kanvonqporenqg;lkreng;jq";
	for (int i = 0; i < strlen("qlwkj;kanvonqporenqg;lkreng;jq"); i++)
	{
		buff[i] = t[i];
	}
	buff[ strlen("qlwkj;kanvonqporenqg;lkreng;jq") ] = 0;

	//AesSetKey(&ctx,BLOCKMODE_ECB,key,0);
	//AesEncryptCBC( &ctx, encrypted, buff, TEST_BUFF_SZ -16);

	////aes_encrypt(, (uint32 *)t, (uint32 *)"rollrat");
	//AesDecryptCBC( &ctx, decrypted, encrypted, TEST_BUFF_SZ - 16);
	//


#define    BLOCK_LOOP(dst,src,total_size,algorithm,block_size)       \
	iSize = total_size;\
	pSrc = (unsigned char *)src;\
	pDst = (unsigned char *)dst;\
	while(iSize > 0)\
	{\
		iBlockSz = (iSize > block_size ) ? block_size : iSize;\
		algorithm( &ctx, pDst   , pSrc , iBlockSz );\
		pDst += iBlockSz;\
		pSrc += iBlockSz;\
		iSize -= iBlockSz;\
	}

	AesCtx ctx;
	int orig_size = TEST_BUFF_SZ;
	int iRoundSize = AesRoundSize( TEST_BUFF_SZ , 16 );
	unsigned char * pSrc;
	unsigned char * pDst;
	int iBlockSz;
	int iSize = 0;

#define BLOCK_SIZE  4096
	AesSetKey(&ctx,BLOCKMODE_CBC,"rollrat",0);
	BLOCK_LOOP(encrypted,buff,orig_size,AesEncryptCBC,BLOCK_SIZE);
	
	AesSetKey(&ctx,BLOCKMODE_CBC,"rollrat",0);
	BLOCK_LOOP(decrypted,encrypted,iRoundSize,AesDecryptCBC,BLOCK_SIZE);

	std::cout << encrypted << std::endl;
	std::cout << decrypted;

	return 0;
}