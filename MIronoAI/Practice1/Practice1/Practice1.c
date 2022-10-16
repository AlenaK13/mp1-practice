#include <stdio.h>
#include <locale.h>
#define Chipboard 0.0008f
#define Fiberboard 0.0008f
#define Wood 0.0009f


#if defined(_WIN32) || defined(_WIN32_)
	#define _CRT_SECURE_NO_WARNINGS_
	#pragma warning(disable:4996)
#endif

int main()
{
	setlocale(LC_ALL, "rus");
	float h, w, d, weight, weight_back, weight_side, weight_cover, weight_door, weight_shelf;

	//���� ������ 
	printf("������� ������ ����� � ����������� (180 <= h <= 220) : ");
	scanf("%f", &h);
	if (h > 220 || h < 180) {
		printf("�� ����� ������������ �������� ������");
		return 0;
	}


	printf("������� ������ ���������� � ����������� (80 <= w <= 120) : ");
	scanf("%f", &w);
	if (w < 80 || w > 120) {
		printf("�� ����� ������������ �������� ������");
		return 0;
	}

	printf("������� ������� ����� � ����������� (50 <= d <= 90) : ");
	scanf("%f", &d);
	if (d > 90 || d < 50) {
		printf("�� ����� ������������ �������� �������");
		return 0;
	}
	//����� ������ ������ �� ���
	weight_back = 0.5 * w * h * Fiberboard;

	//����� ���� �������
	weight_side = 2 * h * d * 1.5 * Chipboard;

	//����� ��������� ������
	weight_cover = 2 * w * d * 1.5 * Wood;

	//����� ���� ������
	weight_door = h * w * Wood;

	//����� �����
	int n;
	n = h / 40;
	weight_shelf = (n - 1) * 1.5 * w * d * Chipboard;


	weight = weight_back + weight_cover + weight_door + weight_shelf + weight_side;
	printf("����� ����� � ����������� �� ��������� ���������� ����� ����������:  ");
	printf("%.2f", weight);


	return 0;

}