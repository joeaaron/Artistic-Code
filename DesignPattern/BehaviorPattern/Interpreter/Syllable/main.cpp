#include "abstractExpression.h"

int main()
{
	TerminalExpression a;
	std::string context = "1 1 | 3 1/8 | 4 1/2";

	std::list<std::string> split_result = split(context, "|");
	for (auto text : split_result)
		std::cout << a.Interpret(text) << " ";

	return 0;
}