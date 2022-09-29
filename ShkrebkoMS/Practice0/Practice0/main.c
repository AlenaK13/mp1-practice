#include <stdio.h>
#include <math.h>



int main()
{
	float r1, r2, x1, x2, y1, y2,CircleCenterDistance,dl1;
	printf("Enter the coordinates of the first circle and its radius\n");
	scanf_s("%f%f%f", &x1, &y1, &r1);
	printf("Enter the coordinates of the second circle and its radius\n");
	scanf_s("%f%f%f", &x2, &y2, &r2);
	CircleCenterDistance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	dl1=r1>r2?r1-r2:r2-r1;
	if ((x1 == x2) && (y1 == y2) && (r1 == r2))
	{
		printf("Circle coincide\n"); //���������� ���������
	}
	else if (CircleCenterDistance > (r1 + r2))
	{
		printf("Circles do not intersect (one does not lie in the other)\n"); //���������� �� ������������ (���� �� ����� � ������)
	}
	else if (CircleCenterDistance == dl1)
	{
		printf("The circles touch internally\n");  //���������� �������� ���������� �������
	}
	else if( (CircleCenterDistance == (r1 + r2)) )
	{
		printf("The circles touch externally\n");  //���������� �������� ������� �������
	}
	else if (CircleCenterDistance < dl1)
	{
		printf("Circles do not intersect (one lies in the other)\n");//���������� �� ������������ (���� ����� � ������)
	}
	else
	{
		printf("Overlapping circles\n");//���������� ������������
	}
	return 0;
}