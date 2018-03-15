#include <iostream>

class A
{
public:
	virtual void print()
	{
		std::cout << "smart" << std::endl;
	}
};

class B:public A
{
public:
	virtual void print()
	{
		std::cout << "stupid!" << std::endl;
	}
};

int main()
{
	//A *p1 = new A;
	//B *p2 = new B;
	A a;
	B b;
	A *p1 = &a;
	A *p2 = &b;
	p1 -> print();
	p2 -> print();

	return 0;
}