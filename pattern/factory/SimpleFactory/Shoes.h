#pragma once
/****************************************************************
//  File name:		Shoes.h
//  Author:			TPAN
//  Version:		1.0.0
//  Date:			2021/12/1
//  Description:	Shoes为鞋子的抽象类（基类），接口函数为Show()，用于显示鞋子广告。
//  History:
//	<author>	<date>		<version>	<desc>
//	TPAN		2021/12/1	1.0.0		build this module
****************************************************************/
#include<iostream>

class Shoes
{
public:
	virtual ~Shoes(){}
	virtual void Show() = 0;
};

// 耐克鞋子
class NiKeShoes : public Shoes
{
public:
	void Show()
	{
		std::cout << "我是耐克球鞋，我的广告语：Just do it" << std::endl;
	}
};

// 阿迪达斯鞋子
class AdidasShoes : public Shoes
{
public:
	void Show()
	{
		std::cout << "我是阿迪达斯球鞋，我的广告语:Impossible is nothing" << std::endl;
	}
};

// 李宁鞋子
class LiNingShoes : public Shoes
{
public:
	void Show()
	{
		std::cout << "我是李宁球鞋，我的广告语：Everything is possible" << std::endl;
	}
};

