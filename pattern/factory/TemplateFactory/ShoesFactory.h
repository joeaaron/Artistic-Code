#pragma once
/****************************************************************
//  File name:		ShoesFactory.h
//  Author:			TPAN
//  Version:		1.0.0
//  Date:			2021/12/6
//  Description:	AbstractFactoryΪ����ģ�幤���࣬����ģ�������AbstractProduct_t ��Ʒ�����࣬��Shoes��Clothe
					ConcreteFactoryΪ����ģ�幤���࣬����ģ�������AbstractProduct_t ��Ʒ�����ࣨ��Shoes��Clothe����ConcreteProduct_t ��Ʒ�����ࣨ��NiKeShoes��UniqloClothe��
//  History:
//	<author>	<date>		<version>	<desc>
//	TPAN		2021/12/6	1.0.0		build this module
****************************************************************/
//#include "Shoes.h"

// ����ģ�幤����
// ģ�����: AbstractProduct_t ��Ʒ������
template <class AbstractProduct_t>
class AbstractFactory
{
public:
	virtual AbstractProduct_t *CreateProduct() = 0;
	virtual ~AbstractFactory(){}
};

// ����ģ�幤����
// ģ�������AbstractProduct_t ��Ʒ�����࣬ConcreteProduct_t ��Ʒ������
template <class AbstractProduct_t, class ConcreteProduct_t>
class ConcreteFactory : public AbstractFactory<AbstractProduct_t>
{
public:
	AbstractProduct_t *CreateProduct()
	{
		return new ConcreteProduct_t();
	}
};
