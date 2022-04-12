#pragma once
/****************************************************************
//  File name:		ShoesFactory.h
//  Author:			TPAN
//  Version:		1.0.0
//  Date:			2021/12/6
//  Description:	IProductRegistrarΪ��Ʒע������࣬ģ����� ProductType_t ��ʾ�����ǲ�Ʒ�����ࣨ��Shoes��Clothe����
					�ṩ�˲�Ʒ���󴴽��Ĵ��麯��CreateProduct��
					ProductFactoryΪ����ģ���࣬ģ����� ProductType_t ��ʾ�����ǲ�Ʒ�����ࣨ��Shoes��Clothe����
					���ڱ���ע���Ʒ����std::map�кͻ�ȡ��Ӧ�Ĳ�Ʒ����
					ProductRegistrarΪ��Ʒע��ģ���࣬ģ����� ProductType_t ��ʾ�����ǲ�Ʒ�����ࣨ��Shoes��Clothe����ProductImpl_t ��ʾ�����Ǿ����Ʒ����NikeShoes��UniqloClothe����
					����ע���Ʒ��������ʹ�����Ʒʵ������
//  History:
//	<author>	<date>		<version>	<desc>
//	TPAN		2021/12/6	1.0.0		build this module
****************************************************************/
#include <iostream>
#include <map>
#include <string>

// ���࣬��Ʒע��ģ��ӿ���
// ģ����� ProductType_t ��ʾ�����ǲ�Ʒ������
template <class ProductType_t>
class IProductRegistrar
{
public:
	// ��ȡ��Ʒ�������ӿ�
	virtual ProductType_t *CreateProduct() = 0;

protected:
	// ��ֹ�ⲿ���������, �����"�ڲ�"�������������Ե���
	IProductRegistrar() {}
	virtual ~IProductRegistrar() {}

private:
	// ��ֹ�ⲿ�����͸�ֵ����
	IProductRegistrar(const IProductRegistrar &);
	const IProductRegistrar &operator=(const IProductRegistrar &);
};

// ����ģ���࣬���ڻ�ȡ��ע���Ʒ����
// ģ����� ProductType_t ��ʾ�����ǲ�Ʒ������
template <class ProductType_t>
class ProductFactory
{
public:
	// ��ȡ����������������ʵ����Ψһ��
	static ProductFactory<ProductType_t> &Instance()
	{
		static ProductFactory<ProductType_t> instance;
		return instance;
	}

	// ��Ʒע��
	void RegisterProduct(IProductRegistrar<ProductType_t> *registrar, std::string name)
	{
		m_ProductRegistry[name] = registrar;
	}

	// ��������name, ��ȡ��Ӧ����Ĳ�Ʒ����
	ProductType_t *GetProduct(std::string name)
	{
		// ��map�ҵ��Ѿ�ע����Ĳ�Ʒ�������ز�Ʒ����
		if (m_ProductRegistry.find(name) != m_ProductRegistry.end())
		{
			return m_ProductRegistry[name]->CreateProduct();
		}

		// δע��Ĳ�Ʒ���򱨴�δ�ҵ�
		std::cout << "No product found for " << name << std::endl;

		return NULL;
	}
private:
	// ��ֹ�ⲿ���������
	ProductFactory() {}
	~ProductFactory() {}

	// ��ֹ�ⲿ�����͸�ֵ����
	ProductFactory(const ProductFactory &);
	const ProductFactory &operator=(const ProductFactory &);

	// ����ע����Ĳ�Ʒ��key:��Ʒ���� , value:��Ʒ����
	std::map<std::string, IProductRegistrar<ProductType_t> *> m_ProductRegistry;
};

// ��Ʒע��ģ���࣬���ڴ��������Ʒ�ʹӹ�����ע���Ʒ
// ģ����� ProductType_t ��ʾ�����ǲ�Ʒ�����ࣨ���ࣩ��ProductImpl_t ��ʾ�����Ǿ����Ʒ����Ʒ��������ࣩ
template <class ProductType_t, class ProductImpl_t>
class ProductRegistrar: public IProductRegistrar<ProductType_t>
{
public:
	// ���캯��������ע���Ʒ��������ֻ����ʾ����
	explicit ProductRegistrar(std::string name)
	{
		// ͨ�����������Ѳ�Ʒע�ᵽ����
		ProductFactory<ProductType_t>::Instance().RegisterProduct(this, name);
	}

	// ���������Ʒ����ָ��
	ProductType_t *CreateProduct()
	{
		return new ProductImpl_t();
	}
};