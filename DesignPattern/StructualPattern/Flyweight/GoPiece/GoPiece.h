#pragma once

#include <iostream>
#include <string>
#include <map>

#define SAFE_DELETE(p) { if(p) { delete (p); (p)=NULL; } }

class IGoPiece
{
public:
	IGoPiece(std::string strColor) : m_strColor(strColor){}

	virtual ~IGoPiece(){}

	virtual void MoveTo(std::string strPerson, int nX, int nY) = 0;

private:
	std::string m_strColor;
};

class WhiteGoPiece : public IGoPiece
{
public:
	WhiteGoPiece() : IGoPiece("white") {}

	virtual void MoveTo(std::string strPerson, int nX, int nY)
	{
		std::cout << strPerson << " 将白色棋子放置在: (" << nX << "," << nY << ")" << std::endl;
	}
};

class BlackGoPiece : public IGoPiece
{
public:
	BlackGoPiece() : IGoPiece("black") {}

	virtual void MoveTo(std::string strPerson, int nX, int nY)
	{
		std::cout << strPerson << " 将黑色棋子放置在: (" << nX << "," << nY << ")" << std::endl;
	}
};

class GoPieceFactory
{
public:
	IGoPiece* GetGoPiece(std::string strColor)
	{
		if (m_goPiece.find(strColor) != m_goPiece.end())
		{
			return m_goPiece[strColor];
		}
		else
		{
			IGoPiece* goPiece = nullptr;
			if (strColor == "black")
			{
				goPiece = new BlackGoPiece();
			}
			else
			{
				goPiece = new WhiteGoPiece();
			}

			m_goPiece.insert({ strColor, goPiece });

			return goPiece;
		}
	}

	~GoPieceFactory() {
		for (auto iter = m_goPiece.begin(); iter != m_goPiece.end(); iter++)
		{
			auto piece = iter->second;
			SAFE_DELETE(piece);
		}
		m_goPiece.clear();
	}

private:
	std::map<std::string, IGoPiece*> m_goPiece;
};