#include <stdio.h>
#include <math.h>
#include <locale.h>

void main()
{
	float x, y, r; //���������� ������ ���
	float a, b, c; //���������� ������ ���
	float k; //���������� ����� ��������
	setlocale(LC_ALL, "Russian");
	printf("������� ���������� ������ ������ ���������� � �� ������\n");
	scanf("%f %f %f", &x, &y, &r);
	printf("������� ���������� ������ ������ ���������� � �� ������\n");
	scanf("%f %f %f", &a, &b, &c);
	if ((x == a) && (y == b) && (r == c))
	{
		printf("���������� ���������\n");
		return;
	}
	if ((x == a) && (y == b) && (r != c))
	{
		printf("���� ���������� ������� � ������ � �� ������ ���������\n");
		return;
	}
	k = sqrt((x - a) * (x - a) + (y - b) * (y - b));
	if ((k + r < c) || (k + c < r))
	{
		printf("���� ���������� ������� � ������ � �� ������ �� ���������\n");
		return;
	}
	if (k > r + c)
	{
		printf("���������� �� ������������\n");
		return;
	}
	if ((k + r == c) || (k + c == r))
	{
		printf("���������� �������� ���������� �������\n");
		return;
	}
	if (k == r + c)
	{
		printf("���������� ��������\n");
		return;
	}
	
		printf("���������� ������������\n");
		return;
}