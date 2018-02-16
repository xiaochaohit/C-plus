#include <iostream>

int abc(int a,int b, int c)
{
	if(a <= 0 || b <= 0 || c <= 0)
		throw "All should >0";
	return a+b*c;
}
int main()
{
	try {std::cout << abc(2,0,4) << std::endl;}
	catch (char const *e)
	{
		std::cout << e << std::endl;
		return 1;
	} 
	return 0;
}