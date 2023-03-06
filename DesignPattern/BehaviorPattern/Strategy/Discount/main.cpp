#include "consume.h"

int main()
{
	Consume member;
	member.AddProduct("cola", 10);
	member.AddProduct("hamburger", 20);
	member.AddProduct("frenchfries", 15);

	double price = member.GetTotalPrice();
	std::cout << "共需支付 : " << price << std::endl;

	member.UpdateUser("Member");
	price = member.GetTotalPrice();
	std::cout << "共需支付 : " << price << std::endl;
	return 0;
}