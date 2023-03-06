#pragma once

// ��ͨ�û� ������
class Discount {
public:
	virtual ~Discount() {}
	virtual double PriceAfterDiscount(double price) {
		return price;
	}
};

// ���û� �� 10 Ԫ
class NewCustomersDiscount :public Discount {
public:
	virtual double PriceAfterDiscount(double price) {
		return price > 10 ? price - 10 : 0;
	}
};

// ��Ա�û� �� 9 ��
class MemberDiscount :public Discount {
public:
	virtual double PriceAfterDiscount(double price) {
		return price * 0.9;
	}
};