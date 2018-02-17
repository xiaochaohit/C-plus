#include <iostream>
//按名次排序，递增数列

template <typename T>
void Racking(T &list, T &rack)
{
	int n = sizeof(list)/sizeof(list[0]);
	for(int i = 0; i < n; i++)	//初始化名次
	{
		rack[i] = 0;
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j<i; j++)
			if(list[i] >= list[j]) rack[i]++;
			else rack[j]++;
	}

}

template <typename T>
void sortNum(T list[], T rack[], int n)
{//交换位置
	T *tempList = new T [n];

	for(int i = 0; i < n; i++)
		tempList[rack[i]] = list[i];
	
	for(int i = 0; i < n; i++)
		list[i] = tempList[i];
	delete [] tempList;
}
int main()
{
	int n = 5;
	int list[] = {4, 3, 9, 3, 7};
	int rack[] = {0, 0, 0, 0, 0};
	Racking(list, rack);	//获得名次
	sortNum(list, rack, n);
	for(int i = 0; i<sizeof(list)/sizeof(list[0]); i++)
		std::cout << list[i] <<" ";
	std::cout << std::endl;
	return 0;
}