#include <stdio.h>
#include <math.h>



int main()
{
	float r1, r2, x1, x2, y1, y2,CircleCenterDistance;
	printf("������� ���������� 1 ���������� � � ������");
	scanf_s("%f%f%f", &x1, &y1, &r1);
	printf("������� ���������� 2 ���������� � � ������");
	scanf_s("%f%f0%f", &x2, &y2, &r2);
	CircleCenterDistance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if ((x1 == x2) && (y1 == y2) && (r1 == r2))
	{
		printf("���������� ���������");
	}
	else if (CircleCenterDistance > (r1 + r2))
	{
		printf("���������� �� ������������ (���� �� ����� � ������)");
	}
	else if (CircleCenterDistance == abs((r1 - r2)))
	{
		printf("���������� �������� ���������� �������");
	}
	else if( (CircleCenterDistance == (r1 + r2)) )
	{
		printf("���������� �������� ������� �������");
	}
	else if (CircleCenterDistance < abs((r1 - r2)))
	{
		printf("���������� �� ������������ (���� ����� � ������)");
	}
	else
	{
		printf("���������� ������������");
	}
	return 0;
}