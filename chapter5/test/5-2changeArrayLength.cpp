#include <iostream>

template<typename T>
void changeLength1D(T* a,int oldLength, int newLength)
{
	if(newLength < 0);
		//throw illegalParameterValue("new length must be >= 0");

	T* temp = new T[newLength];
	int number = std::min(newLength, oldLength);
	std::copy(a, a+number, temp);
	a = temp;	
	delete [] temp;
}

int main()
{
	int list[] ={1,2,3,4,5};
	int oldLength = 5, newLength = 3;
	changeLength1D(list, oldLength, newLength);
	for(int i = 0; i < std::min(newLength, oldLength); i++)
		std::cout << list[i] << std::endl;
	return 0;
}