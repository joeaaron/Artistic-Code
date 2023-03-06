#pragma once

class IObserver
{
public:
	virtual ~IObserver() {};
	virtual void Update(const std::string &msg) = 0;
	virtual std::string GetName() = 0;
};

class ISubject
{
public:
	virtual ~ISubject() {};
	virtual void Attach(IObserver *) = 0;
	virtual void Detach(IObserver *) = 0;
	virtual void Notify(const std::string& strMsgs) = 0;
};