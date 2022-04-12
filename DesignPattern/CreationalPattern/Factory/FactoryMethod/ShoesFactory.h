#pragma once
/****************************************************************
//  File name:		ShoesFactory.h
//  Author:			TPAN
//  Version:		1.0.0
//  Date:			2021/12/2
//  Description:	ShoesFactory���󹤳��࣬�ṩ�˴�������Ь�Ӳ�Ʒ�Ĵ��麯����
					NiKeProducer��AdidasProducer��LiNingProducer���幤���࣬�̳г��������࣬ʵ�ֶ�Ӧ����Ь�Ӳ�Ʒ����Ĵ�����
//  History:
//	<author>	<date>		<version>	<desc>
//	TPAN		2021/12/2	1.0.0		build this module
****************************************************************/
#include "Shoes.h"

// ��Ь��
class ShoesFactory
{
public:
	virtual Shoes *CreateShoes() = 0;
	virtual ~ShoesFactory() {}
};

// �Ϳ�������/������
class NiKeProducer : public ShoesFactory
{
public:
	Shoes *CreateShoes()
	{
		return new NiKeShoes();
	}
};

// ���ϴ�˹������/������
class AdidasProducer : public ShoesFactory
{
public:
	Shoes *CreateShoes()
	{
		return new AdidasShoes();
	}
};

// ����������/������
class LiNingProducer : public ShoesFactory
{
public:
	Shoes *CreateShoes()
	{
		return new LiNingShoes();
	}
};

