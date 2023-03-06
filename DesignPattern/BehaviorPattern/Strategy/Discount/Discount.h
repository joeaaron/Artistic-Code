#pragma once

// 普通用户 不打折
class Discount {
public:
	virtual ~Discount() {}
	virtual double PriceAfterDiscount(double price) {
		return price;
	}
};

// 新用户 减 10 元
class NewCustomersDiscount :public Discount {
public:
	virtual double PriceAfterDiscount(double price) {
		return price > 10 ? price - 10 : 0;
	}
};

// 会员用户 打 9 折
class MemberDiscount :public Discount {
public:
	virtual double PriceAfterDiscount(double price) {
		return price * 0.9;
	}
};