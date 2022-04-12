#include "Shoes.h"
#include "ShoesFactory.h"

int main()
{
	// ========================== 生产耐克球鞋过程 ===========================//
	// 注册产品种类为Shoes（基类），产品为NiKe（子类）到工厂，产品名为nike
	ProductRegistrar<Shoes, NikeShoes> nikeShoes("nike");
	// 从工厂获取产品种类为Shoes，名称为nike的产品对象
	Shoes *pNikeShoes = ProductFactory<Shoes>::Instance().GetProduct("nike");

	if (pNikeShoes != nullptr)
	{
		// 显示产品的广告语
		pNikeShoes->Show();
		// 释放资源
		if (pNikeShoes)
		{
			delete pNikeShoes;
		}
	}

	// ========================== 生产优衣库衣服过程 ===========================//
  // 注册产品种类为Clothe（基类），产品为UniqloClothe（子类）到工厂，产品名为uniqlo
	ProductRegistrar<Clothe, UniqloClothe> uniqloShoes("uniqlo");
	// 从工厂获取产品种类为Shoes，名称为adidas的产品对象
	Clothe *pUniqloClothe = ProductFactory<Clothe>::Instance().GetProduct("uniqlo");
	// 显示产品的广告语
	pUniqloClothe->Show();
	// 释放资源
	if (pUniqloClothe)
	{
		delete pUniqloClothe;
	}


	return 0;
}
