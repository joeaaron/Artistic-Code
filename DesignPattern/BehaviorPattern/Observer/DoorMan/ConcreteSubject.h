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
	void Notify(const std::string& strMsgs);


private:
	std::list<IObserver *> m_ObserverList;
};

void ConcreteSubject::Attach(IObserver *pObserver)
{
	m_ObserverList.emplace_back(pObserver);
}

void ConcreteSubject::Detach(IObserver *pObserver)
{
	if (m_ObserverList.size() > 0)
	{
		m_ObserverList.remove(pObserver);
	}
	
}

void ConcreteSubject::Notify(const std::string& strMsgs)
{
	std::list<IObserver *>::iterator it = m_ObserverList.begin();
	while (it != m_ObserverList.end())
	{
		(*it)->Update(strMsgs);
		++it;
	}
}

