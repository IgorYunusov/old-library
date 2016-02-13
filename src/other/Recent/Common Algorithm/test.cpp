#include <iostream>
#include "dotsplit.h"
#include <string>

int main()
{

	for(std::string str : dot_split("rollrat.rollrat.rollrat('rollrat')"))
	{
		std::cout << str << std::endl;
	}
}