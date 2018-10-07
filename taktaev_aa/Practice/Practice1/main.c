#include <locale.h>
#include <math.h>
#include <stdio.h>

void main() 
{
	float h, w, d, VZad, VBok, VKrish, VDver, VPolk, Massa, pDSP, pDVP, pDer;
	setlocale(LC_ALL, "Russian");
	printf("����� ���������� � �������������� v1.0.\n ��������, ��� �� ������������ � ����������� ���������� �������� ��������� ������ �������� �����.\n");
	printf("������� ������ ����� � ��\n");
	scanf("%f", &h);
	if ((h < 180) || (h > 220)) 
	{
		printf("������� �������� ������");
		return;
	}
	printf("������� ������ ����� � ��\n");
	scanf("%f", &w);
	if ((w < 80) || (w > 120)) 
	{
		printf("������� �������� ������");
		return;
	}
	printf("������� ������� ����� � ��\n");
	scanf("%f", &d);
	if ((d < 50) || (d > 90)) 
	{
		printf("������� �������� �������");
		return;
	}
	printf("������� ��������� ���, ��� � ������ �� ������� ����� ������(� �/��^3)\n");
	scanf("%f %f %f", &pDSP, &pDVP, &pDer);
	if ((pDSP <= 0) || (pDVP <= 0) || (pDer <= 0)) 
	{
		printf("���� �� ��������� �������� ��������� �������. ��������� ���� ������");
		return;
	}
	VZad = w * h * 0.5;
	VBok = 2.0f * h * d * 1.5;
	VKrish = 2.0f * w * d * 1.5;
	VDver = w * h * 1.0f;
	VPolk = (w - 1.5 * 2.0f) * d * floor(h / 40) * 1.5; //��������� � ������� ����������, ��� ����� ��������� ����� ����� ���������� �����. 1.5 �� - ��� ����������������� ������� �����(� ������� ��� �� ����)
	Massa = (VZad * pDVP + VBok * pDSP + VKrish * pDSP + VDver * pDer + VPolk * pDSP) / 1000;
	printf("����� ������ ����� ����� %.2f ��\n", Massa);
	
}