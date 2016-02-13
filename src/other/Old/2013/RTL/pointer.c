/*
	POINTER LESSON FOR HANDICAPPED

	BY HU-BO-JUK-PIT-DO-SEONG

	모든 권한과 권리는 나한테 있다.
*/

#include <stdio.h>

//
// 포인터 기초
//
// &[변수]는 *하나 늘리고, *[변수]는 *하나 줄입니다.
//

void _Swap(void ** _Left, void ** _Right)
{
	// void * = 임의의 변수, object라고 해도 무방함.

	// _Left의 값을 얻어온다. *변수 = 주소로부터 값얻기
	char * _T = (char *)*_Left;

	// _Left를 참조하여 _Right값을 옮긴다.
	*_Left = *_Right;

	// _T를 _Right로 옮긴다.
	*_Right = (void *)_T;
}

	// char *의 주소값을 넘겨받기 위해서 *를 하나 더 붙여줍니다.
void inc(void ** _Ptr)
{
	// 주소를 한단계 올린다.
	((char *)*_Ptr)++;
}

void inc_call(void ** _Ptr)
{
	// *_Ptr : 값을 가져오고,
	// &*_Ptr : 그것의 주소를 가져온다.
	inc(&*_Ptr);
}

void _Equal(char ** _Left, char _Right)
{
	// *_Left : 값을 가져오고, char *
	// **_Left : 그것의 값을 가져온다. char
	if (**_Left == _Right)
		inc(&*_Left);
	else
		((char *)*_Left)--;
}

//
// 함수포인터
//
// 선언 : 반환값 (* 함수이름)(인수들)
// 리턴 : 함수반환값 (* 함수이름(인수))(반환할 함수 인수)
//

int plus_a(int a, int b)
{
	// 단순한 덧셈
	return a + b;
}

int minus_a(int a, int b)
{
	// 단순한 뺄셈
	return a - b;
}

int (* plus_minus(int what))(int, int)
{
	int(*plus)(int, int);		// 선언
	int(*minus)(int, int);
	plus = plus_a;				// 대입
	minus = minus_a;
	if (what == 0)
		return plus;
	else
		return minus;
}

int mul_a(int a, int b)
{
	// 단순한 곱셈
	return a * b;
}

int div_a(int a, int b)
{
	// 단순한 나눗셈
	return a / b;
}

int (* mul_div(int what))(int, int)
{
	int(*mul)(int, int);		// 선언
	int(*div)(int, int);
	mul = mul_a;				// 대입
	div = div_a;
	if (what == 0)
		return mul;
	else
		return div;
}


int (*(* plus_minus_mul_div(int what))(int))(int, int)
{
	int(*(*plus_minus_t)(int))(int, int);
	int(*(*mul_div_t)(int))(int, int);
	plus_minus_t = plus_minus;
	mul_div_t = mul_div;
	if (what == 0)
		return plus_minus_t;
	else
		return mul_div_t;
}

main()
{
	int a, b;
	char t[] = "yomiko wa bbaka.\n";
	char * ptr = t;
	a = 10; b = 11;
	_Swap(&a, &b);
	printf("%d %d\n", a, b);

	// ptr의 주소를 넘깁니다.
	// char * + & = char **와 같습니다.
	inc_call(&ptr);
	printf(ptr);

	// ptr의 첫 문자와, o문자가 같은지 확인합니다.
	_Equal(&ptr, 'o');
	printf(ptr);

	// 주소에 4만큼 더해줍니다.
	ptr += 4;
	printf(ptr);

	// 값에 2만큼 더해줍니다.
	*ptr += 2;
	printf(ptr);

	// 주소에 4만큼 더합니다.
	// ptr = char *;
	// &ptr = char **;
	// *&ptr = char **& = char *;
	*&ptr += 4;
	printf(ptr);

	// 값에 1만큼 더합니다.
	// ptr = char *;
	// &ptr = char **;
	// *&ptr = char **& = char *;
	// **&ptr = char **& = char;
	**&ptr += 1;
	printf(ptr);

	// wht값이 0이므로 plus연산 실행
	a = plus_minus(0)(1, 3);
	printf("%d\n", a);

	// mul_div -> mul 순으로 호출 곱하기 연산실행
	b = plus_minus_mul_div(1)(0)(2, 4);
	printf("%d\n", b);

	return 0;
}

#include <stdio.h>

main()
{
	printf("Hello World!!");
	return 0;
}


