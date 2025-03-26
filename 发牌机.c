#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//转换函数,将数字转为asc2码
int jqk(int n)
{
	if (n == 11)
	{
		return 'J';
	}
	else if (n == 12)
	{
		return 'Q';
	}
	else if (n == 13)
	{
		return 'K';
	}
	else if (n == 1)
	{
		return 'A';
	}
	else
	{
		return n + '0';
	}
}
//比较函数,用于快速排序
int compare(const void* a, const void* b)
{
	return (*(int*)b) - (*(int*)a);
}
int main()
{
	//取种子
	srand(time(NULL));
	//定义结构体
	typedef struct
	{
		int red[13];
		int black[13];
		int sqart[13];
		int flowe[13];
		int king[2];
	}card;
	card c1;
	c1.king[0] = 100;
	c1.king[1] = 200;
	//初始化结构体元素
	for (int i = 1; i <= 13; i++)
	{
		c1.red[i - 1] = i;
		c1.black[i - 1] = i;
		c1.sqart[i - 1] = i;
		c1.flowe[i - 1] = i;
	}

	//打印
	int p = 1;//计数
	//开始分牌
	while (p != 4)
	{
		int m = (p < 3) ? 17 : 20;//m为卡牌数量,简化判断符类似于if-else
		int* nong = (int*)malloc(m * sizeof(int));//动态分配临时数组，为啥叫这个名别管
		int q = 0;//计数
		
		//寻找有效牌
		for (int i = 0; i < m;)//这里的i++也可以写里面，下面跟个else i--就行
		{
			int r = 1 + rand() % 54;//取随机数
			
			if (r > 0 && r <= 13 && c1.red[r - 1] != -1)
			{
				nong[q++] = 3000 + c1.red[r - 1];
				c1.red[r - 1] = -1;
				i++;
			}
			else if (r > 13 && r <= 26 && c1.black[r - 14] != -1)
			{
				nong[q++] = 4000 + c1.black[r - 14];
				c1.black[r - 14] = -1;
				i++;
			}
			else if (r > 26 && r <= 39 && c1.sqart[r - 27] != -1)
			{
				nong[q++] = 1000 + c1.sqart[r - 27];
				c1.sqart[r - 27] = -1;
				i++;
			}
			else if (r > 39 && r <= 52 && c1.flowe[r - 40] != -1)
			{
				nong[q++] = 2000 + c1.flowe[r - 40];
				c1.flowe[r - 40] = -1;
				i++;
			}
			else if (r > 52 && r <= 54 && c1.king[r - 53] != -1)
			{
				if (c1.king[r - 53] == 100)
				{
					nong[q++] = 5000;
					c1.king[r - 53] = -1;
					i++;
				}
				else if (c1.king[r - 53] == 200)
				{
					nong[q++] = 6000;
					c1.king[r - 53] = -1;
					i++;
				}
			}
		}

		//快速排序
		qsort(nong, m, sizeof(int), compare);

		//打印
		printf(m == 17 ? "\n\n农民的牌是:\n" : "\n\n地主的牌是:\n");
		for (int j = 0; j < m; j++)
		{
			if (nong[j] >= 4000 && nong[j] < 5000)
			{
				printf(jqk(nong[j] - 4000) != ':' ? "黑桃%-2c " : "黑桃10   ", jqk(nong[j] - 4000));
			}
			else if (nong[j] >= 3000 && nong[j] < 4000)
			{
				printf(jqk(nong[j] - 3000)!=':'?"红桃%-2c ": "红桃10   ",jqk(nong[j] - 3000));
			}
			else if (nong[j] >= 2000 && nong[j] < 3000)
			{
				printf(jqk(nong[j] - 2000) != ':' ? "梅花%-2c " : "梅花10   ", jqk(nong[j] - 2000));
			}
			else if (nong[j] >= 1000 && nong[j] < 2000)
			{
				printf(jqk(nong[j] - 1000) != ':' ? "方块%-2c " : "方块10   ", jqk(nong[j] - 1000));
			}
			else if (nong[j] == 5000)
			{
				printf("小王 ");
			}
			else if (nong[j] == 6000)
			{
				printf("大王 ");
			}
			if ((j + 1) % 8 == 0)
			{
				printf("\n");
			}
		}

		//释放内存
		free(nong);
		p++;
	}
	return 0;
}