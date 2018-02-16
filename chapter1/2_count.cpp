#include <iostream>


template <typename T>
int count(T &x)
{	
	return sizeof(x)/sizeof(x[0]);
}

int main()
{
	int a[7] = {1,2,3,4,5,6,7};
	std::cout << count(a) << std::endl;
	return 0;
}