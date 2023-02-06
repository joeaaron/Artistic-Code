#include <vector>
#include <string>
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

struct IRelationshipBrowser
{
	virtual std::vector<Person> FindAllChildrenOf(const std::string& strName) = 0;
};

struct Relationships : IRelationshipBrowser {	// Low-level <<<<<<<<<<<<-------------------------
	std::vector <std::tuple<Person, RELATIONSHIOP, Person >> m_relations;

	void AddParentAndChild(const Person &parent, const Person &child)
	{
		m_relations.push_back({ parent, RELATIONSHIOP::eParent, child });
		m_relations.push_back({ child, RELATIONSHIOP::eChild, parent });
	}

	std::vector<Person> FindAllChildrenOf(const std::string& strName)
	{
		std::vector<Person> result;
		for (auto &iter : m_relations)
		{
			auto firstName = std::get<0>(iter);
			auto rel = std::get<1>(iter);
			auto secondName = std::get<2>(iter);

			if (firstName.m_strName == strName &&  rel == RELATIONSHIOP::eParent)
			{
				result.push_back(secondName);
			}
		}

		return result;
	}
};

struct Research {                                // High-level <<<<<<<<<<<<<<<----------------------
	Research(IRelationshipBrowser &browser) {
		for (auto &child : browser.FindAllChildrenOf("John")) {
			std::cout << "John has a child called " << child.m_strName << std::endl;
		}
	}
	//  Research(const Relationships& relationships)
	//  {
	//    auto& relations = relationships.relations;
	//    for (auto&& [first, rel, second] : relations)
	//    {
	//      if (first.name == "John" && rel == Relationship::parent)
	//      {
	//        cout << "John has a child called " << second.name << endl;
	//      }
	//    }
	//  }
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