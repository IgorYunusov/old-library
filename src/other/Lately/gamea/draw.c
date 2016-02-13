#include <Windows.h>

#define COLOR_BALANCE(b, f) ((WORD)((((b) << (4)) & ( 0xF0)) | ((f) & (0x0F))))

static HWND hWnd;
static HDC hdc;

void DrawInit(HWND whWnd)
{
	hWnd = whWnd;
}

void DrawSetDC(HDC dc)
{
	hdc = dc;
}

void DrawPixel(int x, int y, DWORD rgb)
{
	SetPixel(hdc, x, y, rgb);
}

void DrawPlainText(int x, int y, LPCSTR text, int thick)
{
	TextOut(hdc, x, y, text, strlen(text));
}

void DrawLine(int x1, int y1, int x2, int y2)
{
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
}

void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
	MoveToEx(hdc, x2, y2, NULL);
	LineTo(hdc, x3, y3);
	MoveToEx(hdc, x3, y3, NULL);
	LineTo(hdc, x1, y1);
}

void DrawRect(int x, int y, int width, int height)
{
	MoveToEx(hdc, x, y, NULL);
	LineTo(hdc, x, y+height);
	LineTo(hdc, x+width, y+height);
	MoveToEx(hdc, x, y, NULL);
	LineTo(hdc, x+width, y);
	LineTo(hdc, x+width, y+height);
	//Rectangle(hdc, x, y, width, height);
}