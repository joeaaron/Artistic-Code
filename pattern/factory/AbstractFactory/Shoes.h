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

// ���� �·�
class Clothe
{
public:
	virtual void Show() = 0;
	virtual ~Clothe() {}
};

// �Ϳ��·�
class NiKeClothe : public Clothe
{
public:
	void Show()
	{
		std::cout << "�����Ϳ��·���ʱ���������У�" << std::endl;
	}
};

// ���� 
class Shoes
{
public:
	virtual void Show() = 0;
	virtual ~Shoes() {}
};

// �Ϳ�Ь��
class NiKeShoes : public Shoes
{
public:
	void Show()
	{
		std::cout << "�����Ϳ���Ь�������������" << std::endl;
	}
};

