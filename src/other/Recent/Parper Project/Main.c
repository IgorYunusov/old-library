/*************************************************************************

   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:

   main.c

Project:

   Paper Project

------
   AUTHOR: HyunJun Jeong  2015-04-25

***************************************************************************/

#define UNICODE

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <math.h>
#include <conio.h>
#include <direct.h>
#include <shlobj.h>
#include <tchar.h>
#include <locale.h>
#include "algorithm.h"

#define _T(x)		L##x

// 이 값은 배열의 총 개수 값임
static int SIZE_OF_ARRAY;

// 중복된 난수를 추출하는 경우 설정하는 구간
static int RAND_MIN;
static int RAND_SECTION;
static int selected_array_g;

int *array_direct;
int *array_reverse;
int *array_random;
int *array_overlap;

// 정교한 시간측정
LARGE_INTEGER freq, start, finish;

// 부울변수
typedef int			bool;

#define	TRUE		1
#define FALSE		0

#define not			!

bool array_contains(int array[], int data, int until);
void init_array();
void timer_start();
void timer_finish();
long double timer_getns();
void fast_cls();
WCHAR *commasput(int what);
void report_auto();

WCHAR *sort_name[] = {
	_T("선택"), _T("삽입"), _T("거품"), _T("쉘"), _T("퀵"), _T("퀵(비재귀)"), _T("퀵(랜덤)"),
	_T("퀵(부분)"), _T("퀵(가운데)"), _T("기수"), _T("버킷"), _T("힙"), _T("병합") };
WCHAR *array_name[] = {
	_T("순배열"), _T("역순배열"), _T("중복없는 임의배열"), _T("중복있는 임의배열") };
char *array_name_s[] = {
	"pure", "reverse", "non-overlap", "overlap" };

maina()
{
	int i = 0;
	int *task_array;
	int selected_sort = 1, selected_array = 1, selected_size = 1, size_of_array = 0,
		rand_min = 0, rand_max = 100;
	int command;
	int *array_selected = 0;
	bool recalled = FALSE;
	long double *ld_array, sum, variance, avg;

	setlocale(LC_ALL, "Korean");

	{
		printf("\t정렬 알고리즘 정밀 측정기\n\n");
	RE_COLE1:
		printf("\t알고리즘 선택\n\t1. 선택\t\t2. 삽입\t3. 거품\t4. 쉘\t5. 퀵\t6. 퀵(비재귀)\n\t7. 퀵(랜덤)\t8. 퀵(부분)\t9. 퀵(가운데)\n"
			"\t10. 기수\t11. 버킷\t12. 힙\t13. 병합\n\t14. 자동생성\n선택 : ");
		scanf_s("%d", &selected_sort);
		if (selected_sort < 1 || selected_sort > 14) {
			printf("다시 선택하세요.\n");
			goto RE_COLE1;
		}
		else if (selected_sort == 14) {
			printf("\n\t오류가 심한 버킷알고리즘은 제외하고 생성합니다.\n\t시작하려면 아무키나 눌러주세요...");
			_getch();
			printf("\n");
			report_auto();
		}
		if (recalled)
			goto RECALLED;

	RE_COLE2:
		printf("\n\t배열 선택\n\t1. 순배열\t2. 역순배열\t3. 중복없는 임의배열\n\t4. 중복있는 임의배열\n선택 : ");
		scanf_s("%d", &selected_array);
		if (selected_array < 1 || selected_array > 4) {
			printf("다시 선택하세요.\n");
			goto RE_COLE2;
		}
		if (selected_array > 2) {
		RE_SET1:
			printf("랜덤최소 숫자 : ");
			scanf_s("%d", &rand_min);
			printf("랜덤최고 숫자 : ");
			scanf_s("%d", &rand_max);
			if (rand_min >= rand_max || rand_min < 0) {
				printf("다시 맞춰라\n");
				goto RE_SET1;
			}
		}
		if (recalled)
			goto RECALLED;

	RE_COLE3:
		printf("\n\t배열 크기 선택\n\t1. 10\t2. 100\t3. 1,000\t4. 10,000\t5. 100,000\n\t6. 1,000,000\t7. 직접입력\n선택 : ");
		scanf_s("%d", &selected_size);
		if (selected_size < 1 || selected_size > 7) {
			printf("다시 선택하세요.\n");
			goto RE_COLE3;
		}
		if (selected_size == 7) {
			printf("횟수 입력 : ");
			scanf_s("%d", &size_of_array);
		}
		else
			size_of_array = pow(10, selected_size);
		if (recalled)
			goto RECALLED;
	}

	recalled = TRUE;

	{
	RECALLED:
		fast_cls();
		while (TRUE) {
			wprintf(L"\t선택된 알고리즘: %s\n\t선택된 배    열: %s\n\t선택된 배열크기: %s\n",
				sort_name[selected_sort - 1], array_name[selected_array - 1], commasput(size_of_array));
			if (selected_array > 2) {
				printf("\t숫  자 범    위: %d  ~  %d", rand_min, rand_max);
			}
			printf("\n\n");
			printf("\t1. 알고리즘변경\t\t2. 배열변경\t3. 크기변경");
			if (selected_array > 2) {
				printf("\t4. 범위변경\n\t5. 실험시작");
			}
			else printf("\t4. 실험시작");
			printf("\n>> ");
			scanf_s("%d", &command);
			if (selected_array > 2 && command == 4)
				goto RE_SET1;
			else if (command == 1)
				goto RE_COLE1;
			else if (command == 2)
				goto RE_COLE2;
			else if (command == 3)
				goto RE_COLE3;
			else if (command == 4 || (selected_array > 2 && command == 5))
			{
				RAND_MIN = rand_min;
				RAND_SECTION = rand_max - rand_min + 1;
				SIZE_OF_ARRAY = size_of_array;
				array_direct = (int *)malloc(sizeof(int)*size_of_array);
				array_reverse = (int *)malloc(sizeof(int)*size_of_array);
				array_random = (int *)malloc(sizeof(int)*size_of_array);
				array_overlap = (int *)malloc(sizeof(int)*size_of_array);
				fast_cls();
				printf("진행횟수? ");
				scanf_s("%d", &command);
				fast_cls();
				selected_array_g = selected_array;
				task_array = (int *)malloc(sizeof(int) * SIZE_OF_ARRAY);

				ld_array = (long double *)malloc(sizeof(long double) * command);

				for (i = 0; i < command; i++) {
					init_array();
					if (selected_array == 1)
						array_selected = array_direct;
					else if (selected_array == 2)
						array_selected = array_reverse;
					else if (selected_array == 3)
						array_selected = array_random;
					else if (selected_array == 4)
						array_selected = array_overlap;
					switch (selected_sort) {
					case 1: timer_start();  sort_selection	(array_selected, SIZE_OF_ARRAY); timer_finish(); break;
					case 2: timer_start();  sort_insertion	(array_selected, SIZE_OF_ARRAY); timer_finish(); break;
					case 3: timer_start();  sort_bubble		(array_selected, SIZE_OF_ARRAY); timer_finish(); break;
					case 4: timer_start();  sort_shell		(array_selected, SIZE_OF_ARRAY); timer_finish(); break;
					case 5: timer_start();  sort_quick0		(array_selected, SIZE_OF_ARRAY); timer_finish(); break;
					case 6: timer_start();  sort_quick1		(array_selected, SIZE_OF_ARRAY); timer_finish(); break;
					case 7: timer_start();  sort_quick2		(array_selected, SIZE_OF_ARRAY); timer_finish(); break;
					case 8: timer_start();  sort_quick3		(array_selected, SIZE_OF_ARRAY); timer_finish(); break;
					case 9: timer_start();  sort_quick4		(array_selected, SIZE_OF_ARRAY); timer_finish(); break;
					case 10: timer_start(); radix_sort		(array_selected, SIZE_OF_ARRAY); timer_finish(); break;
					case 11: timer_start(); sort_bucket		(array_selected, SIZE_OF_ARRAY, task_array); timer_finish(); break;
					case 12: timer_start(); sort_heap		(array_selected, SIZE_OF_ARRAY); timer_finish(); break;
					case 13: timer_start(); sort_merge		(array_selected, SIZE_OF_ARRAY, task_array); timer_finish(); break;
					}
					ld_array[i] = timer_getns();
				}

				free(task_array);

				printf("\n\n--------------실험 결과--------------\n");
				sum = 0.0f;
				for (i = 0; i < command; i++) {
					printf("%.12lf ns\n", ld_array[i]);
					sum += ld_array[i];
				}
				avg = sum / command;
				variance = 0.0f;
				for (i = 0; i < command; i++) {
					variance += pow(ld_array[i] - avg, 2);
				}
				variance /= command;
				printf("-------------------------------------\n");
				printf("합계 : %.12lf ns\n평균 : %.12lf ns\n분산 : %.12lf\t표준편차 : %.12lf\n\n", sum, avg, variance, sqrt(variance));
				getchar();
			}
			else
				printf("없는 명령입니다.");
		}
	}
	return 0;
}


/***
	array_contains:
	배열에 해당 요소가 포함되어있는지 검사합니다.

	argument: array: 배열이름
	data : 해당 요소
	until: 최대 검색 수치
	***/
bool array_contains(int array[], int data, int until)
{
	int i;
	for (i = 0; i <= until; i++)
		if (array[i] == data)
			return TRUE;
	return FALSE;
}


/***
	init_array:
	배열변수를 초기화합니다.
	***/
void init_array()
{
	int i;
	time_t current_stamp = time(NULL);	// 현재시간

	//	랜덤머신 초기화
	srand((unsigned int)current_stamp);

	if (selected_array_g == 1)
		for (i = 0; i < SIZE_OF_ARRAY; i++)
			array_direct[i] = i + 1;
	if (selected_array_g == 2)
		for (i = 0; i < SIZE_OF_ARRAY; i++)
			array_reverse[i] = SIZE_OF_ARRAY - i;
	if (selected_array_g == 3)
		for (i = 0; i < SIZE_OF_ARRAY; i++) {
			while (TRUE) {
				int rand_insidescope = rand() % (SIZE_OF_ARRAY + 1);
				if (not array_contains(array_random, rand_insidescope, i)) {
					array_random[i] = rand_insidescope;
					break;
				}
			}
		}
	if (selected_array_g == 4)
		for (i = 0; i < SIZE_OF_ARRAY; i++)
			array_overlap[i] = rand() % RAND_SECTION + RAND_MIN;
}

void timer_start()
{
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&start);
}

void timer_finish()
{
	QueryPerformanceCounter(&finish);
}

long double timer_getns()
{
	return (long double)((long double)(finish.QuadPart - start.QuadPart) 
		* 1000000 / (long double)(freq.QuadPart));
}

// 화면지우기
void fast_cls()
{ // http://support.microsoft.com/kb/99261/ko
	COORD coordScreen = { 0, 0 };    /* here's where we'll home the
										cursor */
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	bool bSuccess;
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */
	DWORD dwConSize;                 /* number of character cells in
										the current buffer */

	/* get the number of character cells in the current buffer */
	bSuccess = GetConsoleScreenBufferInfo(hConsole, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	/* fill the entire screen with blanks */
	bSuccess = FillConsoleOutputCharacter(hConsole, (TCHAR) ' ',
		dwConSize, coordScreen, &cCharsWritten);
	/* get the current text attribute */
	bSuccess = GetConsoleScreenBufferInfo(hConsole, &csbi);
	/* now set the buffer's attributes accordingly */
	bSuccess = FillConsoleOutputAttribute(hConsole, csbi.wAttributes,
		dwConSize, coordScreen, &cCharsWritten);
	/* put the cursor at (0, 0) */
	bSuccess = SetConsoleCursorPosition(hConsole, coordScreen);
	return;
}

WCHAR *commasput(int what)
{
	WCHAR *ret = (WCHAR *)malloc(sizeof(WCHAR) * 21);
	int i, j;
	for (i = 0, j = 0; what; what /= 10, i++, j++) {
		if (j % 3 == 0 && j)
			ret[i++] = _T(',');
		ret[i] = what % 10 + _T('0');
	}
	ret[i] = 0;
	return _wcsrev(ret);
}


void create_array_data()
{
	char appData[MAX_PATH];
	FILE *fp;
	int  array, count, i, l;
	int size_of_array = 0;
	int *array_selected = 0;
	
	RAND_MIN = 0;
	RAND_SECTION = 10000000 - 0 + 1;

	for (array = 0; array < 4; array++)
	{
		for (count = 1; count < 2; count++)
		{
			size_of_array = pow(10, count);
			
			array_direct = (int *)malloc(sizeof(int)*size_of_array);
			array_reverse = (int *)malloc(sizeof(int)*size_of_array);
			array_random = (int *)malloc(sizeof(int)*size_of_array);
			array_overlap = (int *)malloc(sizeof(int)*size_of_array);

			SIZE_OF_ARRAY = size_of_array;
			selected_array_g = array + 1;
			init_array();
			
			if (array == 0)
				array_selected = array_direct;
			else if (array == 1)
				array_selected = array_reverse;
			else if (array == 2)
				array_selected = array_random;
			else if (array == 3)
				array_selected = array_overlap;
			
			sprintf_s(appData, MAX_PATH, "%s%s_%d.txt", "C:\\rollrat\\",
				array_name_s[array], size_of_array);
			fopen_s(&fp, appData, "w+");

			for (i = 0; i < size_of_array; i++) {
				fprintf(fp, "%d", array_selected[i]);
				if (i < size_of_array - 1)
					fprintf(fp, "\n");
			}

			fclose(fp);
		}
	}
}

void report_auto()
{
	TCHAR appData[MAX_PATH];
	FILE *fp;
	int algorithm, array, count, i;
	int size_of_array = 0;
	int *task_array;
	int *array_selected = 0;
	bool recalled = FALSE;
	int cxt = 0;
	long double *ld_array, sum, variance, avg;
	char addr[256];

	RAND_MIN = 0;
	RAND_SECTION = 10000000 - 0 + 1;

	/*if (SUCCEEDED(SHGetFolderPath(NULL,
								  CSIDL_LOCAL_APPDATA | CSIDL_FLAG_CREATE,
								  NULL,
								  SHGFP_TYPE_CURRENT,
								  appData)))
								  {*/
	//sprintf_s(addr, 256, "%s%s%d%s", appData, "\\report_", (int)time(NULL), ".log");
	//sprintf_s(addr, 256, "%s%s", "C:", "\\report_.log");
	_wfopen_s(&fp, _T("C:\\rollrat\\report_sort.log"), _T("w+"));
	/*fwprintf(fp, _T("정렬 알고리즘 정밀 측정기으로부터 자동으로 생성되었음.\n\n"));
	fwprintf(fp, _T("[알고리즘] [배열] [횟수] 순으로 알고리즘 목록이 생성되며, 바로 밑에 합계, 평균, 분산, 표준편차가 기제됩니다. 최대 횟수는 십만번이며, ")
	_T("천 개 이하의 자료개수에서만 중복없는 임의배열이 적용됩니다. 랜덤최소 값은 0이며 최대값은 10000으로 설정됩니다. 횟수는 모두 10회입니다.\n\n"));*/
	for (algorithm = 1; algorithm < 14; algorithm++)
	{
		if (algorithm == 11 || algorithm == 7 || algorithm == 8 || algorithm == 9)
			continue; // 버킷 알고리즘 사용안함
		for (array = 0; array < 4; array++)
		{
			for (count = 1; count < 5; count++)
			{
				//if (count > 3 && array == 2)
				//	break;	// 중복없는 임의배열 적용안함

				size_of_array = pow(10, count);//(double)((double)count / 2));

				SIZE_OF_ARRAY = size_of_array;
				task_array = (int *)malloc(sizeof(int) * size_of_array);
				array_direct = (int *)malloc(sizeof(int)*size_of_array);
				array_reverse = (int *)malloc(sizeof(int)*size_of_array);
				array_random = (int *)malloc(sizeof(int)*size_of_array);
				array_overlap = (int *)malloc(sizeof(int)*size_of_array);

#define _MAX_COUNT			30
				ld_array = (long double *)malloc(sizeof(long double) * _MAX_COUNT);

				for (i = 0; i < _MAX_COUNT; i++) {
					selected_array_g = array + 1;

					init_array();

					if (array == 0)
						array_selected = array_direct;
					else if (array == 1)
						array_selected = array_reverse;
					else if (array == 2)
						array_selected = array_random;
					else if (array == 3)
						array_selected = array_overlap;

					switch (algorithm) {
					case 1: timer_start(); sort_selection(array_selected, SIZE_OF_ARRAY); timer_finish(); break;
					case 2: timer_start(); sort_insertion(array_selected, SIZE_OF_ARRAY); timer_finish(); break;
					case 3: timer_start(); sort_bubble(array_selected, SIZE_OF_ARRAY); timer_finish(); break;
					case 4: timer_start(); sort_shell(array_selected, SIZE_OF_ARRAY); timer_finish(); break;
					case 5: timer_start(); sort_quick0(array_selected, SIZE_OF_ARRAY); timer_finish(); break;
					case 6: timer_start(); sort_quick1(array_selected, SIZE_OF_ARRAY); timer_finish(); break;
					case 7: timer_start(); sort_quick2(array_selected, SIZE_OF_ARRAY); timer_finish(); break;
					case 8: timer_start(); sort_quick3(array_selected, SIZE_OF_ARRAY); timer_finish(); break;
					case 9: timer_start(); sort_quick4(array_selected, SIZE_OF_ARRAY); timer_finish(); break;
					case 10: timer_start(); radix_sort(array_selected, SIZE_OF_ARRAY); timer_finish(); break;
					case 11: timer_start(); sort_bucket(array_selected, SIZE_OF_ARRAY, task_array); timer_finish(); break;
					case 12: timer_start(); sort_heap(array_selected, SIZE_OF_ARRAY); timer_finish(); break;
					case 13: timer_start(); sort_merge(array_selected, SIZE_OF_ARRAY, task_array); timer_finish(); break;
					}
					ld_array[i] = timer_getns();
				}

				sum = 0.0f;
				for (i = 0; i < _MAX_COUNT; i++) {
					sum += ld_array[i];
				}
				avg = sum / _MAX_COUNT;
				variance = 0.0f;
				for (i = 0; i < _MAX_COUNT; i++) {
					variance += pow(ld_array[i] - avg, 2);
				}
				variance /= _MAX_COUNT;
				fwprintf(fp, _T("[%s] [%s] [%s]\n"), sort_name[algorithm - 1], array_name[array], commasput(size_of_array));
				fwprintf(fp, _T("합계 : %.12lf ns\n평균 : %.12lf ns\n분산 : %.12lf\n표준편차 : %.12lf\n\n"), sum, avg, variance, sqrt(variance));
				printf("[%d/216]완료됨\n", ++cxt);

				// 오래걸리고 많이하면 과부하걸려서 걍 없앰
				/*free(ld_array);
				free(array_overlap);
				free(array_random);
				free(array_reverse);
				free(array_direct);
				free(task_array);*/
			}
		}
	}
	fwprintf(fp, _T("end"));
	fclose(fp);
	//}
	printf("C:\\rollrat\\report_sort.log에 성공적으로 생성하였습니다.");
}

/***
	swap:
	두 포인터의 값을 서로 바꿉니다.
***/
void aswap(char *left, char *right)
{
	char *tmp = (char *)*left;
	*left = *right;
	*right = tmp;
}

void Swap(char *parm_a, char *parm_b)
{
    int ex = *parm_a;
    *parm_a = *parm_b;
    *parm_b = ex;
}
 
void Min_Heap(char parm_data[], int parm_start, int parm_count)
{
    int node_left, node_right, node_current, node_start, node_index;
    if(parm_count - parm_start < 2) return;
    node_current = parm_start;
 
    while(node_current >= 0){
        node_index = node_current;
        node_start = node_current;
        while(node_start*2+1 < parm_count){
            node_left = node_start*2+1;
            node_right = node_start*2+2;
            node_start = node_left;
 
            if(node_right < parm_count && parm_data[node_right] >= parm_data[node_left]){
                node_start = node_right;
            }
            if(parm_data[node_start] > parm_data[node_index]){
                Swap(&parm_data[node_index], &parm_data[node_start]);
                node_index = node_start;
            }
        }
        --node_current;
    }
}
 
void Heap_Sort(char parm_data[], int parm_count)
{
    Min_Heap(parm_data, parm_count/2-1, parm_count);
    while(parm_count > 0){
        --parm_count;
		for (int k = 0; k < strlen(parm_data); k++)
			printf("%c ", parm_data[k]);
		printf("\n");
        Swap(&parm_data[0], &parm_data[parm_count]);
        Min_Heap(parm_data, 0, parm_count);
    }
}
main()
{
	char str[] = "SORTALGORITHM";
	
	char *task_array;
	task_array = (char *)malloc(sizeof(char) * 30);
	Heap_Sort(str, strlen(str));
	printf("%s", str);
	//create_array_data();
	return 0;
}