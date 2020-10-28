#include <iostream>
#include "stringexpression.h"

using namespace std;
using namespace algolib;

int main()
{
    std::string expressionQ("A+(B*C-(D/E^F)*G)*H");

	auto expressionP = GetPostfixFromInfix(expressionQ);

	for (auto& e : expressionP)
		cout << e << ' ';
    cout << endl;
}