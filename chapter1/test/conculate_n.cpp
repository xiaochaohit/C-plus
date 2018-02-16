#include <iostream>
#include <math.h>

int conculate(int n)
{
	if(n<=1)
		return 1;
	else return n*conculate(n-1);
}

int numSum(int n)
{
	if(n == 0)
		return 0;
	else
		return n + numSum(n-1);
}

int main()
{
	std::cout << conculate(5) <<std::endl;
	std::cout << numSum(5) <<std::endl;
	return 0;
}