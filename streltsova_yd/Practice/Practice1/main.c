#include <stdio.h>
#include <math.h>
#include <locale.h>
void main (){
	double h, w, d, p1, p2, p3, m1, m2, m3, m4, m;
	setlocale (LC_ALL, "Russian");
	printf ("������� ������ (�� 180 �� 220 ��), ������ (�� 80 �� 120 ��) � ������� (�� 50 �� 90 ��) ����� � �����������\n");
	scanf ("%lf %lf %lf", &h, &w, &d);
	printf ("������� ��������� ���, ��� � ������ � ��/��^3\n");
	scanf ("%lf %lf %lf", &p1, &p2, &p3);
	if ((h >= 180) && (h <= 220) && (w >= 80) && (w <= 120))
		m1 = p1 * h * w * 0.5;
	else
	{
		printf ("�������� �������� ������ ��� ������ �����\n");
		return;
	}
	if ((d >= 50) && (d <= 90))
		m2 = 2 * p2 * d * 1.5 * (h + w);
	else
	{
		printf ("�������� �������� ������� �����\n");
		return;
	}
	m3 = p3 * h * w;
	if (((h - 3) / 41 - ((int)h - 3) / 41) == 0) // ����� ������� ����� ����� 1 ��
		m4 = ((((int)h - 3) / 41) - 1) * p2 * w * d;
	else
		m4 = floor ((h - 3) / 41) * p2 *w * d;
	m = m1 + m2 + m3 + m4;
	printf ("����� ����� - %lf", m);
}

