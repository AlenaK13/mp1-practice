#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
void main()
{
	int x1, x2, y1, y2, r1, r2;
	setlocale(LC_ALL, "Rus");
	double d;
	printf("Input x1, y1, x2, y2, r1, r2\n");
	scanf_s("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &r1, &r2);
	if (r1 <= 0)
	{
		printf("Ќе €вл€етс€ окружностью, r1- отрицательный или равен нулю\n");
		return 0;
	}
	if (r2 <= 0)
	{
		printf("Ќе €вл€етс€ окружностью, r2 - отрицательный или равен нулю\n");
		return 0;
	}
	d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if (x1 == x2 && y1 == y2 && r1 == r2)
	{
		printf("ќкружности равны");
	}
	else if (r1 + r2 < d)
	{
		printf("ќкружности не пересекаютс€, отсутсвуют общие точки");
	}
	else if (d < abs(r1 - r2))
	{
		printf("ќкружности не пересекаютс€, вложены друг в друга");
	}
	else if (d == r1 + r2)
	{
		printf("¬нешнее касание окружностей, одна обща€ точка");
	}
	else if (d == r1 - r2)
	{
		printf("¬нутреннее касание окружностей, одна обща€ точка");
	}
	else
	{
		printf("ќкружности пересекаютс€, две общие точки");
	}

}