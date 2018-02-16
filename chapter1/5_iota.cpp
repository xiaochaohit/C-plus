#include <iostream>

template <typename Ta, typename Tb>
void iota(Ta &x, Tb valuex)
{
	for(int i = 0; i < sizeof(x)/sizeof(x[1]); i++)
	{
		x[i] = x[i] + valuex;
	}
}

int main()
{
	int a[5] ={1, 2, 3 ,4, 5};
	int value = 3;
	iota(a, value);
	for(int i = 0; i < sizeof(a)/sizeof(a[1]); i++)
	{
		std::cout << a[i] << std::endl;
	}

	return 0;
}