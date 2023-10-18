#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	double h, w, d, tsten, tbok, tkrysh, tdver, tpolk, dvp, dsp, der, RES;
	double v1, m1, v2, m2, v3, m3, v4, m4, v5, m5;
	double res = 40.0;
	int k = 0;
	tsten = 5.0 / 1000.0; //толщина задней стенки
	tbok = 15.0 / 1000.0; // толщина боковой стенки
	tkrysh = 15.0 / 1000.0; // толщина крышек
	tdver = 1.0 / 100.0; // толщина дверей
	tpolk = 15.0 / 1000.0;
	dvp = 950;
	dsp = 650;
	der = 660;
	do {
		printf("Введите значения h, w и d :");
		scanf("%lf %lf %lf", &h, &w, &d);
		if ((h < 180 || h > 220) || (w < 80 || w > 120) || (d < 50 || d > 90)) {
			printf("Данные значения неверны, повторите ввод\n");
		}
	} while (((h < 180 || h > 220) || (w < 80 || w > 120) || (d < 50 || d > 90)));
	h = h / 100.0;
	w = w / 100.0;
	d = d / 100.0;
	v1 = h * w * tsten; //объем задней стенки
	v2 = (h * d * tbok) * 2; // объем двух боковых стенок
	v3 = (w * d * tkrysh) * 2; // объем крышек
	v4 = (h * w * tdver); // объем дверей
	v5 = (d * (w - 2*tbok ) * tpolk); //объем одной полки
	m1 = dvp * v1;
	m2 = dsp * v2;
	m3 = dsp * v3;
	m4 = der * v4;
	m5 = dsp * v5;
	res = res / 100;
	h = h - 2*tkrysh;
	while (h>= 0.4)
	{
		h = h - res - tkrysh;
		k++;
	}
	RES = m1 + m2 + m3 + m4 + m5*4;
	printf("Результат равен: %lf", RES);
	return 0;
}