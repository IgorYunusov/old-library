/*-------------------------------------------------

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

-------------------------------------------------*/


#pragma once
#ifndef _ROLLRAT_RWIN_
#define _ROLLRAT_RWIN_

#include <Windows.h>

class WINAPI_UTIL
{
public:

	WINAPI_UTIL(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpszCmdParam, int nCmdShow, 
		LPCSTR wTitle, HBRUSH BackColor, UINT Style, int x, int y, int width, int height)
		{
			CREATE_NEW_WINDOW(hInstance, hPrevInstance, IpszCmdParam, nCmdShow, wTitle, BackColor, Style, x, y, width, height);
		}

	HWND CREATE_NEW_WINDOW(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpszCmdParam, int nCmdShow, 
		LPCSTR wTitle, HBRUSH BackColor, UINT Style, int x, int y, int width, int height)
		{
			HWND hWnd;
			MSG Message;
			WNDCLASS WndClass;
			g_hInst = hInstance;

			WndClass.cbClsExtra = 0;
			WndClass.cbWndExtra = 0;
			WndClass.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
			WndClass.hCursor = LoadCursor(NULL,IDC_ARROW);
			WndClass.hIcon = LoadIcon(NULL,IDC_ARROW);
			WndClass.hInstance = hInstance;
			WndClass.lpfnWndProc = WndProc;
			WndClass.lpszClassName = IpszClass;
			WndClass.lpszMenuName = NULL;
			WndClass.style = CS_HREDRAW | CS_VREDRAW;
			RegisterClass(&WndClass);

			hWnd=CreateWindow(IpszClass,
				IpszClass,
				WS_OVERLAPPEDWINDOW, 
				CW_USEDEFAULT,
				CW_USEDEFAULT,
				480, 
				200,
				NULL,
				(HMENU)NULL,
				hInstance,NULL
				);
		}

};

#endif