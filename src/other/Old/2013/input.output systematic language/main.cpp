#include <string>
#include <regex>
#include <Windows.h>
#include <fstream>
#include <iostream>
#include <functional>
#include <cctype>
#include <locale>
#include <stack>
#include <initializer_list>

#include "tools.h"

using namespace std;

#ifndef _DEBUG
int main(int argc, char * argv[])
#else
int main()
#endif
{
#ifndef _DEBUG
	if (argc != 3)
		return 0;
#else
	string redfile;
	cout << "openfilename : " << endl;
	/*cin >> redfile;*/
	redfile = "c:\\windows\\system32\\notepad.exe";
#endif

	File<> file;

	BYTE *t;

	if (
#ifndef _DEBUG
		file.open(argv[1])
#else
		file.open(redfile.c_str())
#endif
		) {
		cerr << "Unable to open file for reading!" << endl;
		return 1;
	}
	else
	{
		file.calcsize();
		t = file.read();
	}

	return 0;
}
