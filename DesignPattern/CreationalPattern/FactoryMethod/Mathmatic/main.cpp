#include "Mathmatic.h"
#include <string>

#define SAFE_DELETE(p) { if(p) { delete p; p=nullptr;}}

int main()
{
	double A = 20;
	double B = 0;

	Factory *divFactory = new DivFactory();
	Operation *op = divFactory->CreateOperator();
	op->SetA(A);
	op->SetB(B);
	try {
		std::cout << op->GetResult() << std::endl;
	}
	catch (std::string exception) {
		std::cout << exception << std::endl;
	}

	SAFE_DELETE(op);
	SAFE_DELETE(divFactory)
}