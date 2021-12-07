#pragma once
/****************************************************************
//  File name:		Shoes.h
//  Author:			TPAN
//  Version:		1.0.0
//  Date:			2021/12/2
//  Description:	Clothe和Shoes，分别为衣服和鞋子的抽象产品类。
					NiKeClothe和NiKeShoes，分别是耐克衣服和耐克衣服的具体产品类。
//  History:
//	<author>	<date>		<version>	<desc>
//	TPAN		2021/12/2	1.0.0		build this module
****************************************************************/
#include<iostream>

// 基类 衣服
class Clothe
{
public:
	virtual void Show() = 0;
	virtual ~Clothe() {}
};

// 耐克衣服
class NiKeClothe : public Clothe
{
public:
	void Show()
	{
		std::cout << "我是耐克衣服，时尚我最在行！" << std::endl;
	}
};

// 基类 
class Shoes
{
public:
	virtual void Show() = 0;
	virtual ~Shoes() {}
};

// 耐克鞋子
class NiKeShoes : public Shoes
{
public:
	void Show()
	{
		std::cout << "我是耐克球鞋，让你酷起来！" << std::endl;
	}
};

