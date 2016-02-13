#include <tchar.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <Windows.h>
#include "hangul.h"
#include "bit_math.h"

#define TEXT(x)		L##x

int foo(int l, int r)
{
	int k, i;
	for (k = 0, i = 0; r; i++, r >>= 1)
		k += r & 1 ? l << i : 0;
	return k;
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

int getx()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.X;
}

void lineclear(int y)
{
	DWORD cCharsWritten;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordScreen = { 0, y };
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	dwConSize = csbi.dwSize.Y;
	FillConsoleOutputCharacter(hConsole, (TCHAR) ' ',
		dwConSize, coordScreen, &cCharsWritten);
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	FillConsoleOutputAttribute(hConsole, csbi.wAttributes,
		dwConSize, coordScreen, &cCharsWritten);
}

int main()
{
	char buffer[1000];
	wchar_t wbuffer[1000];
	wchar_t ff[1000];
	size_t PtNumberOfCharConverted;
	int ibuf = 0, x, g;
	_wsetlocale(LC_ALL, TEXT("korean"));
	for(;;)
	{
		if ((g=_getch()) == 8 && (x=getx())) {
			gotoxy(x-1, 0);
			putchar(' ');
			gotoxy(x-1, 0);
			if (ibuf > 0)
				ibuf--;
			//continue;
		} else {
			buffer[ibuf] = g;
			putchar(buffer[ibuf]);
		}
		buffer[ibuf+1] = 0;
		mbstowcs_s(&PtNumberOfCharConverted, wbuffer, strlen(buffer)+1, buffer, _TRUNCATE);
		hangul_assembly(wbuffer, ff);
		x = getx();
		gotoxy(0, 1);
		lineclear(1);
		wprintf(TEXT("%s"), ff);
		gotoxy(x, 0);
		ibuf++;
	}
}


int p_tmain()
{

	//printf("%d", foo(9, 5));

	wchar_t st[] = TEXT("����� �������� ��°�?");
	wchar_t ff[33];

	_wsetlocale(LC_ALL, TEXT("korean"));

	//hangul_assembly3(TEXT("nfyfzjgs ibjtqjgyv nfhgskfB"), ff);
	//wprintf(TEXT("%s\n"), ff);
	//
	//hangul_total_disassembly(st, ff);
	//wprintf(TEXT("%s\n"), ff);
	//
	//hangul_initial(st, ff);
	//wprintf(TEXT("%s\n"), ff);
	//
	//wprintf(TEXT("%d\n"), hangul_startswith_compare(TEXT("�����ٶ󸶹�� "), TEXT("����������")));

	wchar_t a = TEXT('��'), b = TEXT('��');

	hangul_expression_palatalization(&a, &b);
	wprintf(TEXT("������ȭ: ���� -> %c%c\n"), a, b);

	a = TEXT('Į'), b = TEXT('��');
	hangul_expression_liquidization(&a, &b);
	wprintf(TEXT("�� �� ȭ: Į�� -> %c%c\n"), a, b);

	wprintf(TEXT("�� �� ȭ: ���� -> %c%c\n"), hangul_expression_nasalization(TEXT('��'), TEXT('��')), TEXT('��'));

	wchar_t ts[] = TEXT("�����۶����D����");
	hangul_expression_syllable_of_jongseong_rules(ts);
	wprintf(TEXT("������ ���Ҹ� ��Ģ: �����۶����D���� -> %s"), ts);

	//int multiple_target = 3;
	//int result3;
	//int result5;
	//int result7;

	//// �� ��
	//result3 = (multiple_target << 1) + multiple_target;
	//// �ټ� ��
	//result5 = (multiple_target << 2) + multiple_target;
	//// �ϰ� ��
	//result7 = (multiple_target << 2) + multiple_target << 1;

	//printf("%d %d %d", result3, result5, result7);

//	uint8_t index, x;
//
//	/*scanf_s("%d",&x);
//
//	_BitScanLeft32(&index, x);
//
//	printf("%d	%d", index, ceil_log2(16));
//*/
//	printf("%lf", fast_sine_low(2));
//
	return 0;
}
