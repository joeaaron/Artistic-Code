#include <iostream>
#include <cassert>

class Singleton
{
private:
	Singleton() = default;
	~Singleton() = default;

public:
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static Singleton& GetInstance()
	{
		// C++11�涨��local static�ڶ��߳������µĳ�ʼ����Ϊ��Ҫ���������֤���ڲ���̬�������̰߳�ȫ�ԡ�
		// ��C++11��׼�£���Effective C++�������һ�ָ����ŵĵ���ģʽʵ�֣�ʹ�ú����ڵ� local static ����
		// ������ֻ�е���һ�η���getInstance()����ʱ�Ŵ���ʵ�������ַ���Ҳ����ΪMeyers' Singleton��C++0x֮���ʵ�����̰߳�ȫ�ģ�C++0x֮ǰ���������
		static Singleton instance;
		return instance;
	}
};

int main()
{
	auto& a = Singleton::GetInstance();
	auto&b = Singleton::GetInstance();
	assert(&a == &b);

	return 0;
}