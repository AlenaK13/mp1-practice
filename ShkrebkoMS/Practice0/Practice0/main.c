#include <stdio.h>
#include <math.h>
#include <locate>

set_locate(LC_CTYPE, "Russian");
int main()
{
	float r1, r2, x1, x2, y1, y2;
	printf("������� ���������� 1 ���������� � � ������");
	scanf_s("%f%f%f", &x1, &y1, &r1);
	printf("������� ���������� 2 ���������� � � ������");
	scanf_s("%f%f0%f", &x2, &y2, &r2);
	if ((x1 == x2) && (y1 == y2) && (r1 == r2))
	{
		printf("���������� ���������");
	}
	else if (sqrt((x2-x1)* (x2 - x1) + (y2 - y1)*(y2-y1)) > (r1 + r2))
	{
		printf("���������� �� ������������ (���� �� ����� � ������)");
	}
	else if (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) == abs((r1 - r2)))
	{
		printf("���������� �������� ���������� �������");
	}
	else if( (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) == (r1 + r2)) )
	{
		printf("���������� �������� ������� �������");
	}
	else if (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) < abs((r1 - r2)))
	{
		printf("���������� �� ������������ (���� ����� � ������)");
	}
	else
	{
		printf("���������� ������������ � 2 ������");
	}
	return 0;
}