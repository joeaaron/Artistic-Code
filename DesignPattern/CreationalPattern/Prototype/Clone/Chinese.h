#include "Person.h"

class Chinese : public Person
{
public:
	Chinese() : Person(), m_character("����") {}
	~Chinese() {}

	void SetCharacter(std::string character) { m_character = character; }
	std::string GetCharacter() { return m_character; }

	virtual Person *clone() { return new Chinese(*this); }

private:
	std::string m_character;   // �鷨����
};