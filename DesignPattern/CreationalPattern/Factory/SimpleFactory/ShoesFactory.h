#pragma once
/****************************************************************
//  File name:		ShoesFactory.h
//  Author:			TPAN
//  Version:		1.0.0
//  Date:			2021/12/1
//  Description:	ShoesFactoryΪ�����࣬����ʵ�ָ���Ь�����ʹ�����ӦЬ�Ӳ�Ʒ�����CreateShoes(SHOES_TYPE type)������
//  History:
//	<author>	<date>		<version>	<desc>
//	TPAN		2021/12/1	1.0.0		build this module
****************************************************************/
#include "Shoes.h"

enum class GeShoesType
{
	estNike,
	estLiNing,
	estAdidas
};

class ShoesFactory
{
public:
	Shoes* CreateShoes(GeShoesType type)
	{
		switch (type)
		{
		case GeShoesType::estNike:
			return new NiKeShoes();
			break;
		case GeShoesType::estLiNing:
			return new LiNingShoes();
			break;
		case GeShoesType::estAdidas:
			return new AdidasShoes();
			break;
		default:
			return NULL;
			break;
		}
	}
};