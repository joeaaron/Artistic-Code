#include "Shoes.h"
#include "ShoesFactory.h"

int main()
{
	// ================ �����Ϳ����� ==================== //
	// Ь�������Ϳ�������
	Factory *niKeProducer = new NiKeProducer();

	// �Ϳ������߲�����Ь
	Shoes *nikeShoes = niKeProducer->CreateShoes();
	// �Ϳ������߲����·�
	Clothe *nikeClothe = niKeProducer->CreateClothe();

	// �Ϳ���Ь��溰��
	nikeShoes->Show();
	// �Ϳ��·���溰��
	nikeClothe->Show();

	// �ͷ���Դ
	delete nikeShoes;
	delete nikeClothe;
	delete niKeProducer;

	return 0;
}

