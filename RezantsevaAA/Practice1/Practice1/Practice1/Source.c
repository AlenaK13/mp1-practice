#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	float h, w, d; 
	float density_wood = 640;
	float density_DSP = 800;
	float density_DVP = 750;

	printf("������� ������ ����� h");
	scanf(" %f",&h);
	if ((h < 180) || (h > 220))
	{
		printf("������������ ������, ���������� �������� 180 mm < h < 220 mm");
		return 0;
	}
	printf("������� ������ ����� w");
	scanf(" %f",&w);
	if ((w < 80) || (w > 120))
	{
	printf("������������ ������, ���������� �������� 80 mm < w < 120 mm");
	return 0;
	}
	printf("������� ������� ����� d");
	scanf(" %f", &d);
	if ((d < 50) || (d > 90))
	{
	 printf("������������ ������, ���������� �������� 50 mm < d < 90 mm");
	 return 0;
	}
	
}