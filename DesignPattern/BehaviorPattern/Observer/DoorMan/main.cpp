#include "ConcreteSubject.h"
#include "ConcreteObserver.h"

int main()
{
	ConcreteSubject doorman{};

	ConcreteObserverA employeeA{};
	ConcreteObserverB employeeB{};

	doorman.Attach(&employeeA);
	doorman.Attach(&employeeB);

	doorman.ModifyStatus("Xiao Zhang is late");
	doorman.ModifyStatus("Boss is coming");

	return 0;
}