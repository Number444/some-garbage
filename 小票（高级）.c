#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//�ո���
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
	FILE* fp = fopen("txt01.txt", "a");//��txt�ļ�
	printf("����������Ա:\n");
	//��������
	scanf("%s", shouyin);
	for (int i = 0;i < 2;i++)
	{
		printf("������Ʒ��\n");
		scanf("%s", pinming[i]);
		printf("��������\n");
		scanf("%d", &mount[i]);
		printf("����۸�\n");
		scanf("%f", &perp[i]);
	}
	printf("����Ա:%s\n", shouyin);
	printf("----------------------------------------\n");
	printf("Ʒ��");
	blank(5);
	printf("����");
	blank(5);
	printf("����");
	blank(5);
	printf("С��");
	printf("\n");
	fprintf(fp,"����Ա:%s\n", shouyin);
	fputs("----------------------------------------\n",fp);
	fputs("Ʒ��",fp);
	fputs("     ",fp);
	fputs("����",fp);
	fputs("     ",fp);
	fputs("����",fp);
	fputs("     ",fp);
	fputs("С��\n",fp);
	//д������
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
		//����txt�ļ�
		fprintf(fp,"%s ", pinming[i]);
		fputs("        ",fp);
		fprintf(fp,"%d ", mount[i]);
		fputs("        ",fp);
		fprintf(fp,"%.2f ", perp[i]);
		fputs("      ",fp);
		fprintf(fp,"%.2f ", mount[i] * perp[i]);
		fputs("\n", fp);
	}
	printf("�ϼ�:%d\n", sum);
	printf("����:10000.00");
	printf("\t����:%d", 10000-sum);
	fprintf(fp,"�ϼ�:%d\n", sum);
	fprintf(fp,"����:10000.00");
	fprintf(fp,"\t����:%d\n", 10000 - sum);
	fclose(fp);//�ر�txt
}