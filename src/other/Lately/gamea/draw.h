#ifndef _DRAW_
#define _DRAW_

#include <Windows.h>

void DrawInit(HWND whWnd);
void DrawSetDC(HDC dc);
void DrawPixel(int x, int y, DWORD rgb);
void DrawPlainText(int x, int y, char *text, int thick);
void DrawLine(int x1, int y1, int x2, int y2);
void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3);
void DrawRect(int x, int y, int width, int height);

#endif