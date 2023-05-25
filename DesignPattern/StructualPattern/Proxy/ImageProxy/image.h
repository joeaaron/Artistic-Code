#pragma once
#include <iostream>

class Graphic {
public:
	virtual ~Graphic() {}
	virtual void Draw() = 0;
};

class Image :public Graphic
{
public:
	Image(std::string filepath) :m_filepath(filepath) {}
	~Image() {}

	std::string getFilePath() { return m_filepath; }
	void Draw() { std::cout << "Draw Image" << std::endl; }
private:
	std::string m_filepath;
};

class ImageProxy : public Graphic
{
public:
	ImageProxy(std::string filpath) : m_image(nullptr), m_filepath(filpath) {}
	~ImageProxy() { delete m_image; }

	std::string getFilePath() { return m_filepath; }
	void Draw() { GetImage()->Draw(); }
protected:
	Image* GetImage() {
		if (!m_image)
			m_image = new Image(m_filepath);
		return m_image;
	}
private:
	Image *m_image;
	std::string m_filepath;
};
