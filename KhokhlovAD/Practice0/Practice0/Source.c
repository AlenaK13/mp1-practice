#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Russian");
	int x1, y1, r1, x2, y2, r2;
	double distance;
	printf("������� ���������� ������ � ������ ������ ����������: ");
	scanf_s("%i%i%i", &x1, &y1, &r1);
	printf("������� ���������� ������ � ������ ������ ����������: ");
	scanf_s("%i%i%i", &x2, &y2, &r2);
	distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	if (x1 == x2 && y1 == y2 && r1 == r2)
		printf("��������� ���������");
	else if (distance < r1 - r2 || distance < r2 - r1)
		printf("���� ���������� ������ ������");
	else if (distance == r1 + r2)
		printf("������� �������");
	else if (distance == r1 - r2 || distance == r2 - r1)
		printf("���������� �������");
	else if (distance > r1 + r2)
		printf("�� ������������");
	else if (distance < r1 + r2)
		printf("������������ � 2 ������");
	return 0;
}