#include <stdio.h>
#include <tchar.h>
#include <string.h>
#include <memory.h>
#include "sbcs_mbcs.h"
#include <iostream>
#include "string.h"
#include "_stdio.h"
#include "rpass.h"
//#include "tcdef.h"
#include "tcvcpu.h"
#include <Windows.h>
//#include "tcdef.h"

using namespace std;

int main()
{
	cout /*<< "  __________________________________________________________________________" << endl
		 << "    ______                             _                                    " << endl
		 << "      /                              /  `                      ,            " << endl
		 << "     /       __   )__   )__    __  _/__     __   )__   _  _        __    __ " << endl
		 << "    /      /___) /   ) /   ) /   ) /      /   ) /   ) / /  ) /   /   ) /   )" << endl
		 << "   /      (___  /     /     (___(_/      (___/_/     / /  / /   /   / (___/ " << endl
		 << "                                                                         /  " << endl
		 << "                                                                     (_ /   " << endl
		 << "  __________________________________________________________________________" << endl*/
		 << endl
		 << "        ┌──┐" << endl
		 << "        │■□│   RollRat Terraforming [Core Version 1.13.5]" << endl
		 << "        │□■│   (C) 2014 rollrat. All rights reserved" << endl
		 << "        └──┘" << endl;

	/*char strx[20];
	int f = 0;
	for (int i = 0; i < 20; i++)
		strx[i] = 0;
	_sprintf_aes(strx, "%s", "tyr");
	cout << strx << endl;

	char * enc = (char *)Encryption((unsigned char *)"rollrat", 7, (unsigned char *)"kkrollrat", 9);
	cout << enc << endl;
	char * dec = (char *)Decryption((unsigned char *)enc, strlen(enc), (unsigned char *)"kkrollrat", 9);
	cout << dec << endl;*/

	//rpass_enc_file("c:\\rollrat\\RollRat_Flood.7z", "rollrat");
	//rpass_dec_file("c:\\rollrat\\RollRat_Flood.7z.rpass", "rollrat");
	sem_file("C:\\rollrat\\RollRat_Flood.7z.rpass");
	mds_file_check("C:\\rollrat\\32.txt.sem");
	mds_file("C:\\rollrat\\32.txt.sem");

	tcv_cpu_status tcs;
	tcv_ram tr;

	tcv_cpu_init(&tcs);
	tr = tcv_ram_init();

	return 0;
}