#include <iostream>

template<typename T>
class Singleton {
public:
	//  C++ STL的std::is_nothrow_constructible模板用于检查给定类型T是否是带有参数集的可构造类型，并且众所周知，它不会引发任何异常。如果T为可构造类型，则返回布尔值true，否则返回false。
	static T& getInstance() noexcept(std::is_nothrow_constructible<T>::value)
	{
		
		static T instance{token()};
		return instance;
	}

	virtual ~Singleton() = default;

	Singleton(const Singleton&) = delete;
	Singleton& operator =(const Singleton&) = delete;

protected:
	struct token {}; // helper class
	Singleton() noexcept = default;
};

/********************************************/
// Example:
// constructor should be public because protected `token` control the access

class DerivedSingle : public Singleton<DerivedSingle> {

public:
	DerivedSingle(token) {
		std::cout << "destructor called!" << std::endl;
	}

	~DerivedSingle() {
		std::cout << "constructor called!" << std::endl;
	}
	DerivedSingle(const DerivedSingle&) = delete;
	DerivedSingle& operator =(const DerivedSingle&) = delete;
};

int main(int argc, char* argv[]) 
{
	DerivedSingle& instance1 = DerivedSingle::getInstance();
	DerivedSingle& instance2 = DerivedSingle::getInstance();
	return 0;
}
