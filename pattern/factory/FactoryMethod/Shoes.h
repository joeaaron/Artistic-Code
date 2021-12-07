#pragma once
/****************************************************************
//  File name:		Shoes.h
//  Author:			TPAN
//  Version:		1.0.0
//  Date:			2021/12/2
//  Description:	Clothe��Shoes���ֱ�Ϊ�·���Ь�ӵĳ����Ʒ�ࡣ
					NiKeClothe��NiKeShoes���ֱ����Ϳ��·����Ϳ��·��ľ����Ʒ�ࡣ
//  History:
//	<author>	<date>		<version>	<desc>
//	TPAN		2021/12/2	1.0.0		build this module
****************************************************************/
#include<iostream>

#include<iostream>

class Shoes
{
public:
	virtual ~Shoes() {}
	virtual void Show() = 0;
};

// �Ϳ�Ь��
class NiKeShoes : public Shoes
{
public:
	void Show()
	{
		std::cout << "�����Ϳ���Ь���ҵĹ���Just do it" << std::endl;
	}
};

// ���ϴ�˹Ь��
class AdidasShoes : public Shoes
{
public:
	void Show()
	{
		std::cout << "���ǰ��ϴ�˹��Ь���ҵĹ����:Impossible is nothing" << std::endl;
	}
};

// ����Ь��
class LiNingShoes : public Shoes
{
public:
	void Show()
	{
		std::cout << "����������Ь���ҵĹ���Everything is possible" << std::endl;
	}
};


