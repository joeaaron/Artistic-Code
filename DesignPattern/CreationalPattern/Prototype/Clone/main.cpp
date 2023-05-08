#include "Chinese.h"
#include <iostream>

#define SAFE_DELETE(p) { if(p) { delete p; p=nullptr;}}
int main()
{
	std::cout << "��ʼ��ԭʵ���������丳ֵ" << std::endl;
	Chinese *p = new Chinese();
	p->SetYear(30);
	p->SetName("����");
	p->SetCharacter("С׭");
	std::cout << "ԭʵ��  ���䣺" << p->GetYear() << "�� ���ƣ�" << p->GetName() << "�� �鷨��" << p->GetCharacter() << std::endl;

	Person *p2 = p->clone();
	if (auto p3 = dynamic_cast<Chinese*> (p2)) {
		std::cout << "��¡ԭʵ��" << std::endl;
		std::cout << "��¡��  ���䣺" << p3->GetYear() << "�� ���ƣ�" << p3->GetName() << "�� �鷨��" << p3->GetCharacter() << std::endl;

		std::cout << "�Կ�¡�����¸�ֵ" << std::endl;
		p3->SetYear(20);
		p3->SetName("����");
		p3->SetCharacter("����");
		std::cout << "ԭʵ��  ���䣺" << p->GetYear() << "�� ���ƣ�" << p->GetName() << "�� �鷨��" << p->GetCharacter() << std::endl;
		std::cout << "��¡��  ���䣺" << p3->GetYear() << "�� ���ƣ�" << p3->GetName() << "�� �鷨��" << p3->GetCharacter() << std::endl;
	}

	SAFE_DELETE(p);
	SAFE_DELETE(p2);

	return 0;
}