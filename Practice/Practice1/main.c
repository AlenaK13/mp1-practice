#include <stdio.h>
#include <math.h>
#include <locale.h>
void main()
{
	float h,w,d;//h-������ w-������ d-�������
	float DVP, DSP, drev;
	float zad, bok, krish, dveri, polki;
	double kol;//���������� �����
	setlocale(LC_ALL, "Russian");
	printf("������� ������, ������, �������\n");
	scanf("%f %f %f", &h, &w, &d);
	if ((h < 180) || (h > 220)){
		printf("������������ ������\n");
		return;}
	if ((d < 50) || (d > 90)){
		printf("������������ �������\n");
		return;}
	if ((w < 80) && (w > 120)){
		printf("������������ ������\n");
		return;}
	printf("������� ��������� ���, ���, ������\n");
	scanf("%f %f %f", &DVP, &DSP, &drev);
	if ((DVP <= 0) || (DSP <= 0) || (drev <= 0)){
		printf("������������ ���������\n");
		return;}
	kol= floor(h / 40);
	zad=h * w * DVP * 0.5f;
	bok=2.0f * DSP * h * d * 1.5f;
	krish=2.0f * DSP * w * d *1.5f;
	dveri=drev * h * w * 2.0f;
	polki=kol * d * w * drev;
	printf("����� ����� ����� %.0f\n", zad + bok + krish + dveri + polki);
}