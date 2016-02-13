/*************************************************************************
 *
 * FILE NAME : rpass.h - rollrat algorithm
 *
 * RollRat Terraforming Core
 *
 *
 * CREATION : 2013.07.30
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#ifndef _RPASS_
#define _RPASS

#include "riscldef.h"

#ifdef _EXECUTE_ON_DEVICE
#define USING_DEVICE_FLAG_RPASSH_
#endif

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */
	
unsigned char *Encryption(unsigned char *what, int whatsize, unsigned char *key, int keysize);
unsigned char *Decryption(unsigned char *what, int whatsize, unsigned char *key, int keysize);

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#ifdef __cplusplus
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

void rpass_enc_file(std::string addr, std::string key)
{
	std::ifstream inf(addr, std::ifstream::binary);
	if (inf.fail()) {
		std::cerr << "Error : " << std::endl <<
		"Unable to open file for reading!" << std::endl;
		return;
	}
	
    inf.seekg(0, inf.end);
	int gc = inf.tellg();
    inf.seekg (0, inf.beg);

	char * buffer = new char [gc];
	inf.read(buffer, gc);
	inf.close();

	char * enc_set = (char *)Encryption((unsigned char *)buffer, gc, (unsigned char *)key.c_str(), key.length());

	std::ofstream onf(addr + ".rpass", std::ofstream::binary);
	onf.write(enc_set, gc*16);
	onf.close();
	
	delete[] buffer;
}

bool check_rpass_file(std::string addr)
{
	return !(addr.compare(addr.length() - 6, 6, ".rpass"));
}

void rpass_dec_file(std::string addr, std::string key)
{
	if(!check_rpass_file(addr)) {
		std::cerr << "Error : " << std::endl <<
			"This is not sem file." << std::endl;
		return;
	}
	std::ifstream inf(addr, std::ifstream::binary);
	if (inf.fail()) {
		std::cerr << "Error : " << std::endl <<
		"Unable to open file for reading!" << std::endl;
		return;
	}
	
    inf.seekg(0, inf.end);
	int gc = inf.tellg();
    inf.seekg (0, inf.beg);

	char * buffer = new char [gc];
	inf.read(buffer, gc);
	inf.close();

	char * dec_set = (char *)Decryption((unsigned char *)buffer, gc, (unsigned char *)key.c_str(), key.length());

	std::ofstream onf(addr.substr(0, addr.size() - 6), std::ofstream::binary);
	onf.write(dec_set, gc/16);
	onf.close();

	delete[] buffer;
}
#endif


#endif