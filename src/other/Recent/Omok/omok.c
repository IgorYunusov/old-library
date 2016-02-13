/*************************************************************************

   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:

   omok.c

Project:

   Console omok game

------
   AUTHOR: HyunJun Jeong  2015-05-30

***************************************************************************/

#include <conio.h>
#include <stdio.h>
#include <Windows.h>

static char board[20][41] = {
	"¦£¦¨¦¨¦¨¦¨¦¨¦¨¦¨¦¨¦¨¦¨¦¨¦¨¦¨¦¨¦¨¦¨¦¨¦¨¦¤",
	"¦§¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦©",
	"¦§¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦©",
	"¦§¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦©",
	"¦§¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦©",
	"¦§¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦©",
	"¦§¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦©",
	"¦§¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦©",
	"¦§¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦©",
	"¦§¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦©",
	"¦§¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦©",
	"¦§¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦©",
	"¦§¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦©",
	"¦§¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦©",
	"¦§¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦©",
	"¦§¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦©",
	"¦§¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦©",
	"¦§¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦©",
	"¦§¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦«¦©",
	"¦¦¦ª¦ª¦ª¦ª¦ª¦ª¦ª¦ª¦ª¦ª¦ª¦ª¦ª¦ª¦ª¦ª¦ª¦ª¦¥",
};

void fast_cls();
void print();
void gotoxy(int x, int y);
int x, y;
int switchs;	// Black: 0, White: 1
char switch_ch[2] = { '¡Û', '¡Ü' };

void print()
{
	int i;
	fast_cls();
	for (i = 0; i < 20; i++)
		printf("%s\n", board[i]);
}

void fast_cls()
{ // http://support.microsoft.com/kb/99261/ko
	COORD coordScreen = { 0, 0 };
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	BOOL bSuccess;
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;

	bSuccess = GetConsoleScreenBufferInfo(hConsole, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	bSuccess = FillConsoleOutputCharacter(hConsole, (TCHAR) ' ',
		dwConSize, coordScreen, &cCharsWritten);
	bSuccess = GetConsoleScreenBufferInfo(hConsole, &csbi);
	bSuccess = FillConsoleOutputAttribute(hConsole, csbi.wAttributes,
		dwConSize, coordScreen, &cCharsWritten);
	bSuccess = SetConsoleCursorPosition(hConsole, coordScreen);
	return;
}

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void event_keydown(char key)
{
	switch(key)
	{
	case 72:	// Up
		if (y > 0) y--;
		break;
	case 80:	// Down
		if (y < 19) y++;
		break;
	case 77:	// Right
		if (x < 38) x += 2;
		break;
	case 75:	// Left
		if (x > 0) x -= 2;
		break;
	case 32:	// Space
		switchs = !switchs;
		board[y][x] = switch_ch[switchs];
		print();
		break;
	}
}

int main()
{
	x = y = 0;
	switchs = 0;
	print();
	gotoxy(0, 0);

	for(;;)
	{
		event_keydown(_getch());
		gotoxy(x, y);
	}
	return 0;
}