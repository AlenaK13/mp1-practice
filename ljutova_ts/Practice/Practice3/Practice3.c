#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
#include <locale.h>

void main()
{
	int n, ch, r, min = 1, max = 1000, count = 0;
	char z[3];
	setlocale(LC_ALL, "Russian");

	printf("������ ������:\n");
	printf("1-��������� ���������� �����\n");
	printf("2-������������ ���������� �����\n");
	printf("�������� �����: ");
	scanf("%d", &r);
	if (r == 1)
	{
		srand((unsigned int)time(0));
		ch = rand() % 1000 + 1;
		while (1)
		{
			do
			{
				printf("������� �����: \n");
				scanf("%d", &n);
				if ((n <= 0) || (n >= 1000))
					printf("������.����� ������ ���� � ��������� 1 - 1000 \n");
			} while ((n <= 0) || (n >= 1000));
			count++;
			if (n == ch)
			{
				printf("����������! �� ������� �����\n");
				printf("����� �������: %d \n", count);
				return;
			}
			if (n > ch)
				printf("��������� ����� ������ ����������� \n");
			else
				printf("��������� ����� ������ ����������� \n");
		}
	}
	else if (r == 2)
		do
		{
			printf("������� �����: \n");
			scanf("%d", &n);
			if ((n <= 0) || (n >= 1000))
				printf("������.����� ������ ���� � ��������� 1 - 1000 \n");
		} while ((n <= 0) || (n >= 1000));
		while (z[0] != '=')
		{
			srand((unsigned int)time(0));
			ch = rand() % (max - min + 1) + min;
			printf("���������: %d \n", ch);
			printf("������� (>),(<),(=) �������� ����� � ������� ����������\n");
			scanf("%9s", &z);
			switch (z[0])
			{
			case '>': min = ch;
				count++;
				break;
			case '<': max = ch;
				count++;
				break;
			case '=':count++;
				printf("��������� ������ �����! \n");
				printf("����� ������� : %d \n", count);
				break;
			default: printf("������� ������������ ��������");
				break;
			}
		}
}