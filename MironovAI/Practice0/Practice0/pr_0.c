#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
	double x1, dl, x2, y1, y2, r1, r2;

	setlocale(LC_ALL, "rus");
	printf("Input x1: ");
	scanf_s("%lf", &x1);

	printf("Input y1: ");
	scanf_s("%lf", &y1);
		
	printf("Input r1: ");
	scanf_s("%lf", &r1);

	printf("Input x2: ");
	scanf_s("%lf", &x2);

	printf("Input y2: ");
	scanf_s("%lf", &y2);

	printf("Input r2: ");
	scanf_s("%lf", &r2);


	dl = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

	if (dl == r1 + r2)
	{
		printf("���������� ��������");
		return;
	}

	if (dl >= r1 + r2)
	{
		printf("���������� �� ����� ����� �����");
		return;
	}

	if ((x1 == x2) && (y1 == y2) && (r1 == r2))
	{
		printf("���������� ���������");
		return;
	}

	if (abs(x1 - x2) < r1 || abs(x1 - x2) < r2);
	{
		printf("���� ���������� ������ ������");
		return;
	}

	if (((r1 > r2) && (abs(x1 - x2) + r2 == r2)));
	{
		printf("���� ���������� �������� ������ ������");
		return;
	}

	printf("���������� ����� 2 ����� ����������");
	return 0;
}