#include "Shoes.h"
#include "ShoesFactory.h"

int main()
{
	// ================ �����Ϳ����� ==================== //
	// Ь�������Ϳ�������
	ShoesFactory *niKeProducer = new NiKeProducer();
	// �Ϳ������߲�����Ь
	Shoes *nikeShoes = niKeProducer->CreateShoes();
	// �Ϳ���Ь��溰��
	nikeShoes->Show();
	// �ͷ���Դ
	delete nikeShoes;
	delete niKeProducer;

	// ================ �������ϴ�˹���� ==================== //
	// Ь�����谢�ϴ�˹������
	ShoesFactory *adidasProducer = new AdidasProducer();
	// ���ϴ�˹�����߲�����Ь
	Shoes *adidasShoes = adidasProducer->CreateShoes();
	// ���ϴ�˹��Ь�㺰��
	adidasShoes->Show();
	// �ͷ���Դ
	delete adidasShoes;
	delete adidasProducer;

	return 0;
}


