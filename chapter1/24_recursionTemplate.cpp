#include <iostream>

template <typename Ta,typename Tb>
bool recursionTemplate(Ta &a, Tb x,int i)
{
	if(i > sizeof(a)/sizeof(a[0]))
		return false;
	else if (a[i] == x)
		return true;
	else
		return recursionTemplate(a,x,++i);
}

int main()
{
	int list[5] = {1, 2, 3, 4, 5};
	int test = 3 ,i = 0;
	if(recursionTemplate(list, test, i))
		std::cout << "yes!" << std::endl;
	else
	 	std::cout << "no!" << std::endl;
	return 0;
}