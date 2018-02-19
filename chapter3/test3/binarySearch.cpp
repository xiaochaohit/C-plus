#include <iostream>

template<typename T>
int binarySearch(const T list[],const int n,const T x)
{//二分法查找，返回查找到元素的位置编号，否则返回-1
	int left = 0, right = n - 1;
	while(right >= left)
	{
		int middle = (left + right)/2;
		if(list[middle] == x)
			return middle;
		else if (list[middle] < x)
			left = middle+1;
		else
			right =middle-1;	
	}
	return -1;
}

int main()
{
	int n = 5;
	int x = 0;
	int list[] = {1,2,3,4,5};
	std::cout << binarySearch(list, n, x) << std::endl;
	return 0;
}