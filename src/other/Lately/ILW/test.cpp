
#include <iostream>
#include "ilw.h"
#include "dag.h"


int main()
{
	std::wstring ws;
	ws.append(L"rollrat");
	ILW::ErrorHandler eh(ws);

	auto func = []() { };
	ILW::Control::automaton<decltype(func)> str_automaton;
	str_automaton.new_node(func);

}