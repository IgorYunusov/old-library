/******************************************

	2015년 7월 인천광역시 교육청 모의고사

	수학영역 : A형 30번, B형 21번

	문제 알고리즘

******************************************/

#include <stdio.h>

/*

	문제에서 주어진 정보에 의해 다음과 같이 
	A,B,C,D에 올 수 있는 유형이 정해진다.

		A->A
		A->B

		B->C
		B->D

		C->A
		C->B

		D->C
		D->D

	이 유형마다 카운트를 설정하고 하나씩 줄여나가
	맞는 유형에서 해당 값을 출력시키면 된다.

*/

int last = 0;
int cou = 0;

out(t)
{
	if (t == 1) {
		printf("\n");
		return;
	}
	out(t >> 1);
	printf("\xa1%c", "\xdb\xdc"[t & 1]);
}

outa(a,b,c,d,t)
{
	if (!a) {
		if (!(a + b + c + d) && (last != (t<<1)))
			out(last = t<<1, cou++);
		return;
	}
	outa(a - 1, b, c, d, (t << 1));
	outb(a - 1, b, c, d, (t << 1));
}

outb(a,b,c,d,t)
{
	if (!b) {
		if (!(a + b + c + d) && (last != (t<<1)))
			out(last = t<<1, cou++);
		return;
	}
	outc(a, b - 1, c, d, (t << 1));
	outd(a, b - 1, c, d, (t << 1));
}

outc(a,b,c,d,t)
{
	if (!c) {
		if (!(a + b + c + d) && (last != (t<<1)+1))
			out(last = (t<<1)+1, cou++);
		return; 
	}
	outa(a, b, c - 1, d, (t << 1)+1);
	outb(a, b, c - 1, d, (t << 1)+1);
}

outd(a,b,c,d,t)
{
	if (!d) {
		if (!(a + b + c + d) && (last != (t<<1)+1))
			out(last = (t<<1)+1, cou++);
		return; 
	}
	outc(a, b, c, d - 1, (t << 1)+1);
	outd(a, b, c, d - 1, (t << 1)+1);
}

int start(n,a,b,c,d)
{ // n = dummy
	cou = 0;
	outa(a, b, c, d, 1);
	outb(a, b, c, d, 1);
	outc(a, b, c, d, 1);
	outd(a, b, c, d, 1);
	return cou;
}

int main()
{
	printf("\n%d\n\n", start(6,  2, 1, 1, 1));
	printf("\n%d\n\n", start(10, 4, 2, 2, 1));
	printf("\n%d\n\n", start(6,  2, 1, 1, 1));
	printf("\n%d\n\n", start(10, 4, 2, 2, 1));
	printf("\n%d\n\n", start(6,  2, 1, 1, 1));
	printf("\n%d\n\n", start(10, 4, 2, 2, 1));
	return 0;
}