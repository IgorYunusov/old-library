#include <malloc.h>
#include "stu_uic.h"


void stdsetimsh(PTR_IMAGE_MAIN_SECTIONS_HEADER gx)
{
	gx->SectionTime = 1;
	gx->Separation = '\0';
	gx->GroupingTrue = _NO_USING;
	gx->GroupingSize = 0;
	gx->SimpleListSection = _USING;
	gx->PassWordTrue = _USING;
	gx->UsingNote = _NO_USING;
	gx->UsingUnicodeForData = _NO_USING;
	return;
}

void stdsetish(PTR_IMAGE_STD_HEADER gx)
{
	gx->el_sign = _DWORD_SMALL_ENDIAN(_ROLLRAT_DATA_STRUCTURE_SIGNATURE);
	gx->el_isz = _WORD_SMALL_ENDIAN(IMAGE_STD_HEADER_SIZE);
	gx->el_itdf = IMAGE_STD_DATAARRAYRULE_STANDARD;
	gx->el_uds = _NO_USING;
	gx->el_etype = IMAGE_STD_ENDIANTYPE_INTEL32;
	gx->el_mslad = _DWORD_SMALL_ENDIAN(IMAGE_STD_HEADER_SIZE + 1);
	return;
}

void stdsetishe(PTR_IMAGE_SECTIONS_HEADER gx)
{
	gx->Option = _NO_USING;
	gx->SectionSeparation = '\0';
	gx->MakeVirtualAddress = _USING;
	gx->SearchData = _USING;
	gx->PassWordTrue = _USING;
	gx->GroupingHighSeparation = '\0';
	gx->GroupingLowSeparation = '\0';
	gx->GroupTheNumber = 0;
	gx->OutputRule = 0;
	gx->DataStoreRule = IMAGE_SECTIONS_DATASTROERULE_STANDARD;
	gx->AskBeforeAccess = _USING;
	return;
}

char *ishtostr(IMAGE_STD_HEADER gx)
{
	char strx[sizeof(struct _IMAGE_STD_HEADER)];
	int i;
	for(i = 0; i < sizeof(struct _IMAGE_STD_HEADER); i++)
		strx[i] = ((char *)(void *)(&gx))[i];
	return strx;
}

void strtoish(PTR_IMAGE_STD_HEADER gx, const char *x)
{
	int i;
	for(i = 0; i < sizeof(struct _IMAGE_STD_HEADER); i++)
		((char *)(void *)(&gx))[i] = x[i];
	return;
}

char *imshtostr(IMAGE_MAIN_SECTIONS_HEADER gx)
{
	char strx[sizeof(struct _IMAGE_MAIN_SECTIONS_HEADER)];
	int i;
	for(i = 0; i < sizeof(struct _IMAGE_MAIN_SECTIONS_HEADER); i++)
		strx[i] = ((char *)(void *)(&gx))[i];
	return strx;
}

void strtoimsh(PTR_IMAGE_MAIN_SECTIONS_HEADER gx, const char *x)
{
	int i;
	for(i = 0; i < sizeof(struct _IMAGE_MAIN_SECTIONS_HEADER); i++)
		((char *)(void *)(&gx))[i] = x[i];
	return;
}

void strtoishe(PTR_IMAGE_SECTIONS_HEADER gx, const char *x)
{
	int i;
	for(i = 0; i < sizeof(struct _IMAGE_SECTIONS_HEADER); i++)
		((char *)(void *)(&gx))[i] = x[i];
	return;
}

char *ishetostr(IMAGE_SECTIONS_HEADER gx)
{
	char strx[sizeof(struct _IMAGE_SECTIONS_HEADER)];
	int i;
	for(i = 0; i < sizeof(struct _IMAGE_SECTIONS_HEADER); i++)
		strx[i] = ((char *)(void *)(&gx))[i];
	return strx;
}

char *make(IMAGE_STD_HEADER x, IMAGE_MAIN_SECTIONS_HEADER y, IMAGE_SECTIONS_HEADER z, const DS_TYPE a)
{
	char strx[IMAGE_STD_HEADER_SIZE];
	char stry[IMAGE_MAIN_SECTIONS_HEADER_SIZE];
	char strz[IMAGE_SECTIONS_HEADER_SIZE];
	char *xz;
	int i = 0;
	xz = ishtostr(x);				// ish to str
	for(i = 0; i < IMAGE_STD_HEADER_SIZE; i++)
		strx[i] = xz[i];				// copy to strx
	xz = imshtostr(y);
	for(i = 0; i < IMAGE_MAIN_SECTIONS_HEADER_SIZE; i++)
		stry[i] = xz[i];
	xz = ishetostr(z);
	for(i = 0; i < IMAGE_SECTIONS_HEADER_SIZE; i++)
		strz[i] = xz[i];

	for(i = 0; i < y.SectionTime; i++)
		;
}