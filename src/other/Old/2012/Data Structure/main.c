#include "stu_uic.h"
#include <stdio.h>


int main()
{
	char strx[IMAGE_STD_HEADER_SIZE];
	char stry[IMAGE_MAIN_SECTIONS_HEADER_SIZE];
	char strz[IMAGE_SECTIONS_HEADER_SIZE];
	char *x;
	int i;

	IMAGE_STD_HEADER xISH;
	IMAGE_MAIN_SECTIONS_HEADER xMSH;
	//IMAGE_SECTIONS_HEADER xList;
	IMAGE_SECTIONS_HEADER xData;
	//IMAGE_SECTIONS_HEADER xArray;
	//IMAGE_SECTIONS_HEADER xPassWord;
	//IMAGE_SECTIONS_HEADER xNote;

	printf("%x", 'S');

	// Image Standard Header
	stdsetish(&xISH);
	x = ishtostr(xISH);				// ish to str
	for(i = 0; i < IMAGE_STD_HEADER_SIZE; i++)
		strx[i] = x[i];				// copy to strx
	for(i = 0; i < IMAGE_STD_HEADER_SIZE; i++)
		printf("%c", x[i]);

	// Image Main Sections Header
	stdsetimsh(&xMSH);				// std set
	x = imshtostr(xMSH);
	for(i = 0; i < IMAGE_MAIN_SECTIONS_HEADER_SIZE; i++)
		stry[i] = x[i];

	// Image Setions Header
	stdsetishe(&xData);
	x = ishetostr(xData);
	for(i = 0; i < IMAGE_SECTIONS_HEADER_SIZE; i++)
		strz[i] = x[i];

	x = make(xISH, xMSH, xData, 0);

	return 0;
}