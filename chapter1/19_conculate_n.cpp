#include <iostream>
#include <math.h>

long int conclute_n(int n)
{
	int sum = 1 ;
	if(n <= 0)
		return 1;
	else
	{
		for(int i = 1 ; i <= n ;i++)
			sum = sum * i;
		return sum;
	}
}

int main()
{
	int n=5;
	std::cout << conclute_n(n) << std::endl;
	return 0;
}