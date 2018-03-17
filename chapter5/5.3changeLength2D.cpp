#include <iostream>

using namespace std;

template <typename T>
void changeLength2D(T ** &a, int oldColumns, int oldRows,
					int copyColumns, int copyRows, int newColumns, int newRows)
{
	T ** temp = new T *[newRows];
	if(copyRows > newRows || copyColumns > newColumns)
		cout << "The size of new Array is too small" << endl;
	else
	{
		for (int i = 0; i < newRows; i++)
			temp[i] = new T[newColumns];
		for(int i = 0; i < copyRows; i++)
		{
			copy(a[i], a[i] + copyColumns, temp[i]);
			delete [] a[i];
		}
		
		for(int i = copyRows; i < oldRows; i++)
			delete [] a[i];
		a = temp;
	}
}

int main()
{
	int oldColumns = 5, oldRows = 5;
    int **numArray = new int*[oldRows];  
    for(int i=0;i<oldColumns;i++)  
   {  
       numArray[i]=new int[oldColumns];  
   } 
	//Initial the Array 
	for(int i = 0; i < oldRows; i++)
		for(int j = 0; j < oldColumns; j++)
			numArray[i][j] = j;
	changeLength2D(numArray, oldColumns, oldRows, 3, 3, 4, 4);

	for(int i = 0; i < 4; i++)
	{	for(int j = 0; j < 4; j++)
			cout << numArray[i][j] << " ";
		cout << endl;
	}

	return 0;
}