#include <iostream>
#include "RegexParser.h"

#include <Windows.h>

int main()
{
	_regex parser_x::gremon *ArrGremon;
	_regex parser_x parsemod;

	parsemod.regexSetPattern("a|sd?ozx");
	ArrGremon = parsemod.regexMatch("fwqsdozxasdozxasdfweasdozxasdfe");
	return 0;
}

