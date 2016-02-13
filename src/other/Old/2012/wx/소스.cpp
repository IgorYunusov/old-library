#include <iostream>
#include "wxTime.h"

void �ð����(TIME x)
{
	std::cout << x.y << "�� " << x.n << "�� " << x.d 
		<< "�� " << x.h << "�� " << x.m << "�� " << x.s << "�� " << std::endl;
}

int main()
{
	TIME x;
	ZeroTime(&x);

	PlusSecond(&x, 4654451);
	�ð����(x);
	ZeroTime(&x);

	PlusSecond(&x, 4654452);
	�ð����(x);
	ZeroTime(&x);

	PlusSecond(&x, 4654453);
	�ð����(x);
	ZeroTime(&x);

	PlusSecond(&x, 64722931200);
	�ð����(x);
	ZeroTime(&x);
	
	x.y = 2013;
	x.n = 9;
	x.d = 2;

	std::cout << GetZeller(x) << std::endl;
	std::cout << x.y << std::endl;
	std::cout << GetSecond(x);//64723780214
}
