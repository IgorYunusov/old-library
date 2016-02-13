#define _VECTOR_REMOVE_OPTION_USELESS
#define _CRT_SECURE_NO_WARNINGS
#define _APVL_USING_WINDOWS_CONSOLE_CONTROL
#define _APVL_CONSOLE_USELESS_INIT_SERVICE_SETCONSOLE

#include <stdio.h>
#include <WinSock2.h>
#include <locale.h> 
#include <time.h>
#include "librofex.h"

CONSOLE cSControl;

int CompareText(char * xx, char * xyx)
{
	for(int i = 0; xx[i] != 0; i++)
		if(xx[i] != xyx[i])
			return 0;
	return 1;
}

DWORD WINAPI LoadingThreading(PVOID vparam)
{
	while(1)
	{
		printf("¡¬");
		Sleep(100);
		cSControl.LoadCursorPos();
		printf("¡ª");
		Sleep(100);
		cSControl.LoadCursorPos();
		printf("£¯");
		Sleep(100);
		cSControl.LoadCursorPos();
		printf("¡ª");
		cSControl.LoadCursorPos();
		Sleep(100);
	}
	return 0;
}

DWORD WINAPI ThreadTest1(PVOID vparam)
{
	while(1)
	{
		printf("¡¬");
		Sleep(100);
		cSControl.Cursor_Move(2, 30);
		printf("¡ª");
		Sleep(100);
		cSControl.Cursor_Move(2, 30);
		printf("£¯");
		Sleep(100);
		cSControl.Cursor_Move(2, 30);
		printf("¡ª");
		Sleep(100);
		cSControl.Cursor_Move(2, 30);
	}
	return 0;
}

DWORD WINAPI ThreadTest2(PVOID vparam)
{
	while(1)
	{
		printf("¡¬");
		Sleep(100);
		cSControl.Cursor_Move(4, 30);
		printf("¡ª");
		Sleep(100);
		cSControl.Cursor_Move(4, 30);
		printf("£¯");
		Sleep(100);
		cSControl.Cursor_Move(4, 30);
		printf("¡ª");
		Sleep(100);
		cSControl.Cursor_Move(4, 30);
	}
	return 0;
}

DWORD WINAPI ThreadTest3(PVOID vparam)
{
	while(1)
	{
		printf("¡¬");
		Sleep(100);
		cSControl.Cursor_Move(6, 30);
		printf("¡ª");
		Sleep(100);
		cSControl.Cursor_Move(6, 30);
		printf("£¯");
		Sleep(100);
		cSControl.Cursor_Move(6, 30);
		printf("¡ª");
		Sleep(100);
		cSControl.Cursor_Move(6, 30);
	}
	return 0;
}

int main()
{
	FILTER x = *StateConnectingNew();
	GATHER gather;
	int whileic = 1;
	char	xx[40];
	WSADATA wsaData;
	SOCKET hServSock, hClntSock;
	SOCKADDR_IN servAddr, clntAddr;
	HANDLE hLoadingThread;
	DWORD dwThread;
	int korean = 0;
	HANDLE hThreadTest1, hThreadTest2, hThreadTest3;
	DWORD dwThreadTest1, dwThreadTest2, dwThreadTest3;
	
	cSControl.SetTitle("APVL Tool 1.0 : Unicase");
	cSControl.FullScreen();

#pragma region Title Module
	printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
	printf("&                                                                           &\n");
	printf("&                                                                           &\n");
	printf("&                  Auto Persona Verboter Librofex Tool                      &\n");
	printf("&                                V 1.0                                      &\n");
	printf("&                                                                           &\n");
	printf("&                                                                           &\n");
	printf("&  COPYRIGHT (C) ROLLRAT. ALL RIGHTS RESEVED.                               &\n");
	printf("&                                                                           &\n");
	printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");

	cSControl.VFillColor(0, 0, 1000, 1000, COLOR_BALANCE(NAVY ,YELLOW));
	cSControl.VFillColor(19, 3, 53, 4, COLOR_BALANCE(BLUE, CYAN));
#pragma endregion
	ApvlFileOpen("c:\rollrat.txt");
	while(whileic)
	{
		cSControl.SetTextAtt(COLOR_BALANCE(BLUE, GREEN));
		printf(" >>");
		cSControl.SetTextAtt(COLOR_BALANCE(BLACK, GRAY));
		putchar(' ');

		scanf("%s", xx);
		if(CompareText(xx, "thread"))
		{
			cSControl.SaveCursorPos();
			cSControl.Cursor_Move(70, 1);
			printf("[INIT]");
			cSControl.LoadCursorPos();
			cSControl.Cursor_Move(70, 2);
			cSControl.SaveCursorPos();
			hLoadingThread = CreateThread(0, 0, LoadingThreading, 0, 0, &dwThread);
			Sleep(1000);
		}
		else if(CompareText(xx, "delete"))
		{
			TerminateThread(hLoadingThread, 0);
		}
		else if(CompareText(xx, "socket"))
		{
			scanf("%s", xx);
			if(CompareText(xx, "rollratservicemode"))
			{
				cSControl.Clear(0);
				cSControl.Cursor_Move(0, 0);
				cSControl.SetTitle("Index Librorum Prohibitorum : Unicase");
				printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
				printf("$                                                                           $\n");
				printf("$                                                                           $\n");
				printf("$                      Index Librorum Prohibitorum                          $\n");
				printf("$                                V 1.0                                      $\n");
				printf("$                                                                           $\n");
				printf("$                                                                           $\n");
				printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
				while(whileic)
				{
					if(korean)
					{
						printf(" ¸í·É¾î : ");
						scanf("%s", xx);
					}
					else
					{
						printf(" ILP > ");
						scanf("%s", xx);
						if(CompareText(xx, "language"))
						{
							printf(" SET < ");
							scanf("%s", xx);
							if(CompareText(xx, "korean"))
							{
								printf("       COMPLETE\n");
								korean = 1;
							}
						}
						else if(CompareText(xx, "threadtest"))
						{
							hThreadTest1 = CreateThread(0, 0, ThreadTest1, 0, 0, &dwThreadTest1);
							Sleep(20);
							hThreadTest2 = CreateThread(0, 0, ThreadTest2, 0, 0, &dwThreadTest2);
							Sleep(50);
							hThreadTest3 = CreateThread(0, 0, ThreadTest3, 0, 0, &dwThreadTest3);
							Sleep(40);
						}
						else if(CompareText(xx, "threadtestterminate"))
						{
							TerminateThread(hThreadTest1, 0);
							TerminateThread(hThreadTest2, 0);
							TerminateThread(hThreadTest3, 0);
						}
					}
				}
			}
		}
	}

	return 0;
}