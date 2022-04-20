/**
#define DECLARE_SINGLETON_CLASS(Type) \
friend class std::unique_ptr<Type>; \
friend class CSingleton<Type>; \
static Type* Instance() { Type *shareClass = CSingleton<Type>::Instance(); return shareClass; } \
static void Release() { \
	Type *shareClass = CSingleton<Type>::Instance(); \
	if (shareClass) { \
		delete shareClass; \
		shareClass = nullptr; \
	} \
	CSingleton<Type>::Release(); \
}\**/

#include "CSingleton.h"
DECLARE_SINGLETON_CLASS(CLASS NAME);
class CThreadPool
{
public:
	CThreadPool();
	virtual ~CThreadPool();
	DECLARE_SINGLETON_CLASS(CThreadPool);

	void TestSingleton();
	void ReadTestSingleton();
};

void CThreadPool::TestSingleton() {
	printf("It is address:%p", this);
}

void CThreadPool::ReadTestSingleton() {
	CThreadPool::Instance()->TestSingleton();
	CThreadPool::Release();
}