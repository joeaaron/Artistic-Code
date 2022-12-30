#pragma once

#include <iostream>
#include <string>

class IPlayer
{
public:
	virtual ~IPlayer()= default;

	// ·ÖÅäÎäÆ÷
	virtual void AssignWeapon(std::string strWeapon) = 0;

	// Ê¹Ãü
	virtual void Mission() = 0;

protected:
	std::string m_strTask;
	std::string m_strWeapon;
};