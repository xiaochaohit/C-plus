//Fibonacci
#include <iostream>

template<typename T>
T fibonacci(T n)
{
	if(n == 1 )
		return 0;
	else if(n == 2)
		return 1;
	else 
	{
		return fibonacci(n-1) + fibonacci(n-2);
	}
}

int main()
{
	int n = 5;
	std::cout << fibonacci(n) << std::endl;
	return 0;
}