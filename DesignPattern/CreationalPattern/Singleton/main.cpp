#include "Shoes.h"
#include "ShoesFactory.h"

int main()
{
	// �����Ϳ�Ь�Ĺ�������
	ConcreteFactory<Shoes, NiKeShoes> nikeFactory;
	// �����Ϳ�Ь
	Shoes *pNiKeShoes = nikeFactory.CreateProduct();
	// ��ӡ�Ϳ�Ь�����
	pNiKeShoes->Show();

	// �������¿��·��Ĺ�������
	ConcreteFactory<Clothe, UniqloClothe> uniqloFactory;
	// �������¿��·�����
	Clothe *pUniqloClothe = uniqloFactory.CreateProduct();
	// ��ӡ���¿�����
	pUniqloClothe->Show();

	// �ͷ���Դ
	delete pNiKeShoes;
	pNiKeShoes = NULL;

	delete pUniqloClothe;
	pUniqloClothe = NULL;

	return 0;
}
