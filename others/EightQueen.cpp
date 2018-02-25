#include <iostream>
/**********思路**************/
/*用递归加穷举法的思想来进行问题的解决
 *从第一行开始判断每个位置是否可以放置元素
 *若可放置元素则递归进入下一行的判断
 *直至判断至最后一行输出
 *若不可放置元素则判断下一列
 */
//定义棋盘大小
#define allrows 8
#define allcolumns 8
int count = 1;  //计数全局变量

//判断该位置是否可以放置棋子
int isNotOk(int (*locateOut)[allrows], int nowrow, int nowcol)
{
	//同列有皇后
	for(int i = 0; i < nowrow; i++)
	{
		//std::cout << "In1" << std::endl;
		if(locateOut[i][nowcol])
			return 1;
	}
	//左上方有皇后
	for(int i = nowrow - 1, j = nowcol - 1; i >= 0 && j >= 0; i--, j--)
	{
		//std::cout << "In2" << std::endl;
		if(locateOut[i][j])
			return 2;
	}
	//右上方有皇后
	for(int i = nowrow - 1, j = nowcol + 1; i >= 0 && j < allcolumns; i--, j++)
	{
		//std::cout << "In3" << std::endl;
		if(locateOut[i][j])
			return 3;
	}

	return 0;
}

//主递归函数
void EightQueen(int (*locateOut)[allrows], int nowrow)
{
	if(allrows == nowrow)	//行数计数到最后一行的下一行，则进行输出
	{
		std::cout << "This is " << count <<" ways" << std::endl;
		count++;
		for(int i = 0; i < allrows; i++)
		{
			for(int j = 0; j < allcolumns; j++)
				std::cout << locateOut[i][j] << " ";
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	else
	{
		for(int i = 0; i < allcolumns; i++)
		{
			for(int j = 0; j < allcolumns; j++)  //先清空该行元素，避免上次未清空带来的影响
				locateOut[nowrow][j] = 0;
			locateOut[nowrow][i] = 1;
			if (!isNotOk(locateOut, nowrow, i))
			{
				//std::cout << "In" << std::endl;
				EightQueen(locateOut, nowrow + 1);
			}
		}
	}
}


int main()
{
	int locateOut[allrows][allcolumns];
	for (int i = 0; i < allrows; i++)
	{
		for (int j = 0; j < allcolumns;j++)
		{
			locateOut[i][j] = 0;
		}
	}
	EightQueen(locateOut, 0);
	return 0;
}


