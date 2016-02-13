/*-------------------------------------------------

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

-------------------------------------------------*/

#pragma once
#ifndef _ROLLRAT_WINUTIL_
#define _ROLLRAT_WINUTIL_

#include "cutilityex.h"

#include <Windows.h>

#if defined(_EX_SUCCESS)

_X_LIB_BEGIN

template<class _WINDOW_RESETFUNCTION> 
	class _WINAPI_MANAGEMENT_WINDOW
	{ // window management class
	LPSTR _wnd_name;
	HINSTANCE _wnd_hinstance;
	_WINDOW_RESETFUNCTION WndProc;
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	public:

	void SetWndProc(_WINDOW_RESETFUNCTION _wndproc)
		{ // set wndproc
		WndProc = _wndproc;
		}

	void CreateNewWindow(LPSTR _classname, HINSTANCE hInstance)
		{ // create window
		_wnd_name = _classname;
		_wnd_hinstance=hInstance;
		WndClass.cbClsExtra=0;
		WndClass.cbWndExtra=0;
		WndClass.hbrBackground=(HBRUSH)GetStockObject(LTGRAY_BRUSH);
		WndClass.hCursor=LoadCursor(NULL,IDC_ARROW);
		WndClass.hIcon=LoadIcon(NULL,IDI_APPLICATION);
		WndClass.hInstance=_wnd_hinstance;
		WndClass.lpfnWndProc=(WNDPROC)WndProc;
		WndClass.lpszClassName=_wnd_name;
		WndClass.lpszMenuName=NULL;
		WndClass.style=CS_HREDRAW | CS_VREDRAW;
		RegisterClass(&WndClass);
		hWnd=CreateWindow(_wnd_name,_wnd_name,WS_OVERLAPPEDWINDOW,
		   CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
		   NULL,(HMENU)NULL,hInstance,NULL);
		}

	int Start(int nCmdShow)
		{
		ShowWindow(hWnd,nCmdShow);
		while(GetMessage(&Message,0,0,0)) 
		{TranslateMessage(&Message);
		DispatchMessage(&Message);}
		return Message.wParam;
		}

	HWND HANDLE()
		{ // get handle
		return hWnd;
		}



	};

_X_LIB_END

#endif

#endif