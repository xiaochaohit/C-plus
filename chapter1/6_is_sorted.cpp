#include <iostream>

template <typename T>
bool is_sorted(T &x)
{
	for(int i = 1; i < sizeof(x)/sizeof(x[0]); i++)
	{
		if( x[i] < x[i-1] )
			return false;
	}
		return true;
}

int main()
{
	int a[5] = {1 ,2, 5, 4, 5};

	if(is_sorted(a))
		std::cout << "is_sorted" <<std::endl;
	else 
		std::cout << "not_sorted" <<std::endl;

	return 0;
}