#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus"); 
	float x1, x2, y1, y2, R1, R2, S, tmp;
	printf("������� ���������� x1 ");
	scanf("%f", &x1);
	printf("������� ���������� y1 ");
	scanf("%f", &y1);
	printf("������� R1 ");
	scanf("%f", &R1);
	printf("������� ���������� x2 ");
	scanf("%f", &x2);
	printf("������� ���������� y2 ");
	scanf("%f", &y2);
	printf("������� R2 ");
	scanf("%f", &R2);
	S = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if (S > R1 + R2) {
		printf("���������� �� ������������ ");
		return 0;
	}
	if (S == R1 + R2) {
		printf("������� ������� ����������� ");
		return 0;
	}
	if ((S < R1 + R2) && (S > abs(R1 - R2))) {
		printf("���������� ������������ ");
		return 0;
	}
	if ((S == abs(R1 - R2)) && (x1 != x2)) {
		printf("���������� ������� ����������� ");
		return 0;
	}
	if ((S == 0) && (R1 == R2)) {
		printf("���������� ��������� ");
		return 0;
	}
	if (R1>R2) printf("������ ���������� ����� ������ ������ ");
	else printf("������ ���������� ����� ������ ������ ");
	return 0;
}