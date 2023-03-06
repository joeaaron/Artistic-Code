#include "ConcreteSubject.h"
#include "ConcreteObserver.h"

int main()
{
	RoomMate* B = new RoomMate("B",
		"sleeping",
		"get dressed and run to classroom");
	RoomMate* C = new RoomMate("C",
		 "playing games",
		"pay the fee and run to classroom");
	RoomMate* D = new RoomMate("D",
		"shopping with girl friend",
		"go back to school and be worried about girl friend's angry");
	
	ConcreteSubject* pSubject = new ConcreteSubject();
	pSubject->Attach(B);
	pSubject->Attach(C);
	pSubject->Attach(D);
	
	pSubject->Notify("目前没点名");
	pSubject->Notify("点名了");

	return 0;
}