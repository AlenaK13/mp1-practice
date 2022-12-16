#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Russian");
	float cx1, cx2, r1, cy1, cy2, r2, d;
	printf("������� ���������� ������ ���������� (x, y, r):");
	scanf_s("%f %f %f", &cx1, &cy1, &r1);
	printf("������� ���������� ������ ���������� (x, y, r):");
	scanf_s("%f %f %f", &cx2, &cy2, &r2);
	d = sqrt((cx1 - cx2) * (cx1 - cx2) + (cy1 - cy2) * (cy1 - cy2));
	

	if (d > (r1 + r2)) {
		printf("����� �� ������������"); //4
		return 0;
	}

	if (d < abs(r1 - r2) && (d >= 0)) {
		printf("����� �� ������������ (������)"); //1
		return 0;
	}

	if ((d < r1 + r2) && (d > abs(r1 - r2))) {
		printf("���������� ������������ � ���� ������"); //3
		return 0;
	}

	if (d == r1 + r2) {
		printf("���������� ������������ � ����� ����� (�������)"); //2
		return 0;
	}

	if (d == abs(r1 - r2)) {
		printf("���������� ������������ � ����� ����� (������)"); //5
		return 0;
	}
	return 0;
}