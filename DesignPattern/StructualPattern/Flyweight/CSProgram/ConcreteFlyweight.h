#pragma once 

#include "Flyweight.h"

// 恐怖分子
class Terrorist :public IPlayer
{
public:
	Terrorist()
	{
		m_strTask = "Plant a bomb";
	}

	virtual void AssignWeapon(std::string weapon) override 
	{
		m_strWeapon = weapon;
	}

	virtual void Mission() override 
	{
		std::cout << "Terrorist with weapon " + m_strWeapon + "," + " Task is " + m_strTask << std::endl;
	}
};

// 反恐精英
class CounterTerrorist : public IPlayer
{
public:
	CounterTerrorist() {
		m_strTask = "Diffuse bomb";
	}

	virtual void AssignWeapon(std::string weapon) override 
	{
		m_strWeapon = weapon;
	}

	virtual void Mission() override {
		std::cout << "Counter Terrorist with weapon " + m_strWeapon + "," + " Task is " + m_strTask << std::endl;
	}
};