#pragma once
/****************************************************************
//  File name:		ShoesFactory.h
//  Author:			TPAN
//  Version:		1.0.0
//  Date:			2021/12/1
//  Description:	Factory为抽象工厂，提供了创建鞋子CreateShoes()和衣服产品CreateClothe()对象的接口。
					NiKeProducer为具体工厂，实现了创建耐克鞋子和耐克衣服的方式。
//  History:
//	<author>	<date>		<version>	<desc>
//	TPAN		2021/12/2	1.0.0		build this module
****************************************************************/
#include "Shoes.h"

// 总厂
class Factory
{
public:
	virtual Shoes *CreateShoes() = 0;
	virtual Clothe *CreateClothe() = 0;
	virtual ~Factory() {}
};

// 耐克生产者/生产链
class NiKeProducer : public Factory
{
public:
	Shoes *CreateShoes()
	{
		return new NiKeShoes();
	}

	Clothe *CreateClothe()
	{
		return new NiKeClothe();
	}
};
