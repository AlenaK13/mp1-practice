#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
void main()
{
	int number,user_number,i;
	int zhak;
	long int a,b;//������� �� � �� b
	a=0;
	b=1000;
	setlocale(LC_ALL, "Russian");
	srand((unsigned int) time(0));
	do{
		printf("������� ����� ������\n1 - �������� ������;\n2 - �������� ����������;\n3 - ����� �� ���������\n");
		scanf("%d",&i);
		if (i==1)
		{
			number=rand()%1000;
			user_number=-1;
			while(user_number!=number)
			{
				printf("\n");
				scanf("%d", &user_number);
				if (number>user_number)
				{
					printf("\n���������� ����� ������");
				}
				if (number<user_number)
				{
					printf("\���������� ����� ������");
				}
				if (number==user_number)
				{
					printf("\n�������\n");
				}
			}
		}
		
		if (i==2)
		{
			do
			{
				number=a + rand()%(b - a + 1);
				printf("\n%d",number);
				printf("\n ������� �����\n1 ���� ����� �������,\n2 ���� ����� ������,\n= ���� ����� ����� �����������\n");
				scanf("%d", &zhak);//��� ��������� �������� � �������, �� ��� ������ ��������� ������������ ������� � ��� char ����� ���������� ������
				if (zhak==1)
				{
					a=number+1;
				}
				if (zhak==2)
				{
					b=number-1;
				}
				if (zhak==3)
				{
					printf("����� �������");
				}
			}while(zhak!=3);
		}
	}while(i!=3);
}