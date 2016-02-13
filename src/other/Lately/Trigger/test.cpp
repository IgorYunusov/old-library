
#include <string>
#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
	/*ellipse<string, string> epse;

	epse.push("r1", "r1_value");
	epse.push("r2", "r2_value");
	epse.push("r3", "r3_value");
	epse.push("r4", "r4_value");

	for (int i = 1; i <= 4; i++) {
		auto e = epse["r" + to_string(i)];
		if (std::get<0>(e))
			cout << std::get<1>(e) << endl;
		else
			cout << "error not found : r" << i << endl;
	}*/
	Matrix<bool> matrix(3, 3);
	//matrix.new_column();
	matrix(1, 3) = true;
	//matrix(2, 3) = true;
	vector<string> x;
	x.push_back("rollrat1");
	x.push_back("rollrat2");
	x.push_back("rollrat3");
	vector<string> y;
	y.push_back("rollrat4");
	y.push_back("rollrat5");
	y.push_back("rollrat6");
	graph<string, string> graphing(matrix,x,y);
	auto _g_queue = graphing.get_this_queue();
	_g_queue.travel([](graph<string, string>::_Circle *str) {cout << str->value << endl; });
	//_g_queue.


	return 0;
}