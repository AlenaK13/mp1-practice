#include <stdio.h> 
#include <math.h> 
#include <locale.h> 
int main() 
{ 
float x, X, y, Y, r, R, d; //d-���������� ����� �������� ���������� 
setlocale(LC_ALL, "Russian"); 

printf("������� ���������� ������ ���������� � �� ������\n"); 
scanf("%f %f %f", &x, &y, &r); 
printf("������� ���������� ������ ���������� � �� ������\n"); 
scanf("%f %f %f", &X, &Y, &R); 
d = sqrt((x - X)*(x - X) + (y - Y)*(y - Y)); 
if (d>(r + R)) 
{ 
printf("���������� �� ������������, �� ���� ���������� �� ��������� � ������"); 
return; 
} 
if (d == (r + R)) 
{ 
printf("���������� �������� ������� ������� � ����� �����"); 
return; 
} 
if ((d<(r + R)) && (d>abs(r-R))) 
{ 
printf("���������� ������������ � ���� ������"); 
return; 
} 
if (d == abs(r - R)) 
{ 
printf("���������� �������"); 
return; 
} 
if (0<d<abs(r - R)) 
{ 
printf("���� ���������� ��������� � ������"); 
return; 
} 
}

