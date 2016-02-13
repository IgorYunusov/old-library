/************************************************************
 *															*
 *															*
 *			ROLLRAT AUTO PERSONA VERBOTER LIBROFEX			*
 *															*
 *															*
 *		COPYRIGHT (c) rollrat. 2013. ALL RIGHTS RESERVED.	*
 *															*
 *															*
 ************************************************************/

#pragma once

#ifndef __APVL_CONSOLE
#define __APVL_CONSOLE

#include <Windows.h>

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

class CONSOLE
{
public:

	CONSOLE()
		{
			Init();
#ifndef _APVL_CONSOLE_USELESS_INIT_SERVICE_SETCONSOLE
			SetConsoleMode(OUTPUT_HANDLE, ENABLE_WRAP_AT_EOL_OUTPUT);
#endif
			DisPlayBound = new CHAR_INFO[10000];

			Clear(0);
		}

	CONSOLE(int Width, int Height)
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

	CONSOLE(int Width, int Height, char * Title)
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

	void ForceSetConsole()
		{
			SetConsoleMode(OUTPUT_HANDLE, ENABLE_WRAP_AT_EOL_OUTPUT);
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
			COORD pos = {x, y};
			SetConsoleCursorPosition(OUTPUT_HANDLE, pos);
		}
	void Cursor_Size(DWORD size)
		{
			CONSOLE_CURSOR_INFO cci;
			cci.dwSize = size;
			SetConsoleCursorInfo(CONSOLE_HWND, &cci);
		}
	COORD Cursor_Get()
		{
			CONSOLE_SCREEN_BUFFER_INFO CSBI;
			GetConsoleScreenBufferInfo(OUTPUT_HANDLE, &CSBI);
			return CSBI.dwCursorPosition;
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
			DWORD attrwriten;
			COORD coord = { left, top };
			int i, width = right - left + 1;
	
			for (i = top; i <= bottom; i++) 
			{
				FillConsoleOutputAttribute(OUTPUT_HANDLE, attr, width, coord, &attrwriten);
				coord.Y++;
			}
		}

	void SaveDisplay(int x, int y, int w, int h)
		{
			SMALL_RECT RectEx = { x, y, x+w-1, y+h-1};
			COORD sz = { w, h };
			COORD xy = { 0, 0 };

			ReadConsoleOutput(OUTPUT_HANDLE, DisPlayBound, sz, xy, &RectEx);
		}
		
	void LoadDisplay(int x, int y, int w, int h)
		{
			SMALL_RECT RectEx = { x, y, x+w-1, y + h - 1};
			COORD sz = { w, h };
			COORD xy = { 0, 0 };

			WriteConsoleOutput(OUTPUT_HANDLE, DisPlayBound, sz, xy, &RectEx);
		}

	void SaveCursorPos()
		{
			Cursor_Pos = Cursor_Get();
		}

	void LoadCursorPos()
		{
			Cursor_Move(Cursor_Pos.X, Cursor_Pos.Y);
		}

	void SetTextAtt(DWORD color)
		{
			SetConsoleTextAttribute(OUTPUT_HANDLE, color);
		}

private:

	char * TITLE;

protected:

	HANDLE OUTPUT_HANDLE;
	HANDLE INPUT_HANDLE;
	HWND   CONSOLE_HWND;
	
	CHAR_INFO *DisPlayBound;
	WNDPROC conPROC;
	COORD Cursor_Pos;

};

#endif
