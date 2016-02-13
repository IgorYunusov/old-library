
#include "EfAES.h"
#include "AESInterns.h"


#include <Windows.h>

DWORD t1,t2,t3,t4;
DWORD t5,t6,t7,t8;
// ecb cbc pcbc  crt ofb1~16 cfb1~16 ,
DWORD TimeRecord[36][5];


void recordTime(int index)
{
	TimeRecord[index][0]=1;
	TimeRecord[index][1]=t2-t1;
	TimeRecord[index][2]=t4-t3;
	TimeRecord[index][3]=t6-t5;
	TimeRecord[index][4]=t8-t7;
}

void dumpTimeRecord(void)
{
	char *list[]={ "ECB" , "CBC", "PCBC" ,"CRT"  ,
				  "OFB1" , "OFB2" , "OFB3" , "OFB4" , "OFB5" , "OFB6" , "OFB7" , "OFB8" ,
				  "OFB9" , "OFB10" , "OFB11" , "OFB12" , "OFB13" , "OFB14" , "OFB15" , "OFB16" ,
				  "CFB1" , "CFB2" , "CFB3" , "CFB4" , "CFB5" , "CFB6" , "CFB7" , "CFB8" ,  
				  "CFB9" , "CFB10" , "CFB11" , "CFB12" , "CFB13" , "CFB14" , "CFB15" , "CFB16"   
	};

	CFile f;
	CString fmt;
	int i;

	f.Open("D:\\works\\aes_reference\\my.time.txt",CFile::modeWrite | CFile::modeCreate);
	fmt = "     Encode,Decode,Encode,Decode\n";
	f.Write(fmt,fmt.GetLength());
	for(i=0;i<36;i++)
	{
		if(TimeRecord[i][0])
		{
			fmt.Format("%s %7d%7d%7d%7d\n", list[i],TimeRecord[i][1],TimeRecord[i][2],TimeRecord[i][3],TimeRecord[i][4]);
			f.Write(fmt,fmt.GetLength());
		}
	}
	f.Close();
}


void AesTestBasic(void)
{
	uint8 key[16]={ 0x2b,0x7e,0x15,0x16,
				   0x28,0xae,0xd2,0xa6,
				   0xab,0xf7,0x15,0x88,
				   0x09,0xcf,0x4f,0x3c };

	uint8 input[16]={
					0x32,0x43,0xf6,0xa8,\
					0x88,0x5a,0x30,0x8d,\
					0x31,0x31,0x98,0xa2,\
					0xe0,0x37,0x07,0x34
	};

	uint8 verify[16]={
		0x39,0x25,0x84,0x1d,0x02,0xdc,0x09,0xfb,
		0xdc,0x11,0x85,0x97,0x19,0x6a,0x0b,0x32

	};

	uint8 encrypted[16];
	uint8 decrypted[16];
	ALIGN AesCtx context;
    
	AesSetKey(&context,BLOCKMODE_ECB, key , 0);
	//aes_encrypt((uint32 *)input,(uint32 *)encrypted , ((AESContext *) &context)->AesEncKey  );
	//aes_decrypt((uint32 *)encrypted,(uint32 *)decrypted , ((AESContext *) &context)->AesDecKey );



#define TEST_LOOP 1000000000L
#define TEST_LOOP2 1000L


	uint32 in_test[256];
	uint32 out_test[16];
	memset(in_test,0,64);
	memset(out_test,0,64);



	CString fmt;

	fmt.Format("Correct encode:%s , decode:%s", (memcmp( encrypted, verify , 16 ) == 0 ) ? "Correct":"Wrong",
		(memcmp( input, decrypted , 16 ) == 0 ) ? "Correct":"Wrong"
		);
	AfxMessageBox(fmt);
}





#define TEST_BUFF_SZ   (10*1024*1024)
//#define TEST_BUFF_SZ   (1*1024*1024)
//#define TEST_BUFF_SZ   (128*1024)
#define BLOCK_SIZE  4096
//#define BLOCK_SIZE  TEST_BUFF_SZ
//#define TEST_BUFF_SZ   (4096)
//#define BLOCK_SIZE  (1024)

void fillPattern( uint8 * buff, int isize)
{
	int i;
	for(i=0;i<isize;i++)
	{
		buff[i]=i & 0xff;
	}

	for(i=isize;i<TEST_BUFF_SZ;i++)
	{
		buff[i]=0;
	}
}


static uint8 key[16]={
		0x41, 0x3E, 0xF0, 0xA1, 0xC6, 0x11, 0xE5, 0x50,
		0x35, 0x8E, 0x7C, 0x36, 0x20, 0xF4, 0xA1, 0x77
};

static uint8 input_vector[16] = 
{
	0x41, 0x3E, 0xF0, 0xA1, 0xC6, 0x11, 0xE5, 0x50,
	0x35, 0x8E, 0x7C, 0x36, 0x20, 0xF4, 0xA1, 0x77
};


	/*
	uint8 input_vector[16] = 
	{
		0xff, 0xff, 0xFf, 0xff, 0xff, 0xff, 0xFf, 0xff,
		0xff, 0xff, 0xFf, 0xff, 0xff, 0xff, 0xFf, 0xff
	};
	*/

unsigned char the_orig_buff[TEST_BUFF_SZ + AES_PADDING];

void TestECB(void * orig , void * encrypted,void * decrypted,int iSize)
{
	AesCtx ctx;
	int orig_size = iSize;
	int iRoundSize = AesRoundSize( iSize , 16 );

t1=GetTickCount();
	AesSetKey(&ctx,BLOCKMODE_ECB,key,0);
	AesEncryptECB( &ctx, encrypted   , orig , orig_size );
t2=GetTickCount();

t3=GetTickCount();
	AesSetKey(&ctx,BLOCKMODE_ECB,key,0);
	AesDecryptECB( &ctx, decrypted   , encrypted ,iRoundSize );
t4=GetTickCount();

	if( memcmp( orig , decrypted , iRoundSize ) != 0 )
	{
		AfxMessageBox("ECB Error");
	}

	// in place test
	memcpy( decrypted , orig , orig_size);
t5=GetTickCount();
	AesSetKey(&ctx,BLOCKMODE_ECB,key,0);
	AesEncryptECB( &ctx, decrypted   , decrypted , orig_size );
t6=GetTickCount();

	if( memcmp( encrypted , decrypted , iRoundSize ) != 0 )
	{
		AfxMessageBox("ECB Error cmp");
	}

t7=GetTickCount();
	AesSetKey(&ctx,BLOCKMODE_ECB,key,0);
	AesDecryptECB( &ctx , decrypted , decrypted , iRoundSize);
t8=GetTickCount();
	if( memcmp( orig , decrypted , iRoundSize ) != 0 )
	{
		AfxMessageBox("ECB in place Error");
	}

	recordTime(0);

}

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


void TestCBC(void * orig , void * encrypted,void * decrypted,int iSize)
{
	AesCtx ctx;
	int orig_size = iSize;
	int iRoundSize = AesRoundSize( iSize , 16 );
	unsigned char * pSrc;
	unsigned char * pDst;
	int iBlockSz;

t1=GetTickCount();
	AesSetKey(&ctx,BLOCKMODE_CBC,key,input_vector);
	BLOCK_LOOP(encrypted,orig,orig_size,AesEncryptCBC,BLOCK_SIZE);
t2=GetTickCount();

t3=GetTickCount();
	AesSetKey(&ctx,BLOCKMODE_CBC,key,input_vector);
	BLOCK_LOOP(decrypted,encrypted,iRoundSize,AesDecryptCBC,BLOCK_SIZE);
t4=GetTickCount();

	if( memcmp( orig , decrypted , iRoundSize ) != 0 )
	{
		AfxMessageBox("CBC Error");
	}

	// in place test
	memcpy( decrypted , orig , orig_size);


t5=GetTickCount();
	AesSetKey(&ctx,BLOCKMODE_CBC,key,input_vector);
	BLOCK_LOOP(decrypted,decrypted,orig_size,AesEncryptCBC,BLOCK_SIZE);
t6=GetTickCount();


	if( memcmp( encrypted , decrypted , iRoundSize ) != 0 )
	{
		AfxMessageBox("CBC Error cmp");
	}

t7=GetTickCount();
	AesSetKey(&ctx,BLOCKMODE_CBC,key,input_vector);
	BLOCK_LOOP(decrypted,decrypted,iRoundSize,AesDecryptCBC,BLOCK_SIZE);
t8=GetTickCount();

	if( memcmp( orig , decrypted , orig_size ) != 0 )
	{
		AfxMessageBox("CBC in place Error");
	}
	recordTime(1);


}

void TestPCBC(void * orig , void * encrypted,void * decrypted,int iSize)
{
	AesCtx ctx;
	int orig_size = iSize;
	int iRoundSize = AesRoundSize( iSize , 16 );
	unsigned char * pSrc;
	unsigned char * pDst;
	int iBlockSz;

t1=GetTickCount();
	AesSetKey(&ctx,BLOCKMODE_PCBC,key,input_vector);
	BLOCK_LOOP(encrypted,orig,orig_size,AesEncryptPCBC,BLOCK_SIZE);
t2=GetTickCount();

t3=GetTickCount();
	AesSetKey(&ctx,BLOCKMODE_PCBC,key,input_vector);
	BLOCK_LOOP(decrypted,encrypted,iRoundSize,AesDecryptPCBC,BLOCK_SIZE);
t4=GetTickCount();

	if( memcmp( orig , decrypted , iRoundSize ) != 0 )
	{
		AfxMessageBox("PCBC Error");
	}

	// in place test
	memcpy( decrypted , orig , orig_size);


t5=GetTickCount();
	AesSetKey(&ctx,BLOCKMODE_PCBC,key,input_vector);
	BLOCK_LOOP(decrypted,decrypted,orig_size,AesEncryptPCBC,BLOCK_SIZE);
t6=GetTickCount();


	if( memcmp( encrypted , decrypted , iRoundSize ) != 0 )
	{
		AfxMessageBox("PCBC Error cmp");
	}

t7=GetTickCount();
	AesSetKey(&ctx,BLOCKMODE_PCBC,key,input_vector);
	BLOCK_LOOP(decrypted,decrypted,iRoundSize,AesDecryptPCBC,BLOCK_SIZE);
t8=GetTickCount();

	if( memcmp( orig , decrypted , orig_size ) != 0 )
	{
		AfxMessageBox("PCBC in place Error");
	}
	recordTime(2);


}

void TestCRT(void * orig , void * encrypted,void * decrypted,int iSize)
{
	AesCtx ctx;
	int orig_size = iSize;
	int iRoundSize = AesRoundSize( iSize , 16 );
	unsigned char * pSrc;
	unsigned char * pDst;
	int iBlockSz;

t1=GetTickCount();
	AesSetKey(&ctx,BLOCKMODE_CRT,key,input_vector);
	BLOCK_LOOP(encrypted,orig,orig_size,AesEncryptCRT,BLOCK_SIZE);
t2=GetTickCount();

	iSize = AesRoundSize( iSize , 16 );
t3=GetTickCount();
	AesSetKey(&ctx,BLOCKMODE_CRT,key,input_vector);
	AesDecryptCRT( &ctx, decrypted   , encrypted ,iSize );
	BLOCK_LOOP(decrypted,encrypted,orig_size,AesDecryptCRT,BLOCK_SIZE);
t4=GetTickCount();

	if( memcmp( orig , decrypted , iRoundSize ) != 0 )
	{
		AfxMessageBox("CRT Error");
	}

	// in place test
	memcpy( decrypted , orig , orig_size);

t5=GetTickCount();
	AesSetKey(&ctx,BLOCKMODE_CRT,key,input_vector);
	BLOCK_LOOP(decrypted,decrypted,orig_size,AesEncryptCRT,BLOCK_SIZE);
t6=GetTickCount();

	if( memcmp( encrypted , decrypted , iRoundSize ) != 0 )
	{
		AfxMessageBox("CRT Error cmp");
	}


t7=GetTickCount();
	AesSetKey(&ctx,BLOCKMODE_CRT,key,input_vector);
	BLOCK_LOOP(decrypted,decrypted,iRoundSize,AesDecryptCRT,BLOCK_SIZE);
t8=GetTickCount();
	if( memcmp( orig , decrypted , iRoundSize ) != 0 )
	{
		AfxMessageBox("CRT in place Error");
	}
	recordTime(3);

}


void TestOFB(void * orig , void * encrypted,void * decrypted,int iSize,int iFeedbackSize)
{
	AesCtx ctx;
	int orig_size = iSize;
	int iRoundSize = AesRoundSize( iSize , iFeedbackSize );
	int iRoundBlockSz = AesRoundSize( BLOCK_SIZE ,iFeedbackSize);
	unsigned char * pSrc;
	unsigned char * pDst;
	int iBlockSz;


t1=GetTickCount();
	AesSetKey(&ctx,BLOCKMODE_OFB,key,input_vector);
	AesSetFeedbackSize( &ctx , iFeedbackSize );
	BLOCK_LOOP(encrypted,orig,orig_size,AesEncryptOFB,iRoundBlockSz);
t2=GetTickCount();

	
t3=GetTickCount();
	AesSetKey(&ctx,BLOCKMODE_OFB,key,input_vector);
	AesSetFeedbackSize( &ctx , iFeedbackSize );
	BLOCK_LOOP(decrypted,encrypted,iRoundSize,AesDecryptOFB,iRoundBlockSz);
t4=GetTickCount();

	if( memcmp( orig , decrypted , iRoundSize ) != 0 )
	{
		AfxMessageBox("OFB Error");
	}

	// in place test
	memcpy( decrypted , orig , orig_size);

t5=GetTickCount();
	AesSetKey(&ctx,BLOCKMODE_OFB,key,input_vector);
	AesSetFeedbackSize( &ctx , iFeedbackSize );
	BLOCK_LOOP(decrypted,decrypted,orig_size,AesEncryptOFB,iRoundBlockSz);
t6=GetTickCount();

	if( memcmp( encrypted , decrypted , iRoundSize ) != 0 )
	{
		CString fmt;
		fmt.Format("OFB Error cmp %d",iFeedbackSize);
		AfxMessageBox(fmt);
	}


t7=GetTickCount();
	AesSetKey(&ctx,BLOCKMODE_OFB,key,input_vector);
	AesSetFeedbackSize( &ctx , iFeedbackSize );
	BLOCK_LOOP(decrypted,decrypted,iRoundSize,AesDecryptOFB,iRoundBlockSz);
t8=GetTickCount();
	if( memcmp( orig , decrypted , orig_size ) != 0 )
	{
		AfxMessageBox("OFB in place Error");
	}
	recordTime(4 + iFeedbackSize - 1);

}

void TestCFB(void * orig , void * encrypted,void * decrypted,int iSize,int iFeedbackSize)
{
	AesCtx ctx;
	int orig_size = iSize;
	int iRoundSize = AesRoundSize( iSize , iFeedbackSize );
	int iRoundBlockSz = AesRoundSize( BLOCK_SIZE ,iFeedbackSize);
	unsigned char * pSrc;
	unsigned char * pDst;
	int iBlockSz;

t1=GetTickCount();
	AesSetKey(&ctx,BLOCKMODE_CFB,key,input_vector);
	AesSetFeedbackSize(&ctx,iFeedbackSize);
	BLOCK_LOOP(encrypted,orig,orig_size,AesEncryptCFB,iRoundBlockSz);
t2=GetTickCount();


t3=GetTickCount();
	AesSetKey(&ctx,BLOCKMODE_CFB,key,input_vector);
	AesSetFeedbackSize(&ctx,iFeedbackSize);
	BLOCK_LOOP(decrypted,encrypted,iRoundSize,AesDecryptCFB,iRoundBlockSz);
t4=GetTickCount();

	if( memcmp( orig , decrypted , iRoundSize ) != 0 )
	{
		CString fmt;
		fmt.Format("CFB Error %d",iFeedbackSize);
		AfxMessageBox(fmt);
	}

	// in place test
	memcpy( decrypted , orig , orig_size);

t5=GetTickCount();
	AesSetKey(&ctx,BLOCKMODE_CFB,key,input_vector);
	AesSetFeedbackSize(&ctx,iFeedbackSize);
	BLOCK_LOOP(decrypted,decrypted,orig_size,AesEncryptCFB,iRoundBlockSz);
t6=GetTickCount();

	if( memcmp( encrypted , decrypted , orig_size ) != 0 )
	{
		AfxMessageBox("CFB Error cmp");
	}

t7=GetTickCount();
	AesSetKey(&ctx,BLOCKMODE_CFB,key,input_vector);
	AesSetFeedbackSize(&ctx,iFeedbackSize);
	BLOCK_LOOP(decrypted,decrypted,iRoundSize,AesDecryptCFB,iRoundBlockSz);
t8=GetTickCount();
	if( memcmp( orig , decrypted , orig_size ) != 0 )
	{
		CString fmt;
		fmt.Format("CFB in place Error ,%d , %d",iFeedbackSize,orig_size);
		AfxMessageBox(fmt);
	}
	recordTime(20 + iFeedbackSize - 1);

}


unsigned char quickLib[TEST_BUFF_SZ+16];
int comparef(unsigned char * buff, const char * filename)
{
	CFile f;
	f.Open(filename,CFile::modeRead);
	f.Read( quickLib , TEST_BUFF_SZ  );
	f.Close();
	if( memcmp( buff, quickLib, TEST_BUFF_SZ ) != 0 )
	{
		CString fmt;
		fmt.Format("Compare Error %s",filename);
		AfxMessageBox(fmt);
		return -1;
	}
	return 0;
}

void writeFile(const char *  filename,const void * buff , int size)
{
	CFile f;
	f.Open( filename,CFile::modeCreate | CFile::modeWrite);
	f.Write( buff , size  );
	f.Close();
}


void CreateRegisterInfo()
{
	char register_key[17]={ "lulala9998lulala" };
	char register_vector[17]={ "lulala9998lulala" };
	char register_info[] ={
		"Author:Robert Guan\n"
		"Social Number:L120222093\n"
		"Country:Taiwan\n"
		"Company:Extreme Fast WorkShop\n"
	};
	unsigned char ciphered_register_info[128];
	unsigned char test_decrypt_info[128];
	int i;

	AesCtx ctx;
	AesSetKey( &ctx, BLOCKMODE_CFB , register_key , register_vector );
	AesSetFeedbackSize( &ctx , 1 );

	int iSize = sizeof(register_info);

	AesEncryptCFB( &ctx , (void *) ciphered_register_info , register_info ,iSize  );

	//write done this data
	CFile f;
	f.Open("D:\\works\\aes_reference\\register_info.dat", CFile::modeCreate | CFile::modeWrite);
	CString fmt;
	for(i=0;i<iSize;i++)
	{
		fmt.Format("0x%02X,",ciphered_register_info[i]);
		f.Write(fmt,fmt.GetLength());
	}
	f.Close();

	// test decrypt
	AesSetKey( &ctx, BLOCKMODE_CFB , register_key , register_vector );
	AesSetFeedbackSize( &ctx , 1 );
	AesDecryptCFB( &ctx ,test_decrypt_info ,(void *) ciphered_register_info , iSize  );
}


void AesTestFile(void)
{
	CString fmt;
	AesCtx context;

	int i=0;
//	unsigned long x;
	unsigned char * buff = (unsigned char *) malloc ( TEST_BUFF_SZ + 16);
	unsigned char * encrypted = (unsigned char *) malloc ( TEST_BUFF_SZ + 16);
	unsigned char * decrypted = (unsigned char *) malloc ( TEST_BUFF_SZ + 16);


	fillPattern( buff,TEST_BUFF_SZ);
	fillPattern(the_orig_buff,TEST_BUFF_SZ);

#if 1

	//TestOFB( buff, encrypted , decrypted ,TEST_BUFF_SZ , 16);
	//TestCBC( buff, encrypted , decrypted ,TEST_BUFF_SZ );

	
	//for(i=0;i<=16;i++)
	i=0;
	{
		
		TestECB( buff, encrypted , decrypted ,TEST_BUFF_SZ -i);
		TestCBC( buff, encrypted , decrypted ,TEST_BUFF_SZ -i);
		TestPCBC( buff, encrypted , decrypted ,TEST_BUFF_SZ -i);
		
		//for(int j=1;j<=16;j++)
		int j=16;
		{
			TestOFB( buff, encrypted , decrypted ,TEST_BUFF_SZ -i,j);
			TestCFB( buff, encrypted , decrypted ,TEST_BUFF_SZ -i,j);
		}
		TestCRT( buff, encrypted , decrypted ,TEST_BUFF_SZ -i);
		// check if the source is changed ?
		if( memcmp( buff , the_orig_buff , TEST_BUFF_SZ -i ) != 0 )
		{
			AfxMessageBox("Source is changed");
		}
	}
	
	
	dumpTimeRecord();

#endif

#if 0
	// a special case to test counter mode..

	unsigned char input_vector_crt1[16]= { 0xf0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
									   0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff };


	fillPattern( buff,TEST_BUFF_SZ);
	AesSetKey( &context , BLOCKMODE_CRT , key , input_vector_crt1 );
	for(x=0;x< 0xfff;x++)
		AesEncryptCRT( &context,buff, buff , TEST_BUFF_SZ );
	writeFile("D:\\works\\aes_reference\\crt.test",buff,TEST_BUFF_SZ);



	AfxMessageBox("CRT done");
#endif


#if 0

	// compare data with quicklib
	

	/*
	TestECB( buff, encrypted , decrypted ,TEST_BUFF_SZ);
	comparef(encrypted , "d:\\works\\aes_reference\\quick.ecb");
	TestCBC( buff, encrypted , decrypted ,TEST_BUFF_SZ);
	comparef(encrypted , "d:\\works\\aes_reference\\quick.cbc");
	*/

	TestPCBC( buff, encrypted , decrypted ,TEST_BUFF_SZ);
	comparef(encrypted , "d:\\works\\aes_reference\\quick.pcbc");

	/*
	TestCRT( buff, encrypted , decrypted ,TEST_BUFF_SZ);
	comparef(encrypted , "d:\\works\\aes_reference\\quick.crt");

	
	
	for(i=1;i<=16;i++)
	{
		TestOFB( buff, encrypted , decrypted ,TEST_BUFF_SZ,i);
		CString fn;
		fn.Format("d:\\works\\aes_reference\\quick.ofb.%d",i);
		comparef(encrypted , fn);
	}
	

	for(i=1;i<=16;i++)
	{
		TestCFB( buff, encrypted , decrypted ,TEST_BUFF_SZ,i);
		CString fn;
		fn.Format("d:\\works\\aes_reference\\quick.cfb.%d",i);
		comparef(encrypted , fn);
	}
	*/

#endif

#if 0
	// create register info
	CreateRegisterInfo();
#endif 

#if 0

	uint8 key[16]={ 0x2b,0x7e,0x15,0x16,
				   0x28,0xae,0xd2,0xa6,
				   0xab,0xf7,0x15,0x88,
				   0x09,0xcf,0x4f,0x3c };

	AesSetKey(&context, BLOCKMODE_ECB, key , 0 );
	t1=GetTickCount();
	AesEncryptECB(&context,encrypted,buff,TEST_BUFF_SZ);
	t2=GetTickCount();
	fmt.Format("%d",t2-t1);
	AfxMessageBox(fmt);
#endif 

	free(buff);
	free(encrypted);
	free(decrypted);

	AfxMessageBox("Done");

}
