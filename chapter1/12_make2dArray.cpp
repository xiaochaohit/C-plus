#include <iostream>
#include <stdlib.h>

template <typename T>
bool make2dArray(T ** &x, int numberRows, int  *rowSize)
{//创建行指针
	try{

		x = new int *[5];
		x[0] = new int [2];
		x[0][4] = 5;
		std::cout << x[0][4] <<std::endl;

		for(int i = 0;i < numberRows; i++)
		{
			x[i] = new int [rowSize[i]];
			//std::cout << x[rowSize[i]][i] <<std::endl;
			//std::cout << sizeof(rowSize[i]) <<std::endl;
		}
		return true;
	}
	catch(std::bad_alloc) {return false;}
}

int main()
{
	int **a;
	int rowSize[5]={1, 2, 3, 4, 5};
	make2dArray(a,5,rowSize);
	for(int i = 0;i < 5; i++)
	{
		for(int j = 0;j < rowSize[4]; j++)
		{
		//std::cout << &a[i][j] << std::endl;
		//std::cout << a[i][j] << std::endl;	
		}
	}
	
	return 0;
}