#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <clocale>


int main()
{
	SetLocale(LC_CTYPE, "Russian");
	float xc1, yc1, xc2, yc2, xr1, yr1,xr2,yr2,s,r1,r2;
	printf("������� ���������� ������ ������ ����������: ");
	scanf("&f &f", &xc1, &yc1);
	printf("������� ���������� ������ ������ ����������: ");
	scanf("&f &f", &xc2, &yc2);
	printf("������� ���������� ������� ������ ����������: ");
	scanf("&f &f", &xc1, &yc1);
	printf("������� ���������� ������� ������ ����������: ");
	scanf("&f &f", &xc2, &yc2);
	s = sqrt(pow(xr2 - xr1, 2) + pow(yr2 - yr1, 2));
	r1 = sqrt(pow(xr1 - xc1, 2) + pow(yc1 - yr1, 2));
	r2 = sqrt(pow(xr2 - xc2, 2) + pow(yr2 - yc2, 2));

	if (xc1 == xc2 && yc1 == yc2)
	{
		printf("���������� ���������");
	}

	if (s == 0)
	{
		printf("���������� �������������");
	}

	if (s > 0)
	{
		printf("���������� ������� ���� �� �����");
	}

	if (xc1 == xc2 && yc1 == yc2 && abs(r1 - r2) > 0)
	{
		printf("���� ���������� ������ ������");
	}

	if ()
	{
		printf("���������� ����� ���� ����� �����");
	}
	else
	{
		printf("���������� ������������ � ���� ������");
	}
	return 0;
}