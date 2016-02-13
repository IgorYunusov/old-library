#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_SPACE    "                                        "\
                        "                                        "

static void hollow_diamond(int size);

int main()
{
	hollow_diamond(5);
	return 0;
}

static void hollow_diamond(int size)
{
	int i, j, n, c;
	char lspace[] = MAX_SPACE;	// left space
	char hollow[] = MAX_SPACE;	// inner hollow space
	char *ptr = hollow + sizeof(hollow) / sizeof(char) - 1;
	int size2 = size * 2;

	for(i = 0; i < size2 - 1; i++)
	{
		c = i / size;
		j = abs(c * size2 - i - c * 2);
		n = size - j - 1;

		lspace[n] = 0;
		printf("%s*", lspace);
		if (j)
			printf("%s*", ptr - j * 2 + 1);
		putchar('\n');
		lspace[n] = ' ';
	}
}

#define ratio 0.01745329251994329576923690768489

int heart()
{
	int i, j;
	for(i = 0; i <= 270; i += 17)
	{
		double s = sin(i * ratio);

		if (i == 85)
			continue;

		for (int j = 0; j < (1 - s) * 10; j++)
			printf(" ");

		if (i < 90)
		{
			for (j = 0; j < 2 * (int)(s * 10); j++)
				printf("*");
			for (j = 0; j < 2 * (int)((1 - s) * 10) + 1; j++)
				printf(" ");
			for (j = 0; j < 2 * (int)(s * 10); j++)
				printf("*");
		}
		else
		{
			for (j = 0; j < 2 * (int)((s + 1) * 10) - 1; j++)
				printf("*");
		}

		printf("\n");
	}
}