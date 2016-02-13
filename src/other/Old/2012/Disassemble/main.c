
#define _CRT_SECURE_NO_WARNINGS

#include "pe.h"
#include <stdio.h>

int ifequal(const char *x, const char *y);

int main()
{
	int i;
	FILE *fStream;
	ASLO_IDH	s;ASLO_INH32 y;
	ASLO_ISH text, data, idata, rsrc, reloc;
	char df[40] = {0,};
	char szData[sizeof(ASLO_IDH)] = {0,};
	char S[sizeof(ASLO_INH32)] = {0,};
	char X[sizeof(ASLO_ISH)] = {0,};

	printf("           %%--------------------------------------------------%%\n");
	printf("           |ROLLRAT SOFTWARE PEVIWER AND PEEDITOR VERSION 1.00|\n");
	printf("           |--------------------------------------------------|\n");
	printf("           |If you want to more information Then Visit My Blog|\n");
	printf("           |Or Send E-Mail(rollrat@naver.com) === RollRat ASLO|\n");
	printf("           %%--------------------------------------------------%%\n");
	
	fStream = fopen("c:\\windows\\system32\\notepad.exe", "r");

	if(fStream)
	{
		// Get IDS
		fseek(fStream, 0, SEEK_SET);
		fread(szData, sizeof(ASLO_IDH), 1, fStream);
		FillIDH(&s, szData);

		// Get INH32
		fseek(fStream, s.e_lfanew, SEEK_SET);
		fread(S, sizeof(ASLO_INH32), 1, fStream);
		FillINH32(&y, S);

		// Get TEXT
		fseek(fStream,  s.e_lfanew + sizeof(ASLO_INH32), SEEK_SET);
		fread(X, sizeof(ASLO_ISH), 1, fStream);
		FillISH(&text, X);

		// Get DATA
		fseek(fStream, s.e_lfanew + sizeof(ASLO_INH32) + sizeof(ASLO_ISH), SEEK_SET);
		fread(X, sizeof(ASLO_ISH), 1, fStream);
		FillISH(&data, X);

		// Get IDATA
		fseek(fStream, s.e_lfanew + sizeof(ASLO_INH32) + sizeof(ASLO_ISH) * 2, SEEK_SET);
		fread(X, sizeof(ASLO_ISH), 1, fStream);
		FillISH(&idata, X);
		
		// Get RSRC
		fseek(fStream, s.e_lfanew + sizeof(ASLO_INH32) + sizeof(ASLO_ISH) * 3, SEEK_SET);
		fread(X, sizeof(ASLO_ISH), 1, fStream);
		FillISH(&rsrc, X);
		
		// Get RELOC
		fseek(fStream, s.e_lfanew + sizeof(ASLO_INH32) + sizeof(ASLO_ISH) * 4, SEEK_SET);
		fread(X, sizeof(ASLO_ISH), 1, fStream);
		FillISH(&reloc, X);
	}
	while(1)
	{
		scanf("%s", df);
		if(ifequal(df, "ids"))
		{
			printf("  pFile    Data           Description                    Value\n");
			printf("%08x % 8x  %-30s %s\n", 0, s.e_magic, "Signature", "IMAGE_DOS_SIGNATURE");
			printf("%08x % 8x  %-30s %s\n", 2, s.e_cblp, "Bytes on Last Page of File", "");
			printf("%08x % 8x  %-30s %s\n", 4, s.e_cp, "Pages in File", "");
			printf("%08x % 8x  %-30s %s\n", 6, s.e_crlc, "Relocations", "");
			printf("%08x % 8x  %-30s %s\n", 8, s.e_cparhdr, "Size of header in paragraphs", "");
			printf("%08x % 8x  %-30s %s\n", 10, s.e_minalloc, "Mininum ExParagraphs", "");
			printf("%08x % 8x  %-30s %s\n", 12, s.e_maxalloc, "Maximum ExParagraphs", "");
			printf("%08x % 8x  %-30s %s\n", 14, s.e_ss, "Initial (relative) SS", "");
			printf("%08x % 8x  %-30s %s\n", 16, s.e_sp, "Initial SP", "");
			printf("%08x % 8x  %-30s %s\n", 18, s.e_csum, "Check Sum", "");
			printf("%08x % 8x  %-30s %s\n", 20, s.e_ip, "Initial IP", "");
			printf("%08x % 8x  %-30s %s\n", 22, s.e_cs, "Initial (relative) CS", "");
			printf("%08x % 8x  %-30s %s\n", 24, s.e_lfarlc, "File address of relocation table", "");
			printf("%08x % 8x  %-30s %s\n", 26, s.e_ovno, "Overlay number", "");
			for(i = 0; i < 4; i++)
				printf("%08x % 8x  %-30s %s\n", 26 + (i + 1) * 2, s.e_res[i], "Reserved words", "");
			printf("%08x % 8x  %-30s %s\n", 36, s.e_oemid, "OEM identifier (for e_oeminfo)", "");
			printf("%08x % 8x  %-30s %s\n", 38, s.e_oeminfo, "OEM information; e_oemid specific", "");
			for(i = 0; i < 10; i++)
				printf("%08x % 8x  %-30s %s\n", 38 + (i + 1) * 2, s.e_res2[i], "Reserved words", "");
			printf("%08x % 8x  %-30s %s\n", 60, s.e_lfanew, "File address of new exe header", "");
		}
	}
	fclose(fStream);
}

int ifequal(const char *x, const char *y)
{
	const char *xx = x;
	for(; *xx; xx++, y++)
		if(*xx != *y)
			return 0;
	return 1;
}