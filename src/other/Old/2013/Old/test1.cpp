//int main(int a, int b)
//{
//	if (a == 1) 
//		b = 0;
//	if (a <= 100){
//		b += a++;
//		main(a, b);
//	}
//	else if (a > 100){
//		printf("%d\n", b);
//	}
//}

#include "regex_v2.h"
#include "ttomlier.h"

#include <stdio.h>

int main()
{
	class regex<> t;
	t.analysis("[0-9]");


	ttomlier<> ta("asdfasdf");
	ta.forwardChar(0, 0);
	ta.setFirst();

	printf("%u", ta.disassembleHcode(L'´Û').cho);

	char  xt[] = "asqqwtwqASDfqweRAsdfQWER";
	ta.upper(xt);

	printf("%s", xt);
	ta.lower(xt);

	printf("%s", xt);
	return 0;
}