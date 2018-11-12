#include <stdio.h>
#include <math.h>
#include <locale.h>
void main() {
	setlocale(LC_ALL, "Russian");
	double x1, y1, r1, r2, x2, y2, d;
	printf("Введите координаты центра первой окружности(x,y) и радиус:\n");
	printf("x=");
	scanf("%lf", &x1);
	printf("y=");
	scanf("%lf", &y1);
	printf("r=");
	scanf("%lf", &r1);
	printf("Введите координаты центра второй окружности(x,y) и радиус:\n");
	printf("x=");
	scanf("%lf", &x2);
	printf("y=");
	scanf("%lf", &y2);
	printf("r=");
	scanf("%lf", &r2);
	d = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
	printf("Расстояние между центрами окружности = %.4lf \n", d);
	printf("Взаимное расположение двух окружностей: \n");
	if ((x1 == x2) && (y1 == y2) && (r1 == r2) && (d == 0)) {
		printf("Окружности совпадают \n");
		return;
	}
	if (d > r1 + r2) {
		printf("Окружности не имеют общих точек \n");
		return;
	}
	if (d == r1 + r2) {
		printf("Окружности имеют 1 общую точку (внешнее касание) \n");
		return;
	}
	if (d == r1 - r2) {
		printf("Окружности имеют 1 общую точку (внутреннее касание) \n");
		return;
	}
	printf("Окружности пересекаются (две общие точки)\n");
}
