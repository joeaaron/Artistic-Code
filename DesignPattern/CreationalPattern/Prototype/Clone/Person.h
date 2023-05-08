#pragma once
#include <string>

class Person
{
public:
	Person() :m_year(0), m_name("") {}
	virtual ~Person() {}

	virtual Person *clone() { return new Person(*this); }

	void SetYear(int year) { m_year = year; }
	int GetYear() { return m_year; }

	void SetName(std::string name) { m_name = name; }
	std::string GetName() { return m_name; }

private:
	int m_year;
	std::string m_name;
};