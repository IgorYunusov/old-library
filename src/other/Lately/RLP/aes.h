/*************************************************************************
 *
 *					  ROLLRAT SOFTWARE LIBRARY
 *
 *                    Advanced Encryption Standard
 *
 *************************************************************************/

// EF Library http://www.codeproject.com/Articles/57478/A-Fast-and-Easy-to-Use-AES-Library

#ifndef _AES_
#define _AES_

#include "AESInterns.h"
#include "EfAES.h"

template<typename _ch = unsigned char> class aes
	{
	AesCtx ctx;
public:
#define BLOCK_SIZE  4096

	void AES_EncryptCBC(void *key, _ch *in, _ch *out, size_t size)
		{
		AesSetKey(&ctx,BLOCKMODE_CBC,key,0);
		int iSize = size;
		_ch *Src = in, *Dst = out;
		int iRoundSize = AesRoundSize( size , 16 );
		int iBlockSz;
		while(iSize > 0)
			{
				iBlockSz = (iSize > BLOCK_SIZE ) ? BLOCK_SIZE : iSize;
				AesEncryptCBC( &ctx, Dst, Src, iBlockSz );
				Dst += iBlockSz;
				Src += iBlockSz;
				iSize -= iBlockSz;
			}
		}

	void AES_DecryptCBC(void *key, _ch *in, _ch *out, size_t size)
		{
		AesSetKey(&ctx,BLOCKMODE_CBC,key,0);
		_ch *Src = in, *Dst = out;
		int iRoundSize = AesRoundSize( size , 16 );
		int iSize = iRoundSize;
		int iBlockSz;
		while(iSize > 0)
			{
				iBlockSz = (iSize > BLOCK_SIZE ) ? BLOCK_SIZE : iSize;
				AesDecryptCBC( &ctx, Dst, Src, iBlockSz );
				Dst += iBlockSz;
				Src += iBlockSz;
				iSize -= iBlockSz;
			}
		}

	void AES_EncryptPCBC(void *key, _ch *in, _ch *out, size_t size)
		{
		AesSetKey(&ctx,BLOCKMODE_PCBC,key,0);
		int iSize = size;
		_ch *Src = in, *Dst = out;
		int iRoundSize = AesRoundSize( size , 16 );
		int iBlockSz;
		while(iSize > 0)
			{
				iBlockSz = (iSize > BLOCK_SIZE ) ? BLOCK_SIZE : iSize;
				AesEncryptPCBC( &ctx, Dst, Src, iBlockSz );
				Dst += iBlockSz;
				Src += iBlockSz;
				iSize -= iBlockSz;
			}
		}

	void AES_DecryptPCBC(void *key, _ch *in, _ch *out, size_t size)
		{
		AesSetKey(&ctx,BLOCKMODE_PCBC,key,0);
		_ch *Src = in, *Dst = out;
		int iRoundSize = AesRoundSize( size , 16 );
		int iSize = iRoundSize;
		int iBlockSz;
		while(iSize > 0)
			{
				iBlockSz = (iSize > BLOCK_SIZE ) ? BLOCK_SIZE : iSize;
				AesDecryptPCBC( &ctx, Dst, Src, iBlockSz );
				Dst += iBlockSz;
				Src += iBlockSz;
				iSize -= iBlockSz;
			}
		}

	void AES_EncryptEBC(void *key, _ch *in, _ch *out, size_t size)
		{
		AesSetKey(&ctx,BLOCKMODE_ECB,key,0);
		AesEncryptECB(&ctx, out, in, size);
		}

	void AES_DecryptEBC(void *key, _ch *in, _ch *out, size_t size)
		{
		AesSetKey(&ctx,BLOCKMODE_ECB,key,0);
		AesDecryptECB( &ctx, out, in, AesRoundSize( size , 16 ) );
		}

	};

#endif