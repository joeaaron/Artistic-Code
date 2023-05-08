#pragma once

#include <string>
#include <list>
#include <iostream>

class Computer
{
public:
	void Add(std::string part) { m_module.push_back(part); }
	void SetPrice(int price) { m_price = price; }

	void Show() {
		std::cout << m_price << " �۸�����õ������£� " << std::endl;
		for (auto moudle : m_module)
			std::cout << moudle << std::endl;
	}

private:
	std::list<std::string> m_module;
	int m_price;
};