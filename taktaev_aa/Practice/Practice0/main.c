#include <stdio.h>
#include <math.h>
#include <locale.h>
void main()
{
	float x1, y1, x2, y2, r1, r2, s=0.0f;
	setlocale(LC_ALL, "Russian");
	printf("������� ���������� � ������ ������ ���������� \n");
	scanf("%f %f %f", &x1, &y1, &r1);
	printf("������� ���������� � ������ ������ ���������� \n");
	scanf("%f %f %f", &x2, &y2, &r2);
	s = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if ((s==0) && (r1==r2)) 
	{
		printf("���������� ��������� \n");
		return;
	}
	if (s>(r1 + r2)) 
		{
			printf("���������� �� ������������ � �� �������� \n");
			return;
	    }
	if (s==(r1 + r2)) 
	{
		printf("���������� �������� ������� ������� \n");
		return;
	}
	if ((s + r2==r1) || (s + r1==r2)) 
	{
		printf("���������� �������� ���������� ������� \n");
		return;
	}
	if ((s + r2<r1) || (s + r1<r2)) 
	{
		printf("���� ���������� ����� ������ ������ � �� �������� �� \n");
	}
	else 
	{
		printf("���������� ������������ \n");
	}
	return;
}
