//输入输出重载
#include <iostream>
template <typename T>
class test
{
public:
	test(T x = 0, T y = 0)	//构造函数
	{
		a = x;
		b = y;
	}
	~test(){}
	template <typename U>
	friend std::istream &operator>>(std::istream &in, test<U> &x);
	template <typename U>
	friend std::ostream &operator<<(std::ostream &out, test<U> &x);

protected:
	T a;
	T b;	
};
template <typename T>
std::istream &operator>>(std::istream &in, test<T> &x)
{
	in >> x.a >> x.b;
	return in;
}
template <typename T>
std::ostream &operator<<(std::ostream &out, test<T> &x)
{
	out << x.a << " " << x.b;
	return out;
}
int main()
{

	test<double> A(3,4);
	std::cin >> A;
	std::cout << A <<std::endl;
	return 0;
}

