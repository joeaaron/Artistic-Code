#pragma once
/****************************************************************
//  File name:		ShoesFactory.h
//  Author:			TPAN
//  Version:		1.0.0
//  Date:			2021/12/1
//  Description:	FactoryΪ���󹤳����ṩ�˴���Ь��CreateShoes()���·���ƷCreateClothe()����Ľӿڡ�
					NiKeProducerΪ���幤����ʵ���˴����Ϳ�Ь�Ӻ��Ϳ��·��ķ�ʽ��
//  History:
//	<author>	<date>		<version>	<desc>
//	TPAN		2021/12/2	1.0.0		build this module
****************************************************************/
#include "Shoes.h"

// �ܳ�
class Factory
{
public:
	virtual Shoes *CreateShoes() = 0;
	virtual Clothe *CreateClothe() = 0;
	virtual ~Factory() {}
};

// �Ϳ�������/������
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
