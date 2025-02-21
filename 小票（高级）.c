#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//空格函数
void blank(int a)
{
	for (int j = 0;j < a;j++)
	{
		printf(" ");
	}
}
int main()
{
	char shouyin[30],pinming[2][30];
	int mount[2],  sum=0;
	float perp[2];
	FILE* fp = fopen("txt01.txt", "a");//打开txt文件
	printf("请输入收银员:\n");
	//读入数据
	scanf("%s", shouyin);
	for (int i = 0;i < 2;i++)
	{
		printf("请输入品名\n");
		scanf("%s", pinming[i]);
		printf("输入数量\n");
		scanf("%d", &mount[i]);
		printf("输入价格\n");
		scanf("%f", &perp[i]);
	}
	printf("收银员:%s\n", shouyin);
	printf("----------------------------------------\n");
	printf("品名");
	blank(5);
	printf("数量");
	blank(5);
	printf("单价");
	blank(5);
	printf("小计");
	printf("\n");
	fprintf(fp,"收银员:%s\n", shouyin);
	fputs("----------------------------------------\n",fp);
	fputs("品名",fp);
	fputs("     ",fp);
	fputs("数量",fp);
	fputs("     ",fp);
	fputs("单价",fp);
	fputs("     ",fp);
	fputs("小计\n",fp);
	//写入数据
	for (int i = 0;i < 2;i++)
	{
		printf("%s",pinming[i]);
		blank(8);
		printf("%d",mount[i]);
		blank(8);
		printf("%.2f",perp[i]);
		blank(6);
		printf("%.2f",mount[i]*perp[i]);
		sum += mount[i] * perp[i];
		printf("\n");
		//存入txt文件
		fprintf(fp,"%s ", pinming[i]);
		fputs("        ",fp);
		fprintf(fp,"%d ", mount[i]);
		fputs("        ",fp);
		fprintf(fp,"%.2f ", perp[i]);
		fputs("      ",fp);
		fprintf(fp,"%.2f ", mount[i] * perp[i]);
		fputs("\n", fp);
	}
	printf("合计:%d\n", sum);
	printf("收银:10000.00");
	printf("\t找零:%d", 10000-sum);
	fprintf(fp,"合计:%d\n", sum);
	fprintf(fp,"收银:10000.00");
	fprintf(fp,"\t找零:%d\n", 10000 - sum);
	fclose(fp);//关闭txt
}