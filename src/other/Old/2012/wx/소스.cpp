#include <iostream>
#include "wxTime.h"

void 시간출력(TIME x)
{
	std::cout << x.y << "년 " << x.n << "월 " << x.d 
		<< "일 " << x.h << "시 " << x.m << "분 " << x.s << "초 " << std::endl;
}

int main()
{
	TIME x;
	ZeroTime(&x);

	PlusSecond(&x, 4654451);
	시간출력(x);
	ZeroTime(&x);

	PlusSecond(&x, 4654452);
	시간출력(x);
	ZeroTime(&x);

	PlusSecond(&x, 4654453);
	시간출력(x);
	ZeroTime(&x);

	PlusSecond(&x, 64722931200);
	시간출력(x);
	ZeroTime(&x);
	
	x.y = 2013;
	x.n = 9;
	x.d = 2;

	std::cout << GetZeller(x) << std::endl;
	std::cout << x.y << std::endl;
	std::cout << GetSecond(x);//64723780214
}
