#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int n, r, k, b, a;
	int i = 0;
	char c;
	setlocale(LC_ALL, "Rus");
	printf("�������� ����� 1 ��� 2: ");
	scanf("%d", &n);
	srand((unsigned int)time(0));
	if (n == 1)
	{
		r = 1 + rand() % 1000;
		printf("��������� ���������� ��������� ����� �� 1 �� 1000, ���������� ��������:\n");
		while (1)
		{
			i++;
			printf("������� �����: ");
			scanf("%d", &k);
			if (k < r)
			{
				printf("��������� ����� ������\n");
			}
			else if (k > r)
			{
				printf("���������� ����� ������\n");
			}
			else
			{
				printf("�� �������\n");
				break;
			}
		}
		printf("���������� �������: %d \n", i);
	}
	else if (n == 2)
	{
		printf("��������� ����� �� 1 �� 1000, ������� ���: ");
        scanf("%d", &a);
		k = 1 + rand() % 1000;
        printf("��������� ������� �������: %d \n", k);
		while (1)
		{
			i++;
			printf("���������� ����� ��������: \n");
			scanf("%*c%c", &c);
			if (c == '<')
			{
				b = 1 + rand() % k;
				printf("%d \n", b);
			}
			else if (c == '>')
			{
				b = k + rand() % 1000;
				printf("%d \n", b);
			}
			else if (c == '=')
			{
				printf("��������� ������\n");
				break;
			}

		}
		printf("���������� �������: %d \n", i);
	}
}