#include "concreteelement.h"
#include "concretevisitor.h"

#include <list>
#include <iostream>
using namespace std;

template <typename Container>
inline void DeleteAll(const Container &c)
{
	auto begin = c.begin();
	auto end = c.end();
	while (begin != end) {
		delete *begin;
		++begin;
	}
}

int main()
{
	list<Element *> staffs;
	staffs.push_back(new CppDevEngineer("xiaoA"));
	staffs.push_back(new GoDevEngineer("xiaoB"));
	staffs.push_back(new PythonDevEngineer("xiaoC"));

	ProjectA a;
	cout << "��Ŀ A ���� : " << endl;
	for (auto i : staffs) {
		i->accept(&a);
	}

	cout << "-------------------------------" << endl;

	ProjectB b;
	cout << "��Ŀ B ���� : " << endl;
	for (auto i : staffs) {
		i->accept(&b);
	}

	DeleteAll(staffs);
	return 0;
}