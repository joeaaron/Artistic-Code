#pragma once
#include <iostream>

class Milktea
{
public:
	virtual ~Milktea() {}
	virtual void drink() {}
};

class PearlMilktea : public Milktea
{
public:
	virtual void drink() {
		std::cout << "ÕäÖéÄÌ²è" << std::endl;
	}
};