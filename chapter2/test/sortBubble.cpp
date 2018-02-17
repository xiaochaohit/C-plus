#include <iostream>
//冒泡排序法

template <typename T>
void sortBubble(T list[], int n)
{
	for(int i = 0; i < n; i++)
		for(int j = i+1;j < n-i; j++)
		{
			if(list[i] > list[j])
				std::swap(list[i],list[j]);
		}
}

int main()
{
	int n = 5;
	int list[] = {4, 3, 9, 3, 7};
	sortBubble(list, n);
	for(int i = 0; i < n; i++)
	{
		std::cout << list[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}