#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <locale.h>


int main()
{
	setlocale(LC_CTYPE, "Russian");
	float xc1, yc1, xc2, yc2, xr1, yr1,xr2,yr2,r1,r2,sc,d;
	printf("������� ���������� ������ ������ ����������: ");
	scanf("%f %f", &xc1, &yc1);
	printf("������� ���������� ������ ������ ����������: ");
	scanf("%f %f", &xc2, &yc2);
	printf("������� ���������� ������� ������ ����������: ");
	scanf("%f %f", &xr1, &yr1);
	printf("������� ���������� ������� ������ ����������: ");
	scanf("%f %f", &xr2, &yr2);
	r1 = sqrt(pow(xr1 - xc1, 2) + pow(yc1 - yr1, 2));
	r2 = sqrt(pow(xr2 - xc2, 2) + pow(yr2 - yc2, 2));
	sc = sqrt(pow(xc2 - xc1, 2) + pow(yc2 - yc1, 2));
	d = sc - (r1 + r2);

	if (sc == 0 && r1 == r2)
	{
		printf("���������� ���������");
	}

	else if (d== 0)
	{
		printf("���������� �������������");
	}

	else if (d > 0)
	{
		printf("���������� ������� ���� �� �����");
	}

	else if (sc < abs(r1 - r2))
	{
		printf("���� ���������� ������ ������");
	}

	else if (sc == abs(r1-r2))
	{
		printf("���������� ����� ���� ����� �����");
	}
	else 
	{
		printf("���������� ������������ � ���� ������");
	}
	getchar();
	return 0;
}