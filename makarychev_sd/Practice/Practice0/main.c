#include<stdio.h>
#include<math.h>
#include<locale.h>

void main()
{
	setlocale(LC_ALL, "Rus");
	float x1, x2, y1, y2, r1, r2, d;
	scanf("%f%f%f%f%f%f", &x1, &x2, &y1, &y2, &r1, &r2);
	d = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	if ((r1 <= 0) || (r2 <= 0))
	{
		printf("���������� �� ����������");
		return;
	}
	if ((d == 0) && ((r1 < r2) || (r2 < r1)))
	{
		printf("�������������� ����������");
		return;
	}
	if ((d == 0) && (r1 == r2))
	{
		printf("���������� ���������");
		return;
	}
	if ((r1 - r2 > d) || (r2 - r1 > d))
	{
		printf("���� �� ����������� ��������� ��������� ������ ������");
		return;
	}
	if ((d == r1 - r2) || (d == r2 - r1))
	{
		printf("���������� ����� ���������� �������");
		return;
	}
	if (((r1 - r2 < d) && (r1 + r2 > d)) || ((r2 - r1 < d) && (r2 + r1 > d)))
	{
		printf("���������� ������������");
		return;
	}
	if (r1 + r2 == d)
	{
		printf("���������� ����� ������� �������");
		return;
	}
	if (r1 + r2 < d)
	{
		printf("������ �� ����������� ����� ��� ������");
	}
}

	
