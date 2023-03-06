#pragma once
#include <string>
#include <list>
#include <iostream>

#include "AbstractClass.h"

class ConcreteSubject :public ISubject
{
public:
	void Attach(IObserver *pObserver);
	void Detach(IObserver *pObserver);
	void Notify();

	void ModifyStatus(std::string strStatus);

private:
	std::list<IObserver *> m_ObserverList;
};

void ConcreteSubject::Attach(IObserver *pObserver)
{
	m_ObserverList.emplace_back(pObserver);
}

void ConcreteSubject::Detach(IObserver *pObserver)
{
	m_ObserverList.remove(pObserver);
}

void ConcreteSubject::Notify()
{
	std::list<IObserver *>::iterator it = m_ObserverList.begin();
	while (it != m_ObserverList.end())
	{
		(*it)->Upate();
		++it;
	}
}

void ConcreteSubject::ModifyStatus(std::string strStatus)
{
	if (strStatus == "Boss is coming")
	{
		std::cout << "Boss is coming, please notify!";
		Notify();
	}
	else
	{
		std::cout << strStatus << ", not the Boss, don't notify!";
	}
}