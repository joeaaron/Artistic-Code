#pragma once
#include <iostream>
class HandsetSoft
{
public:
	virtual ~HandsetSoft() {}
	virtual void run() = 0;
};
// ��Ϸ
class HandsetGame : public HandsetSoft
{
public:
	void run() { std::cout << "run HandsetGame" << std::endl; }
};
// ͨѶ¼
class HandsetAddressList : public HandsetSoft
{
public:
	void run() { std::cout << "run HandsetAddressList" << std::endl; }
};