#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus"); 
	float x1, x2, y1, y2, R1, R2, S;
	printf("������� ���������� �1 ");
	scanf("%f", &x1);
	printf("������� ���������� y1 ");
	scanf("%f", &y1);
	printf("������� ���������� �2 ");
	scanf("%f", &x2);
	printf("������� ���������� y2 ");
	scanf("%f", &y2);
	printf("������� R1, ����� R1>R2 ");
	scanf("%f", &R1);
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
	if ((S < R1 + R2) && (S > (R1 - R2))) {
		printf("���������� ������������ ");
		return 0;
	}
	if ((S == (R1 - R2)) && (x1 != x2)) {
		printf("���������� ������� ����������� ");
		return 0;
	}
	if ((S == 0) && (R1 == R2)) {
		printf("���������� ��������� ");
		return 0;
	}
	printf("������ ���������� ����� ������ ������ ");
	return 0;
}