#include "Shoes.h"
#include "ShoesFactory.h"

int main()
{
	// ���칤������
	ShoesFactory shoesFactory;

	// ��Ь�������󴴽����ϴ�˹Ь����
	Shoes *pNikeShoes = shoesFactory.CreateShoes(GeShoesType::estNike);
	if (pNikeShoes != NULL)
	{
		// �Ϳ���Ь��溰��
		pNikeShoes->Show();

		// �ͷ���Դ
		delete pNikeShoes;
		pNikeShoes = NULL;
	}

	// ��Ь�������󴴽����ϴ�˹Ь����
	Shoes *pLiNingShoes = shoesFactory.CreateShoes(GeShoesType::estLiNing);
	if (pLiNingShoes != NULL)
	{
		// ������Ь��溰��
		pLiNingShoes->Show();

		// �ͷ���Դ
		delete pLiNingShoes;
		pLiNingShoes = NULL;
	}

	// ��Ь�������󴴽����ϴ�˹Ь����
	Shoes *pAdidasShoes = shoesFactory.CreateShoes(GeShoesType::estAdidas);
	if (pAdidasShoes != NULL)
	{
		// ���ϴ�˹��Ь��溰��
		pAdidasShoes->Show();

		// �ͷ���Դ
		delete pAdidasShoes;
		pAdidasShoes = NULL;
	}

	return 0;
}
