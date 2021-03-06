/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   main.c

Project:

   GameA

Compile Environment:

   Microsoft Visual Studio V12.0 C++
   MinGW Cross Compiler GCC

------
   AUTHOR: HyunJun Jeong  2015-01-19

***************************************************************************/

#include <Windows.h>
#include <math.h>
#include "draw.h"


/*************************************************************

	이 게임의 규칙과 프로그램 코드의 모든 저작권은
	인천고등학교 창의공학기술동아리-로봇부,프로그래밍부에 있으며
	저작권자 동의 없이 어떠한 부분도 
	무단전재, 복사, 배포, 재배포를 금지합니다.

*************************************************************/


/*============================================================

	기본 게임 규칙

	초기화: 
	1. 5x5의 격자무늬가 있는 정사각형과 각 꼭짓점에 대각으로
	뻗은 선이 그려진 구조로 설정한다.
	2. 노란색 공을 각 대각선 끝, 격자무늬에 맨 오른쪽 맨 위를
	비워둔 나머지 상하좌우로 만나지 않은 곳에 모두 놓는다.
	3. 회색공을 맨 오른쪽 맨 위, 맨 왼쪽 맨 아래에 두고,
	검은색 공을 맨 오른쪽 맨 아래, 맨 왼쪽 맨 위에다 둔다.

	승리조건:
	1. 회색공이 정사각형의 각 끝과, 그 끝과 이어진 대각선 끝에 각각
	존재하는 경우 회색공을 가진 플레이어가 게임에서 이긴다.
	2. 검은색공이 정사각형의 각 끝과, 그 끝과 이어진 대각선 끝에 각각
	존재하는 경우  검은색공을 가진 플레이어가 게임에서 이긴다.

	차례:
	각 플레이어가 공을 가지고 판에 정상적으로 놓을 시 현재 플레이어가
	아닌 플레이어에게 게임을 진행시킨다.

	공:
	1. 회색공을 가진 플레이어는 회색공과 노란색공을 이동시킬 수 있고,
	상대가 직전 차례에 노란색공을 선택한 경우 현재 플레이어는 직전
	상대가 선택한 노란색 공을 선택할 수 없다.
	2. 검은색공을 가진 플레이어는 검은색공과 노란색공을 이동시킬 수 있고,
	상대가 직전 차례에 노란색공을 선택한 겨웅 현재 플레이어는 직전
	상대가 선택한 노란색 공을 선택할 수 없다.
	3. 회색공, 검은색공, 노란색공은 상하좌우 중 하나가 비어있고,
	또한 그 비어있는 부분의 상하좌우중 하나가 비어있으면 그 곳으로
	공을 이동시킬 수 있으며, 공을 놓기 전까지 이 행동을 반복할 수 있다.
	4. 대각선과 연결된 부분에 선택한 공이 위치한 경우, 그 대각선 부분의
	공이 비어있는 경우에 한해 그곳으로 공을 이동시킬 수 있다.
	5. 상하좌우, 대각선 모두 막혀있는 경우 그 공은 선택할 수 없다.

============================================================*/

/**
 *	게임 기본 옵션 설정
 */

// 메세지 박스를 이용하여 상태를 출력합니다.
#define USING_MESSAGEBOX
// 공을 한 칸씩만 이동시킬 수 있습니다. ( 이 옵션은 기본 규칙이 아닙니다. )
#define USING_STEPONE

/**
 *	디버깅용 슈퍼바이저 모드
 */
#if (defined(_DEBUG) || defined(DEBUG))
// 공을 여러칸씩 이동시킬 수 있습니다.
#undef USING_STEPONE
// 노란 공이 초기화 되지 않습니다.
#define NOUSING_YELLOW
// 회색이 검은색을, 검은색이 회색을 조종할 수 있습니다.
#define NOSUPERVISOR_ANYOTHER
// 게임이 끝나도 공을 움직일 수 있습니다.
#define NOUSING_AFTEREND
// 노란 공을 그리기만 합니다.
#define ALLOW_DRAWONLY_YELLOW
// 모든 공을 중복할 수 있습니다.
#define USING_OVERLAP
// 회색, 검은색 공이 초기화 되지 않습니다.
#define NOUSING_PLAYER
// 회색, 검은색 공을 그리기만 합니다.
#define ALLOW_DRAWONLY_PLAYER
#endif

static HINSTANCE g_hInst;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LPCTSTR lpszClass = TEXT("GameA Released");

static void KeyDownLeft(HWND hWnd);
static void KeyDownRight(HWND hWnd);
static void KeyDownUp(HWND hWnd);
static void KeyDownDown(HWND hWnd);

static void KeyLockDownLeft(HWND hWnd);
static void KeyLockDownRight(HWND hWnd);
static void KeyLockDownUp(HWND hWnd);
static void KeyLockDownDown(HWND hWnd);
static BOOL KeyLockCountX();

static void DrawPanel();
static void DrawKeys(HDC hdc);
static void DrawNew(HWND hWnd);
static void DrawScopeRect(HDC hdc);

static void ErrorCheck(HWND hWnd);
static int IsNotExistKey();
static BOOL IsSelectOk();
static BOOL pureIsExist(int bx1, int by1);

/**
 * 격자를 그릴 위치
 */
#define STP1		150 // 원점부터 격자까지 떨어진 거리
#define STP2		600	// 정사각형의 한 변

/**
 * 일정한 길이를 가진 정사각형의 대각선
 */
#define DIL1		100

/**
 * 공의 크기
 */
#define BSZ1		25

/**
 *	Scope용 정사각형의 크기의 2배
 */
#define SCZ1		50


// 이미 공을 선택하여 더 이상 선택할 수 없습니다.
#define ERROR_ALREADYSELECT				1

// 이전에 선택되었던 노란 공 이므로 선택할 수 없습니다.
#define ERROR_PRESELECT					2

// 당신은 이 공을 선택할 권한이 없습니다.
#define ERROR_NOTALLOW					3

// 그 위치엔 공이 없어 선택할 수 없습니다.
#define ERROR_NOTEXIST					4

//// 선택된 공이 없음
#define INFO_DETACH						5

// 이 위치는 당신이 선택한 공의 위치이므로 여기다 놓을 수 없습니다.
#define ERROR_ALREADYSELECTTHESE		6

// 이 위치의 공은 선택할 수 없습니다.
#define ERROR_NOTALLOWPOS				7

/**
 *	위치 잠금
 */
#define LOCK_UP					1
#define LOCK_DOWN				2
#define LOCK_LEFT				4
#define LOCK_RIGHT				8

POINT yellowPt[16] = {
	//	Diagonal Side Block Point
	{STP1-DIL1,STP1-DIL1},
	{STP1-DIL1,STP1+STP2+DIL1},
	{STP1+STP2+DIL1,STP1-DIL1},
	{STP1+STP2+DIL1,STP1+STP2+DIL1},

	//	First Line Block Point
	{STP1,STP1+(STP2/4)*1},
	{STP1,STP1+(STP2/4)*3},

	//	Second Line Block Point
	{STP1+(STP2/4)*1,STP1},
	{STP1+(STP2/4)*1,STP1+(STP2/4)*2},
	{STP1+(STP2/4)*1,STP1+(STP2/4)*4},

	//	Third Line Block Point
	{STP1+(STP2/4)*2,STP1+(STP2/4)*1},
	{STP1+(STP2/4)*2,STP1+(STP2/4)*3},
	
	//	Fourth Line Block Point
	{STP1+(STP2/4)*3,STP1},
	{STP1+(STP2/4)*3,STP1+(STP2/4)*2},
	{STP1+(STP2/4)*3,STP1+(STP2/4)*4},

	//	Fifth Line Block Point
	{STP1+(STP2/4)*4,STP1+(STP2/4)*1},
	{STP1+(STP2/4)*4,STP1+(STP2/4)*3},
};
POINT grayPt[2] = {
	{STP1,STP1},
	{STP1+(STP2/4)*4,STP1+(STP2/4)*4},
};
POINT blackPt[2] = {
	{STP1,STP1+(STP2/4)*4},
	{STP1+(STP2/4)*4,STP1},
};

/**
 *	Scope Position (1~7)
 */
int bx = 0, by = 0;


/**
 *	Scope Position Map
 */
LONG scopePos[7] = {
	STP1-DIL1,
	STP1,
	STP1+(STP2/4)*1,
	STP1+(STP2/4)*2,
	STP1+(STP2/4)*3,
	STP1+(STP2/4)*4,
	STP1+(STP2/4)*4+DIL1,
};

/************************

	Pannel Preview

  Y                 Y
      G Y ○ Y  K  
      Y ○ Y ○ Y  
      ○ Y ○ Y ○  
      Y ○ Y ○ Y  
      K Y ○ Y  G  
  Y                 Y

  K: Black
  Y: Yellow
  G: Gray

************************/

int Turn;
int SelectWhat, SelectPos;
int PreSelectPos;
POINT *SelectedPt;
int ForceSetNo;
int gameEnd;

/**
 *	공이 선택되어있는 경우 일정한 위치에서만 움직일 수 있으므로 위치에
 *	락을 걸어 조정 해야함
 */
int posLock;
int posLockbx, posLockby;

static LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM IParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	int errnom;

	switch (iMsg)
	{
	case WM_CREATE:
		
		break;
	case WM_PAINT:
		DrawNew(hWnd);
		break;
	case WM_KEYDOWN:
#if !defined(NOUSING_AFTEREND)
		if (gameEnd == TRUE) {
			return 0;
		}
#endif
		switch(wParam) {
		case VK_LEFT:
			if (posLock == FALSE)
				KeyDownLeft(hWnd);
			else
				KeyLockDownLeft(hWnd);
			break;
		case VK_RIGHT:
			if(posLock == FALSE)
				KeyDownRight(hWnd);
			else
				KeyLockDownRight(hWnd);
			break;
		case VK_UP:
			if(posLock == FALSE)
				KeyDownUp(hWnd);
			else
				KeyLockDownUp(hWnd);
			break; 
		case VK_DOWN:
			if(posLock == FALSE)
				KeyDownDown(hWnd);
			else
				KeyLockDownDown(hWnd);
			break;
		case VK_SPACE:
			ErrorCheck(hWnd);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd, iMsg, wParam, IParam));
}

/////////////////////////////////////////////////////////
////
////	키보드 이벤트 ( if UnLock )
////
/////////////////////////////////////////////////////////

static void KeyDownLeft(HWND hWnd)
{
	if(bx == 1 && by == 1) {
		bx = by = 0;
		DrawNew(hWnd);
	} else if (bx == 6 && by == 0) {
		bx = 5, by = 1;
		DrawNew(hWnd);
	} else if (bx == 1 && by == 5) {
		bx = 0, by = 6;
		DrawNew(hWnd);
	} else if (bx == 6 && by == 6) {
		bx = by = 5;
		DrawNew(hWnd);
	} else if (bx > 1) {
		bx--;
		DrawNew(hWnd);
	}
}
static void KeyDownRight(HWND hWnd)
{
	if(bx == 0 && by == 0) {
		bx = by = 1;
		DrawNew(hWnd);
	} else if (bx == 5 && by == 1) {
		bx = 6, by = 0;
		DrawNew(hWnd);
	} else if (bx == 0 && by == 6) {
		bx = 1, by = 5;
		DrawNew(hWnd);
	} else if (bx == 5 && by == 5) {
		bx = by = 6;
		DrawNew(hWnd);
	} else if (bx < 5) {
		bx++;
		DrawNew(hWnd);
	}
}
static void KeyDownUp(HWND hWnd)
{
	if(bx == 1 && by == 1) {
		bx = by = 0;
		DrawNew(hWnd);
	} else if (bx == 5 && by == 1) {
		bx = 6, by = 0;
		DrawNew(hWnd);
	} else if (bx == 0 && by == 6) {
		bx = 1, by = 5;
		DrawNew(hWnd);
	} else if (bx == 6 && by == 6) {
		bx = by = 5;
		DrawNew(hWnd);
	} else if (by > 1) {
		by--;
		DrawNew(hWnd);
	}
}
static void KeyDownDown(HWND hWnd)
{
	if(bx == 0 && by == 0) {
		bx = by = 1;
		DrawNew(hWnd);
	} else if (bx == 6 && by == 0) {
		bx = 5, by = 1;
		DrawNew(hWnd);
	} else if (bx == 1 && by == 5) {
		bx = 0, by = 6;
		DrawNew(hWnd);
	} else if (bx == 5 && by == 5) {
		bx = by = 6;
		DrawNew(hWnd);
	} else if (by < 5) {
		by++;
		DrawNew(hWnd);
	}
}


/////////////////////////////////////////////////////////
////
////	그리기 함수 경계
////
/////////////////////////////////////////////////////////

/**
 *	공이 놓일 판을 그리는 함수
 */
static void DrawPanel()
{
	/**
	 * Draw Grid Function
	 */
	int i;
	DrawRect(STP1,STP1, STP2,STP2);
	for(i = 1; i <= 3; i++) {
		// Draw Check
		DrawLine(STP1, STP1+(STP2/4)*i, STP1+STP2, STP1+(STP2/4)*i);
		DrawLine(STP1+(STP2/4)*i, STP1, STP1+(STP2/4)*i, STP1+STP2);
	}
	// Draw Diagonal
	DrawLine(STP1,STP1,				STP1-DIL1,STP1-DIL1);	// A(STP1, STP1)
	DrawLine(STP1,STP1+STP2,		STP1-DIL1,STP1+STP2+DIL1);	// B(STP1, STP1+STP2)
	DrawLine(STP1+STP2,STP1,		STP1+STP2+DIL1,STP1-DIL1);	// C(STP1+STP2, STP1)
	DrawLine(STP1+STP2,STP1+STP2,	STP1+STP2+DIL1,STP1+STP2+DIL1);	// D(STP1+STP2, STP1+STP2)
}

/**
 *	모든 공을 그리는 함수
 */
static void DrawKeys(HDC hdc)
{
	HBRUSH hBrush, hOldBrush;
	int i;

#if !defined(NOUSING_YELLOW) || defined(ALLOW_DRAWONLY_YELLOW)
	// Draw Yellow
	hBrush = CreateSolidBrush(RGB(255, 255, 0));
	hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	for(i = 0; i < 16; i++) {
		Ellipse(hdc, yellowPt[i].x-BSZ1, yellowPt[i].y-BSZ1, 
			yellowPt[i].x+BSZ1, yellowPt[i].y+BSZ1);
	}
	DeleteObject(SelectObject(hdc, hOldBrush));
#endif

#if !defined(NOUSING_PLAYER) || defined(ALLOW_DRAWONLY_PLAYER)
	// Draw Gray
	hBrush = CreateSolidBrush(RGB(0x66,0x66,0x66));
	hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	for(i = 0; i < 2; i++) {
		Ellipse(hdc, grayPt[i].x-BSZ1, grayPt[i].y-BSZ1, 
			grayPt[i].x+BSZ1, grayPt[i].y+BSZ1);
	}
	DeleteObject(SelectObject(hdc, hOldBrush));

	// Draw Black
	hBrush = CreateSolidBrush(RGB(0,0,0));
	hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	for(i = 0; i < 2; i++) {
		Ellipse(hdc, blackPt[i].x-BSZ1, blackPt[i].y-BSZ1, 
			blackPt[i].x+BSZ1, blackPt[i].y+BSZ1);
	}
	DeleteObject(SelectObject(hdc, hOldBrush));
#endif
}

/**
 *	위치를 나타내는 정사각형을 그립니다
 */
static void DrawScopeRect(HDC hdc)
{
	if(Turn == 0) {	// Gray
		HPEN hPen, hOldPen;
		hPen = CreatePen(PS_SOLID,3,RGB(0x66,0x66,0x66));
		hOldPen = (HBRUSH)SelectObject(hdc, hPen);
		DrawRect(scopePos[bx] - SCZ1, scopePos[by] - SCZ1, SCZ1*2, SCZ1*2);
		DeleteObject(SelectObject(hdc, hOldPen));
	} else if (Turn == 1) { // black
		HPEN hPen, hOldPen;
		hPen = CreatePen(PS_SOLID,3,RGB(0,0,0));
		hOldPen = (HBRUSH)SelectObject(hdc, hPen);
		DrawRect(scopePos[bx] - SCZ1, scopePos[by] - SCZ1, SCZ1*2, SCZ1*2);
		DeleteObject(SelectObject(hdc, hOldPen));
	}
}

/**
 *	모든 영역을 초기화하고 다시그립니다
 */
static void DrawNew(HWND hWnd)
{
	RECT rt;
	HDC hdc;
	PAINTSTRUCT ps;

	SetRect(&rt, 0,0,STP1*3+STP2-DIL1+BSZ1, STP1*3+STP2-DIL1+BSZ1);
	InvalidateRect(hWnd,&rt,TRUE);

	DrawSetDC(hdc = BeginPaint(hWnd, &ps));
	DrawPanel();
	DrawScopeRect(hdc);
	DrawKeys(hdc);
	EndPaint(hWnd, &ps);
}

/////////////////////////////////////////////////////////
////
////	선택 함수 경계
////
/////////////////////////////////////////////////////////

/**
 *	공을 놓거나 떼는 사건에 관한 함수
 */
static void ErrorCheck(HWND hWnd)
{
#ifdef USING_MESSAGEBOX
	int errnom;
	if((errnom = IsNotExistKey()) == FALSE) {
		posLock = TRUE;
		posLockbx = bx;
		posLockby = by;
		MessageBox(hWnd, TEXT("공을 놓을 위치를 선택하십시오."), lpszClass, MB_OK | MB_ICONINFORMATION);
	} else if (errnom == INFO_DETACH && SelectWhat != 0) {
		Turn = !Turn;
		SelectedPt->x = scopePos[bx];
		SelectedPt->y = scopePos[by];
		SelectedPt = 0;
		SelectWhat = SelectPos = 0;
		posLock = FALSE;
		DrawNew(hWnd);
		if(IsWin() == TRUE) {
			if(Turn == 1) {
				MessageBox(hWnd, TEXT("Gray가 승리하였습니다."), lpszClass, MB_OK | MB_ICONINFORMATION);
				gameEnd = TRUE;
				return 0;
			} else if(Turn == 0) {
				MessageBox(hWnd, TEXT("Black이 승리하였습니다."), lpszClass, MB_OK | MB_ICONINFORMATION);
				gameEnd = TRUE;
				return 0;
			}
		}
		MessageBox(hWnd, TEXT("성공적으로 공을 이동시켰습니다."), lpszClass, MB_OK | MB_ICONINFORMATION);
	} else {
		switch (errnom) {
		case ERROR_ALREADYSELECT:
			MessageBox(hWnd, TEXT("이미 공을 선택하여 더 이상 선택할 수 없습니다."), lpszClass, MB_OK | MB_ICONERROR);
			break;
		case ERROR_PRESELECT:
			MessageBox(hWnd, TEXT("이전에 선택되었던 노란 공 이므로 선택할 수 없습니다."), lpszClass, MB_OK | MB_ICONERROR);
			break;
		case ERROR_NOTALLOW:
			MessageBox(hWnd, TEXT("당신은 이 공을 선택할 권한이 없습니다."), lpszClass, MB_OK | MB_ICONERROR);
			break;
		case ERROR_NOTEXIST:
			MessageBox(hWnd, TEXT("그 위치엔 공이 없어 선택할 수 없습니다."), lpszClass, MB_OK | MB_ICONERROR);
			break;
		case ERROR_ALREADYSELECTTHESE:
			MessageBox(hWnd, TEXT("이 위치는 당신이 선택한 공의 위치이므로 여기다 놓을 수 없습니다."), lpszClass, MB_OK | MB_ICONERROR);
			break;
		case ERROR_NOTALLOWPOS:
			MessageBox(hWnd, TEXT("이 위치의 공은 선택할 수 없습니다."), lpszClass, MB_OK | MB_ICONERROR);
			break;
		}
	}
#else
	int errnom;
	HDC hdc;
	if((errnom = IsNotExistKey()) == FALSE) {
		posLock = TRUE;
		posLockbx = bx;
		posLockby = by;
		hdc = GetDC(hWnd);
		DrawSetDC(hdc);
		DrawPlainText(100, 5, TEXT("공을 놓을 위치를 선택하십시오."), 1);
		ReleaseDC(hWnd, hdc);
	} else if (errnom == INFO_DETACH && SelectWhat != 0) {
		Turn = !Turn;
		SelectedPt->x = scopePos[bx];
		SelectedPt->y = scopePos[by];
		SelectedPt = 0;
		SelectWhat = SelectPos = 0;
		posLock = FALSE;
		DrawNew(hWnd);
		if(IsWin() == TRUE) {
			if(Turn == 1) {
				hdc = GetDC(hWnd);
				DrawSetDC(hdc);
				DrawPlainText(100, 5, TEXT("Gray가 승리하였습니다."), 1);
				ReleaseDC(hWnd, hdc);
				gameEnd = TRUE;
				return 0;
			} else if(Turn == 0) {
				hdc = GetDC(hWnd);
				DrawSetDC(hdc);
				DrawPlainText(100, 5, TEXT("Black이 승리하였습니다."), 1);
				ReleaseDC(hWnd, hdc);
				gameEnd = TRUE;
				return 0;
			}
		}
		hdc = GetDC(hWnd);
		DrawSetDC(hdc);
		DrawPlainText(100, 5, TEXT("성공적으로 공을 이동시켰습니다."), 1);
		ReleaseDC(hWnd, hdc);
	} else {
		switch (errnom) {
		case ERROR_ALREADYSELECT:
			hdc = GetDC(hWnd);
			DrawSetDC(hdc);
			DrawPlainText(100, 5, TEXT("이미 공을 선택하여 더 이상 선택할 수 없습니다."), 1);
			ReleaseDC(hWnd, hdc);
			break;
		case ERROR_PRESELECT:
			hdc = GetDC(hWnd);
			DrawSetDC(hdc);
			DrawPlainText(100, 5, TEXT("이전에 선택되었던 노란 공 이므로 선택할 수 없습니다."), 1);
			ReleaseDC(hWnd, hdc);
			break;
		case ERROR_NOTALLOW:
			hdc = GetDC(hWnd);
			DrawSetDC(hdc);
			DrawPlainText(100, 5, TEXT("당신은 이 공을 선택할 권한이 없습니다."), 1);
			ReleaseDC(hWnd, hdc);
			break;
		case ERROR_NOTEXIST:
			hdc = GetDC(hWnd);
			DrawSetDC(hdc);
			DrawPlainText(100, 5, TEXT("그 위치엔 공이 없어 선택할 수 없습니다."), 1);
			ReleaseDC(hWnd, hdc);
			break;
		case ERROR_ALREADYSELECTTHESE:
			hdc = GetDC(hWnd);
			DrawSetDC(hdc);
			DrawPlainText(100, 5, TEXT("이 위치는 당신이 선택한 공의 위치이므로 여기다 놓을 수 없습니다."), 1);
			ReleaseDC(hWnd, hdc);
			break;
		case ERROR_NOTALLOWPOS:
			hdc = GetDC(hWnd);
			DrawSetDC(hdc);
			DrawPlainText(100, 5, TEXT("이 위치의 공은 선택할 수 없습니다."), 1);
			ReleaseDC(hWnd, hdc);
			break;
		}

	}
#endif
}

/**
 *	현재 위치에 공이 있는 지의 여부와 그 공의 위치등을 기록하는 함수
 */
static int IsNotExistKey()
{
	int i;

	// 공을 놓으려는 경우를 체크
#if !defined(USING_OVERLAP)
	if (bx == posLockbx && by == posLockby && posLock == TRUE)
		return ERROR_ALREADYSELECTTHESE;
#endif
	if (SelectWhat != 0) {
#if !defined(USING_OVERLAP)
#if !defined(NOUSING_YELLOW)
		for(i = 0; i < 16; i++) {
			if(yellowPt[i].x == scopePos[bx] && yellowPt[i].y == scopePos[by]) {
				return ERROR_ALREADYSELECT;
			}
		}
#endif
		for(i = 0; i < 2; i++) {
			if(grayPt[i].x == scopePos[bx] && grayPt[i].y == scopePos[by]) {
				return ERROR_ALREADYSELECT;
			}
		}
		for(i = 0; i < 2; i++) {
			if(blackPt[i].x == scopePos[bx] && blackPt[i].y == scopePos[by]) {
				return ERROR_ALREADYSELECT;
			}
		}
#endif
		return INFO_DETACH;
	}
	
#if !defined(NOUSING_YELLOW)
	for(i = 0; i < 16; i++) {
		if(yellowPt[i].x == scopePos[bx] && yellowPt[i].y == scopePos[by]) {
			if(PreSelectPos != i) {
				if (IsSelectOk() == FALSE)
					return ERROR_NOTALLOWPOS;
				if(ForceSetNo == FALSE) {
					SelectedPt = &yellowPt[i];
					SelectWhat = 1;
					PreSelectPos = SelectPos = i;
				}
				return FALSE;
			} else {
				return ERROR_PRESELECT;
			}
		}
	}
#endif
#if !defined(NOUSING_PLAYER)
	for(i = 0; i < 2; i++) {
		if(grayPt[i].x == scopePos[bx] && grayPt[i].y == scopePos[by]) {
			PreSelectPos = 17;
#if !defined(NOSUPERVISOR_ANYOTHER)
			if (Turn == 0) {
#endif
				if (IsSelectOk() == FALSE)
					return ERROR_NOTALLOWPOS;
				if(ForceSetNo == FALSE) {
					SelectedPt = &grayPt[i];
					SelectWhat = 2;
					SelectPos = i;
				}
				return FALSE;
#if !defined(NOSUPERVISOR_ANYOTHER)
			} else {
				return ERROR_NOTALLOW;
			}
#endif
		}
	}
	for(i = 0; i < 2; i++) {
		if(blackPt[i].x == scopePos[bx] && blackPt[i].y == scopePos[by]) {
			PreSelectPos = 17;
#if !defined(NOSUPERVISOR_ANYOTHER)
			if (Turn == 1) {
#endif
				if (IsSelectOk() == FALSE)
					return ERROR_NOTALLOWPOS;
				if(ForceSetNo == FALSE) {
					SelectedPt = &blackPt[i];
					SelectWhat = 3;
					SelectPos = i;
				}
				return FALSE;
#if !defined(NOSUPERVISOR_ANYOTHER)
			} else {
				return ERROR_NOTALLOW;
			}
#endif
		}
	}
#endif
	return ERROR_NOTEXIST;
}


/////////////////////////////////////////////////////////
////
////	키보드 이벤트 ( if Locked )
////
/////////////////////////////////////////////////////////

static void KeyLockDownLeft(HWND hWnd)
{
	int SelectWhatTmp = SelectWhat;
	int tmp;
	int bx1 = bx, by1 = by;
	
	if (KeyLockCountX() & LOCK_LEFT)
		return 0;

	if(bx == 1 && by == 1) {
		bx = by = 0;
	} else if (bx == 6 && by == 0) {
		bx = 5, by = 1;
	} else if (bx == 1 && by == 5) {
		bx = 0, by = 6;
	} else if (bx == 6 && by == 6) {
		bx = by = 5;
	} else if (bx > 1) {
		bx--;
	}

#if !defined(USING_OVERLAP)
	SelectWhat = 0;
	ForceSetNo = TRUE;
	tmp = IsNotExistKey();
	if(tmp == ERROR_NOTEXIST || tmp == ERROR_ALREADYSELECTTHESE) {
#endif
		DrawNew(hWnd);
#if !defined(USING_OVERLAP)
	} else {
		bx = bx1;
		by = by1;
	}
	ForceSetNo = FALSE;
	SelectWhat = SelectWhatTmp;
#endif
}

static void KeyLockDownRight(HWND hWnd)
{
	int SelectWhatTmp = SelectWhat;
	int tmp;
	int bx1 = bx, by1 = by;
	
	if (KeyLockCountX() & LOCK_RIGHT)
		return 0;

	if(bx == 0 && by == 0) {
		bx = by = 1;
	} else if (bx == 5 && by == 1) {
		bx = 6, by = 0;
	} else if (bx == 0 && by == 6) {
		bx = 1, by = 5;
	} else if (bx == 5 && by == 5) {
		bx = by = 6;
	} else if (bx < 5) {
		bx++;
	}
	
#if !defined(USING_OVERLAP)
	SelectWhat = 0;
	ForceSetNo = TRUE;
	tmp = IsNotExistKey();
	if(tmp == ERROR_NOTEXIST || tmp == ERROR_ALREADYSELECTTHESE) {
#endif
		DrawNew(hWnd);
#if !defined(USING_OVERLAP)
	} else {
		bx = bx1;
		by = by1;
	}
	ForceSetNo = FALSE;
	SelectWhat = SelectWhatTmp;
#endif
}

static void KeyLockDownUp(HWND hWnd)
{
	int SelectWhatTmp = SelectWhat;
	int tmp;
	int bx1 = bx, by1 = by;
	
	if (KeyLockCountX() & LOCK_UP)
		return 0;

	if(bx == 1 && by == 1) {
		bx = by = 0;
	} else if (bx == 5 && by == 1) {
		bx = 6, by = 0;
	} else if (bx == 0 && by == 6) {
		bx = 1, by = 5;
	} else if (bx == 6 && by == 6) {
		bx = by = 5;
	} else if (by > 1) {
		by--;
	}
	
#if !defined(USING_OVERLAP)
	SelectWhat = 0;
	ForceSetNo = TRUE;
	tmp = IsNotExistKey();
	if(tmp == ERROR_NOTEXIST || tmp == ERROR_ALREADYSELECTTHESE) {
#endif
		DrawNew(hWnd);
#if !defined(USING_OVERLAP)
	} else {
		bx = bx1;
		by = by1;
	}
	ForceSetNo = FALSE;
	SelectWhat = SelectWhatTmp;
#endif
}

static void KeyLockDownDown(HWND hWnd)
{
	int SelectWhatTmp = SelectWhat;
	int tmp;
	int bx1 = bx, by1 = by;

	if (KeyLockCountX() & LOCK_DOWN)
		return 0;

	if(bx == 0 && by == 0) {
		bx = by = 1;
	} else if (bx == 6 && by == 0) {
		bx = 5, by = 1;
	} else if (bx == 1 && by == 5) {
		bx = 0, by = 6;
	} else if (bx == 5 && by == 5) {
		bx = by = 6;
	} else if (by < 5) {
		by++;
	}
	
#if !defined(USING_OVERLAP)
	SelectWhat = 0;
	ForceSetNo = TRUE;
	tmp = IsNotExistKey();
	if(tmp == ERROR_NOTEXIST || tmp == ERROR_ALREADYSELECTTHESE) {
#endif
		DrawNew(hWnd);
#if !defined(USING_OVERLAP)
	} else {
		bx = bx1;
		by = by1;
	}
	ForceSetNo = FALSE;
	SelectWhat = SelectWhatTmp;
#endif
}

/**
 *	한 칸씩만 이동가능하도록 설정합니다.
 */
static BOOL KeyLockCountX()
{
#ifdef USING_STEPONE
	if(posLockbx == bx && posLockby == by)
		return FALSE;
	if (posLockbx - 1 == bx && posLockby == by)
		return LOCK_RIGHT ^ 0xf;
	else if (posLockbx + 1 == bx && posLockby == by)
		return LOCK_LEFT ^ 0xf;
	else if (posLockbx == bx && posLockby - 1 == by)
		return LOCK_DOWN ^ 0xf;
	else if (posLockbx == bx && posLockby + 1 == by)
		return LOCK_UP ^ 0xf;
#endif
	return FALSE;	// 이동가능
}

/**
 *	현재 위치로부터 4방을 검사하여 조사합니다.
 */
static BOOL IsSelectOk()
{
	// 대각선일 경우
	if(bx == 0 || by == 0 || bx == 6 || by == 6) {
		if (bx == 0 && by == 0) {
			if (pureIsExist(1, 1) == FALSE)
				return TRUE;
		} else if (bx == 0 && by == 6) {
			if (pureIsExist(1, 5) == FALSE)
				return TRUE;
		} else if (bx == 6 && by == 0) {
			if (pureIsExist(5, 1) == FALSE)
				return TRUE;
		} else if (bx == 6 && by == 6) {
			if (pureIsExist(5, 5) == FALSE)
				return TRUE;
		}
		return FALSE;
	}

	// 모서리일 경우
	if (bx == 1 && by == 1) {
		if (pureIsExist(0, 0) == FALSE)
			return TRUE;
		else if (pureIsExist(bx, by+1) == FALSE) // 아래
			return TRUE;
		else if (pureIsExist(bx+1, by) == FALSE) // 오른쪽
			return TRUE;
		return FALSE;
	} else if (bx == 1 && by == 5) {
		if (pureIsExist(0, 6) == FALSE)
			return TRUE;
		else if (pureIsExist(bx, by-1) == FALSE) // 위
			return TRUE;
		else if (pureIsExist(bx+1, by) == FALSE) // 오른쪽
			return TRUE;
		return FALSE;
	} else if (bx == 5 && by == 1) {
		if (pureIsExist(6, 0) == FALSE)
			return TRUE;
		else if (pureIsExist(bx, by+1) == FALSE) // 아래
			return TRUE;
		else if (pureIsExist(bx-1, by) == FALSE) // 왼쪽
			return TRUE;
		return FALSE;
	} else if (bx == 5 && by == 5) {
		if (pureIsExist(6, 6) == FALSE)
			return TRUE;
		else if (pureIsExist(bx, by-1) == FALSE) // 위
			return TRUE;
		else if (pureIsExist(bx-1, by) == FALSE) // 왼쪽
			return TRUE;
		return FALSE;
	}

	// 정사각형의 테두리일 경우
	if(bx == 1 && by != 1 && by != 5) {
		if (pureIsExist(bx, by-1) == FALSE) // 위
			return TRUE;
		else if (pureIsExist(bx, by+1) == FALSE) // 아래
			return TRUE;
		else if (pureIsExist(bx+1, by) == FALSE) // 오른쪽
			return TRUE;
		return FALSE;
	} else if (bx == 5 && by != 1 && by != 5) {
		if (pureIsExist(bx, by-1) == FALSE) // 위
			return TRUE;
		else if (pureIsExist(bx, by+1) == FALSE) // 아래
			return TRUE;
		else if (pureIsExist(bx+1, by) == FALSE) // 오른쪽
			return TRUE;
		return FALSE;
	} else if (by == 1 && bx != 1 && bx != 5) {
		if (pureIsExist(bx, by+1) == FALSE) // 아래
			return TRUE;
		else if (pureIsExist(bx+1, by) == FALSE) // 오른쪽
			return TRUE;
		else if (pureIsExist(bx-1, by) == FALSE) // 왼쪽
			return TRUE;
		return FALSE;
	} else if (by == 5 && bx != 1 && bx != 5) {
		if (pureIsExist(bx, by-1) == FALSE) // 위
			return TRUE;
		else if (pureIsExist(bx+1, by) == FALSE) // 오른쪽
			return TRUE;
		else if (pureIsExist(bx-1, by) == FALSE) // 왼쪽
			return TRUE;
		return FALSE;
	}

	// 모서리 쪽이 아닐 경우
	if (pureIsExist(bx, by-1) == FALSE) // 위
		return TRUE;
	else if (pureIsExist(bx, by+1) == FALSE) // 아래
		return TRUE;
	else if (pureIsExist(bx+1, by) == FALSE) // 오른쪽
		return TRUE;
	else if (pureIsExist(bx-1, by) == FALSE) // 왼쪽
		return TRUE;
	return FALSE;
}

/**
 *	해당위치에 공이 있는 지의 여부를 가져옮
 */
static BOOL pureIsExist(int bx1, int by1)
{
	int i;

	// 기반 검사
	// IsSelectOk의 예외를 처리하기 위한 부분입니다.
	if (bx1 < 0 || by1 < 0 || bx1 > 6 || by1 > 6)
		return TRUE;
	
#if !defined(NOUSING_YELLOW)
	for(i = 0; i < 16; i++) {
		if(yellowPt[i].x == scopePos[bx1] && yellowPt[i].y == scopePos[by1]) {
			return TRUE;
		}
	}
#endif
#if !defined(NOUSING_PLAYER)
	for(i = 0; i < 2; i++) {
		if(grayPt[i].x == scopePos[bx1] && grayPt[i].y == scopePos[by1]) {
			return TRUE;
		}
	}
	for(i = 0; i < 2; i++) {
		if(blackPt[i].x == scopePos[bx1] && blackPt[i].y == scopePos[by1]) {
			return TRUE;
		}
	}
#endif
	return FALSE;
}

/////////////////////////////////////////////////////////
////
////	성공 조건
////
/////////////////////////////////////////////////////////

/**
 *	x, y값을 이용하여 bx, by용 위치를 가져옵니다
 */
static int scopePosInverse(LONG what)
{
	int i;
	for (i = 0; i < 7; i++)
		if (scopePos[i] == what)
			return i;
	return -1;	// 정상 작동시 이 부분은 스킵되어야함
}

/**
 *	성공 여부를 가져옵니다
 */
static BOOL IsWin()
{
	int gpt0x = scopePosInverse( grayPt[0].x),
		gpt0y = scopePosInverse( grayPt[0].y), 
		gpt1x = scopePosInverse( grayPt[1].x), 
		gpt1y = scopePosInverse( grayPt[1].y),
		kpt0x = scopePosInverse(blackPt[0].x),
		kpt0y = scopePosInverse(blackPt[0].y),
		kpt1x = scopePosInverse(blackPt[1].x), 
		kpt1y = scopePosInverse(blackPt[1].y);
	if (gpt0x == 0 && gpt0y == 0) {
		if (gpt1x == 1 && gpt1y== 1)
			return TRUE;
	} else if (gpt1x == 0 && gpt1y== 0) {
		if (gpt0x == 1 && gpt0y == 1)
			return TRUE;
	} else if (gpt0x == 0 && gpt0y == 6) {
		if (gpt1x == 1 && gpt1y== 5)
			return TRUE;
	} else if (gpt1x == 0 && gpt1y== 6) {
		if (gpt0x == 1 && gpt0y == 5)
			return TRUE;
	} else if (gpt0x == 6 && gpt0y == 0) {
		if (gpt1x == 5 && gpt1y== 1)
			return TRUE;
	} else if (gpt1x == 6 && gpt1y== 0) {
		if (gpt0x == 5 && gpt0y == 1)
			return TRUE;
	} else if (gpt0x == 6 && gpt0y == 6) {
		if (gpt1x == 5 && gpt1y== 5)
			return TRUE;
	} else if (gpt1x == 6 && gpt1y== 6) {
		if (gpt0x == 5 && gpt0y == 5)
			return TRUE;
	} else if (kpt0x == 0 && kpt0y == 0) {
		if (kpt1x == 1 && kpt1y== 1)
			return TRUE;
	} else if (kpt1x == 0 && kpt1y== 0) {
		if (kpt0x == 1 && kpt0y == 1)
			return TRUE;
	} else if (kpt0x == 0 && kpt0y == 6) {
		if (kpt1x == 1 && kpt1y== 5)
			return TRUE;
	} else if (kpt1x == 0 && kpt1y== 6) {
		if (kpt0x == 1 && kpt0y == 5)
			return TRUE;
	} else if (kpt0x == 6 && kpt0y == 0) {
		if (kpt1x == 5 && kpt1y== 1)
			return TRUE;
	} else if (kpt1x == 6 && kpt1y== 0) {
		if (kpt0x == 5 && kpt0y == 1)
			return TRUE;
	} else if (kpt0x == 6 && kpt0y == 6) {
		if (kpt1x == 5 && kpt1y== 5)
			return TRUE;
	} else if (kpt1x == 6 && kpt1y== 6) {
		if (kpt0x == 5 && kpt0y == 5)
			return TRUE;
	}
	return FALSE;
}

/////////////////////////////////////////////////////////
////
////	진입점 (DX Style)
////
/////////////////////////////////////////////////////////
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASSEX WndClass = { sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW, WndProc, 0, 0, hInstance,
		LoadIcon(NULL, IDC_ARROW), LoadCursor(NULL, IDC_ARROW),
		(HBRUSH)(COLOR_BTNFACE + 1),
		NULL, lpszClass };

	if(FindWindow(NULL, lpszClass)) {
		MessageBox(HWND_DESKTOP, TEXT("Program is already running."), lpszClass, MB_OK | MB_ICONERROR);
		return 0;
	}

	g_hInst = hInstance;

	RegisterClassEx((LPWNDCLASSEX)&WndClass);

	hWnd = CreateWindowEx(0, lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, STP1*3+STP2-DIL1+BSZ1/2, STP1*3+STP2-DIL1+BSZ1/2,
		NULL, (HMENU)NULL, hInstance, NULL);
	////
	DrawInit(hWnd);
	bx = by = 1;
	Turn = 0;
	SelectWhat = SelectPos = 0;
	PreSelectPos = 17;
	posLock = posLockbx = posLockby = 0;
	ForceSetNo = FALSE;
	gameEnd = FALSE;
	////
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&Message, NULL, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}

	return (int)Message.wParam;
}