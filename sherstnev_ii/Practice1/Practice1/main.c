#include <stdio.h>
#include <math.h>
#include <locale.h>

void main()
{
	float x1, y1, x2, y2, r1, r2, t, q;
	setlocale(LC_ALL, "Russian");
	printf("������� x1   ");
	scanf("%f", &x1);
	printf("\n������� y1   ");
	scanf("%f", &y1);
	printf("\n������� x2   ");
	scanf("%f", &x2);
	printf("\n������� y2   ");
	scanf("%f", &y2);
	printf("\n������� r1   ");
	scanf("%f", &r1);
	printf("\n������� r2   ");
	scanf("%f", &r2);
	t=sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1-y2));
	if((x1==x2)&&(y1==y2)&&(r1==r2)) {
		printf("���������� ��������� \n");
		return;
	}
	if(t > r1 + r2) {
		printf("���������� �� ������ \n");
		return;
	}
	if(t == r1 + r2) {
		printf("���������� �������� \n");
		return;
	}
	if((r1 > t+r2)||(r2 > t+r1)) {
		printf("���� ���������� ����� ������ ������ \n");
		return;
	}
	if((r1 == t+r2)||(r2 == t+r1)) {
		printf("���� ���������� ����� ������ ������ � �������� �� \n");
		return;
	}
	printf("���������� ������������ \n");
}