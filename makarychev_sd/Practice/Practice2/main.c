#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void main()

{
	setlocale(LC_ALL, "Rus");
	int n, i, b = 0, c = 9, q, m, p = 0, d = 0;
	int a[10], t[10];
	srand((unsigned int)time(0));
	do
	{
		printf("������� ���������� ������ n � ����� \n");
		scanf("%d", &n);
	} while (n < 1 || n>10);
	for (i = 0; i < n; i++)
	{
		a[i] = rand() * (c - b) / RAND_MAX + b;
		while (1)
		{
			if (a[0] = 0)
				a[0] = rand() * (c - b) / RAND_MAX + b;
			else
				break;
		}
		for (q = 0; q < i; q++)
		{
			if (a[i] == a[q])
			{
				a[i] = rand() * (c - b) / RAND_MAX + b;
				i = 1;
				break;
			}
		}
	}
	while (1)
	{
		d = 0;
		p = 0;
		printf("������� n-������� ����� � ���������������� ������� \n");
		for (m = 0; m < n; m++)
		{
			scanf("%d", &(t[m]));
		}
		for (i = 0; i < n; i++)
		{
			for (m = 0; m < n; m++)
			{
				if ((t[m] == a[i]) && (m == i))
					p++;
				else if ((t[m] == a[i]) && (m != i))
					d++;
			}
		}
		printf("����� ����� %d \n", d);
		printf("����� ����� %d \n", p);
		if ((d == 0) && (p == n))
		{
			printf("����� ������� \n");
			break;
		}
	}
}
