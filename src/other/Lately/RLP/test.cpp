#include <iostream>
#include <string>
#include <regex>
#include <Windows.h>
#include <fstream>
#include <iostream>
#include <functional> 
#include <cctype>
#include <locale>
#include <stack>
#include <initializer_list>
#include "aes.h"

//static uint8 key[16]={
//		0x41, 0x3E, 0xF0, 0xA1, 0xC6, 0x11, 0xE5, 0x50,
//		0x35, 0x8E, 0x7C, 0x36, 0x20, 0xF4, 0xA1, 0x77
//};

//int test()
//{
//	aes<> AES;
#define TEST_BUFF_SZ   (10*1024*1024)
//	unsigned char * buff = new unsigned char[TEST_BUFF_SZ+16];
//	unsigned char * encrypted = new unsigned char[TEST_BUFF_SZ + 16];
//	unsigned char * decrypted = new unsigned char[TEST_BUFF_SZ+16];
//	
//	for (int i = 0; i < TEST_BUFF_SZ + 16; i++)
//	{
//		encrypted[i] = 0;
//		decrypted[i] = 0;
//	}
//
//	char *t = "qlwkj;kanvonqporenqg;lkreng;jq";
//	for (int i = 0; i < strlen("qlwkj;kanvonqporenqg;lkreng;jq"); i++)
//	{
//		buff[i] = t[i];
//	}
//	buff[ strlen("qlwkj;kanvonqporenqg;lkreng;jq") ] = 0;
//
//	AES.AES_EncryptPCBC(key, buff, encrypted, TEST_BUFF_SZ);
//	AES.AES_DecryptPCBC(key, encrypted, decrypted, TEST_BUFF_SZ);
//	std::cout << encrypted << std::endl;
//	std::cout << decrypted << std::endl;
//
//	return 0;
//}
using namespace std;

int amain()
{
	cout << "             %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
		 << "             %                                                     %" << endl
		 << "             %       ROLLRAT READING LINSENCE PERMIT      1.0      %" << endl
		 << "             %       <Encrypt>                                     %" << endl
		 << "             %                                                     %" << endl
		 << "             %       COPYRIGHT ROLLRAT(C) 2014.                    %" << endl
		 << "             %                                                     %" << endl
		 << "             %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;

	cout << "Address : ";

	string str;
	
	cin >> str;
	ifstream inf(str, ifstream::binary);

	if (inf.fail()) {
		cerr << "    Unable to open file for reading!" << endl;
		return 1;
	}
	////////////////

	cout << "    Read file ..." ;
	inf.seekg(0,inf.end);
	long size = inf.tellg();
	inf.seekg(0);
	char* buffer = new char[size];
	inf.read (buffer,size);
	
	cout << endl << "    Complite read!    SIZE [" << size << " Bytes]"<< endl << endl;

	inf.close();
	/////////////////

	string wrtfile;
	cout << "SaveFileAddress : ";
	cin >> wrtfile;
	ofstream onf(wrtfile, ofstream::binary);

	/////////////////

	cout << "Key : ";
	char key[256];
	cin >> key;

	cout << "    Make key ..." ;
	char * buff = new char[size];
	char * encrypted = new char[size];

	for (int i = 0; i < size; i++)
		encrypted[i] = 0;
	for (int i = 0; i < size; i++)
		buff[i] = buffer[i];
	buffer[size] = 0;

	aes<char> AES;
	/*int t = 1;
	int size = 0;
	cout << endl;
	for(auto& iter : bi)
	{
		const char *_tmp = iter.c_str();
		int f = strlen(_tmp);
		for (int i = 0; i < f; i++)
			buff[i] = _tmp[i];
		AES.AES_EncryptCBC(key, buff, encrypted, TEST_BUFF_SZ);
		cout << "    ENCRPYT CBC [" << t << "]" << endl;
		onf << encrypted << endl;
		t++;
		size += f;
	}*/
	AES.AES_EncryptCBC(key, buff, encrypted, size);
	/*int f = 0;
	const char *ptr = encrypted+size;
	for (; *ptr == 0; ptr--)
		f++;*/
	onf.write (encrypted, size);
	//delete buff;
	//delete encrypted;
	//delete buffer;

	onf.close();

	/////////////////
	cout << endl << "Complete !" << endl;
	cout << "    Your Key : " << key << endl;


	return 0;
}

int main()
{
	cout << "             %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
		 << "             %                                                     %" << endl
		 << "             %       ROLLRAT READING LINSENCE PERMIT      1.0      %" << endl
		 << "             %       <Decypt>                                      %" << endl
		 << "             %                                                     %" << endl
		 << "             %       COPYRIGHT ROLLRAT(C) 2014.                    %" << endl
		 << "             %                                                     %" << endl
		 << "             %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;

	cout << "Address : ";

	string str;
	
	cin >> str;
	ifstream inf(str, ifstream::binary);

	if (inf.fail()) {
		cerr << "    Unable to open file for reading!" << endl;
		return 1;
	}
	////////////////

	cout << "    Read file ..." ;

	inf.seekg(0,inf.end);
	long size = inf.tellg();
	inf.seekg(0);
	char* buffer = new char[size];
	inf.read (buffer,size);
	
	cout << endl << "    Complite read!    SIZE [" << size << " Bytes]"<< endl << endl;

	inf.close();
	/////////////////

	string wrtfile;
	cout << "SaveFileAddress : ";
	cin >> wrtfile;
	ofstream onf(wrtfile, ofstream::binary);

	/////////////////

	cout << "Key : ";
	char key[256];
	cin >> key;/*
	cout << "Size : ";
	int size_a;
	cin >> size_a;*/

	cout << "    Make key ...";
	char * buff = new char[size];
	char * decrypted = new char[size];
	
	for (int i = 0; i < size; i++)
		decrypted[i] = 0;
	for (int i = 0; i < size; i++)
		buff[i] = buffer[i];
	buffer[size] = 0;

	aes<char> AES;
	/*int t = 1;
	int size = 0;
	cout << endl;
	for(auto& iter : bi)
	{
		const char *_tmp = iter.c_str();
		int f = strlen(_tmp);
		for (int i = 0; i < f; i++)
			buff[i] = _tmp[i];
		AES.AES_DecryptCBC(key, buff, decrypted, TEST_BUFF_SZ);
		cout << "    ENCRPYT CBC [" << t << "] origin : " << decrypted << endl;
		onf << decrypted << endl;
		t++;
		size += f;
	}*/
	AES.AES_DecryptCBC(key, buff, decrypted, size);
	onf.write (decrypted, size);
	//delete buff;
	//delete decrypted;
	//delete buffer;

	onf.close();

	/////////////////
	cout << endl << "Complete !" << endl;


	return 0;
}