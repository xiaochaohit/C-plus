//#include <studio>
#include <iostream>
using namespace std;

template <class  T >
T abc(const T& a, const T& b, T& c)
{
	c++;
	return c;
}

int main(void)
{
	float x,y,z;
	x = 1.2;
	y = 2.6;
	z = 3;
	cout << abc(x,y,z) << endl;
	cout << z<< endl;
}