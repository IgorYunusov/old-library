#include <windows.h>
#include "zLib_WinApi.h"

WINENTRY("First");

HWND hWndProc;
HWND hEdit1, hEdit2;
HFONT fot;

int APIENTRY WinMain( WINMAIN_PARAMENT )
{
	WWINMAINXY( g_hInst, lpszClass, 840, 400 , 0);
}

LRESULT CALLBACK WndProc( WINPROC_PARAMENT )
{
	switch(iMessage) {
	case WM_CREATE:
		hWndProc = hWnd;
		
		hEdit2 = Create_EditsEx(60, 45, 750, 100, 0);
		hEdit1 = Create_EditEx(60, 20, 750, 20, 1);
		Create_ButtonEx("Show Message", 430, 170, 120, 20, 10);

		return 0;
	case WM_COMMAND:
		switch(LOWORD(wParam))
			case 10:{
				LPTSTR s;
				GetText(hEdit1, s);
				MessageBox(hWnd, s, s, MB_OKCANCEL);
			}
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_PAINT:
		return 0;
	}
	return(DefWindowProc(hWnd,iMessage,wParam,lParam));
}