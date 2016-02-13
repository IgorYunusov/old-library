#include <Windows.h>
#include "vector.h"

HINSTANCE g_hInst;
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam,LPARAM IParam);
LPCTSTR IpszClass = TEXT("API로 버튼 만들기");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpszCmdParam, int nCmdShow)
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

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	SetWindowPos(hWnd,0,100,200,200,400,SWP_NOSIZE);

	while(GetMessage(&Message,NULL,0,0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}

	return (int)Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam,LPARAM IParam)
{
	switch(iMsg)
	{
	case WM_CREATE:
		CreateWindow(TEXT("button"),TEXT("버튼"),
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			20, 20, 100, 25,
			hWnd, (HMENU)0, g_hInst , NULL);
		CreateWindow(TEXT("button"),TEXT("버튼"),
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			20, 50, 100, 25,
			hWnd, (HMENU)1, g_hInst , NULL);
		CreateWindow(TEXT("button"),TEXT("버튼"),
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			20, 80, 100, 25,
			hWnd, (HMENU)2, g_hInst , NULL);
		CreateWindow(TEXT("button"),TEXT("버튼"),
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			20, 110, 100, 25,
			hWnd, (HMENU)3, g_hInst , NULL);

		CreateWindow(TEXT("button"),TEXT("그룹박스 예제"),
			WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
			140, 20, 300, 110,
			hWnd, (HMENU)0, g_hInst , NULL);
		break;
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case 0:
			MessageBox(hWnd, TEXT("Click1 Clicked!"), TEXT("button"), MB_ICONINFORMATION | MB_OK);
			break;
		case 1:
			MessageBox(hWnd, TEXT("Click2 Clicked!"), TEXT("button"), MB_ICONINFORMATION | MB_OK);
			break;
		case 2:
			MessageBox(hWnd, TEXT("Click3 Clicked!"), TEXT("button"), MB_ICONINFORMATION | MB_OK);
			break;
		case 3:
			MessageBox(hWnd, TEXT("Click4 Clicked!"), TEXT("button"), MB_ICONINFORMATION | MB_OK);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd,iMsg,wParam,IParam));
}

