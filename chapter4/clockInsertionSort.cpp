#include <iostream>
#include <time.h>

template<class T>
void insertionSort(T a[], int n)
{// Sort a[0:n-1] using the insertion sort method.
   for (int i = 1; i < n; i++)
   {// insert a[i] into a[0:i-1]
      T t = a[i];
      int j;
      for (j = i-1; j >= 0 && t < a[j]; j--)
         a[j+1] = a[j];
      a[j+1] = t;
   } 
}

int main()
{
	int a[1000], step = 10;
	double clocksPerMillis = double(CLOCKS_PER_SEC) /1000; //每毫秒滴答一次，转换为毫秒为单位

	std::cout <<"用毫秒来计数，最坏的情况下为：" << std::endl;
	std::cout <<"n \t Time" << std::endl;

	//次数 n = 0,10,20,...,100,200,300,...,1000
	for (int n = 0; n <= 1000;n += step)
	{
		for (int i = 0; i < n; i++)
			a[i] = n - i;

		clock_t startTime = clock();
		insertionSort(a, n);
		double elapsedMillis = (clock() - startTime) / clocksPerMillis;

		std::cout << n << '\t' << elapsedMillis << std::endl;

		if(n ==100 ) step = 100;
	}

	return 0;
}