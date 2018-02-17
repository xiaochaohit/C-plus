#include <iostream>
#include <string>
//选择排序法，每循环一次选择一个最大值

template <typename T>
void sortSelection(T list[], int n)
{//依次将最大值放置到最后的位置
	int maxtemp = 0, flag = 0;
	for(int i = n-1; i > 0; i--)
	{
		maxtemp = list[i];
		for(int j = 0; j < n - i; j++)
		{
			if(list[j] > list[i])
			{
				maxtemp = list[j];
				flag = j;
			}
		}
		std::swap(list[n-i],list[flag]);
	}
}

int main()
{
	int n = 5;
	int list[] = {4, 3, 9, 3, 7};
	sortSelection(list, n);
	for(int i = 0; i < n; i++)
	{
		std::cout << list[i] <<" ";
	}
	std::cout << std::endl;
	return 0;
}