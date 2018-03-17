#include <iostream>

class A
{
public:
	virtual void print() = 0;
/*	{
		std::cout << "smart" << std::endl;
	}*/
protected:

		virtual void output()
	{
		std::cout << "smart" << std::endl;
	}
};

class B:protected A
{
public:
	virtual void print()
	{
		std::cout << "stupid!" << std::endl;
		output();
	}
};

int main()
{
	//A *p1 = new A;
	//B *p2 = new B;
	//A a;
	int temp = 1;
	B b;
	//A *p1 = &a;
	//A *p2 = &b;
	//p1 -> print();
	//p2 -> print();
	//p2 -> output();

	return 0;
}