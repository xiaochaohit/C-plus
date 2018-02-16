#include <iostream>
//递归：位向量法输出
//思路：依次改变每一位的值是0或者1，直到访问到最后一位输出，递归该过程

template <typename Ta>
void subset(Ta *A, int n, int i)
{
	if(i == n)
	{
		for(int j = 0; j < n ;j++)
			std::cout << *(A+j);
		std::cout << std::endl;
	}
	else
	{
		A[i] = 0;
		subset(A, n, i+1);
		A[i] = 1;
		subset(A, n, i+1);
	}
}
int main()
{	
	int n = 3;		//序列含有元素个数
	int A[n];		//存储子集变量
	for (int i = 0; i<n; i++)
	{//子集初始化
		A[i] = 0;	
	}
	subset(A,n,0);

	return 0;
}