#include <stdio.h>
#include <math.h>
#include <locale.h>

void main()
{
	float h, w, d;//h-������ w-������ d-�������
	float DVP, DSP, drev;
	float zad, bok, krish, dveri, polki;
	double kol;//���������� �����
	setlocale(LC_ALL, "Russian");
	printf("������� ������, ������, �������\n");
	scanf("%f %f %f", &h, &w, &d);
	if ((h < 180) || (h > 220))
	{
		printf("������������ ������\n");
		return;
	}
	if ((d < 50) || (d > 90))
	{
		printf("������������ �������\n");
		return;
	}
	if ((w < 80) && (w > 120))
	{
		printf("������������ ������\n");
		return;
	}
	printf("������� ��������� ���, ���, ������(��/�^3)\n");
	scanf("%f %f %f", &DVP, &DSP, &drev);
	if ((DVP <= 0) || (DSP <= 0) || (drev <= 0))
	{
		printf("������������ ���������\n");
		return;
	}
	kol = floor(h / 40);
	h = h / 100.0f;//������� � �� ��-->�
	w = w / 100.0f;
	d = d / 100.0f;
	zad = (h - 2 * 0.015f) * w * DVP * 0.005f;
	bok = 2.0f * DSP * (h - 2 * 0.015f) * (d - 0.005f)  * 0.015f;
	krish = 2.0f * DSP * w * d *0.015f;
	dveri = drev * (h - 2 * 0.015f) * (w - 2 * 0.015) * 2.0f;
	polki = kol * (h - 2 * 0.015f) / (0.4f + 0.015f) * (w - 2 * 0.015f) * (d - 0.005f)* drev;
	printf("����� ����� ����� %f\n", zad + bok + krish + dveri + polki);
}