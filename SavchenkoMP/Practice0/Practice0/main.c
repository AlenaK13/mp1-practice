#include <stdio.h>
#include <math.h>
#include <locale.h>

/*
1) �� ��������
2) ������� �������
3) ������������
4) ���������� �������
5) ���� ���������� ������ ������
6) ���������� ���������
*/

void main() {
	
	setlocale(LC_ALL, "rus");
	float x1, y1, r1, x2, y2, r2, M, m, dl;
	//printf("Circle 1 (x1, y1, r1) = ");
	//scanf_s("%f %f %f", &x1, &y1, &r1);
	//printf("Circle 2 (x2, y2, r2) = ");
	//scanf_s("%f %f %f", &x2, &y2, &r2);
	setlocale(LC_ALL, "rus");
	scanf_s("%f %f %f %f %f %f", &x1, &y1, &r1, &x2, &y2, &r2);

	if (r1 > r2) {
		M = r1;
		m = r2;
	}
	else {
		M = r2;
		m = r1;
	}

	dl = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

	if (x1 == x2 && y1 == y2 && r1 == r2)
		printf("6");
	else {
		if (dl > (r1 + r2))
			printf("1"); // �� ��������
		else if (dl == (r1 + r2))
			printf("2"); // ������� �������
		else if ((dl == (r1 + r2)) && (dl > M))
			printf("3"); // ������������
		else if (dl == (M - m))
			printf("4"); // ���������� �������
		else if (dl < (M - m))
			printf("5"); // ���� ���������� ������ ������
	}



}