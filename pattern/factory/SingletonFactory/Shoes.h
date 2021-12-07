#pragma once
/****************************************************************
//  File name:		Shoes.h
//  Author:			TPAN
//  Version:		1.0.0
//  Date:			2021/12/6
//  Description:	Shoes和Clothe，分别为鞋子和衣服的抽象类（基类）
					NiKeShoes和UniqloClothe，分别为耐克鞋子和优衣库衣服具体产品类。
//  History:
//	<author>	<date>		<version>	<desc>
//	TPAN		2021/12/6	1.0.0		build this module
****************************************************************/
#include<iostream>

// 基类 鞋子
class Shoes
{
public:
	virtual void Show() = 0;
	virtual ~Shoes() {}
};

// 耐克鞋子
class NikeShoes : public Shoes
{
public:
	void Show()
	{
		std::cout << "我是耐克球鞋，我的广告语：Just do it" << std::endl;
	}
};

// 基类 衣服
class Clothe
{
public:
	virtual void Show() = 0;
	virtual ~Clothe() {}
};

// 优衣库衣服
class UniqloClothe : public Clothe
{
public:
	void Show()
	{
		std::cout << "我是优衣库衣服，我的广告语：I am Uniqlo" << std::endl;
	}
};

