#include "Chinese.h"
#include <iostream>

#define SAFE_DELETE(p) { if(p) { delete p; p=nullptr;}}
int main()
{
	std::cout << "初始化原实例，并对其赋值" << std::endl;
	Chinese *p = new Chinese();
	p->SetYear(30);
	p->SetName("张三");
	p->SetCharacter("小篆");
	std::cout << "原实例  年龄：" << p->GetYear() << "， 名称：" << p->GetName() << "， 书法：" << p->GetCharacter() << std::endl;

	Person *p2 = p->clone();
	if (auto p3 = dynamic_cast<Chinese*> (p2)) {
		std::cout << "克隆原实例" << std::endl;
		std::cout << "克隆体  年龄：" << p3->GetYear() << "， 名称：" << p3->GetName() << "， 书法：" << p3->GetCharacter() << std::endl;

		std::cout << "对克隆体重新赋值" << std::endl;
		p3->SetYear(20);
		p3->SetName("李四");
		p3->SetCharacter("隶书");
		std::cout << "原实例  年龄：" << p->GetYear() << "， 名称：" << p->GetName() << "， 书法：" << p->GetCharacter() << std::endl;
		std::cout << "克隆体  年龄：" << p3->GetYear() << "， 名称：" << p3->GetName() << "， 书法：" << p3->GetCharacter() << std::endl;
	}

	SAFE_DELETE(p);
	SAFE_DELETE(p2);

	return 0;
}