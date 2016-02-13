#include "String.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include <Windows.h>
#include "Interpreter.h"
#include <vector>

#include <complex>

#include "urray.h"
#include "stac.h"

int main()
{
	basm::String<> T("TLoyal( FT&Y R)AD4556");
	T.Append("TLoyal( FT&Y R)AD4556");
	printf("%s", T.Split("(")(1).Split(")")(0));
	if (T.Split("(")(1).Split(")")(0) == " FT&Y R")
	{
		printf("\ns");
	}
	Interpreter<> Tf;
	Tf.get_condition_from_idealized_codeblock(T);
	std::vector < int > fa;
	//fa.push_back(3);
	//fa.resize(3);
	fa.push_back(6);
	fa.push_back(6);
	fa.push_back(6);
	fa.push_back(6);
	fa.push_back(6);
	fa.push_back(6);
	printf("%d\n", fa.size());
	fa.resize(3);
	printf("%d\n", fa[0]);
	printf("%d\n", fa.size());

	urray<basm::String<char>> S;
	S=GetArgument(basm::make_string("program adsfasd \" fasd fasd f \" adsf").c_str());
	if(S.Contains(basm::make_string("adsf")))
		printf("%s", S[3]);
	return 0;
}