#include<stdio.h>
#include<math.h>
void main() 
{
	double r1, r2, x1, x2, y1, y2;
	scanf("%fl %fl %fl %fl %fl %fl", &r1, &r2, &x1, &x2, &y1, &y2);
	if ((x1 == x2) && (y1 == y2) && (r1 == r2)) {
		printf("���������");
		return;
	}
	if (((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))>((r1+r2)*(r1+r2)))
	{
		printf("�� ������������");
		return;
	}
	if (((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2))==((r1 + r2)*(r1 + r2))||(((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) == ((r1 - r2)*(r1 - r2)))) {
		printf("��������");
		return;
	}
	if (((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) < ((r1 + r2)*(r1 + r2))) {
	
	if (((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) < ((r1 - r2)*(r1 - r2))) {
		printf("���� ������ ������");
	}
	else printf("������������");

}