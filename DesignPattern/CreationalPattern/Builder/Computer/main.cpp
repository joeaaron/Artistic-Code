#include <iostream>
#include "Director.h"

using namespace std;

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){ delete p; p=nullptr;} }
#endif

int main()
{
	Director director;

	Builder6666 build6666;
	Builder11199 build11199;

	director.BuildUp(build6666);
	director.BuildUp(build11199);

	Computer *computer6666 = build6666.GetComputer();
	Computer *computer11199 = build11199.GetComputer();

	computer6666->Show();
	computer11199->Show();

	SAFE_DELETE(computer6666);
	SAFE_DELETE(computer11199);

	return 0;
}