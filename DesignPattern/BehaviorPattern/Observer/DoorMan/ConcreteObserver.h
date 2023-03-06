#pragma once
#include <iostream>

#include "AbstractClass.h"

class RoomMate : public IObserver 
{
public:
	RoomMate(std::string name, std::string now, std::string action)
	{
		_name = name;
		_action = action;
		_now = now;
	};
	     
	void Update(const std::string &msg);
	    
	std::string GetName();

private:
	std::string _name;
	std::string _action;
	std::string _now;
};

std::string RoomMate::GetName() 
{
	return _name;
}

void RoomMate::Update(const std::string &msg) 
{
	std::cout << "This is " << _name << std::endl;

	if (msg == "µãÃûÁË")
		std::cout << "Action: " << _action<< std::endl << std::endl;
	else
		 std::cout << "Go on£º" << _now << std::endl << std::endl;
}
