#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void main()
{
	int number,user_number,i,p;
	char zhak;
	long int a, b;//������� �� � �� b
	a = 0;
	b = 1000;
	setlocale(LC_ALL, "Russian");
	srand((unsigned int) time(0));
	printf("������� ����� ������\n1 - �������� ������;\n2 - �������� ����������;\n3 - ����� �� ���������\n");
	do{
		scanf("%d", &i);
		if (i == 1)
		{
			p = 0;
			number = rand()%1000;
			user_number = -1;
			while(user_number != number)
			{
				printf("\n");
				scanf("%d", &user_number);
				if (number > user_number)
				{
					printf("\n���������� ����� ������");
				}
				if (number < user_number)
				{
					printf("\���������� ����� ������");
				}
				if (number == user_number)
				{
					printf("\n������� �� %d ������� \n", p);
				}
			}
			p++;
		}
		
		if (i == 2)
		{
			p = 0;
			do{
				number = a + rand()%(b - a + 1);
				printf("\n%d",number);
				printf("\n ������� �����\n> ���� ����� �������,\n< ���� ����� ������,\n= ���� ����� ����� �����������\n");
				scanf("%*c%c", &zhak);
				if (zhak == '>')
				{
					a = number + 1;
				}
				if (zhak == '<')
				{
					b = number - 1;
				}
				if (zhak == '=')
				{
					printf("����� ������� �� %d �������", p);
				}
				p++;
			}while (zhak != '=');
		}
	}while (i != 3);
}