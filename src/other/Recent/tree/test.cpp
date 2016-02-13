
#include "tree.h"
#include <string>

int main()
{
	tree<int> x;
	tree<std::string> xt;
	//tree<std::string> xt;
	
	x.is_data();
	
	*x = 1;

	return 0;
}