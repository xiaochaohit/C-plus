#include <iostream>

int main()
{
	/*错误源码
	char *test = "hello word!";
	*test = 't';
	std::cout << test << std::endl;
	*/
	char temp[] = "hello word!";
	char *test = temp;
	*test = 't';
	std::cout << *test << std::endl;
	std::cout << temp[0] <<std::endl;
	return 0;
}