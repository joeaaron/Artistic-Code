#include "Shoes.h"
#include "ShoesFactory.h"

int main()
{
	// 构造工厂对象
	ShoesFactory shoesFactory;

	// 从鞋工厂对象创建阿迪达斯鞋对象
	Shoes *pNikeShoes = shoesFactory.CreateShoes(GeShoesType::estNike);
	if (pNikeShoes != NULL)
	{
		// 耐克球鞋广告喊起
		pNikeShoes->Show();

		// 释放资源
		delete pNikeShoes;
		pNikeShoes = NULL;
	}

	// 从鞋工厂对象创建阿迪达斯鞋对象
	Shoes *pLiNingShoes = shoesFactory.CreateShoes(GeShoesType::estLiNing);
	if (pLiNingShoes != NULL)
	{
		// 李宁球鞋广告喊起
		pLiNingShoes->Show();

		// 释放资源
		delete pLiNingShoes;
		pLiNingShoes = NULL;
	}

	// 从鞋工厂对象创建阿迪达斯鞋对象
	Shoes *pAdidasShoes = shoesFactory.CreateShoes(GeShoesType::estAdidas);
	if (pAdidasShoes != NULL)
	{
		// 阿迪达斯球鞋广告喊起
		pAdidasShoes->Show();

		// 释放资源
		delete pAdidasShoes;
		pAdidasShoes = NULL;
	}

	return 0;
}
