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
			// ���� T/CT ����
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
			// һ��������������뵽 map ��
			m_map.insert(std::make_pair(strType, player));
		}

		return player;
	}

private:
	// �洢 T/CT ������Ԫ�أ�
	static std::map<std::string, IPlayer*> m_map;
};