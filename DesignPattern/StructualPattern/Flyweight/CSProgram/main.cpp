#include "ConcreteFlyweight.h"
#include "FlyweightFactory.h"
#include <ctime>

std::map<std::string, IPlayer*> PlayerFactory::m_map = std::map<std::string, IPlayer*>();

// ������ͺ�����
static std::string strPlayerType[2] = { "T", "CT" };
static std::string strWeapons[4] = { "AK-47", "Maverick", "Gut Knife", "Desert Eagle" };

#define GET_ARRAY_LEN(array, len) {len = (sizeof(array) / sizeof(array[0]));}

int main()
{
	srand((unsigned)time(NULL));

	int nPlayerLen;
	int nWeaponsLen;
	GET_ARRAY_LEN(strPlayerType, nPlayerLen);
	GET_ARRAY_LEN(strWeapons, nWeaponsLen);

	// ���裬��Ϸ����ʮλ���
	for (int i = 0; i < 10; i++) {
		// ��ȡ�����Һ�����
		int typeIndex = rand() % nPlayerLen;
		int weaponIndex = rand() % nWeaponsLen;
		std::string type = strPlayerType[typeIndex];
		std::string weapon = strWeapons[weaponIndex];

		// ��ȡ���
		IPlayer *p = PlayerFactory::GetPlayer(type);

		// ���������������������
		p->AssignWeapon(weapon);

		// �����ȥִ������
		p->Mission();
	}

	return 0;
}