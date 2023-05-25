//网页上一篇图文结合的文章，其中有许多特别大的图片(创建的开销特别大), 
//当我网页打开这篇文章的时候，我需要保证网页的打开速度，不能等图片都创建完成之后在真正显示; 
//还有一种情况，当用户没有阅读到图片的时候就关闭了网页，创建图片显得就很浪费
//
//所以只有当真正阅读到图像的时候，图片才需要真正加载出来。但是打开网页的时候我们又需要创建一个图像的对象，
//上面介绍了一些情况下不直接实例化图像的原因，所以使用一个代理对象，代理真正的图像，
//并且代理中保存图像的尺寸信息，提供给网页图片大致的区域信息。
//与此同时，代理对象有跟原图像对象有一样的接口，只有当前端调用代理的 Draw 来显示图像的时候，代理才真正创建图像，
//并且将随后的请求转发给这个图像对象

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