#include <iostream>
#include <stdlib.h>

template <typename T>
bool make2dArray(T ** &x, int numberOfRows, int numberOfColumns)
{	//创建二维数组

	try{
		//创建行指针
		x = new T * [numberOfRows];

		//为每一行分配空间
		for (int i = 0; i < numberOfRows; i++)
		{
			x[i] = new int [numberOfColumns];
		}
		return true;
	}
	catch (std::bad_alloc) {return false;}
}
template <typename T>
void delete2dArray(T ** &x, int numberOfRows)
{//删除二维数组x
	for(int i = 0; i < numberOfRows; i++)
	{
		delete [] x[i];
	}

	delete [] x;
	x = NULL;
}
int main()
{
	/*int *y = new int(10);
	std::cout << *y << std::endl;
	delete(y);*/
	int **a;
	try{make2dArray(a,6,6);}
	catch(std::bad_alloc)
	{
		std::cout << "Could not create a" << std::endl;
		exit(1);
	}
	std::cout << **a << std::endl;
	//std::cout << sizeof(a[0]) << std::endl;
	delete2dArray(a, 6);
	std::cout << **a << std::endl;
	return 0;
}