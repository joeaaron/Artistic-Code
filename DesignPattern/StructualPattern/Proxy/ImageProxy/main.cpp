//��ҳ��һƪͼ�Ľ�ϵ����£�����������ر���ͼƬ(�����Ŀ����ر��), 
//������ҳ����ƪ���µ�ʱ������Ҫ��֤��ҳ�Ĵ��ٶȣ����ܵ�ͼƬ���������֮����������ʾ; 
//����һ����������û�û���Ķ���ͼƬ��ʱ��͹ر�����ҳ������ͼƬ�Եþͺ��˷�
//
//����ֻ�е������Ķ���ͼ���ʱ��ͼƬ����Ҫ�������س��������Ǵ���ҳ��ʱ����������Ҫ����һ��ͼ��Ķ���
//���������һЩ����²�ֱ��ʵ����ͼ���ԭ������ʹ��һ��������󣬴���������ͼ��
//���Ҵ����б���ͼ��ĳߴ���Ϣ���ṩ����ҳͼƬ���µ�������Ϣ��
//���ͬʱ����������и�ԭͼ�������һ���Ľӿڣ�ֻ�е�ǰ�˵��ô���� Draw ����ʾͼ���ʱ�򣬴������������ͼ��
//���ҽ���������ת�������ͼ�����

#include "image.h"

#define UNUSED(x) (void)x;
using namespace std;

class ImagePtr
{
public:
	ImagePtr(std::string filpath) : m_image(nullptr), m_filepath(filpath) {}
	virtual ~ImagePtr() { delete m_image; }

	virtual Image* operator ->() { return LoadImage(); }
	virtual Image& operator *() { return *LoadImage(); }

private:
	Image * LoadImage() {
		if (!m_image)
			m_image = new Image(m_filepath);
		return m_image;
	}

private:
	Image *m_image;
	std::string m_filepath;
};

int main(int argc, char *argv[])
{
	UNUSED(argc);
	UNUSED(argv);

	std::string filepath;
	ImagePtr ptr = ImagePtr(filepath);
	ptr->Draw();

	ImageProxy proxy = ImageProxy(filepath);
	proxy.Draw();

	return 0;
}