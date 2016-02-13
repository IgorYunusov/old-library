#include "rcc.h"

#include <stdio.h>

void a(ULONG t, char * c)
{
	printf("%s", c);
}

#define A int ma\
in()

A
{
	ptree last = ctree.create();
	ctree.push_left(last, 0, "1");
	ctree.push_right(last, 0, "2");
	last->data = "3";
	preorder_travel(last, a);
	putchar('\n');
	postorder_travel(last, a);
	putchar('\n');
	inorder_travel(last, a);
	{
		int n = 1;
		char *p;
		switch (n)
		{
		case 1:
			p = "one";
			if (0)
		case 2:
			p = "two";
			if (0)
		case 3:
			p = "three";
			printf("%s", p);
			break;
		}
	}
	return 0;
}