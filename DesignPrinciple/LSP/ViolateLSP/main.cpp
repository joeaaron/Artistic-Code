#include <iostream>
#include <assert.h>

class Rectangle
{
public:
	Rectangle(const int nWidth, const int nHeight)
		: m_nWidth(nWidth)
		, m_nHeight(nHeight){}

	int GetWidth() const { return m_nWidth; };
	int GetHeight() const { return m_nHeight; };

	virtual void SetWidth(const int nWidth) { this->m_nWidth = nWidth; }
	virtual void SetHeight(const int nHeight) { this->m_nHeight = nHeight; }

	int CalArea() const { return m_nWidth * m_nHeight; }

protected:
	int m_nWidth, m_nHeight;
};

class Square : public Rectangle
{
public:
	Square(int nSize) : Rectangle(nSize, nSize){}
	void SetWidth(const int nWidth) override { this->m_nWidth = m_nHeight = nWidth; }
	void SetHeight(const int nHeight) override { this->m_nHeight = m_nWidth = nHeight; }
};

void Process(Rectangle& r)
{
	int w = r.GetWidth();
	r.SetHeight(10);

	assert((w * 10) == r.CalArea());
}

// Not so good
//void Process(Rectangle& r)
//{
//	int w = r.GetWidth();
//	r.SetHeitht(10);
//
//	if (dynamic_cast<Square*>(&r) != nullptr)
//	{
//		assert((r.GetWidth() * r.GetWidth()) == r.CalArea());
//	}
//	else
//	{
//		assert((w * 10) == r.CalArea());
//	}
//}

int main()
{
	Rectangle r(5, 5);
	Process(r);
	Square s{ 5 };
	Process(s);

	return EXIT_SUCCESS;
}