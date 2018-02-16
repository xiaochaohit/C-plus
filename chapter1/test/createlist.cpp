#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
//using namespace std;
template <typename T>
void permutations(T list[], int k, int m)
{
	if(k == m)
	{
		std::copy(list, list+m+1, 
			std::ostream_iterator<T>(std::cout,""));
		std::cout << std::endl;
	}
	else
	{
		for(int i = k; i <= m ;i++)
		{
			std::swap(list[i], list[k]);
			permutations(list, k + 1, m);
			std::swap(list[i], list[k]);
		}
	}
}

int main()
{
	char list[3] = {'a', 'b', 'c'};
	int k = 0;
	int m = 2;
	permutations(list, k, m);
	return 0;
}
