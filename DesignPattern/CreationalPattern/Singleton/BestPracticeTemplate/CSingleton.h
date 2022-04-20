#ifndef CSingleton_hpp
#define CSingleton_hpp

#include <stdio.h>
#include <mutex>
#include <memory>

class CSinGuard {
public:
	CSinGuard() { m_lGrdCnt = 0; pthread_mutex_init(&m_cs, nullptr); }
	~CSinGuard() { pthread_mutex_destroy(&m_cs); }

	int IsGuarded() const { return (m_lGrdCnt > 0); }

public:
	class CGuard {
	public:
		CGuard(CSinGuard& rg) :m_rg(rg) { m_rg.Guard(); };
		~CGuard() { m_rg.Unguard(); }

	private:
		CSinGuard& m_rg;
	};

private:
	void Guard() { pthread_mutex_lock(&m_cs); m_lGrdCnt++; }		// ����+1
	void Unguard() { m_lGrdCnt--; pthread_mutex_unlock(&m_cs); }    // ����-1

	friend class CSinGuard::CGuard;

private:
	pthread_mutex_t m_cs;   //�߳���
	long m_lGrdCnt;     //���ü���
};

template <class T>
class CSingleton
{
public:
	static inline T* Instance();
	static inline void Release();

private:
	CSingleton(void) {}
	virtual ~CSingleton(void) {}
	CSingleton(const CSingleton&) {}
	CSingleton & operator= (const CSingleton &) {}

	static std::unique_ptr<T> m_Instance; //����ָ�룬���Զ��ͷ�
	static CSinGuard m_sg;   //������ȫ��
};

//��������(����)ģ��
template <class T>
std::unique_ptr<T> CSingleton<T>::m_Instance;

//������������ȫ��ģ��
template <class T>
CSinGuard CSingleton<T>::m_sg;

//��ȡ����
template <class T>
inline T* CSingleton<T>::GetInstance()
{
	if (m_Instance.get() == nullptr) {
		CSinGuard::CGuard gd(m_sg);      //��������ֹ���߳�ͬʱ����
		if (m_Instance.get() == nullptr) {
			m_Instance.reset(new T);// ʹ��std::unique_ptr<T>.resetʵ����.�����ĵ�static Test instance = new Test();����
		}
	}

	return m_Instance.get();
}

//�ͷŵ���
template <class T>
inline void CSingleton<T>::Release()
{
	CSinGuard::CGuard gd(m_sg);
	m_Instance.release();
}

#endif /* CSingleton_hpp */