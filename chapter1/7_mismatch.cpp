#include <iostream>
 
template <typename T>
int mismatch(T &x , T &y)
{
	for(int i = 0; i < sizeof(x)/sizeof(x[1]); i++)
	{
		if(x[i] != y[i])
			return i;
	}
	return -1;
}

int main()
{
	int a[5] = {1, 2, 3, 4, 5};
	int b[5] = {1, 2, 2, 4, 5};
	std::cout << mismatch(a, b) <<std::endl;
	return 0;

}