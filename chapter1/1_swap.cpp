#include <iostream>

template <class T>
T swap_num(T &a, T &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	return 0;
}

int main()
{
	int a = 1, b = 2;
	swap_num(a, b);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	return 0;
}