#include <string>
#include <vector>
#include <tuple>
#include <iostream>

enum class RELATIONSHIOP : unsigned int
{
	eParent = 0,
	eChild,
	eSibling
};

struct Person
{
	std::string m_strName;
};

struct Relationships {      // Low-level <<<<<<<<<<<<-------------------------
	std::vector <std::tuple<Person, RELATIONSHIOP, Person >> m_relations;

	void AddParentAndChild(const Person &parent, const Person &child) {
		m_relations.push_back({ parent, RELATIONSHIOP::eParent, child });
		m_relations.push_back({ child, RELATIONSHIOP::eChild, parent });
	}
};

struct Research {           // High-level  <<<<<<<<<<<<------------------------
	Research(const Relationships &relationships) {
		//for (auto && [first, rel, second] : relationships.m_relations) {// Need C++17 here
		//	if (first.m_strName == "John" && rel == RELATIONSHIOP::eParent)
		//		std::cout << "John has a child called " << second.m_strName << std::endl;
		//}

		for (auto &iter : relationships.m_relations)
		{
			auto firstName = std::get<0>(iter).m_strName;
			auto rel = std::get<1>(iter);
			auto secondName = std::get<2>(iter).m_strName;

			if (firstName == "John" &&  rel == RELATIONSHIOP::eParent)
			{
				std::cout << "John has a child called " << secondName << std::endl;
			}
		}
	}
};

int main() {
	Person parent{ "John" };
	Person child1{ "Chris" };
	Person child2{ "Matt" };

	Relationships relationships;
	relationships.AddParentAndChild(parent, child1);
	relationships.AddParentAndChild(parent, child2);

	Research _(relationships);

	return EXIT_SUCCESS;
}