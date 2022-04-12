#include "Shoes.h"
#include "ShoesFactory.h"

int main()
{
	// 构造耐克鞋的工厂对象
	ConcreteFactory<Shoes, NiKeShoes> nikeFactory;
	// 创建耐克鞋
	Shoes *pNiKeShoes = nikeFactory.CreateProduct();
	// 打印耐克鞋广告语
	pNiKeShoes->Show();

	// 构造优衣库衣服的工厂对象
	ConcreteFactory<Clothe, UniqloClothe> uniqloFactory;
	// 创建优衣库衣服对象
	Clothe *pUniqloClothe = uniqloFactory.CreateProduct();
	// 打印优衣库广告语
	pUniqloClothe->Show();

	// 释放资源
	delete pNiKeShoes;
	pNiKeShoes = NULL;

	delete pUniqloClothe;
	pUniqloClothe = NULL;

	return 0;
}
