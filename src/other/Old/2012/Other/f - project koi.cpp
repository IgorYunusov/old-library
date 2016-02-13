#include <stdio.h>

int d[9] = {-21, -8, -3, 1, 3, 16, 31, 49, 68};

void f(int low, int high, int key);
int foo(int a, int b);
int main()
{
	//f(0, 8, 18);
	int x[10], y[10];
	int i, j;
	int n = 10;
	for(i = 0; i < n; i++) x[i] = i + 1;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++)
			y[j] = x[(i + j) % n];
		for(j = 0; j < n; j++)
			x[j] = y[j];
	}
	printf("%d %d %d\n", x[3], x[6], x[9]);

	printf("%d", foo(147, 473));

	getchar();
}

void f(int low, int high, int key)
{
	int mid;
	mid = (low+high)/2;
	if(low > high) return;
	if(d[mid] == key) return;
	if(d[mid] > key)
		f(low, mid - 1, key);
	else
	{
		printf("R");
		f(mid + 1, high, key);
	}
}

int foo(int a, int b)
{
	if(a == 0 && b == 0)
		return 0;
	return foo(b / 2, a / 2) * 2 + (a + b) % 2;
}