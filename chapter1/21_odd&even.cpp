#include <iostream>

template <typename T>
double odd_even(T n)
{
	if(n % 2 == 0)
		return n/2;
	else
		return odd_even(3*n+1);
}

int main()
{
	int n = 5;
	std::cout << odd_even(n) << std::endl;
	return 0;
}