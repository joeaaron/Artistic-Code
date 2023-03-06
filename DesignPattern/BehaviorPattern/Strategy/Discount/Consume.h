#pragma once
#include <string>
#include <iostream>

#include "Discount.h"

#define SAFE_DELETE(p) if(p){ delete p; p=nullptr;}
class Consume
{
public:
	Consume(std::string strUser = "") : 
		m_discount(nullptr),
		m_dRealPrice(0)
	{
		GetDiscount(strUser);
	}

	~Consume() { SAFE_DELETE(m_discount); }

	void UpdateUser(std::string user)
	{
		SAFE_DELETE(m_discount);
		GetDiscount(user);
	}

	void AddProduct(std::string name, int price) 
	{
		m_dRealPrice += price;
		std::cout << "添加了新的商品 " << name << " 价格为 " << price << " 目前总价为 " << m_dRealPrice << std::endl;
	}

	double GetTotalPrice() 
	{
		return m_discount->PriceAfterDiscount(m_dRealPrice);
	}

private:
	void GetDiscount(std::string user) 
	{
		if (user == "NewCustomers")
			m_discount = new NewCustomersDiscount;
		else if (user == "Member")
			m_discount = new MemberDiscount;
		else
			m_discount = new Discount;
	}

private:
	Discount *m_discount;
	double m_dRealPrice;
};
