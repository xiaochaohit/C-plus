#include <iostream>
#include <stddef.h> 	//包含ptrdiff_t ，用于存储两个指针减法的操作结果

template <typename iterator>
void copy(iterator start, iterator end, iterator to)
{//从[start,end]复制到[to,to+end-start]
	while(start != end)
	{
		*to = *start;
		to++;
		start++;
	}
}

template <typename T>
class iterator
{
public:
	//
	typedef std::bidirectional_iterator_tag iterator_category;
	typedef T value_type;
	typedef ptrdiff_t difference_type;
	typedef T* pointer;
	typedef T& reference;

	iterator();
	~iterator();
	
};

int main()
{
	int testIn[] = {1,2,3,4,5},testOut[5];
	copy(testIn, testIn+(sizeof(testIn)/sizeof(testIn[0])), testOut);
	
	for(int i = 0; i < sizeof(testIn)/sizeof(testIn[0]); i++)
		std::cout << testOut[i] << std::endl;

	return 0;
}