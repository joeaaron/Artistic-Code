#pragma once

#include "ConcreteFlyweight.h"
#include <map>

class PlayerFactory
{
public:
	static IPlayer* GetPlayer(std::string strType)
	{
		IPlayer *player = nullptr;
		if (m_map.find(strType) != m_map.end())
		{
			player = m_map[strType];
		}
		else
		{
			// 创建 T/CT 对象
			if (strType == "T") 
			{
				std::cout << "Terrorist Created" << std::endl;
				player = new Terrorist();
			}
			else if (strType == "CT") 
			{
				std::cout << "Counter Terrorist Created" << std::endl;
				player = new CounterTerrorist();
			}
			else 
			{
				std::cout << "Unreachable code!" << std::endl;
			}
			// 一旦创建，将其插入到 map 中
			m_map.insert(std::make_pair(strType, player));
		}

		return player;
	}

private:
	// 存储 T/CT 对象（享元池）
	static std::map<std::string, IPlayer*> m_map;
};