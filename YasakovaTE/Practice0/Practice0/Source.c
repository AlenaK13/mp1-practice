#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	float x1, y1, r1, x2, y2, r2, d;
	printf("������� ���������� ������ � ������ ���������� ����� 1: ");
	scanf(" %f %f %f", &x1, &y1, &r1);
	printf("������� ���������� ������ � ������ ���������� ����� 2: ");
	scanf(" %f %f %f", &x2, &y2, &r2);
	d = sqrt(x2 * x2 - 2 * x2 * x1 + x1 * x1 + y2 * y2 - 2 * y1 * y2 + y1 * y1);
	if (d > r1 + r2)
	{
		printf("���������� �� ��������.");
	}
	else if ((r1 == r2) && (d == 0))
	{
		printf("���������� ���������.");
	}
	else if (d < abs(r1 - r2))
	{
		printf("���������� � ������� �������� ����� ������ �������.");
	}
	else if (d == abs(r1 - r2))
	{
		printf("���������� ������� �����������.");
	}
	else if (d == r1 + r2)
	{
		printf("������� ������� �����������.");
	}
	else if ((abs(r1 - r2) < d) && (d < r1 + r2))
	{
		printf("���������� ������������.");
	}
	return 0;
}