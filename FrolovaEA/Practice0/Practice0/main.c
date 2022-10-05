#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {

	setlocale(LC_ALL, "rus");

	float x1, x2, y1, y2, r1, r2, dl;

	printf("������� x1: ");
	scanf_s("%f", &x1);

	printf("������� x2: ");
	scanf_s("%f", &x2);

	printf("������� y1: ");
	scanf_s("%f", &y1);

	printf("������� y2: ");
	scanf_s("%f", &y2);

	printf("������� r1: ");
	scanf_s("%f", &r1);

	printf("������� r2: ");
	scanf_s("%f", &r2);

	dl = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

	if (dl == r1 + r2)
	{
		printf("���������� �������� ���� �����");
		return 0;
	}

	if (dl > r1 + r2)
	{
		printf("���������� �� �������� ���� ����� (������� �������)");
		return 0;
	}

	if ((x1 == x2) && (y1 == y2) && (r1 == r2))
	{
		printf("���������� ���������");
		return 0;
	}

	if ((dl + r1 == r2) || (dl + r2 == r1))
	{
		printf("���������� �������� (���������� �������)");
		return 0;
	}

	if (abs(x1 - x2) < r1 || abs(x1 - x2) < r2)
	{
		printf("���� ���������� ������ ������");
		return 0;
	}

	printf("���������� ����� ��� ����� �����");
	return 0;


}