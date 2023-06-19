#include "context.h"
#include "windows.h"

#include <iostream>
using namespace std;

int main()
{
	Context trafficLights;

	while (true) {
		int wait = trafficLights.Handle();
		cout << "Lighting : " << wait << " second" << endl;
		// Sleep(wait*1000);
		Sleep(1000);
	}

	return 0;
}