/*************************************************************************
 *
 * FILE NAME : sbcs_mbcs.h - SBCS Encrypt Decrypt as MBCS style
 *							 FOR simple document file
 * RollRat Terraforming Core
 *
 *
 * CREATION : 2014.12.05
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#ifndef _TERRAFORMING_SEM_MDS_
#define _TERRAFORMING_SEM_MDS_

#include "defines.h"

#define FINAL_XOR_KEY		0x8f

MBCS sem(SBCS ch)
{
	MBCS ret;
	SBCS ex = ~ch, xor_pre;

	ex = (ex << 4) | ((ex >> 4));

	xor_pre = ~(ch ^ ex);
	xor_pre = (xor_pre << 4) | (xor_pre >> 4);

	ret = (xor_pre ^ ex) | ((xor_pre ^ FINAL_XOR_KEY) << 8);
	return ret;
}

inline SBCS mds(MBCS chs)
{
	SBCS ret = chs ^ (chs >> 8) ^ FINAL_XOR_KEY;

	ret = ~((ret << 4) | (ret >> 4));

	return ret;
}

BOOL mds_check(MBCS chs)
{
	SBCS sbc = (chs >> 8) ^ FINAL_XOR_KEY;
	SBCS ble = sbc ^ chs;
	
	sbc = (~((sbc << 4) | (sbc >> 4))) ^ ble;
	ble = ~((ble << 4) | (ble >> 4));

	if ( ble ^ sbc )
		return FALSE;
	else
		return TRUE;
}

#ifdef __cplusplus
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

void sem_file(std::string addr)
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
	std::vector<unsigned short> mbcss(gc);

	char * buffer = new char [gc];
	inf.read(buffer, gc);
	inf.close();

	for (int i = 0; i < mbcss.size(); i++)
		mbcss[i] = sem(buffer[i]);

	std::ofstream onf(addr + ".sem", std::ofstream::binary);
	onf.write(reinterpret_cast<char *>(&mbcss[0]), mbcss.size()*sizeof(char)*2);
	onf.close();

	delete[] buffer;
}

bool check_sem_file(std::string addr)
{
	return !(addr.compare(addr.length() - 4, 4, ".sem"));
}

void mds_file(std::string addr)
{
	if(!check_sem_file(addr)) {
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
	std::vector<unsigned char> mbcss(gc/2);

	char * buffer = new char [gc];
	inf.read(buffer, gc);
	inf.close();

	for (int i = 0, j = 0; i < gc; i += 2, j++)
		mbcss[j] = mds((buffer[i+1] << 8) | (buffer[i] & 0xff));

	std::ofstream onf(addr.substr(0, addr.size() - 4), std::ofstream::binary);
	onf.write(reinterpret_cast<char *>(&mbcss[0]), mbcss.size()*sizeof(char));
	onf.close();

	delete[] buffer;
}

BOOL mds_file_check(std::string addr)
{
	if(!check_sem_file(addr)) {
		std::cerr << "Error : " << std::endl <<
			"This is not sem file." << std::endl;
		return FALSE;
	}
	std::ifstream inf(addr, std::ifstream::binary);
	if (inf.fail()) {
		std::cerr << "Error : " << std::endl <<
		"Unable to open file for reading!" << std::endl;
		return FALSE;
	}
	
    inf.seekg(0, inf.end);
	int gc = inf.tellg();
    inf.seekg (0, inf.beg);

	char * buffer = new char [gc];
	inf.read(buffer, gc);
	inf.close();

	for (int i = 0, j = 0; i < gc; i += 2, j++)
	{
		BOOL ret = mds_check((buffer[i + 1] << 8) | (buffer[i] & 0xff));
		if(FALSE == ret)
		{
			return i;
		}
	}

	delete[] buffer;

	return TRUE;
}
#endif

#endif