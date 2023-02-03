#include <iostream>
#include <assert.h>

class IShape
{
public:
	virtual int CalArea() const = 0;
};

class Rectangle : public IShape
{
public:
	Rectangle(const int nWidth, const int nHeight)
		: m_nWidth(nWidth)
		, m_nHeight(nHeight) {}

	int GetWidth() const { return m_nWidth; };
	int GetHeight() const { return m_nHeight; };

	virtual void SetWidth(const int nWidth) { this->m_nWidth = nWidth; }
	virtual void SetHeight(const int nHeight) { this->m_nHeight = nHeight; }

	int CalArea() const override{ return m_nWidth * m_nHeight; }

protected:
	int m_nWidth, m_nHeight;
};

class Square : public IShape
{
public:
	Square(int nSize) : m_nSize(nSize) {}
	void SetSize(int nSize) { this->m_nSize = nSize; }
	int CalArea() const override { return m_nSize * m_nSize; }

private:
	int m_nSize;
};

void Process(IShape& s)
{
	s.CalArea();
}

int main()
{
	Rectangle r(5, 5);
	Process(r);
	Square s{ 5 };
	Process(s);

	return EXIT_SUCCESS;
}