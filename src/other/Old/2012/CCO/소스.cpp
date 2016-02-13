/***********************************************************

_____    __  __   ______           __
/  __ |___\ \ \ \ /  __  | __   _ __\ \__
| |_| | _ \ | | | | |__| |/  \_| |/___  _/
|  __/ (_)| | | | |  _  / |(_)  |   | |
| |  \ ___/ |_| |_| | \ \ \____/    | |
\_/ \_\    \__\\__\_/  \_\          \_\

RollRatSoftware-PrivateProgrammingLab

Copyright (c) rollrat. 2009-2013 All rights reserved.


************************************************************/

#pragma once
#ifndef _ROLLRAT_CCO_
#define _ROLLRAT_CCO_

#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

enum ENU_COLORS
{
	BLACK,
	NAVY,
	GREEN,
	TEAL,
	MAROON,
	PURPLE,
	OLIVE,
	GRAY,
	SILVER,
	BLUE,
	LIME,
	CYAN,
	RED,
	MAGENTA,
	YELLOW,
	WHITE,
};

#define COLOR_BALANCE(b, f) ((WORD)((((b) << (4)) & ( 0xF0)) | ((f) & (0x0F))))

class CCO
{
public:

	CCO()
	{
		Init();

		SetConsoleMode(OUTPUT_HANDLE, ENABLE_WRAP_AT_EOL_OUTPUT);
		Cursor_Hide();

		Clear(0);
	}
	CCO(int Width, int Height)
	{
		Init();

		SetSize(Width, Height);
		SetConsoleMode(OUTPUT_HANDLE, ENABLE_WRAP_AT_EOL_OUTPUT);
		Cursor_Hide();
		char s[80];
		sprintf(s, "mode con cols=%d lines=%d", Width, Height);
		system(s);

		Clear(COLOR_BALANCE(WHITE, BLACK));
	}
	CCO(int Width, int Height, char * Title)
	{
		if (Title) SetTitle(Title);
		Init(Title);

		SetSize(Width, Height);
		SetConsoleMode(OUTPUT_HANDLE, ENABLE_WRAP_AT_EOL_OUTPUT);
		Cursor_Hide();
		char s[80];
		sprintf(s, "mode con cols=%d lines=%d", Width, Height);
		system(s);

		Clear(COLOR_BALANCE(WHITE, BLACK));
	}

	/************************************\
	* Name  :: Init     *
	* Purpose :: Initialize Buffer *
	\************************************/
	void Init()
	{
		OUTPUT_HANDLE = GetStdHandle(STD_OUTPUT_HANDLE);
		INPUT_HANDLE = GetStdHandle(STD_INPUT_HANDLE);
		CONSOLE_HWND = FindWindow("ConsoleWindowClass", NULL);
	}
	void Init(char * Titles)
	{
		OUTPUT_HANDLE = GetStdHandle(STD_OUTPUT_HANDLE);
		INPUT_HANDLE = GetStdHandle(STD_INPUT_HANDLE);
		CONSOLE_HWND = FindWindow(NULL, Titles);
	}

public: 

	void VSetPixel(int x, int y, DWORD rgb)
	{
		HDC hdc = GetDC(CONSOLE_HWND);
		SetPixel(hdc, x, y, rgb);
		ReleaseDC(CONSOLE_HWND, hdc);
	}
	void VTextOut(int x, int y, char * Text, int thick)
	{
		HDC hdc = GetDC(CONSOLE_HWND);
		TextOut(hdc, x, y, Text, thick);
		ReleaseDC(CONSOLE_HWND, hdc);
	}
	void VDrawLine(int x, int y, int x_, int y_)
	{
		HDC hdc = GetDC(CONSOLE_HWND);
		MoveToEx(hdc, x, y, NULL);
		LineTo(hdc, x_, y_);
		ReleaseDC(CONSOLE_HWND, hdc);
	}
	void VDrawTriangle(int x, int y, int x_, int y_, int x__, int y__)
	{
		HDC hdc = GetDC(CONSOLE_HWND);
		MoveToEx(hdc, x, y, NULL);
		LineTo(hdc, x_, y_);
		MoveToEx(hdc, x_, y_, NULL);
		LineTo(hdc, x__, y__);
		MoveToEx(hdc, x__, y__, NULL);
		LineTo(hdc, x, y);
		ReleaseDC(CONSOLE_HWND, hdc);
	}
	void VDrawRect(int x, int y, int Width, int Height)
	{
		HDC hdc = GetDC(CONSOLE_HWND);
		MoveToEx(hdc, x, y, NULL);
		LineTo(hdc, x, Height);
		LineTo(hdc, Width, Height);
		MoveToEx(hdc, x, y, NULL);
		LineTo(hdc, Width, y);
		LineTo(hdc, Width, Height);
		ReleaseDC(CONSOLE_HWND, hdc);
	}
	void SetConProc(void * conProc)
	{
		conPROC = (WNDPROC)SetClassLongPtr(CONSOLE_HWND, GCLP_WNDPROC, (LONG)conProc);
		CallWindowProc(conPROC, CONSOLE_HWND, 0, 0, 0);
	}

	/* Public Console Library Functions */

	void SetTitle(char * Title)
	{
		TITLE = Title;
		SetConsoleTitle(Title);
	}
	void SetSize(int Width, int Height)
	{
		SMALL_RECT sr= {0, 0, Width, Height};
		COORD sz = {Width, Height};

		SetConsoleScreenBufferSize(OUTPUT_HANDLE, sz);
		SetConsoleWindowInfo(INPUT_HANDLE, true, &sr);
	}
	void Clear()
	{
		Clear(VGetColor_BAL());
	}
	void Clear(WORD sCOLOR_BALANCE)
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		COORD pos={ 0, 0 };
		DWORD res;
		GetConsoleScreenBufferInfo(OUTPUT_HANDLE, &csbi);
		FillConsoleOutputCharacter(OUTPUT_HANDLE, ' ', csbi.dwSize.X * csbi.dwSize.Y , pos , &res);
		FillConsoleOutputAttribute(OUTPUT_HANDLE, sCOLOR_BALANCE , csbi.dwSize.X * csbi.dwSize.Y ,pos ,&res);
	}
	void FullScreen()
	{
		if(CONSOLE_HWND != NULL)
		{
			SendMessage(CONSOLE_HWND, WM_SYSKEYDOWN , VK_RETURN, 0x211C0001);
		}
	}
	/////////////////////////////////
	void Cursor_Shown()
	{
		CONSOLE_CURSOR_INFO cci;
		cci.bVisible = true;
		SetConsoleCursorInfo(OUTPUT_HANDLE, &cci);
	}
	void Cursor_Hide()
	{
		CONSOLE_CURSOR_INFO cci;
		cci.bVisible = false;
		SetConsoleCursorInfo(OUTPUT_HANDLE, &cci);
	}
	void Cursor_Move(int x, int y)
	{
		COORD pos = {x,y};
		SetConsoleCursorPosition(CONSOLE_HWND, pos);
	}
	void Cursor_Size(DWORD size)
	{
		CONSOLE_CURSOR_INFO cci;
		cci.dwSize = size;
		SetConsoleCursorInfo(CONSOLE_HWND, &cci);
	}
	/////////////////////////////////
	WORD VGetColor_BAL()
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(CONSOLE_HWND, &csbi);
		return csbi.wAttributes;
	}
	void VSetColor_BAL(WORD sCOLOR_BAL)
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(CONSOLE_HWND, &csbi);
		csbi.wAttributes = sCOLOR_BAL;
		SetConsoleTextAttribute(OUTPUT_HANDLE, sCOLOR_BAL);
	}
	WORD VGetColor()
	{
		return VGetColor_BAL() & 0x0F;
	}
	WORD VGetBackColor()
	{
		return (VGetColor_BAL() & 0xF0) >> 4;
	}
	void VSetColor(WORD fore)
	{
		VSetColor_BAL((VGetColor_BAL() & 0xF0) | (fore & 0x0F));
	}
	void VSetBackColor(WORD back)
	{
		VSetColor_BAL((VGetColor_BAL() & 0xF0) | ((back << 4) & 0x0F));
	}
	void VFillColor(int left, int top, int right, int bottom, WORD attr) 
	{
		DWORD cnt;
		COORD coord = { left, top };
		int i, width = right - left + 1;

		for (i = top; i <= bottom; i++) 
		{
			FillConsoleOutputCharacter(OUTPUT_HANDLE, attr, width, coord, &cnt);
			FillConsoleOutputAttribute(OUTPUT_HANDLE, attr, width, coord, &cnt);
			coord.Y++;
		}
	}

private:

	char * TITLE;

protected:

	HANDLE OUTPUT_HANDLE;
	HANDLE INPUT_HANDLE;
	HWND   CONSOLE_HWND;

	WNDPROC conPROC;

};

#endif

#define PI       3.14159265358979323846

void main()
{
	CCO B;

	srand((int)time(NULL)); 
	
	for(int l = 0; l < 100; l++)
		for(int h = 0; h < 500; h++)
			B.VSetPixel(h + 50, (int)sqrt((double)(rand() % 90000)), RGB(255,255,255));
	
	for(int l = 0; l < 100; l++)
		for(int h = 0; h < 500; h++)
			B.VSetPixel(h + 50, 365 - (int)sqrt((double)(rand() % 90000)), RGB(255,255,255));

	scanf("%d");
}