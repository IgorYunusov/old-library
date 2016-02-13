#include <stdio.h>

int snail(int size);

int main()
{
	snail(10);
}

int snail(int size)
{
	int line = 0 ,
		queue = 0;
	int num = 1;
	int array[20][20] = {0, };
	
	for( ; queue <= size; num++, queue++)
		array[line][queue] = num;
	for(queue = size, line += 1; line <= size; line++, num++)
		array[line][queue] = num;
	for(line = size, queue -= 1; queue >= 0; num++, queue--)
		array[line][queue] = num;
	for(line = size - 1, queue = 0; line > 0; line--, num++)
		array[line][queue] = num;

	for ( line=0 ; size>=line ; ++line )
	{
		for ( queue=0 ; size>=queue ; ++queue )
		{
			printf (" %3d", array [line][queue]);
		}
		putchar('\n');
	}
	return 0;
}