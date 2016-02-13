#include "String.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include <Windows.h>

int amain()
{
	basm::String<> T(0);
	basm::String<> F("asdf asdfq w asfqw asdfzcx");

	//F.Append("TTTTTTTTTTTTTTTTTTT");
	//printf("%s\n", F.c_str());
	//F.Append("ADSFasdF");

	basm::String<> *FF = new basm::String<>("   asdf sasdf   ");
	T.Append(*FF);

	//T->Append(36.7);

	//T->Insert(0, "astdf");
	//T.Equals("T");

	printf("%s", *F.Split(" ")[4]);
	
	printf("%s", *F.Replace("asdf", "TFSDFADSFT"));
	printf("\n%d", T.Len("as"));

	printf("%d\n", T.EndsWith("saf"));
	printf("%s\n", *T.Mid(1, 9));
	printf("%s\n", *T);
	printf("%s", *T.Trim().ToUpper().ToLower());
	return 0;
}