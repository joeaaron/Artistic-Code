#pragma once
#include <iostream>

class Operation
{
public:
	Operation() :A(0), B(0) {}
	virtual ~Operation() {}

	double GetA() const { return A; }
	double GetB() const { return B; }
	void SetA(double x) { A = x; }
	void SetB(double y) { B = y; }
	double virtual GetResult() { return 0; }

private:
	double A, B;
};

class Add : public Operation
{
public:
	double GetResult()
	{
		return GetA() + GetB();
	}
};

class Sub : public Operation
{
public:
	double GetResult()
	{
		return GetA() - GetB();
	}
};

class Mul : public Operation
{
public:
	double GetResult()
	{
		return GetA()*GetB();
	}
};

class Div : public Operation
{
public:
	double GetResult()
	{
		if (GetB() == 0)
			throw std::string("Division by zero condition!");
		return GetA() / GetB();
	}
};

class Factory
{
public:
	virtual Operation *CreateOperator() = 0;
};

class AddFactory : public Factory
{
public:
	Operation *CreateOperator() {
		return new Add();
	}
};

class SubFactory : public Factory
{
public:
	Operation *CreateOperator() {
		return new Sub();
	}
};

class MulFactory : public Factory
{
public:
	Operation *CreateOperator() {
		return new Mul();
	}
};

class DivFactory : public Factory
{
public:
	Operation *CreateOperator() {
		return new Div();
	}
};