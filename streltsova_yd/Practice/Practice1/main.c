#include <stdio.h>
#include <math.h>
#include <locale.h>
void main()
{
    double h, w, d, p1, p2, p3, m1, m2, m3, m4, m;
    setlocale (LC_ALL, "Russian");
    printf ("������� ������ (�� 1,8 �� 2,2 �), ������ (�� 0,8 �� 1,2 �) � ������� (�� 0,5 �� 0,9 �) ����� � ������\n");
    scanf ("%lf %lf %lf", &h, &w, &d);
    if ((h < 1.8) || (h > 2.2) || (w < 0.8) || (w > 1.2) || (d < 0.5) || (d > 0.9))
    {
    printf ("������� ������� ������");
    return;
    }
    printf ("������� ��������� ���, ��� � ������ � ��/�^3\n");
    scanf ("%lf %lf %lf", &p1, &p2, &p3);
    m1 = p1 * h * w * 0.005;
    m2 = 2 * p2 * d * 0.015 * (h + w);
    m3 = p3 * h * w * 0.01;
    m4 = (h - 2 * 0.015) / (0.4 + 0.015) * (w - 2 * 0.015) * (d - 0.005);
    m = m1 + m2 + m3 + m4;
    printf ("����� ����� - %lf", m);
}

