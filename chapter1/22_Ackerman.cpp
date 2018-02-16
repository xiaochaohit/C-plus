#include <iostream>
#include <math.h>

double Ackerman(int i, int j)
{
	if(i == 1 && j>=1)
		return pow(2,j);
	else if(i >= 2 && j == 1)
		return Ackerman(i-1, 2);
	else 
		return Ackerman(i-1, Ackerman(i, j-1));
}

int main()
{
	std::cout << Ackerman(1,2) << std::endl;
	std::cout << Ackerman(2,1) << std::endl;
	std::cout << Ackerman(2,2) << std::endl;
	return 0;
}