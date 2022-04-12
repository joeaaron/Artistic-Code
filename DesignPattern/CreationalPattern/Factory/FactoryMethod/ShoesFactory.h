#pragma once
/****************************************************************
//  File name:		ShoesFactory.h
//  Author:			TPAN
//  Version:		1.0.0
//  Date:			2021/12/2
//  Description:	ShoesFactory抽象工厂类，提供了创建具体鞋子产品的纯虚函数。
					NiKeProducer、AdidasProducer、LiNingProducer具体工厂类，继承持续工厂类，实现对应具体鞋子产品对象的创建。
//  History:
//	<author>	<date>		<version>	<desc>
//	TPAN		2021/12/2	1.0.0		build this module
****************************************************************/
#include "Shoes.h"

// 总鞋厂
class ShoesFactory
{
public:
	virtual Shoes *CreateShoes() = 0;
	virtual ~ShoesFactory() {}
};

// 耐克生产者/生产链
class NiKeProducer : public ShoesFactory
{
public:
	Shoes *CreateShoes()
	{
		return new NiKeShoes();
	}
};

// 阿迪达斯生产者/生产链
class AdidasProducer : public ShoesFactory
{
public:
	Shoes *CreateShoes()
	{
		return new AdidasShoes();
	}
};

// 李宁生产者/生产链
class LiNingProducer : public ShoesFactory
{
public:
	Shoes *CreateShoes()
	{
		return new LiNingShoes();
	}
};

