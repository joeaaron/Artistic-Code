#pragma once
/****************************************************************
//  File name:		Shoes.h
//  Author:			TPAN
//  Version:		1.0.0
//  Date:			2021/12/6
//  Description:	Shoes��Clothe���ֱ�ΪЬ�Ӻ��·��ĳ����ࣨ���ࣩ
					NiKeShoes��UniqloClothe���ֱ�Ϊ�Ϳ�Ь�Ӻ����¿��·������Ʒ�ࡣ
//  History:
//	<author>	<date>		<version>	<desc>
//	TPAN		2021/12/6	1.0.0		build this module
****************************************************************/
#include<iostream>

// ���� Ь��
class Shoes
{
public:
	virtual void Show() = 0;
	virtual ~Shoes() {}
};

// �Ϳ�Ь��
class NikeShoes : public Shoes
{
public:
	void Show()
	{
		std::cout << "�����Ϳ���Ь���ҵĹ���Just do it" << std::endl;
	}
};

// ���� �·�
class Clothe
{
public:
	virtual void Show() = 0;
	virtual ~Clothe() {}
};

// ���¿��·�
class UniqloClothe : public Clothe
{
public:
	void Show()
	{
		std::cout << "�������¿��·����ҵĹ���I am Uniqlo" << std::endl;
	}
};

