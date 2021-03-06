#pragma once
/****************************************************************
//  File name:		ShoesFactory.h
//  Author:			TPAN
//  Version:		1.0.0
//  Date:			2021/12/6
//  Description:	AbstractFactory为抽象模板工厂类，其中模板参数：AbstractProduct_t 产品抽象类，如Shoes、Clothe
					ConcreteFactory为具体模板工厂类，其中模板参数：AbstractProduct_t 产品抽象类（如Shoes、Clothe），ConcreteProduct_t 产品具体类（如NiKeShoes、UniqloClothe）
//  History:
//	<author>	<date>		<version>	<desc>
//	TPAN		2021/12/6	1.0.0		build this module
****************************************************************/
//#include "Shoes.h"

// 抽象模板工厂类
// 模板参数: AbstractProduct_t 产品抽象类
template <class AbstractProduct_t>
class AbstractFactory
{
public:
	virtual AbstractProduct_t *CreateProduct() = 0;
	virtual ~AbstractFactory(){}
};

// 具体模板工厂类
// 模板参数：AbstractProduct_t 产品抽象类，ConcreteProduct_t 产品具体类
template <class AbstractProduct_t, class ConcreteProduct_t>
class ConcreteFactory : public AbstractFactory<AbstractProduct_t>
{
public:
	AbstractProduct_t *CreateProduct()
	{
		return new ConcreteProduct_t();
	}
};
