#include "component.h"
#include "decorator.h"
#include <iostream>
using namespace std;

#define SAFE_DELETE(p) if(p){delete p; p=nullptr;}

int main()
{
	PearlMilktea *pPearlMilktea = new PearlMilktea();
	pPearlMilktea->drink();

	AddIce *pAddIce = new AddIce(pPearlMilktea);
	pAddIce->drink();

	AddMilkFoam *pAddMilkFoam = new AddMilkFoam(pAddIce);
	pAddMilkFoam->drink();

	SAFE_DELETE(pAddMilkFoam);

	return 0;
}