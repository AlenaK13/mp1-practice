#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
void main()
{
	int x1, x2, y1, y2, r1, r2;
	setlocale(LC_ALL, "Rus");
	double d;
	printf("Input x1, y1, x2, y2, r1, r2\n");
	scanf_s("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &r1, &r2);
	if (r1 <= 0)
	{
		printf("�� �������� �����������, r1- ������������� ��� ����� ����\n");
		return 0;
	}
	if (r2 <= 0)
	{
		printf("�� �������� �����������, r2 - ������������� ��� ����� ����\n");
		return 0;
	}
	d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if (x1 == x2 && y1 == y2 && r1 == r2)
	{
		printf("���������� �����");
	}
	else if (r1 + r2 < d)
	{
		printf("���������� �� ������������, ���������� ����� �����");
	}
	else if (d < abs(r1 - r2))
	{
		printf("���������� �� ������������, ������� ���� � �����");
	}
	else if (d == r1 + r2)
	{
		printf("������� ������� �����������, ���� ����� �����");
	}
	else if (d == r1 - r2)
	{
		printf("���������� ������� �����������, ���� ����� �����");
	}
	else
	{
		printf("���������� ������������, ��� ����� �����");
	}

}