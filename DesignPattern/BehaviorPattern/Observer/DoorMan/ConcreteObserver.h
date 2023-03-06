#pragma once
#include <iostream>

#include "AbstractClass.h"

class ConcreteObserverA : public IObserver
{
public:
	ConcreteObserverA() {}

	void Update()
	{
		std::cout << "Close the live now!";
	}
};

class ConcreteObserverB :public IObserver
{
public:
	ConcreteObserverB() {}

	void Update()
	{
		std::cout << "Put down your mobile phone now!";
	}
};
