/*
	POINTER LESSON FOR HANDICAPPED

	BY HU-BO-JUK-PIT-DO-SEONG

	��� ���Ѱ� �Ǹ��� ������ �ִ�.
*/

#include <stdio.h>

//
// ������ ����
//
// &[����]�� *�ϳ� �ø���, *[����]�� *�ϳ� ���Դϴ�.
//

void _Swap(void ** _Left, void ** _Right)
{
	// void * = ������ ����, object��� �ص� ������.

	// _Left�� ���� ���´�. *���� = �ּҷκ��� �����
	char * _T = (char *)*_Left;

	// _Left�� �����Ͽ� _Right���� �ű��.
	*_Left = *_Right;

	// _T�� _Right�� �ű��.
	*_Right = (void *)_T;
}

	// char *�� �ּҰ��� �Ѱܹޱ� ���ؼ� *�� �ϳ� �� �ٿ��ݴϴ�.
void inc(void ** _Ptr)
{
	// �ּҸ� �Ѵܰ� �ø���.
	((char *)*_Ptr)++;
}

void inc_call(void ** _Ptr)
{
	// *_Ptr : ���� ��������,
	// &*_Ptr : �װ��� �ּҸ� �����´�.
	inc(&*_Ptr);
}

void _Equal(char ** _Left, char _Right)
{
	// *_Left : ���� ��������, char *
	// **_Left : �װ��� ���� �����´�. char
	if (**_Left == _Right)
		inc(&*_Left);
	else
		((char *)*_Left)--;
}

//
// �Լ�������
//
// ���� : ��ȯ�� (* �Լ��̸�)(�μ���)
// ���� : �Լ���ȯ�� (* �Լ��̸�(�μ�))(��ȯ�� �Լ� �μ�)
//

int plus_a(int a, int b)
{
	// �ܼ��� ����
	return a + b;
}

int minus_a(int a, int b)
{
	// �ܼ��� ����
	return a - b;
}

int (* plus_minus(int what))(int, int)
{
	int(*plus)(int, int);		// ����
	int(*minus)(int, int);
	plus = plus_a;				// ����
	minus = minus_a;
	if (what == 0)
		return plus;
	else
		return minus;
}

int mul_a(int a, int b)
{
	// �ܼ��� ����
	return a * b;
}

int div_a(int a, int b)
{
	// �ܼ��� ������
	return a / b;
}

int (* mul_div(int what))(int, int)
{
	int(*mul)(int, int);		// ����
	int(*div)(int, int);
	mul = mul_a;				// ����
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

	// ptr�� �ּҸ� �ѱ�ϴ�.
	// char * + & = char **�� �����ϴ�.
	inc_call(&ptr);
	printf(ptr);

	// ptr�� ù ���ڿ�, o���ڰ� ������ Ȯ���մϴ�.
	_Equal(&ptr, 'o');
	printf(ptr);

	// �ּҿ� 4��ŭ �����ݴϴ�.
	ptr += 4;
	printf(ptr);

	// ���� 2��ŭ �����ݴϴ�.
	*ptr += 2;
	printf(ptr);

	// �ּҿ� 4��ŭ ���մϴ�.
	// ptr = char *;
	// &ptr = char **;
	// *&ptr = char **& = char *;
	*&ptr += 4;
	printf(ptr);

	// ���� 1��ŭ ���մϴ�.
	// ptr = char *;
	// &ptr = char **;
	// *&ptr = char **& = char *;
	// **&ptr = char **& = char;
	**&ptr += 1;
	printf(ptr);

	// wht���� 0�̹Ƿ� plus���� ����
	a = plus_minus(0)(1, 3);
	printf("%d\n", a);

	// mul_div -> mul ������ ȣ�� ���ϱ� �������
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


