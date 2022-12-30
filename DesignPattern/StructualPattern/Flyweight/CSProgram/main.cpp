#include "ConcreteFlyweight.h"
#include "FlyweightFactory.h"
#include <ctime>

std::map<std::string, IPlayer*> PlayerFactory::m_map = std::map<std::string, IPlayer*>();

// 玩家类型和武器
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

	// 假设，游戏中有十位玩家
	for (int i = 0; i < 10; i++) {
		// 获取随机玩家和武器
		int typeIndex = rand() % nPlayerLen;
		int weaponIndex = rand() % nWeaponsLen;
		std::string type = strPlayerType[typeIndex];
		std::string weapon = strWeapons[weaponIndex];

		// 获取玩家
		IPlayer *p = PlayerFactory::GetPlayer(type);

		// 从武器库中随机分配武器
		p->AssignWeapon(weapon);

		// 派玩家去执行任务
		p->Mission();
	}

	return 0;
}