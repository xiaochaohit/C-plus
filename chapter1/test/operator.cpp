#include <iostream>
#include <stdlib.h>

typedef bool signType;
#define  plus 1
#define  minus 0

class currency
{
public:
	//友元声明
	friend std::ostream& operator <<(std::ostream& out,currency &x);
	//构造函数
	currency(signType theSign = plus,
			unsigned long theDollars = 0,
			unsigned int theCents = 0);
	//析构函数
	~currency(){std::cout << "release the space!" << std::endl;}
	void setValue(signType,unsigned long,unsigned int);
	void setValue(double theAmount);
	currency add(const currency &x) const;
	currency& operator += (currency &x)
{
	*this = add(x);
	return *this;
}
	void output();


private:
	signType sign;
	unsigned long dollars;
	unsigned int cents;
};

currency::currency(signType theSign, unsigned long theDollars, unsigned int theCents)
{
	setValue(theSign, theDollars, theCents);
}

void currency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents)
{//数据成员赋值
	if(theCents >99)
	{
		std::cout << "Cents should be <100" << std::endl;
		exit(1);
	}
		//throw illegalParameterValue("Cents should be <100");
	sign = theSign;
	dollars = theDollars;
	cents = theCents;
}

void currency::setValue(double theAmount)
{
	if(theAmount < 0)
	{
		sign = minus;
		theAmount = - theAmount;
	}
	else
		sign = plus;
	dollars = (unsigned long) theAmount;
	//std::cout << dollars << std::endl;
	cents = (unsigned int)((theAmount + 0.001 - dollars)*100);
}

currency currency::add(const currency &x) const
{
	long a1,a2,a3;
	currency result;

	//计算当前结构体金额
	a1 = dollars * 100 + cents;
	if(sign == minus) a1 = -a1;

	//计算输入结构体金额
	a2 = x.dollars * 100 + x.cents;
	if(x.sign == minus) a2 = -a2;

	//转化为result
	a3 = a1 + a2;
	if(a3 < 0) 
	{
		result.sign = minus;
		a3 = -a3;
	}
	else result.sign = plus;
	result.dollars = (unsigned long) a3/100;
	result.cents = a3 - result.dollars * 100;

	return result;
}



void currency::output()
{
	if(sign == minus) std::cout << "-";
	std::cout << "$" << dollars <<".";
	std::cout << cents << std::endl;
}

std::ostream& operator <<(std::ostream& out,currency &x)
{
	std::cout << x.dollars << std::endl;
	x.output();
	return out;
}
int main()
{
	currency g(minus, 3, 50);
	currency h;
	h.setValue(1.232);
	//g.output();
	//h.output();
	//g.increment(h).increment(g);//连续调用两次increment
	//g.output();
	std::cout << g;
	return 0;
}