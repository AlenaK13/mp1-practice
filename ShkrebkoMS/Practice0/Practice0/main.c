#include <stdio.h>
#include <math.h>



int main()
{
	float r1, r2, x1, x2, y1, y2,CircleCenterDistance;
	printf("Enter the coordinates of the first circle and its radius");
	scanf_s("%f%f%f", &x1, &y1, &r1);
	printf("Enter the coordinates of the second circle and its radius");
	scanf_s("%f%f0%f", &x2, &y2, &r2);
	CircleCenterDistance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if ((x1 == x2) && (y1 == y2) && (r1 == r2))
	{
		printf("Circle coincide"); //���������� ���������
	}
	else if (CircleCenterDistance > (r1 + r2))
	{
		printf("Circles do not intersect (one does not lie in the other)"); //���������� �� ������������ (���� �� ����� � ������)
	}
	else if (CircleCenterDistance == abs((r1 - r2)))
	{
		printf("The circles touch internally");  //���������� �������� ���������� �������
	}
	else if( (CircleCenterDistance == (r1 + r2)) )
	{
		printf("The circles touch externally");  //���������� �������� ������� �������
	}
	else if (CircleCenterDistance < abs((r1 - r2)))
	{
		printf("Circles do not intersect (one lies in the other)");//���������� �� ������������ (���� ����� � ������)
	}
	else
	{
		printf("Circles intersect");//���������� ������������
	}
	return 0;
}