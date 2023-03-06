#pragma once

class IObserver
{
public:
	virtual void Upate() = 0;
};

class ISubject
{
public:
	virtual void Attach(IObserver *) = 0;
	virtual void Detach(IObserver *) = 0;
	virtual void Notify() = 0;
};