#include <iostream>
#include <Windows.h>
#include <vector>
#include <map>
#include <string>
#include <conio.h>
#include <fstream>
#include <random>
#include "frame_tool.h"
//#include "run.h"
#include "type.h"
#include "var.h"
#include "token.h"
#include "frame.h"

using namespace std;
//int tan_zigzag_number(int count)
//{
//	//int *temp = new int[(size_t)((count * (count + 1)) / 2)];
//	int **temp = new int*[count];
//	for (int i = 1; i <= count; i++)
//		temp[i-1] = new int[i];
//
//	// tangent number (1) = 1
//	for (int i = 0; i < count; i++) {
//		//for (int j = 0, k = i ? temp[i][i-1] : 1; j < (count - i); k *= (++j + 1))
//		//	temp[j][i] = k = k + (i ? temp[j][i-1] * (j + 1) : 0);
//		for (int j = 0, k = (temp[i][0] = i ? temp[i-1][1] : 1)*2; j < (count - i - 1); k *= (++j + 2))
//			temp[i][j+1] = k += (i ? temp[i-1][j+2] * (j + 2) : 0);
//	}
//	
//	return temp[count-1][0];
//}

int tan_zigzag_number(int count)
{
	int **temp = new int*[count];
	
	for (int i = 0; i < count; i++) {
		temp[i] = new int[i+1];
		for (int j = 0, k = (temp[i][0] = i ? temp[i-1][1] : 1)*2; j < (count - i - 1); k *= (++j + 2))
			temp[i][j+1] = k += (i ? temp[i-1][j+2] * (j + 2) : 0);
	}
	
	return temp[count-1][0];
}

int tan_zigzag_number_speed(int count)
{
	int **temp = new int*[count];
	temp[0] = new int[1];
	for (int j = 0, k = (temp[0][0] = 1)*2; j < (count - 1); k *= (++j + 2))
		temp[0][j+1] = k;
	for (int i = 1; i < count; i++) {
		temp[i] = new int[i+1];
		for (int j = 0, k = (temp[i][0] = temp[i-1][1]) * 2; j < (count - i - 1); k *= (++j + 2))
			temp[i][j+1] = k += temp[i-1][j+2] * (j + 2);
	}
	return temp[count-1][0];
}

int tan_zigzag_numberk(int count)
{
	int **temp = (int **) malloc (sizeof(int *) * count);
	int ret;
	for (int i = 0; i < count; i++) {
		temp[i] = (int *) malloc (sizeof(int) * (i+1));
		for (int j = 0, k = (temp[i][0] = i ? temp[i-1][1] : 1)*2; j < (count - i - 1); k *= (++j + 2))
			temp[i][j+1] = k += (i ? temp[i-1][j+2] * (j + 2) : 0);
	}
	ret = temp[count - 1][0];
	free(temp);
	return ret;
}

int tan_zigzag_numberk_speed(int count)
{
	int **temp = (int **) malloc (sizeof(int *) * count);
	int ret;
	temp[0] = (int *) malloc (sizeof(int) * (1));
	for (int j = 0, k = (temp[0][0] = 1)*2; j < (count - 1); k *= (++j + 2))
		temp[0][j+1] = k;
	for (int i = 1; i < count; i++) {
		temp[i] = (int *) malloc (sizeof(int) * (i+1));
		for (int j = 0, k = (temp[i][0] = temp[i-1][1]) * 2; j < (count - i - 1); k *= (++j + 2))
			temp[i][j+1] = k += temp[i-1][j+2] * (j + 2);
	}
	ret = temp[count - 1][0];
	free(temp);
	return ret;
}

int main(int argc, char *argv[])
{
	/*long double x = 1000000;
	typedef std::numeric_limits< double > dbl;
	cout.precision(dbl::digits10);
	for (int i = 0; i < 40 ; i++)
	{
		cout << x << endl;
		x = x - (pow(x, 3) - 2) / (3 * pow(x, 2));
	}
	

	cout << tan_zigzag_numberk_speed(7);*/

#ifndef _DEBUG
	if (argc == 1) {
		cout << "잘못된 접근입니다." << endl;
		return 1;
	} else {
		if (strcmp(argv[1], "ef1287")) {
			cout << "접근 지정첨자가 틀렸습니다." << endl;
			return 1;
		}
	}
#else
	cout << get<1>(_scan::scan_number("265")) << endl;
	cout << get<2>(_scan::scan_number("265.543")) << endl;
	variable_map txxx;
	PVARIABLE txx = _variable::variable_syntax("var abx = 32");
	txxx(txx->varname, txx);
	txx = _variable::variable_syntax("var bcd : int");
	txxx(txx->varname, txx);
	txx = _variable::variable_syntax("var z : int = 6");
	txxx(txx->varname, txx);
	txx = _variable::variable_syntax("var x : int");
	txxx(txx->varname, txx);
	_token::token_syntax("bcd = abx", txxx);
	_token::token_syntax("x = bcd+2", txxx);
	_token::token_syntax("x *= abx+2", txxx);
	cout << "var abx = 32" << endl;
	cout << "var bcd : int" << endl;
	cout << "var x : int" << endl;
	cout << "bcd = abx" << endl;
	cout << "x = abx" << endl;
	cout << "x *= abx+2" << endl;
	cout << "----------------result-------------------" << endl;
	cout << "abx = " << txxx["abx"]->idata << endl;
	cout << "bcd = " << txxx["bcd"]->idata << endl;
	cout << "x = " << txxx["x"]->idata << endl;
	
	std::vector<std::string> fdt;
	fdt.push_back("func.src");
	fdt.push_back("var z : int = 6");
	fdt.push_back("var y : int = 6");
	fdt.push_back("z += y");
	
	run_sst(fdt, false);
#endif

	std::vector<std::string> file_data;
	cout << "Swift Script Tester [Version 0.0.1016.11]" << endl << 
			"(c) 2014 RollRat. All rights reserved." << endl << endl;
	
	char *command_input = (char *) malloc (256);
	for(;;) {
		cout << "> ";
		in_command(command_input);
		vector<string> vec_str_cmd;
		get_command_line(vec_str_cmd, command_input);
		
		if (vec_str_cmd[0] == "set") {
			if (vec_str_cmd.size() > 2) {
				if (vec_str_cmd[1] == "file") {
					std::ifstream inf(vec_str_cmd[2], std::ios::in);
					if (inf.fail()) {
						std::cerr << "Error : " << std::endl <<
							"Unable to open file for reading!" << std::endl;
						continue;
					}

					file_data.clear();
					while(!inf.eof())
					{
						char size_f[256];
						inf.getline(size_f, 256);
						file_data.push_back(size_f);
					}

					inf.close();
				}
			}
		} else if (vec_str_cmd[0] == "run") {
			bool run_debug = false;
			if (file_data.size() == 0) {
				cout << "파일을 먼저 불러오십시오." << endl;
				continue;
			} else if (vec_str_cmd.size() > 1) {
				if (vec_str_cmd[1] == "-debug")
					run_debug = true;
			}
			run_sst(file_data, run_debug);
		} else if (vec_str_cmd[0] == "info") {
			if (vec_str_cmd.size() > 1) {
				if (vec_str_cmd[1] == "variable") {
					cout << "변수 Int, String, None, Variable구현, Array 형태만구현" << endl;
				}
			}
		}
	}

	return 0;
}