#include <iostream>

int commonDivisor(int x, int y)
{
	if(x == 0 && y == 0)
		return 0;
	else if(y == 0)
		return x;
	else
		return commonDivisor(y,x % y);
}

int main()
{
	std::cout << commonDivisor(20, 30) << std::endl;
	return 0;
}