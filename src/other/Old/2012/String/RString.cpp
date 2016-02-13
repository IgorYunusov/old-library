#include <iostream>
#include <iterator>
//#include "RString.hpp"
//#include "RCompiler.hpp"
//#include "libCCO.h"
#include "rutil.h"
#include "vector.h"
#include "integer.h"
#include "uinteger.h"
#include "RString.hpp"
#include "bank.h"
#include <Windows.h>
#include <array>
#include <vector>
#include <list>
#include "linkedlist.h"
#include "cutilityex.h"
#include <string>
#include <locale.h>
#include <time.h>
#include "array.h"
#include "winutil.h"
#include <map>
#include "excmemory.h"
#include "qurey.h"

//#include <iterator>
void delay(int i)
{
	if (i == 0)
		return;
	delay(i-10);  // give the decrement as 1 or 10 or 100 as convenient
}

using namespace std;

#define f_n 8

void array_spin()
{
    char A[f_n][f_n], B[f_n][f_n];
    int i,j;
    char alphabet='A';
 
    for(i=0; i<f_n; i++){
        for(j=0; j<f_n; j++){
            A[i][j]=alphabet;
            alphabet++;
        }
    }
 
    for(i=0; i<f_n; i++){
        for(j=0; j<f_n; j++){
            printf("%c ",A[i][j]);
        }
        printf("\n");
    }
 
    printf("==================\n");
 
	_X_LIB _rotate<char**> (A, f_n, f_n, 2);

	for(i=0; i<f_n; i++){
        for(j=0; j<f_n; j++){
            printf("%c ",A[i][j]);
        }
        printf("\n");
    }
	
    printf("==================\n");
 
	_X_LIB _reverse<char**> (A, f_n, f_n);
	
	for(i=0; i<f_n; i++){
        for(j=0; j<f_n; j++){
            printf("%c ",A[i][j]);
        }
        printf("\n");
    }
	
    printf("==================\n");
 
	_X_LIB _back(A[0], 3, 1);

    for(i=0; i<f_n; i++){
        for(j=0; j<f_n; j++){
            printf("%c ",A[i][j]);
        }
        printf("\n");
    }

	printf("==================\n");
 
	_X_LIB _forward(A[0], 2, 3, 2);

    for(i=0; i<f_n; i++){
        for(j=0; j<f_n; j++){
            printf("%c ",A[i][j]);
        }
        printf("\n");
    }

	printf("==================\n");

	srand(time(NULL));

	_X_LIB _polytazing(A, f_n, f_n, rand);

    for(i=0; i<f_n; i++){
        for(j=0; j<f_n; j++){
            printf("%c ",A[i][j]);
        }
        printf("\n");
    }

}

void main()
{
	array_spin();
	//auto_ptr<int> aiop;
	max(2,3);

	_X_LIB _X_Vector_Ex<int> A(50);
	_X_UTIL array<int> b;
	_X_UTIL array<int> ca;

	const int* pp = new int(10);
	int* pi = const_cast<int*> (pp);

	_X_LIB _X_Mem_Controller<char> bA;
	_X_LIB _iterator<int> iter;

	int *aop;
	aop = _X_LIB _Allocate<int> (3);

	b.allocate(10);
	ca.allocate(10);

	_X_UTIL array_n<char> bc;
	bc = _X_UTIL _Triangle<_X_UTIL array_n<char> > (50, '*');
	for( ; bc++; )
	{	
		for( ; (&bc)++; )
			cout << **bc;
		cout << endl;
	}

	_X_UTIL _Replace_Each(bc, '*', 'e', '&');

	for( ; bc++; )
	{	
		for( ; (&bc)++; )
			cout << **bc;
		cout << endl;
	}

	for( ; ca++; )
		&ca = 1;
	for( ; b++; )
		&b = 6;
	_X_UTIL _Push_Back(ca, 9);
	//_X_UTIL _Push_Back(ca, 9);

	for( ; ca++; )
		cout << *ca << endl;

	cout << endl;

	b << ca << 300;

	for( ; b++; )
		cout << *b << endl;

	std::array<int,5> first = {10, 20, 30, 40, 50};

	int* a = new int[0];

	A << 5; // 항목 추가
	A.assign(5,1);

	cout<< A.size_r() << endl;

	A >> 5; // 항목 삭제

	cout<< A.size_r() << endl;

	A.insert(25, 4);
	A.push_back(20); // vector 끝에 항목을 추가합니다.

	cout << A.back() << endl;
	cout << A[25] << endl
		 << A.size_r() << endl;

	//A.erase(2,10);

	cout << A.size_r() << endl << endl;

	A.fill(50);

	for(int i = 0; i <= A.size_r(); i++)
		cout << A[i] << endl;

	A->alloc(0, 0);

	int i = 0;

	/*Integer ex;
	ex = 309;
	cout << ex << endl;
	ex++;
	cout << ex << endl;
	ex--;
	cout << ex << endl;

	ex += "1000";
	cout << ex;*/

	_X_LIB sList<float> floatList;

	RString asdf("rollrat software");

	cout << endl;

	for(int i = 0; i < asdf.Length(); i++)
		cout << asdf.Get()[i].Get();
	cout << endl;
	cout << (char*)asdf.Get() << endl;

	_X_LIB link<int> aas;

	aas.push_back(991);
	aas.push_back(99);
	aas.push_back(199);

	_X_LIB qurey_link<int> aasd;
	_X_LIB qurey_const_sequencer<int> qu;

	aasd.push_back(1);
	aasd.push_back(2);
	aasd.push_back(3);
	aasd.push_back(4);
	aasd.push_back(4);
	aasd.push_front(5);
	aasd.push_front(5);
	aasd.pop_front();
	aasd.pop_front();
	aasd.pop_front();

	for(qu = aasd.begin(); qu != aasd.end(); qu++)
		cout << *qu << endl;
	
	cout << endl << aas.pop_back() << endl << endl;

	int Asc[50000];
	#define abs(num)			( num > 0 ? num : ( num * -1 ))

	for(int ad = 0; ad <= 50000; ad++)
		Asc[ad] = abs(ad % 6 * 20 - ad);
	
	cout << endl;
	
	_X_LIB _quick_sort(Asc, 50000);

	for(int ad = 0; ad <= 50000; ad++)
		cout << Asc[ad] << endl;

	int choice;
	float value;
	do
	{
		cout << "? ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			cout << "Enter a floating point value: ";
			cin >> value;
			floatList.insertAtFront(value);
			floatList.print();
			break;
		case 2:
			cout << "Enter a floating point value: ";
			cin >> value;
			floatList.insertAtBack(value);
			floatList.print();
			break;
		case 3:
			if(floatList.removeFromFront(value))
				cout << value << " removed from list !" << endl;
			floatList.print();
			break;
		case 4:
			if(floatList.removeFromBack(value))
				cout << value << " removed from list !" << endl;
			floatList.print();
			break;
		}

	} while(choice != 5);

	/*_X_LIB _X_Bank abd("rollrat");

	abd.SetPointPercent(0.9f);
	abd.SavingMoney(1000);

	abd.FindMoney(100);
	abd.FindMoney(100);
	abd.FindMoney(100);
	abd.FindMoney(100);
	abd.FindMoney(100);
	abd.FindMoney(100);
	abd.FindMoney(100);
	abd.FindMoney(100);
	abd.FindMoney(100);

	abd.SavingMoney(1000);
	abd.SavingMoney(1000);
	abd.SavingMoney(1000);
	abd.SavingMoney(1000);

	abd.GetPoint();*/
	
		int f = 0;
	for(
		;
		;
		)
	{
		f++;
		Sleep(1000);
	}

	cin.get();
}

void maㅁin()
{
	int i, j, k, step;
	printf("*모양 마름모 상부의 높이? : ");
	scanf("%d", &step); // 마름모 형태의 상부 입력받음

	// 윗부분 print
	for(k=step; k>0; k--)
	{
		for(i=k-1; i>0; i--) // 윗부분에서는 라인이 내려갈수록 공백의 수가 하나씩 줄어든다.
		{
			printf(" "); // 공백 하나 출력
		}
		for(j=step*2-2*k; j>=0; j--) // 윗부분에서는 라인이 내려갈수록 *의 수가 하나씩 많아진다.
			printf("*"); // * 하나 출력
		printf("\n"); // 개행(행을 바꾼다)
	}



	// 아래 부분 print
	for(k=1; k<step; k++)
	{
		for(i=k; i>0; i--) // 아래부분에서는 라인이 내려갈수록 공백의 수가 하나씩 많아진다.
		{
			printf(" "); // 공백 하나 출력
		}
		for(j=step*2-2*k; j>1; j--) // 아래부분에서는 라인이 내려갈수록 *의 수가 하나씩 줄어든다.
			printf("*"); // * 하나 출력
		printf("\n"); // 개행(행을 바꾼다)
	}
}

