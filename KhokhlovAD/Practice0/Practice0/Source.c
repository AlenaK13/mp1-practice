#include <stdio.h>
#include <math.h>
int main()
{
	int x1, x2, y1, y2, r1, r2, max, min;
	float d;
	printf("x1=");
	scanf_s("%d", &x1);
	printf("y1=");
	scanf_s("%d", &y1);
	printf("r1=");
	scanf_s("%d", &r1);
	printf("x2=");
	scanf_s("%d", &x2);
	printf("y2=");
	scanf_s("%d", &y2);
	printf("r2=");
	scanf_s("%d", &r2);
	if (r1>r2)
	{
		max = r1;
		min = r2;
	}
	else
	{
		max = r2;
		min = r1;
	}
	d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if (d>(r1+r2))
	{
		printf("ne_peresekautsa");   //�� ������������
	}
	else if (d == (r1+r2))
	{
		printf("vneshnee kasanie");   //������� �������
	}
	else if ((d<(r1+r2))&&(d>max))
	{
		printf("peresekautsa");   //������������
	}
	else if (d==(max-min))
	{
		printf("vnutrennee kasanie");   //���������� �������
	}
	else if (d<(max-min))
	{
		printf("1 okruj vnutri drugoi");  // ���� ���������� ������ ������ � �� ��������
	}
	else	printf("okrujnosti sovpadaut"); //���������� ���������
}