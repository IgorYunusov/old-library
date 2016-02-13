/*=================================================

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

=================================================*/
#pragma once
#ifndef _winapisz_
#define _winapisz_

// 여기있는 함수들은 WinApi를 사용하는데 귀찮은 것들을 포함합니다.

#define WINMAIN_PARAMENT \
	HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow

#define WINMAIN_PARAMENT_HALF \
	HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR, int

#define MSG_LOOF while(GetMessage(&Message,0,0,0)) {\
		TranslateMessage(&Message);\
		DispatchMessage(&Message);}

#define WINPROC_PARAMENT \
	HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam

#define CLASS_INSTALL( _histance_ , _class_ ) \
	HWND hWnd;\
	MSG Message;\
	WNDCLASS WndClass;\
	_histance_=hInstance;\
	WndClass.cbClsExtra=0;\
	WndClass.cbWndExtra=0;\
	WndClass.hbrBackground=(HBRUSH)GetStockObject(LTGRAY_BRUSH);\
	WndClass.hCursor=LoadCursor(NULL,IDC_ARROW);\
	WndClass.hIcon=LoadIcon(NULL,IDI_APPLICATION);\
	WndClass.hInstance=hInstance;\
	WndClass.lpfnWndProc=(WNDPROC)WndProc;\
	WndClass.lpszClassName=_class_;\
	WndClass.lpszMenuName=NULL;\
	WndClass.style=CS_HREDRAW | CS_VREDRAW;\
	RegisterClass(&WndClass);

#define CLASS_INSTALLEX( _histance_ , _class_ ) \
	HWND hWnd;\
	MSG Message;\
	WNDCLASSEX WndClassEx;\
	_histance_=hInstance;\
	WndClassEx.cbClsExtra=0;\
	WndClassEx.cbWndExtra=0;\
	WndClassEx.hbrBackground=(HBRUSH)GetStockObject(LTGRAY_BRUSH);\
	WndClassEx.hCursor=LoadCursor(NULL,IDC_ARROW);\
	WndClassEx.hIcon=LoadIcon(NULL,IDI_APPLICATION);\
	WndClassEx.hInstance=hInstance;\
	WndClassEx.lpfnWndProc=(WNDPROC)WndProc;\
	WndClassEx.lpszClassName=_class_;\
	WndClassEx.lpszMenuName=NULL;\
	WndClassEx.style=CS_HREDRAW | CS_VREDRAW;\
	RegisterClassEx(&WndClassEx);

#define CLASS_SHOW( _class_ ) \
	hWnd=CreateWindow(_class_,_class_,WS_OVERLAPPEDWINDOW,\
		CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,\
		NULL,(HMENU)NULL,hInstance,NULL);\
	ShowWindow(hWnd,nCmdShow);
#define CLASS_SHOWXY( _class_, _x, _y)\
	hWnd=CreateWindow(_class_,_class_,WS_OVERLAPPEDWINDOW,\
		CW_USEDEFAULT,CW_USEDEFAULT,_x,_y,\
		NULL,(HMENU)NULL,hInstance,NULL);\
	ShowWindow(hWnd,nCmdShow);

#define CLASS_SHOWEx( _op_, _class_ ) \
	hWnd=CreateWindowEx(_op_,_class_,_class_,WS_OVERLAPPEDWINDOW,\
		CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,\
		NULL,(HMENU)NULL,hInstance,NULL);\
	ShowWindow(hWnd,nCmdShow);
#define CLASS_SHOWXYEx( _op_, _class_, _x, _y)\
	hWnd=CreateWindowEx(_op_,_class_,_class_,WS_OVERLAPPEDWINDOW,\
		CW_USEDEFAULT,CW_USEDEFAULT,_x,_y,\
		NULL,(HMENU)NULL,hInstance,NULL);\
	ShowWindow(hWnd,nCmdShow);

#define WWINMAIN( _histance_ , _class_ )\
	CLASS_INSTALL(_histance_, _class_)\
	CLASS_SHOW(_class_)\
	MSG_LOOF\
	return Message.wParam;

#define WWINMAINXY( _histance_ , _class_ , _x , _y)\
	CLASS_INSTALL(_histance_, _class_)\
	CLASS_SHOWXY(_class_, _x, _y)\
	MSG_LOOF\
	return Message.wParam;

#define WWINMAINXYEX( _histance_ , _class_ , _x , _y, _op_)\
	CLASS_INSTALLEX(_histance_, _class_)\
	CLASS_SHOWXYEx(_op_,_class_, _x, _y)\
	MSG_LOOF\
	return Message.wParam;

#define WINENTRY( _Class_ )\
	LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);\
	HINSTANCE g_hInst;\
	LPSTR lpszClass=_Class_;

#define Create_Edits(x, y, width, height, hMenu) CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_BORDER | ES_MULTILINE,\
		x, y, width, height, hWnd, (HMENU)hMenu, g_hInst, NULL)
#define Create_Edit(x, y, width, height, hMenu) CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE,\
		x, y, width, height, hWnd, (HMENU)hMenu, g_hInst, NULL)
#define Create_ListBox(x, y, width, height, hMenu) CreateWindow(TEXT("listbox"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | WS_VSCROLL | LBS_NOTIFY,\
		x, y, width, height, hWnd, (HMENU)hMenu, g_hInst, NULL)
#define Create_Button(caption, x, y, width, height, hMenu) CreateWindow(TEXT("button"), TEXT(caption), WS_CHILD| WS_VISIBLE | BS_PUSHBUTTON,\
		x, y, width, height, hWnd, (HMENU)hMenu, g_hInst, NULL)
#define Create_CRadioButton(caption, x, y, width, height, hMenu) CreateWindow(TEXT("button"), TEXT(caption), WS_CHILD| WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP,\
		x, y, width, height, hWnd, (HMENU)hMenu, g_hInst, NULL)
#define Create_RadioButton(caption, x, y, width, height, hMenu) CreateWindow(TEXT("button"), TEXT(caption), WS_CHILD| WS_VISIBLE | BS_AUTORADIOBUTTON,\
		x, y, width, height, hWnd, (HMENU)hMenu, g_hInst, NULL)
#define Create_CheckBox(caption, x, y, width, height, hMenu) CreateWindow(TEXT("button"), TEXT(caption), WS_CHILD| WS_VISIBLE | BS_CHECKBOX,\
		x, y, width, height, hWnd, (HMENU)hMenu, g_hInst, NULL)
#define Create_GroupBox(caption, x, y, width, height, hMenu) CreateWindow(TEXT("button"), TEXT(caption), WS_CHILD| WS_VISIBLE | BS_GROUPBOX,\
		x, y, width, height, hWnd, (HMENU)hMenu, g_hInst, NULL)

#define Create_EditsEx(x, y, width, height, hMenu) CreateWindowEx(0, TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_BORDER | ES_MULTILINE,\
		x, y, width, height, hWnd, (HMENU)hMenu, g_hInst, NULL)
#define Create_EditEx(x, y, width, height, hMenu) CreateWindowEx(0, TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE,\
		x, y, width, height, hWnd, (HMENU)hMenu, g_hInst, NULL)
#define Create_ListBoxEx(x, y, width, height, hMenu) CreateWindowEx(0, TEXT("listbox"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | WS_VSCROLL | LBS_NOTIFY,\
		x, y, width, height, hWnd, (HMENU)hMenu, g_hInst, NULL)
#define Create_ButtonEx(caption, x, y, width, height, hMenu) CreateWindowEx(0, TEXT("button"), TEXT(caption), WS_CHILD| WS_VISIBLE | BS_PUSHBUTTON,\
		x, y, width, height, hWnd, (HMENU)hMenu, g_hInst, NULL)
#define Create_CRadioButtonEx(caption, x, y, width, height, hMenu) CreateWindowEx(0, TEXT("button"), TEXT(caption), WS_CHILD| WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP,\
		x, y, width, height, hWnd, (HMENU)hMenu, g_hInst, NULL)
#define Create_RadioButtonEx(caption, x, y, width, height, hMenu) CreateWindowEx(0, TEXT("button"), TEXT(caption), WS_CHILD| WS_VISIBLE | BS_AUTORADIOBUTTON,\
		x, y, width, height, hWnd, (HMENU)hMenu, g_hInst, NULL)
#define Create_CheckBoxEx(caption, x, y, width, height, hMenu) CreateWindowEx(0, TEXT("button"), TEXT(caption), WS_CHILD| WS_VISIBLE | BS_CHECKBOX,\
		x, y, width, height, hWnd, (HMENU)hMenu, g_hInst, NULL)
#define Create_GroupBoxEx(caption, x, y, width, height, hMenu) CreateWindowEx(0, TEXT("button"), TEXT(caption), WS_CHILD| WS_VISIBLE | BS_GROUPBOX,\
		x, y, width, height, hWnd, (HMENU)hMenu, g_hInst, NULL)


#define HDC_ hdc = BeginPaint(hWnd, &ps);
#define _HDC EndPaint(hWnd, &ps);
#define GHDC_ hdc = GetDC(hWnd);
#define _GHDC ReleaseDC(hWnd, hdc);
#define Paint_Text(caption, x, y) TextOut(hdc, x, y, TEXT(caption), lstrlen(caption))
#define MsgBox(body, title, option) MessageBox(hWnd, body, title, option)
#define SetGroupBox(x, y) xs = x; ys = y
#define cx(x) x + xs
#define cy(y) y + ys

#define GetText( _hwnd_ , _lptstr_ )\
	_lptstr_ = new TCHAR[GetWindowTextLength(_hwnd_) + 1];\
	GetWindowText(_hwnd_, _lptstr_, GetWindowTextLength(_hwnd_) + 1)

#endif
/*
 *	The rollrat z_library
 *  Updated : 2013-06
 *	http://blog.naver.com/rollrat
 *  Copyright (c) 2009-2013 by rollrat. All right reserved.
 *  For more information, refer to the documentation on the license.
V0.1:0015****/

/*
 *	Special Library 'The Complex'
 *	Lastest Updated : 2013-06-15
 *	C/C++ syntax of the total complex made ​​possible by mobilizing header.
 *	If you understand all this, you C/C++ will have 
 *	completed all of the grammar.
L1_H*/

/*
 *	This item, is available free of charge. However, if you change 
 *	yourself, you can bring fatal consequences. This project is 
 *	based on the ethical issues of the information, and began to 
 *	improve the openness of the program. You can use anyone, but 
 *	please observe the clear copyright notice. When you beat this, 
 *	you can go into the legal action.
V0.1_z_Library_btype*/