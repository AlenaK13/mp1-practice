#include <stdio.h>
#include <math.h>
void main() {
	double x1, y1, r1, x2, y2, r2, d;
	scanf("%lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &r1, &r2, &d);
	d = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	if (d = r1 + r2)
	{
		printf("���������� ������������ � ����� �����");
		return;
	}
	if (d > r1 + r2)
	{
		printf("���������� �� ������������");
		return;
	}
	if (r1 - r2 < d < r1 + r2)
	{
		printf("���������� ������������ � ���� ������");
		return;
	}
	if (d = 0)
	{
		printf("���� ���������� ����������� � ������ ������");
		return;
	}
	if (d<r1-r2)
	{
		printf("���� ���������� ����������� ������ ������ � ���������� � ������� ���� ");
		return;
	}
	if (d = r1 - r2)
	{
		printf("���� ���������� ����������� ������ ������ � ���������� � ������� ����");
	}
 
}