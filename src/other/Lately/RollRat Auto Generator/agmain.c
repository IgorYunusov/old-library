#include "aghead.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>

void administrator_mode();

void getch_ex(char that[255])
{
	char ch=0;
	int c=0;
	printf("# password : ");
	ch = _getch();
	while(ch != 13)
	{
		int k=0;
		that[c++] = ch;
		//printf("*");
		ch = _getch();
		//putchar('\n');
		for(; k < c; k++)
			printf("%x %x %x %x %x %x %x %x %x %x ", 
				(BYTE)(that[k] ^ (BYTE)(ch)), 
				(BYTE)(that[k] ^ (BYTE)(~ch)), 
				(BYTE)(that[k] | (BYTE)(ch)), 
				(BYTE)(that[k] | (BYTE)(~ch)),
				(BYTE)(that[k] & (BYTE)(ch)),
				(BYTE)(that[k] & (BYTE)(~ch)),
				(BYTE)(that[k] + (BYTE)(ch)),
				(BYTE)(that[k] + (BYTE)(~ch)),
				(BYTE)(that[k] - (BYTE)(ch)),
				(BYTE)(that[k] - (BYTE)(~ch)));
	}
	that[c] = 0;
}

void getch_star(char that[255])
{
	char ch=0;
	int c=0;
	printf("# password : ");
	ch = _getch();
	while(ch != 13)
	{
		int k=0;
		that[c++] = ch;
		printf("*");
		ch = _getch();
	}
	that[c] = 0;
}

void getch_none(char that[255])
{
	char ch=0;
	int c=0;
	printf("# password : ");
	ch = _getch();
	while(ch != 13)
	{
		int k=0;
		that[c++] = ch;
		ch = _getch();
	}
	that[c] = 0;
}

int main(int argc, char *argv[])
{
	char username[25];
	printf("RollRat Auto Generator¢â\n");
	printf("Copyright (C) rollrat. All rights reserved.\n\n");

//#ifndef _DEBUG
//	if (argc < 3) {
//		printf("Argument count should be more two argument for correct execution!");
//		return 1;
//	}
//#endif
RE:
	printf("# user name : ");
	scanf_s("%s", username, 25);

	if (!strcmp(username, "administrator"))
	{
		char pass[255];
		getch_none(pass);
		if (!strcmp(pass, "tkfkadmsandjtdmfhtksmsrk"/*"rollrat970613software@naver.comtkfkadmsandjtdmfhtksmsrk"*/)){
			printf(" true\nHi, administrator.\n\n");
			administrator_mode();
		} else {
			printf(" false\n\n");
			goto RE;
		}
	} else {
		printf("Hi, %s\n\n", username);
		while(1) {
			char command_input[255];
			printf("[guest@%s ~]$ ", username);
			scanf_s("%s", command_input, 255);
			if(!strcmp(command_input, "access")) {
				goto RE;
			}

		}
	}


	//ag_excuate_filedata("C:\\rollrat\\3.txt", "C:\\rollrat\\4.txt");
	//ag_excuate_filedata(argv[1], argv[2]);

	return 0;
}

void administrator_mode()
{
	char *command_input = (char *) malloc (255);
	BOOL security = FALSE;
	fgets (command_input, 255, stdin);
	while(1) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		printf("[");
		SetConsoleTextAttribute(hConsole, 10);
		printf("administrator");
		SetConsoleTextAttribute(hConsole, 7);
		printf("@");
		SetConsoleTextAttribute(hConsole, 14);
		printf("root ~");
		SetConsoleTextAttribute(hConsole, 7);
		printf("]$ ");
		if(security)
			getch_ex(command_input);
		else
			fgets (command_input, 255, stdin);
		if (!strcmp(command_input, "security\n"))
			if (security)
				printf("already run!\n");
			else
				printf("ok!\n"), security = TRUE;

		
		//scanf_s("%s", command_input, 255);
	}
}