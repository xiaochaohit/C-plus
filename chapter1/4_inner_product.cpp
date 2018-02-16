#include <iostream>

template <class T>
int inner_product(T &a, T &b)
{
	int sum = 0;
	for(int i = 0; i < sizeof(a)/sizeof(a[0]) ;i++)
		sum = sum + a[i]*b[i];
	return sum;
}

int main()
{
	//int a[5] = {1, 2, 3, 4, 5}, b[5] = {1, 2, 3, 4, 5};
	int a[5],b[5];
	std::cout<< inner_product(a, b)<< std::endl;
	std::cout<< sizeof(a)<< std::endl;	
	return 0;
}