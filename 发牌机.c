#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//ת������,������תΪasc2��
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
//�ȽϺ���,���ڿ�������
int compare(const void* a, const void* b)
{
	return (*(int*)b) - (*(int*)a);
}
int main()
{
	//ȡ����
	srand(time(NULL));
	//����ṹ��
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
	//��ʼ���ṹ��Ԫ��
	for (int i = 1; i <= 13; i++)
	{
		c1.red[i - 1] = i;
		c1.black[i - 1] = i;
		c1.sqart[i - 1] = i;
		c1.flowe[i - 1] = i;
	}

	//��ӡ
	int p = 1;//����
	//��ʼ����
	while (p != 4)
	{
		int m = (p < 3) ? 17 : 20;//mΪ��������,���жϷ�������if-else
		int* nong = (int*)malloc(m * sizeof(int));//��̬������ʱ���飬Ϊɶ����������
		int q = 0;//����
		
		//Ѱ����Ч��
		for (int i = 0; i < m;)//�����i++Ҳ����д���棬�������else i--����
		{
			int r = 1 + rand() % 54;//ȡ�����
			
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

		//��������
		qsort(nong, m, sizeof(int), compare);

		//��ӡ
		printf(m == 17 ? "\n\nũ�������:\n" : "\n\n����������:\n");
		for (int j = 0; j < m; j++)
		{
			if (nong[j] >= 4000 && nong[j] < 5000)
			{
				printf(jqk(nong[j] - 4000) != ':' ? "����%-2c " : "����10   ", jqk(nong[j] - 4000));
			}
			else if (nong[j] >= 3000 && nong[j] < 4000)
			{
				printf(jqk(nong[j] - 3000)!=':'?"����%-2c ": "����10   ",jqk(nong[j] - 3000));
			}
			else if (nong[j] >= 2000 && nong[j] < 3000)
			{
				printf(jqk(nong[j] - 2000) != ':' ? "÷��%-2c " : "÷��10   ", jqk(nong[j] - 2000));
			}
			else if (nong[j] >= 1000 && nong[j] < 2000)
			{
				printf(jqk(nong[j] - 1000) != ':' ? "����%-2c " : "����10   ", jqk(nong[j] - 1000));
			}
			else if (nong[j] == 5000)
			{
				printf("С�� ");
			}
			else if (nong[j] == 6000)
			{
				printf("���� ");
			}
			if ((j + 1) % 8 == 0)
			{
				printf("\n");
			}
		}

		//�ͷ��ڴ�
		free(nong);
		p++;
	}
	return 0;
}