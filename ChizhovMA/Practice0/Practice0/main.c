#include <stdio.h>
#include <clocale>
#include <math.h>


int main()
{
	float x1, y1, r1, x2, y2, r2;
	printf("������� ���������� � ������ ������ ����������");
	scanf("%f%f%f", &x1, &y1, &r1);
	printf("������� ���������� � ������ ������ ����������");
	scanf("%f%f%f", &x2, &y2, &r2);
	setlocale(LC_CTYPE, "Russian");

	if ((x1 == x2) && (y1 == y2) && (r1 == r2))
	{
		printf("���������� �����");
	}
	if (x1 == x2 && y1 == y2 && r1 > r2)
	{
		printf("������ ���������� ������� �������");
	}
	if (x1 == x2 && y1 == y2 && r1 < r2)
	{
		printf("������ ���������� ������� � ������");
	}
	if (sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) == (r1 + r2))
	{
		printf("���������� ����� ���� ����� �����");
	}
	if (sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2 )) >= (r1 + r2))
	{
		printf("���������� �� ����� ����� �����");
	}
	return 0;
}
