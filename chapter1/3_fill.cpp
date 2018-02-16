#include <iostream>

template <class T>
void initValue(const int &start, const int &end, const int &value, T &numList)
{
	for(int i = start; i <= end; i++)
	{
		numList[i] = value;
	}
}

int main()
{
	int a[100] = {};
	int numStart = 10, numEnd = 20, numValue = 6;
	initValue(numStart, numEnd, numValue, a);
	for(int i = numStart; i <= numEnd; i++)
	{
		std::cout << a[i] << std::endl;
	}
	return 0;
}