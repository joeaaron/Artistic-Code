#include "Shoes.h"
#include "ShoesFactory.h"

int main()
{
	// ========================== �����Ϳ���Ь���� ===========================//
	// ע���Ʒ����ΪShoes�����ࣩ����ƷΪNiKe�����ࣩ����������Ʒ��Ϊnike
	ProductRegistrar<Shoes, NikeShoes> nikeShoes("nike");
	// �ӹ�����ȡ��Ʒ����ΪShoes������Ϊnike�Ĳ�Ʒ����
	Shoes *pNikeShoes = ProductFactory<Shoes>::Instance().GetProduct("nike");

	if (pNikeShoes != nullptr)
	{
		// ��ʾ��Ʒ�Ĺ����
		pNikeShoes->Show();
		// �ͷ���Դ
		if (pNikeShoes)
		{
			delete pNikeShoes;
		}
	}

	// ========================== �������¿��·����� ===========================//
  // ע���Ʒ����ΪClothe�����ࣩ����ƷΪUniqloClothe�����ࣩ����������Ʒ��Ϊuniqlo
	ProductRegistrar<Clothe, UniqloClothe> uniqloShoes("uniqlo");
	// �ӹ�����ȡ��Ʒ����ΪShoes������Ϊadidas�Ĳ�Ʒ����
	Clothe *pUniqloClothe = ProductFactory<Clothe>::Instance().GetProduct("uniqlo");
	// ��ʾ��Ʒ�Ĺ����
	pUniqloClothe->Show();
	// �ͷ���Դ
	if (pUniqloClothe)
	{
		delete pUniqloClothe;
	}


	return 0;
}
